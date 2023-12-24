using UnityEngine;
using System.Collections;
using System.Collections.Generic;

namespace BlGame.Model
{
    public class GoodsModel : Singleton<GoodsModel>
    {
        public void AddOrChangeRuneBaptze(int shopId, RuneBaptze rune)
        {
            if (!m_RuneBaptze.ContainsKey(shopId))
            {
                m_RuneBaptze.Add(shopId, rune);
                return;
            }
            m_RuneBaptze[shopId] = rune;
        }

        public void RemeoveRuneBaptze(int shopId)
        {
            if (m_RuneBaptze.ContainsKey(shopId))
            {
                m_RuneBaptze[shopId] = null;
                m_RuneBaptze.Remove(shopId);
            }
        }

        public Dictionary<int, RuneBaptze> GetRuneBaptzeMap()
        {
            return m_RuneBaptze;
        }

        public RuneBaptze GetRuneBaptze(int shopId)
        {
            if (!m_RuneBaptze.ContainsKey(shopId))
            {
                Debug.LogError("not find shopID");
                return null;
            }
            return m_RuneBaptze[shopId];
        }
        Dictionary<int, RuneBaptze> m_RuneBaptze = new Dictionary<int, RuneBaptze>();

        public void AddOrChangeRuneBaptze(List<GSToGC.NotifyOtherItemInfo.OtherItem> list)
        {
            foreach (var item in list)
            {
                if (item.ItemNum == 0)
                {
                    m_RuneBaptze.Remove((int)item.ItemId);
                }
                else
                {
                    RuneBaptze rune = new Model.RuneBaptze();
                    rune.mRemainingTime = item.ExpiredTime;
                    rune.mNum = (int)item.ItemNum;
                    AddOrChangeRuneBaptze((int)item.ItemId, rune);
                }

                EventCenter.Broadcast<uint, int, long>(EGameEvent.eGameEvent_RuneRefreshCardUpdate, item.ItemId, (int)item.ItemNum, (long)item.ExpiredTime);
            }
        }
    }
    public class RuneBaptze : System.Object
    {
        public long mRemainingTime;
        public int mNum;
    }
}
