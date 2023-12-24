#ifndef CONNECTCTRL_H
#define CONNECTCTRL_H

#include "ucsingleton.h"
#include "ucdataqueue.h"
#include "ucnet.h"
#include "netrequest.h"
using namespace UCODE;

/**
* @brief ���ӿ�����,�ڱ���Ϊ�ͻ���ʱʹ��,�������ƶԷ���������������,����������
* ������CCpListener��Ӧ
*
*/
class CConnectCtrl
{
	CConnectCtrl();
	~CConnectCtrl();

	DECLARE_SINGLETON(CConnectCtrl)
public:

	/**
	* @brief ������������̺߳���
	* @param pParam :���̺߳����Ĳ���,����������������ӿ������ָ�뼴��
	* @return �̺߳����ķ���ֵ
	*/
	static unsigned WINAPI ThreadFunc(LPVOID pParam);

	/**
	* @brief ��ʼ���ӿ�����
	* @return �Ƿ��ʼ���ɹ�
	*/
    bool Init();

	/**
	* @brief �������ӿ�����
	* @return void
	*/
	void Uninit();

	//// 2009-03-24 cwy add for interface expanding
	// add bind function
	//bool PushBindReq(UINT32 dwConnectorID, const struct sockaddr* pstSockAddr, INT32 nSockAddrLen);
	////~

	/**
	* @brief ����"��������"
	* @param dwConnectorID : ��������ID, ��������������������
	* @param dwIP : Զ�̵�IP��ַ
	* @param wPort : Զ�̵Ķ˿ں�
	* @param poPacketParser : ���ݰ�������
	* @param poSession : ���ӵĻỰ
	* @param dwRecvBufSize : ���ջ����С
	* @param dwSendBufSize : ���ͻ����С
	* @param bNeedBind : �Ƿ���Ҫ�󶨱�����IP��ַ
	* @param pszBindIP : ���ذ󶨵�IP��ַ
	* @param wBindPort : ���ذ󶨵Ķ˿ں�
	*/
	bool PushConnReq(UINT32 dwConnectorID, UINT32 dwIP, UINT16 wPort, 
		ISDPacketParser* poPacketParser, ISDSession* poSession, 
		UINT32 dwRecvBufSize, UINT32 dwSendBufSize,
		//// 2009-03-24 cwy add for interface expanding, add bind function
		bool bNeedBind, const char* pszBindIP, UINT16 wBindPort,const BOOL bNodelay = FALSE);

	/**
	* @brief hSock������׽��ְ�IP��ַ
	* @param hSock : �׽���
	* @param pIpAddr : ��Ҫ�󶨵�IP��ַ
	* @param port : ��Ҫ�󶨵Ķ˿ں�
	*/
	bool  BindAddress(SOCKET hSock, const char * pIpAddr, UINT16 port);

	/**
	* @brief ִ�й��ܺ���
	* @return void
	*/
	void OnExecute();

protected:
	//SOCKET _CreateSocket(SConnReq* pstConnReq);

	/**
	* @brief ����"��������",��Զ�̷�������������
	* @return void
	*/
	void _ProcRequests();

	/**
	* @brief ���������¼�,�鿴�����Ƿ�ɹ�
	* @return void
	*/
	void _ProcEvents();

	/**
	* @brief �ر�����������������¼�
	* @param dwIndex : ���������¼�������
	* @return void
	*/
	void _CloseEvent(UINT32 dwIndex);

	/**
	* @brief ѹ��"��������"����,�����¼������г��ֿյ�
	* @return void
	*/
	void _CompressEvent();

	/**
	* @brief �������ӿ�����
	* @return void
	*/
	void _CleanUp();

	/**
	* @brief �����ӿ��������ʱ,ִ�д���
	* @param hSock : �׽���
	* @param pstConnReq : "��������"
	* @return void
	*/
	void _OnSockError(SOCKET hSock ,SConnReq* pstConnReq);

protected:
	bool				m_bTerminate;
	HANDLE				m_hThread;
	SConnReq*			m_pAllReqArray;
	CSDDataQueue		m_oFreeQueue;
	CSDDataQueue		m_oReqQueue;

	UINT32				m_dwSockCount;
	SConnReq**			m_pProcReqArray;
	WSAEVENT*			m_pEventsArray;
	SOCKET*				m_pSockArray;
};

#endif

