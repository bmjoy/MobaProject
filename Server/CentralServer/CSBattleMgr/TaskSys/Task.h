#pragma once

#include <map>
#include <vector>
#include <list>
using namespace std;
#include "..\..\CommonCPlus\Include\FBAll_Const.h"
#include "..\CSUser.h"

class CTask
{
public:
	CTask(CCSUser* user, const STaskConfig* pTaskConfig);
	virtual ~CTask();
public:
	UINT32 GetGUID() { return mTaskGUID; }
	TASK_TIME_TYPE GetTimeType() { return mTaskConfig->taskTimeType; }
	TASK_TYPE GetType() { return mTaskConfig->taskType; }
	UINT32 GetID() { return mTaskConfig->taskID; }
	UINT32 GetNextID() { return mTaskConfig->nextTaskID; }
	UINT32 GetParam(UINT32 pos) { return mTaskConfig->taskParams[pos]; }
	UINT32 GetCount() { return mCurCount; }

public:
	bool AddCount(UINT32 count) { mCurCount+=count; NotifyCount(); return IsFinished(); }
	bool IsFinished() { return mCurCount>=mTaskConfig->taskMaxCount; }
	bool IsCanAwards() { return mCurCount!=UINT32_MAX; }
	void NotifyCount();
	void GiveAwards();

public:
	static UINT32 mMaxTaskGUID;
	UINT32 mTaskGUID;//��ǰ����Ψһ���
	UINT32 mCurCount;//��ǰ����
	const STaskConfig* mTaskConfig;
	CCSUser* mOwner;
};
