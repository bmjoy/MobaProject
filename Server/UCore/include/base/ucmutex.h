#ifndef UCMUTEX_H
#define UCMUTEX_H

#include "uctype.h"
#include "uccondition.h"

#if !(defined(WIN32) || defined(WIN64))
#include <pthread.h>
#endif

namespace UCODE
{
    /**
    * @defgroup groupsync �߳�ͬ��
    * @ingroup  UCODE
    * @{
    */
#if (defined(WIN32) || defined(WIN64))
    typedef CRITICAL_SECTION SDMutexId;
#else
    typedef pthread_mutex_t SDMutexId;
#endif

    BOOL SDMutexInit(SDMutexId & id);

    VOID SDMutexLock(SDMutexId & id);

    VOID SDMutexUnlock(SDMutexId & id);

    BOOL SDMutexUninit(SDMutexId &id);


    /**
    *@brief ������ʲôҲ����
    */
    class CSDNonMutex
    {
    public:

        /**
        * @brief
        * ʲôҲ����
        * @return VOID
        */
        inline VOID  Lock() {}

        /**
        * @brief
        * ʲôҲ����
        * @return VOID
        */
        inline VOID  Unlock() {}

        /**
        * @brief
        * ʲôҲ����
        * @return VOID
        */
        inline VOID  LockRead() {}

        /**
        * @brief
        * ʲôҲ����
        * @return VOID
        */
        inline VOID  LockWrite() {}
    };

    /**
    *@brief �߳�ͬ����ͨ��������
    */
    class CSDMutex
    {
        friend class CSDCondition;

    public:
        CSDMutex();
        ~CSDMutex();

        /**
        * @brief
        * ������
        * @return VOID
        */
        VOID  Lock();

        /**
        * @brief
        * �뿪��
        * @return VOID
        */
        VOID  Unlock();

        /**
        * @brief
        * �����������ǰ���ж�����߳̽���
        * @return VOID
        */
        VOID  LockRead()
        {
            Lock();
        }

        /**
        * @brief
        * ����д������ǰֻ����һ���߳̽���
        * @return VOID
        */
        VOID  LockWrite()
        {
            Lock();
        }

    private:
        //  no value sematics, therefore private and not implemented.
        CSDMutex (const CSDMutex&);
        CSDMutex& operator= (const CSDMutex&);

    private:
#if (defined(WIN32) || defined(WIN64))
        SDMutexId m_mutexId;
#else
        mutable SDMutexId m_mutexId;
#endif
    };

    /**
    *@brief �߳�ͬ����д��������
    */
    class CSDRWMutex
    {
    public:
        CSDRWMutex();
        ~CSDRWMutex();

        /**
        * @brief
        * �����������ǰ���ж�����߳̽���
        * @return VOID
        */
        VOID  LockRead();

        /**
        * @brief
        * ����д������ǰֻ����һ���߳̽���
        * @return VOID
        */
        VOID  LockWrite();

        /**
        * @brief
        * ������
        * @return VOID
        */
        VOID  Lock();

        /**
        * @brief
        * �뿪��
        * @return VOID
        */
        VOID  Unlock();

        /**
        * @brief
        * ��ǰ�ж��ٸ���ȡ�߳�ͬʱ��ȡ
        * @return ��ȡ�ߵ�����
        */
        unsigned int  ReaderCount() const;

        /**
        * @brief
        * ��ǰ�ж��ٸ�д�����߳��ڵȴ�
        * @return �ȴ�д���ߵ�����
        */
        unsigned int  PendingWriterCount() const;

    private:
        CSDMutex m_mutex;
        CSDCondition m_readCond;
        CSDCondition m_pendingWriteCond;
        unsigned int m_readerCount;
        bool m_hasWriterLock;
        unsigned int m_pendingWriteCount;
    };

    /**
    *@brief �߳�ͬ���ݹ���������
    */
    class CSDRecursiveMutex
    {
    public:
        CSDRecursiveMutex();
        ~CSDRecursiveMutex();

        /**
        * @brief
        * ������
        * @return VOID
        */
        VOID  Lock();

        /**
        * @brief
        * �뿪��
        * @return VOID
        */
        VOID  Unlock();

        /**
        * @brief
        * �����������ǰ���ж�����߳̽���
        * @return VOID
        */
        VOID  LockRead()
        {
            Lock();
        }

        /**
        * @brief
        * ����д������ǰֻ����һ���߳̽���
        * @return VOID
        */
        VOID  LockWrite()
        {
            Lock();
        }
    private:
        SDMutexId m_mutexId;
#if !(defined(WIN32) || defined(WIN64))
        pthread_mutexattr_t m_mutexAttr;
#endif
    };

    /** @} */
} //namespace UCODE



#endif

