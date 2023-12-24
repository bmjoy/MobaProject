#include "SSAI_Soldier.h"
#include "SSNPC.h"
#include "SSBattle.h"
#include "SSMoveTool.h"

namespace SceneServer{

CSSAI_Soldier::CSSAI_Soldier(CSSGameUnit* pGU):CSSAI(pGU), m_cStartAttackPos(0,0,0)
, m_ifNeedRestartMove(TRUE)
, m_eOccupyState(eOccupyState_Walk)
, m_n32CurNodeIdx(0)
, m_ifAttackTarDead(FALSE)
{
	if (m_pcMasterGU){
		m_pcSoldierGU = m_pcMasterGU->TryCastToNPC();
	}
	m_bIfFliter = FALSE;
}

void	CSSAI_Soldier::SetOccupyPath(std::vector<CVector3D> & pathNode)//(const CVector3D *cpcPathNode, UINT32 un32NodeNum){
{	//���Ȳ��ܳ������ڵ�����
//	m_n32NodeNum = un32NodeNum;
	//if (pathNode.size() > (UINT32)c_n32MaxOrderPathNode){
		//m_n32NodeNum = (UINT32)c_n32MaxOrderPathNode;
//	}
	//�����ݿ�����������
	m_n32NodeNum = pathNode.size();
	for(int i=0; i< m_n32NodeNum; i++)
	{
		m_acOrderPath[i] = pathNode[i];

		if (i > (UINT32)c_n32MaxOrderPathNode){
			m_n32NodeNum = (UINT32)c_n32MaxOrderPathNode;
			break;
		}
	}

	//memcpy(m_acOrderPath, cpcPathNode, sizeof(CVector3D) * m_n32NodeNum);
	//��ʼ������
	m_eOccupyState = eOccupyState_Walk;
	//���õ�һ��Ŀ��ڵ�Ϊ����Ľڵ�
	float nearDist = 0;
	for(int i=0;i<m_n32NodeNum;i++){
		if(i > 3) break;
		float dist = m_pcSoldierGU->GetCurPos().GetWatchDistSqr(m_acOrderPath[i]);
		if(nearDist == 0 || dist < nearDist){
			nearDist = dist;
			SetNowPathIndex(i);
		}
	}
	
	
	//��ʼ����
	if(m_pcSoldierGU->GetCurBattle()->AskStartMoveToTar(m_pcSoldierGU,&m_acOrderPath[m_n32CurNodeIdx],TRUE,FALSE)){
		m_ifMoving = TRUE;
	}
}

void	CSSAI_Soldier::SetAttackTarget(CSSGameUnit* pTarget){
	SetAttackGU(pTarget);
	m_eOccupyState = eOccupyState_Attack;
	m_tLastCheckMoveTarTime = 0;
	m_pcSoldierGU->SetCurAtkGUID(GetAttackGU()->GetObjGUID());
	TryFree();
}

INT32	CSSAI_Soldier::HeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan){
	//����Ƿ��ǲ��ܹ���״̬
	if(TRUE == IfPassitiveState()){
		if(IfMoving())
			m_pcSoldierGU->GetCurBattle()->AskStopMoveObjectTar(m_pcSoldierGU);
		return eEC_AbsentOrderPriority;
	}
	//����Ƿ��Ѿ�����Ŀ��㸽��������ǣ���������Ϊ��һ���㡣������ڹ����л��߷����еĻ���Զ����Ϳ����ˣ������ܻ�ͷ·
	if (m_pcSoldierGU->GetCurPos().CanWatch((FLOAT)(eOccupyState_Walk == m_eOccupyState?c_n32PathPointWatchDist:1000), &m_acOrderPath[m_n32CurNodeIdx])){
	//�������㷨��Խ������X�Ľ��ޣ��������������ˡ�
	//if(  (m_acOrderPath[m_n32NodeNum-1].m_fX - m_acOrderPath[0].m_fX >= 0 && m_pcSoldierGU->GetCurPos().m_fX > m_acOrderPath[m_n32CurNodeIdx].m_fX - 200 )
	//	|| (m_acOrderPath[m_n32NodeNum-1].m_fX - m_acOrderPath[0].m_fX < 0 && m_pcSoldierGU->GetCurPos().m_fX < m_acOrderPath[m_n32CurNodeIdx].m_fX + 200 )  ){
		SetNowPathIndex(m_n32CurNodeIdx+1);
		//���������״̬����ת������Ŀ��
		if (eOccupyState_Walk == m_eOccupyState){
			MoveToTar(&m_acOrderPath[m_n32CurNodeIdx],TRUE, 0);
			m_ifNeedRestartMove = FALSE;
		}
	}

	//��·״̬
	if (eOccupyState_Walk == m_eOccupyState){
		CSSGameUnit *pcTarGU = m_pcSoldierGU->LookForEnemy(NULL,0,FALSE);
		//������ֵ��ˣ�����빥��״̬
		if (NULL != pcTarGU){
			SetAttackTarget(pcTarGU);
			m_cStartAttackPos = m_pcSoldierGU->GetCurPos();
		}
		else{
			//���ͣ�����ˣ����������ƶ�
			if(FALSE == m_ifMoving || m_ifNeedRestartMove){
				MoveToTar(&m_acOrderPath[m_n32CurNodeIdx],TRUE, tUTCMilsec);
				m_ifNeedRestartMove = FALSE;
			}
		}
	}
	//����״̬
	if (eOccupyState_Attack == m_eOccupyState){
		do{
			TIME_TICK tTickSpan = tUTCMilsec - m_tLastWatchEnemyMilsec;
			//ÿ1����һ��
			if(tTickSpan > 1000){
				//�Ƿ񳬹����׷�����룬����ǣ�����
				if (FALSE == m_pcSoldierGU->GetCurPos().CanWatch((FLOAT)m_pcSoldierGU->GetPursueDist(), m_cStartAttackPos)){
					m_eOccupyState = eOccupyState_Back;
					//���㷵�ص㡣���ص�Ϊ·����ֱ������ĵ�
					m_cBackToLinePos = &m_acOrderPath[m_n32CurNodeIdx];
					float minDistSqrt = -1;
					float tempMinDistSqrt = -1;
					CVector3D tempBackPoint;
					for(int i=m_n32CurNodeIdx-1;i<m_n32CurNodeIdx+2;i++){
						if(i < 0) continue;
						if(i >= m_n32NodeNum-1) break;
						IfPointNearPath(m_pcSoldierGU->GetCurPos(),&m_acOrderPath[i],&m_acOrderPath[i+1],tempMinDistSqrt,tempBackPoint);
						//���������ǰ���ҵ��ĵ㶼������������ΪĿ���
						if(minDistSqrt == -1 || (tempMinDistSqrt < minDistSqrt && tempMinDistSqrt >= 0)){
							minDistSqrt = tempMinDistSqrt;
							m_cBackToLinePos = tempBackPoint;
							SetNowPathIndex(i+1);
						}
					}
					//�򷵻ص��ƶ�
					MoveToTar(m_cBackToLinePos,TRUE,tUTCMilsec);
					break;
				}
				//����Ƿ��и����ȼ�Ŀ��
				CSSGameUnit *pcEnemy = m_pcSoldierGU->LookForEnemy(GetAttackGU(),0,FALSE);
				if ( NULL != pcEnemy &&  GetAttackGU() != pcEnemy){
					SetAttackTarget(pcEnemy);
				}
				//����Ƿ��й���������Ŀ��
				else if(m_eAttackState == eAttackState_Pursue){
					pcEnemy = m_pcSoldierGU->LookForEnemy(NULL, m_pcSoldierGU->GetFPData(eEffectCAte_AttackDist) * m_pcSoldierGU->GetFPData(eEffectCAte_AttackDist),FALSE);
					if(NULL != pcEnemy && m_pcSoldierGU->IfInReleaseSkillRange(pcEnemy, m_pcSoldierGU->GetNormalAttackSkill_NEW()->cpsCfg)){
						SetAttackTarget(pcEnemy);
					}
				}
				m_tLastWatchEnemyMilsec = tUTCMilsec;
			}

			//ִ�й�����Ϊ����
			INT32 rst = AttackHeartBeat(tUTCMilsec,tTickSpan);
			if(eNormal != rst){
				if(GetAttackGU() == NULL){
					m_eOccupyState = eOccupyState_Walk;
					//MoveToTar(&m_acOrderPath[m_n32CurNodeIdx],TRUE, 0);
				}
				if(eEC_TargetIsDead == rst){
					m_ifAttackTarDead = TRUE;
					TryFree();
				}
			}
		}
		while(FALSE);
		
		
	}
	
	//����״̬
	if(eOccupyState_Back == m_eOccupyState){
		//�����������ľ���
		if (m_pcSoldierGU->GetCurPos().CanWatch((FLOAT)(500), m_cBackToLinePos)){
			m_eOccupyState = eOccupyState_Walk;
			m_ifNeedRestartMove = TRUE;
			MoveToTar(&m_acOrderPath[m_n32CurNodeIdx],TRUE,tUTCMilsec);
		}
		else{
			//���ͣ�����ˣ����������ƶ�
			if(FALSE == m_ifMoving){
				if (m_pcSoldierGU->GetCurPos().CanWatch((FLOAT)(800), m_cBackToLinePos)){
					m_eOccupyState = eOccupyState_Walk;
					m_ifNeedRestartMove = TRUE;
					MoveToTar(&m_acOrderPath[m_n32CurNodeIdx],TRUE,tUTCMilsec);
				}
				else{
					MoveToTar(m_cBackToLinePos,TRUE,tUTCMilsec);
				}
			}
		}
	}

	return eNormal;
}

bool	CSSAI_Soldier::IfPointNearPath(CVector3D cPoint, CVector3D cPath1, CVector3D cPath2, float &distSqrt, CVector3D &nearesatPoint){
	float x = cPoint.m_fX;float y = cPoint.m_fZ;
	float x1 = cPath1.m_fX;float y1 = cPath1.m_fZ;
	float x2 = cPath2.m_fX;float y2 = cPath2.m_fZ;
	//�����һ�������90��
	double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);
	if (cross <= 0) {
		distSqrt = (x - x1) * (x - x1) + (y - y1) * (y - y1);
		nearesatPoint = cPath1;
		return FALSE;
	}
	//����ڶ��������90��
	double d2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	if (cross >= d2){
		distSqrt = (x - x2) * (x - x2) + (y - y2) * (y - y2);
		nearesatPoint = cPath2;
		return FALSE;
	}
	//�����Ƕ�С��90�ȣ���Ĵ������߶���
	double r = cross / d2;
	double px = x1 + (x2 - x1) * r;
	double py = y1 + (y2 - y1) * r;
	distSqrt = (x - px) * (x - px) + (py - y1) * (py - y1);
	nearesatPoint.m_fX = px;
	nearesatPoint.m_fZ = py;
	return TRUE;
}

}