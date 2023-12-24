/*
* file name			:SSightMng.h
* file mark			:
* summary			:
*
* version			:1.0
* author			:LiuLu
* complete date		:July 15 2014
* summary			:
*
*/

#ifndef __SSightMng_h__
#define __SSightMng_h__

#include "stdafx.h"
#include "SSObjectPool.h"
#include <hash_map>
#include <set>

namespace SceneServer{

enum ESightType;
class CSSight;
class ISSightObject;

class CSSightMgr
{
private:
	//ʹ�������Ż����Ķ�����Ұ����ϵͳ������Ƿ���һ����Ұ�г��ֻ�����ʧ�Ĺؼ�����
	struct SSightObjectInfo
	{
		set<ISSightObject*> childSet;

		static const UINT c_maxSightSize = 3;
		CSSight* sightArray[c_maxSightSize];

		SSightObjectInfo(){
			for (INT32 i = 0; i < c_maxSightSize; ++i){
				sightArray[i] = nullptr;
			}
		}

		void clear(){
			childSet.clear();
			for (INT32 i = 0; i < c_maxSightSize; ++i){
				sightArray[i] = nullptr;
			}
		}

		void AddSight(CSSight* pSight){
			for(int i=0;i<c_maxSightSize;i++){
				if(pSight == sightArray[i]){
					break;
				}
				if(sightArray[i] == NULL){
					sightArray[i] = pSight;
					break;
				}
			}
		}

		void RemoveSight(CSSight* pSight){
			for(int i=0;i<c_maxSightSize;i++){
				if(sightArray[i] == pSight){
					sightArray[i] = NULL;
				}
			}
		}

		bool	IfHasSight(CSSight* pSight){
			for(int i=0;i<c_maxSightSize;i++){
				if(sightArray[i] == pSight){
					return TRUE;
				}
			}
			return FALSE;
		}
	};

	vector<CSSight*>								m_SightVec;//��Ұ�б�
	hash_map<ISSightObject*, SSightObjectInfo>		m_SightObjectMap;//��Ұ�����б�
	TIME_MILSEC										m_lastHeartBeatTime;//�ϴμ����������Ұ�����ʱ��

	void								CheckObjectInSight(CSSight* pSight, ISSightObject* pObject, SSightObjectInfo& soInfo);

public:
	CSSightMgr();
	~CSSightMgr();
	CSSight*							CreateSight();
	void								RemoveSight(CSSight* pSight);
	void								AddWatcherAndCheck(CSSight* pSight, CSSUser* pWatcher);
	void								AddSightObject(ISSightObject* pObject);
	void								AddChildSightObject(ISSightObject* pFather, ISSightObject* pChild);
	void								RemoveSightObject(ISSightObject* pObject);
	void								RemoveChildSightObject(ISSightObject* pFather, ISSightObject* pChild);
	void								GetWatcher(ISSightObject* pObject, CSSUser** pWatcherArray, UINT16& length);
	void								GetAllWatcher(vector<CSSUser*>& pWatcherVec);
	void								GetWatcherBySightType(ESightType eSightType, vector<CSSUser*>& pWatcherVec);
	INT32								OnHeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan);
	hash_map<ISSightObject*, SSightObjectInfo>&				GetSightObjMap() { return m_SightObjectMap; };
};

}

#endif