#ifndef CPSOCK_H
#define CPSOCK_H

#include "ucnet.h"
#include "uclock.h"
#include "uccondition.h"
#include "ucnetconfig.h"
#include "ucnetopt.h"

using namespace UCODE;

class CCPSock;

enum EIocpOperation
{
	IOCP_RECV = 0,
	IOCP_SEND,
	IOCP_ACCEPT,
	IOCP_CONNECT, 
	IOCP_CLOSE
};

/**
* @brief ÿ�������,�;��������һ�������
*/
struct SPerHandleData
{
	bool		bListen;
	void*		ptr;
};

/**
* @brief ÿ��IO������,��ÿ��IO����������һ�������
*/
struct SPerIoData
{
	OVERLAPPED		stOverlapped;
	SOCKET			hSock;
	EIocpOperation	nOp;
	WSABUF			stWsaBuf;
	char			Buf[128];
};

struct CConnData;

/**
* @brief ����һ���׽�����
*
*/
class CCPSock
{
public:
	CCPSock();
	~CCPSock();

	/**
	* @brief ���ô��׽�����
	*
	*/
	void Reset();

	/**
	* @brief ���ô��׽�������׽���
	* @param �����õ��׽�����
	*/
	inline void SetSock(SOCKET hSock) { m_hSock = hSock; }

	/**
	* @brief ���ش��׽�������������׽���
	* @return ���ص��׽���
	*/
	inline SOCKET GetSock() { return m_hSock; }

	/**
	* @brief �ڴ��׽����ϸ��ӷ�����Ϣ�Ļ���
	* @param pRecvBuf : ������Ϣ�Ļ���
	* @param dwRecvBufSize : ������Ϣ����Ĵ�С
	*/
	void AttachRecvBuf(char* pRecvBuf, UINT32 dwRecvBufSize);

	/**
	* @brief ������׽����ϸ��ӵķ�����Ϣ����,ִ�д˺�����,���׽����಻�ٸ����κη��ͻ���
	* @param ppRecvBuf : [�������]��ȡ������ķ�����Ϣ����
	* @return ԭ���ӵķ�����Ϣ����Ĵ�С
	*/
	UINT32 DetachRecvBuf(char** ppRecvBuf);

	/**
	* @brief �ڴ��׽����ϸ��ӽ�����Ϣ�Ļ���
	* @param pSendBuf : ������Ϣ�Ļ���
	* @param dwSendBufSize : ������Ϣ����Ĵ�С
	*/
	void AttachSendBuf(char* pSendBuf, UINT32 dwSendBufSize);

	/**
	* @brief ������׽����ϸ��ӵĽ�����Ϣ����,ִ�д˺�����,���׽����಻�ٸ����κν��ջ���
	* @param ppSendBuf : [�������]��ȡ������Ľ�����Ϣ����
	* @return ԭ���ӵĽ�����Ϣ����Ĵ�С
	*/
	UINT32 DetachSendBuf(char** ppSendBuf);

	/**
	* @brief ��������׽�����ص�"��������"
	* @param pConnData : ���õ�"��������"
	*/
	void SetConnData(CConnData* pConnData);

	/**
	* @brief ��ȡ����׽�����ص�"��������"
	* @return ��ȡ��"��������"
	*/
	CConnData *GetConnData () {return this->m_pConnData;}

	/**
	* @brief ��������׽�����ص����ݰ�������
	* @param poPacketParser : ���õ����ݰ�������
	*/
	inline void SetPacketParser(ISDPacketParser* poPacketParser) { m_poPacketParser = poPacketParser; }

	/**
	* @brief �����Ƿ�����
	* @param bConnect : �����Ƿ�����
	* @return void
	*/
	inline void SetConnect(BOOL bConnect)
	{
		m_bConnect = bConnect;
	}

	/**
	* @brief �鿴���׽����Ƿ�����
	* @return trueΪ����,falseΪû������
	*/
	inline BOOL IsConnect()
	{
		return m_bConnect;
	}

	//UINT32 IncDelayReleaseStamp() { return ++m_dwDelayReleaseStamp; }

	/**
	* @brief ʹ�ô��׽����෢������
	* @param pData : ָ�������ݰ���ָ��
	* @param dwLen : ���͵����ݰ�����
	*/
	void Send(const char* pData, UINT32 dwLen);

		/**
	* @brief ʹ�ô��׽����෢������
	* @param pData : ָ�������ݰ���ָ��
	* @param dwLen : ���͵����ݰ�����
	*/
	void UpdateSend();

	/**
	* @brief ʹ�ô��׽�����ͬ����������
	* @param pData : ָ�������ݰ���ָ��
	* @param dwLen : ���͵����ݰ�����
	*/
	INT32 SyncSend(const char * pData, UINT32 dwLen);

	/**
	* @brief ʹ�ô��׽������첽��������
	* @param pData : ָ�������ݰ���ָ��
	* @param dwLen : ���͵����ݰ�����
	*/
	bool AsyncSend(const char* pData, UINT32 dwLen);

	/**
	* @brief ���û��رմ��׽�����
	* @return void
	*/
	void Close(); //close from user 

	/**
	* @brief �����׽�����IO��ɶ˿ڹ�������
	* @return trueΪ�����ɹ�,falseΪ����ʧ��
	*/
	bool AssociateWithIocp();

	/**
	* @brief ���ͽ��������¼�
	* @return �Ƿ��ͽ��������¼��ɹ�,�ɹ�����true,ʧ�ܷ���false
	*/
	bool PostRecv();

	/**
	* @brief ���յ�������
	* @param dwBytes : ���յ���������
	*/
	void OnRecv(DWORD dwBytes);

	/**
	* @brief ����������
	* @param dwBytes : ���͵�������
	*/
	void OnSend(DWORD dwBytes);

	/**
	* @brief ��IOCP�յ��ر�����ʱ,���ô˺���
	* @param bPassive : trueΪҵ���߳������ر�,falseΪ�ڲ��̱߳����ر�
	*/
	void OnClose(bool bPassive = true); // close from IOCP Queue. 

	/**
	* @brief ��ʵ�ر��׽���
	* @return void
	*/
	void DoClose();

#ifdef UCODENET_HAS_GATHER_SEND 
	Condition             m_sendCond; 
	void    OnSendOut();
	volatile UINT32  m_hasCollectSent;	
#endif

	/**
	* @brief ���ӷ�����Ϣ����һ
	*/
	inline void IncPostSend()
	{
		InterlockedIncrement((LONG*)&m_dwPostSend);
	}

	/**
	* @brief ���ٷ�����Ϣ����һ
	*/
	inline void DecPostSend()
	{
		InterlockedDecrement((LONG*)&m_dwPostSend);
	}

	/**
	* @brief ��ȡĿǰ���еķ�����Ϣ����
	* @return Ŀǰ���еķ�����Ϣ����
	*/
    UINT32 GetPostSend(void)
	{
		return InterlockedExchange((LONG*)&m_dwPostSend, m_dwPostSend);
	}

	/**
	* @brief ���ӽ�����Ϣ����һ
	*/
	inline void IncPostRecv()
	{
		InterlockedIncrement((LONG*)&m_dwPostRecv);
	}

	/**
	* @brief ���ٽ�����Ϣ����һ
	*/
	inline void DecPostRecv()
	{
		InterlockedDecrement((LONG*)&m_dwPostRecv);
	}

	/**
	* @brief ��ȡĿǰ���еĽ�����Ϣ����
	* @return Ŀǰ���еĽ�����Ϣ����
	*/
	UINT32 GetPostRecv(void)
	{
		return InterlockedExchange((LONG*)&m_dwPostRecv, m_dwPostRecv);
	}

	//// cwy add 2009-03-23, interface expanding
	// returns the free send-buffer size
	/**
	* @brief ����δʹ�õķ��ͻ���
	*/
	inline UINT32 GetSendBufFree(void){ return m_dwSendBufSize - m_nDataSend; }

	/**
	* @brief ��ȡ��������ID��
	*/
    inline UINT32 GetConnectionID(); 
	
	/**
	* @brief ��ȡ���ͻ����С
	* @return ���ͻ����С
	*/
	inline UINT32  GetSendBufSize() { return m_dwSendBufSize; }

	/**
	* @brief ��ȡ���ջ����С
	* @return ���ջ����С
	*/
	inline UINT32  GetRecvBufSize() { return m_dwRecvBufSize; }

    void SetSendStrategy(const SSendStrategy &stSendStrategy) {m_stSendStrategy = stSendStrategy;}
protected:
	/**
	* @brief ������Ϣ�¼�
	* @return �����¼��Ƿ�ɹ�,trueΪ�ɹ�,falseΪʧ��
	*/
	bool _PostSend();

	bool _PostClose(SOCKET hSock); 

	void _OnError(INT32 nUCODEError, INT32 nSysError);

protected:
	SOCKET				m_hSock;
	volatile BOOL		m_bConnect;
	volatile BOOL		m_bSendData;
	bool				m_bThreadSafe;
	//UINT32			m_dwDelayReleaseStamp;	//�ӳ��ͷ�ʱ���
	char*				m_pSendBuf;
	char*				m_pRecvBuf;
	UINT32				m_dwRecvBufSize;
	UINT32				m_dwSendBufSize;
	INT32				m_nDataReceived;	//���յ������ݵĳ���
	INT32				m_nDataSend;		//�����͵����ݵĳ���
	SPerHandleData		m_stPerHandleData;
	
	SPerIoData          m_stCloseIoData; 
	SPerIoData			m_stRecvIoData;
	SPerIoData			m_stSendIoData;	

	//static int user_close_count ;
	//static int on_close_count; 
 
	/*static*/ 
    CSDMutex			m_sendMutex;

	CConnData*			m_pConnData;
	//UINT32				m_dwConnectionID;	//m_poConnection��ָ��Ķ�����ܱ��ͷź��ֱ����·��䣬�����ҪID�������Ƿ������������
	ISDPacketParser*	m_poPacketParser;
    //volatile UINT32     m_dwPostRecv;       //δ����WSARecv������
	//Modify by hexi.Add 'volatile' qualifer.2009-08-21
    volatile UINT32		m_dwPostSend;       //δ����WSASend������
	volatile UINT32		m_dwPostRecv;       //δ����WSARecv������

    SSendStrategy       m_stSendStrategy;
    //bool                m_bIsNeedForceClean;
};

#endif

