// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// UserMgr.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"
#include <boost/date_time/posix_time/posix_time.hpp> 
#include "boost/date_time/gregorian/gregorian.hpp"
// TODO: �� STDAFX.H ��
// �����κ�����ĸ���ͷ�ļ����������ڴ��ļ�������

INT64 GetMiliSecond(){
	using boost::gregorian::date;
	using boost::posix_time::ptime;
	using boost::posix_time::microsec_clock;
	static ptime const epoch(date(1970, 1, 1));
	return (microsec_clock::universal_time() - epoch).total_milliseconds();
}
