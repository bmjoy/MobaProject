 #include <hash_set>


#ifndef SSATAR_H_
#define SSATAR_H_

namespace SceneServer{

//����״̬ö��
enum ENodeState{
	eNodeStae_None = 0,
	eNodeState_Open,//���ţ�����
	eNodeState_Close,//�رգ�������
};

//���ڷ���Ѱ·��������ݽṹ
struct SFindPathInfoNew{
	SIntPoint			psStartIntPoint;//���
	SIntPoint			psTargetIntPoint;//Ŀ���յ�
	UINT32				*pDynamicBlockArray;//��̬�赲����
	bool				ifToTarget;//�Ƿ����ߵ�Ŀ��㣬False�����ߵ�Ŀ�����ڸ��Ӽ���
	bool				ifFliter;//�Ƿ�ƽ��
	SIntPoint*			psPathBuff;//���صĽ��������
	INT32				n32PathNodeNum;//���صĽ�������鳤��

	SFindPathInfoNew():
		psStartIntPoint(0,0),
		psTargetIntPoint(0,0),
		pDynamicBlockArray(NULL),
		ifToTarget(FALSE),
		ifFliter(FALSE),
		psPathBuff(NULL),
		n32PathNodeNum(0)
	{
		
	}
};

//���ڱ���������ͼ�ĸ���״̬
struct SAStarRegion{
	UINT16 un16RunTimeID;
	UINT16 un16XRegionIdx;
	UINT16 un16ZRegionIdx;
	UINT16 un16AroundGONum;
	bool	bStaticBlock;
	bool	bDynamicBlock;
	INT8	n8NodeState;
	UINT16	un16GValue;
	UINT16	un16HValue;
	SAStarRegion*	psParentNode;
	SAStarRegion*	psNextOne;
	SAStarRegion():
	un16RunTimeID(0),
	un16XRegionIdx(0),
	un16ZRegionIdx(0),
	un16AroundGONum(0),
	bStaticBlock(false),
	bDynamicBlock(false),
	un16GValue(0),
	un16HValue(0),
	psParentNode(NULL),
	n8NodeState(eNodeStae_None),
	psNextOne(NULL)
	{}

	UINT16	GetFValue(){
		return un16GValue + un16HValue;
	}
};


struct	SAStarRegionBuff{
	INT32		n32CurRegionNum;
	UINT16		un16CurRunTimeID;
	SAStarRegion	*psBeginRegion;

	SAStarRegionBuff():
	un16CurRunTimeID(0),
	n32CurRegionNum(0),
	psBeginRegion(NULL)
	{}

	void	Clear(){
		un16CurRunTimeID = 0;
		n32CurRegionNum = 0;
		psBeginRegion = NULL;
	}

	INT32			Push(SAStarRegion *psRegion){
		psRegion->psNextOne = psBeginRegion;
		psBeginRegion = psRegion;
		n32CurRegionNum++;
		if (0 == un16CurRunTimeID){
			un16CurRunTimeID = psRegion->un16RunTimeID;
		}
		Assert(un16CurRunTimeID == psRegion->un16RunTimeID);
		return eNormal;
	}

	SAStarRegion*	Pop(){
		if (0 >= n32CurRegionNum){
			return NULL;
		}

		SAStarRegion *psTempRegion = psBeginRegion;
		psBeginRegion = psTempRegion->psNextOne;
		n32CurRegionNum--;
		psTempRegion->psNextOne = NULL;
		Assert (un16CurRunTimeID == psTempRegion->un16RunTimeID);
		return psTempRegion;
	}
};

//�ö����ʵ�ֵļ����ýڵ�����
//�߼��Ƚϸ��ӣ���ο����£�http://www.apkbus.com/android-58533-1-1.html
struct	SAStarRegionBuffBinaryTree{
	static const	UINT16 c_maxLength = 100;
	INT32		n32CurRegionNum;//��ǰ�ڵ�����
	SAStarRegion*	data[c_maxLength];//���нڵ�

	SAStarRegionBuffBinaryTree():
		n32CurRegionNum(0)
	{
		Clear();
	}

	void	Clear(){
		n32CurRegionNum = 0;
		memset(data,0,c_maxLength*sizeof(SAStarRegion*));
	}

	//�Ե������ڵ�
	void			Exchange(UINT16 pos1, UINT16 pos2){
		SAStarRegion* pTemp = data[pos1];
		data[pos1] = data[pos2];
		data[pos2] = pTemp;
	}

	//���һ���½ڵ�
	bool			Push(SAStarRegion *psRegion){
		if(n32CurRegionNum >= c_maxLength){
			return FALSE;
		}
		n32CurRegionNum++;
		data[n32CurRegionNum] = psRegion;
		if(n32CurRegionNum <= 1){
			return TRUE;
		}
		//��ʼѭ���滻λ��
		UINT16	un16Pos = n32CurRegionNum;
		while(TRUE){
			UINT16 un16TempPos = un16Pos/2;
			if(data[un16TempPos]->GetFValue() > data[un16Pos]->GetFValue()){
				Exchange(un16TempPos,un16Pos);
				un16Pos = un16TempPos;
				if(un16Pos <= 1){
					break;
				}
			}
			else{
				break;
			}
		}
		return TRUE;
	}

	//��ȡ��СFֵ�Ľڵ�
	SAStarRegion*	PopMiniFValue(){
		if(n32CurRegionNum <= 0){
			return NULL;
		}
		SAStarRegion* returnValue = data[1];
		if(n32CurRegionNum <= 1){
			data[1] = NULL;
			n32CurRegionNum--;
			return returnValue;
		}
		data[1] = data[n32CurRegionNum];
		data[n32CurRegionNum] = NULL;
		n32CurRegionNum--;
		//��ʼѭ���滻λ��
		UINT16	un16Pos = 1;
		while(TRUE){
			UINT16 un16TempPos1 = un16Pos*2;
			UINT16 un16TempPos2 = un16Pos*2+1;
			bool bIfNeedChange = FALSE;
			UINT16 un16ChangePos = -1;
			if(un16TempPos1 <= n32CurRegionNum && data[un16Pos]->GetFValue() > data[un16TempPos1]->GetFValue()){
				bIfNeedChange = TRUE;
				un16ChangePos = un16TempPos1;
			}
			if(un16TempPos2 <= n32CurRegionNum && data[un16Pos]->GetFValue() > data[un16TempPos2]->GetFValue()){
				if(bIfNeedChange){
					//��һ��������Ҫ�滻
					if(data[un16TempPos1]->GetFValue() > data[un16TempPos2]->GetFValue()){
						un16ChangePos = un16TempPos2;
					}
				}
				else{
					bIfNeedChange = TRUE;
					un16ChangePos = un16TempPos2;
				}
			}

			if(bIfNeedChange){
				//��Ҫ�滻
				Exchange(un16Pos , un16ChangePos);
				un16Pos = un16ChangePos;
			}
			else{
				break;
			}
		}
		return returnValue;
	}
};

class CSSAStar
{
private:
	UINT16 m_un16RunTimeID;
	UINT16 m_un16XRegionNum;//���
	UINT16 m_un16ZRegionNum;//�߶�
	UINT32	m_un32TotalRegionNum;//����
	SAStarRegion *m_pcRegionList;//�����б�
	bool*	m_staticBlockArray;//��̬�赲�б�

	SAStarRegionBuffBinaryTree	m_sOpenRegionBuff;
	SAStarRegionBuff			m_sTempRegionBuff;

	bool			IfAStarImpact(UINT16 x,UINT16 y,UINT32 *pDynamicBlockArray);


public:
	CSSAStar();
	~CSSAStar();
	void			Init(UINT16	width, UINT16 height, bool* staticBlockArray);

	//����Ѱ·����
	INT32			FindPath(SFindPathInfoNew &rsFindPathInfo);
	//���������ȡ����
	SAStarRegion*	GetAStarRegionByIdx(UINT32 un32Idx);
	SAStarRegion*	GetAStarRegionByIdx(UINT16 un16XIdx, UINT16 un16ZIdx);
	//��ȡһ��������Χ���и��ӣ����8��
	INT32			GetAroundRegion(SAStarRegion *pcCenterRegion, SAStarRegion *apsAroundRegion[c_n32AroundAStarRegionNum]);
	//ͨ���������ӻ�ȡ��Է���
	EIntDir			GetRegionDir(SAStarRegion *cpsBeginRegion,SAStarRegion *&cpsEndRegion);
};

}

#endif

