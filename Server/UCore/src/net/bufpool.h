#ifndef BUFPOOL_H
#define BUFPOOL_H

#include <list>
#include <map>
#include <set>

typedef std::list<char*> CListBuf;
typedef std::set<char*> CSetBuf;

/**
* @brief �����ڴ�أ����ڲ����̰߳�ȫ��
*
*/
class CBufPool
{
public:
	CBufPool(void);
	virtual ~CBufPool(void);

	/**
	* @brief ��ʼ�������ڴ��
	* @param dwSize : ÿƬ�ڴ�Ĵ�С
	* @return void
	*/
	void Init(UINT32 dwSize);

	/**
	* @brief �ͷŴ˶����ڴ�ص��ڴ棬�ص�δ��ʼ����״̬
	* @return void
	*
	*/
	void Uninit();

	/**
	* @brief ��ȡ�ڴ�ص�ÿƬ�ڴ�Ĵ�С
	* @return ����ÿƬ�ڴ�Ĵ�С
	* @return void
	*/
	UINT32 GetSize();

	/**
	* @brief ��ȡһ���ڴ�
	* @return ����һ���ڴ�
	* @return void
	*/
	char* Create();

	/**
	* @brief ����һ���ڴ�
	* @param pBuf : ���յ��ڴ�
	* @return void
	*/
	void Release(char* pBuf);

protected:
	UINT32		m_dwSize;
	CListBuf	m_oListBuf;
	CSetBuf		m_oSetBuf;
#ifdef _DEBUG
	CSetBuf		m_oSetFree;
#endif
};

/**
* @brief ���ֳ��ȵĶ����ڴ��
*/
typedef std::map<UINT32, CBufPool*> CMapBufPool;

#endif

