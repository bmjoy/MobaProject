#include "SSSkill.h"
#include "SSGameUnit.h"
#include "SSHero.h"
#include "SSNPC.h"
#include "SSBattle.h"
#include "SSEffectMgr.h"

namespace SceneServer{

INT32	CSSSkill::CheckStatus(){
	//��鼼��������״̬
	if (eOAS_PassiveState < pcMasterGU->GetGOActionStateInfo().eOAS){
		return eEC_AbsentOrderPriority;
	}
	if (pcMasterGU->GetFPData(eEffectCate_Dizziness) > 0){
		return eEC_UseSkillFailForDizziness;
	}
	if (pcMasterGU->GetFPData(eEffectCate_Silence) > 0 && FALSE == cpsCfg->bIfNomalAttack){
		return eEC_UseSkillFailForSilenced;
	}
	if (pcMasterGU->GetFPData(eEffectCate_Disarm) > 0 && TRUE == cpsCfg->bIfNomalAttack){
		return eEC_UseSkillFailForDisarmed;
	}

	return eNormal;
}

INT32	CSSSkill::CheckConsume(){
	if (pcMasterGU->IfHero()){
		CSSHero *pcHero = pcMasterGU->TryCastToHero();
		if (pcHero->GetCP(eCPCP_Personnal) < cpsCfg->n32UseCP){
			return eEC_UseSkillFailForLackCP;
		}
		if (pcHero->GetCurMP() < cpsCfg->n32UseMP){
			return eEC_UseSkillFailForLackMP;
		}
		if (pcHero->GetCurHP() < cpsCfg->n32UseHP){
			return eEC_UseSkillFailForLackHP;
		}
	}
	return eNormal;
}

void	CSSSkill::CostConsume(){
	if (pcMasterGU->IfHero()){
		CSSHero *pcHero = pcMasterGU->TryCastToHero();

		if(cpsCfg->n32UseCP > 0) pcHero->ChangeCP(eCPCP_Personnal, -cpsCfg->n32UseCP, false);
		if(cpsCfg->n32UseHP > 0) pcHero->ChangeCurHP(pcMasterGU, GSToGC::SkillConsume, -cpsCfg->n32UseHP);
		if(cpsCfg->n32UseMP > 0) pcHero->ChangeCurMP(pcMasterGU, GSToGC::SkillConsume, -cpsCfg->n32UseMP);
	}
}

INT32	CSSSkill::CheckAndSetTarget(){
	if (cpsCfg->eReleaseWay == ESReleaseWay_NO_TARGET){
		pcTarGU = NULL;
	}
	else{
		if(pcMasterGU->IfHero()){
			CSSHero *pcHero = pcMasterGU->TryCastToHero();
			pcTarGU = pcHero->GetCurBattle()->GetGameUnitByGUID(pcHero->GetLockedTargetGUID());
			if (NULL == pcTarGU && cpsCfg->eReleaseWay != ESReleaseWay_AUTO){
				return eEC_UseSkillFailForNULLTarget;
			}
		}
	}

	if(pcMasterGU->IfHero()){
		CSSHero *pcHero = pcMasterGU->TryCastToHero();
		UINT32 un32SkillID = cpsCfg->un32SkillID;
		if(NULL != pcHero && pcHero->IsGasSkill(un32SkillID)){
			INT32 n32CheckRet = pcHero->CheckUseGasSkill(un32SkillID);
			if(eNormal != n32CheckRet){
				return n32CheckRet;
			}
		}
	}
	return eNormal;
}

INT32	CSSSkill::CheckTargetTypeCamp(){
	if(pcTarGU == NULL){
		return eNormal;
	}

	if(pcTarGU->IsDead()){
		return eEC_UseSkillTargetIsDead;
	}

	switch(cpsCfg->eSkillTargetCate)
	{
	case eSTC_Self://�Լ�
		break;
	case eSTC_AllObject://����Ŀ��
		break;
	case eSTC_TeamMember://����
		{
			if(pcMasterGU->GetObjGUID() == pcTarGU->GetObjGUID()){
				return eEC_UseSkillTargetWrongCamp;
			}
			if(pcTarGU->GetCampID() > 1 && pcMasterGU->GetCampID() % 2 != pcTarGU->GetCampID() % 2){
				return eEC_UseSkillTargetWrongCamp;
			}
		}
		break;
	case eSTC_Enemy://����
		if(CFunction::IfEnemy(pcMasterGU->GetCampID(), pcTarGU->GetCampID()) == false){
			return eEC_UseSkillTargetWrongCamp;
		}
		break;
	case eSTC_AllFriendUnit://�����Ѿ�Ŀ��
		if((pcTarGU->GetCampID() > 1 && pcMasterGU->GetCampID() % 2 != pcTarGU->GetCampID() % 2) || pcMasterGU->GetCampID() == eGOCamp_AllEnemy){
				return eEC_UseSkillTargetWrongCamp;
		}
		break;
	}

	if(pcTarGU->IfHero()){
		if(cpsCfg->bIfAffectHero == false){
			return eEC_UseSkillTargetWrongType;
		}
	}
	else if(pcTarGU->IfNPC()){
		CSSNPC* pNpc = pcTarGU->TryCastToNPC();

		if(pNpc->GetNPCCfg()->eNPCCate == eNPCCate_WideAnimal || pNpc->GetNPCCfg()->eNPCCate == eNPCCate_Solider){
			if(cpsCfg->bIfAffectMonster == false){
				return eEC_UseSkillTargetWrongType;
			}
		}
		if(pNpc->GetNPCCfg()->eNPCCate == eNPCCate_Building){
			if(cpsCfg->bIfAffectBuilding == false){
				return eEC_UseSkillFailForBuildingNullity;
			}
		}
	}
	return eNormal;
}

void	CSSSkill::SetSkillDir(){
	cDir = pcMasterGU->GetCurDir();
	switch (cpsCfg->eReleaseWay){
	case ESReleaseWay_NEED_TARGET:
	case ESReleaseWay_AUTO:
		if(NULL != pcTarGU && FALSE == pcMasterGU->IfNPC_Building()){
			cDir = pcTarGU->GetCurPos() - pcMasterGU->GetCurPos();
			cDir.m_fY = 0;
			cDir.unit();
			pcMasterGU->SetGOActionState_Dir(cDir);
		}
		break;
	}
}

INT32	CSSSkill::IfSkillUsableWithNowTarget(){
	INT32 rst = CheckStatus();
	if(eNormal != rst) return rst;

	//�������
	rst = CheckConsume();
	if(eNormal != rst){
		return rst;
	}

	rst = CheckAndSetTarget();
	if(eNormal != rst) return rst;

	rst = CheckTargetTypeCamp();
	if(eNormal != rst) return rst;

	if(pcTarGU != NULL && (pcTarGU->IsDead() || pcTarGU->GetGOActionStateInfo().eOAS == eOAS_Reliving)){
		return eEC_UseSkillFailForNULLTarget;
	}

	if (FALSE == pcMasterGU->IfInReleaseSkillRange(pcTarGU, cpsCfg)){
		return eEC_AbsentSkillDistance;
	}

	return rst;
}

INT32 CSSSkill::DoCoolDown(){
	TIME_MILSEC curTime = GetUTCMiliSecond();
	tStateMilsec = curTime;

	//CD��Ҫ����ͨ�����ͼ��ܹ����ֿ�����
	if(cpsCfg->bIfNomalAttack){
		INT32 attackSpeed = pcMasterGU->GetFPData(eEffectCate_AttackSpeed);
		INT32 n32ReleaseMilsec = cpsCfg->n32ReleaseMilsec * attackSpeed / 1000;
		INT32 n32StandCoolDownMilsec = (cpsCfg->n32CoolDown + cpsCfg->n32ReleaseMilsec ) * attackSpeed / 1000;
		//���������һ���ͷ���ͨ�������ܼ��ʱ��ȽϾã�����ȴʱ��ֱ�Ӵ�ǰҡ������ʱ�俪ʼ�㡣����ֱ������һ����ȴʱ��Ļ����ϼ���������������
		if(tCooldownMilsec + n32ReleaseMilsec + 150 > tStateMilsec){
			tCooldownMilsec += n32StandCoolDownMilsec;
		}
		else{
			tCooldownMilsec = tBeginMilsec + n32StandCoolDownMilsec;
		}
	}
	//�������ͨ���ܣ�ֱ�ӴӼ��ܷų�����ʱ�����CD����
	else{
		tCooldownMilsec = tStateMilsec + ( cpsCfg->n32CoolDown * (1.0f - pcMasterGU->GetFPData(eEffectCate_CooldownReduce) / 1000.0f) );
	}

	CSSHero* pHero = pcMasterGU->TryCastToHero();
	if (pHero){
		pHero->SyncSkillStateToGC(cpsCfg->un32SkillID);
	}

	return eNormal;
}

INT32	CSSSkill::IfInCD(){
	//��鼼��״̬
	if(GetUTCMiliSecond() < tCooldownMilsec){
		return eEC_UseSkillFailForSkillCoolDown;
	}
	/*
	if (eSkillState_Free != eSkillState){
		TryFree();
	}
	if (eSkillState_Free != eSkillState){
		if (eSkillState_End == eSkillState){
			return eEC_UseSkillFailForSkillCoolDown;
		}
		return eEC_InvalidSkillState;
	}
	*/
	return eNormal;
}

INT32	CSSSkill::IfSkillUsable(){
	INT32 rst = CheckStatus();
	if(eNormal != rst) return rst;

	//�������
	rst = CheckConsume();
	if(eNormal != rst){
		return rst;
	}

	//���CD
	rst = IfInCD();
	return rst;
}

void CSSSkill::MakeSkillEffect(TIME_MILSEC	tUTCMilsec){
	CostConsume();
	CSSBattle *pcCurBattle = pcMasterGU->GetCurBattle();

	CVector3D cPos = pcMasterGU->GetCurPos();
	if(NULL != pcTarGU) {
		cPos = pcTarGU->GetCurPos();
	}

	//������������Ŀ��
	if(cpsCfg->eSkillTargetCate == eSTC_Self){
		pcTarGU = pcMasterGU;
	}

	//�����չ�ǰ�ı�������
	if(TRUE == cpsCfg->bIfNomalAttack)
	{
		pcMasterGU->OnPassitiveSkillCalled(EPassiveSkillTriggerType_Attack, pcTarGU);
	}
	//����ʹ�ü���ǰ�ı�������
	if(FALSE == cpsCfg->bIfNomalAttack)
	{
		pcMasterGU->OnPassitiveSkillCalled(EPassiveSkillTriggerType_UseSkill, pcTarGU);
	}

	pcCurBattle->GetEffectMgr()->AddEffectsFromCfg((SSNextSkillEffectCfg*)cpsCfg->asSkillModelList, pcMasterGU.get(), pcTarGU.get(), cPos, pcMasterGU->GetCurDir(), this, tUTCMilsec);
}

void CSSSkill::CheckAndDoInstantSkill(){
	if(IfImpactSkill()){
		cDir = pcMasterGU->GetCurDir();
		MakeSkillEffect(tBeginMilsec);
		if(cpsCfg->n32SkillLastTime <= 0){
			End();
		}
		else{
			eSkillState = eSkillState_Using;
			tStateMilsec = GetUTCMiliSecond();
		}
	}
}

INT32	CSSSkill::Start(){
	INT32 rst = IfSkillUsable();
	if(eNormal != rst) return rst;

	eSkillState = eSkillState_Free;
	tBeginMilsec = GetUTCMiliSecond();
	ifRunning = TRUE;
	if(pcTarGU != NULL)
		cTargetPos = pcTarGU->GetCurPos();

	CheckAndDoInstantSkill();

	return eNormal;
}

bool	CSSSkill::TryCancle(){
	bool ifCanCancle = FALSE;
	//������ǰҡ������ǰ��ʱ�򣬿���ȡ��
	if(eSkillState_Releasing >= eSkillState){
		ifCanCancle = TRUE;
	}
	//������״̬ʱ����Ҫ����ѯ��ģ��ʱ�����ȡ��
	else if(eSkillState_Using == eSkillState){
		bool ifCanStopUsing = TRUE;
		for (INT32 i = 0; i < c_n32UsingEffectsNum; ++i){
			UINT32 un32EfffectUniqueID = un32UsingEffectsArr[i];
			if (0 != un32EfffectUniqueID){
				CSSSkillEffect* pEffect = pcMasterGU->GetCurBattle()->GetEffectMgr()->GetEffect(un32EfffectUniqueID);
				if (NULL != pEffect){
					if(FALSE == pEffect->IsCanStopUsing()){
						ifCanStopUsing = FALSE;
						break;
					}
				}
			}
		}
		if(ifCanStopUsing){
			ifCanCancle = TRUE;
		}
	}
	//����ҡ�׶ε�ʱ�򣬿���ȡ��
	else if(eSkillState_Lasting == eSkillState){
		ifCanCancle = TRUE;
	}
	//�������ȡ����ȡ������ʩ��
	if(ifCanCancle){
		//ȡ������ʹ���е�ģ��
		if(eSkillState_Using == eSkillState){
			for (INT32 i = 0; i < c_n32UsingEffectsNum; ++i){
				UINT32 un32EfffectUniqueID = un32UsingEffectsArr[i];
				if (0 != un32EfffectUniqueID){
					CSSSkillEffect* pEffect = pcMasterGU->GetCurBattle()->GetEffectMgr()->GetEffect(un32EfffectUniqueID);
					if (NULL != pEffect){
						pEffect->ForceStop();
					}
				}
			}
			ClearUsingEffects();
		}
		End();
		return TRUE;
	}else{
		return FALSE;
	}
}

bool	CSSSkill::IfMasterMoveAble(){
	//������������׶Σ���ô�����ƶ�
	if(eSkillState_Using != eSkillState){
		return TRUE;
	}
	else if(eSkillState_Using == eSkillState){
		for (INT32 i = 0; i < c_n32UsingEffectsNum; ++i){
			UINT32 un32EfffectUniqueID = un32UsingEffectsArr[i];
			if (0 == un32EfffectUniqueID) continue;
			CSSSkillEffect* pEffect = pcMasterGU->GetCurBattle()->GetEffectMgr()->GetEffect(un32EfffectUniqueID);
			if (NULL != pEffect){
				if(FALSE == pEffect->IfCanMove()){
					return FALSE;
				}
			}
		}
	}
	return TRUE;
}

INT32	CSSSkill::End(){
	ifRunning = FALSE;
	eSkillState = eSkillState_End;
	return eNormal;
}

INT32	CSSSkill::HeartBeat(TIME_MILSEC	tUTCMilsec, TIME_TICK	tTickSpan){
	ESkillState heartBeatStartState = eSkillState;

	INT32 rst = eNormal;

	do{
		rst = CheckStatus();
		if(eNormal != rst) break;

		//�������̫Զ��Ҳ��Ҫȡ������ʩ��
		if(eSkillState_Releasing >= eSkillState && FALSE == pcMasterGU->IfInReleaseSkillRange(pcTarGU, cpsCfg, 1000)){
			rst = eEC_NullPointer;
			break;
		}

		/**************************************
			�ȴ� ״̬
		**************************************/
		if (eSkillState_Free ==  eSkillState){
			eSkillState = eSkillState_Preparing;
			tStateMilsec = tUTCMilsec;
			SetSkillDir();
		}

		/**************************************
			���� ״̬
		**************************************/
		if (eSkillState_Preparing ==  eSkillState){
			//�������ȴ�����ֱ�ӷ���
			TIME_MILSEC tMilsecSpan = tUTCMilsec - tStateMilsec;
			if (tMilsecSpan < cpsCfg->n32PrepareMilsec){
				rst = eNormal;
				break;
			}
			//����Ҫ�ȴ��������ʩ��ǰҡ״̬
			eSkillState = eSkillState_Releasing;
			tStateMilsec = tUTCMilsec;
		}

		/**************************************
			ǰҡ ״̬
		**************************************/
		if (eSkillState_Releasing ==  eSkillState){
			//���ǰҡʱ����δ��������ֱ�ӷ���
			INT32 n32ReleaseMilsec = cpsCfg->n32ReleaseMilsec;
			//��ͨ������ǰҡʱ��Ҫ���㹥�ټӳ�
			if (cpsCfg->bIfNomalAttack){
				if(m_normalAttackReleaseTime == 0){
					m_normalAttackReleaseTime = n32ReleaseMilsec * pcMasterGU->GetFPData(eEffectCate_AttackSpeed) / 1000.0f;
				}
				n32ReleaseMilsec = m_normalAttackReleaseTime;
			}

			INT32 tMilsecSpan = tUTCMilsec - tStateMilsec;
			if (tMilsecSpan < n32ReleaseMilsec){
				rst = eNormal;
				break;
			}
			//ʱ�䵽�ˣ���ʼ���ü���ģ��
		
			//��鲢�۷�
			rst = CheckConsume();
			if(eNormal != rst){
				break;
			}
			MakeSkillEffect(tUTCMilsec);
			//������һ�׶�
			eSkillState = eSkillState_Using;
			tStateMilsec = tUTCMilsec;
			m_normalAttackReleaseTime = 0;
		}

		/**************************************
			���� ״̬
		**************************************/
		if (eSkillState_Using ==  eSkillState){
			bool bIfUsing = FALSE;
			//�������е������еļ���Ч��,�����Ƿ���Ȼ��ռ����
			for (INT32 i = 0; i < c_n32UsingEffectsNum; ++i){
				UINT32 un32EfffectUniqueID = un32UsingEffectsArr[i];
				if (0 != un32EfffectUniqueID){
					CSSSkillEffect* pEffect = pcMasterGU->GetCurBattle()->GetEffectMgr()->GetEffect(un32EfffectUniqueID);
					if (NULL != pEffect){
						if(TRUE == pEffect->IsUsingSkill()){
							bIfUsing = TRUE;
						}
						else{
							un32UsingEffectsArr[i] = 0;
						}
					}
				}
			}
			//�������ʹ��״̬������뼼�ܺ�ҡ�׶�
			if(FALSE == bIfUsing){
				ClearUsingEffects();
				eSkillState = eSkillState_Lasting;
				tStateMilsec = tUTCMilsec;
			}
		}

		/**************************************
			��ҡ ״̬
		**************************************/
		if (eSkillState_Lasting ==  eSkillState){
			//�����ҡ���������ܽ������״̬
			if(tStateMilsec + cpsCfg->n32SkillLastTime > tUTCMilsec){
				rst = eNormal;
				break;
			}
			eSkillState = eSkillState_End;
			tStateMilsec = tUTCMilsec;
		}

		/**************************************
			���� ״̬
		**************************************/
		if (eSkillState_End ==  eSkillState){
			rst = eSkillState_End;
			End();
			break;
		}
	}
	while(FALSE);

	//���״̬�ı��ˣ�����Ҫͬ������������
	if(heartBeatStartState != eSkillState){
		if(eSkillState_Preparing == eSkillState){
			pcMasterGU->BeginAction_PrepareSkill(this, cDir, TRUE);
		}
		else if(eSkillState_Releasing == eSkillState){
			pcMasterGU->BeginAction_ReleaseSkill(this, cDir, TRUE);
		}
		else if(eSkillState_Using == eSkillState){
			pcMasterGU->BeginAction_UsingSkill(this, cDir, TRUE);
		}
		else if(eSkillState_Lasting == eSkillState){
			pcMasterGU->BeginAction_LastingSkill(this, cDir, TRUE);
		}
	}

	return rst;
}

void CSSSkill::ReFreshCD(){
	tCooldownMilsec = GetUTCMiliSecond();
}

void CSSSkill::OnValueChanged(INT32 oldValue,INT32 newValue){
	//tStateMilsec = curTime;
	//�������ͨ���������ٸı��ʱ����Ҫ�ı���ȴʱ��
	if(cpsCfg->bIfNomalAttack){
		TIME_MILSEC curTime = GetUTCMiliSecond();
		INT32 attackSpeed = pcMasterGU->GetFPData(eEffectCate_AttackSpeed);
		INT32 n32ReleaseMilsec = cpsCfg->n32ReleaseMilsec * attackSpeed / 1000;
		INT32 n32StandCoolDownMilsec = (cpsCfg->n32CoolDown + cpsCfg->n32ReleaseMilsec ) * attackSpeed / 1000;

		//�������ǰҡ�׶Σ�����Ҫ�ı�ǰҡ��ʱ��
		if( m_normalAttackReleaseTime > 0){
			//��ǰҡʱ���Ϊ������ʱ��͵ȴ�����ʱ��
			INT32 releaseTimeBefore = curTime - tStateMilsec;
			INT32 releaseTimeAfterOld = m_normalAttackReleaseTime - releaseTimeBefore;
			if(releaseTimeAfterOld > 0){
				INT32 normalAttackReleaseTimeNew = m_normalAttackReleaseTime * newValue / oldValue;
				INT32 releaseTimeAfterNew = releaseTimeAfterOld * newValue / oldValue;
				m_normalAttackReleaseTime += (releaseTimeAfterNew - releaseTimeAfterOld);

				tBeginMilsec += (normalAttackReleaseTimeNew - m_normalAttackReleaseTime);
			}
		}
		else if( tCooldownMilsec > curTime){
			//��ȴ�У���Ҫ�ı���ȴʱ��
			//����ȴʱ���Ϊ����ȴʱ��͵ȴ���ȴʱ��
			INT32 coldTimeAfterOld = tCooldownMilsec - curTime;
			if(coldTimeAfterOld > 0){
				INT32 coldTimeAfterNew = coldTimeAfterOld * newValue / oldValue;
				tCooldownMilsec += (coldTimeAfterNew - coldTimeAfterOld);
			}
		}
	}
}

}