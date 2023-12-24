// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// UserMgr.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"
#include "CSBattleMgr.h"
#include "CSUserMgr.h"
#include "CSKernel.h"
// TODO: �� STDAFX.H ��
// �����κ�����ĸ���ͷ�ļ����������ڴ��ļ�������
namespace CentralServer{
static  redisAsyncContextWrapper* m_pUserDBredisAsyncContext = nullptr;
static  redisAsyncContextWrapper* m_pLogicredisAsyncContext = nullptr;

CCSUserMgr*	GetCSUserMgrInstance()
{
	return &CCSUserMgr::GetInstance();
}

string GetLocalDayStr(){
	return boost::gregorian::to_iso_string(boost::gregorian::day_clock::local_day());
}

INT32 GetDaysDiffAwayToday(boost::gregorian::date& preDay){
	boost::gregorian::date today = boost::gregorian::day_clock::local_day();
	boost::gregorian::date_period range(preDay, today);
	return range.length().days();
}
CCSBattleMgr*	GetBattleMgrInstance(){
	return &CCSBattleMgr::GetInstance();
}

CCSKernel* GetCSKernelInstance(){
	return &CCSKernel::GetInstance();
}

static ptime sInitTime(microsec_clock::universal_time());
ptime& GetInitPtime(){
	return sInitTime;
}

INT64 GetUTCMiliSecond(){
	return (microsec_clock::universal_time() - sInitTime).total_milliseconds();
}

redisAsyncContextWrapper* GetUserDBCacheRedisHandler(){
	return m_pUserDBredisAsyncContext;
}

redisAsyncContextWrapper* GetLogicRedisHandler(){
	return m_pLogicredisAsyncContext;
}

void SetUserDBCacheRedisHandler(redisAsyncContextWrapper* predisAsyncContextWrapper){
	m_pUserDBredisAsyncContext = predisAsyncContextWrapper;
}

void SetLogicCacheRedisHandler(redisAsyncContextWrapper* predisAsyncContextWrapper){
	m_pLogicredisAsyncContext = predisAsyncContextWrapper;
}

}