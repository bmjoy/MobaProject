/*
* file name			:SSAI_HeroRobot.h
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
#include "SSAI_Hero.h"
#include "SSGameUnit.h"

namespace SceneServer{
	class CSSHero;
	class CSSBTreeNode;

	const static INT32 c_transHomeSkillID = 100001;

	class CSSAI_HeroRobot : public CSSAI_Hero
	{
	private:
		CSSHero*			m_pcHeroGU;	//Ӣ��
		CSSBTreeNode*		m_pBTreeRoot;
		bool				m_bIfMoveByPath;//�Ƿ����ڰ�·���ƶ�
		vector<vector<CVector3D>> m_path;//·��
		UINT8				m_un8ChoosedPath;//��ѡ·�����
		UINT16				m_un16PathIndex;//��ǰ·���ڵ�
		bool				m_bIfPathForward;//·���Ƿ�����ǰ��
		CVector3D			m_pathPos;//��ǰ·��Ŀ��
		vector<CSSSkill*>	m_skillVec;//Ӣ�ۼ�����ʱ�洢�ռ�
		UINT16				m_buyItemIndex;//׼���������Ʒ���
		INT32				m_startWaitTime;//��Ϸ��ʼʱ�ĵȴ�ʱ��
		TIME_MILSEC			m_tActionTime;//���һ����������ʱ��

		CSSBTreeNode*		CreateTreeNode(INT32 ID, INT32 type, INT32 modelID, INT32 parameters[16]);
		CSSBTreeNode*		CreateCondition(INT32 ID, INT32 modelID, INT32 parameters[16]);
		CSSBTreeNode*		CreateAction(INT32 ID, INT32 modelID, INT32 parameters[16]);
	protected:
		virtual	void		DoStandNormalAttack(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan){};
	public:
		virtual ~CSSAI_HeroRobot();
		CSSAI_HeroRobot(CSSGameUnit* pGU,ERobotAIType eAiType);


		vector<CSSSkill*>*	GetSkillVec(){return &m_skillVec;}
		CSSSkill*			GetPrepareSkill(){return m_skillVec.empty()?NULL:m_skillVec[0];}
		vector<vector<CVector3D>>& GetPathVec(){return m_path;}
		bool				MoveByPath(INT32 pathIndex, INT32 nodeIndex, bool moveForward);
		INT32				Random(INT32 start, INT32 end);
		UINT16				GetNextBuyItemIndex(){return m_buyItemIndex;}
		void				OnBoughtOneItem(){m_buyItemIndex++;}
		INT32				GetStartWaitTime(){return m_startWaitTime;}
		VOID				SetStartWaitTime(INT32 time){m_startWaitTime = time;}
		TIME_MILSEC			GetLastActionTime(){return m_tActionTime;}
		VOID				SetLastActionTime(TIME_MILSEC time){m_tActionTime = time;}
		INT32				HeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan);

		virtual void		OnMoveBlock();
	};

}