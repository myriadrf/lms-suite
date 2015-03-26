// -----------------------------------------------------------------------------
// FILE: 		ConnectionManager.h
// DESCRIPTION:	Header for ConnectionManager.cpp
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef CONNECTION_MANAGER_H
#define CONNECTION_MANAGER_H

#include "LMS7002M_Commands.h"
#include "IConnection.h"
#include <string>
#include <map>
#include "SignalHandler.h"

enum eDeviceType
{
    LMS_RECEIVER,
    LMS_TRANSMITTER,
    LMS_TRANCEIVER
};

struct DeviceInfo
{
    string name;
    eDeviceType type;
    eConnectionType port;
    int portIndex;
};

/** @brief Handles communication with device. Data writing and reading is not
    thread safe
*/
class ConnectionManager : public SignalHandler
{
public:
    static const int cMAX_CONTROL_PACKET_SIZE = 64;
    static const int cPACKET_HEADER_SIZE = 8;

    virtual void HandleMessage(const LMS_Message &msg);

	ConnectionManager();
	~ConnectionManager();

	void SetControlDevice( eDeviceType dev );
    eDeviceType GetControlDevice();

    bool IsOpen();
	bool Open();
	void Close();
	void FindDevices();

    int GetOpenedReceiver();
    int GetOpenedTransmitter();
    bool OpenReceiver(int i);
    bool OpenTransmitter(int i);
    vector<string> GetReceiverList();
    vector<string> GetTransmitterList();

    int SendData( eCMD_LMS7002M cmd, const unsigned char *data, long length);
	int SendReadData( eCMD_LMS7002M cmd, const unsigned char *outData, unsigned long oLength, unsigned char *inData, unsigned long &iLength);

	unsigned short mSPI_read(unsigned short addr_reg);
	int mSPI_write(unsigned short addr_reg, unsigned short data_reg);

	bool Port_write_direct(const unsigned char *buf, const unsigned long len);
	bool Port_read_direct(unsigned char *buf, unsigned long &len);

	void EnableTrippleReadChecking(bool checkMultipleReads);
	bool GetTriplleReadCheckingState() { return m_tripleCheckRead; };
	void ClearComm();
	void EnableTestWrittenData(bool enabled);

protected:
    int MakeAndSendPacket( eCMD_LMS7002M cmd, const unsigned char *data, long length);
    int ReadData(unsigned char *data, long &length);

    vector<DeviceInfo> m_receivers;
    vector<DeviceInfo> m_transmitters;

	/// Port used for communication.
	IConnection *activeControlPort;

	IConnection *activeTransmitter;
	IConnection *activeReceiver;
	std::map<eConnectionType, IConnection*> m_connections;

	eDeviceType m_controllingDevice;
	int currentReceiver;
	int currentTransmitter;
	bool m_system_big_endian;

	bool m_tripleCheckRead;
	bool m_testWriting;
};

#endif
