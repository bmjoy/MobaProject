#include "SSAI_Wild.h"
#include "SSNPC.h"
#include "SSBattle.h"
#include "SSMoveTool.h"

namespace SceneServer{

CSSAI_Wild::CSSAI_Wild(CSSGameUnit* pGU):CSSAI(pGU), m_ifAIRunning(TRUE)
	, m_eGuardState(eGuardState_Sleep)
{
	if (m_pcMasterGU){
		m_pcWildGU = m_pcMasterGU->TryCastToNPC();
	}
	m_bIfFliter = FALSE;
}

CSSGameUnit* CSSAI_Wild::LookForEnemy(){
	if (m_pcMasterGU->GetCurEnemyGUID() < 1){
		return NULL;
	}
	CSSGameUnit* pTarget = m_pcMasterGU->GetCurBattle()->GetGameUnitByGUID(m_pcMasterGU->GetCurEnemyGUID());
	if(pTarget == NULL || FALSE == pTarget->IfCanBeTarget() || pTarget->GetCurHP() <= 0 || pTarget->IfHero() == FALSE){
		return NULL;
	}
	return pTarget;
}

void	CSSAI_Wild::StopAI(){
	if(FALSE == m_ifAIRunning) return;

	m_ifAIRunning = FALSE;
	if (eGuardState_WalkBack == m_eGuardState){
		m_pcWildGU->GetCurBattle()->AskStopMoveObjectTar(m_pcWildGU);
	}
	else if (eGuardState_Attack == m_eGuardState){
		CancleAttack();
	}
	m_pcWildGU->BeginAction_Free(TRUE);
}

INT32	CSSAI_Wild::HeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan){
	//���AI�Ƿ���ͣ
	if(FALSE == m_ifAIRunning){
		return eNormal;
	}
	//����Ƿ��ǲ��ܹ���״̬
	if(TRUE == IfPassitiveState()){
		return eEC_AbsentOrderPriority;
	}

	//�ȴ�״̬
	if (eGuardState_Sleep == m_eGuardState){
		CSSGameUnit *pcTarEnemy = LookForEnemy();
		if (NULL != pcTarEnemy){
			m_eGuardState = eGuardState_Attack;
			//��ʼ������
			SetAttackGU(pcTarEnemy);
			m_eAttackState = eAttackState_Pursue;
			m_tLastCheckMoveTarTime = 0;
		}
	}
	//����״̬
	if (eGuardState_Attack == m_eGuardState){
		//�������ʹ�ü����У���ֱ��ִ������
		bool continueAttack = FALSE;
		if(eAttackState_UseSkill == m_eAttackState ){
			continueAttack = TRUE;
		}
		else{
			//����Ƿ��˸÷��ص�ʱ����
			INT32 n32PursueDist = m_pcWildGU->GetPursueDist();
			if (m_pcWildGU->GetCurPos().GetWatchDistSqr(m_pcWildGU->GetWMBornPos()) > n32PursueDist * n32PursueDist){
				m_eGuardState = eGuardState_WalkBack;
				MoveToTar(m_pcWildGU->GetWMBornPos(),TRUE,tUTCMilsec);
			}
			//���򣬼���ִ�й���ָ��
			else{
				continueAttack = TRUE;
			}
		}
		if(continueAttack){
			INT32 rst = AttackHeartBeat(tUTCMilsec,tTickSpan);
			//�����������ʧ�ܣ�������Ѱ��Ŀ��
			if(eNormal != rst && eSkillState_End != rst && eEC_UseSkillFailForSkillCoolDown != rst){
				CSSGameUnit *pcTarEnemy = LookForEnemy();
				if (NULL != pcTarEnemy){
					m_eGuardState = eGuardState_Attack;
					//��ʼ������
					SetAttackGU(pcTarEnemy);
					m_eAttackState = eAttackState_Pursue;
					m_tLastCheckMoveTarTime = 0;
				}
				//û��Ŀ����Թ����ˣ��ؼ�
				else{
					m_eGuardState = eGuardState_WalkBack;
					MoveToTar(m_pcWildGU->GetWMBornPos(),TRUE,tUTCMilsec);
				}
			}
		}
	}
	//�ؼ�״̬
	if (eGuardState_WalkBack == m_eGuardState){
		if(FALSE == m_ifMoving){
			//����Ƿ�ص���������
			//if (m_pcWildGU->GetCurPos().GetWatchDistSqr(m_pcWildGU->GetWMBornPos()) <= 5000){
			if(TRUE == CSSMoveTool::IfInTheSameBlock(m_pcWildGU->GetCurPos().m_fX,m_pcWildGU->GetCurPos().m_fZ, m_pcWildGU->GetWMBornPos().m_fX, m_pcWildGU->GetWMBornPos().m_fZ)){
				m_pcWildGU->BeginAction_Free(true);
				m_eGuardState  = eGuardState_Sleep;
				m_pcWildGU->GetCurBattle()->SetWildNPCGroupCurEnemy(m_pcWildGU, NULL);
				m_pcMasterGU->SetCurEnemyGUID(0);
			}
			else{
				MoveToTar(m_pcWildGU->GetWMBornPos(),TRUE,tUTCMilsec);
			}
		}
	}

	return eNormal;
}



}