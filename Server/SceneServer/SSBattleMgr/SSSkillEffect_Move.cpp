
#include "SSSkillEffect_Move.h"
#include "SSGameUnit.h"
#include "SSBattle.h"
#include "SSEffectMgr.h"
#include "SSHero.h"

#include "SSBattleMgr.h"
 


namespace SceneServer{



CSSSkillEffect_Move::CSSSkillEffect_Move(): m_pMoveCfg(NULL)
	,m_pMoveTarget(NULL)
	,m_bIfEnd(FALSE)
	,m_bIfStartForceMove(FALSE)
	,m_moveDir(0,0,0)
	,m_lastMovePos(0,0,0)
	,m_moveTargetPos(0,0,0)
	,m_tBeginMilsec(0)
	,m_tLastMoveMilsec(0)
	,m_tEndMilsec(0)

{
	m_SkillEffectType = eSkillEffectType_Move;
}

CSSSkillEffect_Move::~CSSSkillEffect_Move(){

}

INT32 CSSSkillEffect_Move::Update(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan){
	if(m_bIfEnd){
		m_pMoveTarget->EndAction_Controled(TRUE,m_pcMasterGO);
		return eEC_EffectEnd;
	}

	//���Ŀ��״̬
	if(m_pMoveTarget == NULL || eOAS_Controlled != m_pMoveTarget->GetGOActionStateInfo().eOAS){
		m_bIfEnd = FALSE;
		return eEC_EffectEnd;
	}
	
	//��һ���������ƶ�
	//if(tUTCMilsec - m_tBeginMilsec < 50){
	//	return eNormal;
	//}
	
	//��ʼһ����ͨ�����ƶ�
	switch(m_pMoveCfg->eMoveType){
		//����λ�ƣ�ָ��һ��ָ����Ŀ�������ƶ�
	case ESkillEffectMoveType_Absolute:
		{
			float canMoveDist = m_pMoveCfg->n32Speed * (float)tTickSpan / 1000;
			CVector3D moveVec = m_moveTargetPos - m_pMoveTarget->GetCurPos();
			float dist = moveVec.length();
			if(dist <= canMoveDist/2 || moveVec.m_fX*m_moveDir.m_fX<0 || moveVec.m_fZ*m_moveDir.m_fZ<0){
				//�����̶����ƶ���ʱ��ǿ���ƶ���Ŀ���(����bug����һ��λ�Ʊ���һ��λ�ƴ�ϵ�ʱ�򣬱�������ͷ�Ů����Ҫ����)
				m_pMoveTarget->SetGOActionState_Pos(m_moveTargetPos);

				m_bIfEnd = TRUE;
				StopMove();
				return eEC_EffectEnd;
			}

		}
		break;
		//���շ����ƶ�����ʱ�䵽�ˣ�����λ��ϵͳ֪ͨ���Ż�ֹͣλ��
	case ESkillEffectMoveType_Opposite:
		{
			//����Ƿ��ƶ�ʱ�䵽��
			if(tUTCMilsec > m_tEndMilsec){
				m_bIfEnd = TRUE;
				StopMove();
				return eEC_EffectEnd;
			}
		}
		break;
	}
	

	return eNormal;
}

INT32	CSSSkillEffect_Move::Begin(){
	m_pMoveCfg = (SSkillModelMoveCfg*)m_pCfg;
	//�����ƶ��Լ���Ҳ�����ƶ�Ŀ��
	m_pMoveTarget = m_pMoveCfg->eMovedTargetType == ESkillEffectMovedTargetType_Self ? m_pcMasterGO : m_pcTarGU;
	if(m_pMoveTarget == NULL || m_pMoveTarget->IsDead()){
		return eEC_EffectEnd;
	}

	if(FALSE == CheckHitTargetType(m_pMoveTarget)){
		return eEC_EffectEnd;
	}

	m_lastMovePos.Zero();
	m_moveDir.Zero();
	m_moveTargetPos.Zero();
	m_tBeginMilsec = 0;
	m_tLastMoveMilsec = 0;
	m_tEndMilsec = 0;
	m_bIfEnd = FALSE;

	switch(m_pMoveCfg->eMoveType){
		//�س�Ч����ֱ��˲�Ƶ�������
	case ESkillEffectMoveType_HOME:
		{
			CVector3D pTargetPos =  m_pMoveTarget->TryCastToHero()->GetHeroBornPos();
			CVector3D pStartPos = m_pMoveTarget->GetCurPos();
			CVector3D cDir = pTargetPos - pStartPos;
			cDir.m_fY = 0;
			cDir.unit();
			ResetPos(m_pMoveTarget, pTargetPos, cDir, TRUE);
			NotifyTeleportToGC(m_pMoveTarget, pStartPos, m_pMoveTarget->GetCurDir());
			m_bIfEnd = TRUE;
			//��������Ŀ��
			if(m_pMoveTarget->IfHero()){
				m_pMoveTarget->TryCastToHero()->ClearLockedTargetGUID();
			}
		}
		break;
	case ESkillEffectMoveType_Absolute:
		{
			if(m_pcTarGU == NULL){
				return eEC_EffectEnd;
			}

			if(m_pMoveTarget == NULL || FALSE == m_pMoveTarget->IfCanBeTarget()){
				return eEC_EffectEnd;
			}
			//���Գ��Լ��ƶ�(����)��Ҳ���Գ�Ŀ���ƶ�(���)
			if(m_pMoveCfg->eMoveToTargetType == ESkillEffectMoveToTargetType_Self){
				m_moveTargetPos = m_pcMasterGO->GetCurPos();
			}
			else if(m_pMoveCfg->eMoveToTargetType == ESkillEffectMoveToTargetType_Target){
				m_moveTargetPos = m_pcTarGU->GetCurPos();
			}
			else if(m_pMoveCfg->eMoveToTargetType == ESkillEffectMoveToTargetType_SkillTarget){
				m_moveTargetPos = m_pSkillRuntimeData->cTargetPos;
			}

			CVector3D cNowPos = m_pMoveTarget->GetCurPos();
			CVector3D cNowDist = m_moveTargetPos - cNowPos;
			if(m_pMoveCfg->n32Distance > 0 && cNowDist.sqr() > m_pMoveCfg->n32Distance * m_pMoveCfg->n32Distance){
				//�������λ�Ƽ��ܣ�����
				return eEC_EffectEnd;
			}

			m_moveDir = cNowDist;
			m_moveDir.m_fY = 0;
			m_moveDir.unit();
			if(m_pMoveCfg->n32Speed <= 0){//�����˲�ƣ�ֱ��ǿ���ƶ�λ��
				CVector3D pStartPos = m_pMoveTarget->GetCurPos();
				ResetPos(m_pMoveTarget, m_moveTargetPos, m_moveDir, FALSE, TRUE, FALSE);
				NotifyTeleportToGC(m_pMoveTarget, pStartPos, m_moveDir);
				m_bIfEnd = TRUE;
			}
			else{
				//���򣬽��뿪ʼ�ƶ�״̬
				StartMove(cNowPos);
			}
		}
		break;
		//����ƶ�
	case ESkillEffectMoveType_Opposite:
		{
			if(m_pMoveTarget == NULL || FALSE == m_pMoveTarget->IfCanBeTarget()){
				return eEC_EffectEnd;
			}

			CVector3D cNowPos = m_pMoveTarget->GetCurPos();
			if(cNowPos.IsZero()){
				return eEC_EffectEnd;
			}

			//λ�Ƶķ��򣬿��Ը�����һ��Ч�����еķ���Ŀ��������򣬻��߼���ʹ���ߵ�������
			if(m_pMoveCfg->eMoveToTargetType == ESkillEffectMoveToTargetType_Hit_Anger){
				m_moveDir = m_cDir;
			}
			else if(m_pMoveCfg->eMoveToTargetType == ESkillEffectMoveToTargetType_Target_Anger){
				m_moveDir = m_pMoveTarget->GetCurDir();
			}
			else if(m_pMoveCfg->eMoveToTargetType == ESkillEffectMoveToTargetType_Master_Anger){
				m_moveDir = m_pcMasterGO->GetCurDir();
			}
			//Ȼ����תһ��ָ���Ƕ�
			m_moveDir.RotateXZBy(m_pMoveCfg->n32Angle);
			
			CVector3D targetPos = cNowPos + m_moveDir * m_pMoveCfg->n32Distance;
			if(m_pMoveCfg->n32Speed <= 0){//˲��
				CVector3D pStartPos = m_pMoveTarget->GetCurPos();
				ResetPos(m_pMoveTarget, targetPos, m_moveDir,FALSE, TRUE, FALSE);
				NotifyTeleportToGC(m_pMoveTarget, pStartPos, m_moveDir);
				m_bIfEnd = TRUE;
			}
			else{//�г���ʱ����ƶ�
				StartMove(cNowPos);
			}
		}
		break;
	}
	//���λ�ƽ����ˣ�������һ��Ч��
	if(m_bIfEnd){
		GetBattle()->GetEffectMgr()->AddEffectsFromCfg((SSNextSkillEffectCfg*)m_pCfg->asSkillModelList
			, m_pcMasterGO, m_pcTarGU, m_pcMasterGO->GetCurPos(), m_pcMasterGO->GetCurDir(), m_pSkillRuntimeData, GetUTCMiliSecond());
		return eEC_EffectEnd;
	}
	else{
		return eNormal;
	}
}

INT32 CSSSkillEffect_Move::End(){
	if (NULL != m_pMoveTarget){
		m_pMoveTarget->RemoveMoveEffect(GetUniqueID());
		StopMove();
		if(m_bIfEnd){
			NotifyStopMoveToGC(m_pMoveTarget, m_pMoveTarget->GetCurPos());
		}
	}

	return eNormal;
}
//��ʼ�ƶ����������������ã�Ȼ�����λ��ϵͳ�������͸��ͻ���ǿ��λ�Ƶ���Ϣ
void  CSSSkillEffect_Move::StartMove(CVector3D& cStartPos){
	m_bIfStartForceMove = TRUE;
	m_lastMovePos = cStartPos;
	m_pMoveTarget->SetMoveEffect(GetUniqueID(), m_pMoveTarget == m_pcMasterGO.get());
	m_tBeginMilsec = GetUTCMiliSecond();
	m_tEndMilsec = m_tBeginMilsec + (INT32)((float)m_pMoveCfg->n32Distance / m_pMoveCfg->n32Speed * 1000);
	m_tLastMoveMilsec = m_tBeginMilsec;
	m_pMoveTarget->BeginAction_Controled(FALSE, m_pMoveTarget);
	m_pMoveTarget->SetMoveHolder(this);
	SSkillModelMoveCfg* pCfg = (SSkillModelMoveCfg*)m_pCfg;
	GetBattle()->AskStartMoveForced(m_pMoveTarget,m_moveDir,(FLOAT)pCfg->n32Speed / 1000.0f, pCfg->eMoveType == ESkillEffectMoveType_Opposite);
	NotifyStartMoveToGC(m_pMoveTarget, cStartPos, m_moveDir, m_pMoveCfg->n32Speed);
}

void  CSSSkillEffect_Move::StopMove(){
	if(m_bIfStartForceMove){
		m_bIfStartForceMove = FALSE;
		//ResetPos(m_pMoveTarget, cStopPos, m_moveDir, TRUE);
		m_pMoveTarget->ClearMoveHolder();
		GetBattle()->AskStopMoveObjectForceMove(m_pMoveTarget);
		if(m_bIfEnd){
			NotifyStopMoveToGC(m_pMoveTarget, m_pMoveTarget->GetCurPos());
		}
		m_pMoveTarget->EndAction_Controled(TRUE,m_pcMasterGO);
		//����������սᣬ���ú���ģ��
		if(m_bIfEnd){
			GetBattle()->GetEffectMgr()->AddEffectsFromCfg((SSNextSkillEffectCfg*)m_pCfg->asSkillModelList
				, m_pcMasterGO, m_pcTarGU, m_pMoveTarget->GetCurPos(), m_pMoveTarget->GetCurDir(), m_pSkillRuntimeData, GetUTCMiliSecond());
		}
		m_bIfEnd = FALSE;
	}
}

void  CSSSkillEffect_Move::OnStopMove(){
	End();
}

//���ö���ָ��Ŀ��
bool  CSSSkillEffect_Move::ResetPos(CSSGameUnit* pTarget, CVector3D& pos, CVector3D& dir, bool bIfEnd, bool bIfCheckCollide, bool bIFFindForward){
	if(pTarget == NULL){
		return FALSE;
	}
	if(bIfEnd){
		GetBattle()->ResetPos(pTarget, pos,TRUE);
		return true;
	}

	bool rst = TRUE;

	//�����Ҫ�����ײ���������ײϵͳ��Ѱ��һ�����������Ŀհ׵�
	if(bIfCheckCollide){
		CVector3D pTargetPos;
		if(bIFFindForward){
			//��ǰ����ҵ�һ���հ׵�
			rst = eNormal == GetBattle()->GetLastFreePosByPath(pTarget, pTarget->GetCurPos(), pos, pTargetPos);
		}
		else{
			//�Ӻ���ǰ�ߵ�һ���հ׵�
			rst = eNormal == GetBattle()->GetFirstFreePosByPath(pTarget, pos, pTarget->GetCurPos(), pTargetPos);
		}
		if(rst && pTarget->GetCurPos() != pTargetPos){
			GetBattle()->ResetPos(pTarget,pTargetPos,TRUE);
		}
	}
	else{
		pTarget->SetGOActionState_Pos(pos);
	}
	m_pMoveTarget->OnTeleport();
	return rst;
}

INT32 CSSSkillEffect_Move::NotifyTeleportToGC(CSSGameUnit* pTarget, CVector3D& pStartPos, CVector3D& cDir){
	if(m_pcMasterGO == NULL){
		return eEC_EffectEnd;
	}

	GSToGC::NotifySkillModelStartForceMoveTeleport sMove;
	sMove.set_guid(pTarget->GetObjGUID());
	sMove.set_effectid(m_pCfg->un32SkillModelID);

	GSToGC::Pos* pos = new GSToGC::Pos;
	CSSBattle::SetPos(pStartPos, *pos);
	sMove.set_allocated_beginpos(pos);

	GSToGC::Pos* tarpos = new GSToGC::Pos;
	CSSBattle::SetPos(pTarget->GetCurPos(), *tarpos);
	sMove.set_allocated_tarpos(tarpos);

	GSToGC::Dir* dir = new GSToGC::Dir;
	CSSBattle::SetDir(cDir, *dir);
	sMove.set_allocated_begindir(dir);
	GetBattle()->SendMsgToAllWatcher(sMove, sMove.msgid(), m_pMoveTarget);
	return eNormal;
}

INT32 CSSSkillEffect_Move::NotifyStartMoveToGC(CSSGameUnit* pStartGU, CVector3D& cPos, CVector3D& cDir, INT32 n32Speed){
	if(m_pcMasterGO == NULL){
		return eEC_EffectEnd;
	}

	GSToGC::NotifySkillModelStartForceMove sMove;
	sMove.set_guid(pStartGU->GetObjGUID());
	sMove.set_effectid(m_pCfg->un32SkillModelID);

	GSToGC::Pos* pos = new GSToGC::Pos;
	CSSBattle::SetPos(cPos, *pos);
	sMove.set_allocated_pod(pos);

	GSToGC::Dir* dir = new GSToGC::Dir;
	CSSBattle::SetDir(cDir, *dir);
	sMove.set_allocated_dir(dir);
	sMove.set_speed(n32Speed);
	GetBattle()->SendMsgToAllWatcher(sMove, sMove.msgid(), m_pMoveTarget);
	return eNormal;
}

INT32 CSSSkillEffect_Move::NotifyStopMoveToGC(CSSGameUnit* pStartGU, CVector3D& cPos){
	if(m_pcMasterGO == NULL){
		return eEC_EffectEnd;
	}

	GSToGC::NotifySkillModelStartForceMoveStop sMoveStop;
	sMoveStop.set_guid(pStartGU->GetObjGUID());
	sMoveStop.set_effectid(m_pCfg->un32SkillModelID);

	GSToGC::Pos* pos = new GSToGC::Pos;
	CSSBattle::SetPos(cPos, *pos);
	sMoveStop.set_allocated_pos(pos);
	GetBattle()->SendMsgToAllWatcher(sMoveStop, sMoveStop.msgid(), m_pMoveTarget);
	return eNormal;
}

bool CSSSkillEffect_Move::IfParaInvalid(){
	if (CSSSkillEffect::IfParaInvalid()){
		return TRUE;
	}

	if (FALSE == m_bIfEnd){
		return NULL == m_pMoveTarget;
	}

	return FALSE;
}


}