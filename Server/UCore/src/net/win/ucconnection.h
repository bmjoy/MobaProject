#ifndef UCODECONNECTION_H
#define UCODECONNECTION_H

#include "ucnetconfig.h"
#include "ucnet.h"


using namespace UCODE;

struct CConnData;

#define	 NET_SEND_BUFFER_SIZE		1024

struct SNetSendBuffer
{
	SNetSendBuffer():dwLen(0){}
	char    cBuffer[NET_SEND_BUFFER_SIZE];
	UINT32  dwLen;
};

/**
* @brief ����һ���������ӵ���
*/
class CUCConnection : public ISDConnection
{
	enum EConnStat
	{
		CONN_NONE = 0,
		CONN_OK,
		CONN_ASSOCIATE,
		CONN_CLOSING,
	};
public:
	CUCConnection();
	virtual ~CUCConnection();

	/**
	* @brief �������Ƿ�Ϊ���ӵ�
	* @return ����true�������ӵ�,����false����Ͽ���
	*/
	virtual bool UCAPI IsConnected(void);

	/**
	* @brief ʹ�ô����ӷ�������
	* @param pBuf : ָ���͵����ݵ�ָ��
	* @param dwLen : �������ݵĳ���
	*/
	virtual void UCAPI Send(const char* pBuf, UINT32 dwLen);

	/**
	* @brief ���ô����ӵĲ���
	* @param dwType : ��������
	* @param pOpt : ��������
	* @return void
	*/
	virtual void UCAPI SetOpt(UINT32 dwType, void* pOpt);

	/**
	* @brief �Ͽ�����
	* @return void
	*/
	virtual void UCAPI Disconnect(void);

	/**
	* @brief ��ȡ�����ӵ�Զ��IP��ַ��������
	* @return �����ӵ�Զ��IP��ַ��������
	*/
	virtual const UINT32 UCAPI GetRemoteIP(void)	{ return m_dwRemoteIP;	}

	/**
	* @brief ��ȡ�����ӵ�Զ��IP��ַ���ַ�������
	*/
	virtual const char* UCAPI GetRemoteIPStr(void)	{ return inet_ntoa( (in_addr&)m_dwRemoteIP );	}

	/**
	* @brief ��ȡ�����ӵ�Զ�̶˿ں�
	* @return �����ӵ�Զ�̶˿ں�
	*/
	virtual UINT16  UCAPI GetRemotePort(void)		{ return m_wRemotePort; }

	/**
	* @brief ��ȡ�����ӵı���IP��ַ��������
	* @return �����ӵı���IP��ַ��������
	*/
	virtual const UINT32 UCAPI GetLocalIP(void)		{ return m_dwLocalIP;	}

	/**
	* @brief ��ȡ�����ӵı���IP��ַ���ַ�����
	* @return �����ӵı���IP��ַ���ַ�����
	*/
	virtual const char* UCAPI GetLocalIPStr(void)	{ return inet_ntoa( (in_addr&)m_dwLocalIP );	}

	/**
	* @brief ��ȡ�����ӵı��ض˿ں�
	* @return �����ӵı��ض˿ں�
	*/
	virtual UINT16 UCAPI GetLocalPort(void)			{ return m_wLocalPort;	}

	/**
	* @brief ����δʹ�õķ��ͻ���
	*/
	virtual UINT32 UCAPI GetSendBufFree(void);

	/**
	* @brief ���ô�����,��������ӵ���Ϣ
	*/
	void Reset();

	/**
	* @brief ���ô����ӵ�ID��
	*/
	inline void SetID(UINT32 dwID) { m_dwID = dwID; }

	/**
	* @brief ��ȡ�����ӵ�ID��
	*/
	UINT32 GetID() { return m_dwID; }

	/**
	* @brief ���ô������Ƿ�Ϊ��������,�ֻ򱻶�����
	* @param bAccept : falseΪ��������,trueΪ��������
	* @return void
	*/
	inline void SetAccept(bool bAccept)	{ m_bAccept = bAccept;	}

	/**
	* @brief �鿴�������Ƿ�Ϊ��������
	* @return trueΪ��������,falseΪ��������
	*/
	bool IsAccept()					{ return m_bAccept;		}

	inline void SetParentID(UINT32 dwParentID)	{ m_dwParentID = dwParentID;	}
	UINT32 GetParentID()				{ return m_dwParentID;			}

	/**
	* @brief ���ô����ӵ�Զ��IP��ַ
	* @param dwIP : �����͵�Զ��IP��ַ
	* @return void
	*/
	void SetRemoteIP(UINT32 dwIP);

	/**
	* @brief ���ô����ӵ�Զ�̶˿ں�
	* @param dwIP : Զ�̶˿ں�
	* @return void
	*/
	inline void SetRemotePort(UINT16 wPort)	{ m_wRemotePort = wPort;	}

	/**
	* @brief ���ô����ӵı���IP��ַ
	* @param dwIP : ����IP��ַ
	* @return void
	*/
	void SetLocalIP(UINT32 dwIP);

	/**
	* @brief ���ô����ӵı��ض˿ں�
	* @param wPort : ���ض˿ں�
	* @return void
	*/
	inline void SetLocalPort(UINT16 wPort)		{ m_wLocalPort = wPort;		}

	/**
	* @brief ���ô����ӵ���������
	* @param pConnData : ��������
	* @return void
	*/
	inline void SetConnData(CConnData* pConnData)		{ m_pConnData = pConnData; }

	/**
	* @brief ���ô����ӵĻỰ
	* @param poSession : ���ӻỰ
	*/
	inline void SetSession(ISDSession* poSession) { m_poSession = poSession; }

	/**
	* @brief �����������ӳɹ�ʱ,���ô˺���
	*/
	void OnConnect();

	/**
	* @brief �������ӷ�������ʱ,���ô˺���
	* @param pBuf : ָ���͵����ݵ�ָ��
	* @param dwLen : �������ݵĳ���
	*/
	void OnSend(const char * pBuf, UINT32 dwLen);

	/**
	* @brief �����������ӳɹ�ʱ,���ô���
	*/
	void OnAssociate();

	/**
	* @brief �������ӹر�ʱ,���ô˺���
	*/
	void OnClose();

	/**
	* @brief �������ӽ��յ���Ϣʱ,���ô˺���
	*/
	inline void OnRecv(const char* pData, INT32 nLen)
	{
		if(m_nConnStat != CONN_ASSOCIATE)
		{
			return;
		}

		SDASSERT(m_poSession != NULL);
		m_poSession->OnRecv(pData, nLen);
	}

	/**
	* @brief �������ӷ�������ʱ,���ô˺���
	*/
	inline void OnError(INT32 nUCODEError, INT32 nSysError)
	{
		if(m_nConnStat != CONN_ASSOCIATE)
		{
			return;
		}

		SDASSERT(m_poSession != NULL);
		m_poSession->OnError(nUCODEError, nSysError);
	}

	/**
	* @brief �������ӷ�������ʱ,���ô˺���
	* @param pBuf : ָ���͵����ݵ�ָ��
	* @param dwLen : �������ݵĳ���
	*/
	void UpdateSend();

	inline	UINT8	GetRunIndex(){return m_byRunIndex;}
protected:
	UINT32		m_dwID;
	UINT32		m_dwParentID;
	bool		m_bAccept;
	UINT8		m_byRunIndex;
	EConnStat	m_nConnStat;
	UINT32		m_dwLocalIP;
	UINT32		m_dwRemoteIP;
	UINT16		m_wLocalPort;
	UINT16		m_wRemotePort;
	//char		m_szLocalIP[16];
	//char		m_szRemoteIP[16]; //decrease the memory footprint
	CConnData *	m_pConnData;
	ISDSession* m_poSession;
};

#endif

