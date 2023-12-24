#pragma once

#include "INetSession.h"

class ICliSession : public INetSession
{
public:
	ICliSession();
	virtual ~ICliSession();
public:
	bool Reconnect(); 
	bool Reconnect(const char* ip, UINT32 port);
	void SetConnector(ISDConnector* connector) { m_poConnector=connector; }
	void SetRemoteEndPointer(const char* ip,UINT32 port);
	virtual void Update();
	void SetCanReconnectTag(bool can){mReconnectTag = can;}
	bool GetCanReconnectTag(){return mReconnectTag;}
public:
	virtual void UCAPI OnEstablish(void);
	virtual void UCAPI Release(void) {/*��������,���ͷŸö���*/}
private:
	ISDConnector* m_poConnector;
	UINT32 mReconTime;
	std::string mRemoteEndPointer;
	bool mReconnectTag;
};
