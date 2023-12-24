#include "SSBTreeAct_MoveByPath.h"
#include "SSAI_HeroRobot.h"
#include "SSHero.h"
#include "SSBattle.h"
#include "SSCfgMgr.h"

namespace SceneServer{
	BOOLEAN	CSSBTreeAct_MoveByPath::Action(CSSAI_HeroRobot* pAI){
		pAI->SetLastActionTime(GetUTCMiliSecond());
		//ELOG(LOG_DBBUG,"Action: Start Move By Path");
		CSSHero* pHero = pAI->GetHero();

		if(m_parameters[0] == 1){
			//Ѱ��һ��������·��
			INT32 nearestPathIndex = 0;
			INT32 nearestNodeIndex = 0;
			//����ڼң������ѡ��һ��·
			if(pHero->GetCurPos().CanWatch(500,pHero->GetHeroBornPos())){
				nearestNodeIndex = 0;
				nearestPathIndex = pAI->Random(0,pAI->GetPathVec().size()-1);
			}
			//����ѡ�������һ��·
			else{
				FindNearestPathNode(pAI,nearestPathIndex,nearestNodeIndex);
			}
			//����������һ�����ƶ�
			if(nearestNodeIndex < pAI->GetPathVec()[nearestPathIndex].size() - 1) nearestNodeIndex++;
			//�ƶ�
			return pAI->MoveByPath(nearestPathIndex,nearestNodeIndex,TRUE);
		}
		else if(m_parameters[0] == 2){
			//Ѱ��һ���ؼҵ�·��
			INT32 nearestPathIndex = 0;
			INT32 nearestNodeIndex = 0;
			FindNearestPathNode(pAI,nearestPathIndex,nearestNodeIndex);
			//��������ǰһ�����ƶ�
			if(nearestNodeIndex > 0) nearestNodeIndex--;
			//�ƶ�
			return pAI->MoveByPath(nearestPathIndex,nearestNodeIndex,FALSE);
		}
		
		return FALSE;
	}

	void	CSSBTreeAct_MoveByPath::FindNearestPathNode(CSSAI_HeroRobot* pAI,INT32 &nearestPathIndex,INT32 &nearestNodeIndex){
		CSSHero* pHero = pAI->GetHero();
		CVector3D curPos = pHero->GetCurPos();
		vector<vector<CVector3D>> pathVec = pAI->GetPathVec();
		float distSqr = 0;
		for(int pathIndex = 0; pathIndex < pathVec.size(); pathIndex++){
			vector<CVector3D>* pPath = &pathVec[pathIndex];
			for(int nodeIndex = 0; nodeIndex < pPath->size(); nodeIndex++){
				CVector3D node = pPath->at(nodeIndex);
				float dist = curPos.GetWatchDistSqr(node);
				if(distSqr == 0 || dist < distSqr){
					distSqr = dist;
					nearestPathIndex = pathIndex;
					nearestNodeIndex = nodeIndex;
				}
			}
		}
	}
};