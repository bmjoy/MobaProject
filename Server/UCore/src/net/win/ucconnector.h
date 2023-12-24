#ifndef UCODECONNECTOR_H
#define UCODECONNECTOR_H

#include "ucnet.h"
#include <map>

using namespace UCODE;

/**
* @brief ����������,���ڱ�������Զ�̷�����
*/
class CUCODEConnector : public ISDConnector
{
	enum EConnStat
	{
		CONN_NONE = 0,
		CONN_PROC,
		CONN_OK
	};

public:
	CUCODEConnector();
	virtual ~CUCODEConnector();

	/**
	* @brief �������ݰ�������
	* @param poPakcetParser : ���õ����ݰ�������
	* @return void
	*/
	virtual void UCAPI SetPacketParser(ISDPacketParser* poPakcetParser);

	/**
	* @brief �������ӻỰ
	* @param poSession : ���õ����ӻỰ
	* @return void
	*/
	virtual void UCAPI SetSession(ISDSession* poSession);

	/**
	* @brief ���û����С
	* @param dwRecvBufSize : ���ý��ջ����С
	* @param dwSendBufSize : ���÷��ͻ����С
	* @return void
	*/
	virtual void UCAPI SetBufferSize(UINT32 dwRecvBufSize, UINT32 dwSendBufSize);

	/**
	* @brief ���ô�����������
	* @param dwType : ���ô�������������
	* @param pOpt : ���ô���������ֵ
	* @return void
	*/
	virtual void UCAPI SetOpt(UINT32 dwType, void* pOpt);

	/**
	* @brief ʹ�ô�����������Զ�̷�����
	* @param pszIP : ����Զ�̷�����IP��ַ
	* @param wPort : ����Զ�̷������Ķ˿ں�
	* @return �Ƿ����ӳɹ�,trueΪ�ɹ�,falseΪʧ��
	*/
	virtual bool UCAPI Connect(const char* pszIP, UINT16 wPort);

	/**
	* @brief ʹ�ô���������������Զ�̷�����
	* @return �Ƿ��������ӳɹ�,trueΪ�ɹ�,falseΪʧ��
	* @remark �������ӵ�Զ�̷�������IP�Ͷ˿�Ϊm_dwIP��m_wPort
	*/
	virtual bool UCAPI ReConnect(void);

	/**
	* @brief �ͷŴ�������
	* @return void
	*/
	virtual void UCAPI Release(void);

	/**
	* @brief ���ô���������ID��
	* @param dwID : ������������ID��
	*/
	void SetID(UINT32 dwID) { m_dwID = dwID; }

	/**
	* @brief ��ȡ����������ID��
	* @return ��ȡ��ID��
	*/
	UINT32 GetID() { return m_dwID; }

	//// 2009-03-24 cwy add for interface expanding, add bind function
	/**
	* @brief ���󶨱���IP��ַʧ��ʱ,���ô˺���
	* @param nUCODEError : UCODE Error
	* @param nSysError : Sys Error
	* @return void
	*/
	void OnBindErr(INT32 nUCODEError, INT32 nSysError);

	/**
	* @brief ��ʹ�ô����������ӳɹ�ʱ,���ô˺���
	* @return void
	*/
	void OnConnect();

	/**
	* @brief �����Ӵ���ʱ,���ô˺���
	* @param nSysError : Sys Error
	* @return void
	*/
	void OnConnectErr(INT32 nSysError);

	/**
	* @brief �����ӹر�ʱ,���ô˺���
	* @return void
	*/
	void OnClose();

protected:
	UINT32				m_dwID;
	ISDPacketParser*	m_poPacketParser;
	ISDSession*			m_poSession;
	UINT32				m_dwRecvBufSize;
	UINT32				m_dwSendBufSize;
	UINT32				m_dwIP;
	UINT16				m_wPort;
	EConnStat			m_nConnStat;
	bool					m_bNeedBind;
	const char*		m_pszBindIP;
	UINT16				m_wBindPort;
    BOOL                m_bNodelay;
};

typedef std::map<UINT32, CUCODEConnector*> CMapConnector;

#endif

