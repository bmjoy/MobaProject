#ifndef UCODENETWIN_H
#define UCODENETWIN_H

#include "ucnet.h"
#include "ucsingleton.h"
#include "ucconnector.h"
#include "ucloopbuffer.h"
#include "netevent.h"
#include "cpsock.h"
#include <vector>
using namespace UCODE;

struct SendOutTimer;

class CUCODENetWin : public IUCNet
{
	CUCODENetWin();
	virtual ~CUCODENetWin();

	DECLARE_SINGLETON(CUCODENetWin)

public:
	//Interface IUCODEBase
	
	/**
	* @brief ���Ӷ�UCODENet������
	* @return void
	*/
	virtual void UCAPI AddRef(void);

	/**
	* @brief ��ѯĿǰ���õ�����
	* @return ����Ŀǰ���õ�����
	*/
	virtual UINT32  UCAPI QueryRef(void);

	/**
	* @brief ���ٶ�UCODENet������,������Ϊ0,�ͷŴ���
	* @return void
	*/
	virtual void UCAPI Release(void);

	/**
	* @brief ��ȡ����İ汾
	* @return ���ش���İ汾��
	*/
	virtual SUCODEVersion UCAPI GetVersion(void);

	/**
	* @brief ���ش��������
	* @return ���ش��������
	*/
	virtual const char * UCAPI GetModuleName(void);

	//Interface IUCNet

	/**
	* @brief ��������������
	* @param dwNetIOType : �������ӵ�����,����ֻ��NETIO_COMPLETIONPORT
	* @return ����������������
	*/
	virtual ISDConnector* UCAPI CreateConnector(UINT32 dwNetIOType);

	/**
	* @brief �������������
	* @param dwNetIOType : �������������,
	* ������NETIO_COMPLETIONPORT��NETIO_COMPLETIONPORT_GATE
	* @return ���������������
	*/
	virtual ISDListener*  UCAPI CreateListener(UINT32 dwNetIOType);

	/**
	* @brief �����߳�������UCODENet���߼�����
	* @param nCount : �˴����е��߼������ĸ���
	* @return bool : �Ƿ�������nCount���߼�����
	*/
	virtual bool UCAPI Run(INT32 nCount);

	/**
	* @brief ��ʼ��UCODENet
	* @return trueΪ��ʼ���ɹ�,falseΪ��ʼ��ʧ��
	*/
	bool Init();

	/**
	* @brief ����UCODENet
	* @return trueΪ����ɹ�,falseΪ����ʧ��
	*/
	void Uninit();

	/**
	* @brief �ͷ�����������
	* @return trueΪ����ɹ�,falseΪ����ʧ��
	*/
	void ReleaseConnector(CUCODEConnector* poConnector);

	/**
	* @brief ����dwID��������������
	* @return ���ص�����������,����ʧ��,����NULL
	*/
	CUCODEConnector* FindConnector(UINT32 dwID);

	typedef std::vector<CCPSock * > ConnectedSockets; 

#ifdef UCODENET_HAS_GATHER_SEND 
	ConnectedSockets m_connSockets; 
    void FlushBufferedData()
	{
		for (ConnectedSockets::iterator itr = m_connSockets.begin();
				itr != m_connSockets.end(); ++itr)
		{
			(*itr)->OnSendOut(); 
		}
	}
#endif // 

	/**
	* @brief ������յ���������
	* @param pConnData : "��������"
	* @param pData : ���յ���������
	* @param len : �������ݵĳ���
	*/
	void ProcRecvData(CConnData * pConnData, const char * pData, int len); 

protected:
	/**
	* @brief ����UCODENet���
	* @return �Ƿ񴴽�����ɹ�,trueΪ�ɹ�,falseΪʧ��
	*/
	bool _CreateComponent();

	/**
	* @brief ��ʼ��UCODENet���
	* @return �Ƿ��ʼ������ɹ�,trueΪ�ɹ�,falseΪʧ��
	*/
	bool _InitComponent();

	/**
	* @brief ����UCODENet���
	* @return void
	*/
	void _UninitComponent();

	/**
	* @brief �ݻ�UCODENet���
	* @return void
	*/
	void _DesroryComponent();

	/**
	* @brief ��������������
	* @return void
	*/
	void _ClearConnector();

	void _ProcEstablishEvt(SEstablishEvt* pstEvent);
	void _ProcAssociateEvt(SAssociateEvt* pstEvent);
	void _ProcConnErrEvt(SConnErrEvt* pstEvent);
	void _ProcErrorEvt(SErrorEvt* pstEvent);
	void _ProcTerminateEvt(STerminateEvt* pstEvent);
	void _ProcRecvEvt(SRecvEvt* pstEvent);
	void _ProcSendEvt(SSendEvt* pstEvent);
	//// 2009-03-24 cwy add for interface expanding, add bind function
	void _ProcBindErrEvt(SBindErrEvt* pstEvent);

protected:
	UINT32			m_dwRef;
	UINT32			m_dwNextConnectorID;
	CMapConnector	m_oMapConnector;
	char*			m_pRecvBuf;
    UINT32          m_dwLastTick;    
};

#endif

