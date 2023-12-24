#ifndef _SDNETCONFIG_H_
#define _SDNETCONFIG_H_
#include "ucconfig.h"
#if (defined(WIN32) || defined(WIN64))
#include <WinSock2.h>
#include <Windows.h>
#else
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#endif 
#include <assert.h>
#include <stdio.h>
#include "uclogger.h"
#include "ucstring.h"
#include "uctype.h"
using namespace UCODE;

#define SDASSERT assert

#define DEFAULT_SENDBUF_SIZE	65536
#define DEFAULT_RECVBUF_SIZE	65536

//�����ͻ���յ���������
#define MAX_PKG_LEN		(1024*1024*10)

extern UINT32 g_dwNetLogLevel;
extern CSDLogger g_oNetLogger;

extern INT32 g_nThreadNum;
extern INT32 g_nLoopSize;
extern BOOL  g_bNodelay;
#define CRITICAL	if(g_dwNetLogLevel & LOGLV_CRITICAL)g_oNetLogger.Critical
#define WARN		if(g_dwNetLogLevel & LOGLV_WARN)	g_oNetLogger.Warn
#define INFO		if(g_dwNetLogLevel & LOGLV_INFO)	g_oNetLogger.Info
#define DBG			if(g_dwNetLogLevel & LOGLV_DEBUG)	g_oNetLogger.Debug

extern INT32 MAX_CONNECTION;		//�������������
extern INT32 RECV_LOOP_BUF_SIZE;	//����ѭ��buffer��С��Epoll�̵߳����̵߳����ݹܵ���С
extern INT32 SEND_LOOP_BUF_SIZE;	//����ѭ��buffer��С�������̵߳�Epoll�̵߳����ݹܵ���С
extern INT32 MAX_NET_REQUEST;		//���̵߳�Epoll�̵߳�������д�С
extern INT32 MAX_NET_EVENT;			//Epoll�̵߳����̵߳������¼����д�С
extern INT32 POP_TO_BUF_COUNT;		//ÿ������ʱ��������е���������¼��ĸ���
extern INT32 VAL_SO_SNDLOWAT;		//���͵ͳ�����setsockopt�е�SO_SNDLOWAT
extern UINT32 DELAY_RELEASE_CPSOCK_TIME;

#define MSG_MARK  _SDTA2T(__FUNCTION__), __LINE__



#endif // 

