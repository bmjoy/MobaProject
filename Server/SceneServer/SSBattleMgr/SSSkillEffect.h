/*
* file name			:SSSkillModel.h
* file mark			:
* summary			:
*
* version			:1.0
* author			:LiuLu
* complete date		:May 28 2014
* summary			:
*
*/
#pragma once

#include "stdafx.h"
#include <map>
#include "SafeRefPtr.h"
#include "SSSkill.h"

namespace SceneServer{

class CSSGameUnit;
class CSSBattleMgr;

//����Ч���ĸ���
class CSSSkillEffect : public referable<CSSSkillEffect>
{
public:
	ESkillEffectType			m_SkillEffectType;//Ч������
	ref_ptr<CSSSkill>			m_pSkillRuntimeData;//���ܵ�ָ��
	const SSkillEffectlBaseCfg*	m_pCfg;//Ч������
	INT32						m_EffectDelayTime;//Ч���ĵȴ�ʱ��
	ref_ptr<CSSGameUnit>		m_pcMasterGO;//���ܵ�ӵ����
	ref_ptr<CSSGameUnit>		m_pcStartSkillGU;//Ч�����ĸ������������Aʹ�ü��ܣ�����B����B���ϳ���һ��Ч������C��Ч����ô����ĳ��������B
	TIME_MILSEC					m_tBeginMilsec;//Ч���Ŀ�ʼʱ��
	ref_ptr<CSSGameUnit>		m_pcTarGU;//Ч����Ŀ�����
	CVector3D					m_cDir;//����
	CVector3D					m_cPos;//λ��
	ref_ptr<CSSSkillEffect>		m_lDependEffect[c_n32MaxDependSkillEffectCfgNum];//�����Լ���Ч��ָ��
	bool						m_IsForceStop;//Ч���Ƿ�ǿ����ֹ��
	UINT32						m_un32UniqueID;//ΨһID
	CSSBattle*					m_pBattle;//ս����ָ��
	bool						m_ifExpired;
public:
	CSSBattleMgr*				m_pCSSBattleMgr;
	void						SetBattleMgr(CSSBattleMgr* pMgr);
	virtual		void			Clean();
protected:
	bool						CheckHitTargetType(CSSGameUnit* pTarget);//�������ö�������(Ӣ�ۣ�NPC������)
	bool						CheckHitTargetCamp(CSSGameUnit* pTarget);//�������ö�����Ӫ
	void						OnSkillHitTarget(CSSGameUnit* pTarget);//�������д���
 
public:
	// the following fun should not be overrided
	INT32						CheckCooldown();//����Ƿ񴥷���ȴ
	bool						IfNeedWait(TIME_MILSEC tUTCMilsec);//�ж��Ƿ���Ҫ�ȴ���ʼ
	INT32						Clear();
	bool						IsForceStop();
	INT32						ForceStop();//ǿ��ֹͣ
	virtual bool				IsUsingSkill(){return FALSE;}//Ч���Ƿ��ǳ���������
	virtual bool				IsCanStopUsing(){return TRUE;}//���������Ƿ���Ա��ж�
	virtual bool				IfCanMove(){return TRUE;}//�ƶ������Ƿ�����ƶ�
	INT32						StopDependedEffect();//ֹͣ�������Լ���Ч����
	virtual bool				IsNeedSync(){return FALSE;}
	INT32						AddSelfToUsingList();//���Լ����뵽���������б���
	UINT32						GetUniqueID(){return m_un32UniqueID;}
	virtual void				SetExpired(){m_ifExpired = true;}
public:
	virtual	INT32				Begin() = 0;
	virtual INT32				Update(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan) = 0;
	virtual	INT32				End() = 0;
	virtual CVector3D			GetCurPos(){return CVector3D();}
	bool						CheckBattle();
	CSSBattle*					GetBattle();
	virtual bool				IfParaInvalid();
	
	CSSSkillEffect();
	virtual ~CSSSkillEffect() ;
};

}