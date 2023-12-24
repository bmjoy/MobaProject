// CSUserMgr.cpp : ���� DLL Ӧ�ó���ĵ���������
#include "stdafx.h"
#include "CSUserMgr.h"
#include "CSCfgMgr.h"
#include "DBMgr.h"
#include "../ELogging/ELogging/SSActive.h"
#include "CSKernel.h"
#include "Include/FBAll_Const.h"


using namespace std;
//using namespace MysqlDWrapper;
namespace CentralServer{  
	bool CCSUserMgr::AddNotice(const SNotice& notice)
{
	UINT64 temp_date = time(NULL);
	INT64 temp = temp_date - notice.end_time;
	if (temp > 0) //��������ж�
	{
		return false;
	}
	gNoticeVec.push_back(notice);
	return true;
}
	
	UINT64 CCSUserMgr::GetCurDateTime()
{
	time_t curtime=time(0); 
	tm tim =*localtime(&curtime); 
	int day,mon,year,hour,min,sec; 
	day=tim.tm_mday;
	mon=tim.tm_mon;
	year=tim.tm_year;
	hour=tim.tm_hour;
	min = tim.tm_min;
	sec = tim.tm_sec;
	year += 1900;
	mon += 1;

	stringstream t_ss;
	t_ss<<year;
	//�¡��ա�ʱ���֡��벻����λ�Ĳ�0
	if (mon < 10){
		t_ss<<0;
	}
	t_ss<<mon;
	if (day < 10){
		t_ss<<0;
	}
	t_ss<<day;
	if (hour<10){
		t_ss<<0;
	}
	t_ss<<hour;

	//תstring
	string t_sec;
	t_ss>>t_sec;

	//תUint64
	stringstream ss;
	ss<<t_sec;

	UINT64 un64_t;
	ss>>un64_t;

	return un64_t;
}

	UINT64 CCSUserMgr::GetCDKeySurplusSec(INT64 &dateTime, UINT64 expire_time)
	{
		INT64 temp_time = expire_time - GetCurDateTime();
		INT64 temp_n64 = 0;

		dateTime += temp_time * 3600;
		temp_n64 = temp_time / 100;

		if (temp_n64 != 0)
		{
			dateTime += temp_time * 3600 * 24;
		}

		return eNormal;
	}
	
}
