/*
* file name			:SSAI.h
* file mark			:
* summary			:
*
* version			:1.0
* author			:LiuLu
* complete date		:Octorber 9 2014
* summary			:
*
*/

#pragma once

#include "stdafx.h"

namespace SceneServer{

	class CSSGameUnit;
	class CSSSkill;

	class CSSAI
	{
	private:
		ref_ptr<CSSGameUnit>		m_pcAttackGU;//�Զ�������Ŀ��
	protected:
		ref_ptr<CSSGameUnit>	m_pcMasterGU;//AI��ӵ����
		bool					m_ifMoving;//�Ƿ������ƶ���
		CSSSkill*				m_pAttackSkill;

		bool					IfPassitiveState();
		void					MoveToTar(CVector3D pos, bool ifMoveToBlackPoint, TIME_TICK nowTime);

		//�Զ�������ر����ͺ���
		enum EAttackState{
			eAttackState_Pursue,
			eAttackState_UseSkill,
		};
		EAttackState m_eAttackState;

		TIME_TICK					m_tLastTryMoveTime;//�ϴγ����ƶ�ʧ�ܵ�ʱ��
		CVector3D					m_pcMoveTarPos;//��ǰǰ����Ŀ���ַ
		TIME_TICK					m_tLastCheckMoveTarTime;//��һ�μ��Ŀ�������ʱ��
		bool						m_bIfFliter;
		

		
		void	SetAttackGU(CSSGameUnit* pcAttackGU);
		INT32	AttackHeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan);
		void	StopAttack();
		void	CancleAttack();
		void	TryFree();
	public:
		virtual	~CSSAI();
		CSSAI(CSSGameUnit* pMaster);
		void						SetNormalAttackSkill(CSSSkill* pAttackSkill){m_pAttackSkill = pAttackSkill;}
		CSSSkill*					GetNormalAttackSkill(){return m_pAttackSkill;}
		virtual void				OnMoveBlock();
		bool						IfMoving(){return m_ifMoving;}
		bool						IfAttacking();
		CSSGameUnit*				GetAttackGU(){return m_pcAttackGU;}
		virtual INT32				HeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan) = 0;
		virtual void				OnTeleport(){}
	};

}