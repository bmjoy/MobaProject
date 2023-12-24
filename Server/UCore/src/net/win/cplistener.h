#ifndef CPLISTENER_H
#define CPLISTENER_H
#include <mswsock.h>
#include "cpsock.h"
#include "ucnet.h"
#include "conndatamgr.h"

using namespace UCODE;

/**
* @brief ��ɶ˿ڼ�����,�ڱ���Ϊ��������ʱ,������ʹ��IOCP��ʵ���ܽ������ӵ���
* ������CConnectCtrl��Ӧ
*/
class CCpListener
{
public:
	CCpListener();
	~CCpListener();

	/**
	* @brief ������ɶ˿ڼ�����ID
	* @param dwID : ���õ�ID
	* @return void
	*/
	inline void SetID(UINT32 dwID) { m_dwID = dwID; }

	/**
	* @brief �������ݰ�������
	* @param poPacketParser : ���õ����ݰ�������
	* @return void
	*/
	inline void SetPacketParser(ISDPacketParser* poPacketParser) { m_poPacketParser = poPacketParser; }

	/**
	* @brief ���ûỰ������
	* @param poSessionFactory : ���õĻỰ������
	* @return void
	*/
	inline void SetSessionFactory(ISDSessionFactory* poSessionFactory) { m_poSessionFactory = poSessionFactory; }

	/**
	* @brief ���û����С
	* @param dwRecvBufSize : ���ý��ջ����С
	* @param dwSendBufSize : ���÷��ͻ����С
	* @return void
	*/
	void SetBufferSize(UINT32 dwRecvBufSize, UINT32 dwSendBufSize) { m_dwRecvBufSize = dwRecvBufSize; m_dwSendBufSize = dwSendBufSize; }

	/**
	* @brief ��ʼ����
	* @param pszIP : ����IP��ַ
	* @param wPort : ���ض˿ں�
	* @param bReUseAddr : �Ƿ�˿ڸ���
	* @return �����ɹ�����true,����ʧ�ܷ���false
	*/
	bool Start(const char* pszIP, UINT16 wPort, bool bReUseAddr);

	/**
	* @brief ֹͣ����
	* @return void
	*/
	void Stop();

	/**
	* @brief ����һ���������ӵ�ÿIO����
	* @param pstPerIoData : �˽������������ÿIO����
	* @return �Ƿ������ӳɹ���trueΪ�ɹ�
	*/
	bool PostAcceptEx(SPerIoData* pstPerIoData);

	/**
	* @brief ���ͻ��˷���һ��������������ʱ��ִ�д˺���
	* @param bSucc : �����������Ƿ�ɹ���trueΪ�ɹ�
	* @param pstPerIoData : �˽������������ÿIO����
	* @return void
	*/
	void OnAccept(BOOL bSucc, SPerIoData* pstPerIoData);

    VOID         SetNoDelay(const BOOL bNoDelay = FALSE);
protected:

	/**
	* @brief ��ʼ�����ҽ��ܽ�������
	* @return �����Ƿ����ɹ�,trueΪ�ɹ�,falseΪʧ��
	*/
	bool _InitAcceptEx();

	/**
	* @brief ��ȡ�ɴ�ÿIO���ݽ��������ӵı������ݺ�Զ������
	* @param pstPerIoData : ÿIO����
	* @param RemoteAddr : Զ�̷������ĵ�ַ
	* @param LocalAddr : ���ط������ĵ�ַ
	*/
	void GetSockAddress(SPerIoData * pstPerIoData, sockaddr_in & RemoteAddr, sockaddr_in &  LocalAddr); 

protected:
    SPerHandleData              m_stPerHandleData;
    SOCKET                      m_hListenSock;
    LPFN_ACCEPTEX               m_lpfnAcceptEx;
    LPFN_GETACCEPTEXSOCKADDRS   m_lpfnGetAcceptExSockaddrs;
    SPerIoData*                 m_pPerIoDataArray;

    UINT32                      m_dwID;				//��Ӧ��CUCODEListener��ID
    ISDPacketParser*			m_poPacketParser;
    ISDSessionFactory*			m_poSessionFactory;
    UINT32                      m_dwRecvBufSize;
    UINT32                      m_dwSendBufSize;
    volatile bool               m_bStart;
    //CCpLock                   m_oReleaseLock;//Comment by hexi. 2009-08-21
    static CSDMutex             m_soGetAddrMutex; //lcj
    volatile UINT32             m_dwReleaseCount;//Modify by hexi.Add 'volatile' qualifer.2009-08-21
    BOOL                m_bNodelay;
};

#endif

