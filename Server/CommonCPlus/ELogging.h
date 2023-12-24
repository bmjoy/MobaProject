// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� ELOGGING_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// ELOGGING_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef ELOGGING_EXPORTS
#define ELOGGING_API extern "C" __declspec(dllexport)
#else
#define ELOGGING_API extern "C" __declspec(dllimport)
#endif

ELOGGING_API void ELog(int eLoggingEnum, char* fun, int line, char* msg, ...);

ELOGGING_API void ELogDirect(int eLoggingEnum, char* fun, int line, char* msg);