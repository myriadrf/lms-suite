// -----------------------------------------------------------------------------
// FILE: 		ConnectionManager.h
// DESCRIPTION:	Handles data writing and reading to chip
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#include "ConnectionManager.h"
#include <iostream>
#include <stdio.h>

#include "../CommonUtilities.h"
#include "ConnectionCOM.h"
#include "MessageLog.h"
#include <sstream>

using namespace std;

/** @brief Returns most repeated value, if all different returns first one
*/
unsigned char bestOfThree(const unsigned char A, const unsigned char B, const unsigned char C)
{
    if(A == B || A == C)
        return A;
    else if(B == C)
        return B;
    return A;
}

/** @brief Handles incoming messages
    @param msg message about event
*/
void ConnectionManager::HandleMessage(const LMS_Message &msg)
{

}

/** @brief Creates connection interfaces, determines system endianness for forming 16 bit values
*/
ConnectionManager::ConnectionManager() : activeControlPort(NULL), activeTransmitter(NULL), activeReceiver(NULL)
{
	m_testWriting = false;
    m_tripleCheckRead = true;
    m_system_big_endian = true;
    unsigned int endian_test = 0x11000044;
    unsigned char *p_byte;
    p_byte = (unsigned char*)&endian_test;
    if(p_byte[0] == 0x11 && p_byte[3] == 0x44) // little endian
        m_system_big_endian = false;
    else if(p_byte[0] == 0x44 && p_byte[3] == 0x11) // big endian
        m_system_big_endian = true;
    else
        MessageLog::getInstance()->write("Cannot determine system endiannes. Using big endian", LOG_ERROR);
    currentReceiver = -1;
	currentTransmitter = -1;
    m_controllingDevice = LMS_RECEIVER;
    m_connections[COM_PORT] = new ConnectionCOM();
    MessageLog::getInstance()->write("COM connection supported\n", LOG_INFO);

}

/** @brief Destroys connection interfaces
*/
ConnectionManager::~ConnectionManager()
{
    std::map<eConnectionType, IConnection*>::iterator iter;
    for (iter = m_connections.begin(); iter != m_connections.end(); ++iter)
    {
        delete iter->second;
    }

    if(activeReceiver)
        delete activeReceiver;
    if(activeTransmitter)
        delete activeTransmitter;
}

/** @brief Returns whether control device is opened
    @return true if opened
*/
bool ConnectionManager::IsOpen()
{
    if(activeControlPort)
        return activeControlPort->IsOpen();
    return false;
}

/** @brief Connects to first found chip
    @return true is connection was made
*/
bool ConnectionManager::Open()
{
    bool status = false;
    FindDevices();
    if(m_receivers.size() > 0)
    {
        status = OpenReceiver(0);
    }
//    if(m_transmitters.size() > 0)
//        OpenTransmitter(0);
//    SetControlDevice(m_controllingDevice);
    return status;
}

/** @brief Closes connection to chip
*/
void ConnectionManager::Close()
{
    bool wasConnected = false;
    if(activeControlPort)
    {
        wasConnected = activeControlPort->IsOpen();
        activeControlPort->Close();
    }
    if(activeReceiver)
    {
        activeReceiver->Close();
        Notify(LMS_Message(MSG_BOARD_DISCONNECTED, "Disconnected from board", activeReceiver->GetType(), 0));
    }
    if(activeTransmitter)
    {
        activeTransmitter->Close();
        //Notify(LMS_Message(MSG_BOARD_DISCONNECTED, "Disconnected from board", activeReceiver->GetType(), 0));
    }
    if(wasConnected)
        MessageLog::getInstance()->write("Connection to Board closed\n");
}

/** @brief Finds all currently connected devices and forms transmitter,receiver device lists
*/
void ConnectionManager::FindDevices()
{
    Close();
    m_transmitters.clear();
    m_receivers.clear();
    DeviceInfo dev;
    std::map<eConnectionType, IConnection*>::iterator iter;
    for (iter = m_connections.begin(); iter != m_connections.end(); ++iter)
    {
        vector<string> names;
        IConnection *port = iter->second;
        port->FindDevices();
        names = port->GetDeviceNames();
        for(unsigned int i=0; i<names.size(); ++i)
        {
            dev.name = names[i];
            dev.port = iter->first;
            dev.portIndex = i;
            dev.type = LMS_TRANCEIVER;
            m_transmitters.push_back(dev);
            m_receivers.push_back(dev);
        }
    }
}

/** @brief Sends given data to chip
    @param cmd LMS chip command
    @param data data buffer to send
    @param length size of data in bytes
    @return Command status

    Forms packet header and sends given data buffer to chip.
    When using CMD_LMS7002_WR the data buffer should be pointer to array of unsigned shorts.
 */
int ConnectionManager::SendData(eCMD_LMS7002M cmd, const unsigned char* data, long length)
{
    if(!IsOpen())
        return STATUS_UNDEFINED;

    const int maxDataLen = cMAX_CONTROL_PACKET_SIZE-cPACKET_HEADER_SIZE;
    long sendLen;

    int status = STATUS_UNDEFINED;
    unsigned char buffer[cMAX_CONTROL_PACKET_SIZE];
    memset(buffer, 0, cMAX_CONTROL_PACKET_SIZE);

    const unsigned char* pdata_start = data;

    stringstream msg;
    bool hasErrors = false;

    while( length > 0)
    {
        sendLen = length < maxDataLen ? length : maxDataLen;

        if( MakeAndSendPacket(cmd, pdata_start, sendLen) )
        {
            long readLen = cMAX_CONTROL_PACKET_SIZE;
            status = ReadData(buffer, readLen);
            if(status == STATUS_ERROR_CMD || readLen == 0)
                break;

            //check if data has been written correctly
            if(cmd == CMD_LMS7002_WR && m_testWriting)
            {
                unsigned long bToRead = sendLen;
                unsigned char writeBuffer[64];
                unsigned char readbackBuffer[64];
                memset(writeBuffer, 0, 64);
                memset(readbackBuffer, 0, 64);
                int rdBufPos = 0;
                for(int i=0; i<sendLen; i+=4)
                {
                    writeBuffer[rdBufPos++] = pdata_start[i];
                    writeBuffer[rdBufPos++] = pdata_start[i+1];
                }
                SendReadData(CMD_LMS7002_RD, writeBuffer, sendLen/2, readbackBuffer, bToRead);

                unsigned short *writtenShorts = (unsigned short*)data;
                unsigned short *readShorts = (unsigned short*)readbackBuffer;

                for(int i=0; i<sendLen/4; ++i)
                {
                    if(writtenShorts[i+1] != readShorts[i+1])
                    {
                        if(hasErrors == false)
                            msg << "Written data don't match readback data:\n";
                        hasErrors = true;
                        msg << "at 0x" << int2hex(writtenShorts[i], 2) << " Wr: 0x" << int2hex(writtenShorts[i+1], 2) << "  Rd: 0x" << int2hex(readShorts[i+1], 2) << endl;
                    }
                }
            }
        }
        else
        {
            status = STATUS_ERROR_CMD;
            break;
        }
        pdata_start += sendLen;
        length -= sendLen;
    }
    if(hasErrors)
    {
        MessageLog::getInstance()->write(msg.str().c_str(), LOG_ERROR);
        Notify( LMS_Message(MSG_CRITICAL_ERROR, msg.str().c_str(), 0, 0));
    }
    return status;
}

/** @brief Creates and sends packet buffer according to given command and data buffers
    @param cmd LMS chip command
    @param data data buffer to send
    @param length size of data in bytes
    @return true if success

    When using CMD_LMS7002_WR the data buffer should be pointer to array of unsigned shorts.
*/
int ConnectionManager::MakeAndSendPacket( eCMD_LMS7002M cmd, const unsigned char *data, long length)
{
    const int maxDataLen = cMAX_CONTROL_PACKET_SIZE-cPACKET_HEADER_SIZE;
    if(length > maxDataLen)
    {
        MessageLog::getInstance()->write("MakeAndSendPacket : Packet larger than 64 bytes, truncating to 64 bytes." , LOG_WARNING);
        length = maxDataLen;
    }

    long sendLen;
    unsigned char buffer[cMAX_CONTROL_PACKET_SIZE];
    memset(buffer, 0, cMAX_CONTROL_PACKET_SIZE);

    sendLen = length < maxDataLen ? length : maxDataLen;
    memcpy(&buffer[8], data, sendLen);
    unsigned char temp;
    if(activeControlPort)
    {
        buffer[0] = cmd;
        //buffer[1] = 0; //Status
        // buffer[3-7] reserved
        switch( cmd )
        {
        case CMD_SI5351_WR:
        case CMD_SI5356_WR:
            buffer[2] = sendLen/2; //data block pairs(address,value)
            break;
        case CMD_SI5351_RD:
        case CMD_SI5356_RD:
            buffer[2] = sendLen; //data blocks(address)
            break;
        case CMD_ADF4002_WR:
            buffer[2] = sendLen/3; //data block(3xByte)
            break;
        case CMD_LMS7002_WR:
            buffer[2] = sendLen/4; //data block pairs(address,value)
            if(m_system_big_endian)
                for(int i=8; i<cMAX_CONTROL_PACKET_SIZE; i+=2)
                {
                    temp = buffer[i];
                    buffer[i] = buffer[i+1];
                    buffer[i+1] = temp;
                }
            break;
        case CMD_LMS7002_RD:
            buffer[2] = sendLen/2; //data blocks(address)
            if(m_system_big_endian)
                for(int i=8; i<cMAX_CONTROL_PACKET_SIZE; i+=2)
                {
                    temp = buffer[i];
                    buffer[i] = buffer[i+1];
                    buffer[i+1] = temp;
                }
            break;
        case CMD_PROG_MCU:
        case CMD_LMS7002_RST:
        case CMD_GET_INFO:
        case 0x2A:
        case 0x2B:
            buffer[2] = 1;
            break;
            break;
        default:
            MessageLog::getInstance()->write("Sending packet with unrecognized command", LOG_WARNING);
        }

        if( activeControlPort->SendData(buffer, cMAX_CONTROL_PACKET_SIZE) > 0 )
            return true;
        else
            return false;
    }
    return false;
}

/** @brief Receives data from chip
    @param data array for incoming data
    @param length number of bytes to receive, this variable will be changed to actual number of bytes returned
    @return Command status
    Receives incoming data from chip and places it to given array.
*/
int ConnectionManager::ReadData(unsigned char* data, long& length)
{
    if(length > cMAX_CONTROL_PACKET_SIZE-cPACKET_HEADER_SIZE)
    {
        length = cMAX_CONTROL_PACKET_SIZE-cPACKET_HEADER_SIZE;
    }
    int status = STATUS_UNDEFINED;
    unsigned char buffer[cMAX_CONTROL_PACKET_SIZE];
    int bytesReceived;

    if(activeControlPort)
    {
        memset(buffer, 0, cMAX_CONTROL_PACKET_SIZE);
        bytesReceived = activeControlPort->ReadData(buffer, cMAX_CONTROL_PACKET_SIZE);
        if(bytesReceived > 0)
        {
            status = buffer[1];
            length = length > bytesReceived-cPACKET_HEADER_SIZE ? bytesReceived-cPACKET_HEADER_SIZE : length;
            if(bytesReceived-cPACKET_HEADER_SIZE <= 0)
                length = 0;
        }
        else
        {
            status = STATUS_UNDEFINED;
            length = 0;
        }
        memcpy(data, &buffer[8], length);
    }
    return status;
}

/** @brief Sends given data to chip and reads incoming data
    @param cmd LMS chip command
    @param outData data buffer to send
    @param oLength number of bytes in outData
    @param inData received data
    @param iLength number of bytes to receive
    @return Command status

    When using CMD_LMS7002_WR or CMD_LMS7002_RD commands the data buffers should be pointers to array of unsigned shorts.
*/
int ConnectionManager::SendReadData( eCMD_LMS7002M cmd, const unsigned char *outData, unsigned long oLength, unsigned char *inData, unsigned long &iLength)
{
    if(!IsOpen())
        return STATUS_UNDEFINED;

    int readCount = m_tripleCheckRead ? 3 : 1;
    const unsigned int maxDataLen = cMAX_CONTROL_PACKET_SIZE-cPACKET_HEADER_SIZE;
    unsigned char outBuffer[maxDataLen];
    unsigned char inBuffer[readCount][maxDataLen];
    for(int i=0; i<readCount; ++i)
        memset(inBuffer[i], 0, maxDataLen);

    int status = STATUS_UNDEFINED;

    unsigned int outBufPos = 0;
    unsigned int inDataPos = 0;

    unsigned char bestByte = 0;

    for(unsigned int i=0; i<oLength; ++i)
    {
        outBuffer[outBufPos++] = outData[i];
        if(outBufPos >= maxDataLen || (cmd == CMD_LMS7002_RD && outBufPos>=28) || outBufPos == oLength || i==oLength-1)
        {
            for(int i=0; i<readCount; ++i)
            {
                if(MakeAndSendPacket(cmd, outBuffer, outBufPos))
                {
                    long readLen = 64;
                    status = ReadData(inBuffer[i], readLen);

                    if(cmd == CMD_LMS7002_RD)
                    {
                        unsigned char temp;
                        if(m_system_big_endian)
                            for(unsigned int j=0; j<outBufPos*2; j+=2)
                            {
                                temp = inBuffer[i][j];
                                inBuffer[i][j] = inBuffer[i][j+1];
                                inBuffer[i][j+1] = temp;
                            }
                    }
                }
            }

            for(unsigned int b=0; b<outBufPos*2; ++b)
            {
                if(m_tripleCheckRead)
                    bestByte = bestOfThree(inBuffer[0][b],inBuffer[1][b], inBuffer[2][b]);
                else
                    bestByte = inBuffer[0][b];
                inData[inDataPos++] = bestByte;
            }
            if(inDataPos > iLength)
            {
                return status;
            }
            outBufPos = 0;
        }
    }
    return status;
}

/** @brief Creates connection to selected receiver
    @param i receiver index from list
    @return true if success
*/
bool ConnectionManager::OpenReceiver(int i)
{
    if(activeReceiver)
    {
        delete activeReceiver;
        activeReceiver = NULL;
    }

    switch(m_receivers[i].port)
    {
    case COM_PORT:
        activeReceiver = new ConnectionCOM();
        activeReceiver->FindDevices();
        break;
    default:
        return false;
    }

    if(activeReceiver)
    {
        currentReceiver = i;
        if( activeReceiver->Open(i) )
        {
            stringstream ss;
            ss << "Connected to Board on ";
            ss << m_receivers[i].name << " | ";

            SetControlDevice(m_controllingDevice);

            unsigned char inBuf[cMAX_CONTROL_PACKET_SIZE];
            memset(inBuf, 0, cMAX_CONTROL_PACKET_SIZE);
            unsigned long btoRead = cMAX_CONTROL_PACKET_SIZE;
            unsigned char outBuf[1];
            SendReadData(CMD_GET_INFO, outBuf, 1, inBuf, btoRead);


            ss << "Firmware: " << (int)inBuf[0] << "  Device: ";
            if(inBuf[1] < LMS_DEV_COUNT)
            {
                ss << LMS_DEV_NAMES[inBuf[1]];
            }
            else
            {
                ss << "UNSPECIFIED ID";
            }
            ss << "  Protocol: " << (int)inBuf[2];
            Notify(LMS_Message(MSG_BOARD_CONNECTED, ss.str(), activeReceiver->GetType(), i));
            ss << endl;
            MessageLog::getInstance()->write(ss.str());
            return true;
        }
    }
    else
        currentReceiver = -1;
    return false;
}

/** @brief Creates connection to selected transmitter
    @param i transmitter index from list
    @return true if success
*/
bool ConnectionManager::OpenTransmitter(int i)
{
    if(activeTransmitter)
    {
        delete activeTransmitter;
        activeTransmitter = NULL;
    }
    switch(m_transmitters[i].port)
    {
    case COM_PORT:
        activeTransmitter = new ConnectionCOM();
        activeTransmitter->FindDevices();
        break;
    default:
        return false;
    }
    if(activeTransmitter)
    {
        if( activeTransmitter->Open(i) )
        {
            currentTransmitter = i;
            //string msg = "Connected to Transmitter on ";
            string msg = "Connected to Board on ";
            msg.append(m_transmitters[i].name);
            MessageLog::getInstance()->write(msg);
            SetControlDevice(m_controllingDevice);
// TODO (userk1#1#): add notify message
            return true;
        }
    }
    else
        currentTransmitter = -1;
    return false;
}

/** @brief Returns a list of connected receivers
    @return vector of receiver device names
*/
vector<string> ConnectionManager::GetReceiverList()
{
    vector<string> receivers;
    for(unsigned int i=0; i<m_receivers.size(); ++i)
    {
        receivers.push_back(m_receivers[i].name);
    }
    return receivers;
}

/** @brief Returns a list of connected transmitters
    @return vector of transmitter device names
*/
vector<string> ConnectionManager::GetTransmitterList()
{
    vector<string> transmitters;
    for(unsigned int i=0; i<m_transmitters.size(); ++i)
    {
        transmitters.push_back(m_transmitters[i].name);
    }
    return transmitters;
}

/** @brief Sets which device receives configuration commands
    @param dev device type: receiver, transmitter, transceiver
*/
void ConnectionManager::SetControlDevice( eDeviceType dev )
{
    m_controllingDevice = dev;
    switch(m_controllingDevice)
    {
    case LMS_RECEIVER:
        if(activeReceiver)
            activeControlPort = activeReceiver;
        break;
    case LMS_TRANSMITTER:
        if(activeTransmitter)
            activeControlPort = activeTransmitter;
        break;
    default:
        break;
    }
}

/** @brief Returns connection port selected for controlling
*/
eDeviceType ConnectionManager::GetControlDevice()
{
    return m_controllingDevice;
}

/** @brief Returns connection port to opened receiver
*/
int ConnectionManager::GetOpenedReceiver()
{
    return currentReceiver;
}

/** @brief Returns connection port to opened transmitter
*/
int ConnectionManager::GetOpenedTransmitter()
{
    return currentTransmitter;
}

/** @brief Writes given data to one chip register
    @param addr_reg register address 16 bits
    @param data_reg register value 16 bits
    @return command status
*/
int ConnectionManager:: mSPI_write(unsigned short addr_reg, unsigned short data_reg)
{
    unsigned short Byte_array[2];
    Byte_array[0] = addr_reg;
    Byte_array[1] = data_reg;

    if (IsOpen()==true)
        return SendData(CMD_LMS7002_WR, (unsigned char*)Byte_array, 4);
    return STATUS_UNDEFINED;
}

/** @brief Reads one register value from chip
    @param addr_reg register address 16 bits
    @return register value 16 bits
*/
unsigned short ConnectionManager:: mSPI_read(unsigned short addr_reg)
{
	int ret=0;
	unsigned short tempi=0x0000;

	unsigned short Out_array[1];
	unsigned short In_array[100];
	unsigned long retint;
	Out_array[0] = addr_reg;

    for (int i=0;i<100;i++)
        In_array[i]=0x00;

    if (IsOpen()==true)
    {
    ret = SendReadData(CMD_LMS7002_RD, (unsigned char*)Out_array, 2,(unsigned char*)In_array, retint);
    if ( (ret == STATUS_COMPLETED_CMD ) )
        tempi=In_array[1];
    }
    return tempi;
}

/** @brief Writes given data to chip without any modifications
    @param buf data buffer to write
    @param len length of data buffer
    @return true if success
*/
bool ConnectionManager::Port_write_direct(const unsigned char *buf, const unsigned long len)
{
    if(activeControlPort)
    {
        unsigned long bytesSent = activeControlPort->SendData(buf, len);
        if(bytesSent > 0)
            return true;
    }
    else
        MessageLog::getInstance()->write("Connection port not opened\n", LOG_WARNING);
    return false;
}

/** @brief Tries to read any incoming data and puts it to given buffer
    @param buf buffer for received data, must be big enough to store len bytes
    @param len number of bytes to read, after procedure it will be changed to actual number of bytes received
    @param true if success
*/
bool ConnectionManager::Port_read_direct(unsigned char *buf, unsigned long &len)
{
    unsigned char inBuffers[len];
    int bytesReceived;

    if(activeControlPort)
    {
        bytesReceived = activeControlPort->ReadData(inBuffers, len);
        memcpy(buf, inBuffers, bytesReceived);
        return true;
    }
    else
        MessageLog::getInstance()->write("Connection port not opened\n", LOG_WARNING);
    return false;
}

/** @brief Enables or Disables triple checking of received data
*/
void ConnectionManager::EnableTrippleReadChecking(bool checkMultipleReads)
{
    m_tripleCheckRead = checkMultipleReads;
}

/** @brief Clears currently used connection buffers
*/
void ConnectionManager::ClearComm()
{
    if(activeControlPort)
        activeControlPort->ClearComm();
}

void ConnectionManager::EnableTestWrittenData(bool enabled)
{
    m_testWriting = enabled;
}
