/*
* file name			:SSMoveObject.h
* file mark			:
* summary			:
*
* version			:1.0
* author			:LiuLu
* complete date		:Auguest 6 2014
* summary			:
*
*/

#ifndef __ISSMoveObject_h__
#define __ISSMoveObject_h__

#include "stdafx.h"
#include "SSIntersectObject.h"

namespace SceneServer{

enum SSMoveObjectMoveType{
	SSMoveObjectMoveType_None,
	SSMoveObjectMoveType_Dir,
	SSMoveObjectMoveType_Tar,
	SSMoveObjectMoveType_ForceMove,
};

enum SSMoveObjectStatus{
	SSMoveObjectStatus_None,
	SSMoveObjectStatus_Stand,
	SSMoveObjectStatus_Move,
	SSMoveObjectStatus_ForceMove,
};

enum SSMoveObjectImpactType
{
	SSMoveObjectImpactType_Undefined = -1,
	SSMoveObjectImpactType_NoImpact = 0,
	SSMoveObjectImpactType_Group,
	SSMoveObjectImpactType_ALL,//Ұ�֡�����ȫ��ײ//
};

enum SSImpactGruop
{
	SSImpactGruop_None,//Ĭ��//
	SSImpactGruop_Hero,
	SSImpactGruop_Solider,
	SSImpactGruop_Zhuzi,
	SSImpactGruop_Wild,//Ұ�֣�ֻ��ͬ������ײ
	SSImpactGruop_All,//����ȫ��ײ//
};

class ISSMoveObject
{
private:
	SSMoveObjectImpactType	m_savedImpactType; //�������ײ����
	SSMoveObjectStatus	m_moveStatus;//�ƶ�״̬(ֹͣ���ƶ���)
	SSMoveObjectMoveType m_moveType;//�ƶ����ͣ�����Ѱ·��ǿ�ƣ�
	UINT8				m_grpID;//��ID
	TIME_MILSEC			m_startMoveTime;//��ʼ�ƶ�ʱ��
	TIME_MILSEC			m_lastFailStartTime;//�ϴγ����ƶ�ʧ��ʱ��
	FLOAT				m_oldSpeed;//������ٶ�
	bool				m_bIfSpeedChanged;//�Ƿ������ٶȸı�
	FLOAT				m_forceMoveSpeed;//ǿ��λ���ٶ�
	ColVector			m_askMoveDir;//�����ƶ��ķ���
	TIME_MILSEC			m_redirectTime;//�ϴγ����Զ�ת��ʱ��
	ColVector			m_dir;//ʵ���ƶ�����
	ColSphere			m_stepMoveTarget;//�Զ�Ѱ·��ǰ�ƶ�Ŀ��
	ColVector			m_beforeMovePos;//��һ��λ�Ƶ�����
	SIntPoint			m_asPathCell[c_n32MaxOrderPathNode];//�Զ�Ѱ·��·����
	UINT16				m_pathLength;//�Զ�Ѱ··������
	UINT16				m_moveStep;//�Զ�Ѱ·��ǰ�������к�
	bool				m_ifStepMoved;//δʹ��
	bool				m_ifForceMoveImpact;//ǿ��λ���Ƿ���Ҫ�����ײ


public:
	ISSMoveObject():m_moveType(SSMoveObjectMoveType_None)
		, m_moveStatus(SSMoveObjectStatus_None)
		, m_savedImpactType(SSMoveObjectImpactType_Undefined)
		, m_grpID(SSImpactGruop_None)
		, m_startMoveTime(0)
		, m_lastFailStartTime(0)
		, m_oldSpeed(0.0f)
		, m_bIfSpeedChanged(FALSE)
		, m_forceMoveSpeed(0.0f)
		, m_pathLength(0)
		, m_moveStep(0)
		, m_ifStepMoved(FALSE)
		, m_ifForceMoveImpact(FALSE){
		for (int i = 0; i < c_n32MaxOrderPathNode; ++i){
			m_asPathCell[i].Clear();
		}
	}
	virtual ~ISSMoveObject(){}

	//��ȡ���ݵĳ���ӿ�
	virtual bool				IfCanImpact() = 0;
	virtual ColSphere			GetColSphere() = 0;
	virtual ColVector			GetColVector() = 0;
	virtual INT16				GetColRadius() = 0;
	virtual FLOAT				GetSpeed() = 0;
	virtual SSMoveObjectImpactType		GetImpactType() = 0;

	//�����¼�֪ͨ�ĳ���ӿ�
	virtual void				OnStartMove(ColVector dir) = 0;
	virtual void				OnMoved(ColVector pos) = 0;
	virtual void				OnMoveBlock() = 0;
	virtual void				OnChangeDir(ColVector dir) = 0;

	bool						IfStart;


	//�߼�����
	void				AddMoveStep(){++m_moveStep;}
	//��ȡ��ǰ�Զ�Ѱ·λ�Ƶ�Ŀ���
	bool				GetNowMoveIntTar(SIntPoint &point){
		if(m_moveStep >= m_pathLength)
			return FALSE;

		point = m_asPathCell[m_moveStep];
		return TRUE;
	}
	//����ʱ����㽫Ҫ����ĵ������
	void				CalculateStepMoveTarget(TIME_MILSEC now){
		INT64 timeDiff = now - GetStartMoveTime();
		if(timeDiff > 500) 
			timeDiff = 500;
		if (timeDiff <= 0){
			//ELOG(LOG_WARNNING, "timeDiff:%lld", timeDiff);
			timeDiff = 0;
		}
		FLOAT speed = (m_moveStatus == SSMoveObjectStatus_ForceMove) ? m_forceMoveSpeed : GetSpeed();
		if(speed != m_oldSpeed){
			m_oldSpeed = speed;
			m_bIfSpeedChanged = TRUE;
		}
		ColVector moveVec = GetDir() * speed * timeDiff;
		float moveDist = moveVec.Length();
		if(moveDist > 200){
			int abc = 0;
		}
		ColSphere sph = GetColSphere();
		sph.c = sph.c + moveVec;
		Assert(sph.c.x < 100000 && sph.c.y < 100000 && sph.c.x > 0 && sph.c.y > 0);
		SetStepMoveTarget(sph);
	}
	//λ�ơ���λ���Ѿ���������֤������ֱ���ƶ�����
	FLOAT				Move(TIME_MILSEC now){
		SetBeforeMovePos(GetColVector());
		ColSphere sph = GetStepMoveTarget();
		FLOAT dist = (sph.c - GetBeforeMovePos()).Length();
		OnMoved(sph.c);
		SetStartMoveTime(now);
		SetStepMoved(TRUE);
		if(m_bIfSpeedChanged){
			m_bIfSpeedChanged = FALSE;
			OnStartMove(GetDir());
		}
		return dist;
	}
	//���ͣ���λ�ƻ�����ͬ�����ǲ������ƶ���������λ�ƵĻص�
	void				Teleport(TIME_MILSEC now){
		ColSphere sph = GetStepMoveTarget();
		SetBeforeMovePos(sph.c);
		OnMoved(sph.c);
		SetStartMoveTime(now);
	}
	//ֹͣ�ƶ������ص�ֹͣ�Ľӿ�
	void				Stop(TIME_MILSEC now, bool ifNeedCallBack = TRUE){
		SetMoveStatus(SSMoveObjectStatus_Stand);
		SetLastFailStartTime(now);
		ColSphere nowPos = GetColSphere();
		SetStepMoveTarget(nowPos);
		SetBeforeMovePos(nowPos.c);
		if(ifNeedCallBack)
			OnMoveBlock();
	}
	//��ȡ��ײ����
	SSMoveObjectImpactType GetImpactType_Now(){if(m_savedImpactType == SSMoveObjectImpactType_Undefined){m_savedImpactType = GetImpactType();} return m_savedImpactType;}

	//���е�Get��Set����
	void					SetMoveType(SSMoveObjectMoveType type){m_moveType = type;}
	SSMoveObjectMoveType	GetMoveType(){return m_moveType;}

	SSMoveObjectStatus  GetMoveStatus(){return m_moveStatus;}
	void  SetMoveStatus(SSMoveObjectStatus status){m_moveStatus = status;}

	UINT8				GetGroupID(){return m_grpID;}
	void				SetGroupID(UINT8 grpID){m_grpID = grpID;}

	TIME_MILSEC			GetStartMoveTime(){return m_startMoveTime;}
	void				SetStartMoveTime(TIME_MILSEC startMoveTime){m_startMoveTime = startMoveTime;}

	TIME_MILSEC			GetLastFailStartTime(){return m_lastFailStartTime;}
	void				SetLastFailStartTime(TIME_MILSEC lastFailStartTime){m_lastFailStartTime = lastFailStartTime;}

	ColVector&			GetDir(){return m_dir;}
	void				SetDir(ColVector& dir){m_dir = dir.Unit(); OnChangeDir(m_dir);}

	ColVector&			GetAskMoveDir(){return m_askMoveDir;}
	void				SetAskMoveDir(ColVector& dir){m_askMoveDir = dir.Unit();}

	TIME_MILSEC			GetRedirectTime(){return m_redirectTime;}
	void				SetRedirectTime(TIME_MILSEC redirectTime){m_redirectTime = redirectTime;}

	ColVector&			GetBeforeMovePos(){return m_beforeMovePos;}
	void				SetBeforeMovePos(ColVector& beforeMovePos){m_beforeMovePos = beforeMovePos;}

	ColSphere&			GetStepMoveTarget(){return m_stepMoveTarget;}
	void				SetStepMoveTarget(ColSphere& stepMoveTarget){m_stepMoveTarget = stepMoveTarget;}

	void				SetForceMoveSpeed(FLOAT speed){m_forceMoveSpeed = speed;}

	bool				IfStepMoved(){return m_ifStepMoved;}
	void				SetStepMoved(bool moved){m_ifStepMoved = moved;}

	bool				IfForceMoveImpact(){return m_ifForceMoveImpact;}
	void				SetIfForceMoveImpact(bool ifForceMoveImpact){m_ifForceMoveImpact = ifForceMoveImpact;}

	SIntPoint*			GetPathCell(){return m_asPathCell;}
	void				SetPathLength(UINT16 length){m_pathLength = length;}
	void				SetMoveStep(UINT16 step){m_moveStep = step;}
};

}

#endif