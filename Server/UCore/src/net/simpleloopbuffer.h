#ifndef _SIMPLE_LOOP_BUFFER_H__
#define _SIMPLE_LOOP_BUFFER_H__

#include "uctype.h"
#include "ucmutex.h"
#include "uclock.h"
using namespace UCODE;
class CSimpleLoopBuffer
{
public:
	CSimpleLoopBuffer();
	~CSimpleLoopBuffer();

	/**
	* @brief
	* ��ʼ��ѭ��������
	* @param nSize : ��ʼ����û������Ĵ�С��ʵ�ʴ�СΪnSize+1
	* @return �ɹ�����true��ʧ�ܷ���false
	*/
	bool Init(INT32 nSize);

	/**
	* @brief
	* ����Ҫ�洢��Buffer������ѭ���������Ľ�β
	* @param pData : [�������]ָ����Ҫ����ѭ����������Buffer��ʼλ��
	* @param nLen : ָ����Ҫ�����Buffer�ĳ���
	* @return ���ѭ��������ӵ�еĴ�С���ڵ���nLen������true�����򷵻�false
	* @remark �˺��������̰߳�ȫ��
	*/
	INT32 PushBack(const CHAR *pData, INT32 nLen);

	/**
	* @brief
	* ��ѭ������������ʼλ��ȡnLen���ȵ�Buffer����������Buffer��
	* @param pBuf : [�����������]��ȡ���ݵ�Buffer����ʼָ��
	* @param nLen : ��Ҫ������Buffer����
	* @return ������㹻������������ݣ�����true�����򷵻�false
	* @remark �˺��������̰߳�ȫ��
	*/
	INT32 PopFront(CHAR * &pBuf, INT32 nLen,CHAR* szData);

	/**
	* @brief
	* ����nLen���ȵ�����
	* @param nLen : ��Ҫ�����ĳ���
	* @return void
	* @remark �˺��������̰߳�ȫ��
	*/
	bool DiscardFront(INT32 nLen);

private:
	CHAR    *m_pBuffer;
	CHAR    *m_pNextRead;
	CHAR    *m_pNextWrite;
	CHAR    *m_pEnd;
	CHAR    *m_pLast;

	CSDNonMutex m_oMutex;
    typedef CSDLock<CSDNonMutex> CSDLock;
};

#endif

