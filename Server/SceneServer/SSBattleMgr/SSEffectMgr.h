/*
* file name			:SSSkillMng.h
* file mark			:
* summary			:
*
* version			:1.0
* author			:LiuLu
* complete date		:May 27 2014
* summary			:
*
*/

#ifndef __SSSkillMng_h__
#define __SSSkillMng_h__

#include "stdafx.h"
#include "SSObjectPool.h"

namespace SceneServer{

class CSSSkillEffect;
class CSSSkillEffect_Caculate;
class CSSSkillEffect_Fly;
class CSSSkillEffect_Leading;
class CSSSkillEffect_Range;
class CSSSkillEffect_Buf;
class CSSSkillEffect_Summon;
class CSSSkillEffect_Move;
class CSSkillModel_Switch;
class CSSArea;
class CSSBattleMgr;
class CSSSkill;

enum E_SynEffect{
	E_SynEffect_Appear,
	E_SynEffect_DisAppear,
	E_SynEffect_Max
};

class CSSEffectMgr
{
public:
	typedef std::map<UINT32, CSSSkillEffect*>		EffectMap;
private:
	EffectMap								m_WaitingEffectMap;//���еȴ�ִ�е�Ч���б�
	EffectMap								m_UpdateEffectMap;//����ִ���е�Ч���б�
public:
	CSSEffectMgr();
	~CSSEffectMgr();
public:
	CSSBattleMgr*				m_pCSSBattleMgr;//ս��������
	CSSBattle*					m_pCSSBattle;
	void						SetBattleMgr(CSSBattleMgr* pMgr,CSSBattle* pBattle);
public:
	INT32				OnHeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan);
	INT32				AddEffectsFromCfg(SSNextSkillEffectCfg* pEffectCfg, CSSGameUnit* pMaster, CSSGameUnit* pTarget, CVector3D cPos
		, CVector3D cDir, CSSSkill* pSkill, TIME_MILSEC beginTime,CSSGameUnit* pStartSkillGU = NULL);//�������ô���һ���µ�Ч����һ���ڼ���������Ч�����ñ��Ч����ʱ��ʹ��
	INT32				UseSkillDirect(UINT32 un32SkillID, CSSGameUnit* pReleaser, CSSGameUnit* pTarget);//��������ϵͳ��ֱ�����һ��Ч��
	void				Clear();

	CSSSkillEffect*		GetEffect(UINT32 un32EffectUniqueID);
	INT32				RemoveEffect(UINT32 un32EffectUniqueID);
	void				RemoveAllEffectBySkillID(INT32 skillID);
	INT32				DirectAddBuff(INT32 n32BuffEffectId, CSSGameUnit* pReleaser, CSSGameUnit* pTarget);//��������ϵͳ��ֱ�����һ��buff
	
	static bool			CanEffectBeTriggered(std::default_random_engine& egine, INT32 n32TriggerRate, INT32 n32TriggerBase = 1000);//�жϼ��ʴ�����Ч���Ƿ��ܹ�����ɹ�����
	EffectMap&			GetEffectMap();

private:
	INT32				AddEffect(CSSSkillEffect* pEffect);
	CSSSkillEffect*		CreateSkillEffect(INT32 n32SkillEffectId);//����һ��Ч����ʵ���������丸���ָ��
	INT32				DestroyAFreeSkillEffect(CSSSkillEffect* pcEffect);//����Ч��
};

}

#endif