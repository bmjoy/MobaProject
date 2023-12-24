/*
* file name			:SSAI_Hero.h
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
#include "SSAI.h"
#include "SSGameUnit.h"

namespace SceneServer{
	class CSSSkill;
	class CSSHero;
	class CSSNPC;

	class CSSAI_Hero : public CSSAI
	{
	private:
		CSSHero*			m_pcHeroGU;	//Ӣ��

		bool				m_ifMoveDir;//�Ƿ����ֶ��ƶ���
		//�Զ�������ص�����
		bool				m_ifAutoAttack;
		CSSSkill*			m_pNowSkill;
		//�Զ�ʩ�ż������
		CSSSkill*			m_pWantUseSkill;//ϣ��ʹ�õļ���
		CSSSkill*			m_nextSkill;//Ԥ��ʹ�õ���һ������

		//������ص�����
		bool				m_ifAbsorb;
		ref_ptr<CSSGameUnit>	m_pcAbsorbNPC;//������Ŀ��
		INT32				m_n32ToRemoveAbsorbIndex;//��Ҫ���Ƴ������������
		TIME_MILSEC			m_tStartAbsorbTime;//��ʼ������ʱ��
		bool				m_ifStandAttack;//�Ƿ���վ���Զ�������
		INT32				AbsorbHeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan);
		INT32				WantUseSkillHeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan);
		INT32				UseSkillHeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan);
		void				TryCancleAbsorb();		INT32				CheckAttackTarget();
		INT32				TryUseSkillWithAnyType(CSSSkill* pSkill);
		void				StopWantUseSkill(BOOLEAN ifStopMove = TRUE);
		bool				StopAllSkill(bool bIfForceStop = FALSE);

	protected:
		void				ClearAction();
		virtual	void		DoStandNormalAttack(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan);
	public:
		virtual ~CSSAI_Hero();
		CSSAI_Hero(CSSGameUnit* pGU);

		INT32				HeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan);

		INT32				AskMoveDir(const CVector3D &crcDir);
		INT32				AskMoveTar(const CVector3D &crcPos);
		INT32				AskStopMove();
		INT32				AskStartAutoAttack();

		INT32				AskUseSkill(UINT32 un32SkillID);
		INT32				AskAbsorbMonster(INT32 n32ToRemoveIndex);
		INT32				AskGasExpersion();

		bool				IfAbsorbing(){return m_ifAbsorb;}
		bool				IfAutoAttacking(){return m_ifAutoAttack;}
		bool				IfUsingSkill(){return NULL != m_pNowSkill && TRUE == m_pNowSkill->ifRunning;}

		CSSHero*			GetHero(){return m_pcHeroGU;}
		CSSSkill*			GetNowSkill(){return m_pNowSkill;}
		INT32				GetAbsorbCost(CSSNPC *sspNPC);

		virtual void		OnTeleport();
	};

}