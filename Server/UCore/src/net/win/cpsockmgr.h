#ifndef CPSOCKMGR_H
#define CPSOCKMGR_H

#include <list>
#include "ucobjectpool.h"
#include "ucsingleton.h"
#include "cpsock.h"
#include "ucmutex.h"
#include "bufpool.h"

using namespace UCODE;

typedef std::list<CCPSock*> CCPSockList;

/**
* @brief �׽����������
*/
class CCPSockMgr
{
	CCPSockMgr();
	~CCPSockMgr();

	DECLARE_SINGLETON(CCPSockMgr)

public:
	/**
	* @brief ��ʼ���׽����������
	* @param nMax : ����׽���������
	* @return ��ʼ���ɹ�,����true,��ʼ��ʧ��,����false
	*/
	bool Init(INT32 nMax);

	/**
	* @brief �����׽����������
	* @return void
	*/
	void Uninit();

	/**
	* @brief ����һ���׽�����
	* @param dwRecvBufSize : ���׽���������Buf
	* @param dwSendBufSize : ���׽��������Buf
	* @return �������׽�����
	*/
	CCPSock * Create(UINT32 dwRecvBufSize, UINT32 dwSendBufSize);

	/**
	* @brief ����һ���׽�����
	* @param poSock : ���յ��׽�����
	* @return void
	*/
	void Release(CCPSock* poSock);

	//void DelayRelease(CCPSock* poSock);
	//void CheckDelayRelease();

#if UCODENet_Has_CollectBuffer_BeforeSend
    void OnSendOut();
    std::set<CCPSock*>      m_oSendSockList;
#endif

protected:

	/**
	* @brief �ڲ�����һ���׽�����
	* @param dwRecvBufSize : ���׽���������Buf
	* @param dwSendBufSize : ���׽��������Buf
	* @return �������׽�����
	*/
	CCPSock * _Create(UINT32 dwRecvBufSize, UINT32 dwSendBufSize);

	/**
	* @brief �ڲ�����һ���׽�����
	* @param dwRecvBufSize : ���׽���������Buf
	* @param dwSendBufSize : ���׽��������Buf
	* @return �������׽�����
	*/
	void _Release(CCPSock* poSock);

	/**
	* @brief ���ҷ���dwSize��С����Ļ����
	* @param dwSize : ����ط���Ĵ�СdwSize
	* @param bCreate : �Ƿ�������Ѿ������ɹ��Ļ����,�ֻ������û�д����ɹ��Ļ����,�����û����
	* @return ���ش˻����
	*/
	CBufPool* _FindBufPool(UINT32 dwSize, bool bCreate = true);

protected:
	CCPSock*				m_pSockArray;
	INT32					m_nSockCount;
	CCPSockList				m_oFreeList;
	CCPSockList				m_oDelayReleaseList;
	CMapBufPool				m_oMapBufPool;
	CSDMutex                  m_oLock;
	time_t					m_nLastCheckTime;
	SOCKET*					m_pSockHandleArray;
};

#endif

