// -----------------------------------------------------------------------------
// FILE: 		ConnectionCOM.h
// DESCRIPTION:	Header for ConnectionCOM.cpp
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef CONNECTION_COM_PORT_H
#define CONNECTION_COM_PORT_H

#ifndef LINUX
	#include "windows.h"
#endif

#include "IConnection.h"
#include <string>
#include <vector>
using namespace std;

class ConnectionCOM : public IConnection
{
public:
    static const int COM_BUFFER_LENGTH = 1024; //max buffer size for data

	ConnectionCOM();
	~ConnectionCOM();

	bool Open();
	bool Open(int i);
	void Close();
	bool IsOpen();

	int SendData(const unsigned char *buffer, unsigned long length, unsigned long timeout_ms = 0);
	int ReadData(unsigned char *buffer, unsigned long length, unsigned long timeout_ms = 0);

	vector<string> GetDeviceNames();
	void FindDevices();
	void ClearComm();
private:
	void FindAllComPorts();
	int Open(const char *comName, int baudrate);

	bool TestConnectivity();

	string comPortName;
	int comBaudrate;
	bool connected;

	int currentDeviceIndex;
	vector<string> comPortList;
	vector<string> m_deviceNames;

#ifndef LINUX
	HANDLE hComm;
	COMMTIMEOUTS m_ctmoNew;
	COMMTIMEOUTS m_ctmoOld;
	OVERLAPPED m_osROverlap;
	OVERLAPPED m_osWOverlap;
	DCB m_dcbCommPort;
#else
    int hComm; //com port file descriptor
#endif

};
#endif
