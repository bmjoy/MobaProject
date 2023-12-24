#include "ucnetconfig.h"
#include "connectionmgr.h"
#include "uclock.h"

IMPLEMENT_SINGLETON(CConnectionMgr)

CConnectionMgr::CConnectionMgr()
{
	m_dwNextID			= 0;
	m_nMaxConnection	= 0;
	m_pConnectionArray	= NULL;
}

CConnectionMgr::~CConnectionMgr()
{
}

bool CConnectionMgr::Init(INT32 nMax)
{
	m_pConnectionArray = new CUCConnection[nMax];
	if(NULL == m_pConnectionArray)
	{
		CRITICAL(_SDT("CConnectionMgr::Init, new CUCConnection[%d] failed"), nMax);
		return false;
	}

	m_nMaxConnection = nMax;
	for(INT32 i = 0; i < nMax; i++)
	{
		m_oFreeList.push_back(&m_pConnectionArray[i]);
	}

	return true;
}

void CConnectionMgr::Uninit()
{
	if(m_pConnectionArray != NULL)
	{
		delete [] m_pConnectionArray;
		m_pConnectionArray = NULL;
	}
}

//
// ���̵߳��ã�IOCP�̣߳������̣߳��������������߳����ͬһ�����ͬʱ���õĿ���
//
CUCConnection* CConnectionMgr::Create()
{
	CUCConnection* poConnection = NULL;

    m_mutex.Lock(); 
	if(!m_oFreeList.empty())
	{
		poConnection = m_oFreeList.front();
		m_oFreeList.pop_front();
		poConnection->SetID(++m_dwNextID);
	}
	m_mutex.Unlock(); 

	return poConnection;
}

//
// ���̵߳��ã����̣߳�IOCP�̣߳������̣߳��������������߳����ͬһ�����ͬʱ���õĿ���
//
void CConnectionMgr::Release(CUCConnection* poConnection)
{
	if(NULL == poConnection)
	{
		return;
	}

	poConnection->Reset();

	m_mutex.Lock(); 
	m_oFreeList.push_back(poConnection);
	m_mutex.Unlock(); 
}

