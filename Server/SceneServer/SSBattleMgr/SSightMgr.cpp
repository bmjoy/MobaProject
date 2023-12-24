#include "SSightMgr.h"
#include "SSight.h"
#include "SSightObject.h"
namespace SceneServer{
CSSightMgr::CSSightMgr():
	m_lastHeartBeatTime(0)
{
	
}

CSSightMgr::~CSSightMgr(){
	for(auto iter = m_SightVec.begin(); iter != m_SightVec.end(); iter++){
		delete (*iter);
	}
}
//��������ӵ���Ұϵͳ������һ����Ұ
CSSight* CSSightMgr::CreateSight(){
	CSSight* pSight = new CSSight;
	m_SightVec.push_back(pSight);
	return pSight;
}
//�Ƴ���Ұ
void CSSightMgr::RemoveSight(CSSight* pSight){
	for(auto iter = m_SightVec.begin(); iter!=m_SightVec.end(); ++iter){
		if(*iter == pSight){
			delete pSight;
			m_SightVec.erase(iter);
			return;
		}
	}
	Assert(false);
}

//��һ����Ұ�����һ���۲���
void CSSightMgr::AddWatcherAndCheck(CSSight* pSight, CSSUser* pWatcher){
	if(false == pSight->AddWatcher(pWatcher)){
		return;
	}
	vector<CSSUser*> pWatcherVec;	
	pWatcherVec.push_back(pWatcher);
	//������ж����Ƿ�����Ұ�С�����ǣ���Ҫ����Appear��Ϣ������¹۲���
	for(auto iter = m_SightObjectMap.begin(); iter != m_SightObjectMap.end(); ++iter){
		SSightObjectInfo& pSOInfo = iter->second;
		ISSightObject* pObject = iter->first;
		if(false == pSight->HasWatcher())
			continue;
		if(pObject->GetOwner()==pSight ||
			pSight->IsInSight(pObject)){
			pObject->OnAppearInSight(pWatcherVec);
			for(auto iter = pSOInfo.childSet.begin(); iter != pSOInfo.childSet.end();++iter){
				(*iter)->OnAppearInSight(pWatcherVec);
			}
		}
	}
}

//�����Ұ����
void CSSightMgr::AddSightObject(ISSightObject* pObject){
	SSightObjectInfo info;
	//�������ܿ�������Ұ����Ĺ۲��߷���Appear��Ϣ
	for(auto iter = m_SightVec.begin(); iter != m_SightVec.end(); ++iter){
		CSSight* pSight = *iter;
		if(pObject->GetOwner()==pSight ||
			pSight->IsInSight(pObject)){
			info.AddSight(pSight);
			if(false == pSight->HasWatcher()) 
				continue;
			pObject->OnAppearInSight(pSight->GetWatchers());
		}
	}
	m_SightObjectMap.insert(std::make_pair(pObject, info));
}

//�������Ұ��������Ұ����������Ұ�����ϣ������������Ƿ�����Ұ�г��֡����丸�������Appear��Disapear�ӿ�ʱ������Ҫͬ������
void CSSightMgr::AddChildSightObject(ISSightObject* pFather, ISSightObject* pChild){
	auto iter = m_SightObjectMap.find(pFather);
	if(iter == m_SightObjectMap.end()){
		return;
	}
	SSightObjectInfo* pInfo = &(iter->second);
	pInfo->childSet.insert(pChild);
	for(int i=0;i<pInfo->c_maxSightSize;++i){
		CSSight* pSight = pInfo->sightArray[i];
		if(pSight == NULL) 
			continue;
		if(false == pSight->HasWatcher()) 
			continue;
		pChild->OnAppearInSight(pSight->GetWatchers());
	}
}

//�Ƴ���Ұ����
void CSSightMgr::RemoveSightObject(ISSightObject* pObject){
	auto iter = m_SightObjectMap.find(pObject);
	if(m_SightObjectMap.end() != iter){
		SSightObjectInfo *pInfo = &iter->second;
		//���Ͷ�Ӧ��Disappear��Ϣ����۲��ߣ�����������������Ұ������ͬ���ķ��ͺ��Ƴ�����
		for(int i=0;i<pInfo->c_maxSightSize;i++){
			CSSight* pSight = pInfo->sightArray[i];
			if(pSight == NULL) continue;
			for(auto childIter = pInfo->childSet.begin();childIter != pInfo->childSet.end(); ++childIter){
				(*childIter)->OnDisappearInSight(pSight->GetWatchers());
			}
			pObject->OnDisappearInSight(pSight->GetWatchers());
		}
		m_SightObjectMap.erase(iter);
	}
}

void CSSightMgr::RemoveChildSightObject(ISSightObject* pFather, ISSightObject* pChild){
	auto iter = m_SightObjectMap.find(pFather);
	if(m_SightObjectMap.end() != iter){
		ISSightObject* pObject = iter->first;
		SSightObjectInfo *pInfo = &iter->second;
		for(int i=0;i<pInfo->c_maxSightSize;i++){
			CSSight* pSight = pInfo->sightArray[i];
			if(pSight == NULL) 
				continue;
			pChild->OnDisappearInSight(pSight->GetWatchers());
		}
		pInfo->childSet.erase(pChild);
	}
}

//��ȡ�����ܿ���ָ����Ұ����Ĺ۲��߲�����
void CSSightMgr::GetWatcher(ISSightObject* pObject, CSSUser** pWatcherArray, UINT16& length){
	int index = 0;
	auto iter = m_SightObjectMap.find(pObject);
	if(m_SightObjectMap.end() != iter){
		ISSightObject* pObject = iter->first;
		SSightObjectInfo *pInfo = &iter->second;
		for(int i=0;i<pInfo->c_maxSightSize;i++){
			CSSight* pSight = pInfo->sightArray[i];
			if(pSight == NULL) continue;
			vector<CSSUser*>& pTempWatcherVec = pSight->GetWatchers();
			for(auto watcherIter = pTempWatcherVec.begin(); watcherIter != pTempWatcherVec.end(); watcherIter++){
				pWatcherArray[index++] = *watcherIter;
			}
		}
	}
	length = index;
}

//��ȡ������Ұϵͳ�����еĹ۲���
void CSSightMgr::GetAllWatcher(vector<CSSUser*>& pWatcherVec){
	for(auto sightIter = m_SightVec.begin(); sightIter != m_SightVec.end(); sightIter++){
		CSSight* pSight = *sightIter;
		vector<CSSUser*>& pTempWatcherVec = pSight->GetWatchers();
		for(auto watcherIter = pTempWatcherVec.begin(); watcherIter != pTempWatcherVec.end(); watcherIter++){
			pWatcherVec.push_back(*watcherIter);
		}
	}
}

//��ȡָ����Ұ���͵����еĹ۲���
void CSSightMgr::GetWatcherBySightType(ESightType eSightType, vector<CSSUser*>& pWatcherVec){
	for(auto sightIter = m_SightVec.begin(); sightIter != m_SightVec.end(); ++sightIter){
		CSSight* pSight = *sightIter;
		if(pSight->m_sightType == eSightType){
			pWatcherVec = pSight->GetWatchers();
			break;
		}
	}
}
//����
INT32 CSSightMgr::OnHeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan){

	ProfileInScope lProfileInScope(StaticsType_Sight);

	//ÿ500�������һ�η����ж������Ұ
	bool updateAllSight = FALSE;
	if(tUTCMilsec - m_lastHeartBeatTime > 500){
		updateAllSight = TRUE;
		m_lastHeartBeatTime = tUTCMilsec;
	}
	//������е���Ұ���󡣵�����ֻ�����ʧ����Ұ�е�ʱ�򣬷��Ͷ�Ӧ����Ϣ
	for(auto iter = m_SightObjectMap.begin(); iter != m_SightObjectMap.end(); ++iter){
		for(auto sightIter = m_SightVec.begin(); sightIter != m_SightVec.end(); ++sightIter){
			if(updateAllSight || iter->first->GetSightObjectType() == ESSSightObjectType_Sensitive){
				CheckObjectInSight(*sightIter, iter->first, iter->second);
			}
		}
	}

	return eNormal;
}

void CSSightMgr::CheckObjectInSight(CSSight* pSight, ISSightObject* pObject, SSightObjectInfo& soInfo){
	if(false == pSight->HasWatcher()){
		return;
	}

	// �����ж��Լ����Լ���Ұ��//
	if (pObject->GetOwner()==pSight){
		return;
	}

	//�����������Ұ�У�Ȼ����ǰ�ֲ��ڸ���Ұ�У�����Appear��Ϣ
	if(pSight->IsInSight(pObject)){
		if(false == soInfo.IfHasSight(pSight)){
			soInfo.AddSight(pSight);
			pObject->OnAppearInSight(pSight->GetWatchers());
			for(auto iter = soInfo.childSet.begin(); iter != soInfo.childSet.end();++iter){
				(*iter)->OnAppearInSight(pSight->GetWatchers());
			}
		}
	}
	//�����������Ұ�У���ǰȴ����Ұ�У�����Disappear��Ϣ
	else{
		if(true == soInfo.IfHasSight(pSight)){
			soInfo.RemoveSight(pSight);
			pObject->OnDisappearInSight(pSight->GetWatchers());
			for(auto iter = soInfo.childSet.begin(); iter != soInfo.childSet.end();++iter){
				(*iter)->OnDisappearInSight(pSight->GetWatchers());
			}
		}
	}
}

}