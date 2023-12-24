// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include <SDKDDKVer.h>
#include <boost/asio.hpp>
#include <stdio.h>
#include <tchar.h>

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include <WinSock2.h>
#include <Windows.h>
#include <conio.h>
#include <atlconv.h>
#include "Net\LSNetSessionMgr.h"
#include "../../ThirdFunc/MsgLists/GSToBS.pb.h"
#include "../../ThirdFunc/MsgLists/BSToLS.pb.h"
#include "../../ThirdFunc/MsgLists/LSToBS.pb.h"
#include "../../ThirdFunc/MsgLists/LSToGC.pb.h"
#include "../../ThirdFunc/MsgLists/GCToBS.pb.h"
#include "../../ThirdFunc/MsgLists/LSToSDK.pb.h"
#include "../../ThirdFunc/MsgLists/SDKToLS.pb.h"
#include "../../CommonCPlus/Include/FBAll_Const.h"
#include "GCToLS.pb.h"
#include <boost/shared_ptr.hpp>
#include "../../ThirdFunc/MsgLists/ParseProto.h"

struct sLSConfig
{
	INT32 bs_listen_port;
	INT32 bs_base_index;
	INT32 bs_max_count;
	INT32 client_listen_port;
};
extern sLSConfig gLsConfig;

struct sServerAddr
{
	string str_name;
	string str_addr;
	UINT32 str_port;
};
extern map<UINT32,sServerAddr> gAllServerAddr;

struct sOneBsInfo
{
	bool bs_isLost;
	UINT32 bs_nets;
	string bs_IpExport;	//bs ���⹫����ַ//
	string bs_Ip;		//bs ������֤��ַ//
	UINT32 bs_Port;
	UINT32 bs_Id;
};
extern map<UINT32,sOneBsInfo> gAllBsInfo; 

struct LoginUserInfo
{
	string uin;
	string sessionid;
	UINT32 plat;
};
struct UserLoginData{
	int platFrom;
	string sessionid;
	string uin;
};