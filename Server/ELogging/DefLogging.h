#pragma once
#include <Windows.h>
#include "ELogging\ELogging.h"
#include <iostream>
#include <tchar.h>

#pragma comment(lib,"..\\..\\Bin\\x64\\Release\\ELogging.lib")

// ע�⣺���ö��ֵ��2��//
enum LoggingEnum{
	LOG_INFO,
	LOG_DBBUG,
	LOG_ERROR,
	LOG_WARNNING,
	LOG_SpecialDebug,
	LOG_ASSERT,
	LOG_END
};
