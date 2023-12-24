
#include "SSSkillEffect_Buf.h"
#include "SSGameUnit.h"
#include "SSHero.h"
#include "SSBattle.h"
#include "SSEffectMgr.h"
#include "SSPassiveSkillMgr.h"
#include "SSSkillEffect_Caculate.h"
namespace SceneServer{

CSSSkillEffect_Buf::CSSSkillEffect_Buf():m_tBeginDotMilsec(0)
	, m_pBufCfg(NULL)
	, m_bIfBuffAdded(FALSE)
	, m_passitiveSkillID(0)
	, m_repeatTimes(0)
{
	m_SkillEffectType = eSkillEffectType_Buf;
}

CSSSkillEffect_Buf::~CSSSkillEffect_Buf(){
}

const SSkillModelBufCfg* CSSSkillEffect_Buf::GetModelConfig(){
	return (const SSkillModelBufCfg*)m_pCfg;
}

INT32	CSSSkillEffect_Buf::Begin(){
	m_pBufCfg = (SSkillModelBufCfg*)m_pCfg;
	if (NULL == m_pBufCfg){
		return eEC_EffectEnd;
	}

	if(m_pBufCfg->eBuffTarget == eSBTC_Releaser){
		m_pcTarGU = m_pcMasterGO;
	}

	if(NULL == m_pcTarGU || m_pcTarGU->IsDead()){
		return eEC_EffectEnd;
	}

	if(FALSE == m_pcTarGU->CanAddBuf()){
		return eEC_EffectEnd;
	}

	if(FALSE == CheckHitTargetCamp(m_pcTarGU) || FALSE == CheckHitTargetType(m_pcTarGU)){
		return eEC_EffectEnd;
	}
	

	CSSSkillEffect_Buf* pSameBuf = NULL;//���ظ���buf
	INT32 n32SameBuffNum = 0;

	CSSSkillEffect_Buf* pRejectBuf = NULL;//�໥��ͻ��buf

	CSSSkillEffect_Buf* pReplaceBuf = NULL;//�Ḳ�ǵ�buf

	TIME_MILSEC tCurTime = GetUTCMiliSecond();

	for (UINT32* iter = m_pcTarGU->GetBufArr().Begin(); iter != m_pcTarGU->GetBufArr().End(); iter = m_pcTarGU->GetBufArr().Next()){
		CSSSkillEffect_Buf* pBuf = (CSSSkillEffect_Buf*)m_pcTarGU->GetCurBattle()->GetEffectMgr()->GetEffect(*iter);
		if (NULL != pBuf){
			SSkillModelBufCfg* pTempCfg = (SSkillModelBufCfg*)pBuf->m_pCfg;
			if (NULL == pTempCfg){
				m_pcTarGU->GetBufArr().RemoveElement(*iter);
				continue;
			}
			//��ȡ����(�ѵ�����ͻ������)buff������еĻ�
			if(pTempCfg->un32SkillModelID == m_pBufCfg->un32SkillModelID){
				n32SameBuffNum++;
				pSameBuf = pBuf;
			}
			if(m_pBufCfg->n32RejectId != 0 && pTempCfg->n32RejectId == m_pBufCfg->n32RejectId){
				pRejectBuf = pBuf;
			}
			if(m_pBufCfg->n32ReplaceId != 0 && pTempCfg->n32ReplaceId == m_pBufCfg->n32ReplaceId){
				pReplaceBuf = pBuf;
			}
		}
	}

	//����л����buff����buffʧЧ
	if(pRejectBuf != NULL){
		return eEC_EffectEnd;
	}

	if(pReplaceBuf != NULL){
		//����Ҫ���ǵ�buff�������ǵ�buffֱ���ս�
		pReplaceBuf->SetExpired();
	}
	//�������ͬ��buff
	else if(pSameBuf != NULL){
		//������ɶѵ����򷵻�
		if(m_pBufCfg->eReplaceType == EReplaceType_Forbit){
			return eEC_EffectEnd;
		}
		//���Ϊ����ʱ�����͵Ķѵ�
		else if(m_pBufCfg->eReplaceType == EReplaceType_Reset){
			//����ѵ�����δ�������ԭ��buff���Ч��
			if(pSameBuf->GetRepeateTimes() < m_pBufCfg->n32ReplaceTimes){
				pSameBuf->AddRepeatEffect();
			}
			//�����Ƿ�����˲���������Ҫ���ó���ʱ��
			pSameBuf->ResetTime();
			//��buffʧЧ����
			return eEC_EffectEnd;
		}
		//����Ǹ��Լ������ʱ��Ķѵ�
		else if(m_pBufCfg->eReplaceType == EReplaceType_SingleCaculate){
			//����ѵ��Ĵ����������ɶѵ�����������buffʧЧ
			if(m_pBufCfg->n32ReplaceTimes > 0 && n32SameBuffNum >= m_pBufCfg->n32ReplaceTimes){
				return eEC_EffectEnd;
			}
		}
		
	}

	m_tBeginDotMilsec = tCurTime - m_pBufCfg->n32EffectInterval;
	m_tBeginMilsec = tCurTime;

	if(FALSE == m_bIfBuffAdded){
		//���buffЧ��
		AddBuffEffect(FALSE);
		//��buff���뵽�����buff�б���ȥ
		m_pcTarGU->AddBuf(GetUniqueID());
		//buff��Ϊ���������Ұ���󣬼��뵽��Ұϵͳ��
		m_pcTarGU->GetCurBattle()->AddChildSightObject(m_pcTarGU, this);
	}
	
	m_pcTarGU->GetCurBattle()->GetEffectMgr()->AddEffectsFromCfg(m_pBufCfg->asSkillStartModelList
		, m_pcMasterGO, m_pcTarGU, m_pcTarGU->GetCurPos(),  m_pcTarGU->GetCurDir() - m_pcMasterGO->GetCurDir(), m_pSkillRuntimeData, tCurTime);
	return eNormal;
}

void CSSSkillEffect_Buf::AddRepeatEffect(){
	//���buffЧ��
	AddBuffEffect(TRUE);
}

void CSSSkillEffect_Buf::AddBuffEffect(bool bIfRepeat){
	m_bIfBuffAdded = TRUE;
	if(m_pBufCfg->sEffectInfo.eEffectCate != eEffectCate_None){
		//���buff����Ϊ���������������ϱ�������
		if(eEffectCAte_PassitiveSkill == m_pBufCfg->sEffectInfo.eEffectCate){
			if(FALSE == bIfRepeat){//����ֻ�����һ��
				m_passitiveSkillID = GetBattle()->GetPassiveSkillMgr()->AddPassiveSkill(m_pcTarGU,m_pBufCfg->sEffectInfo.n32EffectBaseValue);
			}
		}
		//������Ǳ������ܣ����������϶�Ӧ������
		else{
			INT32 n32OriVal = m_pcTarGU->GetFPData(m_pBufCfg->sEffectInfo.eEffectCate);
			CSSSkillEffect_Caculate::CaculateSkillEffectOnce(m_pcMasterGO, m_pcTarGU, m_pBufCfg->sEffectInfo, 0); 
			m_repeatTimes++;//�ѵ�����+1
		}
	}
}

INT32 CSSSkillEffect_Buf::Update(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan){
	if (m_ifExpired){
		return eEC_EffectEnd;
	}

	if(m_tBeginMilsec + m_pBufCfg->n32EffectLastTick <= tUTCMilsec){
		return eEC_EffectEnd;
	}

	if(NULL == m_pcTarGU){
		return eEC_EffectEnd;
	}
	//�����Ӣ�۵�NPC�����ˣ���ʩ�ŵ�buffҪ�Ƴ�
	if( m_pcMasterGO->IsDead() && FALSE == m_pcMasterGO->IfHero() ){
		return eEC_EffectEnd;
	}
	//Ŀ��������������Ϊ���������buff(�󲿷�buff����)�������
	if(m_pcTarGU->IsDead() && TRUE == m_pBufCfg->bIfClearAtDie){
		return eEC_EffectEnd;
	}
	//ÿ����ʱ��㣬�͵���һ��dotЧ��
	if(m_pBufCfg->n32EffectInterval > 0 && m_tBeginDotMilsec + m_pBufCfg->n32EffectInterval <= tUTCMilsec){
		m_tBeginDotMilsec += m_pBufCfg->n32EffectInterval;
		GetBattle()->GetEffectMgr()->AddEffectsFromCfg(m_pBufCfg->asSkillIntervalModelList, m_pcMasterGO, m_pcTarGU, m_pcTarGU->GetCurPos()
			, m_pcTarGU->GetCurDir(), m_pSkillRuntimeData, tUTCMilsec);
	}

	return eNormal;
} 

INT32	CSSSkillEffect_Buf::End(){
	if (FALSE == m_bIfBuffAdded){
		return eEC_EffectEnd;
	}
	m_bIfBuffAdded = FALSE;

	if(NULL == m_pcTarGU){
		return eEC_EffectEnd;
	}
	//buf������ʱ�򣬵��ý���ʱ���ģ��(�󲿷�buff��ľ��)
	GetBattle()->GetEffectMgr()->AddEffectsFromCfg(m_pBufCfg->asSkillEndModelList, m_pcMasterGO, m_pcTarGU, m_pcTarGU->GetCurPos()
		, m_pcTarGU->GetCurDir(), m_pSkillRuntimeData, GetUTCMiliSecond());

	if(m_pBufCfg->sEffectInfo.eEffectCate != eEffectCate_None){
		//����Ǳ���Ч����buff����Ҫ�������Ӷ��������Ƴ�
		if(eEffectCAte_PassitiveSkill == m_pBufCfg->sEffectInfo.eEffectCate){
			if(m_passitiveSkillID > 0){
				GetBattle()->GetPassiveSkillMgr()->RevmovePassiveSkill(m_passitiveSkillID);
				m_passitiveSkillID = 0;
			}
		}
		//������Ǳ���Ч��������Ҫ����ӵ����ԴӶ������Ƴ�
		else{
			//����˶��ٴ����ԣ�����Ҫ�Ƴ����ٴ�
			for(int i=0;i<m_repeatTimes;i++){
				CSSSkillEffect_Caculate::CaculateSkillEffectOnce(m_pcMasterGO, m_pcTarGU, m_pBufCfg->sEffectInfo, 0,FALSE,FALSE);
			}
		}
	}
	//�Ӷ��������Ƴ�buff��ID
	// ע�⣺������ʱ��˵����tar����ɾ�ģ�������ж��
	m_pcTarGU->RemoveBuf(m_un32UniqueID);
	//����Ұϵͳ���Ƴ�buff����Ұ
	GetBattle()->RemoveChildSightObject(m_pcTarGU, this);

	return eNormal;
}
void CSSSkillEffect_Buf::Clear(){
	End();
}

void CSSSkillEffect_Buf::ResetTime(){
	m_tBeginMilsec = GetUTCMiliSecond();
}

//����buff����Ұ�г��ֵ���Ϣ
void CSSSkillEffect_Buf::OnAppearInSight(std::vector<CSSUser*>& cTempUserMap){
	if(NULL == m_pcTarGU || NULL == m_pcMasterGO){
		return;
	}

	GSToGC::BuffEffect sMsg;
	sMsg.set_guid(m_pcMasterGO->GetObjGUID());
	sMsg.set_uniqueid(m_un32UniqueID);
	sMsg.set_effectid(m_pCfg->un32SkillModelID);
	sMsg.set_time(GetUTCMiliSecond() - m_tBeginDotMilsec - m_pBufCfg->n32EffectInterval);
	sMsg.set_state(EBuffMsgStatus_Start);
	if (m_pcTarGU){
		sMsg.set_targuid(m_pcTarGU->GetObjGUID());
	}
	
	m_pcTarGU->GetCurBattle()->SendMsgToWatchers(sMsg, sMsg.msgid(), cTempUserMap);
}
//����buff����Ұ����ʧ����Ϣ
void CSSSkillEffect_Buf::OnDisappearInSight(std::vector<CSSUser*>& cTempUserMap){
	if(NULL == m_pcTarGU || NULL == m_pcMasterGO){
		return;
	}

	GSToGC::BuffEffect sMsg;
	sMsg.set_guid(m_pcMasterGO->GetObjGUID());
	sMsg.set_uniqueid(m_un32UniqueID);
	sMsg.set_effectid(m_pCfg->un32SkillModelID);
	sMsg.set_time(GetUTCMiliSecond() - m_tBeginDotMilsec - m_pBufCfg->n32EffectInterval);
	sMsg.set_state(EBuffMsgStatus_End);
	if (m_pcTarGU){
		sMsg.set_targuid(m_pcTarGU->GetObjGUID());
	}

	m_pcTarGU->GetCurBattle()->SendMsgToWatchers(sMsg, sMsg.msgid(), cTempUserMap);
}

float CSSSkillEffect_Buf::GetSightPosX(){
	if(NULL == m_pcTarGU){
		return 0;
	}
	return m_pcTarGU->GetCurPos().m_fX;
}
float CSSSkillEffect_Buf::GetSightPosY(){
	if(NULL == m_pcTarGU){
		return 0;
	}
	return m_pcTarGU->GetCurPos().m_fZ;
}

CVector3D CSSSkillEffect_Buf::GetCurPos(){
	if(NULL == m_pcTarGU){
		return CVector3D();
	}
	return m_pcTarGU->GetCurPos();
}

bool CSSSkillEffect_Buf::IfParaInvalid(){
	return TRUE == IsForceStop();
}

void CSSSkillEffect_Buf::SetExpired(){
	m_ifExpired = true;
}

}