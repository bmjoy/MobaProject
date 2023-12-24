#include "SSSkillEffect_Fly.h"
#include "SSGameUnit.h"
#include "SSHero.h"
#include "SSBattle.h"
#include "SSEffectMgr.h"

namespace SceneServer{

CSSSkillEffect_Fly::CSSSkillEffect_Fly(){
	m_SkillEffectType = eSkillEffectType_Emit;
}

CSSSkillEffect_Fly::~CSSSkillEffect_Fly(){
}

INT32 CSSSkillEffect_Fly::Begin(){
	if (NULL == m_pcMasterGO){
		return eEC_EffectEnd;
	}

	m_lEmitEntityArr.Clear();
	m_lEmitHitTargetArr.Clear();

	const SSkillModelEmitCfg* pCfg = GetModelConfig();

	//���û�����Ϣ�����е�������������Ƕȣ�
	INT32 n32ProjNum = pCfg->n32ProjectileNum;
	INT32 n32AngleInter = pCfg->n32ProjectileAngle;
	INT32 n32LeftAngle = -n32AngleInter * (n32ProjNum-1) / 2;

	vector<CSSGameUnit*> vecAreaObj; 
	GO2SightDiffMap sGO2SightDiffMaptvEnemyMap;
	//�������Ϊ�Զ�Ѱ�У���ô����Ҫ����Χ���б��в���һ���Ϸ���Ŀ��
	if(pCfg->eEmitType == eSkillModelEmitType_AutoFind){
		//׼����Χ�����б�
		GetBattle()->FindAroundGU(m_pcMasterGO->GetCurPos(), pCfg->n32FlyPar2 + 500,vecAreaObj);
		for(vector<CSSGameUnit*>::iterator iter = vecAreaObj.begin(); iter != vecAreaObj.end();){
			CSSGameUnit* pcTempGU = *iter;
			float tempDist = (pcTempGU->GetCurPos() - m_pcMasterGO->GetCurPos()).length();
			if (pcTempGU->IsDead() || !CheckHitTargetType(pcTempGU) || !CheckHitTargetCamp(pcTempGU) || tempDist > pCfg->n32FlyPar2){
				iter = vecAreaObj.erase(iter);
			}
			else{
				iter++;
			}
		}
	}
	//���ݷ�������������ѭ���ͷ�
	for(int i = 0; i < n32ProjNum; i++){
		//��ȡÿһ����������ĳ����Ƕ�
		CVector3D cCurDir = m_pcMasterGO->GetGOActionStateInfo().cDir;
		INT32 n32Degree = n32LeftAngle + n32AngleInter * i;
		cCurDir.RotateXZBy((double)n32Degree);

		SSEmitEntity rsSSE;
		rsSSE.Clear();

		//����������Զ�Ѱ�У��������п���Ŀ���������һ��
		if(pCfg->eEmitType == eSkillModelEmitType_AutoFind){
			//���ѡ��һ��Ŀ��
			if(vecAreaObj.empty()){
				break;
			}
			CSSGameUnit* pTempGU = vecAreaObj.at(rand()%vecAreaObj.size());
			m_pcTarGU = pTempGU;
			cCurDir = (pTempGU->GetCurPos() - m_pcTarGU->GetCurPos()).unit();
			vector<CSSGameUnit*>::iterator iter = find(vecAreaObj.begin(),vecAreaObj.end(),pTempGU);
			vecAreaObj.erase(iter);
		}

		if (NULL != m_pcTarGU){
			rsSSE.sTargetGUID = m_pcTarGU->GetObjGUID();
		}

		//����ǻ����ڻ���ֱ�ӷ��м��ܣ�����һ�㴫�����ļ��ܿ�ʼ����Ϊ�գ�������Ϊ������㡣���򣬼���������Ϊ������㡣
		rsSSE.pcTargetGU = m_pcTarGU;
		CSSGameUnit* pStartUnit = m_pcMasterGO;
		if(pCfg->eEmitType == eSkillModelEmitType_Direct || pCfg->eEmitType == eSkillModelEmitType_Boomerang){
			if(NULL != m_pcStartSkillGU){
				pStartUnit = m_pcStartSkillGU;
			}
		}

		rsSSE.cCurPos = pStartUnit->GetEmitPos();
		rsSSE.cCurDir = cCurDir;
		rsSSE.tLaunchUTCMilsec = GetUTCMiliSecond();
		rsSSE.tLastEffectTime = rsSSE.tLaunchUTCMilsec;
		rsSSE.bIfEnded = false;
		rsSSE.bIfTurnBack = false;
		rsSSE.n32ProjectID = GetBattle()->GetUniqueEffectID();

		//����Ǵ�Ŀ�����Ͽ�ʼ�ĵ������ܣ�����Ҫ������Ѱ��һ������Ŀ��
		bool bIfEmitBuilded = TRUE;
		if((pCfg->eEmitType == eSkillModelEmitType_Bounce || pCfg->eEmitType == eSkillModelEmitType_Bounce_NoRepeat) && pCfg->n32FlyPar3 == 2){

			GetBattle()->GetEffectMgr()->AddEffectsFromCfg((SSNextSkillEffectCfg*)m_pCfg->asSkillModelList
				, m_pcMasterGO, m_pcTarGU, m_pcTarGU->GetCurPos(), m_pcMasterGO->GetCurDir(), m_pSkillRuntimeData, GetUTCMiliSecond());

			bool bIfCanRepeat = pCfg->eEmitType == eSkillModelEmitType_Bounce? TRUE : FALSE;
			rsSSE.cCurPos = m_pcTarGU->GetEmitPos();
			rsSSE.cCurDir = m_pcTarGU->GetCurDir();
			//Ѱ�ҵ���Ŀ��
			CSSGameUnit* pNextTarget = FindNextBounceTarget(&rsSSE,m_pcTarGU, bIfCanRepeat);
			if(pNextTarget != NULL){
				rsSSE.pcTargetGU = pNextTarget;
				rsSSE.sTargetGUID = pNextTarget->GetObjGUID();
				rsSSE.lHitTargetsArr.AddElement(m_pcTarGU->GetObjGUID());
				pStartUnit = m_pcTarGU;
			}
			else{
				bIfEmitBuilded = FALSE;
			}
		}
		if(bIfEmitBuilded){
			m_lEmitEntityArr.AddElement(rsSSE);
			NotifyNewEmitObjectToGC(pStartUnit, &rsSSE);
		}
	}
	return eNormal;
}

INT32 CSSSkillEffect_Fly::Update(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan){
	if(NULL == m_pcMasterGO || m_pcMasterGO->GetExpire()){
		return eEC_EffectEnd;
	}

	//�������������еķ������壬������һ���Ч����Ȼ������������Ƿ���Ҫ���١�
	const INT32 n32MaxHitTargetSize = m_lEmitHitTargetArr.GetMaxSize();
	for (INT32 i = 0; i < n32MaxHitTargetSize; ++i){
		if (TRUE == m_lEmitHitTargetArr.m_Arr[i].isVaild){
			SSEmitHitTargetInfo& entity = m_lEmitHitTargetArr.m_Arr[i].ele;
			if (NULL == entity.pTarget){
				m_lEmitHitTargetArr.m_Arr[i].isVaild = FALSE;
				--m_lEmitHitTargetArr.m_CurSize;
				continue;
			}

			if(FALSE == entity.pTarget->GetExpire() && entity.pTarget->IsDead() == FALSE){
				GetBattle()->GetEffectMgr()->AddEffectsFromCfg((SSNextSkillEffectCfg*)m_pCfg->asSkillModelList
					, m_pcMasterGO, entity.pTarget, entity.cPos, entity.cDir, m_pSkillRuntimeData, GetUTCMiliSecond());
				OnSkillHitTarget(entity.pTarget);
			}

			m_lEmitHitTargetArr.m_Arr[i].isVaild = FALSE;
			--m_lEmitHitTargetArr.m_CurSize;
		}
	}

	//������л��ڷ��еķ��е��ߣ��������������������ˣ�����������Ϣ
	const INT32 n32MaxSize = m_lEmitEntityArr.GetMaxSize();
	for (INT32 i = 0; i < n32MaxSize; ++i){
		if (TRUE == m_lEmitEntityArr.m_Arr[i].isVaild){
			SSEmitEntity& entity = m_lEmitEntityArr.m_Arr[i].ele;
			OnHeartBeat_CheckSimpleSkillEntityImpact(&entity, tUTCMilsec, tTickSpan);
			if(TRUE == entity.bIfEnded){
				const SSkillModelEmitCfg* pCfg = GetModelConfig();
				switch(pCfg->eEmitType){
				case eSkillModelEmitType_Direct:
				case eSkillModelEmitType_Boomerang:
				case eSkillModelEmitType_Area:
				case eSkillModelEmitType_AutoFind:
					NotifyDestoryEmitObjectToGC(&entity);
					break;
				}

				entity.Clear();
				m_lEmitEntityArr.m_Arr[i].isVaild = FALSE;
				--m_lEmitEntityArr.m_CurSize;
			}
		}
	}

	if(0 == m_lEmitEntityArr.GetCurSize() && 0 == m_lEmitHitTargetArr.GetCurSize()){
		return eEC_EffectEnd;
	}

	return eNormal;
}

INT32	CSSSkillEffect_Fly::OnHeartBeat_CheckSimpleSkillEntityImpact(SSEmitEntity *rsSSE, TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan){
	if(tUTCMilsec - rsSSE->tLaunchUTCMilsec < 50){
		return eNormal;
	}
	if(FALSE == CheckBattle()){
		return eEC_ConstInvalid;
	}
	const SSkillModelEmitCfg* pCfg = GetModelConfig();
	switch(pCfg->eEmitType)
	{
		//�Զ�������ķ���Ч�������ϼ���Ŀ��ľ��롣����ȶԷ��İ뾶С��������С�
	case eSkillModelEmitType_Follow:
	case eSkillModelEmitType_AutoFind:
		{
			if (rsSSE->sTargetGUID > 0 && NULL != rsSSE->pcTargetGU && FALSE == rsSSE->pcTargetGU->GetExpire() && rsSSE->pcTargetGU->IsDead() == FALSE){
				if (rsSSE->pcTargetGU->GetObjGUID() != rsSSE->sTargetGUID || rsSSE->pcTargetGU->IsDead()){
					rsSSE->bIfEnded = true;
					return eEC_InvalidSkillTarget;
				}
				CVector3D cTarPos = rsSSE->pcTargetGU->GetOnHitPos();
				CVector3D cSelfPos = rsSSE->cCurPos;
				CVector3D cDir = cTarPos - cSelfPos;
				float fDist = cDir.length() - rsSSE->pcTargetGU->GetObjCollideRadius();
				float fCanMoveDist = GetModelConfig()->n32ProjFlySpeed * (FLOAT)tTickSpan / 1000;
				if (fCanMoveDist >= fDist){
					SSEmitHitTargetInfo temp = {rsSSE->pcTargetGU, rsSSE->pcTargetGU->GetCurPos(), cDir};
					m_lEmitHitTargetArr.AddElement(temp);
					rsSSE->bIfEnded = true;
					return eEC_ConstInvalid;
				}
				cDir.unit();
				rsSSE->cCurPos = cSelfPos + cDir * fCanMoveDist;
			}
			else{
				rsSSE->bIfEnded = true;
			}
		}
		break;
		//ֱ�ӷ������Ч������Ҫ���ϼ���Ƿ�������ײ��һ������ЧĿ����ײ���������У�Ȼ����ݴ�͸�����ж��Ƿ����١�
	case eSkillModelEmitType_Direct:
		{
			//������ʱ��
			if(rsSSE->tLaunchUTCMilsec + pCfg->n32ProjectileLifeTime < tUTCMilsec){
				rsSSE->bIfEnded = true;
				return eEC_ConstInvalid;
			}

			CVector3D cSelfPos = rsSSE->cCurPos;
			CVector3D cDir = rsSSE->cCurDir;
			float fCanMoveDist = GetModelConfig()->n32ProjFlySpeed * (FLOAT)tTickSpan / 1000;
			vector<CSSGameUnit*> targetList;
			CheckSimpleSkillEntityImpact(rsSSE,fCanMoveDist,&targetList,pCfg->bIsPenetrate, FALSE);
			
			for(vector<CSSGameUnit*>::iterator iter = targetList.begin();iter != targetList.end(); iter++){
				if(CheckHitTargetType(*iter)){
					SSEmitHitTargetInfo temp = {*iter, (*iter)->GetCurPos(), cDir};
					m_lEmitHitTargetArr.AddElement(temp);
				}
			}
			//����Ŀ���Ҳ��Ǵ�͸������е�����ֹ��
			if(FALSE == targetList.empty() && FALSE == pCfg->bIsPenetrate){
				rsSSE->bIfEnded = true;
				return eEC_ConstInvalid;
			}
			
			cDir.unit();
			rsSSE->cCurPos = cSelfPos + cDir * fCanMoveDist;
		}
		break;
	case eSkillModelEmitType_Boomerang:
		{
			if(FALSE == rsSSE->bIfTurnBack){//������ǰ�ɽ׶�
				//������ʱ��
				if(rsSSE->tLaunchUTCMilsec + pCfg->n32ProjectileLifeTime < tUTCMilsec){
					NotifyTurnEmitObjectToGC(rsSSE);
					rsSSE->bIfTurnBack = true;
					rsSSE->pcTargetGU = m_pcMasterGO;
					rsSSE->sTargetGUID = m_pcMasterGO->GetObjGUID();
					rsSSE->cCurDir = (rsSSE->pcTargetGU->GetCurPos() - rsSSE->cCurPos).unit();
					rsSSE->Clear();
					return eNormal;
				}

				CVector3D cSelfPos = rsSSE->cCurPos;
				CVector3D cDir = rsSSE->cCurDir;
				float fCanMoveDist = GetModelConfig()->n32ProjFlySpeed * (FLOAT)tTickSpan / 1000;
				vector<CSSGameUnit*> targetList;
				CheckSimpleSkillEntityImpact(rsSSE,fCanMoveDist,&targetList,pCfg->bIsPenetrate, FALSE);

				for(vector<CSSGameUnit*>::iterator iter = targetList.begin();iter != targetList.end(); iter++){
					if(CheckHitTargetType(*iter)){
						SSEmitHitTargetInfo temp = {*iter, (*iter)->GetCurPos(), cDir};
						m_lEmitHitTargetArr.AddElement(temp);
					}
				}
				//����Ŀ���Ҳ��Ǵ�͸������е�����ֹ��
				if(FALSE == targetList.empty() && FALSE == pCfg->bIsPenetrate){
					rsSSE->bIfEnded = true;
					return eEC_ConstInvalid;
				}

				cDir.unit();
				rsSSE->cCurPos = cSelfPos + cDir * fCanMoveDist;
			}
			else{//��������׶�
				if (rsSSE->sTargetGUID > 0 && NULL != rsSSE->pcTargetGU && FALSE == rsSSE->pcTargetGU->GetExpire() && rsSSE->pcTargetGU->IsDead() == FALSE){
					if (rsSSE->pcTargetGU->GetObjGUID() != rsSSE->sTargetGUID || rsSSE->pcTargetGU->IsDead()){
						rsSSE->bIfEnded = true;
						return eEC_InvalidSkillTarget;
					}
					//CVector3D cTarPos = rsSSE->pcTargetGU->GetGOActionStateInfo().cPos;
					CVector3D cTarPos = rsSSE->pcTargetGU->GetOnHitPos();
					CVector3D cSelfPos = rsSSE->cCurPos;
					CVector3D cDir = cTarPos - cSelfPos;
					float fDist = cDir.length() - rsSSE->pcTargetGU->GetObjCollideRadius();
					float fCanMoveDist = GetModelConfig()->n32ProjFlySpeed * (FLOAT)tTickSpan / 1000;

					vector<CSSGameUnit*> targetList;
					CheckSimpleSkillEntityImpact(rsSSE,fCanMoveDist,&targetList,pCfg->bIsPenetrate, FALSE);
					for(vector<CSSGameUnit*>::iterator iter = targetList.begin();iter != targetList.end(); iter++){
						if(CheckHitTargetType(*iter)){
							SSEmitHitTargetInfo temp = {*iter, (*iter)->GetCurPos(), cDir};
							m_lEmitHitTargetArr.AddElement(temp);
						}
					}
					//����Ŀ���Ҳ��Ǵ�͸������е�����ֹ��
					if(FALSE == targetList.empty() && FALSE == pCfg->bIsPenetrate){
						rsSSE->bIfEnded = true;
						return eEC_ConstInvalid;
					}
					//�ص����ϣ���ֹ
					if (fCanMoveDist >= fDist){
						rsSSE->bIfEnded = true;
						return eEC_ConstInvalid;
					}
					cDir.unit();
					rsSSE->cCurPos = cSelfPos + cDir * fCanMoveDist;
				}
				else{
					rsSSE->bIfEnded = true;
				}
			}
		}
		break;
		//�����༼�ܣ������е�ʱ�򣬻��и��ݵ���������Ѱ����һ�ε�����Ŀ��
	case eSkillModelEmitType_Bounce:
	case eSkillModelEmitType_Bounce_NoRepeat:
		{
			bool bIfCanRepeat = pCfg->eEmitType == eSkillModelEmitType_Bounce? TRUE : FALSE;
			if (rsSSE->sTargetGUID > 0 && NULL != rsSSE->pcTargetGU && FALSE == rsSSE->pcTargetGU->GetExpire() && rsSSE->pcTargetGU->IsDead() == FALSE){
				if (rsSSE->pcTargetGU->GetObjGUID() != rsSSE->sTargetGUID || rsSSE->pcTargetGU->IsDead()){
					rsSSE->bIfEnded = true;
					return eEC_InvalidSkillTarget;
				}
				//CVector3D cTarPos = rsSSE->pcTargetGU->GetGOActionStateInfo().cPos;
				CVector3D cTarPos = rsSSE->pcTargetGU->GetOnHitPos();
				CVector3D cSelfPos = rsSSE->cCurPos;
				CVector3D cDir = cTarPos - cSelfPos;
				float fDist = cDir.length() - rsSSE->pcTargetGU->GetObjCollideRadius();
				float fCanMoveDist = GetModelConfig()->n32ProjFlySpeed * (FLOAT)tTickSpan / 1000;
				if (fCanMoveDist >= fDist){//����Ŀ��
					//��鵯������
					if(rsSSE->lHitTargetsArr.GetCurSize() < pCfg->n32FlyPar1)
					{
						//δ������������
						CSSGameUnit* pNextTarget = FindNextBounceTarget(rsSSE,rsSSE->pcTargetGU, bIfCanRepeat);
						if(NULL != pNextTarget){
							SSEmitEntity newSSE;
							newSSE.pcTargetGU = pNextTarget;
							newSSE.sTargetGUID = pNextTarget->GetObjGUID();
							//newSSE.cCurPos = rsSSE->pcTargetGU->GetCurPos();
							newSSE.cCurPos = rsSSE->pcTargetGU->GetEmitPos();
							newSSE.cCurDir = rsSSE->pcTargetGU->GetCurDir();
							newSSE.tLaunchUTCMilsec = tUTCMilsec;
							newSSE.bIfEnded = false;
							newSSE.n32ProjectID = GetBattle()->GetUniqueEffectID();
							newSSE.lHitTargetsArr = rsSSE->lHitTargetsArr;
							newSSE.lHitTargetsArr.AddElement(rsSSE->pcTargetGU->GetObjGUID());
							m_lEmitEntityArr.AddElement(newSSE);
							NotifyNewEmitObjectToGC(rsSSE->pcTargetGU, &newSSE);
						}
					}
					//�����˺�������ģ��
					SSEmitHitTargetInfo temp = {rsSSE->pcTargetGU, rsSSE->pcTargetGU->GetCurPos(), cDir};
					m_lEmitHitTargetArr.AddElement(temp);
					rsSSE->bIfEnded = true;

					return eEC_ConstInvalid;
				}
				cDir.unit();
				rsSSE->cCurPos = cSelfPos + cDir * fCanMoveDist;
			}
			else{
				rsSSE->bIfEnded = true;
			}
		}
		break;
		//��Χ�ڷ��м��ܣ����ϵĸ��ݼ���жϷ�ΧЧ������Χ�ڵ�������ЧĿ�����Ϊ���С���Χ���м���Ĭ���Ǵ�͸�ġ�
	case eSkillModelEmitType_Area:
		{
			//������ʱ��
			if(rsSSE->tLaunchUTCMilsec + pCfg->n32ProjectileLifeTime < tUTCMilsec){
				rsSSE->bIfEnded = true;
				return eEC_ConstInvalid;
			}
			CVector3D cSelfPos = rsSSE->cCurPos;
			CVector3D cDir = rsSSE->cCurDir;
			float fCanMoveDist = GetModelConfig()->n32ProjFlySpeed * (FLOAT)tTickSpan / 1000;
			if(rsSSE->tLastEffectTime <= tUTCMilsec){
				rsSSE->tLastEffectTime += pCfg->n32FlyPar1;
				vector<CSSGameUnit*> targetList;
				CheckSimpleSkillEntityImpact(rsSSE,fCanMoveDist,&targetList,TRUE,TRUE);

				for(vector<CSSGameUnit*>::iterator iter = targetList.begin();iter != targetList.end(); iter++){
					if(CheckHitTargetType(*iter)){
						SSEmitHitTargetInfo temp = {*iter, (*iter)->GetCurPos(), cDir};
						m_lEmitHitTargetArr.AddElement(temp);
					}
				}
			}

			cDir.unit();
			rsSSE->cCurPos = cSelfPos + cDir * fCanMoveDist;
		}
		break;
	default:
		break;
	//if a skill entity to a specified target.
	}
	return eNormal;
}

const SSkillModelEmitCfg* CSSSkillEffect_Fly::GetModelConfig(){
	return (const SSkillModelEmitCfg*)m_pCfg;
}

//�����е��ߺ���Щ���巢������ײ
INT32	CSSSkillEffect_Fly::CheckSimpleSkillEntityImpact(SSEmitEntity* rsSSE, float fDist, vector<CSSGameUnit*>* pTargetList, bool bIsPenetrate, bool bIfCanRepeat){
	const SSkillModelEmitCfg* pCfg = GetModelConfig();
	//��ȡ�ܱ߷�Χ�ڵ����ж���
	vector<CSSGameUnit*> vecAreaObj; 
	GetBattle()->FindAroundGU(rsSSE->cCurPos,(FLOAT)pCfg->n32ProjectileCollideRadius + 500,vecAreaObj);

	for (UINT32 i = 0; i < vecAreaObj.size(); i++){
		if(m_pcMasterGO == vecAreaObj[i]){
			continue;
		}
		CSSGameUnit *pcTempGU = vecAreaObj[i];
		if (CheckHitTargetType(pcTempGU) && CheckHitTargetCamp(pcTempGU) &&
			CFunction::IfImpact(rsSSE->cCurPos, (FLOAT)pCfg->n32ProjectileCollideRadius, pcTempGU->GetGOActionStateInfo().cPos, (FLOAT)pcTempGU->GetObjCollideRadius())){
				if(pcTempGU->GetExpire() || pcTempGU->IsDead()) continue;
			bool bCaculateEffect = true;
			//��Ҫ����Ƿ��ظ�����������ظ��������������б��еĶ��󲻿ɼ���
			if (FALSE == bIfCanRepeat){
				bool bExist = rsSSE->lHitTargetsArr.IsHvElement(pcTempGU->GetObjGUID());

				if (FALSE == bExist){
					rsSSE->lHitTargetsArr.AddElement(pcTempGU->GetObjGUID());
				}
				else{
					bCaculateEffect = false;
				}
			}
			if (bCaculateEffect){
				pTargetList->push_back(pcTempGU);
				if(FALSE == bIsPenetrate){
					break;
				}
			}
		}
	}

	return eNormal;
}

//Ѱ����һ����������
CSSGameUnit* CSSSkillEffect_Fly::FindNextBounceTarget(SSEmitEntity* pSSE, CSSGameUnit* exceptGU, bool bIfCanRepeat){
	const SSkillModelEmitCfg* pCfg = GetModelConfig();
	vector<CSSGameUnit*> vecAreaObj; 
	GetBattle()->FindAroundGU(pSSE->cCurPos,(FLOAT)pCfg->n32FlyPar2 + 500,vecAreaObj);

	for(vector<CSSGameUnit*>::iterator iter = vecAreaObj.begin(); iter != vecAreaObj.end();){
		CSSGameUnit* pcTempGU = *iter;
		float tempDist = (pcTempGU->GetCurPos() - pSSE->cCurPos).length();
		//������Ȼ����ѡ�����Ķ���
		if (pcTempGU == exceptGU || pcTempGU->GetExpire() || pcTempGU->IsDead() || !CheckHitTargetType(pcTempGU) || !CheckHitTargetCamp(pcTempGU) || tempDist > pCfg->n32FlyPar2){
			iter = vecAreaObj.erase(iter);
		}
		else{
			//��������ظ������ѵ������Ķ���Ҳ����
			if(FALSE == bIfCanRepeat){
				bool bIsRepeat = pSSE->lHitTargetsArr.IsHvElement(pcTempGU->GetObjGUID());
				if(bIsRepeat){
					iter = vecAreaObj.erase(iter);
				}
				else{
					++iter;
				}
			}
			else{
				++iter;
			}
		}
	}
	if(FALSE == vecAreaObj.empty()){
		return vecAreaObj[rand() % vecAreaObj.size()];
	}
	return NULL;
}

//���ʹ����µķ��е�����Ϣ���ͻ���
INT32 CSSSkillEffect_Fly::NotifyNewEmitObjectToGC(CSSGameUnit* pStartGU, SSEmitEntity* pSSE){
	if(m_pcMasterGO == NULL){
		return eEC_EffectEnd;
	}

	GSToGC::EmitSkill sEmitSkill;
	sEmitSkill.set_guid(pStartGU->GetObjGUID());
	sEmitSkill.set_effectid(m_pCfg->un32SkillModelID);
	sEmitSkill.set_uniqueid(pSSE->n32ProjectID);
	GSToGC::Dir* dir = new GSToGC::Dir;
	CSSBattle::SetDir(pSSE->cCurDir, *dir);
	sEmitSkill.set_allocated_dir(dir);
	//���е������û��Ŀ��(�Ǹ���)���򲻷�
	if(pSSE->pcTargetGU != NULL){
		sEmitSkill.set_targuid(pSSE->pcTargetGU->GetObjGUID());
		GSToGC::Pos* tarPos = new GSToGC::Pos;
		CSSBattle::SetPos(pSSE->pcTargetGU->GetGOActionStateInfo().cPos, *tarPos);
		sEmitSkill.set_allocated_tarpos(tarPos);
	}
	if (m_pSkillRuntimeData){
		sEmitSkill.set_ifabsorbskill(m_pSkillRuntimeData->cpsCfg->bIsConsumeSkill);
	}

	GetBattle()->SendMsgToAllWatcher(sEmitSkill, sEmitSkill.msgid(), m_pcMasterGO);

	return eNormal;
}
//�������ٷ��е�����Ϣ���ͻ���
INT32 CSSSkillEffect_Fly::NotifyDestoryEmitObjectToGC(SSEmitEntity* pSSE){
	if(m_pcMasterGO == NULL){
		return eEC_EffectEnd;
	}
	
	GSToGC::DestroyEmitEffect sMsg;
	sMsg.set_uniqueid(pSSE->n32ProjectID);
	GetBattle()->SendMsgToAllWatcher(sMsg, sMsg.msgid(), m_pcMasterGO);

	return eNormal;
}
//���ͷ��е���ת����Ϣ���ͻ���(ֻ�л�������Ҫ�õ�)
INT32 CSSSkillEffect_Fly::NotifyTurnEmitObjectToGC(SSEmitEntity* pSSE){
	if(m_pcMasterGO == NULL){
		return eEC_EffectEnd;
	}
	
	GSToGC::NotifySkillModelEmitTurn sMsg;
	sMsg.set_progectid(pSSE->n32ProjectID);
	sMsg.set_guid(m_pcMasterGO->GetObjGUID());
	GetBattle()->SendMsgToAllWatcher(sMsg, sMsg.msgid(), m_pcMasterGO);
	return eNormal;
}

INT32 CSSSkillEffect_Fly::End(){
	return eNormal;
}

bool CSSSkillEffect_Fly::IfParaInvalid(){
	return TRUE == IsForceStop();
}

}