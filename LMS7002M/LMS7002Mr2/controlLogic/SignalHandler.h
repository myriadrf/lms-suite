// -----------------------------------------------------------------------------
// FILE: 		SignalHandler.h
// DESCRIPTION: Header for SignalHandler.cpp
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef LMS_SIGNAL_HANDLER
#define LMS_SIGNAL_HANDLER

#include <vector>
#include <string>
using namespace std;
class SignalHandler;

enum LMS_MessageType
{
    MSG_UNDEFINED,
	MSG_BOARD_CONNECTED,
	MSG_BOARD_DISCONNECTED,
	MSG_BOARD_RESET,
	MSG_REGISTER_TEST,
	MSG_CHANNEL_CHANGED,
	MSG_REGISTER_VALUE_SET,
	MSG_PROGRAMMING_PACKET_SENT,
	MSG_CRITICAL_ERROR,
	MSG_SHOW_WARNING
};

struct LMS_Message
{
    LMS_Message() : type(MSG_UNDEFINED), text("Empty"), param1(0), param2(0) {};
    LMS_Message(LMS_MessageType type, const string text, const int p1, const int p2) :
        type(type), text(text), param1(p1), param2(p2) {};
	LMS_MessageType type;
	string text;
	int param1;
	int param2;
};

class SignalHandler
{
public:
	SignalHandler();
	virtual ~SignalHandler();

	void RegisterForNotifications(SignalHandler *handler);
	void UnregisterFromNotifications(SignalHandler *handler);

	void Notify(const LMS_Message &msg);

	/// Method used to handle incoming messages
	virtual void HandleMessage(const LMS_Message &msg) = 0;
protected:
	vector< SignalHandler* > m_listeners;
};

#endif
