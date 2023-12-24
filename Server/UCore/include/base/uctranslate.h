#ifndef UC_TRANSLATE_H
#define UC_TRANSLATE_H

//#include "ucdebug.h"
#include "uctype.h"
#include <string>
using namespace std;

#if UC_WITH_LIBICONV
#include "iconv.h"
#include "localcharset.h"
namespace UCODE
{
    /**
    * @brief һ���ַ�������һ���ַ�����ת��
    */
	class CSDTranslate
	{
	public:

		/**
		* @brief ���캯������ʼ��ת�����
		*/
		CSDTranslate();
		
		/**
		* @�����������ر�ת�����
		*/
		~CSDTranslate();


	public:

        /**
        * @brief ��Դ�ַ���ת����Ŀ���ַ���
        * @param cpSrc : Դ�ַ���
        * @param nSrcLen : Դ�ַ�������
        * @param cpDesc  : Ŀ���ַ���
        * @param nDescLen: Ŀ���ַ�������
        * @return -1:ת��ʧ�� ����ɹ�ת��
        */
		size_t Translate(CHAR *cpSrc, 
						 size_t nSrcLen, 
						 CHAR * cpDesc,
						 size_t nDescLen );

        /**
        * @brief ��ʼ��Դ�ַ�����Ŀ���ַ���
        * @param cpFromCharset : Դ�ַ���
        * @param cpToCharset   : Ŀ���ַ���
        * @return TRUE:��ʼ���ɹ� FALSE:��ʼ��ʧ��
        */
		bool   Init(const char *cpFromCharset,const char *cpToCharset);
	private:
		iconv_t    m_hHandle;
		string	   m_strFromCharset;
		string	   m_strToCharset;
	};

    /**
    * @brief �ַ���ת��
    * @param desc : Ŀ���ַ���
    * @param src  : Դ�ַ���
    * @param input: ���뻺����
    * @param iLen :���뻺�����Ĵ�С
    * @param output : ���������
    * @param oLen   : ����������Ĵ�С
    * @return 0:�ɹ� -1:ʧ��
    */
	INT32		SDIconvCovert(CHAR *desc, CHAR *src, CHAR *input, size_t ilen, CHAR *output, size_t& olen);

    /**
    * @brief ��ȡ���ز���ϵͳ���ַ�������淶
    * @return ���ز���ϵͳ���ַ�������
    */
	const CHAR *  SDGetLocaleCharset (VOID);
}



#endif

#endif

