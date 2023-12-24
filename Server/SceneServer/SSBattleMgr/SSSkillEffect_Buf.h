#pragma once

#include "stdafx.h"
#include "SSSkillEffect.h"
#include "SSightObject.h"
 

namespace SceneServer{

enum EBuffMsgStatus{
	EBuffMsgStatus_Start = 0,
	EBuffMsgStatus_End,
	EBuffMsgStatus_Fail,
};

class CSSSkillEffect_Buf : public CSSSkillEffect, public ISSightObject
{
private:  
	TIME_MILSEC					m_tBeginDotMilsec;//buf��ʼʱ��
	bool						m_bIfBuffAdded; //buf�Ƿ���Ч
	SSkillModelBufCfg*			m_pBufCfg;
	INT32						m_passitiveSkillID;//��������ID��buf������������Ч������ID��¼������ر�
	INT32						m_repeatTimes;//�ѵ�����
	const SSkillModelBufCfg*	GetModelConfig();

 
public:
	CSSSkillEffect_Buf();
	~CSSSkillEffect_Buf();

	virtual	INT32				Begin();
	virtual INT32				End();
	virtual INT32				Update(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan); 
	virtual bool				IsNeedSync(){return TRUE;}
	virtual bool				IfParaInvalid();
	void						Clear();
	CVector3D					GetCurPos();
	void						ResetTime();
	virtual void					OnAppearInSight(std::vector<CSSUser*>& cTempUserMap);
	virtual void					OnDisappearInSight(std::vector<CSSUser*>& cTempUserMap);
	virtual float					GetSightPosX();
	virtual float					GetSightPosY();
	virtual ESSSightObjectType	GetSightObjectType(){return ESSSightObjectType_Insensitive;}
	virtual void				SetExpired();
	INT32						GetRepeateTimes(){return m_repeatTimes;}
	void						AddRepeatEffect();
	void						AddBuffEffect(bool bIfRepeat);
};

}
