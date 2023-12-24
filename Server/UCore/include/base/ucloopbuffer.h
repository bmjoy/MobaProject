#ifndef UCLOOPBUFFER_H
#define UCLOOPBUFFER_H

/**
* @file sdloopbuffer.h
* @brief ѭ����������
**/

#include "uctype.h"

namespace UCODE
{
    /**
    * @defgroup grouploopbuffer ѭ��������
    * @ingroup  UCODE
    * @{
    */

    /**
    * @brief ѭ����������֧�ֵ��̶߳�д
    */
    class CSDLoopBuffer
    {
    public:
        CSDLoopBuffer(VOID);
        ~CSDLoopBuffer(VOID);

        /**
        * @brief
        * ��ʼ��ѭ��������
        * @param nSize : ��ʼ����û������Ĵ�С��ʵ�ʴ�СΪnSize+1
        * @return �ɹ�����TRUE��ʧ�ܷ���FALSE
        */
        BOOL  Init(INT32 nSize);

        /**
        * @brief
        * ����Ҫ�洢��Buffer������ѭ���������Ľ�β
        * @param pData : [�������]ָ����Ҫ����ѭ����������Buffer��ʼλ��
        * @param nLen : ָ����Ҫ�����Buffer�ĳ���
        * @return ���ѭ��������ӵ�еĴ�С���ڵ���nLen������TRUE�����򷵻�FALSE
        * @remark �˺��������̰߳�ȫ��
        */
        BOOL  PushBack(const CHAR *pData, INT32 nLen);

        /**
        * @brief
        * ��ѭ������������ʼλ��ȡnLen���ȵ�Buffer����������Buffer��
        * @param pBuf : [�����������]��ȡ���ݵ�Buffer����ʼָ��
        * @param nLen : ��Ҫ������Buffer����
        * @return ������㹻������������ݣ�����TRUE�����򷵻�FALSE
        * @remark �˺��������̰߳�ȫ��
        */
        BOOL  PopFront(CHAR *pBuf, INT32 nLen);

        /**
        * @brief
        * ����nLen���ȵ�����
        * @param nLen : ��Ҫ�����ĳ���
        * @return VOID
        * @remark �˺��������̰߳�ȫ��
        */
        VOID  DiscardFront(INT32 nLen);

    private:
        CHAR    *m_pBuffer;
        CHAR    *m_pHead;
        CHAR    *m_pTail;
        INT32	m_nSize;
    };

    /** @} */
}

#endif

