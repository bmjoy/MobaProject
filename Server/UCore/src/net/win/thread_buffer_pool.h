#ifndef __THREAD_BUFFER_POOL_H__
#define __THREAD_BUFFER_POOL_H__

#include <Windows.h>
#include "simpleloopbuffer.h"
#include <iostream>
#include "ucnetwin.h"

/**
* @brief ʵ��һ���̰߳�ȫ�ģ��ڲ�ͬ�̴߳���ͬ��Buffer�أ�ʹ��ThreadLocal�ķ�ʽ��
*
*
*/
class ThreadBufferPool
{
public:
	ThreadBufferPool()
	{
		m_tlsIndex = TlsAlloc();
	}
 
	/**
	* @brief ����ThreadLocal�Ļ���
	*
	*
	*/
	BOOL CreateThreadBuffer()
	{
		LPVOID pBuf = (LPVOID)LocalAlloc(LPTR, sizeof(CSimpleLoopBuffer));
		if (!TlsSetValue(m_tlsIndex, pBuf))
        {
            LocalFree((HLOCAL) pBuf);
            return FALSE;
        }
        CSimpleLoopBuffer * pLoopBuf = new (pBuf)CSimpleLoopBuffer();
        pLoopBuf->Init( g_nLoopSize );
        return TRUE;
	}

	/**
	* @brief �ͷ�ThreadLocal�Ļ���
	*
	*
	*/
	void ReleaseThreadBuffer()
	{
		if (CSimpleLoopBuffer * pBuf = (CSimpleLoopBuffer*)TlsGetValue(m_tlsIndex))
        {
            pBuf->~CSimpleLoopBuffer();
			LocalFree((HLOCAL) pBuf);
		}
	}

	/**
	* @brief ��ThreadLocal�Ļ����������
	* @param pData : ���������ָ��
	* @param nLen : ���ݵĳ���
	* @return ThreadLocal�Ļ��棬��Ҫע����ǣ����صĻ�����̰߳�ȫ����Ҫ���û���֤��
	* �û���Ҫ��ȷ���صĻ���ֻ�ڵ�ǰ���߳���ʹ��
	*/
	CSimpleLoopBuffer * PushData(const char * pData, int nLen)
	{
		if (CSimpleLoopBuffer* pLoopBuf = (CSimpleLoopBuffer*)TlsGetValue(m_tlsIndex))
        {
            INT32 nResult = pLoopBuf->PushBack(pData, nLen);
            if (nResult != nLen)
            {
                CRITICAL(_SDT("[%s:%d]:Loopbuffer is busy!ThreadID:%d,Len:%d,Error:%d"),
                    MSG_MARK,
                    GetCurrentThreadId(),
                    nLen,
                    nResult);
                do
                {
                    Sleep(1);
                } while (pLoopBuf->PushBack(pData, nLen) != nLen);
            }
            return pLoopBuf;
		}
        return 0;
	}
private:

	DWORD  m_tlsIndex;
};


#endif // 

