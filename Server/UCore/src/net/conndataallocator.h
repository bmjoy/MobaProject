#ifndef __OBJECT_ALLOCATOR_EX_H__
#define __OBJECT_ALLOCATOR_EX_H__

#include "ucmutex.h"
#include "uclock.h"
#include <deque>

#include "conndatamgr.h"

static UINT32 g_connectionId = 0; 

/**
* @brief �������ݷ�����,�˷��������̰߳�ȫ��
*
*/
class ConnDataAllocator
{	
	enum 
	{
		POOL_INFLATE_SIZE= 200, 
	};
public:
	typedef size_t   size_type;
	typedef CConnData*       pointer;
	typedef CConnData&       reference;
	typedef const CConnData* const_pointer;
	typedef const CConnData& const_reference;
	typedef CConnData        value_type;

	typedef std::deque<pointer> ObjectQueue; 
	typedef ObjectQueue::iterator ObjectQueueItr; 

	ConnDataAllocator() throw() 
	{
		m_totalSize = 0; 
		m_allocSize = 0; 
		m_releaseSize = 0; 
		CSDLock<CSDMutex> lock(m_mutex); 
		inflate();
	}

	~ConnDataAllocator() throw() 
	{
		CSDLock<CSDMutex> lock(m_mutex); 
		for(ObjectQueueItr itr = m_objects.begin(); itr != m_objects.end(); ++itr)
		{
			::operator delete (*itr);
		}
		this->m_objects.clear();

		for (CMapBufPool::iterator itr = m_mapBufPool.begin(); itr != m_mapBufPool.end(); ++itr)
		{
			itr->second->Uninit();
			delete itr->second; 
		}
		m_mapBufPool.clear(); 
	}

	/**
	* @brief ��ȡ���õ�ָ��
	*/
	pointer address(reference __x) const { return &__x; }

	/**
	* @brief ��ȡ�������õĳ���ָ��
	*/
	const_pointer address(const_reference __x) const { return &__x; }

	/**
	* @brief ����һ����������
	* @param recvBufSize : �������ݵĻ����С
	* @param sendBufSize : �������ݵĻ����С
	* @return �������������
	*/
	CConnData* allocate(UINT32 recvBufSize, UINT32 sendBufSize)
	{
		m_allocSize ++;
		m_mutex.Lock();
		if (m_objects.empty())
		{
			this->inflate();
		}

		CConnData * pConnData = m_objects.front();
		m_objects.pop_front();

		CConnDataMgr * pConnDataMgr = CConnDataMgr::Instance();
		pConnData->connId= g_connectionId ++;
		pConnDataMgr->AddUsedConnData(pConnData);

		CBufPool * pRecvBufPool = FindBufPool(recvBufSize);
		pConnData->recvBuf = pRecvBufPool->Create();

		CBufPool * pSendBufPool = FindBufPool(sendBufSize);
		pConnData->sendBuf = pSendBufPool->Create();

		m_mutex.Unlock();
		return pConnData;
	}

	// __p is not permitted to be a null pointer.
	/**
	* @brief �ͷ�һ����������
	* @param pConnData : ��Ҫ���ͷŵ���������
	* @param recvBufSize : �������ݵĻ����С
	* @param sendBufSize : �������ݵĻ����С
	* @return �������������
	*/
	void deallocate(pointer pConnData, UINT32 recvBufSize, UINT32 sendBufSize)
	{ 
		m_releaseSize++;
		m_mutex.Lock();
		m_objects.push_back(pConnData);

		ReleaseBufPool(pConnData->recvBuf, recvBufSize);
		ReleaseBufPool(pConnData->sendBuf, sendBufSize);

		CConnDataMgr * pConnDataMgr = CConnDataMgr::Instance();

		
		pConnDataMgr->RemoveUsedConnData(pConnData);
		if (pConnDataMgr->m_initState == -1)
		{
			pConnDataMgr->m_initState = 0;
			// release all used data; 
			pConnDataMgr->ReleaseUsedConnData();		
		}
		m_mutex.Unlock();
	}

	/**
	* @brief ����ĳ��Socke�Ƿ�ʹ��
	* @param pSock : ��Ҫ���ҵ�Socket
	* @return �����ʹ�÷���true,���û�б�ʹ�÷���false
	*/
	bool find(CCPSock * pSock)
	{
		CSDLock<CSDMutex> lock(m_mutex);
		CConnDataMgr * pConnDataMgr = CConnDataMgr::Instance();
		return pConnDataMgr->FindUsedConnSock(pSock);
	}

	/**
	* @brief ��ȡ����dwSize��С�ڴ�Ķ����ڴ��
	* @param dwSize : �����ڴ�Ĵ�С
	* @param bCreate : ���û�и��ڴ��,�Ƿ񴴽�
	* @return ���ط���dwSize��С�ڴ�Ķ����ڴ��,���û�иô�С���ڴ��,����NULL
	*/
	CBufPool* FindBufPool(UINT32 dwSize, bool bCreate = true);

	/**
	* @brief �ͷ��ڴ浽�ڴ��
	* @param pBuf : ��Ҫ�ͷŵ��ڴ�
	* @param dwSize : ���ڴ�Ĵ�С
	*/
	void ReleaseBufPool(char * pBuf, UINT32 dwSize);

	/**
	* @brief ���ػ����Է����������ݵ�����
	* @return �����Է����������ݵ�����
	*/
	inline size_type size()
	{
		CSDLock<CSDMutex> lock(m_mutex);
		return m_objects.size();
	}

	/**
	* @brief �����ܹ�������������ݵ�����
	* @return �ܹ�������������ݵ�����
	*/
	inline size_type max_size() const throw() 
	{ 
		return m_totalSize;
	}

private:
	/**
	* @brief �����ܹ�������������ݵ�����
	* @param count : �ܹ�������������ݵ�����
	* @return void
	*/
	void inflate(int count = POOL_INFLATE_SIZE)
	{
		//NOTICE: locked outside
		for (int i = 0; i < count ;i++)
		{
			pointer  _p = static_cast<pointer>(::operator new (sizeof(value_type)));
			m_objects.push_back(_p);
		}
		m_totalSize += count;
	}

	/**
	* @brief ���������������
	*/
	ConnDataAllocator(const ConnDataAllocator&) throw() 
	{
	}
 

	ObjectQueue m_objects;
	CSDMutex m_mutex;
	int m_totalSize;
	int m_allocSize;
	int m_releaseSize;

	CMapBufPool		 m_mapBufPool;

};

#endif // 

