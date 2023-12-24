#ifndef NETREQUEST_H
#define NETREQUEST_H

#include "ucnet.h"
#include <list>

using namespace UCODE;

enum ENetReqType
{
	NETREQ_INVALID = 0,
	NETREQ_CONNECT,
	NETREQ_DISCONN,
};

/**
* @brief ���Ӵ�������ṹ��
*/
struct SConnReq
{
	UINT32				dwConnectorID;
	UINT32				dwIP;
	UINT16				wPort;
	UINT16				wBindPort;
	const char*			pszBindIP;

	ISDPacketParser*	poPacketParser;
	ISDSession*			poSession;
	UINT32				dwRecvBufSize;
	UINT32				dwSendBufSize;
	bool				bNeedBind;
    BOOL                bNoDelay;
};

/**
* @brief �Ͽ���������ṹ��
*/
struct UCODEisconnReq
{
	UINT32				dwConnectorID;
};

/**
* @brief ��������ṹ��
*/
struct SNetRequest
{
	ENetReqType		nType;
	union
	{
		SConnReq			stConn;
		UCODEisconnReq			stDisConn;
	}stUn;
};

typedef std::list<SNetRequest*> CNetReqList;

#endif

