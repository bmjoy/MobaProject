#pragma once

class INetSession;
#include <WinSock2.h>
#include <Windows.h>
#include "..\PointerPoll.h"
#include "NetPointerPool.h"

// ������Ϣͷ����ȡ��������
struct SNetHeader
{
	int size;
	int type;
};

// ������Ϣ�ṹ��
typedef bool (*msg_handle)(const char* pMsg, int n32MsgLength, INetSession* vthis, int n32MsgID);

// ������Ϣ�ڵ㣬������������==>������Ϣ�����ַ�֮
struct MsgNode
{
	msg_handle mHandle;
	bool mIsInitMsg;
	MsgNode() { mIsInitMsg=false; mHandle=NULL; }
};

class IMsgHandle
{
public:
	IMsgHandle(int base,int max);
	virtual ~IMsgHandle();
public:
	void RegisterMsgFunc(int type, msg_handle fuc_handle,bool isInitMsg=false);
	void SetUnKnownMsgHandle(msg_handle fuc_handle);
	MsgNode* mNodes;
	msg_handle mUnknownHandle;
	int mMax;
	int mBase;
};
