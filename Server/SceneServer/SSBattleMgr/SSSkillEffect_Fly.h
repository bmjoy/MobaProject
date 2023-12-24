/*
* file name			:SSSkillModel_Emit.h
* file mark			:
* summary			:
*
* version			:1.0
* author			:LiuLu
* complete date		:May 29 2014
* summary			:
*
*/
#pragma once

#include "stdafx.h"
#include "SSSkillEffect.h"
#include "SSElementArr.h"
#include "SafeRefPtr.h"

namespace SceneServer{

class CSSSkillEffect_Fly : public CSSSkillEffect
{
private:
	//���ж���ʵ�壬���ڱ�����ж����״̬
	struct SSEmitEntity{
		SGUID_KEY		sTargetGUID;
		ref_ptr<CSSGameUnit>	pcTargetGU;
		CVector3D		cCurPos;
		CVector3D		cCurDir;
		TIME_MILSEC		tLaunchUTCMilsec;
		bool			bIfEnded;
		INT32			n32ProjectID;
		TIME_MILSEC		tLastEffectTime;
		bool			bIfTurnBack;
		ElementArr<SGUID_KEY, 32> lHitTargetsArr;

		SSEmitEntity(): sTargetGUID(0)
			, pcTargetGU(NULL)
			, cCurPos(0,0,0)
			, cCurDir(0,0,0)
			, tLaunchUTCMilsec(0)
			, bIfEnded(FALSE)
			, n32ProjectID(0)
			, tLastEffectTime(0)
			, bIfTurnBack(FALSE)
		{}

		void Clear(){
			lHitTargetsArr.Clear();
		}
	};

	ElementArr<SSEmitEntity, 16> m_lEmitEntityArr;//���������б����16��

	struct SSEmitHitTargetInfo{
		ref_ptr<CSSGameUnit>	pTarget;
		CVector3D		cPos;
		CVector3D		cDir;
	};

	ElementArr<SSEmitHitTargetInfo,12> m_lEmitHitTargetArr;

public:
	CSSSkillEffect_Fly();
	~CSSSkillEffect_Fly();

private:
	INT32						OnHeartBeat_CheckSimpleSkillEntityImpact(SSEmitEntity *rsSSE, TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan);
	const SSkillModelEmitCfg*	GetModelConfig();
	INT32						NotifyNewEmitObjectToGC(CSSGameUnit* pStartGU, SSEmitEntity* pSSE);
	INT32						NotifyDestoryEmitObjectToGC(SSEmitEntity* pSSE);
	INT32						NotifyTurnEmitObjectToGC(SSEmitEntity* pSSE);
	INT32						CheckSimpleSkillEntityImpact(SSEmitEntity* rsSSE, float fDist, vector<CSSGameUnit*>* pTargetList, bool bIsPenetrate, bool bIfCanRepeat);//���һ������Ŀ���Ƿ������˭��
	CSSGameUnit*				FindNextBounceTarget(SSEmitEntity* pSSE, CSSGameUnit* exceptGU, bool bIfCanRepeat);//Ѱ����һ����������

public:
	virtual	INT32				Begin();
	INT32						Update(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan);
	virtual INT32				End();
	virtual bool				IfParaInvalid();
};

}