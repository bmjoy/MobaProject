#pragma once

#include "../../ELogging/ELoggingHeader.h"
#include "../../ELogging/ELogging/ThreadSafeQueue.h"
#include "INetSession.h"
#include "ISrvCliSession.h"
#include "ICliSession.h"

#define LOGLEVEL (LOGLV_WARN|LOGLV_CRITICAL)
#define MAX_COUNT_LISTENER	3

class INetSessionMgr : public ISDSessionFactory, public ISDLogger, public ISDPacketParser
{
public:
	INetSessionMgr();
	virtual ~INetSessionMgr();
	static INetSessionMgr* GetInstance() {return mInstance; }
public:
	bool CreateListener(int port, int recvsize, int sendsize, int pos, ISDSessionFactory* pOtherFactory=NULL);
	virtual bool CreateConnector(SESSION_TYPE type, const char* ip, int port, int recvsize, int sendsize, int logicId);
public:
	UINT32 AddSession(INetSession* pSession);
	INetSession* GetSession(int sessionId) { return m_AllSessions.GetPointer(sessionId); }
	void RemoveSession(INetSession* pSession);
	void SendMsgToSession(SESSION_TYPE stype, int sessionId, google::protobuf::Message& sMsg, int n32MsgID);
	void SendMsgToSession(SESSION_TYPE stype, int sessionId, const std::string& sMsg, int n32MsgID);
	void SendMsgToSession(SESSION_TYPE stype, int sessionId, const char* pMsgBuffer, int n32MsgLen, int n32MsgID);
	void TranMsgToSession(SESSION_TYPE stype, int sessionId, const char* pMsgBuffer, int n32MsgLen, int n32MsgID, int n32TransId, int n32GcNet);//�Ż�GSר��(������pb)
	void Send(SESSION_TYPE stype, int sessionId,char* pBuffer);
	void StopListener(int pos) { if (pos<MAX_COUNT_LISTENER){ mListener[pos]->Stop(); } } 
	void DisconnectOne(int sessionId);
	void Update();
public:
	virtual ISDSession* UCAPI CreateSession(ISDConnection* pConnection) = 0;
	virtual ICliSession* UCAPI CreateConnectorSession(SESSION_TYPE type) = 0;
public:
	virtual bool UCAPI LogText(const TCHAR* pszLog);
	virtual bool UCAPI LogBinary(const UINT8* pLog, UINT32 dwLen);
public:
	virtual INT32 UCAPI ParsePacket(const char* pBuf, UINT32 dwLen);
public:
	IUCNet* mNetModule;//����ģ��
	ISDListener* mListener[MAX_COUNT_LISTENER];//��������
	static INetSessionMgr* mInstance;//����
	bool mIsUnSafeSend;//�Ƿ���Ҫ��ȫ����
	CRITICAL_SECTION mNetworkCs;//�ٽ���
	vector<char*> m_SafeQueue;//��ȫ����
	NetPointerPool<INetSession> m_AllSessions;//ָ���
};
