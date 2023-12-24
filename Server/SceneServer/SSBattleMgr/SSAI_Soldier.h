/*
* file name			:SSAI_Soldier.h
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
	class CSSSoldier;
	class CSSNPC;

	class CSSAI_Soldier : public CSSAI
	{
	private:
		enum	EOccupyState{
			eOccupyState_Walk,
			eOccupyState_Attack,
			eOccupyState_Back
		};
		EOccupyState			m_eOccupyState;//Ѳ��״̬

		CSSNPC*					m_pcSoldierGU;	//С��

		CVector3D				m_acOrderPath[c_n32MaxOrderPathNode];//Ѱ·�ڵ�
		INT32					m_n32NodeNum;//�ڵ�����
		INT32					m_n32CurNodeIdx;//��ǰ���е���·�����

		bool					m_ifNeedRestartMove;//�Ƿ���Ҫ���¿�ʼ�ƶ�
		CVector3D				m_cStartAttackPos;//��ʼ���й���ʱ������λ��
		CVector3D				m_cBackToLinePos;//�ص����ϵ�Ŀ���
		TIME_TICK				m_tLastWatchEnemyMilsec;//�ϴμ��Ŀ���ʱ��
		bool					m_ifAttackTarDead;//�Ƿ񹥻�Ŀ��������

		void					SetNowPathIndex(INT32 index){m_n32CurNodeIdx = index;if (m_n32CurNodeIdx >= m_n32NodeNum)m_n32CurNodeIdx = m_n32NodeNum - 1;}
		void					SetAttackTarget(CSSGameUnit* pTarget);
		bool					IfPointNearPath(CVector3D cPoint, CVector3D cPath1, CVector3D cPath2, float &distSqrt, CVector3D &nearesatPoint);
	protected:

	public:
		~CSSAI_Soldier(){}
		CSSAI_Soldier(CSSGameUnit* pGU);

		void				SetOccupyPath(std::vector<CVector3D> & pathNode);//(const CVector3D *cpcPathNode, UINT32 un32NodeNum);
		INT32				HeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan);
	};

}