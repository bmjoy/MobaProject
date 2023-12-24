#include "SSAI_Hero.h"
#include "SSGameUnit.h"
#include "SSBattle.h"
#include "SSSkill.h"
#include "SSNPC.h"
#include "SSHero.h"
#include "SSCfgMgr.h"
#include "SSUser.h"
#include "log/SSGameLogMgr.h"

namespace SceneServer{

CSSAI_Hero::CSSAI_Hero(CSSGameUnit* pGU):CSSAI(pGU), m_ifAutoAttack(FALSE)
, m_pNowSkill(NULL)
, m_pWantUseSkill(NULL)
, m_nextSkill(NULL)
, m_ifAbsorb(FALSE)
, m_ifMoveDir(FALSE)
, m_pcAbsorbNPC(NULL)
, m_ifStandAttack(FALSE)
{
	if (m_pcMasterGU){
		m_pcHeroGU = m_pcMasterGU->TryCastToHero();
	}
	m_bIfFliter = TRUE;
}

CSSAI_Hero::~CSSAI_Hero(){
	m_pcHeroGU = NULL;
	m_pNowSkill = NULL;
	m_pWantUseSkill = NULL;
}

INT32 CSSAI_Hero::AskMoveDir(const CVector3D &crcDir){
	//����Ƿ��ǲ��ܲ���״̬
	if(TRUE == IfPassitiveState()){
		return eEC_AbsentOrderPriority;
	}
	//����ֹͣ���м���
	if(FALSE == StopAllSkill()){
		if(m_pNowSkill == NULL || FALSE == m_pNowSkill->IfMasterMoveAble()){
			return eEC_AbsentOrderPriority;
		}
	}
	//ֹͣ�Զ�����
	m_ifAutoAttack = FALSE;
	StopAttack();
	//ֹͣ����
	TryCancleAbsorb();
	//�����ƶ�
	if(FALSE == m_pcHeroGU->GetCurBattle()->AskStartMoveDir(m_pcHeroGU, crcDir)){
		m_pcHeroGU->BeginAction_Free(TRUE);
		return eEC_AbsentOrderPriority;
	}
	//ֹͣվ������
	m_ifStandAttack = FALSE;
	m_ifMoveDir = TRUE;
	m_ifMoving = TRUE;
	return eNormal;
}

INT32 CSSAI_Hero::AskMoveTar(const CVector3D &crcPos){
	//����Ƿ��ǲ��ܲ���״̬
	if(TRUE == IfPassitiveState()){
		return eEC_AbsentOrderPriority;
	}
	//����ֹͣ���м���
	if(FALSE == StopAllSkill()){
		if(m_pNowSkill == NULL || FALSE == m_pNowSkill->IfMasterMoveAble()){
			return eEC_AbsentOrderPriority;
		}
	}
	//ֹͣ�Զ�����
	m_ifAutoAttack = FALSE;
	//ֹͣ�Զ�׷��ʩ�ż���
	StopWantUseSkill();
	//ֹͣ�Զ�����
	StopAttack();
	//ֹͣ����
	TryCancleAbsorb();
	//ֹͣ�ֶ��ƶ�
	m_ifMoveDir = FALSE;
	//�����ƶ�
	if(FALSE == m_pcHeroGU->GetCurBattle()->AskStartMoveToTar(m_pcHeroGU,crcPos,TRUE,TRUE)){
		m_pcHeroGU->BeginAction_Free(TRUE);
		return eEC_AbsentOrderPriority;
	}
	//ֹͣվ������
	m_ifStandAttack = FALSE;
	m_ifMoving = TRUE;
	return eNormal;
}

INT32 CSSAI_Hero::AskStopMove(){
	//����Ƿ��ǲ��ܲ���״̬
	if(TRUE == IfPassitiveState()){
		return eEC_AbsentOrderPriority;
	}
	m_pcHeroGU->GetCurBattle()->AskStopMoveObjectDir(m_pcHeroGU);
	m_ifMoveDir = FALSE;

	return eNormal;
}

INT32 CSSAI_Hero::AskStartAutoAttack(){
	//����Ƿ��ܿ�����
	if(TRUE == IfPassitiveState()){
		return eNormal;
	}
	//����Ѿ����Զ������ˣ�ֱ�ӷ���
	if(m_ifAutoAttack){
		return eNormal;
	}
	//����Ƿ����ֶ��ƶ��С�����ǣ��ܾ������Զ�����
	if(TRUE == m_ifMoveDir){
		return eNormal;
	}
	//����Ƿ����������С�����ǣ��ܾ������Զ�����
	if(m_ifAbsorb){
		return eNormal;
	}
	//����Ƿ񱻽�е
	if (m_pcMasterGU->GetFPData(eEffectCate_Restrain) > 0){
		return eNormal;
	}
	//����������ܹ��������
	INT32 rst = CheckAttackTarget();
	if(eNormal != rst){
		return rst;
	}
	//����ֹͣ���м���
	if(FALSE == StopAllSkill()){
		return eEC_AbsentOrderPriority;
	}
	
	//ֹͣ�ֶ��ƶ�
	m_ifMoveDir = FALSE;
	//ֹͣվ������
	m_ifStandAttack = FALSE;
	//��ʼ������
	m_ifAutoAttack = TRUE;
	m_eAttackState = eAttackState_Pursue;
	m_tLastCheckMoveTarTime = 0;

	//��ʼ�����Զ�����
	AttackHeartBeat(GetUTCMiliSecond(),0);

	return eNormal;
}

INT32 CSSAI_Hero::AskUseSkill(UINT32 un32SkillID){
	//����Ƿ��ǲ��ܲ���״̬
	if(TRUE == IfPassitiveState()){
		return eEC_AbsentOrderPriority;
	}
	//����Ƿ񱻳�Ĭ��
	if(m_pcHeroGU->GetFPData(eEffectCate_Silence) > 0){
		return eEC_UseSkillFailForSilenced;
	}
	//����Ƿ��������У�����ǣ�����ʹ�ü���
	if(m_ifAbsorb){
		return eEC_AbsentOrderPriority;
	}
	//��ȡ����鼼���Ƿ����
	CSSSkill* pSkill = m_pcHeroGU->GetSkillByID(un32SkillID);
	if(NULL == pSkill){
		return eEC_CanNotFindTheSkill;
	}

	//��鼼���Ƿ���Ͽ�������
	INT32 rst = pSkill->IfSkillUsable();
	if(eNormal != rst){
		return rst;
	}
	//����Ƿ����������еļ���
	if(m_pNowSkill != NULL && m_pNowSkill->cpsCfg->un32SkillID == pSkill->cpsCfg->un32SkillID){
		return eEC_AbsentOrderPriority;
	}
	//�����ж��Ƿ���ʩ�ż����С������ʩ�ż����У������ļ��ܶ����м�¼���ȴ�ʩ��
	if(IfUsingSkill() && (TRUE == m_pNowSkill->IfSkillBeforeHit() || m_pNowSkill->GetSkillState() == eSkillState_Using)){
		//ǰҡ������״̬����Ҫ����ǰ���ܼ�������
		m_nextSkill = pSkill;
		return eEC_AbsentOrderPriority;
	}
	else{
		//�ȼ�⼼���Ƿ񹻾���ʩ��	
		rst = pSkill->IfSkillUsableWithNowTarget();
		if(eEC_AbsentSkillDistance == rst){
			//���������̲������������Զ�׷���ͷż��ܹ���

			//ֹͣ�Զ�����
			m_ifAutoAttack = FALSE;
			//ֹͣ�ֶ��ƶ�
			m_ifMoveDir = FALSE;
			//ֹͣվ������
			m_ifStandAttack = FALSE;
			//��������
			m_pWantUseSkill = pSkill;
			m_pcMoveTarPos = m_pWantUseSkill->pcTarGU->GetCurPos();
			m_tLastCheckMoveTarTime = GetUTCMiliSecond();
			MoveToTar(m_pcMoveTarPos,FALSE,m_tLastCheckMoveTarTime);
			return eNormal;
		}
		else if(eNormal != rst){
			return rst;
		}
		else{
			//����Ƿ���˲�����ܡ������˲�����ܣ�����Ҫ��ϵ�ǰ��λ��
			if(FALSE == pSkill->IfImpactSkill() || 
				(pSkill->cpsCfg->n32SkillLastTime > 0 && IfMoving() == FALSE && m_ifAutoAttack == FALSE && m_pAttackSkill->ifRunning == FALSE)
				){
				//����Ƿ�˲�����ܣ���ֹͣ��ص��Զ�������λ�Ƶ�
				//ֹͣ�Զ�����
				CancleAttack();
				//ֹͣ�ƶ�
				m_ifMoveDir = FALSE;
				m_pcHeroGU->GetCurBattle()->AskStopMoveObjectAll(m_pcHeroGU);
				//��ʼʹ�ü��ܣ�ֹͣ��������
				StopAllSkill();
				//��Ҫ�����������漼��
				m_pNowSkill = pSkill;
				//ֹͣ�Զ�������վ������
				if(pSkill->IfHasPreTime() == FALSE){
					//û��ǰҡ�ķ�˲������(�ֽ׶ξ�����������)����Ҫֹͣ�Զ�����
					m_ifAutoAttack = FALSE;
				}
				m_ifStandAttack = FALSE;
			}
			//��ʼʹ�ü���
			pSkill->Start();
			return rst;
		}
	}
	
}

INT32 CSSAI_Hero::AskAbsorbMonster(INT32 n32ToRemoveIndex){
	//����Ƿ��ǲ��ܲ���״̬
	if(TRUE == IfPassitiveState()){
		return eEC_AbsentOrderPriority;
	}
	//�����������Ϸ���
	CSSGameUnit* pTempGU = m_pcHeroGU->GetCurBattle()->GetGameUnitByGUID(m_pcHeroGU->GetLockedTargetGUID());
	if (NULL == pTempGU || FALSE == pTempGU->IfWildNPC() || pTempGU->IsDead()){
		return eEC_NULLNPC;
	}
	m_pcAbsorbNPC = pTempGU->TryCastToNPC();
	//����Ƿ��������
	if (FALSE == m_pcAbsorbNPC->TryCastToNPC()->GetNPCCfg()->bIfCanControl){
		return eEC_AbsorbMonsterFailForMonsterCannotBeConstrol;
	}
	//�����ҹ�ϵ
	if (false == CFunction::IfEnemy(m_pcAbsorbNPC->GetCampID(),m_pcHeroGU->GetCampID())){
		return eEc_InvalidAbsorbTar;
	}
	//��������ȼ�
	if (m_pcHeroGU->GetLevel() < c_un32HeroMinAbsorbLevel){
		return eEC_AbsorbMonsterFailForLackLevel;
	}
	//����������ӵĺϷ���
	if (n32ToRemoveIndex > 1 || n32ToRemoveIndex < -1){
		return eEC_NullHero;
	}
	//����Ƿ��Ѿ��������ظ���Ұ��
	for (INT32 i = 0; i < c_n32MaxAbsorbSkillNum; ++i){
		if (m_pcAbsorbNPC->TryCastToNPC()->GetNPCCfg()->eOT == m_pcHeroGU->GetAbsorbMonsterID(i)){
			return eEC_AbsorbMonsterFailForHasSameSkillID;
		}
	}
	//����Ǯ
	if (m_pcHeroGU->GetCP(eCPCP_Personnal) < GetAbsorbCost(m_pcAbsorbNPC->TryCastToNPC())){
		return eEC_AbsorbMonsterFailForLackCP;
	}
	//����ֹͣ���м���
	if(FALSE == StopAllSkill()){
		return eEC_AbsentOrderPriority;
	}
	//ֹͣ�Զ�����
	if(m_ifAutoAttack){
		CancleAttack();
	}
	//ֹͣ�ֶ��ƶ�
	m_ifMoveDir = FALSE;
	m_pcHeroGU->GetCurBattle()->AskStopMoveObjectDir(m_pcHeroGU);
	m_pcHeroGU->GetCurBattle()->AskStopMoveObjectTar(m_pcHeroGU);
	//��ʼ������
	m_n32ToRemoveAbsorbIndex = n32ToRemoveIndex;
	m_pcHeroGU->BeginAction_Free(TRUE);
	m_tStartAbsorbTime = GetUTCMiliSecond();
	m_ifAbsorb = TRUE;
	//ֹͣ���������AI
	m_pcAbsorbNPC->TryCastToNPC()->AskStopAI();
	//���Ϳ�ʼ������Ϣ���ͻ���
	GSToGC::AbsorbBegin sAbsorbBegin;
	sAbsorbBegin.set_guid(m_pcHeroGU->GetObjGUID());
	sAbsorbBegin.set_monsterguid(m_pcAbsorbNPC->GetObjGUID());
	m_pcHeroGU->GetCurBattle()->SyncMsgToGC(sAbsorbBegin, sAbsorbBegin.msgid(), m_pcHeroGU->GetObjGUID(), m_pcHeroGU, NULL);
	 
	return eNormal;
}

INT32	CSSAI_Hero::AskGasExpersion(){
	//����Ƿ��ǲ��ܲ���״̬
	if(TRUE == IfPassitiveState()){
		return eEC_AbsentOrderPriority;
	}
	//����Ƿ񱻳�Ĭ��
	if(m_pcHeroGU->GetFPData(eEffectCate_Silence) > 0){
		return eEC_StateCanNotUseGas;
	}

	INT32 rst = m_pcHeroGU->GasExpersion();
	if(eNormal == rst){
		//�����ɹ�����Ҫ��ϼ���Ѱ·
		StopWantUseSkill(TRUE);
	}
	//log
	if(!m_pcHeroGU->IfAI() && !m_pcHeroGU->GetCurBattle()->IsGuideBattle()){
		stringstream mystream;
		mystream << ( ( GetUTCMiliSecond() - m_pcHeroGU->GetCurBattle()->GetBattleStateStartTime() ) / 1000) << LOG_SIGN;
		mystream << m_pcHeroGU->GetUser()->GetGUID();
		CSSGameLogMgr::GetInstance().AddBattleLog(eLog_BattleExpersion,m_pcHeroGU->GetCurBattleID(),m_pcHeroGU->GetCurBattle()->GetBattleMapId(),mystream.str());
	}
	return rst;
}

void	CSSAI_Hero::TryCancleAbsorb(){
	if(m_ifAbsorb){
		m_pcHeroGU->SynAbsobInfoToGC(0, 0, 0);
		if(m_pcAbsorbNPC != NULL){
			m_pcAbsorbNPC->TryCastToNPC()->AskResumeAI();
			m_pcAbsorbNPC = NULL;
		}
		m_ifAbsorb = FALSE;
	}
}

INT32	CSSAI_Hero::GetAbsorbCost(CSSNPC *sspNPC){
	if (0 < sspNPC->GetBelongAltar()){
		return sspNPC->GetNPCCfg()->n32ConsumeCP * 2;	
	}
	return sspNPC->GetNPCCfg()->n32ConsumeCP;
}

INT32 CSSAI_Hero::AbsorbHeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan){
	//���״̬
	if (eOAS_Free != m_pcHeroGU->GetGOActionStateInfo().eOAS){
		return eEC_AbsorbMonsterFailForHeroDead;
	}
	if (m_pcHeroGU->GetFPData(eEffectCate_Dizziness)){
		return eEC_AbsorbMonsterFailForDizziness;
	}
	//����Ƿ��л��˶���
	if (m_pcAbsorbNPC == NULL || m_pcHeroGU->GetLockedTargetGUID() != m_pcAbsorbNPC->GetObjGUID()){
		return eEC_AbsorbMonsterFailForDiffNPC;
	}
	//����״̬
	if (m_pcAbsorbNPC->IsDead()){
		return eEC_AbsorbMonsterFailForMonsterDead;
	}
	//�������ʱ���Ƿ���
	if (tUTCMilsec - m_tStartAbsorbTime >= c_n32AbsorbTimeout){
		//����Ǯ
		if (m_pcHeroGU->GetCP(eCPCP_Personnal) < GetAbsorbCost(m_pcAbsorbNPC->TryCastToNPC())){
			return eEC_AbsorbMonsterFailForLackCP;
		}
		//�������Ŀ���Ӧ�ļ���
		const SSNewSkillCfg* cpsCfg = (SSNewSkillCfg*)(CSSCfgMgr::GetSSCfgInstance().GetSkillFromOriSkillAndNewLevel(m_pcAbsorbNPC->TryCastToNPC()->GetNPCCfg()->aun32SkillList[1] , m_pcHeroGU->GetLevel()));
		if (NULL == cpsCfg){
			return eEC_NULLCfg;
		}
		//������Ҫ�Ƴ��ĸ���
		INT32	newAbsorbSkillIndex = -1;
		if (0 == m_pcHeroGU->GetAbsorbMonsterID(0)){
			m_n32ToRemoveAbsorbIndex = -1;
			newAbsorbSkillIndex = 0;
		}
		else if (0 == m_pcHeroGU->GetAbsorbMonsterID(1)){
			if (m_pcHeroGU->GetLevel() < c_un32HeroMidAbsorbLevel){
				//Ӣ�۵ȼ����������ڶ����֣����Ƴ���һ����
				m_n32ToRemoveAbsorbIndex = 0;
			}
			else{
				m_n32ToRemoveAbsorbIndex = -1;
			}
			newAbsorbSkillIndex = 1;
		}
		else if(-1 == m_n32ToRemoveAbsorbIndex){
			m_n32ToRemoveAbsorbIndex = 1;
			newAbsorbSkillIndex = m_n32ToRemoveAbsorbIndex;
		}

		//�Ƴ�ռλ�ĸ���
		if (-1 != m_n32ToRemoveAbsorbIndex){
			UINT32 un32MosterID = m_pcHeroGU->GetAbsorbMonsterID(m_n32ToRemoveAbsorbIndex);
			if (0 != un32MosterID){
				m_pcHeroGU->AskRemoveAbsorbSkill(un32MosterID);
			}
			newAbsorbSkillIndex = m_n32ToRemoveAbsorbIndex;
		}

		m_pcHeroGU->ChangeCP(eCPCP_Personnal, -GetAbsorbCost(m_pcAbsorbNPC->TryCastToNPC()), false);
		m_pcHeroGU->ChangeFPInAbsorb(*m_pcAbsorbNPC->TryCastToNPC()->GetNPCCfg(), TRUE);
		m_pcAbsorbNPC->SetExpire(TRUE);

		AbsorbRuntimeInfo* pChangAbsorbRuntimeInfo = m_pcHeroGU->GetAbsorbMonsterSkillInfo(newAbsorbSkillIndex);
		pChangAbsorbRuntimeInfo->Clear();
		pChangAbsorbRuntimeInfo->sNPCCfg = (SNPCCfg*)m_pcAbsorbNPC->TryCastToNPC()->GetNPCCfg();
		pChangAbsorbRuntimeInfo->pSkill->Clear();
		pChangAbsorbRuntimeInfo->pSkill->cpsCfg = cpsCfg;

		pChangAbsorbRuntimeInfo->pSkill->pcMasterGU = m_pcMasterGU;
		pChangAbsorbRuntimeInfo->pSkill->eSkillState = eSkillState_Free;
		pChangAbsorbRuntimeInfo->pSkill->tStateMilsec = 0;


		//���������ɹ���Ϣ���ͻ���
		UINT32 n32MonsterIDArr[2] = {0};
		for (INT32 i = 0; i < 2; ++i){
			n32MonsterIDArr[i] = m_pcHeroGU->GetAbsorbMonsterID(i);
		}
		m_pcHeroGU->SynAbsobInfoToGC(1, n32MonsterIDArr[0], n32MonsterIDArr[1]);

		m_pcHeroGU->GetCurBattle()->DoWildMonsterDead(  m_pcAbsorbNPC->TryCastToNPC());			 

		m_ifAbsorb = FALSE;

		//log
		if(!m_pcHeroGU->IfAI() && m_pcHeroGU->GetUser()&& !m_pcHeroGU->GetCurBattle()->IsGuideBattle())
		{
			stringstream mystream;
			mystream <<((GetUTCMiliSecond() - m_pcHeroGU->GetCurBattle()->GetBattleStateStartTime()) / 1000)<<LOG_SIGN;
			mystream <<  m_pcHeroGU->GetUser()->GetGUID()   <<LOG_SIGN;
			mystream <<m_pcHeroGU->GetObjType()<<LOG_SIGN;
			mystream <<m_pcHeroGU->GetLevel()<<LOG_SIGN;
			mystream <<m_pcAbsorbNPC->GetObjType();
			CSSGameLogMgr::GetInstance().AddBattleLog(eLog_BattleStrawMonster,m_pcHeroGU->GetCurBattle()->GetBattleID(),m_pcHeroGU->GetCurBattle()->GetBattleMapId(),mystream.str());
		} 
	}

	return eNormal;
}

INT32	CSSAI_Hero::CheckAttackTarget(){
	if(m_pcHeroGU->GetLockedTargetGUID() < 1 || NULL == m_pcHeroGU->GetCurBattle()->GetGameUnitByGUID(m_pcHeroGU->GetLockedTargetGUID())){
		return eEC_NotEnemy;
	}
	SetAttackGU(m_pcHeroGU->GetCurBattle()->GetGameUnitByGUID(m_pcHeroGU->GetLockedTargetGUID()));
	//���Ŀ��Ϸ���
	if(FALSE == CFunction::IfEnemy(m_pcMasterGU->GetCampID(), GetAttackGU()->GetCampID())){
		SetAttackGU(NULL);
		return eEC_NotEnemy;
	}
	return eNormal;
}

INT32 CSSAI_Hero::WantUseSkillHeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan){
	if (m_pcMasterGU->GetFPData(eEffectCate_Silence) > 0){
		//�������Ĭ�ˣ���Ҫ��ֹ����Ѱ·
		StopWantUseSkill(TRUE);
		return eNormal;
	}
	//����Ƿ����ʩ�ž���
	if (eNormal == m_pWantUseSkill->IfSkillUsableWithNowTarget()){
		//����ʩ�������ˣ�ֹͣ�Զ�׷������ʼʩ�ż���
		m_pcMasterGU->GetCurBattle()->AskStopMoveObjectTar(m_pcMasterGU);
		INT32 rst = TryUseSkillWithAnyType(m_pWantUseSkill);
		StopWantUseSkill();
		return rst;
	}
	//����Ƿ�Ŀ�겻����ʩ��Ҫ����
	if(m_pWantUseSkill->pcTarGU == NULL || m_pWantUseSkill->pcTarGU->IsDead()){
		StopWantUseSkill(TRUE);
		return eNormal;
	}
	//���û�н���ʩ�����룬�����׷��
	if(FALSE == m_ifMoving || (tUTCMilsec - m_tLastCheckMoveTarTime > 500 && m_pWantUseSkill->pcTarGU->GetCurPos() != m_pcMoveTarPos ) ){
		m_pcMoveTarPos = m_pWantUseSkill->pcTarGU->GetCurPos();
		m_tLastCheckMoveTarTime = tUTCMilsec;
		MoveToTar(m_pcMoveTarPos,FALSE,m_tLastCheckMoveTarTime);
	}

	return eNormal;
}

void CSSAI_Hero::StopWantUseSkill(BOOLEAN ifStopMove){
	if(m_pWantUseSkill != NULL){
		m_pWantUseSkill = NULL;
		if(ifStopMove && m_ifMoving){
			m_pcHeroGU->GetCurBattle()->AskStopMoveObjectTar(m_pcHeroGU);
		}
	}
	m_nextSkill = NULL;
}

bool CSSAI_Hero::StopAllSkill(bool bIfForceStop){
	if(NULL != m_pNowSkill){
		if(FALSE == m_pNowSkill->TryCancle()){
			return FALSE;
		}
		m_pNowSkill = NULL;
	}
	StopWantUseSkill(TRUE);
	m_nextSkill = NULL;
	return TRUE;
}

INT32 CSSAI_Hero::UseSkillHeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan){
	INT32 rst = m_pNowSkill->HeartBeat(tUTCMilsec, tTickSpan);
	if(eNormal != rst){
		if(eSkillState_End != rst){
			m_pNowSkill->TryCancle();
		}
		m_pNowSkill = NULL;
		TryFree();
		//������ܽ����ˣ���鲢������һ��Ԥ������
		if(m_nextSkill != NULL){
			TryUseSkillWithAnyType(m_nextSkill);
		}
	}
	return eNormal;
}

INT32 CSSAI_Hero::TryUseSkillWithAnyType(CSSSkill* pSkill){
	//����Ƿ���Ʒ����
	map<CSSSkill*,UINT8>* pGoodsSkillMap = m_pcHeroGU->GetGoodsSkillMap();
	auto iter = pGoodsSkillMap->find(pSkill);
	INT32 rst = eNormal;
	if(iter != pGoodsSkillMap->end()){
		rst = m_pcHeroGU->AskUseGoods(iter->second);
	}
	else{
		rst =  AskUseSkill(pSkill->cpsCfg->un32SkillID);
	}
	return rst;
}

INT32 CSSAI_Hero::HeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan){
	//����Ƿ��ǲ��ܲ���״̬a
	if(TRUE == IfPassitiveState()){
		//������ɿ�״̬�£����������ƶ��Ͳ���״̬
		//ֹͣ����
		TryCancleAbsorb();
		StopAllSkill(TRUE);
		//ֹͣ�Զ�����
		CancleAttack();
		StopWantUseSkill(TRUE);
		m_nextSkill = NULL;
		m_ifAutoAttack = FALSE;
		m_ifMoveDir = FALSE;
		if(m_ifMoving){
			m_pcHeroGU->GetCurBattle()->AskStopMoveObjectDir(m_pcHeroGU);
			m_pcHeroGU->GetCurBattle()->AskStopMoveObjectTar(m_pcHeroGU);
		}
		return eEC_AbsentOrderPriority;
	}
	/*
		Ӣ�۵������������������飺������ʹ�ü��ܣ��Զ�����
		�������������໥���������ܲ����
	*/

	if(m_ifAbsorb){
		if(eNormal != AbsorbHeartBeat(tUTCMilsec,tTickSpan)){
			TryCancleAbsorb();
		}
	}
	//�Զ�׷��ʩ�ż���qwqq
	else if(m_pWantUseSkill != NULL){
		WantUseSkillHeartBeat(tUTCMilsec,tTickSpan);
	}
	//ʩ�ż�������
	else if(m_pNowSkill != NULL){
		UseSkillHeartBeat(tUTCMilsec,tTickSpan);
	}
	//�Զ��������������м��������е�ʱ�򣬲������Զ�����
	else if(m_ifAutoAttack){
		//���Ŀ�ꡣ������Ŀ�걻�л���ʱ��Ҫ�л�����Ŀ�ꡣ
		if(GetAttackGU() == NULL || GetAttackGU()->GetObjGUID() != m_pcHeroGU->GetLockedTargetGUID()){
			INT32 rst = CheckAttackTarget();
			if(eNormal != rst){
				CancleAttack();
				m_ifAutoAttack = FALSE;
				TryFree();
				return rst;
			}
			//��ʼ������
			m_eAttackState = eAttackState_Pursue;
			m_tLastCheckMoveTarTime = 0;
		}
		//���Ŀ�������˻������ڸ�����
		else if(GetAttackGU()->IsDead() || GetAttackGU()->GetGOActionStateInfo().eOAS == eOAS_Reliving){
			TryFree();
			CancleAttack();
			return eNormal;
		}
		AttackHeartBeat(tUTCMilsec,tTickSpan);
	}
	//ʲô��û������ô�ͼ���Ƿ��п�������������Ŀ��
	else if(FALSE == m_ifMoving){
		DoStandNormalAttack(tUTCMilsec,tTickSpan);
	}

	return eNormal;
}

void	CSSAI_Hero::DoStandNormalAttack(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan){
	//�ж��Ƿ�������Ŀ��
	if(m_pcHeroGU->GetLockedTargetGUID() > 0){
		CSSGameUnit* pAttackTar = m_pcHeroGU->GetCurBattle()->GetGameUnitByGUID(m_pcHeroGU->GetLockedTargetGUID());
		//�Ƿ�������ͨ������
		if(m_pAttackSkill->ifRunning){
			if(pAttackTar == NULL || pAttackTar->IsDead() || pAttackTar->GetGOActionStateInfo().eOAS == eOAS_Reliving){
				m_ifStandAttack = FALSE;
				TryFree();
			}
			else{
				INT32 rst = m_pAttackSkill->HeartBeat(tUTCMilsec,tTickSpan);
				if(eEC_NullPointer == rst){
					m_ifStandAttack = FALSE;
					TryFree();
				}
			}
		}
		else{
			//�Ƿ��ǺϷ��Ĺ���Ŀ��
			if(eNormal == m_pAttackSkill->IfSkillUsableWithNowTarget()){
			//if(pAttackTar != NULL && TRUE == CFunction::IfEnemy(m_pcHeroGU->GetCampID(), pAttackTar->GetCampID())){
				//��ͨ���������Ƿ����
				if(eNormal == m_pAttackSkill->IfSkillUsable()){ 
					//�Ƿ��ڹ�����Χ��
					if (TRUE == m_pcHeroGU->IfInReleaseSkillRange(pAttackTar, m_pAttackSkill->cpsCfg)){
						//�����ڣ���ʼʩ��
						m_pAttackSkill->pcTarGU = pAttackTar;
						m_ifStandAttack = TRUE;
						if(eNormal != m_pAttackSkill->Start()){
							m_ifStandAttack = FALSE;
							TryFree();
						}
					}
					else{
						if( TRUE == m_ifStandAttack){
							m_ifStandAttack = FALSE;
							TryFree();
						}
					}
				}
			}
			else if( TRUE == m_ifStandAttack && tUTCMilsec + 100 > m_pAttackSkill->tCooldownMilsec){
				m_ifStandAttack = FALSE;
				TryFree();
			}
		}
	}
	else{
		if( TRUE == m_ifStandAttack && tUTCMilsec + 100 > m_pAttackSkill->tCooldownMilsec){
			m_ifStandAttack = FALSE;
			TryFree();
		}
	}
}

void	CSSAI_Hero::ClearAction(){
	//����Ƿ���ʩ�ż�����
	if(NULL != m_pNowSkill){
		m_pNowSkill->TryCancle();
	}
	//ֹͣ�Զ�׷��ʩ�ż���
	StopWantUseSkill();
	//ֹͣ�Զ�����
	m_ifAutoAttack = FALSE;
	StopAttack();
	//ֹͣ����
	TryCancleAbsorb();
	//ֹͣ�ֶ��ƶ�
	m_ifMoveDir = FALSE;
	//ֹͣ�Զ��ƶ�
	if(m_ifMoving){
		m_pcHeroGU->GetCurBattle()->AskStopMoveObjectTar(m_pcHeroGU);
	}
}

void	CSSAI_Hero::OnTeleport(){
	if(m_pNowSkill != NULL){
		m_pNowSkill->TryCancle();
	}
}

}