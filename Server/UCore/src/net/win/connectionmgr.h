#ifndef CONNECTIONMGR_H
#define CONNECTIONMGR_H

#include "ucsingleton.h"
#include "ucconnection.h"
#include "ucmutex.h"
#include <deque>
/**
* @brief ���ӹ�����
*
*/
class CConnectionMgr
{
	CConnectionMgr();
	~CConnectionMgr();

	DECLARE_SINGLETON(CConnectionMgr)

	typedef std::deque<CUCConnection*> CConnectionPool;
public:

	/**
	* @brief ��ʼ�����ӹ�����
	* @param nMax ���ӹ������й���������������
	* @return �Ƿ��ʼ���ɹ�,trueΪ�ɹ�,falseΪʧ��
	*/
	bool Init(INT32 nMax);

	/**
	* @brief �������ӹ�����
	* @return void
	*/
	void Uninit();

	/**
	* @brief ����һ������
	* @return ���ش���������
	*/
	CUCConnection* Create();

	/**
	* @brief ����һ������
	* @return void
	*/
	void Release(CUCConnection* poConnection);

protected:
	UINT32					m_dwNextID;
	INT32					m_nMaxConnection;
	CUCConnection*			m_pConnectionArray;
	CConnectionPool			m_oFreeList;

    CSDMutex                   m_mutex;
};

#endif

