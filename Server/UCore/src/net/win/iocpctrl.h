#ifndef IOCPCTRL_H
#define IOCPCTRL_H

#include "ucsingleton.h"
#include "cpsock.h"
#include <set>
#include "thread_buffer_pool.h"
using namespace UCODE;

/**
* @brief IOCP������,������һ����������,�ڲ�������2 * CPU�������߳�(Worker Item).
* ���߳�ѭ����ѯIOCP�ڲ��������¼�,�����ɴ���.�����������߳̽����ǽ����е������¼�����ѭ��
*
*/
class CIocpCtrl
{
	CIocpCtrl();
	~CIocpCtrl();

	DECLARE_SINGLETON(CIocpCtrl)

public:
	static unsigned WINAPI ThreadFunc(LPVOID pParam);

	/**
	* @brief ��ʼ��IOCP������
	* @return �Ƿ��ʼ���ɹ���trueΪ�ɹ���falseΪʧ��
	*/
	bool Init();

	/**
	* @brief ����IOCP������
	*
	*/
	void Uninit();

	/**
	* @brief ��IOCPִ��ʱ�����ô˺���
	*
	*
	*/
	void OnExecute();

	/**
	* @brief ��ĳ���׽��ֽӿڰ��ڴ�IOCP��
	* @param hSock : �󶨵��׽���
	* @param pstData : �͸��׽�����ص�����
	* @return �Ƿ�󶨳ɹ�
	*/
	bool AssociateWithIocp(SOCKET hSock, SPerHandleData* pstData);

	//inline bool PostIocpCompletionStatus(DWORD dwNumberOfBytesTransferred,
	//	ULONG_PTR dwCompletionKey,
	//	LPOVERLAPPED lpOverlapped)
	//{
	//	return PostQueuedCompletionStatus(m_hCompletionPort,
	//		dwNumberOfBytesTransferred, dwCompletionKey, lpOverlapped); 
	//}

	/**
	* @brief ����ThreadLocal�Ļ���
	* @return ���ص�ThreadLocal�Ļ���
	* @remark ����ʹ�÷�ʽ��ʹ�÷��ص�ThreadLocal�Ļ������ڵ��߳�Ϊ���ഴ�����߳�
	*/
	ThreadBufferPool * GetThreadBufferPool()
	{
		return & m_threadBufPool; 
	}

protected:
	HANDLE		m_hCompletionPort;//IO��ɶ˿ڵľ��
	INT32		m_nNumberOfWorkers;//��ǰIO��ɶ˿ڹ����Ĺ����߳�����
	HANDLE*		m_WorkerArray;

	ThreadBufferPool  m_threadBufPool; 

	static int m_acceptCount; 
};

#endif

