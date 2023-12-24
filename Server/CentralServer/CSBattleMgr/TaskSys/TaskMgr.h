#pragma once

#include "Task.h"

/**

���ݿ�ṹ�壺ÿ���������ʱ��,����1ID:����1����,����2ID:����2����,.....

**/

class CTask;

class CTaskMgr
{
public:
	CTaskMgr(CCSUser* user);
	virtual ~CTaskMgr();
public:
	bool AddTask(UINT32 taskId,UINT32 taskCount=0);//��ȡ����
	bool FinishTask(UINT32 taskGuid);//�������
	bool RushDailyTasks();//ˢ��ÿ������
	bool OnEvent(TASK_TYPE tt,UINT32 count,UINT32 param1,UINT32 param2);//�����¼�
	bool PackTaskData(string& taskData,bool& isTaskRush);//��������
	bool UnpackTaskData(string& taskData);//��������
public:
	void NotifyTaskAdd(CTask* pTask);//֪ͨ��������
	void NotifyTaskUpdate(CTask* pTask);//֪ͨ��������
	void NotifyTaskRewards(CTask* pTask);//֪ͨ������
	void NotifyTaskDel(CTask* pTask);//֪ͨɾ������
	void NotifyAllTask();//֪ͨ��������
	void NotifyAllDailyTask();//֪ͨ�����ճ�����
private:
	CCSUser* mOwner;
	UINT32 mDailyDay;//�ճ�����ʱ��
	map<UINT32,CTask*> mDailyTasks;//�ճ�����
	map<UINT32,CTask*> mInfiniteTasks;//��������(�ɾ�����)
	vector<CTask*> mAllTasks;//��������
	bool mIsForbidAllTaskNotify;//�Ƿ�֪ͨ��������
	bool mIsForbidDailyTaskNotify;//�Ƿ�֪ͨ�ճ�����
};
