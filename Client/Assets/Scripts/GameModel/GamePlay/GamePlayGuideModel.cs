using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using BlGame.GuideDate;

using BlGame.Ctrl;

namespace BlGame.Model
{
    public class GamePlayGuideModel : Singleton<GamePlayGuideModel>
    {
        public int NowTaskId;

        /// <summary>
        /// 完成子任务
        /// </summary>
        /// <param name="taskId"></param>
        public void OnFinishChildTask(GuideTaskType type , int taskId)
        {
            if (!ConfigReader.GuideTaskMgrInfoDict.TryGetValue(NowTaskId, out GuideMgr))
            {
                return;
            }
            switch (GuideMgr.TaskEndType)
            {
                case GuideDate.TaskCheckType.AllMeetCheck: AllGuideChildTaskCheck(taskId); break;

                case GuideDate.TaskCheckType.AnyMeetCheck: AnyGuideChildTaskCheck(taskId); break;

                case GuideDate.TaskCheckType.PartMeetCheck: PartGuideChildTaskCheck(taskId); break;
            }
        }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
        /// <summary>
        /// 完成全部子任务
        /// </summary>
        private void AllGuideChildTaskCheck(int taskId)
        { 

        }

        /// <summary>
        /// 完成指定子任务
        /// </summary>
        private void AnyGuideChildTaskCheck(int taskId)
        {
        }

        private void PartGuideChildTaskCheck(int taskId)
        {
            if (GuideMgr.EndTaskChildId == taskId)
            {
                OnChangeToNextTask();
            }
        }

        /// <summary>
        /// 开始模块Id
        /// </summary>
        /// <param name="modelId"></param>
        public void StartModelTask(mGuideStepInfo modelId)
        {
            foreach (var item in ConfigReader.GuideTaskMgrInfoDict)
            {
                if ((mGuideStepInfo)item.Value.mTasktype == modelId)
                {
                    NowTaskId = item.Key;
                    return;
                }
            }
        }

        /// <summary>
        /// 是否事件执行触发
        /// </summary>
        /// <param name="mType"></param>
        /// <param name="gObj"></param>
        /// <returns></returns>
        public bool IsGuideTrigger(ButtonTriggerType mType, GameObject gObj)
        {
            foreach (GuideTaskBase task in GuideTaskExecuteList)
            {
                if (task.taskType != GuideTaskType.ForceClickTask)
                {
                    continue;
                }
                GuideForceClick click = (GuideForceClick)task;
                if (click.IsGuideTrigger(mType, gObj))
                {
                    return true;
                }
            }
            return false;
        }

        /// <summary>
        /// 转换到下一个引导任务模块
        /// </summary>
        public void OnChangeToNextTask()
        {
            GuideClearTask();
            if (GuideMgr.moduleend)             //如果完成的任务是模块的最后一个任务，告诉服务器
            {
                GamePlayGuideCtrl.Instance.GuideCSStepComplete(GuideMgr.mTasktype, (mGuideStepInfo)GuideMgr.mTasktype == mGuideStepInfo.BuyRuneGuide);
            }
            if (UIGuideModel.Instance.mIsGuideComp && GuideMgr != null && GuideMgr.moduleend)
            {
                GamePlayGuideCtrl.Instance.Exit();
                return;
            }
            if (GuideMgr == null)
            {
                return;
            }
            NowTaskId = GuideMgr.NextTaskId;
            if (!ConfigReader.GuideTaskMgrInfoDict.TryGetValue(NowTaskId, out GuideMgr))
            {
                return;
            }
            //if (UIGuideModel.Instance.mGuideFinishList.Contains((uint)GuideMgr.mTasktype))              //如果当前模块是之前已经完成的
            //{
            //    GamePlayGuideCtrl.Instance.Exit();
            //    return;
            //}
            if (GuideMgr.mToServerType != 0)
            {
                GamePlayGuideCtrl.Instance.AskSSGuideStepComp((GCToSS.AskSSGuideStepComp.Edotype)GuideMgr.mToServerType, NowTaskId);
            }
            EventCenter.Broadcast(EGameEvent.eGameEvent_PlayTaskModelFinish);
        }

        public void GuideClearTask()
        {
            foreach (GuideTaskBase task in GuideTaskExecuteList)
            {
                task.ClearTask();
            }
            GuideTaskExecuteList.Clear();
        }

        //
        public void ClearModelData()
        {
            GuideTaskExecuteList.Clear();
            GuideMgr = null;
        }

        public List<GuideTaskBase> GuideTaskExecuteList = new List<GuideTaskBase>();

        private GuideMgrInfo GuideMgr;
    }


}
