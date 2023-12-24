#ifndef UCSTRING_H
#define UCSTRING_H

#include "uctype.h"
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <vector>
//#include <ucdebug.h>
#include <stdarg.h>

#if (defined(WIN32) || defined(WIN64))

#ifdef UNICODE
typedef std::wstring tstring;
#else
typedef std::string tstring;
#endif

#else
#ifdef UNICODE
typedef std::basic_string<TCHAR> tstring;
#else
typedef std::string tstring;
#endif
#endif


#if (defined(WIN32) || defined(WIN64))
#include <tchar.h>
#define SDSYMBOL_RT         "\r\n"
#define SDFMT_I64           "%I64d"
#define WCHAR_SDFMT_I64      L"%I64d"
#define SDFMT_U64           "%I64u"
#define WCHAR_SDFMT_U64     L"%I64u"
#define SDFMT_X64           "%I64x"
#else
#include <wchar.h>
#include <wctype.h>
#define SDSYMBOL_RT         "\n"
#define SDFMT_I64           "%lld"
#define WCHAR_SDFMT_I64      L"%lld"
#define SDFMT_U64           "%llu"
#define WCHAR_SDFMT_U64     L"%llu"
#define SDFMT_64X           "%llx"
#endif

namespace UCODE
{
    /**
    * @defgroup groupstring �ַ�������
    * @brief �ַ����������߽���
    * @ingroup  UCODE
    * @{
    */

    /** @see isalnum */
#define SDIsAlNum(c) (isalnum(((UCHAR)(c))))
    /** @see isalpha */
#define SDIsAlpha(c) (isalpha(((UCHAR)(c))))
    /** @see iscntrl */
#define SDIsCntrl(c) (iscntrl(((UCHAR)(c))))
    /** @see isdigit */
#define SDIsDigit(c) (isdigit(((UCHAR)(c))))
    /** @see isgraph */
#define SDISGraph(c) (isgraph(((UCHAR)(c))))
    /** @see islower*/
#define SDIsLower(c) (islower(((UCHAR)(c))))
    /** @see isascii */
#ifdef isascii
#define SDIsAscii(c) (isascii(((UCHAR)(c))))
#else
#define SDIsAscii(c) (((c) & ~0x7f)==0)
#endif
    /** @see isprint */
#define SDIsPrint(c) (isprint(((UCHAR)(c))))
    /** @see ispunct */
#define SDIsPunct(c) (ispunct(((UCHAR)(c))))
    /** @see isspace */
#define SDIsSpace(c) (isspace(((UCHAR)(c))))
    /** @see isupper */
#define SDIsUpper(c) (isupper(((UCHAR)(c))))
    /** @see isxdigit */
#define SDIsXdigit(c) (isxdigit(((UCHAR)(c))))
    /** @see tolower */
#define SDToLower(c) (tolower(((UCHAR)(c))))
    /** @see toupper */
#define SDToUpper(c) (toupper(((UCHAR)(c))))

    ///////////////////////////////////////////////////////////////////////////
#define SDSprintf sprintf
#define SDSwprintf swprintf

#if (defined(WIN32) || defined(WIN64))
#define SDSnprintf _snprintf
#else
#define SDSnprintf snprintf
#endif

///////////////////////////////////////////////////////////////////////
#define SDAtoi atoi

#if (defined(WIN32) || defined(WIN64))
#define SDAtoi64 _atoi64
#else
#define SDAtoi64 atoll
#endif

#ifdef UNICODE
#define TCHAR                 WCHAR	
#define _SDT(x)               L##x
#define _SDTStrlen            SDWcslen
#define _SDTStrnlen           SDWcsnlen
#define _SDTStrcat            SDWcscat
#define _SDTStrcpy            SDWcscpy
#define _SDTStrncpy           SDWcsncpy
#define _SDTStrcmp            SDWcscmp
#define _SDTStrncmp           SDWcsncmp
#define _SDTStrchr            SDWcschr
#define _SDTStrrchr           SDWcsrchr
#define _SDTStrcasecmp        SDWcscasecmp
#define _SDTA2T(x)            SDA2W(x).c_str()
#define _SDTT2A(x)            SDW2A(x).c_str()
#define _SDTT2Local(x)        SDW2Local(x).c_str()
#define _SDTLocal2T(x)        SDLocal2W(x).c_str()
#define _SDTUTF82W(x)         SDUTF82W(x).c_str()
#define _SDTT2UTF8(x)         SDW2UTF8(x).c_str()
#define _SDTUTF82T(x)         SDUTF82W(x).c_str()
#define _SDTSource2T(x,y)     SDSource2W(x,y).c_str()
#define _SDTTtoi		      SDWtoi
#define _SDTsnprintf		  SDsnwprintf
#define _SDTvsprintf          vswprintf
#define _SDTvsnprintf          vswprintf
#define _SDTsprintf		      swprintf
#define _SDTStrchr            SDWcschr
#define _SDTStrrchr           SDWcsrchr
#define _SDTStrtok            SDWcstok
#define _SDTStrlwr            SDWcslwr
#define _SDTStrupr            SDWcsupr
#define _SDTStrcat             SDWcscat
#define _SDTStrncat             SDWcsncat
#define _SDTStrncasecmp   SDWcsncasecmp
#define _SDTBufferToHex       SDBufferToHexW
#define _SDTIntToHex          SDIntToHexW
#define _SDTStrTrimLeft       SDStrTrimLeftW
#define _SDTStrTrimRight      SDStrTrimRightW
#define _SDTStrTrim           SDStrTrimW
#define _SDTStrtod            SDWCStrtod
#define _SDTSplitStrings      SDSplitStringsW
#define _SDTAtou64            SDWtou64
#define _SDTAtou              SDWtou
#define _SDTItoa              SDItoa
#define _SDTItoa64            SDItoa64
#define _SDTUtoa              SDUtoa
#define _SDTUtoa64            SDUtoa64
#else
#define _SDT(x)               x
#define _SDTStrlen            SDStrlen
#define _SDTStrnlen           SDStrnlen
#define _SDTStrcat            SDStrcat
#define _SDTStrcpy            SDStrcpy
#define _SDTStrncpy           SDStrncpy
#define _SDTStrcmp            SDStrcmp
#define _SDTStrncmp           SDStrncmp
#define _SDTStrchr            SDStrchr
#define _SDTStrrchr           SDStrrchr
#define _SDTStrcasecmp        SDStrcasecmp
#define _SDTA2T(x)            (x)
#define _SDTT2A(x)            (x)
#define _SDTT2Local(x)        (x)
#define _SDTLocal2T(x)        (x)
#define _SDTUTF82W(x)         (x)
#define _SDTT2UTF8(x)         SDLocal2UTF8(x).c_str()
#define _SDTUTF82T(x)         SDUTF82Local(x).c_str()
#define _SDTSource2T(x,y)     SDSource2Local(x,y).c_str()
#define _SDTTtoi		      SDAtoi
#ifdef __linux__
#define _SDTsnprintf		  snprintf
#elif defined(__APPLE__)
#define _SDTsnprintf		      snprintf
#else
#define _SDTsnprintf		  _snprintf
#endif
#define _SDTvsprintf          vsprintf
#define _SDTvsnprintf          vsnprintf
#define _SDTsprintf		      sprintf
#define _SDTStrchr            SDStrchr
#define _SDTStrrchr           SDStrrchr
#define _SDTStrtok            SDStrtok
#define _SDTStrlwr            SDStrlwr
#define _SDTStrupr            SDStrupr
#define _SDTStrcat             SDStrcat
#define _SDTStrncat             SDStrncat
#define _SDTStrncasecmp   SDStrncasecmp
#define _SDTBufferToHex       SDBufferToHexA
#define _SDTIntToHex          SDIntToHexA
#define _SDTStrTrimLeft       SDStrTrimLeftA
#define _SDTStrTrimRight      SDStrTrimRightA
#define _SDTStrTrim           SDStrTrimA
#define _SDTStrtod            SDStrtod
#define _SDTSplitStrings      SDSplitStringsA
#define _SDTAtou64            SDAtou64
#define _SDTAtou              SDAtou
#define _SDTItoa              SDItow
#define _SDTItoa64            SDItow64
#define _SDTUtoa              SDUtow
#define _SDTUtoa64            SDUtow64
#endif

    /**
    * @brief
    * ��ȡ�ַ����ĳ���
    * @param string : ��0Ϊ���������ַ���
    * @return : �ַ����ĳ���
    */
    inline UINT32  SDStrlen( const CHAR* string )
    {
        return (UINT32)strlen(string);
    }

    /**
    * @brief
    * ��ȡUnicode�ַ����ĳ���
    * @param string : ��0Ϊ���������ַ���
    * @return : Unicode�ַ����ĳ���
    */
    inline UINT32  SDWcslen( const WCHAR* string )
    {
        return (UINT32)wcslen(string);
    }

    /**
    * @brief
    * ��ȡ�ַ����ĳ���
    * @param pszStr : �ַ���
    * @param sizeInBytes :����ⳤ��
    * @return ��ȡ�ַ����ĳ��ȣ�����ַ����ĳ��ȳ���sizeInBytes������sizeInBytes
    */
    inline UINT32  SDStrnlen(const CHAR* pszStr, UINT32 sizeInBytes )
    {
        return (UINT32)strnlen(pszStr, sizeInBytes);
    }

    /**
    * @brief
    * ��ȡUnicode�ַ����ĳ���
    * @param pszStr : Unicode�ַ���
    * @param sizeInBytes :����ⳤ��
    * @return ��ȡUnicode�ַ����ĳ��ȣ����Unicode�ַ����ĳ��ȳ���sizeInBytes������sizeInBytes
    */
    inline UINT32  SDWcsnlen(const WCHAR* pszStr, size_t sizeInBytes)
    {
        return (UINT32)wcsnlen(pszStr, sizeInBytes);
    }

    /**
    * @brief
    * ��Ŀ���ַ��������һ���ַ���
    * @param strDestination : ��0Ϊ��������Ŀ���ַ���
    * @param strSource : ��0Ϊ��������Դ�ַ���
    * @return ����ַ�����ʹ�õ���Ŀ���ַ����ռ䣬��Ԥ���㹻�Ŀռ�
    */
    inline CHAR*  SDStrcat(CHAR* strDestination, const CHAR* strSource )
    {
        return strcat(strDestination, strSource);
    }

    /**
    * @brief
    * ��Ŀ���ַ��������һ���ַ���
    * @param strDestination : ��0Ϊ��������Ŀ���ַ���
    * @param dstLen : Ŀ�괮�ڴ���ܳ���,����ϲ���ĳ��ȴ��ڴ˳���,������кϲ�,���ؿմ�,���޸�Ŀ�괮
    * @param strSource : ��0Ϊ��������Դ�ַ���
    * @return ����ַ�����ʹ�õ���Ŀ���ַ����ռ�,����ϲ���ĳ��ȴ��ڴ˳���,������кϲ�,����NULL,���޸�Ŀ�괮
    */
    inline CHAR *  SDStrSafeCat(CHAR* strDestination, UINT32 dstLen, const CHAR* strSource)
    {
        if (dstLen < strlen(strDestination) + strlen(strSource) + 1)
        {
            return NULL;
        }
        return strcat(strDestination,strSource);
    }

    /**
    * @brief
    * ��Ŀ��Unicode�ַ��������һ��Unicode�ַ���
    * @param strDestination : ��0Ϊ��������Ŀ��Unicode�ַ���
    * @param strSource : ��0Ϊ��������ԴUnicode�ַ���
    * @return ���Unicode�ַ�����ʹ�õ���Ŀ��Unicode�ַ����ռ䣬��Ԥ���㹻�Ŀռ�
    */
    inline WCHAR*   SDWcscat(WCHAR*strDestination, const WCHAR *strSource )
    {
        return wcscat(strDestination, strSource);
    }

    /**
    * @brief
    * ��Ŀ���ַ��������һ���ַ���
    * @param strDestination : ��0Ϊ��������Ŀ���ַ���
    * @param strSource : Դ�ַ���
    * @param len : Դ�ַ����������ӳ���
    * @return ����ַ�����ʹ�õ���Ŀ���ַ����ռ䣬��Ԥ���㹻�Ŀռ�
    */
    inline CHAR*  SDStrncat(CHAR *strDestination, const CHAR *strSource, UINT32 len)
    {
        return strncat(strDestination, strSource, len);
    }

    /**
    * @brief
    * ��Ŀ��Unicode�ַ��������һ��Unicode�ַ���
    * @param strDestination : ��0Ϊ��������Ŀ��Unicode�ַ���
    * @param strSource : ԴUnicode�ַ���
    * @param len : ԴUnicode�ַ����������ӳ���
    * @return ���Unicode�ַ�����ʹ�õ���Ŀ��Unicode�ַ����ռ䣬��Ԥ���㹻�Ŀռ�
    */
    inline WCHAR*  SDWcsncat(WCHAR *strDestination, const WCHAR *strSource, UINT32 len)
    {
        return wcsncat(strDestination, strSource, len);
    }

    /**
    * @brief
    * �����ַ���
    * @param strDestination : ��0Ϊ��������Ŀ�껺�������뱣֤���㹻�Ŀռ�
    * @param strSource : ��0Ϊ��������Դ�ַ���
    * @return Ŀ���ַ���
    */
    inline CHAR*  SDStrcpy( CHAR *strDestination, const CHAR *strSource )
    {
        return strcpy(strDestination, strSource);
    }

    /**
    * @brief
    * ��ȫ�����ַ���
    * @param strDestination : ��Ҫ�����ַ�����Ŀ�껺����
    * @param numberOfElements : Ŀ���ַ�����󳤶�
    * @param strSource : ��0��β��Դ�ַ���
    * @return ����Ŀ�괮,���Ŀ�껺�����ĳ���С��Դ��,����NULL
    */
    inline CHAR* SDStrSafeCpy( char *strDestination, size_t numberOfElements, const CHAR *strSource )
    {
        if (numberOfElements  < strlen(strSource) +1)
        {
            return NULL;
        }

        return strncpy(strDestination,strSource,numberOfElements);
    }

    /**
    * @brief
    * ��ȫ�����ַ���
    * @param strDestination : ��Ҫ�����ַ�����Ŀ�껺����
    * @param numberOfElements : Ŀ���ַ�����󳤶�
    * @param strSource : ��0��β��Դ�ַ���
    * @return ����Ŀ�괮,���Ŀ�껺�����ĳ���С��Դ��,����NULL
    */
    template <class T>
    inline void SDStrSafeCpy(T& Destination, const char* Source) 
    {
        // Use cast to ensure that we only allow character arrays
        (static_cast<char[sizeof(Destination)]>(Destination));

        // Copy up to the size of the buffer
        SDStrSafeCpy(Destination, Source, sizeof(Destination));
    }


    /**
    * @brief
    * ����Unicode�ַ���
    * @param strDestination : ��0��β��Ŀ�껺�������뱣֤���㹻�Ŀռ�
    * @param strSource : ��0��β��Դ�ַ���
    * @return Ŀ���ַ���
    */
    inline WCHAR*  SDWcscpy( WCHAR *strDestination, const WCHAR *strSource )
    {
        return wcscpy(strDestination, strSource);
    }

    /**
    * @brief
    * ��ȫ����Unicode�ַ���
    * @param strDestination : ��Ҫ����Unicode�ַ�����Ŀ�껺����
    * @param numberOfElements : Ŀ����Unicode������󳤶�
    * @param strSource : ��0��β��ԴUnicode�ַ���
    * @return ����Ŀ�괮,���Ŀ�껺�����ĳ���С��Դ��,����NULL
    */
    WCHAR * SDWcsSafeCpy( WCHAR *strDestination, size_t numberOfElements, const WCHAR *strSource );

    /**
    * @brief
    * �����ַ���
    * @param strDestination : ��0��β��Ŀ���ַ���
    * @param strSource : ��0��β��Դ�ַ���
    * @param len : ��󿽱�����
    * @return ����Ŀ���ַ���
    */
    inline CHAR*  SDStrncpy( CHAR *strDestination, const CHAR *strSource, UINT32 len )
    {
        return strncpy(strDestination, strSource, len);
    }

    /**
    * @brief
    * ����Unicode�ַ���
    * @param strDestination : ��0��β��Ŀ��Unicode�ַ���
    * @param strSource : ��0��β��ԴUnicode�ַ���
    * @param len : ��󿽱�����
    * @return ����Ŀ��Unicode�ַ���
    */
    inline WCHAR*  SDWcsncpy( WCHAR *strDestination, const WCHAR *strSource, UINT32 len )
    {
        return wcsncpy(strDestination, strSource, len);
    }

    /**
    * @brief
    * �Ƚ��ַ���
    * @param string1 : ��0�������ַ���1
    * @param string2 : ��0�������ַ���2
    * @return �ȽϽ��
    * < 0 �ַ���1С���ַ���2
    * 0 �ַ���1�����ַ���2
    * > 0 �ַ���1�����ַ���2
    */
    inline INT32  SDStrcmp( const CHAR *string1, const CHAR *string2 )
    {
        return strcmp(string1, string2);
    }

    /**
    * @brief
    * �Ƚ�Unicode�ַ���
    * @param string1 : ��0������Unicode�ַ���1
    * @param string2 : ��0������Unicode�ַ���2
    * @return �ȽϽ��
    * < 0 �ַ���1С���ַ���2
    * 0 �ַ���1�����ַ���2
    * > 0 �ַ���1�����ַ���2
    */
    inline INT32  SDWcscmp( const WCHAR *string1, const WCHAR *string2 )
    {
        return wcscmp(string1, string2);
    }

    /**
    * @brief
    * �Ƚ��ַ���
    * @param string1 : ��0�������ַ���1
    * @param string2 : ��0�������ַ���2
    * @param count : ���Ƚϳ���
    * @return �ȽϽ��
    * < 0 �ַ���1С���ַ���2
    * 0 �ַ���1�����ַ���2
    * > 0 �ַ���1�����ַ���2
    */
    inline INT32  SDStrncmp( const CHAR *string1, const CHAR *string2, UINT32 count )
    {
        return strncmp( string1, string2, count );
    }

    /**
    * @brief
    * �Ƚ�Unicode�ַ���
    * @param string1 : ��0������Unicode�ַ���1
    * @param string2 : ��0������Unicode�ַ���2
    * @param count : ���Ƚϳ���
    * @return �ȽϽ��
    * < 0 �ַ���1С���ַ���2
    * 0 �ַ���1�����ַ���2
    * > 0 �ַ���1�����ַ���2
    */
    inline INT32  SDWcsncmp( const WCHAR *string1, const WCHAR *string2, size_t count )
    {
        return wcsncmp( string1, string2, count );
    }

    /**
    * @brief
    * ��һ���ַ����в���ĳ���ַ���λ��
    * @param string : ��0�������ַ���
    * @param c : ��Ҫ�����ҵ��ַ��ַ�
    * @return ָ����ҵĸ��ַ��ĵ�һ�γ��ֵ�λ�ã�����û���ҵ�����NULL
    */
    inline CHAR*  SDStrchr( const CHAR *string, INT32 c )
    {
        return (CHAR*)strchr(string, c);
    }

    /**
    * @brief
    * ��һ��Unicode�ַ����в���ĳ���ַ���λ��
    * @param string : ��0������Unicode�ַ���
    * @param c : ��Ҫ�����ҵ��ַ��ַ�
    * @return ָ����ҵĸ��ַ��ĵ�һ�γ��ֵ�λ�ã�����û���ҵ�����NULL
    */
    inline WCHAR*  SDWcschr( const WCHAR *string, WCHAR c )
    {
        return (WCHAR*)wcschr(string, c);
    }

    /**
    * @brief
    * ��һ���ַ������������ĳ���ַ���λ��
    * @param string : ��0�������ַ���
    * @param c : ��Ҫ�����ҵ��ַ��ַ�
    * @return ָ����ҵĸ��ַ������һ�γ��ֵ�λ�ã�����û���ҵ�����NULL
    */
    inline CHAR*  SDStrrchr( const CHAR *string, INT32 c )
    {
        return (CHAR*)strrchr(string ,c);
    }

    /**
    * @brief
    * ��һ��Unicode�ַ������������ĳ���ַ���λ��
    * @param string : ��0������Unicode�ַ���
    * @param c : ��Ҫ�����ҵ��ַ��ַ�
    * @return ָ����ҵĸ��ַ������һ�γ��ֵ�λ�ã�����û���ҵ�����NULL
    */
    wchar_t*  SDWcsrchr( const wchar_t *string, wchar_t c );

    /**
    * @brief
    * �����ַ���Сд���Ƚ��ַ���
    * @param s1 : ��0�������ַ���1
    * @param s2 : ��0�������ַ���2
    * @return �ȽϽ��
    * < 0 �ַ���1С���ַ���2
    * 0 �ַ���1�����ַ���2
    * > 0 �ַ���1�����ַ���2
    */
    inline INT32  SDStrcasecmp(const CHAR *s1, const CHAR *s2)
    {
#if (defined(WIN32) || defined(WIN64))
        return _stricmp(s1, s2);
#else
        return strcasecmp(s1, s2);
#endif
    }

    /**
    * @brief
    * �����ַ���Сд���Ƚ��ַ���
    * @param s1 : ��0�������ַ���1
    * @param s2 : ��0�������ַ���2
    * @param count : ���Ƚϳ���
    * @return �ȽϽ��
    * < 0 �ַ���1С���ַ���2
    * 0 �ַ���1�����ַ���2
    * > 0 �ַ���1�����ַ���2
    */
    inline INT32  SDStrncasecmp(const CHAR *s1, const CHAR *s2, UINT32 count)
    {
#if (defined(WIN32) || defined(WIN64))
        return _strnicmp(s1, s2, count);
#else
        return strncasecmp(s1, s2, count);
#endif
    }

    /**
    * @brief
    * �����ַ���Сд���Ƚ�Unicode�ַ���
    * @param s1 : ��0������Unicode�ַ���1
    * @param s2 : ��0������Unicode�ַ���2
    * @return �ȽϽ��
    * < 0 �ַ���1С���ַ���2
    * 0 �ַ���1�����ַ���2
    * > 0 �ַ���1�����ַ���2
    */
     INT32  SDWcscasecmp(const wchar_t *s1, const wchar_t *s2);

    /**
    * @brief
    * �����ַ���Сд���Ƚ�Unicode�ַ���
    * @param s1 : ��0������Unicode�ַ���1
    * @param s2 : ��0������Unicode�ַ���2
    * @param count : ���Ƚϳ���
    * @return �ȽϽ��
    * < 0 �ַ���1С���ַ���2
    * 0 �ַ���1�����ַ���2
    * > 0 �ַ���1�����ַ���2
    */
    INT32  SDWcsncasecmp(const wchar_t *s1, const wchar_t *s2, UINT32 count);


    /**
    * @brief
    * ��ĳ���ַ����з�Ϊ����ַ���
    * @param pszStr : ��һ�����뱻�зֵ��ַ�����֮������NULL
    * @param delim : �ָ��ַ������硰:������,������ ����
    * @return ���η��ر��и�����ַ��������û���µ����ַ���������NULL
    */
    inline CHAR*  SDStrtok(CHAR *pszStr, const CHAR *delim)
    {
        return strtok(pszStr, delim);
    }

    /**
    * @brief
    * ��ĳ��Unicode�ַ����з�Ϊ���Unicode�ַ���
    * @param pszStr : ��һ�����뱻�зֵ�Unicode�ַ�����֮������NULL
    * @param delim : �ָ�Unicode�ַ������硰:������,������ ����
    * @return ���η��ر��и����Unicode�ַ��������û���µ���Unicode�ַ���������NULL
    */
    inline wchar_t*  SDWcstok(wchar_t *pszStr, const wchar_t *delim);

    /**
    * @brief
    * ���ַ����е�����ANSI�ַ�ת��ΪСд
    * @param pszStr : ��0��β���ַ���
    * @return ��ת�����ַ�����ʹ��ԭ���ַ����Ŀռ䣬ԭ���ַ��������ƻ�
    */
    CHAR*  SDStrlwr(CHAR* pszStr);


    /**
    * @brief
    * ���ַ����е�����ANSI�ַ�ת��Ϊ��д
    * @param pszStr : ��0��β���ַ���
    * @return ��ת�����ַ�����ʹ��ԭ���ַ����Ŀռ䣬ԭ���ַ��������ƻ�
    */
    CHAR*  SDStrupr(CHAR* pszStr);

    /**
    * @brief
    * ��Unicode�ַ����е������ַ�ת��ΪСд
    * @param pszStr : ��0��β��Unicode�ַ���
    * @return ��ת����Unicode�ַ�����ʹ��ԭ��Unicode�ַ����Ŀռ䣬ԭ��Unicode�ַ��������ƻ�
    */
    WCHAR*  SDWcslwr(WCHAR* pszStr);

    /**
    * @brief
    * ��Unicode�ַ����е������ַ�ת��Ϊ��д
    * @param pszStr : ��0��β��Unicode�ַ���
    * @return ��ת����Unicode�ַ�����ʹ��ԭ��Unicode�ַ����Ŀռ䣬ԭ��Unicode�ַ��������ƻ�
    */
    WCHAR*  SDWcsupr(WCHAR* pszStr);

    /**
    * @brief
    * ���ַ���ת��ΪUnicode�ַ���
    * @param src : ��0��β���ַ���
    * @return ת�����MultiBytes�ַ���
    */
	std::wstring  SDA2W(const CHAR *src);


    /**
    * @brief
    * ��Unicode�ַ���ת��ΪANSI�ַ���
    * @param src : ��0��β��Unicode�ַ���
    * @return ת�����ANSI�ַ���
    */
	std::string  SDW2A(const WCHAR *src);
  
    /**
    * @brief
    * ��Unicode�ַ���ת��Ϊ���ز���ϵͳ���õ��ַ�������
    * @param src : ��0��β��Unicode�ַ���
    * @return ת������ַ���
    */
	std::string  SDW2Local(const WCHAR *src);

    /**
    * @brief
    * �����ز���ϵͳ���õ��ַ�������ת��ΪUnicode�ַ���
    * @param src : ��0��β���ַ���
    * @return ת������ַ���
    */
	std::wstring  SDLocal2W(const CHAR *src);

    /**
    * @brief
    * ��Unicode�ַ���ת��ΪUTF8���뼯
    * @param src : ��0��β��Unicode�ַ���
    * @return ת������ַ���
    */
	std::string  SDW2UTF8(const WCHAR *src);

    /**
    * @brief
    * ��UTF8���뼯ת��ΪUnicode�ַ���
    * @param src : ��0��β���ַ���
    * @return ת������ַ���
    */
    std::wstring  SDUTF82W(const CHAR *src);

    /**
    * @brief
    * ��UTF8���뼯ת��ΪASCII�ַ���
    * @param src : ��0��β���ַ���
    * @return ת������ַ���
    */
    std::string  SDUTF82A(const CHAR *src);

    /**
    * @brief
    * ��ASCII�ַ���ת��ΪUTF8���뼯
    * @param src : ��0��β���ַ���
    * @return ת������ַ���
    */
    std::string  SDA2UTF8(const CHAR *src);
  
    /**
    * @brief
    * �����ز���ϵͳ���õ��ַ�������ת��ΪUTF8���뼯
    * @param src : ��0��β���ַ���
    * @return ת������ַ���
    */
    std::string  SDLocal2UTF8(const CHAR *src);

    /**
    * @brief
    * ��UTF8���뼯ת��Ϊ���ز���ϵͳ���õ��ַ�������
    * @param src : ��0��β���ַ���
    * @return ת������ַ���
    */
    std::string  SDUTF82Local(const CHAR *src);

    /**
    * @brief
    * ��UTF8���뼯ת��Ϊ���ز���ϵͳ���õ��ַ�������
    * @param src : ��0��β���ַ���
    * @return ת������ַ���
    */
    std::wstring SDSource2W(const CHAR *szCodePage,const CHAR *src);

    /**
    * @brief
    * ��UTF8���뼯ת��Ϊ���ز���ϵͳ���õ��ַ�������
    * @param src : ��0��β���ַ���
    * @return ת������ַ���
    */
    std::string SDSource2Local(const CHAR *szCodePage,const CHAR *src);

    /**
    * @brief
    * ��UTF8���뼯ת��Ϊ���ز���ϵͳ���õ��ַ�������
    * @param src : ��0��β���ַ���
    * @return ת������ַ���
    */
    std::string SDUTF82Source(const CHAR *szCodePage,const CHAR *src);

	/**
	* @brief
	* ���ַ���ת��Ϊ32λ�޷�������
	* @param pStr : ��ת�����ַ���
	* @return 32λ�޷�������
	*/
    UINT32  SDAtou(const CHAR* pStr);

	/**
	* @brief
	* ���ַ���ת��Ϊ64λ�޷�������
	* @param pStr : ��ת�����ַ���
	* @return 64λ�޷�������
	*/
	UINT64  SDAtou64(const CHAR* pStr); 

	/**
	* @brief
	* ��Unicode�ַ���ת��Ϊ64λ�޷�������
	* @param pStr : ��ת�����ַ���
	* @return 64λ�޷�������
	*/
	UINT64  SDWtou64(const WCHAR* pStr); 

    UINT32  SDWtou(const WCHAR* pStr);

    /**
	* @brief
	* ��Unicode�ַ���ת��Ϊ32λ�з�������
	* @param _Str : ��ת�����ַ���
	* @return 32λ�з�������
	*/
	inline INT32 SDWtoi(const WCHAR *_Str)
	{
		return atoi(SDW2A(_Str).c_str());
	}

    /**
    * @brief
    * ��һ������ת��Ϊ�ַ���
    * @param pBuf : ת������ַ��洢�ռ�
    * @param buflen : �ַ��洢�ռ����󳤶�
    * @param dwNum : ����ת��������
    * @return ת�����ַ���ʹ�õĿռ䳤��
    */
    inline INT32  SDItoa(CHAR* pBuf, UINT32 buflen, INT32 dwNum)
    {
        return SDSnprintf(pBuf, buflen, "%d", dwNum);
    }

	/**
    * @brief
    * ��һ������ת��ΪUnicode�ַ���
    * @param pBuf : ת������ַ��洢�ռ�
    * @param buflen : �ַ��洢�ռ����󳤶�
    * @param dwNum : ����ת��������
    * @return ת�����ַ���ʹ�õĿռ䳤��
    */
    inline INT32  SDItow(WCHAR* pBuf, UINT32 buflen, INT32 dwNum)
    {
        return swprintf(pBuf, buflen, L"%d", dwNum);
    }


	/**
	* @brief
	* ����64λ��������ת��Ϊ�ַ���
	* @param pBuf : ת������ַ��洢�ռ�
	* @param buflen : �ַ��洢�ռ����󳤶�
	* @param dqNum : ����ת��������
	* @return ת�����ַ���ʹ�õĿռ䳤��
	*/
	inline INT32  SDItoa64(CHAR *pBuf, UINT32 buflen, INT64 dqNum)
	{
		return SDSnprintf(pBuf, buflen, SDFMT_I64 , dqNum);
	}

	/**
	* @brief
	* ����64λ��������ת��ΪUnicode�ַ���
	* @param pBuf : ת������ַ��洢�ռ�
	* @param buflen : �ַ��洢�ռ����󳤶�
	* @param dqNum : ����ת��������
	* @return ת�����ַ���ʹ�õĿռ䳤��
	*/
    inline INT32  SDItow64(WCHAR *pBuf, UINT32 buflen, INT64 dqNum)
    {
        return swprintf(pBuf, buflen,WCHAR_SDFMT_I64 , dqNum);
    }

	/**
	* @brief
	* ���޷�������ת��Ϊ�ַ���
	* @param pBuf : ת������ַ��洢�ռ�
	* @param buflen : �ַ��洢�ռ����󳤶�
	* @param dwNum : ����ת��������
	* @return ת�����ַ���ʹ�õĿռ䳤��
	*/
	inline INT32  SDUtoa(CHAR *pBuf, UINT32 buflen, UINT32 dwNum)
	{
		return SDSnprintf(pBuf, buflen, "%u", dwNum);
	}

	/**
	* @brief
	* ���޷�������ת��ΪUnicode�ַ���
	* @param pBuf : ת������ַ��洢�ռ�
	* @param buflen : �ַ��洢�ռ����󳤶�
	* @param dwNum : ����ת��������
	* @return ת�����ַ���ʹ�õĿռ䳤��
	*/
    inline INT32  SDUtow(WCHAR *pBuf, UINT32 buflen, UINT32 dwNum)
    {
        return swprintf(pBuf, buflen, L"%u", dwNum);
    }


	/**
	* @brief
	* ����64λ�޷�������ת��Ϊ�ַ���
	* @param pBuf : ת������ַ��洢�ռ�
	* @param buflen : �ַ��洢�ռ����󳤶�
	* @param dqNum : ����ת��������
	* @return ת�����ַ���ʹ�õĿռ䳤��
	*/
	inline INT32  SDUtoa64(CHAR* pBuf,UINT32 buflen, UINT64 dqNum)
	{
		return SDSnprintf(pBuf, buflen, SDFMT_U64, dqNum);
	}
   
	/**
	* @brief
	* ����64λ�޷�������ת��ΪUnicode�ַ���
	* @param pBuf : ת������ַ��洢�ռ�
	* @param buflen : �ַ��洢�ռ����󳤶�
	* @param dqNum : ����ת��������
	* @return ת�����ַ���ʹ�õĿռ䳤��
	*/
    inline INT32  SDUtow64(WCHAR* pBuf,UINT32 buflen, UINT64 dqNum)
    {
        return SDSwprintf(pBuf, buflen, WCHAR_SDFMT_U64, dqNum);
    }

    /**
    * @brief
    * ���ַ���ת��Ϊ������
    * @param nptr : ����ת������0��β���ַ���
    * @param endptr : [�������]����ΪNULL���������޷�ת�����ַ������ﷵ����ָ��
    * @return ��ȡ�ĸ�����
    */
    inline DOUBLE  SDStrtod(const CHAR *nptr, CHAR **endptr)
    {
        return strtod(nptr, endptr);
    }

	/**
    * @brief
    * ��Unicode�ַ���ת��Ϊ������
    * @param nptr : ����ת������0��β���ַ���
    * @param endptr : [�������]����ΪNULL���������޷�ת�����ַ������ﷵ����ָ��
    * @return ��ȡ�ĸ�����
    */
    inline DOUBLE  SDWCStrtod(const WCHAR *nptr, WCHAR **endptr)
    {
        return wcstod(nptr, endptr);
    }
    
    /**
    * @brief
    * split a string���ַ����ָ�Ϊһ���ַ�����vector
    * @param sSource : ���ָ���ַ���
    * @param delim : �ָ�������:��:������,������ ����
    * @return a vector to store strings splited from sSource
    */
    std::vector<std::string>  SDSplitStringsA(const std::string &sSource, CHAR delim);
   
	/**
    * @brief
    * split a wstring��Unicode�ַ����ָ�Ϊһ��Unicode�ַ�����vector
    * @param sSource : ���ָ��Unicode�ַ���
    * @param delim : �ָ�������:��:������,������ ����
    * @return a vector to store wstrings splited from sSource
    */
	std::vector<std::wstring>  SDSplitStringsW(const std::wstring &sSource, WCHAR delim);

    /**
    * @brief
    * ���ַ���ת��Ϊ��д
    * @param pszStr : ����ת�����ַ���
    * @return ת������ַ���
    */
    std::string  SDStrupr(std::string &pszStr);

    /**
    * @brief
    * ���ַ���ת��ΪСд
    * @param pszStr : ����ת�����ַ���
    * @return ת������ַ���
    */
    std::string  SDStrlwr(std::string &pszStr);

    /**
    * @brief
    * ��һ���ַ����ÿ�
    * @param Destination : ��Ҫ�ÿյ�����
    * @return VOID
    */
    template <class T>
    inline VOID  SDZeroString(T &Destination) throw()
    {
        (static_cast<CHAR[sizeof(Destination)]>(Destination));
        Destination[0] = '\0';
        Destination[sizeof(Destination)-1] = '\0';
    }


    /**
    * @brief
    * ��������Bufferת��Ϊ�ַ���,
    * @param pBuf    ������Bufferָ��
    * @param bufLen  ������Buffer����
    * @param pSplitter ����Ķ��������ݼ����
	* @param lineLen Դ�ַ����ָ���е�ÿ�г���,�ó��Ȳ������ָ����ĳ���
    * @return ת������ַ���
    */
    std::string  SDBufferToHexA(const CHAR *pBuf, UINT32 bufLen, const CHAR *pSplitter = "", INT32 lineLen = -1);

	/**
    * @brief
    * ��������Bufferת��ΪUnicode�ַ���,
    * @param pBuf    ������Bufferָ��
    * @param bufLen  ������Buffer����
    * @param pSplitter ����Ķ��������ݼ����
	* @param lineLen Դ�ַ����ָ���е�ÿ�г���,�ó��Ȳ������ָ����ĳ���
    * @return ת�����Unicode�ַ���
    */
    std::wstring  SDBufferToHexW(const WCHAR *pBuf, UINT32 bufLen, const WCHAR *pSplitter = L"", INT32 lineLen = -1);

    /**
    * @brief
    * ��32λ�з�����������ת��Ϊ�����ƴ�,
    * @param dwNum : 32λ�з�����������
    * @return ת������ַ���
    */
    std::string  SDIntToHexA(INT32 dwNum);

	/**
    * @brief
    * ��32λ�з�����������ת��Ϊ�����ƴ�,
    * @param dwNum : 32λ�з�����������
    * @return ת�����Unicode�ַ���
    */
    std::wstring  SDIntToHexW(INT32 dwNum);

    /**
    * @brief
    * ��str��ߵ�chȥ����ԭ�ַ��������޸�
    * @param pszStr : ȥ����ߵ�ch�ַ�
    * @param pTrimStr : ��ȥ�����ַ�
    * @return ȥ���ַ�pTrimStr����ַ���
    */
    std::string  SDStrTrimLeftA(std::string &pszStr, const CHAR *pTrimStr = " \r\t\n");

	/**
    * @brief
    * ��str��ߵ�chȥ����ԭUnicode�ַ��������޸�
    * @param pszStr : ȥ����ߵ�ch�ַ�
    * @param pTrimStr : ��ȥ�����ַ�
    * @return ȥ���ַ�pTrimStr���Unicode�ַ���
    */
    std::wstring  SDStrTrimLeftW(std::wstring &pszStr, const WCHAR *pTrimStr = L" \r\t\n");

    /**
    * @brief
    * ��str�ұߵ�chȥ����ԭ�ַ��������޸�
    * @param pszStr : ȥ���ұߵ�ch�ַ�
    * @param pTrimStr : ��ȥ�����ַ�
    * @return ȥ���ַ�pTrimStr����ַ���
    */
    std::string  SDStrTrimRightA(std::string &pszStr, const CHAR *pTrimStr = " \r\t\n");

	/**
    * @brief
    * ��str�ұߵ�chȥ����ԭUnicode�ַ��������޸�
    * @param pszStr : ȥ���ұߵ�ch�ַ�
    * @param pTrimStr : ��ȥ�����ַ�
    * @return ȥ���ַ�pTrimStr���Unicode�ַ���
    */
	std::wstring  SDStrTrimRightW(std::wstring &pszStr, const WCHAR *pTrimStr = L" \r\t\n");

    /**
    * @brief
    * ��str�������ߵ�pTrimStrȥ����ԭ�ַ��������޸�
    * @param pszStr : ȥ���������ߵ�ch�ַ�
    * @param pTrimStr : ��ȥ�����ַ�
    * @return ȥ���ַ�pTrimStr����ַ���
    */
    std::string  SDStrTrimA(std::string &pszStr, const CHAR* pTrimStr = " \r\t\n");
   
	/**
    * @brief
    * ��str�������ߵ�pTrimStrȥ����ԭUnicode�ַ��������޸�
    * @param pszStr : ȥ���������ߵ�ch�ַ�
    * @param pTrimStr : ��ȥ�����ַ�
    * @return ȥ���ַ�pTrimStr���Unicode�ַ���
    */
	std::wstring  SDStrTrimW(std::wstring &pszStr, const WCHAR* pTrimStr = L" \r\t\n");

    /** @} */


    /**
    * @brief Unicode�ַ�����ʽ��
    * @param buffer : �洢��ʽ�����buffer
    * @param n      : Unicode�ַ�������
    * @param format : ����ʽ����Unicode�ַ���
    * @return ��ֵ:�ɹ�ת�����ַ����ĳ��� ��ֵ:��ʽ��ʧ��
    */
	INT32  SDsnwprintf(WCHAR* buffer, size_t n, const WCHAR* format, ...);

    template <class T>
    inline void SDSafeSprintf(T& Destination, const CHAR *format, ...)
    {
        (static_cast<char[sizeof(Destination)]>(Destination));

        va_list args;
        va_start(args,format);
        _vsnprintf(Destination, sizeof(Destination)-1, format, args);
        va_end(args);
        Destination[sizeof(Destination)-1] = '\0';
    }

}//namespace UCODE

#endif


