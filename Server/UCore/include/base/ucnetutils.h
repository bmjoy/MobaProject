#ifndef UCNETUTILS_H
#define UCNETUTILS_H

#if (defined(WIN32) || defined(WIN64))
#include <WinSock2.h>
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <sys/resource.h>
#endif

#include <string>
#include "uctype.h"
#include "ucstring.h"
namespace UCODE
{

    /**
    * @defgroup groupnetutil �������
    * @ingroup  UCODE
    * @{
    */


    typedef  struct hostent SDHostent;

    /**
    * @brief
    * IPv4 �����͵�ip��ַת��Ϊ��ָ��ĵ�ַ��ʾ 0.0.0.0
    * ��IPv6��ַת��Ϊ�ַ�����ʾ��ʽ
    * @param af : address family, AF_INET/AF_INET6
    * @param pSrc : ��Ҫ��ת���������ַ,
    * @param pDst : ת����������ַ��ŵĿռ�
    * @param size : �����ַ��ſռ����󳤶�
    * @return ת����������ַ��ŵĿռ�(`pDst'), ����ʧ�ܷ���NULL
    */
    const TCHAR*  SDNetInetNtop(INT32 af, const VOID *pSrc, TCHAR *pDst, size_t size);

    /**
    * @brief
    *  ���ַ�����ʾ��IP��ַת��Ϊ���ͻ�IPv6�ṹ��ʾ
    * @param af : address family, AF_INET/AF_INET6
    * @param pSrc : ��Ҫ��ת���������ַ
    * @param pDst : ת����������ַ��ŵĿռ�
    * @  ��ȷ����TRUE ,���src����ʾ�ĵ�ַ��Ч,�����ַ�岻ƥ��,�򷵻�FALSE
    */
    BOOL  SDNetInetPton(INT32 af, const CHAR *pSrc, VOID *pDst);

    /**
    * @brief
    * ��UINT32�������ݴ�����˳��ת��Ϊ����˳��
    * @param netlong : UINT32��������˳������
    * @return UINT32��������˳������
    */
    inline UINT32  SDNtohl(UINT32 netlong)
    {
        return ntohl(netlong);
    }

    /**
    * @brief
    * ��UINT16�������ݴ�����˳��ת��Ϊ����˳��
    * @param netshort : UINT16��������˳������
    * @return UINT16��������˳������
    */
    inline UINT16  SDNtohs(UINT16 netshort)
    {
        return ntohs(netshort);
    }

    /**
    * @brief
    * ��UINT32�������ݴ�����˳��ת��Ϊ����˳��
    * @param hostlong : UINT32��������˳������
    * @return UINT32��������˳������
    */
    inline UINT32  SDHtonl(UINT32 hostlong)
    {
        return htonl(hostlong);
    }

    /**
    * @brief
    * ��UINT64�������ݴ�����˳��ת��Ϊ����˳��
    * @param hostlong : UINT64��������˳������
    * @return UINT64��������˳������
    */
    inline UINT64  SDHtonll(UINT64 number)
    {
        return ( htonl( UINT32((number >> 32) & 0xFFFFFFFF)) |
                 (UINT64(htonl(UINT32(number & 0xFFFFFFFF))) << 32));
    }

    /**
    * @brief
    * ��UINT64�������ݴ�����˳��ת��Ϊ����˳��
    * @param hostlong : UINT64��������˳������
    * @return UINT64��������˳������
    */
    inline UINT64  SDNtohll(UINT64 number)
    {
        return ( ntohl( UINT32((number >> 32) & 0xFFFFFFFF) ) |
                 (UINT64 (ntohl(UINT32(number & 0xFFFFFFFF)))  << 32));
    }


    /**
    * @brief
    * ��UINT16�������ݴ�����˳��ת��Ϊ����˳��
    * @param hostlong : UINT16��������˳������
    * @return UINT16��������˳������
    */
    inline UINT16   SDHtons(UINT16 hostlong)
    {
        return htons(hostlong);
    }

    /**
    * @brief
    * ת��һ���ַ����͵�IPv4�ĵ�ַΪһ�������͵�IP��ַ
    * @param pszAddr : �ַ����͵�IPv4�ĵ�ַ
    * @return �����͵�IP��ַ
    */
    inline ULONG  SDInetAddr(const TCHAR* pszAddr)
    {
        return inet_addr(_SDTT2A(pszAddr));
    }

    /**
    * @brief
    * ת��һ�������͵�IPv4�ĵ�ַΪһ���ַ����͵�IP��ַ
    * @param lIp : �����͵�IPv4�ĵ�ַ
    * @return �ַ����͵�IP��ַ�������������NULL
    */
    inline tstring   SDInetNtoa(LONG lIp)
    {
        struct in_addr addr;
#if (defined(WIN32) || defined(WIN64))
        addr.S_un.S_addr = lIp;
#else
        addr.s_addr = lIp;
#endif
        std::string strIp = inet_ntoa(addr);
        tstring wstrIp =  _SDTA2T(strIp.c_str());
        return wstrIp;
    }

    /**
    * @brief
    * ��ȡ��������Ӧ��IP��ַ
    * @param pszName : ������
    * @return ������IP��ַ
    */
    LONG  SDGetIpFromName(const CHAR * pszName);

	/**
	* @brief
	* ��ȡ������	
	* @return ������������
	*/
    tstring  SDGetHostName();

	/**
	* @brief
	* ��ȡ��������Ӧ��������Ϣ	
    * @param pszName : ������
	* @return ������������Ϣ
	*/
    SDHostent*  SDGetHostByName(const TCHAR * pszName); // ��������

    /**
    * @brief
    * ��ȡ��ǰ�����ı���IP��ַ
    * @param dwIp :  ���ڻ�ȡ���ص�IP��ַ������
    * @param dwCount : ���鳤��
    * @return ����IP��ַ������
    */
    INT32  SDGetLocalIp(ULONG dwIp[], UINT32 dwCount);

	//TODO get mac address
    /** @} */
    

	/**
    * @brief �����ļ����������
	* @param dwSetLimit : �����Ƶ��ļ������
    * @return  0: success -1: getrlimit failed -2: setrlimit failed
    */
	INT32 SetFileHandleLimit(const UINT32 dwSetLimit);


}//

#endif /// 

