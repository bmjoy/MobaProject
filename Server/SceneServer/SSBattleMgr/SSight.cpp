#include "SSight.h"
#include "SSightLight.h"

#include "SSUser.h"
#include "ISSightLight.h"
#include "SSightObject.h"

namespace SceneServer{

CSSight::CSSight():
	m_sightType(ESightType_Normal)
{}

CSSight::~CSSight()
{
	Clear();
}

void CSSight::Clear()
{
	m_watcherVec.clear();
	m_sightLishtMap.clear();
}

//��ӹ۲���
bool CSSight::AddWatcher(CSSUser* pWatcher){
	for(auto iter = m_watcherVec.begin();iter!=m_watcherVec.end();iter++){
		CSSUser* pTemp = *iter;
		if(pTemp == pWatcher){
			return false;
		}
	}
	m_watcherVec.push_back(pWatcher);
	return true;
}

//��������ṩ��
void CSSight::AddSightLight(ISSightLight* pISightLight, ISSightObject* pAsSightObj){
	pAsSightObj->SetOwner(this);
	m_sightLishtMap.insert(pISightLight);
}

void CSSight::RemoveSightLight(ISSightLight* pISightLight, ISSightObject* pAsSightObj){
	pAsSightObj->SetOwner(NULL);
	m_sightLishtMap.erase(pISightLight);
}

//�ж�һ�����Ƿ��ڸ���Ұϵͳ����Ұ��
bool CSSight::IsInSight(ISSightObject* pSObject){
	if(FALSE == HasWatcher()){
		return false;
	}
	//OBϵͳ����ȫ��Ұ
	if(m_sightType == ESightType_OB)
		return true;
	if(pSObject->IfInvisible())
		return false;
	for(auto iter = m_sightLishtMap.begin();iter != m_sightLishtMap.end(); ++iter){
		ISSightLight* pLight = *iter;
		if(pLight->IsInSight(pSObject->GetSightPosX(), pSObject->GetSightPosY())){
			return true;
		}
	}
	return false;
}
}