#include "stdafx.h"
#include "TaskMgr.h"
#include "..\CSCfgMgr.h"
#include "..\CSUserMgr.h"
using namespace CentralServer;

CTaskMgr::CTaskMgr(CCSUser* user)
{
	mOwner = user;
	mDailyDay = 0;
	mIsForbidAllTaskNotify = false;
	mIsForbidDailyTaskNotify = false;
}

CTaskMgr::~CTaskMgr()
{

}

bool CTaskMgr::AddTask( UINT32 taskId, UINT32 taskCount/*=0*/ )
{
	if (taskId==0) return false;
	const STaskConfig* pTaskConfig = CCSCfgMgr::getInstance().GetTaskConfig(taskId);
	if (pTaskConfig==NULL) return false;
	CTask* pTask = new CTask(mOwner,pTaskConfig);
	pTask->mCurCount = taskCount;
	if (pTask->GetTimeType()==TTT_Daily)
		mDailyTasks.insert(make_pair(pTask->GetGUID(),pTask));
	else if (pTask->GetTimeType()==TTT_Infinite)
		mInfiniteTasks.insert(make_pair(pTask->GetGUID(),pTask));
	mAllTasks.push_back(pTask);
	NotifyTaskAdd(pTask);
	return true;
}

bool CTaskMgr::FinishTask( UINT32 taskGuid )
{
	CTask* pTask = NULL;
	for (auto it=mAllTasks.begin();it!=mAllTasks.end();++it){
		pTask = (*it);
		if (pTask->GetGUID()==taskGuid){
			if (pTask->IsFinished() && pTask->IsCanAwards()){//�ж��Ƿ�������,�Ƿ�����콱
				pTask->GiveAwards();//��������
				AddTask(pTask->GetNextID());//������һ����
				if (pTask->GetTimeType()!=TTT_Daily){//�ճ�������ɾ��
					mDailyTasks.erase(taskGuid);
					mInfiniteTasks.erase(taskGuid);
					mAllTasks.erase(it);
					NotifyTaskDel(pTask);
					delete pTask;
				}
				return true;
			}
			break;
		}
	}
	return false;
}

bool CTaskMgr::OnEvent( TASK_TYPE tt,UINT32 count,UINT32 param1,UINT32 param2 )
{
	CTask* pTask = NULL;
	for (auto it=mAllTasks.begin();it!=mAllTasks.end();++it)
	{
		pTask = (*it);
		if (pTask->GetType()!=tt) continue;
		// ����Ҫ����У�飬ֱ�Ӽ���
		if (pTask->GetParam(0)==0) { pTask->AddCount(count); continue; }
		// ��������Ž��м���
		switch(tt)
		{
		case TT_GameWin:
			if (pTask->GetParam(1)==param1/*����ID*/) pTask->AddCount(count);
			break;
		}
	}
	return true;
}

bool CTaskMgr::RushDailyTasks()
{
	mIsForbidDailyTaskNotify = true;
	for (auto it=mDailyTasks.begin();it!=mDailyTasks.end();++it){
		for (auto itAll=mAllTasks.begin();itAll!=mAllTasks.end();++itAll){
			if ((*itAll)->GetGUID()==it->second->GetGUID()){
				mAllTasks.erase(itAll);
				break;
			}
		}
	}
	mDailyTasks.clear();
	// ֪ͨÿ������ȫ�ѽ���
	mDailyDay = CentralServer::GetCSUserMgrInstance()->GetTodayTime().date().day_number();
	AddTask(10001);
	AddTask(10002);
	NotifyAllDailyTask();
	mIsForbidDailyTaskNotify = false;
	return true;
}

bool CTaskMgr::PackTaskData( string& taskData, bool& isTaskRush )
{
	string oldTaskData = taskData;
	stringstream sTaskListVal;
	sTaskListVal << mDailyDay << ",";
	CTask* pTask = NULL;
	for (auto it=mAllTasks.begin();it!=mAllTasks.end();++it)
	{
		pTask = (*it);
		sTaskListVal << pTask->GetID() << ":" << pTask->GetCount() << ",";
	}
	taskData = sTaskListVal.str();
	isTaskRush = (taskData==oldTaskData?false:true);
	return true;
}

bool CTaskMgr::UnpackTaskData( string& taskData )
{
	mIsForbidAllTaskNotify = true;
	for (auto it=mAllTasks.begin();it!=mAllTasks.end();++it){
		delete (*it);
	}
	mDailyDay = 0;
	mDailyTasks.clear();
	mInfiniteTasks.clear();
	mAllTasks.clear();
	vector<string> vTasks;
	boost::algorithm::split(vTasks, taskData, boost::algorithm::is_any_of(","));
	bool isRushDailyTask = false;
	for (auto it=vTasks.begin();it!=vTasks.end();++it){
		if (it==vTasks.begin()){//��һԪ�أ��ճ�����ʱ��
			boost::posix_time::ptime& todayTime = CentralServer::GetCSUserMgrInstance()->GetTodayTime();
			UINT32 updateDay = todayTime.date().day_number();//����5�������
			if (todayTime.time_of_day().hours()<5) updateDay -= 1;
			mDailyDay= atoi((*it).c_str());
			if (mDailyDay==0 || mDailyDay<updateDay) isRushDailyTask = true;
		}
		else{//����Ԫ�أ�ȫ������
			vector<string> oneTask;
			boost::algorithm::split(oneTask, (*it), boost::algorithm::is_any_of(":"));
			if (oneTask.size()!=2) continue;
			UINT32 taskId = atoi(oneTask[0].c_str());
			UINT32 taskCount = atoi(oneTask[1].c_str());
			const STaskConfig* pTaskConfig = CCSCfgMgr::getInstance().GetTaskConfig(taskId);
			if (pTaskConfig==NULL) continue;
			if (isRushDailyTask && pTaskConfig->taskTimeType==TTT_Daily) continue;
			AddTask(taskId,taskCount);
		}
	}
	if (isRushDailyTask) RushDailyTasks();
	mIsForbidAllTaskNotify = false;
	return true;
}

void CTaskMgr::NotifyTaskAdd( CTask* pTask )
{
	if (mIsForbidAllTaskNotify) return;
	if (mIsForbidDailyTaskNotify && pTask->GetTimeType()==TTT_Daily) return;
	GSToGC::NotifyAddOneTask msg;
	msg.mutable_onetask()->set_task_id(pTask->GetID());
	msg.mutable_onetask()->set_task_guid(pTask->GetGUID());
	msg.mutable_onetask()->set_task_curcount(pTask->GetCount());
	mOwner->PostMsgToGC(msg,msg.msgid());
}

void CTaskMgr::NotifyTaskUpdate( CTask* pTask )
{
	if (mIsForbidAllTaskNotify) return;
	if (mIsForbidDailyTaskNotify && pTask->GetTimeType()==TTT_Daily) return;
	GSToGC::NotifyUpdateOneTask msg;
	msg.mutable_onetask()->set_task_id(pTask->GetID());
	msg.mutable_onetask()->set_task_guid(pTask->GetGUID());
	msg.mutable_onetask()->set_task_curcount(pTask->GetCount());
	mOwner->PostMsgToGC(msg,msg.msgid());
}

void CTaskMgr::NotifyTaskDel( CTask* pTask )
{
	if (mIsForbidAllTaskNotify) return;
	if (mIsForbidDailyTaskNotify && pTask->GetTimeType()==TTT_Daily) return;
	GSToGC::NotifyDelOneTask msg;
	msg.set_task_guid(pTask->GetGUID());
	mOwner->PostMsgToGC(msg,msg.msgid());
}

void CTaskMgr::NotifyTaskRewards( CTask* pTask )
{
	GSToGC::NotifyRewardsOneTask msg;
	msg.set_task_guid(pTask->GetGUID());
	mOwner->PostMsgToGC(msg,msg.msgid());
}

void CTaskMgr::NotifyAllTask()
{
	CTask* pTask = NULL;
	GSToGC::NotifyUpdateAllTask msg;
	for (auto it=mAllTasks.begin();it!=mAllTasks.end();++it)
	{
		pTask = (*it);
		::GSToGC::TaskData* pTaskData = msg.add_tasklist();
		pTaskData->set_task_id(pTask->GetID());
		pTaskData->set_task_guid(pTask->GetGUID());
		pTaskData->set_task_curcount(pTask->GetCount());
	}
	mOwner->PostMsgToGC(msg,msg.msgid());
}

void CTaskMgr::NotifyAllDailyTask()
{
	if (mIsForbidAllTaskNotify) return;
	CTask* pTask = NULL;
	GSToGC::NotifyUpdateAllDailyTask msg;
	for (auto it=mDailyTasks.begin();it!=mDailyTasks.end();++it)
	{
		pTask = (it->second);
		::GSToGC::TaskData* pTaskData = msg.add_tasklist();
		pTaskData->set_task_id(pTask->GetID());
		pTaskData->set_task_guid(pTask->GetGUID());
		pTaskData->set_task_curcount(pTask->GetCount());
	}
	mOwner->PostMsgToGC(msg,msg.msgid());
}
