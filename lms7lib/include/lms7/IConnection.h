/**
@file lms7/IConnection.h
@author Lime Microsystems
@brief Interface class for connection types
*/

#ifndef ICONNECTION_H
#define ICONNECTION_H
#include <lms7/Config.h>

#include <string>
#include <vector>

/// Supported connection types.
enum eConnectionType
{
	CONNECTION_UNDEFINED = -1,
	COM_PORT = 0,
	USB_PORT = 1,
	SPI_PORT = 2,
	//insert new types here
	CONNECTION_TYPES_COUNT //used only for memory allocation
};

class LMS7_API IConnection
{
public:
	IConnection() : m_connectionType(CONNECTION_UNDEFINED){};
	virtual ~IConnection(){};
	virtual int RefreshDeviceList() = 0;
	virtual bool Open(unsigned i) = 0;
	virtual void Close() = 0;
	virtual bool IsOpen() = 0;
	virtual int GetOpenedIndex() = 0;

	virtual int Write(const unsigned char *buffer, int length, int timeout_ms = 0) = 0;
	virtual int Read(unsigned char *buffer, int length, int timeout_ms = 0) = 0;

	virtual std::vector<std::string> GetDeviceNames() = 0;

	virtual eConnectionType GetType() { return m_connectionType; };
	virtual bool SetParam(const char *name, const char* value) {return false;};

	virtual int BeginDataReading(char *buffer, long length){ return -1; };
	virtual int WaitForReading(int contextHandle, unsigned int timeout_ms){ return 0;};
	virtual int FinishDataReading(char *buffer, long &length, int contextHandle){ return 0;}
	virtual void AbortReading(){};

	virtual int BeginDataSending(const char *buffer, long length){ return -1; };
	virtual int WaitForSending(int contextHandle, unsigned int timeout_ms){ return 0;};
	virtual int FinishDataSending(const char *buffer, long &length, int contextHandle){ return 0;}
	virtual void AbortSending(){};
protected:
	eConnectionType m_connectionType;
};

#endif
