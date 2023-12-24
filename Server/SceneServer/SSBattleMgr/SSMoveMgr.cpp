#include "SSMoveMgr.h"
#include "SSMoveObject.h"
#include "SSMoveTool.h"
#include "SSAStar.h"

#include "SSGameUnit.h"
namespace SceneServer{
	CSSMoveMgr::CSSMoveMgr():
	m_staticBlockArray(NULL),
	m_regionWidth(0),
	m_regionHeight(0),
	m_regionSize(0)
{
	for (INT32 i = 0; i < 1024; ++i){
		m_heartBeatTempArray[i] = nullptr;
	}
}

CSSMoveMgr::~CSSMoveMgr(){
	if(m_staticBlockArray != NULL){
		delete []m_staticBlockArray;
		m_staticBlockArray = NULL;
	}
	DelAllPathCache();
}

void CSSMoveMgr::AddMoveObject(ISSMoveObject* pMObject, UINT8 ui8GrpID)
{
	Assert(ui8GrpID!=SSImpactGruop_None);//������ͱ�����\����Ҳ���������//
	RemoveMoveObject(pMObject);
	pMObject->SetGroupID(ui8GrpID);
	pMObject->SetMoveStatus(SSMoveObjectStatus_Stand);
	pMObject->SetStepMoveTarget(pMObject->GetColSphere());
	pMObject->SetBeforeMovePos(pMObject->GetStepMoveTarget().c);
	m_mObjectMap[ui8GrpID].insert(pMObject);
	m_allMObjectSet.insert(pMObject);
}

void CSSMoveMgr::RemoveMoveObject(ISSMoveObject* pMObject)
{
	if (pMObject->GetGroupID() == SSImpactGruop_None) return;
	hash_set<ISSMoveObject*>* pSet = &m_mObjectMap[pMObject->GetGroupID()];
	pSet->erase(pMObject);
	m_allMObjectSet.erase(pMObject);
}

void CSSMoveMgr::AddStaticTriBlockInfo(UINT16 x, UINT16 y, ETriDir dir){
	m_staticTriBlockMap[GetRegionID_INT(x,y)] = SIntTri(x,y,dir);
}


//��ʼ���շ����ƶ�(�������ƶ��е���)
bool CSSMoveMgr::AskStartMoveDir(ISSMoveObject* pMObject, ColVector dir){
	if(FALSE == AskStartCheck(pMObject)){
		return FALSE;
	}
	if(pMObject->GetMoveStatus() == SSMoveObjectStatus_Stand){
		pMObject->SetMoveType(SSMoveObjectMoveType_Dir);
		TIME_MILSEC now = GetUTCMiliSecond();
		pMObject->SetMoveStatus(SSMoveObjectStatus_Move);
		pMObject->SetAskMoveDir(dir);
		pMObject->SetDir(dir);
		pMObject->SetStartMoveTime(now);
		//������һ��100������λ��
		pMObject->CalculateStepMoveTarget(now + 100);
		//����Ƿ��ֱ��ײǽ
		if(FALSE == TestNextStepMove(pMObject)){
			if(FALSE == TryTurnDir(pMObject)){
				pMObject->Stop(now,FALSE);
				return FALSE;
			}
		}
		pMObject->OnStartMove(pMObject->GetDir());
		return TRUE;
	}
	return FALSE;
}

//�����ƶ���ָ������(�������ƶ��е���)
bool CSSMoveMgr::AskStartMoveToTar(ISSMoveObject* pMObject, ColVector pos, bool bIfMoveToBlackPoint, bool bIfFliter){
	TIME_MILSEC now = GetUTCMiliSecond();
	if(now - pMObject->GetLastFailStartTime() < 150){
		//ͬһ����λ����̳���ʱ��Ϊ150;
		return FALSE;
	}
	if(FALSE == AskStartCheck(pMObject)){
		pMObject->SetLastFailStartTime(now);
		return FALSE;
	}
	pMObject->SetMoveType(SSMoveObjectMoveType_Tar);
	if(pMObject->GetMoveStatus() == SSMoveObjectStatus_Stand){
		//��ȡ��Χ�Ķ�̬��ײ����
		UINT32 dynamicBlockSet[c_maxDynamicBlockNum] = {0};
		UINT16 dynBlockLength = 0;
		FindDynamicBlock(pMObject,dynamicBlockSet, dynBlockLength);
		//׼��Ѱ·�Ļ�������
		ColVector nowVec = pMObject->GetColVector();
		UINT16 startX = GetRegionIndexX(nowVec.x);
		UINT16 startY = GetRegionIndexY(nowVec.y);
		UINT16 targetX= GetRegionIndexX(pos.x);
		UINT16 targetY= GetRegionIndexY(pos.y);

		bool bIfNeedFind = FALSE;
		if(dynBlockLength == 0){
			//û���赲�����Զ�ȡ��������
			SIntPoint* cachePath = GetPathByCache(GetPathID(GetRegionID_INT(startX,startY), GetRegionID_INT(targetX,targetY)));
			if(cachePath != NULL){
				//�л����ֵ��ֱ��ʹ��
				SIntPoint* path = &pMObject->GetPathCell()[1];
				memcpy(path,cachePath,sizeof(SIntPoint)*(c_n32MaxOrderPathNode-1));
				pMObject->SetPathLength(1);
				for(int i=0;i<c_n32MaxOrderPathNode-1;i++){
					if(cachePath[i].n32XIdx == 0 || cachePath[i].n32ZIdx == 0){
						pMObject->SetPathLength(i + 1);
						break;
					}
				}
			}
			else{
				//û�л����ֵ
				bIfNeedFind = TRUE;
			}
		}

		if(dynBlockLength > 0 || bIfNeedFind){
			//����ж�̬�赲�������Ҳ������棬������ҪѰ��
			SFindPathInfoNew aStartInfo;
			//�������
			aStartInfo.psStartIntPoint.n32XIdx = startX;
			aStartInfo.psStartIntPoint.n32ZIdx = startY;
			//�����յ�
			aStartInfo.psTargetIntPoint.n32XIdx = targetX;
			aStartInfo.psTargetIntPoint.n32ZIdx = targetY;
			pMObject->GetPathCell()[0] = aStartInfo.psTargetIntPoint;
			//�����赲
			aStartInfo.pDynamicBlockArray = dynamicBlockSet;
			//������������
			aStartInfo.ifToTarget = bIfMoveToBlackPoint;
			aStartInfo.ifFliter = bIfFliter;
			//��ʼ�������õ�����
			aStartInfo.psPathBuff = &pMObject->GetPathCell()[1];
			aStartInfo.n32PathNodeNum = c_n32MaxOrderPathNode - 1;

			m_Astar.FindPath(aStartInfo);
			//���Ѱ·ʧ�ܣ�����
			if(aStartInfo.n32PathNodeNum <= 0){
				pMObject->SetLastFailStartTime(now);
				return FALSE;
			}

			pMObject->SetPathLength(aStartInfo.n32PathNodeNum + 1);

			if(dynBlockLength == 0 && aStartInfo.n32PathNodeNum > 0){
				//û�ж�̬�赲���ѱ���Ѱ·����
				SavePathToCache(GetPathID(GetRegionID_INT(startX,startY),GetRegionID_INT(targetX,targetY)),aStartInfo.psPathBuff,aStartInfo.n32PathNodeNum);
			}
		}

		//�����ƶ�����
		pMObject->SetStartMoveTime(GetUTCMiliSecond());
		pMObject->SetMoveStep(1);
		SetNextMovePoint(pMObject);

		//�ж϶�̬��ײ
		pMObject->IfStart = TRUE;
		TIME_MILSEC now = GetUTCMiliSecond();
		pMObject->SetStartMoveTime(now);
		pMObject->CalculateStepMoveTarget(now + 100);
		//�����һ��100�������赲�����ء���������£����ﷵ�صĸ���Ӧ�úܵ͡��������Ϸ�����ڵ�ͼ�Ͽ�ס�����ȼ��������Ƿ�Ѱ����·ֱ�ӱ��赲
		if(FALSE == TestNextStepMove(pMObject,FALSE,TRUE)){
			pMObject->Stop(now,FALSE);
			pMObject->IfStart = FALSE; 
			return FALSE;
		}
		pMObject->IfStart = FALSE;
		pMObject->OnStartMove(pMObject->GetDir());

		return TRUE;
	}

	pMObject->SetLastFailStartTime(now);

	return FALSE;
}

//��ʼǿ��λ��(�������ƶ��е���)
bool CSSMoveMgr::AskStartMoveForced(ISSMoveObject* pMObject, ColVector dir, FLOAT speed, bool bIfImpact){
	if(FALSE == AskStartCheck(pMObject)){
		return FALSE;
	}
	//ǿ��λ�ƿ��Դ����������λ�ƣ�����ǿ��λ��(�����߼�����Щ����)
	if(pMObject->GetMoveStatus() == SSMoveObjectStatus_Stand){
		pMObject->SetMoveType(SSMoveObjectMoveType_ForceMove);
		TIME_MILSEC now = GetUTCMiliSecond();
		pMObject->SetDir(dir);
		pMObject->SetStartMoveTime(now);
		pMObject->SetMoveStatus(SSMoveObjectStatus_ForceMove);
		pMObject->SetIfForceMoveImpact(bIfImpact);
		pMObject->SetForceMoveSpeed(speed);
		return TRUE;
	}
	return FALSE;
}

//���ƶ�Ŀ������Ϊ��һ����
bool CSSMoveMgr::SetNextMovePoint(ISSMoveObject* pMObject){
	//��ȡ��һ��Ŀ���
	SIntPoint firstIntPoint;
	if(FALSE == pMObject->GetNowMoveIntTar(firstIntPoint))
		return FALSE;
	//��ȡĿ�����ĵ�
	ColVector firstPoint = GetRegionCenter(firstIntPoint.n32XIdx, firstIntPoint.n32ZIdx);
	//����Ŀ�귽��
	ColVector dir = (firstPoint - pMObject->GetColVector()).Unit();
	pMObject->SetDir(dir);
	pMObject->SetMoveStatus(SSMoveObjectStatus_Move);
	return TRUE;
}

//Ѱ����Χ�Ķ�̬�赲����
void CSSMoveMgr::FindDynamicBlock(ISSMoveObject* pMObject, UINT32 *dynamicArray, UINT16 &length){
	ColVector selfSph = pMObject->GetColVector();
	if(pMObject->GetImpactType_Now() == SSMoveObjectImpactType_NoImpact) return;
	if (!pMObject->IfCanImpact()) return;
	UINT16 index = 0;
	SSMoveObjectImpactType impact_type = pMObject->GetImpactType_Now();
	switch (impact_type)
	{
		//���������ײ��������Ҫ������е�ͬ���Ա���Լ�ȫ��ײ��ĳ�Ա
	case SSMoveObjectImpactType_Group:
		{
			hash_set<ISSMoveObject*>& group_set = m_mObjectMap[pMObject->GetGroupID()];
			for (auto it = group_set.begin(); it!= group_set.end(); ++it)
			{
				if (*it == pMObject) continue;
				AddDnnamicBlock(pMObject,*it,dynamicArray,length,index);
			}
			hash_set<ISSMoveObject*>& group_all_set = m_mObjectMap[SSImpactGruop_All];
			for (auto it = group_all_set.begin(); it!= group_all_set.end(); ++it)
			{
				if (*it == pMObject) continue;
				AddDnnamicBlock(pMObject,*it,dynamicArray,length,index);
			}
		}
		break;
		//�����ȫ��ײ������ֱ�Ӽ�����е���ײ����
	case SSMoveObjectImpactType_ALL:
		{
			for(hash_set<ISSMoveObject*>::iterator iter = m_allMObjectSet.begin(); iter != m_allMObjectSet.end(); ++iter)
			{
				if(*iter == pMObject) continue;
				AddDnnamicBlock(pMObject,*iter,dynamicArray,length,index);
			}
		}
		break;
	}
}

void	CSSMoveMgr::AddDnnamicBlock(ISSMoveObject* pMObject, ISSMoveObject* pTarget, UINT32 *dynamicArray, UINT16 &length, UINT16 &index){
	//���״̬
	if(pTarget->GetMoveStatus() != SSMoveObjectStatus_Stand){
		return;
	}
	//����赲����
	if(pTarget->IfCanImpact() == FALSE){
		return;
	}
	//������
	ColVector selfSph = pMObject->GetColVector();
	ColSphere sph = pTarget->GetColSphere();
	if(abs(sph.c.x - selfSph.x) > 500 || abs(sph.c.y - selfSph.y) > 500){
		return;
	}

	//���ķ���Ϊ�� ��ȡ����ײ��ΪԲ�ģ���ײ�ߺ��ƶ��߰뾶֮��Ϊ�뾶�����ǵ����и���
	sph.r += pMObject->GetColRadius();
	//��ȡ�赲�ĸ���
	for(float x=sph.c.x - sph.r; x<= sph.c.x + sph.r + m_regionSize; x+=m_regionSize){
		for(float y=sph.c.y - sph.r; y<= sph.c.y + sph.r + m_regionSize; y+=m_regionSize){
			//�ж��������Ƿ���Բ��
			UINT16 uiX = GetRegionIndexX(x);
			UINT16 uiY = GetRegionIndexY(y);
			//����������
			ColAABB aabb;
			aabb.min.x = uiX*m_regionSize; aabb.min.y = uiY*m_regionSize;
			aabb.max.x = (uiX+1)*m_regionSize; aabb.max.y = (uiY+1)*m_regionSize;
			if(CSSMoveTool::IfImpact(sph,aabb)){
				if(index < c_maxDynamicBlockNum)
					dynamicArray[index++] = GetRegionID_INT(uiX,uiY);
			}
		}
	}
	length = index;
}

//����ֹͣ�ƶ�
bool	CSSMoveMgr::AskStopMoveObject(ISSMoveObject* pMObject,EnumAskStopMoveType type){
	//�ж϶����Ƿ����
	if(m_allMObjectSet.end() == m_allMObjectSet.find(pMObject)){
		return FALSE;
	}
	//���ݵ�ǰ״̬���д���
	if(pMObject->GetMoveStatus() == SSMoveObjectStatus_Stand){
		return FALSE;
	}
	//ÿ��ö��ֵ����ֻ��ָֹͣ�����͵��ƶ���All���͵Ŀ���ֹͣ�����ƶ�
	if(pMObject->GetMoveStatus() == SSMoveObjectStatus_Move){
		if(type == EnumAskStopMoveType_ALL || 
			(type == EnumAskStopMoveType_DIR && pMObject->GetMoveType() == SSMoveObjectMoveType_Dir)
			|| (type == EnumAskStopMoveType_TAR && pMObject->GetMoveType() == SSMoveObjectMoveType_Tar))
			StopLastStep(pMObject,TRUE);
	}
	if(pMObject->GetMoveStatus() == SSMoveObjectStatus_ForceMove){
		if(type == EnumAskStopMoveType_ALL || type == EnumAskStopMoveType_FORCEMOVE)
		{
			StopLastStep(pMObject,TRUE);
			ResetPos(pMObject,pMObject->GetColVector(),TRUE);
		}
	}

	return TRUE;
}

bool	CSSMoveMgr::AskStartCheck(ISSMoveObject* pMObject){
	//�ж϶����Ƿ����
	if(m_allMObjectSet.end() == m_allMObjectSet.find(pMObject)){
		return FALSE;
	}
	//���ݵ�ǰ״̬���д���
	if(pMObject->GetMoveStatus() == SSMoveObjectStatus_ForceMove){
		return FALSE;
	}
	if(pMObject->GetMoveStatus() == SSMoveObjectStatus_Move){
		//������ƶ�״̬,�Ƚ���һ���ƶ��ս�
		StopLastStep(pMObject,FALSE);
	}
	return TRUE;
}

INT32 CSSMoveMgr::OnHeartBeat(TIME_MILSEC tUTCMilsec, TIME_TICK tTickSpan){

	ProfileInScope lProfileInScope(StaticsType_Move);

	TIME_MILSEC now = GetUTCMiliSecond();

	const UINT16 moveObjectSize = m_allMObjectSet.size();
	Assert(moveObjectSize<=1024);

	for (INT32 i = 0; i < 1024; ++i){
		m_heartBeatTempArray[i] = nullptr;
	}

	//��������Ŀ��Ϊδ�ƶ�
	UINT16 index = 0;
	for(auto iter = m_allMObjectSet.begin(); iter != m_allMObjectSet.end(); ++iter){
		ISSMoveObject* pMObject = *iter;
		if(pMObject->GetMoveStatus() == SSMoveObjectStatus_Stand){
			continue;
		}
		pMObject->SetStepMoved(FALSE);
		//����ǰ��շ���λ�Ƶ���ң�Ҫ��ʱ���䷽������
		if(pMObject->GetMoveType() == SSMoveObjectMoveType_Dir && pMObject->GetDir() != pMObject->GetAskMoveDir()){
			ColVector nowDir = pMObject->GetDir();
			pMObject->SetDir(pMObject->GetAskMoveDir());
			pMObject->CalculateStepMoveTarget(now);
			//����侲̬��ײ
			if (IfStaticImpact(pMObject))
			{
				//����о�̬��ײ�����䷽��Ļ���
				pMObject->SetDir(nowDir);
			}
			else{
				//����ı��ˣ�������Ϣ
				pMObject->OnStartMove(pMObject->GetDir());
			}
		}
		//Ԥ�ȼ�����һ����Ҫ�ƶ�����λ��
		pMObject->CalculateStepMoveTarget(now);
		m_heartBeatTempArray[index++] = pMObject;
	}

	UINT16 moveTargetNum = 0;
	//���������ƶ����ж���ֱ��û���κ�һ����������ƶ�Ϊֹ
	do{
		moveTargetNum = 0;
		for(int i=0;i<moveObjectSize;i++){
			ISSMoveObject* pMObject = m_heartBeatTempArray[i];
			if(pMObject == NULL) continue;
			//�����ƶ�������ֵ����ɹ������ʱ�����㹻С��ʱ���ƶ��ɹ�Ҳ���ܾ���Ϊ0��
			float moveDist = 0;
			if(TRUE == TryMove(pMObject,now, moveDist)){
				//λ�Ƴɹ�
				++moveTargetNum;
				//����Ƿ���Ҫ�����ƶ��㣬�����ƶ���Ŀ��
				CheckTargetMoveStatus(pMObject,moveDist);
				m_heartBeatTempArray[i] = NULL;
			}
		}
	}while(moveTargetNum > 0);

	//ʣ�µ�Ŀ�궼�ǲ����ƶ��ģ�����ֹͣ
	for(int i=0;i<moveObjectSize;i++){
		ISSMoveObject* pMObject = m_heartBeatTempArray[i];
		if(pMObject == NULL) continue;
		pMObject->Stop(now);
	}

	//���¼������Ŀ�꣬���Ƿ��������һ�������ƶ�
	for(auto iter = m_allMObjectSet.begin(); iter != m_allMObjectSet.end(); ++iter){
		ISSMoveObject* pMObject = *iter;
		if(pMObject->GetMoveStatus() == SSMoveObjectStatus_Stand) continue;
		if(pMObject->GetMoveStatus() == SSMoveObjectStatus_ForceMove) continue;
		pMObject->CalculateStepMoveTarget(now + 100);
		if(FALSE == TestNextStepMove(pMObject,pMObject->GetMoveType() == SSMoveObjectMoveType_Dir)){
			//��һ�������ƶ���ʧ�ܣ�����ֹͣ
			pMObject->Stop(now);
		}
	}

	return eNormal;
}

bool CSSMoveMgr::TryMove(ISSMoveObject* pMObject,TIME_MILSEC now, float &moveDist)
{
	bool bIfForceMoveImpact = pMObject->GetMoveStatus() == SSMoveObjectStatus_ForceMove && pMObject->IfForceMoveImpact();

	//��龲̬��ײ,ֻ�а��շ�������ƶ���Ŀ�����Ҫ���//
	if( (pMObject->GetMoveType() == SSMoveObjectMoveType_Dir || bIfForceMoveImpact))
	{
		if (IfStaticImpact(pMObject))
		{
			//�������һ��������ܳ�ȥ������Ȼ���Է���
			pMObject->CalculateStepMoveTarget(now + 100);
			if(IfStaticImpact(pMObject)){
				pMObject->CalculateStepMoveTarget(now);
				if(bIfForceMoveImpact || FALSE == TryTurnDir(pMObject)){
					moveDist = 0;
					return FALSE;
				}
			}
			else{
				pMObject->CalculateStepMoveTarget(now);
			}
		}
	}

	//��鶯̬��ײ//
	if(pMObject->GetMoveStatus() != SSMoveObjectStatus_ForceMove || bIfForceMoveImpact)
	{
		if (IfDynamicImpact(pMObject,TRUE))
		{
			moveDist = 0;
			return FALSE;
		}
	}

	//�ƶ�
	moveDist = pMObject->Move(now);
	return TRUE;
}

void CSSMoveMgr::StopLastStep(ISSMoveObject* pMObject, bool bIfCallBack){
	//���ݵ�ǰʱ������һ���ƶ���ʱ�������һС�����ƶ�
	TIME_MILSEC now = GetUTCMiliSecond();
	pMObject->CalculateStepMoveTarget(now);
	float tempFloat;
	TryMove(pMObject,now,tempFloat);
	pMObject->Stop(now,bIfCallBack);
}

void CSSMoveMgr::CheckTargetMoveStatus(ISSMoveObject* pMObject, float movedLength){
	if(pMObject->GetMoveType() != SSMoveObjectMoveType_Tar){
		return;
	}

	if(pMObject->GetMoveStatus() == SSMoveObjectStatus_ForceMove){
		return;
	}

	SIntPoint targetIntPoint;
	if(FALSE == pMObject->GetNowMoveIntTar(targetIntPoint)){
		//����Ҳ���Ŀ��㣬����
		return;
	}
	ColVector targetPoint = GetRegionCenter(targetIntPoint.n32XIdx, targetIntPoint.n32ZIdx);
	ColVector oldDir = targetPoint - pMObject->GetBeforeMovePos();
	ColVector nowDir = targetPoint - pMObject->GetColVector();
	//FLOAT distToPoint = (targetPoint - pMObject->GetBeforeMovePos()).Length();
	//�ж��Ƿ��Ѿ��ƶ�������;��
	//if((distToPoint - movedLength) < (movedLength/2)){
	if((oldDir.x>=0 && nowDir.x<=0)||(oldDir.x<=0 && nowDir.x>=0)||(oldDir.y>=0 && nowDir.y<=0)||(oldDir.y<=0 && nowDir.y>=0)){
		pMObject->AddMoveStep();
		//Ѱ����һ���ƶ���
		if(FALSE == SetNextMovePoint(pMObject)){
			//�ִ�Ŀ�ĵأ�ֹͣ�ƶ�
			pMObject->SetMoveStatus(SSMoveObjectStatus_Stand);
			pMObject->OnMoveBlock();
		}
		else{
			pMObject->OnStartMove(pMObject->GetDir());
		}
	}
	else{
		if(oldDir.Length() < nowDir.Length()){
			int abc = 0;
		}
	}
}

bool	CSSMoveMgr::IfStaticImpact(ISSMoveObject* pMObject){
	//��龲̬��ײ
	ColSphere nextPoint = pMObject->GetStepMoveTarget();
	INT16	colRadius = pMObject->GetColRadius();
	for(int i=-(colRadius/100+1);i<colRadius/100+1;i++){
		for(int j=-(colRadius/100+1);j<colRadius/100+1;j++){
			float x = nextPoint.c.x + i*100;
			if(x < nextPoint.c.x - colRadius) x = nextPoint.c.x - colRadius;
			if(x > nextPoint.c.x + colRadius) x = nextPoint.c.x + colRadius;
			float y = nextPoint.c.y + j*100;
			if(y < nextPoint.c.y - colRadius) y = nextPoint.c.y - colRadius;
			if(y > nextPoint.c.y + colRadius) y = nextPoint.c.y + colRadius;

			//�ȼ�鷽������ײ
			if(TRUE == m_staticBlockArray[GetRegionID_FLOAT(x,y)]){
				return TRUE;
			}
			//�ټ����������ײ
			auto iter = m_staticTriBlockMap.find(GetRegionID_FLOAT(x,y));
			if(iter != m_staticTriBlockMap.end()){
				SIntTri &tri = iter->second;
				if(tri.eDir == ETriDir_RightBelow){
					if(x-(tri.x*m_regionSize) + y - (tri.y*m_regionSize) < m_regionSize) { return TRUE;}
				}
				else if(tri.eDir == ETriDir_RightUp){
					if(x-(tri.x*m_regionSize) + ((tri.y+1)*m_regionSize) - y < m_regionSize) { return TRUE;}
				}
				else if(tri.eDir == ETriDir_LeftBelow){
					if(((tri.x+1)*m_regionSize) - x + y - (tri.y*m_regionSize) < m_regionSize) { return TRUE;}
				}
				else if(tri.eDir == ETriDir_LeftUp){
					if(((tri.x+1)*m_regionSize) - x + ((tri.y+1)*m_regionSize) - y < m_regionSize) { return TRUE;}
				}
			}
		}
	}
	return FALSE;
}

//�����һ�������Ƿ������������ײ
bool CSSMoveMgr::TestNextStepMove(ISSMoveObject* pMObject, bool bIfCheckStaticBlock, bool bIfCheckDynamicBlock)
{
	if(bIfCheckStaticBlock && TRUE == IfStaticImpact(pMObject))
	{
		if(pMObject->GetMoveType() == SSMoveObjectMoveType_Dir){
			if(TryTurnDir(pMObject)){
				return TRUE;
			}
		}
		return FALSE;
	}
	if(bIfCheckDynamicBlock && TRUE == IfDynamicImpact(pMObject,TRUE))
	{
		return FALSE;
	}
	return TRUE;
}

bool	CSSMoveMgr::IfDynamicImpact(ISSMoveObject* pMObject,bool pIfCheckNextStep)
{
	if (!pMObject->IfCanImpact()) return FALSE;
	if (pMObject->GetColRadius() == 0) 
		return FALSE;

	//���ݷ������ײ���ͣ�������п��ܺ��Լ���ײ�Ķ���
	SSMoveObjectImpactType impact_type = pMObject->GetImpactType_Now();
	switch (impact_type)
	{
	case SSMoveObjectImpactType_Group:
		{
			hash_set<ISSMoveObject*>& group_set = m_mObjectMap[pMObject->GetGroupID()];
			for (auto it = group_set.begin(); it!= group_set.end(); ++it)
			{
				if (*it == pMObject) continue;
				if (IfDynamicImpact(pMObject,*it,pIfCheckNextStep))
				{
					return TRUE;
				}
			}
			hash_set<ISSMoveObject*>& group_all_set = m_mObjectMap[SSImpactGruop_All];
			for (auto it = group_all_set.begin(); it!= group_all_set.end(); ++it)
			{
				if (*it == pMObject) continue;
				if (IfDynamicImpact(pMObject,*it,pIfCheckNextStep))
				{
					return TRUE;
				}
			}
		}
		break;
	case SSMoveObjectImpactType_ALL:
		{
			for(hash_set<ISSMoveObject*>::iterator iter = m_allMObjectSet.begin(); iter != m_allMObjectSet.end(); ++iter)
			{
				if(*iter == pMObject) continue;
				if(TRUE == IfDynamicImpact(pMObject,*iter,pIfCheckNextStep))
				{
					return TRUE;
				}
			}
		}
		break;
	}
	return FALSE;
}

//���һ�������Ƿ��ͱ�Ķ�����ײ//
bool	CSSMoveMgr::IfDynamicImpact(ISSMoveObject* pMObjectMove,ISSMoveObject* pMObjectBlock, bool pIfCheckNextStep)
{
	if (!pMObjectBlock->IfCanImpact()) return FALSE;
	if (pMObjectBlock->GetColRadius() == 0) 
		return FALSE;
	//���ݲ�������Ƿ���赲Ŀ��ĵ�ǰ��Ŀ��λ����ײ//
	return CSSMoveTool::IfImpact(pMObjectMove->GetStepMoveTarget(),pMObjectBlock->GetColSphere()) ||
		(pIfCheckNextStep && pMObjectBlock->GetMoveStatus() ==  SSMoveObjectStatus_Move &&  CSSMoveTool::IfImpact(pMObjectMove->GetStepMoveTarget(),pMObjectBlock->GetStepMoveTarget()) );
}
//����ת����������ײ
BOOLEAN CSSMoveMgr::TryTurnDir(ISSMoveObject* pMObject){
	if(pMObject->GetMoveType() != SSMoveObjectMoveType_Dir){
		return FALSE;
	}
	
	ColSphere stepTarget = pMObject->GetStepMoveTarget();
	ColVector nowDir = pMObject->GetDir();
	float nowAngle = atan2f(nowDir.y,nowDir.x);
	if(nowAngle < 0) nowAngle += 3.1415926f*2;
	int nowAngleIndex = nowAngle / 3.1415926f * 4;
	float newAngleArr[4];
	newAngleArr[0] = nowAngleIndex * 3.1415926f / 4;
	newAngleArr[1] = (nowAngleIndex+1) * 3.1415926f / 4;
	newAngleArr[2] = (nowAngleIndex-1) * 3.1415926f / 4;
	newAngleArr[3] = (nowAngleIndex+2) * 3.1415926f / 4;

	TIME_MILSEC now = GetUTCMiliSecond();
	for(int i=0;i<4;i++){
		ColVector newDir(cosf(newAngleArr[i]),sinf(newAngleArr[i]));
		pMObject->SetDir(newDir);
		//�����·����Ƿ����ײ
		pMObject->CalculateStepMoveTarget(now+100);
		if (FALSE == IfStaticImpact(pMObject) && FALSE == IfDynamicImpact(pMObject,FALSE)){
			pMObject->OnStartMove(pMObject->GetDir());
			pMObject->SetRedirectTime(now);
			return TRUE;
		}
	}
	pMObject->SetDir(nowDir);
	return FALSE;
}

//Ѱ��һ��������ײ�Ŀհ׵�
bool CSSMoveMgr::GetAroundFreePos(ColVector pos, ColVector &outPos, ISSMoveObject *pGU, UINT8 ui8MoveGrpID){
	//Ĭ�ϲ�����СΪ50
	//float step = 50;
	//float r = pGU->GetColRadius();
	//֮ǰ���㷨�����ȱ���y����������������
	//���Լ�Ϊ���ģ�����Χ��ɢ��Ѱ��һ�����Է��µİ�ȫ��
	//for(int i=0;i<100;i++){
	//	for(int j=0;j<100;j++){
	//		float x = pos.x + step*i * (i%2==0?1:-1);
	//		float y = pos.y + step*j * (j%2==0?1:-1);
	//		if(FALSE == IfPosImpact(pGU,x,y,r,ui8MoveGrpID)){
	//			outPos.x = x;
	//			outPos.y = y;
	//			return TRUE;
	//		}
	//	}
	//}

	//���㷨����rΪ�뾶������������ByCH20140920
	float radius=pGU->GetColRadius();	//��ײ·��
	int	maxR=100;						//Ѱ�Ұ뾶Ĭ��100
	float step=50;						//Ѱ�Ҳ���Ĭ��50
	float stepI;						//X������������������ѭ���Ѿ��жϹ��ĸ��ӣ�
	for(int r=0;r<maxR;r++)				//�ӽ���Զ��
	{
		for(int j=-r;j<=r;j++)			//��j��
		{
			//����stepX�����м�ո�
			if(j==-r||j==r)
			{
				stepI=1;
			}else
			{
				stepI=r*2;
			}
			for(int i=-r;i<=r;i=i+stepI)	//��i��
			{
				float x=pos.x+i*step;
				float y=pos.y+j*step;
				if(FALSE == IfPosImpact(pGU,x,y,radius,ui8MoveGrpID)){
					outPos.x = x;
					outPos.y = y;
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}

//���һ�����Ƿ����ײ
bool CSSMoveMgr::IfPosImpact(ISSMoveObject* pMObject, float x,float y, float r, UINT8 groupID){
	ColSphere cs;
	cs.c.x = x;
	cs.c.y = y;
	cs.r = r;
	pMObject->SetStepMoveTarget(cs);
	if(IfStaticImpact(pMObject)){
		return TRUE;
	}
	
	/*
	for(hash_set<ISSMoveObject*>::iterator iter = m_allMObjectSet.begin(); iter != m_allMObjectSet.end(); ++iter){
	ISSMoveObject *pTarget = *iter;
	if(pTarget->GetImpactType_Now() == SSMoveObjectImpactType_NoImpact){
	continue;
	}
	if(pTarget->GetImpactType_Now() == SSMoveObjectImpactType_Group && pTarget->GetGroupID() != groupID){
	continue;
	}
	if(CSSMoveTool::IfImpact(pTarget->GetStepMoveTarget(),cs)){
	return TRUE;
	}
	}
	*/

	if (!pMObject->IfCanImpact()) return FALSE;

	SSMoveObjectImpactType impact_type = pMObject->GetImpactType_Now();
	switch (impact_type)
	{
	case SSMoveObjectImpactType_Group:
		{
			hash_set<ISSMoveObject*>& group_set = m_mObjectMap[groupID];
			for (auto it = group_set.begin(); it!= group_set.end(); ++it)
			{
				if (*it == pMObject) continue;
				if(CSSMoveTool::IfImpact((*it)->GetStepMoveTarget(),cs)){
					return TRUE;
				}
			}
			hash_set<ISSMoveObject*>& group_all_set = m_mObjectMap[SSImpactGruop_All];
			for (auto it = group_all_set.begin(); it!= group_all_set.end(); ++it)
			{
				if (*it == pMObject) continue;
				if(CSSMoveTool::IfImpact((*it)->GetStepMoveTarget(),cs)){
					return TRUE;
				}
			}
		}
		break;
	case SSMoveObjectImpactType_ALL:
		{
			for(hash_set<ISSMoveObject*>::iterator iter = m_allMObjectSet.begin(); iter != m_allMObjectSet.end(); ++iter)
			{
				if(*iter == pMObject) continue;
				if(CSSMoveTool::IfImpact((*iter)->GetStepMoveTarget(),cs)){
					return TRUE;
				}
			}
		}
		break;
	}


	return FALSE;
}

bool CSSMoveMgr::ResetPos(ISSMoveObject *pGU, ColVector pos, bool bIfImpact){
	//�Ը�������Ϊ���ģ�Ѱ��һ�����Է��µĵ㣬Ȼ�����ƶ�����λ�á�
	ColVector outPos;
	if(bIfImpact){
		if(FALSE == GetAroundFreePos(pos,outPos,pGU,pGU->GetGroupID())){
			return FALSE;
		}
	}
	else{
		outPos = pos;
	}
	ColSphere sph = pGU->GetColSphere();
	sph.c = outPos;
	pGU->SetStepMoveTarget(sph);
	pGU->Teleport(GetUTCMiliSecond());
	return TRUE;
}

void CSSMoveMgr::SavePathToCache(UINT64 ID, SIntPoint* path, const UINT16 length)
{
	Assert(m_MapCacheMap.find(ID)==m_MapCacheMap.end());
	Assert(length<=c_n32MaxOrderPathNode-1);
	SIntPoint* newPath = new SIntPoint[c_n32MaxOrderPathNode-1]();
	memcpy(newPath,path,length*sizeof(SIntPoint));
	m_MapCacheMap[ID] = newPath;
}

void CSSMoveMgr::DelAllPathCache()
{
	for (auto it=m_MapCacheMap.begin(); it!=m_MapCacheMap.end(); ++it)
	{
		delete [](it->second);
	}
	m_MapCacheMap.clear();
}

}