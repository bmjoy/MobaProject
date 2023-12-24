#ifndef UCODELISTENER_H
#define UCODELISTENER_H

#include "ucnet.h"
#include "cplistener.h"

using namespace UCODE;

/**
* @brief ���������,����Զ�̿ͻ��˶Դ�����
*/
class CUCODEListener : public ISDListener
{
public:
	CUCODEListener();
	virtual ~CUCODEListener();

	//Interface ISDListener
	/**
	* @brief �������ݰ�������
	* @param poPacketParser : ���õ����ݰ�������
	* @return void
	*/
	virtual void UCAPI SetPacketParser(ISDPacketParser* poPacketParser);

	/**
	* @brief �������ӻỰ�Ĺ�����
	* @param poSessionFactory : ���ӻỰ�Ĺ�����
	* @return void
	*/
	virtual void UCAPI SetSessionFactory(ISDSessionFactory* poSessionFactory);

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
	* @brief ��ʼ����
	* @param pszIP : ����IP��ַ
	* @param wPort : ���ض˿ں�
	* @param bReUseAddr : �Ƿ�˿ڸ���
	* @return �����ɹ�����true,����ʧ�ܷ���false
	*/
	virtual bool UCAPI Start(const char* pszIP, UINT16 wPort, bool bReUseAddr);

	/**
	* @brief ֹͣ����
	* @return void
	*/
	virtual bool UCAPI Stop(void);

	/**
	* @brief �ͷŴ˼�����
	* @return void
	*/
	virtual void UCAPI Release(void);

protected:
	ISDPacketParser*	m_poPacketParser;
	ISDSessionFactory*	m_poSessionFactory;
	UINT32				m_dwRecvBufSize;
	UINT32				m_dwSendBufSize;
	CCpListener*		m_poCpListener;
	bool				m_bStart;
    BOOL                m_bNodelay;
};

#endif

