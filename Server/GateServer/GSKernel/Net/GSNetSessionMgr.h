#pragma once

#include "../../Share/Net/INetSessionMgr.h"
#include "ClientSession.h"

struct SProfileNet
{
	UINT32 mClientCount;
	UINT32 mTimeForDealWithMsg;//������Ϣʱ��//
	UINT32 mTimeForDealWithOther;//��������ʱ��//
	std::map<UINT32,UINT32> mMessageCount;//��Ϣ����//
};

extern SProfileNet gProfileNet;

class GSNetSessionMgr : public INetSessionMgr
{
public:
	GSNetSessionMgr();
	virtual ~GSNetSessionMgr();
public:
	virtual ISDSession* UCAPI CreateSession(ISDConnection* pConnection);
	virtual ICliSession* UCAPI CreateConnectorSession(SESSION_TYPE type);
};
