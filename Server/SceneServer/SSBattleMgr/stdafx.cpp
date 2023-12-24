// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// UserMgr.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"
#include "SSBattle.h"
#include <windows.h>  
#include <Mmsystem.h>
#include "SSWorkThreadMgr.h"
// TODO: �� STDAFX.H ��
// �����κ�����ĸ���ͷ�ļ����������ڴ��ļ�������

namespace SceneServer{

int64_t GetUTCMiliSecond(){
	return CSSWorkThreadMgr::GetInstance().GetUTCTimeOfPerThread();
}  

INT64 GetWinMiliseconds(){
	LARGE_INTEGER s_frequency;
	BOOL s_use_qpc = QueryPerformanceFrequency(&s_frequency);
	LARGE_INTEGER now;
	QueryPerformanceCounter(&now);
	return (1000LL * now.QuadPart) / s_frequency.QuadPart;
}
}