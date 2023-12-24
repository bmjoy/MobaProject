#include "SSAI_Building.h"
#include "SSNPC.h"
#include "SSBattle.h"

namespace SceneServer{

CSSAI_Building::CSSAI_Building(CSSGameUnit* pGU):CSSAI(pGU)
	, m_pcBuildingGU(NULL)
{
	if (m_pcMasterGU){
		m_pcBuildingGU = m_pcMasterGU->TryCastToNPC();
	}
}

INT32	CSSAI_Building::HeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan){
	//û�й������ܵ�������ִ��AI
	if(NULL == m_pAttackSkill){
		return eNormal;
	}
	if(eNormal == m_pAttackSkill->IfSkillUsable()){
		//�����п������ٻ��������ٻ�������Ұ�����й����ģ������޹���
		CSSGameUnit* pEnemy = m_pcBuildingGU->LookForEnemy(NULL, 0, m_pcMasterGU->GetFatherHeroGUID() > 0?TRUE:FALSE);
		//��Ŀ�꣬��ʹ����ͨ��������
		if(NULL != pEnemy){
			m_pAttackSkill->pcTarGU = pEnemy;
			INT32	rst = m_pAttackSkill->Start();
			//���ʩ��ʧ��(�������ᣬΪ�������ܶ�����Ч���Ƽ���׼��),�򷵻أ���һ����������
			if(eNormal != rst){
				return rst;
			}
		}
	}
	return eNormal;
}



}