// LoginServer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "SDKAsynHandler.h"
#include "SdkConnector.h"

bool DoUserCmd(const char* cmd);
bool LoadAllConfig();
bool LoadServerList();
bool Init();
void Run();
void UnInit();

CLSNetSessionMgr* gNetSessionMgr;

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleTitle(_T("ls id=1"));

	if (!Init()) 
	{
		system("pause");
		return -1;
	}

	while(true)
	{
		if (kbhit())
		{
			static char CmdArray[1024] = {0};
			static int CmdPos = 0;
			char CmdOne = getche();
			CmdArray[CmdPos++] = CmdOne;
			bool bRet = 0;
			if (CmdPos>=1024 || CmdOne==13) { CmdArray[--CmdPos]=0; bRet = DoUserCmd(CmdArray); CmdPos=0; if (bRet) break; }
		}
		SdkConnector::GetInstance().Update();
		Run();
		::Sleep(1);
	}
	UnInit();
	google::protobuf::ShutdownProtobufLibrary();
	return 0;
}

bool DoUserCmd(const char* cmd)
{
	printf("start parse cmd %s\n",cmd);

	if (stricmp(cmd,"exit")==0) return true;

	return false;
}

bool Init()
{
	gNetSessionMgr = new CLSNetSessionMgr;
	if (!LoadAllConfig())
	{
		printf("can't load all config.\n");
		return false;
	}
	if (!LoadServerList())
	{
		printf("can't load server list config.\n");
		return false;
	}
	INetSessionMgr::GetInstance()->CreateListener(gLsConfig.bs_listen_port,102400,102400,0,&gBalanceSessionFactory);//GS�˿ڳ�����
	INetSessionMgr::GetInstance()->CreateListener(gLsConfig.client_listen_port,102400,102400,1,&gClientSessionFactory);//GC�˿ڶ�����
	SDKAsynHandler::GetInstance().Init();
	return true;
}

void UnInit()
{
	delete INetSessionMgr::GetInstance();
}

void Run()
{
	INetSessionMgr::GetInstance()->Update();
}

bool LoadAllConfig()
{
	gLsConfig.client_listen_port = GetPrivateProfileInt(_T("MainGC"),_T("ListernPortForClient"),0,_T("LSConfig\\Setup.ini"));
	gLsConfig.bs_listen_port = GetPrivateProfileInt(_T("MainBS"),_T("ListernPortForBS"),0,_T("LSConfig\\Setup.ini"));
	gLsConfig.bs_base_index = GetPrivateProfileInt(_T("MainBS"),_T("BSBaseIndex"),0,_T("LSConfig\\Setup.ini"));
	gLsConfig.bs_max_count = GetPrivateProfileInt(_T("MainBS"),_T("BSMaxCount"),0,_T("LSConfig\\Setup.ini"));

	char server_key[64];
	char server_address[64];
	char server_address_ex[64];
	for (int i=1;i<=gLsConfig.bs_max_count;++i)
	{
		_snprintf(server_key, sizeof(server_key), "BS%u",i);
		GetPrivateProfileStringA("MainBS",server_key,"",server_address,64,"LSConfig\\Setup.ini");
		_snprintf(server_key, sizeof(server_key), "BS%uExport",i);
		GetPrivateProfileStringA("MainBS",server_key,"",server_address_ex,64,"LSConfig\\Setup.ini");
		sOneBsInfo& oneBsInfo = gAllBsInfo[gLsConfig.bs_base_index+i-1];
		oneBsInfo.bs_Id = gLsConfig.bs_base_index+i-1;
		oneBsInfo.bs_nets = 0;
		oneBsInfo.bs_isLost = true;
		//////////////////////////////////////////////////////////////////////////
		{
			char* portPos = strchr(server_address,':'); *portPos=0; ++portPos;
			oneBsInfo.bs_Ip = server_address;
			oneBsInfo.bs_Port = atoi(portPos);
		}
		//////////////////////////////////////////////////////////////////////////
		{
			char* exportPos = strchr(server_address_ex,':'); *exportPos=0; ++exportPos;
			oneBsInfo.bs_IpExport = server_address_ex;
			int exPos = atoi(exportPos);
			if (exPos>0)
				gNetSessionMgr->getnetip(oneBsInfo.bs_IpExport,exPos-1);
		}
	}
	return true;
}

bool LoadServerList()
{
	int listnum = GetPrivateProfileInt(_T("MainList"),_T("ServerNum"),0,_T("LSConfig\\Serverlist.ini"));
	char server_name[32];
	char server_addr[32];
	char t_name[32];
	char t_addr[32];
	memset(server_name, 0, sizeof(server_name));
	memset(server_addr, 0, sizeof(server_addr));
	memset(t_name, 0, sizeof(t_name));
	memset(t_addr, 0, sizeof(t_addr));

	//UINT32 port_id; 
	for (int i = 1; i <= listnum; ++i){
		sServerAddr serveraddr;
		memset(&serveraddr, 0, sizeof(serveraddr));

		_snprintf(t_name, sizeof(t_name), "Name%u",i);
		GetPrivateProfileStringA("MainList", t_name, "", server_name, 32, "LSConfig\\Serverlist.ini");
		_snprintf(t_addr, sizeof(t_addr), "Addr%u",i);
		GetPrivateProfileStringA("MainList", t_addr, "", server_addr, 32, "LSConfig\\Serverlist.ini");
		char* portPos = strchr(server_addr,':'); *portPos=0; ++portPos;
		serveraddr.str_port = atoi(portPos);

		string temp_addr = server_addr;
		string temp_name = server_name;

		//�Ȱ� ascii תΪ unicode 
		std::wstring  wstr_addr = SdkConnector::Acsi2WideByte(temp_addr);
		//���� unicode תΪ utf8  
		string utf8_addr = SdkConnector::Unicode2Utf8(wstr_addr);

		std::wstring  wstr_name = SdkConnector::Acsi2WideByte(temp_name);
		string utf8_name = SdkConnector::Unicode2Utf8(wstr_name);

		serveraddr.str_addr = utf8_addr;
		serveraddr.str_name = utf8_name;
		gAllServerAddr[i] = serveraddr; 
	}
	return true;
}