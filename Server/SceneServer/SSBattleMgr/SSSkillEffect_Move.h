
#ifndef SSSKILLEFFECT_MOVE_H_
#define SSSKILLEFFECT_MOVE_H_


#include "stdafx.h"
#include "SSSkillEffect.h"
#include "SSMoveObjectHolder.h"
#include "SafeRefPtr.h"

namespace SceneServer{

class CSSSkillEffect_Move : public CSSSkillEffect, public ISSMoveObjectHolder
{
private: 
	SSkillModelMoveCfg* m_pMoveCfg;
	ref_ptr<CSSGameUnit>		m_pMoveTarget;//�ƶ���
	bool				m_bIfEnd;//�Ƿ��ƶ�������
	bool				m_bIfStartForceMove;//�Ƿ�ǿ���ƶ��ѿ�ʼ
	CVector3D			m_moveDir;//�ƶ�����
	CVector3D			m_lastMovePos;//��һ֡λ��
	CVector3D			m_moveTargetPos;//�ƶ��յ�λ��
	TIME_MILSEC			m_tBeginMilsec;//��ʼ�ƶ���ʱ��
	TIME_MILSEC			m_tLastMoveMilsec;//��һ֡��ʱ��
	TIME_MILSEC			m_tEndMilsec;//����ʱ��

public:
	CSSSkillEffect_Move();
	~CSSSkillEffect_Move();

private:
	bool				ResetPos(CSSGameUnit* pTarget, CVector3D& pos, CVector3D& dir, bool bIfEnd = FALSE, bool bIfCheckCollide = TRUE, bool bIFFindForward = TRUE);
	INT32				NotifyTeleportToGC(CSSGameUnit* pTarget, CVector3D& pStartPos, CVector3D& cDir);
	INT32				NotifyStartMoveToGC(CSSGameUnit* pStartGU, CVector3D& cPos, CVector3D& cDir, INT32 n32Speed);
	INT32				NotifyStopMoveToGC(CSSGameUnit* pStartGU, CVector3D& cPos);
	void				StartMove(CVector3D& cStartPos);
	void				StopMove();

public:
	virtual INT32		Begin();
	INT32				Update(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan); 
	virtual INT32		End();
	virtual bool		IfParaInvalid();

	virtual void		OnStopMove();
};

}



#endif