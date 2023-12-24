#include "SSAI.h"
#include "SSGameUnit.h"
#include "SSBattle.h"
#include "SSSkill.h"

namespace SceneServer{

CSSAI::CSSAI(CSSGameUnit* pMaster):m_pcMasterGU(pMaster), m_eAttackState(eAttackState_Pursue)
, m_ifMoving(FALSE)
, m_pcAttackGU(NULL)
, m_pcMoveTarPos(0,0,0)
, m_tLastCheckMoveTarTime(0)
, m_bIfFliter(FALSE)
, m_pAttackSkill(NULL)
, m_tLastTryMoveTime(0)
{
	
}

CSSAI::~CSSAI(){

}

bool	CSSAI::IfPassitiveState(){
	if(NULL == m_pcMasterGU){
		return TRUE;
	}
	if (eOAS_PassiveState < m_pcMasterGU->GetGOActionStateInfo().eOAS){
		return TRUE;
	}
	if( m_pcMasterGU->GetFPData(eEffectCate_Dizziness) > 0){
		return TRUE;
	}
	return FALSE;
}

void	CSSAI::MoveToTar(CVector3D pos, bool ifMoveToBlackPoint, TIME_TICK nowTime){
	if(m_tLastTryMoveTime != 0 && nowTime - m_tLastTryMoveTime < 300){
		return;
	}
	if(m_pcMasterGU->GetCurBattle()->AskStartMoveToTar(m_pcMasterGU,pos,ifMoveToBlackPoint,m_bIfFliter)){
		m_ifMoving = TRUE;
		m_tLastTryMoveTime = 0;
	}
	else{
		m_ifMoving = FALSE;
		m_pcMasterGU->BeginAction_Free(TRUE);
		m_tLastTryMoveTime = GetUTCMiliSecond();
	}
	m_pcMasterGU->SetCurEnemyGUID(0);
}

void	CSSAI::CancleAttack(){
	m_pcMoveTarPos.Clear();
	if (eAttackState_Pursue == m_eAttackState){
		m_pcMasterGU->GetCurBattle()->AskStopMoveObjectTar(m_pcMasterGU);
	}
	//����ȡ�����ܡ���ͨ����������ʵ�ǿ϶�����ȡ���ɹ���,���Բ����жϷ���ֵ
	m_pAttackSkill->TryCancle();
	/*
	else if (eAttackState_UseSkill == m_eAttackState){
		//����ȡ�����ܡ���ͨ����������ʵ�ǿ϶�����ȡ���ɹ���,���Բ����жϷ���ֵ
		m_pAttackSkill->TryCancle();
	}
	*/
}

void	CSSAI::StopAttack(){
	CancleAttack();
	SetAttackGU(NULL);
	m_pcMoveTarPos.Clear();
	m_tLastCheckMoveTarTime = 0;
}

INT32	CSSAI::AttackHeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan){
	INT32 rst = eNormal;
	//��鼼��
	if(NULL == m_pAttackSkill){
		return eEC_AbsentOrderPriority;
	}
	//���״̬
	if(TRUE == IfPassitiveState()){
		if(IfMoving())
			m_pcMasterGU->GetCurBattle()->AskStopMoveObjectTar(m_pcMasterGU);
		m_pAttackSkill->End();
		return eEC_AbsentOrderPriority;
	}

	//��鹥��Ŀ��״̬
	if(GetAttackGU() == NULL || GetAttackGU()->IsDead() || GetAttackGU()->GetGOActionStateInfo().eOAS == eOAS_Reliving){
		SetAttackGU(NULL);
		if(IfMoving())
			m_pcMasterGU->GetCurBattle()->AskStopMoveObjectTar(m_pcMasterGU);
		m_eAttackState = eAttackState_Pursue;
		m_pAttackSkill->End();
		return eEC_TargetIsDead;
	}

	if (eAttackState_Pursue == m_eAttackState){
		//����Ƿ���ʩ������
		if (TRUE == m_pcMasterGU->IfInReleaseSkillRange(GetAttackGU(), m_pAttackSkill->cpsCfg)){
			m_eAttackState = eAttackState_UseSkill;
			m_pcMasterGU->GetCurBattle()->AskStopMoveObjectTar(m_pcMasterGU);
			m_pcMasterGU->GetCurBattle()->AskStopMoveObjectDir(m_pcMasterGU);
		}else{
			//����ƶ�״̬���Ƿ����ÿ�ʼ�������¿�ʼ�ƶ�
			TIME_TICK tLastCheckTickSpan = tUTCMilsec - m_tLastCheckMoveTarTime;
			if (500 <= tLastCheckTickSpan){
				if(m_pcMoveTarPos.m_fX != GetAttackGU()->GetCurPos().m_fX || m_pcMoveTarPos.m_fZ != GetAttackGU()->GetCurPos().m_fZ){
					m_pcMoveTarPos = GetAttackGU()->GetCurPos();
					//��ʼ�ƶ�
					MoveToTar(m_pcMoveTarPos,FALSE, 0);
				}
				m_tLastCheckMoveTarTime = tUTCMilsec;
			}
			//���ͣ�����ˣ����������ƶ�
			if(FALSE == m_ifMoving){
				MoveToTar(m_pcMoveTarPos,FALSE, tUTCMilsec);
			}
			
		}
	}

	if (eAttackState_UseSkill == m_eAttackState){
		if(IfMoving()){
			m_pcMasterGU->GetCurBattle()->AskStopMoveObjectTar(m_pcMasterGU);
			m_pcMasterGU->GetCurBattle()->AskStopMoveObjectDir(m_pcMasterGU);
		}
		if(m_pAttackSkill != NULL){
			//����Ƿ�������ʩ��״̬
			if(FALSE == m_pAttackSkill->ifRunning){
				//�������û����ʹ���У�����ʩ������
				if (TRUE == m_pcMasterGU->IfInReleaseSkillRange(GetAttackGU(), m_pAttackSkill->cpsCfg)){
					//�����ڣ���ʼʩ��
					m_pAttackSkill->pcTarGU = GetAttackGU();
					rst = m_pAttackSkill->Start();
					//���ʩ��ʧ��(CD�У���е��ԭ��),�򷵻أ���һ����������
					if(eNormal != rst){
						return rst;
					}
				}
				else{
					//�����⣬�л����ƶ�ģʽ
					m_eAttackState = eAttackState_Pursue;
					return eNormal;
				}
			}
			else{
				//������ʩ���У����ü�������
				INT32 rst = m_pAttackSkill->HeartBeat(tUTCMilsec, tTickSpan);
				if(eNormal != rst){
					if(eSkillState_End != rst && m_pcMasterGU->GetGOActionStateInfo().eOAS != eOAS_Free){
						m_pcMasterGU->BeginAction_Free(TRUE);
					}
					m_pAttackSkill->End();
					return rst;
				}
			}
		}
	}
	

	return eNormal;
}

bool	CSSAI::IfAttacking(){
	return m_pAttackSkill != NULL && m_pAttackSkill->ifRunning;
}

void	CSSAI::OnMoveBlock(){
	m_ifMoving = FALSE;
}

void	CSSAI::TryFree(){
	if(m_pcMasterGU->GetGOActionStateInfo().eOAS < eOAS_PassiveState){
		m_pcMasterGU->BeginAction_Free(TRUE);
	}
}

void	CSSAI::SetAttackGU(CSSGameUnit* pcAttackGU){
	m_pcAttackGU = pcAttackGU;
	if(m_pAttackSkill != NULL){
		m_pAttackSkill->pcTarGU = m_pcAttackGU;
	}
}

}