// LogServer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Net/LogNetSessionMgr.h"
#include "LogHandler.h"
int main()
{
	auto res = CLogHandler::GetInstance().Init();
	if (res){
		while(true){
			INetSessionMgr::GetInstance()->Update();
			Sleep(1);
		}
	}

	return 0;
}

