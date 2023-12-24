#ifndef EVENTMGR_H
#define EVENTMGR_H

#include "ucsingleton.h"
#include "ucdataqueue.h"
#include "netevent.h"
#include "ucmutex.h"
#include "ucloopbuffer.h"
#include "ucobjectpool.h"
#include "thread_buffer_pool.h"

using namespace UCODE;

class CUCConnection;

/**
* @brief �����¼�������
*/
class CEventMgr
{
	CEventMgr();
	~CEventMgr();

	DECLARE_SINGLETON(CEventMgr)

public:
	/**
	* @brief ��ʼ�������¼�������
	* @param nSize : ����ܳ���δ����������¼�������
	* @return �Ƿ��ʼ���ɹ�,trueΪ�ɹ�,falseΪ���ɹ�
	*/
	bool Init(INT32 nSize);

	/**
	* @brief ���������¼�������
	*/
	void Uninit();

	/**
	* @brief ��ȡһ��δ����������¼�(ĿǰΪ���Ȳ���������¼�)
	* @return ����һ��δ����������¼�.�������ʧ��,����NULL
	* @remark ���ڴ���ֻ�������߳��е���,����,�˺����ڲ���δ��֤�̰߳�ȫ
	*/
	inline SNetEvent*  PopFrontNetEvt()
	{
		return  (SNetEvent*)m_oEvtQueue.PopFront();
	}

	//// 2009-03-24 cwy add for interface expanding, add bind function
	inline void PushBindEvt(UINT32 dwConnectorID, INT32	 nUCODEErrCode, INT32 nSysErrCode)
	{
		SNetEvent* pstEvent = _GetFreeEvt();
		SDASSERT(pstEvent != NULL);
		pstEvent->nType = NETEVT_BIND_ERR;
		SBindErrEvt* pstBindErr		= &pstEvent->stUn.stBindErr;
		pstBindErr->dwConnectorID	= dwConnectorID;
		pstBindErr->nUCODEErrCode		= nUCODEErrCode;
		pstBindErr->nSysErrCode		= nSysErrCode;

		_PushBackNetEvt(pstEvent);
	}

	inline void PushEstablishEvt(CConnData* pConnData, bool bAccepted, UINT32 dwParentID)
	{
		SNetEvent* pstEvent = _GetFreeEvt();
		SDASSERT(pstEvent != NULL);

		pstEvent->nType					= NETEVT_ESTABLISH;
		SEstablishEvt* pstEstablishEvt	= &pstEvent->stUn.stEstablish;
		pstEstablishEvt->pConnData		= pConnData;
		pstEstablishEvt->bAccepted		= bAccepted;
		pstEstablishEvt->dwParentID		= dwParentID;

		_PushBackNetEvt(pstEvent);
	}

	inline void PushAssociateEvt(CConnData* pConnData, UINT32 dwConnectionID)
	{
		SNetEvent* pstEvent = _GetFreeEvt();
		SDASSERT(pstEvent != NULL);

		pstEvent->nType								= NETEVT_ASSOCIATE;
		pstEvent->stUn.stAssociate.pConnData		= pConnData;
		pstEvent->stUn.stAssociate.dwConnectionID	= dwConnectionID;

		_PushBackNetEvt(pstEvent);
	}

	inline void PushConnErrEvt(INT32 nSysErrCode, UINT32 dwConnectorID)
	{
		SNetEvent* pstEvent = _GetFreeEvt();
		SDASSERT(pstEvent != NULL);

		pstEvent->nType				= NETEVT_CONN_ERR;
		SConnErrEvt* pstConnErr		= &pstEvent->stUn.stConnErr;
		pstConnErr->nSysErrCode		= nSysErrCode;
		pstConnErr->dwConnectorID	= dwConnectorID;

		_PushBackNetEvt(pstEvent);
	}

	inline void PushErrorEvt(CConnData* pConnData, UINT32 dwConnectionID, INT32 nUCODEErrCode, INT32 nSysErrCode)
	{
		SNetEvent* pstEvent = _GetFreeEvt();
		SDASSERT(pstEvent != NULL);

		pstEvent->nType				= NETEVT_ERROR;
		SErrorEvt* pstError			= &pstEvent->stUn.stError;
		pstError->pConnData			= pConnData;
		pstError->dwConnectionID	= dwConnectionID;
		pstError->nUCODEErrCode		= nUCODEErrCode;
		pstError->nSysErrCode		= nSysErrCode;

		_PushBackNetEvt(pstEvent);
	}

	inline void PushTerminateEvt(CConnData* pConnData, UINT32 dwConnectionID)
	{
		SNetEvent* pstEvent = _GetFreeEvt();
		SDASSERT(pstEvent != NULL);

		pstEvent->nType					= NETEVT_TERMINATE;
		STerminateEvt* pstTerminate		= &pstEvent->stUn.stTerminate;
		pstTerminate->pConnData			= pConnData;
		pstTerminate->dwConnectionID	= dwConnectionID;

		_PushBackNetEvt(pstEvent);
	}

	inline void PushRecvEvt(CConnData* pConnData, UINT32 dwConnectionID, const char* pData, INT32 nLen)
	{
		SNetEvent* pstEvent = _GetFreeEvt();
		SDASSERT(pstEvent != NULL);
		
		pstEvent->nType							= NETEVT_RECV;
		pstEvent->stUn.stRecv.pConnData			= pConnData;
		pstEvent->stUn.stRecv.dwConnectionID	= dwConnectionID;
		pstEvent->stUn.stRecv.nLen				= nLen;

		pstEvent->stUn.stRecv.pLoopBuf = m_threadBufferPool->PushData(pData, nLen);
		if (pstEvent->stUn.stRecv.pLoopBuf != NULL)
		{
			this->_PushBackNetEvt(pstEvent);
		}

		/*
		m_oQueueLock.Lock();

		while(!m_poRecvQueue->PushBack(pData, nLen))
		{
            m_oQueueLock.Unlock();
			WARN("PushRecvEvt, PushBack data failed, sleep and try again");
			Sleep(1);
            m_oQueueLock.Lock();
		}

		pstEvent->nType = NETEVT_RECV;
		pstEvent->stUn.stRecv.pConnData		= pConnData;
		pstEvent->stUn.stRecv.dwConnectionID	= dwConnectionID;
		pstEvent->stUn.stRecv.nLen				= nLen;

		if(!m_oEvtQueue.PushBack(pstEvent))
		{
			CRITICAL("CEventMgr::_PushBackNetEvt, fail, Event Queue Full");
			SDASSERT(false);
		}
		m_oQueueLock.Unlock();
		*/
	}

	inline void PushSendEvt(CConnData * pConnData, const char * pBuf, INT32 nLen)
	{
		SNetEvent* pstEvent = _GetFreeEvt();
		SDASSERT(pstEvent != NULL);

		pstEvent->nType					= NETEVT_SEND;
		pstEvent->stUn.stSend.pConnData = pConnData;
		pstEvent->stUn.stSend.pBuf		= pBuf;
		pstEvent->stUn.stSend.dwLen		= nLen;
		_PushBackNetEvt(pstEvent);
	}

	/**
	* @brief �ͷ�һ�������¼����¼�����
	* @param pstEvt : �ͷŵ������¼�
	*/
	inline void ReleaseNetEvt(SNetEvent* pstEvt)
	{
		delete pstEvt;
	}

protected:

	/**
	* @brief ���¼����л�ȡһ�����е������¼��ṹ��
	* @return ���صĿ��е������¼��ṹ��
	*/
	inline SNetEvent* _GetFreeEvt()
	{
		return new SNetEvent;
	}

	/**
	* @brief ����һ�������¼�������
	* @param pstEvt : ����������¼�
	*/
	inline void _PushBackNetEvt(SNetEvent* pstEvt)
	{
		m_oQueueLock.Lock();
		while(!m_oEvtQueue.PushBack(pstEvt))
		{
			CRITICAL(_SDT("CEventMgr::_PushBackNetEvt, fail, Event Queue Full"));
			SDASSERT(false);
			Sleep(1);
		}
		m_oQueueLock.Unlock();
	}

	///**
	//* @brief �ͷ�һ�������¼����¼�����
	//* @param pstEvt : �ͷŵ������¼�
	//*/
	//inline void _ReleaseEvt(SNetEvent* pstEvt)
	//{
	//	m_evtPool.Free(pstEvt); 
	//}

protected:
	CSDMutex m_oQueueLock;

	CSDObjectPool<SNetEvent, CSDMutex> m_evtPool;

	CSDDataQueue		m_oEvtQueue;
	//CLoopBuffer*		m_poRecvQueue;

	ThreadBufferPool *  m_threadBufferPool;
};

#endif

