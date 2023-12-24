/*
* file name			:SSAI_Wild.h
* file mark			:
* summary			:
*
* version			:1.0
* author			:LiuLu
* complete date		:Octorber 13 2014
* summary			:
*
*/

#pragma once

#include "stdafx.h"
#include "SSAI.h"
#include "SSGameUnit.h"

namespace SceneServer{
	class CSSSkill;
	class CSSNPC;

	class CSSAI_Wild : public CSSAI
	{
	private:
		bool					m_ifAIRunning;

		enum	EGuardState{
			eGuardState_Sleep,
			eGuardState_Attack,
			eGuardState_WalkBack, 
		};
		EGuardState				m_eGuardState;//����״̬

		CSSNPC*					m_pcWildGU;	//Ұ��

		//CVector3D				m_cStartPos;//������

		//Ѱ�ҷ��Ϲ��������ĵ���
		CSSGameUnit*			LookForEnemy();

	protected:

	public:
		virtual ~CSSAI_Wild(){}
		CSSAI_Wild(CSSGameUnit* pGU);

		void				StopAI();
		void				ResumeAI(){m_ifAIRunning = TRUE;}
		INT32				HeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan);
	};

}