using UnityEngine;
using BlGame.Network;
using System.Collections;
using System.Collections.Generic;
using BlGame;
using BlGame.Model;
using BlGame.GameEntity; 

namespace BlGame.Ctrl
{ 
    public class MailCtrl : Singleton<MailCtrl>
    {
        public void Enter()
        {
            EventCenter.Broadcast(EGameEvent.eGameEvent_MailEnter);
        }

        public void Exit()
        {
            EventCenter.Broadcast(EGameEvent.eGameEvent_MailExit);
        }

        //关闭邮件
        public void DelOrSortMailList(int mailId, bool ifDel, bool ifSort)
        {
            MailModel.Instance.ResetMailList(mailId, ifDel, ifSort);
        }
        public void DelOrSortMailList(GSToGC.DelAndSortMail pMsg)
        { 
            DelOrSortMailList(pMsg.Mailid, pMsg.mailidDel, pMsg.Sort);
        }
        //新增邮件
        public void AddMail(GSToGC.NotifyMailList pMsg)
        { 
            foreach(GSToGC.ShortMail mail in pMsg.mailLists)
            {
                MailModel.Instance.AddMailData((int)mail.mailType, mail.Mailid, mail.mailTitle, (EMailCurtState)mail.mailState);
            } 
            //从新排序
            MailModel.Instance.SortMailList();

            EventCenter.Broadcast(EGameEvent.eGameEvent_AddNewMailReq);

            Debug.Log("=====11111111111========");
            EventCenter.Broadcast(EGameEvent.eGameEvent_UpdateMailList);
            Debug.Log("=====11111111111========");
        }
        //更新单封邮件
        public void UpdateMailInfo(GSToGC.MailInfo pMsg)
        {
            MailModel.Instance.UpdateMailInfo(pMsg.Mailid, pMsg.Mailcontent, pMsg.Mailgift, pMsg.Sender, pMsg.createTime); 
        }

        //获取单封邮件内容
        public void GetMailContent(int mailId)
        {
            if (mailId < 1)
            {
                Debug.LogWarning("mailId < 1" );
                return;
            }
            if (MailModel.Instance.CheckMailContentByMailId(mailId))
            {
                return;
            }

            GCToCS.AskMailInfo pMsg = new GCToCS.AskMailInfo()
            {
                mailId = mailId
            };
            NetworkManager.Instance.SendMsg(pMsg, (int)pMsg.Msgnum);

            Debug.LogWarning("AskMailInfo:" + mailId);
        }
        //关闭 或者 领取奖励
        public void CloseOrGetMailGift(int mailId)
        {
            Debug.Log("CloseOrGetMailGift:" + mailId);

            GCToCS.AskGetMailGift pMsg = new GCToCS.AskGetMailGift()
            {
                mailId = mailId
            };
            NetworkManager.Instance.SendMsg(pMsg, (int)pMsg.Msgnum);
            
        } 
        
    }
}
