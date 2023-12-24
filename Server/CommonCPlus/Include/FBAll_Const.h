#pragma once
#include "PreDefine.h"
#include "WYYTools/Vector3D.h"
#include "ServerMath.h"
#include <string>
#include <vector> 
#include <time.h>
#include <atltime.h>
#include <sstream>
#include "boost/spirit.hpp" 
#include "boost/algorithm/string.hpp"
#include <random>

#include <map>
#include <hash_map>

//ע�⣺��Ҫ�����ڴ��ļ����ȫ�����ݣ�����ÿ��Server���
using namespace std;
	enum EVENT_TYPE
	{
		EVT_NONE,
		EVT_ON_CS_REGISTERED,
		EVT_ON_CS_DISCONNECT,
		EVT_ON_SS_REGISTERED,
		EVT_ON_SS_DISCONNECT,
		EVT_ON_GS_REGISTERED,
		EVT_ON_GS_DISCONNECT,
		EVT_SS2CS_SyncAllGameInfo,
	};

const	INT32	c_n32MaxInt32 = 0xffffffff / 2;
const	UINT32	c_un32MaxUInt32 = 0xffffffff;
const	INT32	c_n32DefaultBufferSize = 4096;
const	TIME_TICK	c_tDefaultPingCDTick = 1000 * 160;
const	TIME_TICK	c_tSSPingCSCDTick = 1000 * 10;//20��CSδ�յ�SS��Ϣ�򲻷���ս��//
const	TIME_TICK	c_tUserPingCDTick = 1000 * 180;
const	TIME_TICK	c_tDefaultPingCDTickFromClient = 1000 * 180;

const	INT32	c_n32DefaultNameLen = 30;
const	INT32	c_n32DefaultNickNameLen = 32;
const	INT32	c_n32DefaultUserPwdLen = 33;
const	INT32	c_n32DefaultDeviceKeyLen = c_n32DefaultNameLen * 5;
const	INT32	c_n32ProjectileMaxChildProjectileType = 3;
const	INT32	c_n32DefaultRemoveConsoleKeyLen = 65;

const	INT32	c_n32MaxOrderPathNode = 30;
const	UINT32		c_un32MaxUserInBattleCamp = 3;
const	UINT32		c_un32MaxObserverInBattle = 2;
const	UINT32		c_un32MaxUserInBattle = c_un32MaxUserInBattleCamp * 2;
const	UINT32		c_un32MaxAllUserInBattle = c_un32MaxUserInBattle + c_un32MaxObserverInBattle;
const	UINT32		c_un32TipsToSelectHeroTime = 1000 * 50;
const	UINT32		c_un32BattleSelectHeroTimeoutMilsec = 1000 * 60;
const	UINT32		c_un32BattleLoadingTimeoutMilsec = 1000 * 60;
const	UINT32		c_un32PlayingBattleTimeoutMilsec = 1000 * 3600 * 2; //
const	UINT32		c_un32MaxTimeWaitAllUserOffline = 1000 * 180;
const	UINT32		c_un32BattleShowResult = 1000 * 6;
const	UINT32		c_un32CombatSettlementTime = 1000 * 12;
const	UINT32		c_un32PlayVictoryVideoTime = 1000 * 6;
const	UINT32		c_un32StoreDBDataCDMilsec = 1000 * 60 ;//* 30;
const	UINT32		c_un32ShowTime = 1000 * 10;
const	UINT32		c_un32GlobalObjBeginIdx = 100000000;
const	UINT32		c_un32ObjTypeSpace = 10000;
const	UINT8		c_un32GoodsBagNum = 2;
const	UINT8		c_un32GridNumOfBag = 3;
const	UINT8		c_un32MaxGridNum = c_un32GoodsBagNum * c_un32GridNumOfBag;
const   UINT32		c_un32HeroMaxBornPos	= 6;
const   UINT32		c_n32DefaultFilePathLen     = 32;
const	UINT32		c_un32MaxGoodsDownInfoNum = 10;
const	UINT32		c_un32MaxItemEffectNum = 10;
const	UINT32		c_un32MaxSenceTypeNum = 3;
const	UINT32		c_un32MaxGoodsChildNum = 512;
const	UINT32		c_un32MaxRunesNum = 512;
const	UINT32		c_un32MaxRunesSlot = 9*20;
const	TIME_MILSEC		c_tDefaultNPCBornCDMilsec = 30;

const	INT32		c_n32MiniDistToTar = 25;
const   UINT32		c_un32DefaultRadius = 5;
const	INT32		c_n32MaxSkillEffectNum =3;
const	INT32		c_n32MaxSkillBuffNum =3;
const	INT32		c_n32MaxNPCSkillNum = 5;
const	INT32		c_n32MaxHeroSkillNum = 7;
const	INT32		c_n32MaxHeroSkillNum_ex = 9;

const	INT32		c_n32MaxHeroPassitiveSkillNum = 3;
const	INT32		c_n32NormalAndGasHeroSkillNum = 4;
const	INT32		c_n32MaxGoodsSkillNum = 1;
const INT32			c_n32CellSize = 100;
const INT32			c_n32MiniCollideRadius = 0;
const INT32			c_n32HalfCellSize = 25;
const INT32			c_n32AreaCellNum = 32;
const INT32			c_n32MAxBattlePwdLen = 6;
const INT32			c_n32MaxAbsorbAttriChangeNum = 13;
const	INT32		c_n32MaxMoveSpeed = 1100;
const INT32 c_n32MapDefaultValue = 2;	//the default value of map position proportion 
const INT32 c_n32FindPathDefaultArrNom = 20;
const INT32 c_n32DefaultBlance = 1000;
const INT32 c_n32DefaultBlockStopTime = 1000;
const INT32 c_n32StopBlockNum = 2; //max block time, so this obj stop action
const UINT32 c_un32InValidBattleID = 0;
const UINT32	c_un32MaxBuffCollideNum = 20;
const INT64   c_un32MaxAroundCell = 20;
const UINT32		c_un32MaxHeroLevel = 15;
const UINT32	c_un32HeroMinAbsorbLevel = 3;
const UINT32	c_un32HeroMidAbsorbLevel = 7;
const INT32		c_n32MaxAbsorbSkillNum = 2;
const INT32		c_n32AbsorbTimeout = 1000 * 3;
const INT32		c_n32CloseDist = 5;
const UINT16  c_un16MaxPatrol = 3;
const UINT16  c_un16MaxMonster = 6;
const UINT16  c_un16NoticeLen = 32; 
const UINT32 c_un32NpcGivenFury = 5;
const UINT32 c_un32HeroGivenFury = 40;
const UINT32 c_un32PerFuryValue = 120; 
const UINT32 c_un32FuryRunTime = 18 * 1000;
const UINT32 c_un32RecoverCpTime = 1 * 1000;
const INT32	c_n32DefaultBlockMilsec = 0;
const UINT32 c_un32MoveTarMaxBlockTick = 3000;
const INT32	c_n32DefaultFreeAlarmCDTick = 3000;
const UINT32 c_un32IntervalSendPos = 500;
const UINT32  c_un32CheckMaxSkillTargetNum = 100;
const UINT32 c_un32DefaultGoodsSkillIdx = 85000;
const INT32 c_n32MaxNextSkillEffectCfgNum = 16;
const INT32 c_n32MaxDependSkillEffectCfgNum = 16;
const INT32 c_n32MaxEffectCaculateCateNum = 16;
const INT32 c_n32MaxGameUnitBuffNum = 32;
const INT32	c_n32MaxBattleInSS = 200;

const INT32	c_n32MaxEffectAddNum = 2048;
const UINT32 c_un32AddBattleCost = 35;
const INT32  n_c32SkkEffectNum = 32;
const INT32  n_c32NPCNum = 5;
const INT32 n_c32SkillTriggerRate = 1000;

const INT32 c_n32MaxLimits = 2147483647;
const UINT32 c_un32MaxLimits = 4294967295;
const INT32	c_n32MaxlongExpireSolierTime = 1000 * 60 * 3;
const INT32	c_n32OccupyWalkCheckTimeSpan = 500;

const UINT32 c_n32GuideStepLen = 128;
const UINT32 c_n32GuideBlStepLen = 64;

const TIME_MILSEC PersistTimeAlways = -1;
const UINT8 c_un8MaxCLDaysReward = 7;
//MilSec To time
const UINT64 c_unOneDayMilSec = 1000 * 60 * 60 * 24;
const UINT64 c_unOneHourMiSec = 1000 * 60 * 60;
const UINT64 c_unOneMinMiSec = 1000 * 60;

const UINT32 c_OneDaySec = 24 * 60 * 60;
// Battle end compute
// const UINT16 c_un16BattleWinBaseGold = 200;

//��������ϵͳ��ʼ
const INT32	n_cPassiveSkillTriggerNum = 64;
//OB
const INT64 c_n64OBUserDefaultId = 3000000; 

const INT32	c_n32DefaultPerCp = 400;

const INT32 c_n32MaxWhileNum = 999;

const INT32 c_n32EnterTimeOver = 60000;

const UINT8 c_un8MaxFriends = 50;
const UINT8 c_un8MaxBlacklist = 50;
const UINT16 c_un8MaxMsgLength = 360; 
const UINT8 c_un8MaxMsgSave = 100; 
const UINT32 c_un32MinOpertionTime = 10 * 1000;

const UINT32 c_un32FriendsLen = 1024; 
const UINT32 c_un32HeroListLen = 128; 
 
const UINT8	c_un8MaxNickNameQuery = 10; 

const INT32 c_NoticeLen = 512;

const UINT64  c_DefaultUserIdx = 10000;
const UINT32  c_DefaultSaveTimeSpace = 180000;

const INT32	  c_BattleTimeOut = 360000;
const INT32   c_BattleLogTimeSpace = 120;

const INT32   c_MaxMailN = 50; 
const INT32   c_MailTitleLen = 64;
const INT32   c_MailContenLen = 256; 
const INT32   c_MailGiftLen = 128; 
const INT32   c_MailSenderLen = 32; 
const INT32   c_MailGetLen = 32;
const INT32   c_MailCreateTimeLen = 32;
const INT32   c_MailEndTimeLen = 32;

const INT32	c_n32MaxPathNumInBattle = 3;
const INT32	c_n32AroundAreaNum = 9;
const UINT32  un32MapObjNum = 100;
const UINT32  c_n32DefaultXCellNum = 400;
const UINT32  c_n32DefaultZCellNum = 400; 

/******************************************************/ 
//hero reborn ���
const INT32		c_BaseRebornTimes = 3;
const INT32		c_FirBuyRebornCost = 1;
const INT32		c_SecBuyRebornCost = 5;
const INT32		c_ThrBuyRebornCost = 9;
const INT32		c_VipBuyRebornCost = 3;
const INT32		c_MinusRebornTimes = -1;
/******************************************************/ 
//��ɱ����ɱ���������
const INT32		c_MaxConKillBetween = 10 * 1000;
const INT32		c_MaxAssKillBetween = 10 * 1000;
const INT32		c_MaxValidBetween = 6 * 1000;
const INT32		c_MaxContinueKills = 3;

const INT32		c_n32BaseExp = 50;
const INT32		c_n32CoefficientExp = 22;
const double		c_fLvPowerExp = 1.1;

const INT32		c_n32BaseCP = 240;
const INT32		c_n32CoefficientCP = 6;
const INT32		c_n32RangeOneBaseCP = 80;
const INT32		c_n32RangeOneCoefCP = 14;
const INT32		c_n32RangeTwoBaseCP = 30;
const INT32		c_n32RangeTwoCoefCP = 15;

const INT32		c_FirstBloodReward = 210;
const INT32		c_n32EndKillingSpreeReward = 100;
const INT32		c_n32EndDomanatingReward = 200;
const INT32		c_n32EndMegaKillReward = 300;
const INT32		c_n32EndUnstoppableReward = 400;
const INT32		c_n32EndWhickedSickReward = 500;
const INT32		c_n32EndMonsterKillReward = 600;
const INT32		c_n32EndGodLikeReward = 700;
const INT32		c_n32EndHolyShitReward = 800;

/******************************************************/ 
//��ɱӢ�����

/******************************************************/ 
//ս���������
//Exp
const INT32		c_ExpTimelineBegin = 20;
const INT32		c_ExpTimelineEnd = 40;
const INT32		c_ExpTimeFixed = 20;

const float		c_fWELvPower = 1.3;
const INT32		c_WETimeCoef = 2;
const INT32		c_WELvCoef = 2;
const INT32		c_WEBase = 125;

const float		c_fLELvPower = 1.1;
const INT32		c_LETimeCoef = 1;
const INT32		c_LELvCoef = 1;
const INT32		c_LEBase = 100;
//gold
const INT32		c_GTimelineBegin = 10;
const INT32		c_GTimelineMid = 20;
const INT32		c_GTimelineEnd = 55;
const INT32		c_GTimeFixed = 20;

const INT32		c_FWGTimeCoefOne = 20;
const INT32		c_FWGBase = 200;
const INT32		c_FWGTimeCoefTwo = 2;

const INT32		c_WGTimeCoef = 10;
const INT32		c_WGBase = 100;

const INT32		c_LGTimeCoef = 3;
const INT32		c_LGBase = 30;
/************************************************/
//buy reborn
const INT64		c_n64BuyRebornPrice = 0;
const INT64		c_n64vipBuyRebornCost = 0;
const INT16		c_n16MinusRebornTimes = -1;

/************************************************************************/
const INT64		c_MaxHeroClientMatch = 101000;

/******************************************************/ 
//��־�������
#define gSign "$$"
#define gSignTab "\t"
#define gSignPoint ","
#define gSignSemIc ":"
#define gSignPartSemIc ";"
#define gSignSplitIc "|"
 
/******************************************************/ 

enum EConstEnum{
	eObjLevel1Inter = 10000,
	eObjLevel2Inter = 1000,
	eObjLevel3Inter = 100,
};

enum ERunePosType{
	eRunePosType_Bag = 0,
	eRunePosType_Slot
};

enum EServerNetState{
	eSNS_Closed = 0,
	eSNS_Connecting,
	eSNS_Free,
	eSNS_Busy,
	eSNS_Full,
};

enum ERunesPosType{
	eRunesPosType_Bag,
	eRunesPosType_Slot,
	eRunesPosType_Invalid,
};

enum	EFBAllErrorCode{
	//Server model error code.
	eEC_Begin = -0x00010000 * 2,
	eEC_InvalidModelStatus, //�Ƿ���ģ��״̬
	eEC_InvalidModelID, //�Ƿ���ģ��ID
	eEC_InvalidGSID, //�Ƿ���GSID
	eEC_InvalidSSID, //�Ƿ���SSID
	eEC_NullDataSource, //�Ҳ�������Դ
	eEC_NullObjMgr, //�Ҳ���ObjMgr
	eEC_NullDataMgr, //�Ҳ���DataMgr
	eEC_NullWorldMgr, //�Ҳ���WorldMgr
	eEC_NullSceneServer, //�Ҳ���SceneServer
	eEC_NullGateServer, //�Ҳ���GateServer
	eEC_NullCentralServer, //�Ҳ���CentralServer
	eEC_InvalidUserPwd, //�Ƿ����û�����
	eEC_InvalidPosition, //�Ƿ���λ��
	eEC_InvalidRegionID, //�Ƿ�������ID
	eEC_InvalidAreaID, //�Ƿ�������ID
	eEC_NetSessionCollide, //����Ự��ͻ
	eEC_NullUser, //�Ҳ����û�
	eEC_UserExist, //�û��Ѿ�����
	eEC_GameObjectAlreadyExist, //��Ϸ�����Ѿ�����
	eEC_NullGameUnit, //�Ҳ�����Ϸ��Ԫ
	eEC_LoadLibarayFail, //����ģ��ʧ��
	eEC_OpenCfgFileFail, //�ҿ������ļ�ʧ��
	eEC_NoneNetListener, //û�����������
	eEC_NoneNetConnector, //û������������
	eEC_OpenConnectorFail, //������������ʧ��
	eEC_TooManyConnectorOpened, //����̫�������
	eEC_InitModelTimeOut, //��ʼ��ģ��ʧ��
	eEC_StartModelTimeOut, //����ģ�鳬ʱ
	eEC_NullMasterUser, //�Ҳ������û�
	eEC_InvalidAttackTarget, //�Ƿ��ļ���Ŀ��
	eEC_NetConnectionClosed, //���������Ѿ��ر�
	eEC_NetProtocalDataError, //����Э�����ݴ���
	eEC_TooManySSNum, //SS��������
	eEC_TooManyGSNum, //GS��������
	eEC_InvalidNetState, //�Ƿ�������״̬
	eEC_JustInBattle, //��ǰ����ս����
	eEC_InvalidBattlePos, //�Ƿ���ս����λ
	eEC_TheBattleUserFull, //ս���û�����
	eEC_UserDonotInTheBattle, //�û�����ս��֮��
	eEC_JustNotInBattle, //��ǰ����ս��֮��
	eEC_InvalidBattleState, //�Ƿ���ս��״̬
	eEC_InvalidBattleID, //�Ƿ���ս��ID
	eEC_HeroExist, //Ӣ���Ѿ�����
	eEC_InvalidUserNetInfo, //�Ƿ����û�������Ϣ
	eEC_BattleExist, //ս���Ѿ�����
	eEC_BattleDonotExist, //ս�۲�����
	eEC_MapLoaded, //��ͼ�Ѿ�����
	eEC_BattleLocalObjIdxOverflow, //ս�۱��ض������
	eEC_CannotFindoutTheObject, //�Ҳ�������
	eEC_NullHero, //�Ҳ���Ӣ��
	eEC_NotAllUserReady, //���������û��Ѿ�׼����
	eEC_YouAreNotBattleManager, //�㲻��ս�۹���Ա
	eEC_InvalidOrderCate, //�Ƿ���Order���
	eEC_InvalidGameObjectCamp, //�Ƿ�����Ϸ������Ӫ
	eEC_CreateOrderFail, //����Orderʧ��
	eEC_InvalidOrderState, //�Ƿ���Order״̬
	eEC_OrderNoMasterGO, //Orderû��������
	eEC_AbsentOrderPriority, //Order���ȼ�����
	eEC_NullBattle, //�Ҳ���ս��
	eEC_MoveBlocked, //�ƶ����赲
	eEC_ReadCfgFileFail, //��ȡ�����ļ�ʧ��
	eEC_TooManyNPCCfgNum, //NPC��������̫��
	eEC_TooManyHeroCfgNum, //Ӣ����������̫��
	eEc_TooManMapDataCfgNum, //��ͼ��������̫��
	eEC_InvalidHeroSeat, //�Ƿ���Ӣ����λ
	eEC_InvalidMapID, //�Ƿ��ĵ�ͼID
	eEc_InvalidPos, //�Ƿ���λ��
	eEC_InvalidCellID, //�Ƿ��ĵ�Ԫ��ID
	eEC_NullArea, //�Ƿ�������
	eEC_InvalidScriptParameters, //�Ƿ��Ľű�����
	eEC_InvalidObjTypeID, //�Ƿ��Ķ�������ID
	eEC_InvalidPathNodeNum, //�Ƿ���·���ڵ�����
	eEC_InvalidVector3D, //�Ƿ���3D����
	eEC_UserInfoUnComplete, //�û���Ϣ��ȫ
	eEC_GenerateGUIDFail, //����GUIDʧ��
	eEC_NotEnemy, //û�е���
	eEC_NotNormalAttackSkill, //û����ͨ��������
	eEC_CanNotFindTheSkill, //�Ҳ���ָ������ID
	eEC_NotOrderInfo, //û��Order��Ϣ
	eEC_InvalidSkillID, //�Ƿ��ļ���ID
	eEC_InvalidSkillState, //�Ƿ��ļ���״̬
	eEC_InvalidSkillTarget, //�Ƿ��ļ���Ŀ��
	eEC_NullSkillData, //û�м�������
	eEC_InvalidGameObjectCate, //�Ƿ�����Ϸ��������
	eEC_HasChoosedHero, //�Ѿ�ѡ����Ӣ��
	eEC_OthersHasChoosedHero, //
	eEC_HasNoTheHero,
	eEC_AbsentAttackDistance, //�������벻��
	eEC_TargetIsDead, //Ŀ���Ѿ�����
	eEC_InvalidTargetActionState, //Ŀ����Ϊ״̬�Ƿ�
	eEC_InvalidBattle, //�Ƿ���ս��
	eEC_TheBattlIsFull,	 //ս���Ѿ���Ա
	eEC_BattlePDWNotMatch, 
	eEC_NullGameObject,//�Ҳ�����Ϸ����
	eEC_NULLNickName, //�Ҳ����ǳ�
	eEC_TimeExpire, //ʱ�䳬ʱ
	eEC_NoneAvailbleBuff, //û����ЧBUFF
	eEC_BuffOverlapUpperLimit, //����BUFF����
	eEC_InvalidCurHPNum, //�Ƿ��ĵ�ǰHP
	eEC_InvalidCurMPNum, //�Ƿ��ĵ�ǰMP
	eEc_NoPathNode, //�Ҳ���·���ڵ�
	eEC_InvalidBuffTypeID, //�Ƿ��Ļ�������ID
	eEC_AbsentSkillDistance, //���ܾ��벻��
	eEC_BuildingCanNotMove, //���������ƶ�
	eEC_AbsentCP, //CP����
	eEC_AbsentMP, //MP����
	eEC_AbsentHP, //HP����
	eEC_BuildingCanNotAddBuff, //�����������BUFF
	eEC_InvalidActionState, //�Ƿ�����Ϊ״̬
	eEC_JustSkillAction,  //����ʹ�ü���
	eEC_AbsorbMonsterFailForLackLevel, 
	eEC_AbsorbMonsterFailForHasFullAbsorb,
	eEC_AbsorbMonsterFailForHasSameSkillID,
	eEC_AbsorbMonsterFailForLackCP,
	eEC_AbsorbMonsterFailForMonsterDead,
	eEC_AbsorbMonsterFailForMonsterCannotBeConstrol,
	eEC_AbsorbMonsterFailForHeroDead,
	eEC_AbsorbMonsterFailForNotMonster,
	eEC_AbsorbMonsterFailForDiffNPC,
	eEC_AbsorbMonsterFailForErrorState,
	eEC_AbsorbMonsterFailForDizziness,
	eEC_NULLNPC, //�Ҳ���NPC
	eEC_NULLCfg, //�Ҳ���������Ϣ
	eEC_InvaildSkillID, //�Ƿ��ļ���ID
	eEC_RemoveAbsorbSkillFailed, //�Ƴ���������ʧ��
	eEC_StateCanNotUseGas,
	eEc_ExistWildMonsterBornPos, 
	eEc_InvalidControlNPCType,
	eEC_GasExplosionNotFull,
	eEC_MultiAbsortNotAllowed,
	eEC_StaticBlock, //��̬�赲
	eEC_DynamicBlock, //��̬�赲
	eEC_NoDistanceToMove, //û�о�����Ҫ�ƶ�
	eEC_CannotFindFullPathNode, //�Ҳ���������·��
	eEC_HeroNotDead, //Ӣ��û������
	eEC_NotEnoughGold, //��Ҳ���
	eEC_NoRebornTimes,
	eEC_BattleIsPlaying,
	eEC_RemoveBuffFailed,	
	eEc_DeadAltar,
	eEC_InvaildCampID,
	eEC_NotInSameBattle,
	eEC_AskBuyRunesFail,
	eEC_AskComposeRunesFail,
	eEC_AskUnUseRunesFail,
	eEC_AskUseRunesFail,
	eEC_AskMoveGoodsFail,
	eEC_AskSellGoodsFail,
	eEC_InvaildGridID,
	eEC_AskUseGoodsFailForCoolDown,
	eEC_rInvalidGoodsNum,
	eEC_AskBuyGoodsFailForLackCP,
	eEC_AskBuyGoodsFailForInvalidCPType,
	eEC_AskBuyGoodsFailForHasSameTypeID,
	eEC_AskBuyGoodsFailForHasFunType,
	eEC_AskBuyGoodsFailForBagFull,
	eEC_CannotCreateVoipServer,
	eEc_AttackOneObj,
	eEc_ExistObj,
	eEc_TheSkillEnd,
	eEc_ErrorSkillId,
	eEc_InvalidMastType,
	eEC_NickNameCollision, //�ǳƳ�ͻ
	eEC_ObjectAlreadyExist,
	eEC_ForbitAbWMSolder, //��������Ұ�ֱ�
	eEC_TargetCannotLooked,//Ŀ�겻������
	eEC_ErrorAreaId,//�����areaId
	eEc_NoWatchUser,//û�й۲���
	eEc_MaxBornSolder,
	eEC_AddBattleFailForLackOfGold,
	eEC_CampNotBalance,
	eEC_AskBuyGoodsFailForSole,

	eEC_TimeOut,
	eEC_AddEffectFailed,
	eEC_EffectEnd,

	eEC_UseSkillFailForSilenced,
	eEC_UseSkillFailForDisarmed,
	eEC_UseSkillFailForLackHP,
	eEC_UseSkillFailForLackMP,
	eEC_UseSkillFailForLackCP,
	eEC_UseSkillFailForSkillCoolDown,
	eEC_UseSkillFailForNULLTarget,
	eEC_UseSkillFailForBuildingNullity,

	eEC_UseGoodsFailForDizziness,
	eEC_UseGoodsFailForBuildingNullity,
	eEC_UseGoodsFailForNULLTarget, 
	eEC_UseGoodslFailForSilenced,
	eEC_UseGoodslFailForErrorCamp,
	eEC_UseSkillGasNotInRunState,
	eEC_UseSkillGasHasInRunState,
	eEC_NoAbsorbSkill,

	eEC_UseSkillFailForDizziness,
	eEC_AskBuyGoodsFailForLackTeamCP,
	eEC_CanntAbsorb,
	eEC_SkillPrepareFailed,
	eEC_CancelSkillOrderFailed,

	eEC_TheBattleObserverNotFull,
	eEC_TheBattleObserverFull,
	eEC_BeginBattleFailForNullPlayer,
	eEC_AddBattleFailForAllFull,
	eEC_AddBattleFailForUserFull,
	eEC_WarningToSelectHero,
	eEC_GuideNotOn,
	eEC_HasCompGuideStep,
	eEc_InvalidStepId,
	eEc_DelAbsorbICOFailed,
	eEC_AbsorbMonsterFail,
	eEC_ZeroGUID,
	eEc_NoObjList,

	eEC_JustInThatSeatPos,
	eEC_NickNameNotAllowed,
	eEc_InvalidTarget,	//����Ķ���:����
	eEC_GUDead,
	eEC_TooManyUserInBattle,
	eEc_NoAtkObj,
	eEC_InvalidMapInfo,
	eEc_InvalidMapId,
	eEc_NullLuaCfg,
	eEC_NullMapCfg,
	eEC_LoadFilterCfgFailed,
	eEC_RemoveEffectFailed,
	eEC_UserNotExist,
	eEC_BattleFinished,

	eEC_UserWasInFriendList,
	eEC_UserWasInBlackList,
	eEC_UserNotOnline,
	eEC_MsgTooLarge,
	eEC_UserRefuseReceiveYourMsg,
	eEC_UserOfflineFull,

	eEC_HaveBuySameGoods,
	eEC_BuyGoodsFailedLackGold,
	eEC_BuyGoodsFailedLackDiamond,
	eEc_ExistGuidCfg,
	eEC_NullInfo,
	eEC_UserRSExist,
	eEc_ErrorGuideStepId,
	eEc_invalidObjId,
	eEC_NothingContent,
	eEc_DoneDBWrong,
	eEC_AskTooFrequently,
	eEC_UserOfflineMsgFull,
	eEc_InvalidAbsorbTar,
	eEC_BeginAIFailed,
	eEC_CanNotUseChinese,

	eEC_TipsObjAppear,
	eEC_TipsNPCBorn,
	eEC_TipsSuperNPCBorn,
	eEc_ErrorType,
	eEC_FriendsListFull,
	eEC_BlackListFull,
	eEC_JustInFriendsList,
	eEC_JustInBlackList,
	eEC_NullUserRSInfo,
	eEC_UserBusy,
	eEC_YouInOppositeBlackList,
	eEC_CounterpartFriendListFull,
	eEC_UserInYourBlackList,
	eEC_AskHaveSend,
	eEc_existBattle,
 	eEC_CannotBuygoodsWhenDeath,
	eEc_TimeToSaveDB,

	eEc_91LoginFail,
	eEc_91InvalidAppID,
	eEc_91InvalidAct,
	eEc_91InvalidPara,
	eEc_91InvalidSign,
	eEc_91InvalidSessionID,

	eEc_UserNotHaveHero,
	eEC_CannotSellgoodsWhenDeath,
	eEC_PPUserNameRuleWrong,
	eEC_PPUserNotExist,
	eEC_PPInvalidAct,
	eEC_PPUserExisted,
	eEC_PPPwdCheckError,
	eEC_PPUserProhibited,
	eEC_PPDataError,
	eEC_PPSessionTimeout,
	eEC_PPUserHaveBinding,

	eEC_TBInvalidToken,
	eEC_TBInvalidFormat,

	eEc_FunClosed,
	eEC_BattleClosing,	//��������
	eEC_InvalidPwdLength,
	eEC_PleaseEnterPwd,
	eEC_InvalidUserNameLegth,

	eEC_NullPointer,
	eEC_InvalidMsgProtocalID,
	eEC_NullMsgHandler,
	eEc_InvalidGUID,
	eEC_NullMsg,
	eEC_InvalidNSID,
	eEC_GUIDCollision,
	eEC_InvalidUserName,
	eEc_InvalidMailId,
	eEC_UserOfflineOrNullUser,
	eEC_UserWasPlaying,
	eEC_RequestSended,
	eEC_AddFriendSeccuse,
	eEC_OppositeSideFriendFull,
	eEC_ReEnterRoomFail,//�ؽ�����ʧ��
	eEC_DiamondNotEnough,
	eEC_ParseProtoError,//����PB����
	eEC_UnKnownError,//δ֪����//
	eEC_ErrorTimes,
	eEC_MatchLinkInvalid,//ƥ��������ʧЧ//
	eEC_AddMatchTeamError,//����ƥ�����ʧ��
	eEC_NotEnoughItem,		//item number not enough
	eEC_DidNotHaveThisItem,    
	eEC_UserRefuseAddFriends,
	eEC_MatchTeamateStoped,//�ȴ�ƥ�����
	eEc_ExistGuideTaskId,	//���ڵ�����id
	eEC_UnknowPlatform,
	eEC_MsgAnalysisFail,
	eEC_PostLoginMsgFail,
	eEC_NickNameTooShort,
	eEC_GuideUserForbit,
	eEC_InvalidCDKey,
	eEC_WashRuneFail,
	eEC_GetCDKeyGiftSuccess,

	eEc_MailHasTimeOver, //�ʼ��ʼ�����
	eEc_MailHasRecv, //�ʼ��Ѿ���ȡ 
	eEC_HavedPerpetualHero,
	eEC_InvalidPara,
};

enum eGoodsState{
	eGoodsState_Free,
	eGoodsState_Pending
};

struct SIPAddr 
{
	CHAR	aszIPAddr[16];
	SIPAddr() { memset(aszIPAddr,0,16); }
};

enum	EUserPlayingStatus
{
	eUserPlayingStatus_OffLine = 0,
	eUserPlayingStatus_Playing,
};

enum EPayType{
	ePayType_None = 0,
	ePayType_Gold = 1,
	ePayType_Diamond = 2,
};

enum EFBAllProtocalSpace
{
	eFBAllProtocalSpace_GameClient = 0,
	eFBAllProtocalSpace_CentralServer,
	eFBAllProtocalSpace_SceneServer,
	eFBAllProtocalSpace_GateServer,
	eFBAllProtocalSpace_BalanceServer,
	eFBAllProtocalSpace_LoginServer,
};

enum EBattleState
{
	eBS_Free = 0,
	eBS_Waiting,
	eBS_SelectHero,
	eBS_ShowHero,
	eBS_Loading,//Not in SS
	eBS_Playing,//Start in SS
	eBS_ShowResult,//GC had��SS no��CS had but do nothing.
	eBS_Finished,//All had.
	eBS_GuideFinished,//Only SS had.
	eBS_End,//Only a end flag.
};

enum	ECSModelID
{
	eCSModelID_Kernel = 0,
	eCSModelID_UserMgr,
	eCSModelID_BattleMgr,
	//eCSModelID_GameEntityMgr,
	//eCSModelID_AIMgr,
	eCSModelID_End,
};

enum	ESSModelID
{
	eSSModelID_Kernel = 0,
	eSSModelID_UserMgr,
	eSSModelID_BattleMgr,
	//eSSModelID_WorldMgr,
	//eSSModelID_ObjMgr,
	eSSModelID_End,
};

enum	EGSModelID
{
	eGSModelID_Kernel = 0,
	eGSModelID_End,
};

enum EUserPlatform{
	//ios
	ePlatform_PC = 0,
	ePlatformiOS_91 = 1,
	ePlatformiOS_TB = 2,
	ePlatformiOS_PP = 3,
	ePlatformiOS_CMGE = 4,
	ePlatformiOS_UC = 5,
	ePlatformiOS_iTools = 6,
	ePlatformiOS_OnlineGame = 7,
	ePlatformiOS_As = 8,
	ePlatformiOS_XY = 9,
	ePlatformiOS_CMGE_ZB =  10,
	

	//android
	ePlatformAndroid_CMGE = 104,
	ePlatformAndroid_UC = 105,

	//����
	ePlatformiOS_CMGEInfo = 304,
	//RC use
	ePlatform_All = 1000,
};

enum ServerState
{ 
	Fluent = 0,//����
	Busy = 1,//��mang
	HouseFull = 2,//��
};


enum EClientOS
{
	eCOS_IOS,
	eCOS_Android,
};

enum EUserLoginWay
{
	eULW_None = 0,
	eULW_QuickLogin,
};

enum EPreDefine_ErrorCode
{ 
	eEC_UseSkillTargetWrongType = -14,//ʹ�ü��ܴ��������
	eEC_UseSkillTargetWrongCamp = -13,//ʹ�ü��ܴ������Ӫ
	eEC_UseSkillTargetIsDead = -12,//ʹ�ü���Ŀ���Ѿ�����
	eEC_OverTime = -4,
	eEC_InsertFail  = -3,
	eEC_ConstInvalid = -2,
	eEC_OperatePending = -1,
	eNormal = 0,
};

enum ERunesConsumeType
{
	eRunesConsumeType_Diamand = 1,
	eRunesConsumeType_Gold,

	eRunesConsumeType_None
};
enum EUserCate
{
	eUserCate_Admin = 0,
	eUserCate_GM,
	eUserCate_Robot,
	eUserCate_DiamondVIP,
	eUserCate_GloldVIP,
	eUserCate_SilverVIP,
	eUserCate_CopperVIP,
	eUserCate_Normal,
};

enum EAttendantCate{
	eAC_None = 0,
	eAC_AddHP,
	eAC_AddMP,
	eAC_AddAttack,
	eAC_AddDefense,
};

enum EMagicCate{
	eMC_Physical,
	eMC_Water,
	eMC_Fire,
	eMC_Grass,
	eMC_Thunder,
};

enum EAICate{
	eAICate_None = 0,
	eAICate_Occupate,
	eAICate_Guard,
	eAICate_Patrol,
	eAICate_End,
};

enum EAttackMode{
	eAM_Passive = 0,
	eAM_Active,
};

enum ERace{
	eRace_APE,
	eRace_Primeval,
	eRace_Amphibian,
	eRace_Ghost,
};

enum ERunesOP{
	eRunesOP_BUY,
	eRunesOP_USE,
	eRunesOP_UNUSE,
	eRunesOP_Compose
};

enum	EObjectType
{
	eObjectType_None = 0,
	eObjectType_Guild,
	eObjectType_User,
	eObjectType_HeroBegin = c_un32ObjTypeSpace,
	eObjectType_NPCBegin = c_un32ObjTypeSpace * 2,
	eObjectType_GoodsBegin = c_un32ObjTypeSpace * 3, 
	eObjectType_AiRobotBegin = c_un32ObjTypeSpace * 4,
};

enum EAttackTar
{
	eAttackTar_None = 0,
	eAttackTar_ToSky = 1,
	eAttackTar_ToWaterSurface = 2,
	eAttackTar_ToUnderWater = 4,
};

enum EEquipTarget
{
	eEquipTarget_Building = 1,
	eEquipTarget_Ship,
	eEquipTarget_Both,
};

enum	EDiamondChangeReason
{
	eDiamondChangeReason_None = 0,
	eDiamondChangeReason_SaleObject,
	eDiamondChangeReason_GMInstruction,
	eDiamondChangeReason_LoginReward = 4,
};

enum	EGoldChangeReason{
	eGoldChangeReason_None = 0,
};

enum	EUserDBDataVer
{
	eUserDBDataVer_Begin = 0,
	eUserDBDataVer_20140224,
	eUserDBDataVer_End,
};

enum	ECityDBDataVer
{
	eCityDBDataVer_Begin = 0,
	eCityDBDataVer_End,
};

enum	EBuildingDBDataVer
{
	eBuildingDBDataVer_Begin = 0,
	eBuildingDBDataVer_End,
};

enum ESex
{
	eSex_Invalid,
	eSex_Male,
	eSex_Female
};
enum	EShipDBDataVer
{
	eShipDBDataVer_Begin = 0,
	eShipDBDataVer_End,
};

enum	EPlaneDBDataVer
{
	ePlaneDBDataVer_Begin = 0,
	ePlaneDBDataVer_End,
};

enum EMissionType
{
	eMissionType_Attack = 0,

	eMissionType_End,
};


enum	EPlatformQueryID{
	ePlatformQueryID_None = 0,
	ePlatformQueryID_ValidateUser,
};

enum	ESkillUseWay{
	eSUW_None = 0,
	eSUW_Active,
	eSUW_Passive,
	eSUW_TriggerWhileAttack,
	eSUW_TriggerWhileBeAttack,
	eSUW_TriggerWhileBeHurt,
	eSUW_TriggerWhileDie,
	eSUW_TriggerWhileUse,
	eSUW_TriggerWhileImpact,
};

enum ESkillTargetCate{
	eSTC_None = 0,
	eSTC_Self,//�Լ�
	eSTC_TeamMember,//��Ա�����Լ�
	eSTC_TeamMember_Without_Self,//��Ա�������Լ�
	eSTC_Enemy,//����
	eSTC_AllObject,//���е�λ
	eSTC_AllFriendUnit,//�����ѷ���λ
};

enum ESkillModelTargetCate{
	eSMTC_None = 0,
	eSMTC_Self,//�Լ�
	eSMTC_Enemy,//����
	eSMTC_AllObject,//���е�λ
};

enum ESkillRange{
	eSkilLRange_None = 0,
	eSkilLRange_Single,
	eSkilLRange_Circle,
	eSkilLRange_Rectangle,
};

//��·�޸ļ���ϵͳԤ��ɾ��
/*
enum ESkillType{
		eSkillType_None = 0,
		eSkillType_ShortDistance,
		eSkillType_LongDistance,
		eSkillType_MonomerNotForceFly,
		eSkillType_PierceNotForceFly,
		eSkillType_CommonRange,
		eSkillType_FollowRange,
		eSkillType_ReBounce,
		eSkillType_NoneBounce,
		eSkillType_FlyRange,
		eSkillType_ExchangPosition,
		eSkillType_CreateFixedNPC,
		eSkillType_CreateFollowNPC,
		eSkillType_FixRange,
};
*/

enum ESkillAOECate{
	eSAOECate_None,
	eSAOECate_SelfCenter,
	eSAOECate_TargetCenter,
	eSAOECate_FixDist_Ex,//�Թ̶�����Ϊ�����
};

enum EEffectCate{
	eEffectCate_None = 0,
	eEffectCate_PhyHurt,//�����˺�
	eEffectCate_MagicHurt,//ħ���˺�
	eEffectCate_CurHP,//��ǰHP
	eEffectCate_CurMP,//��ǰMP
	eEffectCate_PhyAttack,//�﹥
	eEffectCate_MagicAttack,//ħ��
	eEffectCate_PhyDefense,//�￹
	eEffectCate_MagicDefense,//ħ��
	eEffectCate_MoveSpeed,//�ƶ��ٶ�
	eEffectCate_AttackSpeed,//����
	eEffectCate_MaxHP,//���MP
	eEffectCate_MaxMP,//���HP
	eEffectCate_HPRecoverRate,//HP�ظ�
	eEffectCate_MPRecoverRate,//MP�ظ�
	eEffectCate_ReliveTime,//����ʱ��	
	eEffectCate_Dizziness,//����
	eEffectCate_Silence,//��Ĭ
	eEffectCate_PosMove,//δʹ��
	eEffectCate_Rebound,//δʹ��
	eEffectCate_PhySuckBlood,//������Ѫ
	eEffectCate_Disarm,//��е
	eEffectCate_Restrain,//����
	eEffectCate_CriPersent,//��������
	eEffectCate_CriHarm,//�����˺��ӳ�
	eEffectCate_CPRecover,//��Ǯ�ظ�
	eEffectCAte_PassitiveSkill,//����
	eEffectCate_Invisible,//����
	eEffectCAte_AttackDist,//���
	eEffectCate_TrueHurt,//��ʵ�˺�
	eEffectCate_PhyPassNum,//����͸��ֵ
	eEffectCate_PhyPassPercent,//����͸����
	eEffectCate_MagicPassNum,//ħ����͸��ֵ
	eEffectCate_MagicPassPercent,//ħ����͸����
	eEffectCate_CooldownReduce,//��ȴ����
	eEffectCate_PhyDmgReduce,//�������ǧ�ֱ�
	eEffectCate_MagicDmgReduce,//ħ������ǧ�ֱ�
	eEffectCate_TrueDmgReduce,//��ʵ����ǧ�ֱ�
	eEffectCate_PhyDmgReduceNum,//���������ֵ
	eEffectCate_MagicDmgReduceNum,//ħ��������ֵ
	eEffectCate_TrueDmgReduceNum,//��ʵ������ֵ
	eEffectCate_MagicSuckBlood,//������Ѫ
	eEffectCate_End,//�����ָ���
};

enum EAbsorbDataState{
	eEAbsorbDataState_Invalid = 0,
	eEAbsorbDataState_Paparing ,
	eEAbsorbDataState_Prepared,
};

enum EEffectTar{
	eSET_SkillTar = 0,
	eSET_Releaser,
	eSET_Friends,
	eSET_Enemy,
};

enum ESkillBuffTarCate{
	eSBTC_None = 0,
	eSBTC_Releaser,
	eSBTC_SkillTar,
};

enum ESkillState{
	eSkillState_Free,
	eSkillState_Preparing,
	eSkillState_Releasing,
	eSkillState_Using,
	eSkillState_Lasting,
	eSkillState_End,
};

enum ESkillEffectState{
	eSkillModelState_Free,
	eSkillModelState_Preparing,
	eSkillModelState_Releasing,
	eSkillModelState_End,
};

enum ENPCCateChild{
	eNPCChild_None = 0,
	eNPCChild_NPC_Per_AtkBuilding,
	eNPCChild_NPC_Per_Bomb,
	eNPCChild_NPC_Per_Small,
	eNPCChild_NPC_Per_Big,

	eNPCChild_BUILD_Altar = 10, 
	eNPCChild_BUILD_Base,

	eNPCChild_Summon = 20, //�ٻ��� 
	eNPCChild_Summon_End = 30,//�ٻ������

	eNPCCateChild_Ohter,
};

enum ENPCSolderChild{
	eNPCSChild_None = 0,
	eNPCSChild_AltarSolder,
	eNPCSChild_BuldSolder,
	eNPCSChild_BombSolder,
};

enum ENPCCate{
	eNPCCate_WideAnimal = 1,//Ұ��
	eNPCCate_Solider,//ʿ��
	eNPCCate_Building,//������
	//eNPCCate_Altar,
};


enum	EDBType
{
	eDBType_None = 0,
	eDB_GameDb, 
	eDB_CdkeyDb, 
	eDB_LogDb,
	eDB_MailDb,
};

/*
enum EHPChangeReason{
	eHPCR_NormalHurt,
	eHPCR_BlastHurt,
	eHPCR_BuffEffect,
	eHPCR_Recover,
	eHPCR_SkillConsume,
	eHPCR_SkillHurt,
	
	eHPCR_SkillAbsorbHurt,
	eHPCR_SysteHurt,
};


enum EMPChangeReason{
	eMPCR_SkillConsume,
	eMPCR_BuffEffect,
	eMPCR_Recover,
};
*/

enum ESkillCountdownCate{
	eSCC_Immediately = 1,
	eSCC_Delay,
	eSCC_Script,
};

enum EHateLevel{
	eHateLevel_First,
	eHateLevel_Second,
	eHateLevel_Third,
	eHateLevel_Fourth,
	eHateLevel_Fifth,
	eHateLevel_Sixth,
	eHateLevel_Seventh,
	eHateLevel_Eighth,
	eHateLevel_End,
};

enum EExpChangeReason{
	eECR_KillEnemy,
	eECR_HelpKillEnemy,
	eECR_SystemAward,
};

enum EWMLevel{
	eEWM_None = 0,
	eEWM_low,
	eEWM_Middle,
	eEWM_High,
};

enum EWMGroup{
	eEWMGroup_none = 0,
	eEWMGroup_1,
	eEWMGroup_2,
	eEWMGroup_3,
	eEWMGroup_4,

	eEWMGroup_other,
};


enum ELoginRewardItemType
{
	eLoginRewadItem_None = 0,//δ��
	eLoginRewadItem_Gold = 1,//���
	eLoginRewadItem_Diamond = 2,//��ʯ
	eLoginRewadItem_GoodsIDBegin = 3,//��Ʒ
};

 enum ERewardType
 {
	 eRewardType_None = 0,		//δ��
	 eRewardType_Nomal = 1,		//��ͨ
	 eRewardType_Extend = 2,	//����
 };

enum ESkillSlotIdx{	
	eSkillSlotIdx_NotNormalSkill1 = -1,
	eSkillSlotIdx_NormalSkill1,
	eSkillSlotIdx_NormalSkill2,
	eSkillSlotIdx_GasSkill1,
	eSkillSlotIdx_GasSkill2,
	eSkillSlotIdx_NormalAttack,
	eSkillSlotIdx_SuiteSkill1,
	eSkillSlotIdx_SuiteSkill2,
};

enum	EIntDir{
	eIntDir_Invalid = -1,
	eIntDir_Up = 0,
	eIntDir_UpLeft,
	eIntDir_Left,
	eIntDir_BelowLeft,
	eIntDir_Below,
	eIntDir_BelowRight,
	eIntDir_Right,
	eIntDir_UpRight,
	eIntDir_End,
};


enum ELuaParamType
{
	eELua_Param_Number = 0,
	eELua_Param_String,
	eELua_Param_Struct
};

//set wild monster be atk type
enum EVMBeAtkType
{
	eEVMBeAtk_Hp_Hurt = 0,
	eEVMBeAtk_Lost_Enemy,
	eEVMBeAtk_Get_State,
};

//set the hero atk list
enum EHeroBeAtkType
{
	eEHeroBeAtk_Add =0,
	eEHeroBeAtk_Del,
	eEHeroBeAtk_IfBeAtk,
	eEHeroBeAtk_GetGuid,
};

//�ѵ�����
enum EReplaceType
{
	EReplaceType_None = 0,
	EReplaceType_Forbit= 1,//������ѵ�
	EReplaceType_Reset,// �ѵ�����ˢ�³�����ʱ��
	EReplaceType_SingleCaculate,   //�ѵ������Լ������ʱ��
};

//��״
enum ESkillShapeType
{
	eSkillShapeType_None = 0,
	eSkillShapeType_Cicle,
	eSkillShapeType_Rectangle, //����
	eSkillShapeType_Sector,//����
};

//�ٻ�����
enum ESummonType
{
	eSkillSummonType_None = 0,
	eSkillSummonType_Building,
	eSkillSummonType_Retinue,//���
	eSkillSummonType_Monster,//Ұ��
};
//�ٻ���ʽ
enum ESummonWayType
{
	eSummonType_None = 0,
	eSummonType_DistDir,//ʩ������ ����
	eSummonType_Tarpos, //Ŀ����ٻ� 
	 
};

enum EHeroCPAward
{
	eHeroCPAward_None = 0,
	eHeroCPAward_Self,
	eHeroCPAward_Other,
};

enum EHeroLoginState
{
	eHero_None = 0,
	eHero_New,
	eHero_Old,

	eHero_Own,
	 
};

enum EObjInfoType
{
	eObjType_None = 0,

	eObjType_HeroInfo,
	eObjType_HeroLv,  
};

enum ESystemFunc
{
	eSysFunc_None = 0,
	eSysFunc_Normal,
	eSysFunc_OB,
	eSysFunc_Guide,
};
//OB
enum EOBSystemFunc
{
	eOB_None = 0, 
	eOB_InitUserSeat,
	eOB_AddUser,
	eOB_OBBattleHeroInfo, 
	eOB_ObjBaseInfo, 
	eOB_BattleInfo,
	eOB_HerosCount, //����ͳ����Ϣ
	eOB_Post,
};


//��������
enum EKillReason
{
	eKillReason_NormalAtk = 0,
	eKillReason_SkillAtk,
	eKillReason_SummonSkillAtk,//�ٻ�
	eKillReason_Building,
};
enum EDeadType
{
	eType_User = 0,
	eType_NPC,
	eType_AltarNPC,
	eType_WildNPC,
	eType_Tower,
	eType_AltarTower,
	eType_BaseBuild,
};
struct  GuideCaseDeadInfo
{
	INT32						n32NPCId;
	EDeadType					eNPCType; 
	EKillReason					eCaseDeadReson;

	GuideCaseDeadInfo(){ Release(); }

	void Release()
	{
		n32NPCId = 0;
		eNPCType = eType_User;
		eCaseDeadReson = eKillReason_NormalAtk;
	}
} ; 

enum EGuideType
{
	eGuideType_None = 0,
	eGuideType_GetHeroId,
	eGuideType_Comp,
	eGuideType_BronNPC,
	 eGuideType_ReBronNPCHero,
};

enum EGuideState
{
	eGuideState_Init = 0,
	eGuideState_Comp,
	eGuideState_LastEndStep,
	eGuideState_Finish,
	eGuideState_FinishState,
};

enum EAltarBornNpcType
{
	//eAltarBornNPCType_Close = 0,
	eAltarBornNPCType_Add = 0 ,
	//eAltarBornNPCType_Born,
	eAltarBornNPCType_Del = 1,
};

enum EBattleEndType
{
	eBattleEnd_Normal = 0,
	eBattleEnd_Guide = 1,
	eBattleEnd_UserAllOffline = 2,
	eBattleEnd_Guide_AskGoHall = 3,
};

enum ESummonFunc
{
	eSummonFunc_None = 0,
	eSummonFunc_All,
	eSummonFunc_One,
	eSummonFunc_Update,
	eSummonFunc_Call,
};

enum ESysSightType
{
	eSightType_SelfAndOB = 0,
	eSightType_All, 
	eSightType_OB,
	eSightType_State,

	eSightType_End,
};

enum ERelationShip{
	eRSType_None = 0,
	eRSType_Friends,
	eRSType_Detestation,
};

enum EDBOperation{
	eOperationType_None = 0,
	eOperationType_Add = 1,
	eOperationType_Del = 2,
	eOperationType_Upd = 3,
};
 

//cs ������������
enum ECSGuideType
{
	eCSGuideType_None = 0,
	eCSGuideType_1,//����
	eCSGuideType_2,//����
	eCSGuideType_3, //������������
};

struct NPCHeroCfg
{
	INT32  nStepId;
	INT32  nNPCId;
	INT32  nDelayTimeCfg;
	INT64  bornTime;

	NPCHeroCfg():nStepId(0),nDelayTimeCfg(0),bornTime(0){}

	NPCHeroCfg(INT32 ns,INT32 npcId, INT32 nd)
	{
		nStepId = ns;
		nNPCId = npcId;
		nDelayTimeCfg = nd;
		bornTime = 0;
	}
};


struct tagBornSolderCfg 
{
	INT32 n32BSpaceTimeCfg;
	INT32 n32MaxExistNumCfg;  
	INT32 n32CurtExistNum;
	INT32 n32CurtDeadNum; 

	tagBornSolderCfg():n32BSpaceTimeCfg(0)
		, n32MaxExistNumCfg(0)
		, n32CurtExistNum(0)
		, n32CurtDeadNum(0){}

	bool operator <(const tagBornSolderCfg& p){
		return n32BSpaceTimeCfg < p.n32BSpaceTimeCfg;
	}
	tagBornSolderCfg(INT32 st,  INT32 mb):n32BSpaceTimeCfg(st)
		, n32MaxExistNumCfg(mb)
		, n32CurtExistNum(0)
		, n32CurtDeadNum(0){
	}  
	void ChangeParam(bool b)
	{  
		b ? ++n32CurtExistNum : ++n32CurtDeadNum;  
	}
	void Release()
	{
		n32BSpaceTimeCfg = 0;
		n32MaxExistNumCfg = 0;
		n32CurtExistNum = 0;
		n32CurtDeadNum = 0;
	}
};

struct SWMRefrshCfg
{
	EWMLevel eWmLv;
	UINT32 un32BufId;
	UINT64 un32Cfg; 
	UINT64 un64LastMilsec;	 
	bool operator <(const SWMRefrshCfg& p){
		return eWmLv < p.eWmLv;
	}
	SWMRefrshCfg():eWmLv(eEWM_low)
		, un32BufId(0)
		, un32Cfg(0)
		, un64LastMilsec(0)
	{
	}
	void Release()
	{
		eWmLv = eEWM_low;
		un32BufId = 0;
		un32Cfg = 0;
		un64LastMilsec = 0;
	}
	SWMRefrshCfg(EWMLevel ev,UINT32 bufId, UINT32 cdcfg, UINT64 um)
		: eWmLv(ev)
		, un32BufId(bufId)
		, un32Cfg(cdcfg)
		, un64LastMilsec(um)
	{
	}
}; 

//��������δ��ɲ��裬����Ұ��
struct tagGuideVmBornCfg 
{
	INT32  stepId;
	INT32  cdTime;
	INT32  totalBornNum; 

	INT32  curtNum; 
	time_t		m_BornTime;  

	tagGuideVmBornCfg():stepId(0)
		, cdTime(0)
		, totalBornNum(0)
		, m_BornTime(0){}
};

//ս����������ɾ��
enum EBattleOPType
{
	eBattleOP_None = 0,
	eBattleOP_Create,
	eBattleOP_Finish,
};
 
//������ʾ����
enum ETipsType
{
	eTips_None = 0,
	eTips_ObjAppear,
	eTips_NPCBorn,
	eTips_SuperNPCBorn,
};
//��������
enum EGuideBattleType
{
	eGuideBattle_None = 0,
	eGuideBattle_Primary,
	eGuideBattle_Middle,
	eGuideBattle_Hight,
};


//�ʼ�
enum EMailType
{
	eMailType_None = 0,
	eMailType_1,
	eMailType_2,
	eMailType_3,
	eMailType_4,
};

//�����͵�ö��(����)
enum EMerchType
{
	eMerchType_None = 0,
	eMerchType_Gold,
	eMerchType_Diamond, 
	eMerchType_Goods,
	/*eMerchType_Runne,
	eMerchType_Hero,
	eMerchType_Skin,
	eMerchType_Goods,
	eMerchType_Exp, */
};

typedef UINT64 SGUID_KEY;

const float c_fPersentDevide = 1000.0f;

struct SFightProperty{
	INT32		n32PhyAttPower;
	INT32		n32MagicAttPower;
	INT32		n32PhyDefAbility;
	INT32		n32MagicDefAbility;
	INT32		n32MoveSpeed;
	INT32		n32AttackSpeed;
	INT32		n32AttackDist;
	INT32		n32MaxHP;
	INT32		n32MaxMP;
	INT32		n32HPRecover;
	INT32		n32MPRecover;
	INT32		n32ReliveSecond;
	INT32		n32CriPersent;
	INT32		n32CriHarm;
	INT32		n32CPRecover;
	INT32		n32DizzinessCounter;
	INT32		n32SilenceCounter;
	INT32		n32DisarmCounter;
	INT32		n32RestrainCounter;
	INT32		n32InvisibleCounter;

	SFightProperty():n32PhyAttPower(0)
		, n32MagicAttPower(0)
		, n32PhyDefAbility(0)
		, n32MagicDefAbility(0)
		, n32MoveSpeed(0)
		, n32AttackSpeed(0)
		, n32AttackDist(0)
		, n32MaxHP(0)
		, n32MaxMP(0)
		, n32HPRecover(0)
		, n32MPRecover(0)
		, n32ReliveSecond(0)
		, n32CriPersent(0)
		, n32CriHarm(0)
		, n32CPRecover(0)
		, n32DizzinessCounter(0)
		, n32SilenceCounter(0)
		, n32DisarmCounter(0)
		, n32RestrainCounter(0)
		, n32InvisibleCounter(0){}


	SFightProperty& operator += (SFightProperty& rsRight)
	{
		n32PhyAttPower		+= rsRight.n32PhyAttPower;
		n32MagicAttPower	+= rsRight.n32MagicAttPower;
		n32PhyDefAbility	+= rsRight.n32PhyDefAbility;
		n32MagicDefAbility	+= rsRight.n32MagicDefAbility;
		n32MoveSpeed		+= rsRight.n32MoveSpeed;
		n32AttackSpeed		+= rsRight.n32AttackSpeed;
		n32AttackDist		+= rsRight.n32AttackDist;
		n32MaxHP			+= rsRight.n32MaxHP;
		n32MaxMP			+= rsRight.n32MaxMP;
		n32HPRecover		+= rsRight.n32HPRecover;
		n32MPRecover		+= rsRight.n32MPRecover;
		n32ReliveSecond		+= rsRight.n32ReliveSecond;

		n32CriPersent		+= rsRight.n32CriPersent;
		n32CriHarm			+= rsRight.n32CriHarm;
		n32CPRecover		+= rsRight.n32CPRecover;

		n32DizzinessCounter += rsRight.n32DizzinessCounter;
		n32SilenceCounter	+= rsRight.n32SilenceCounter;
		n32DisarmCounter	+= rsRight.n32DisarmCounter;
		n32RestrainCounter	+= rsRight.n32RestrainCounter;
		n32InvisibleCounter	+= rsRight.n32InvisibleCounter;
		return *this;
	}

	SFightProperty& operator *= (INT32 i)
	{
		n32PhyAttPower		*= i;
		n32MagicAttPower	*= i;
		n32PhyDefAbility	*= i;
		n32MagicDefAbility	*= i;
		n32MoveSpeed		*= i;
		n32AttackSpeed		*= i;
		n32AttackDist		*= i;

		n32MaxHP			*= i;
		n32MaxMP			*= i;
		n32HPRecover		*= i;
		n32MPRecover		*= i;
		n32ReliveSecond		*= i;

		n32CriPersent		*= i;
		n32CriHarm			*= i;
		n32CPRecover		*= i;
		return *this;
	}

	SFightProperty operator *(INT32 i)
	{
		SFightProperty sNewFP;

		sNewFP.n32PhyAttPower		= n32PhyAttPower		* i;
		sNewFP.n32MagicAttPower		= n32MagicAttPower	* i;
		sNewFP.n32PhyDefAbility		= n32PhyDefAbility	* i;
		sNewFP.n32MagicDefAbility	= n32MagicDefAbility	* i;
		sNewFP.n32MoveSpeed			= n32MoveSpeed		* i;
		sNewFP.n32AttackSpeed		= n32AttackSpeed		* i;
		sNewFP.n32AttackDist		= n32AttackDist		* i;
		sNewFP.n32MaxHP				= n32MaxHP			* i;
		sNewFP.n32MaxMP				= n32MaxMP			* i;
		sNewFP.n32HPRecover			= n32HPRecover		* i;
		sNewFP.n32MPRecover			= n32MPRecover		* i;
		sNewFP.n32ReliveSecond		= n32ReliveSecond		* i;

		sNewFP.n32CriPersent		= n32CriPersent		* i;
		sNewFP.n32CriHarm			= n32CriHarm			* i;
		sNewFP.n32CPRecover			= n32CPRecover		* i;

		return sNewFP;
	}

	SFightProperty operator + (const SFightProperty& rsLeft){
		SFightProperty sNewFP;
		sNewFP.n32PhyAttPower		= n32PhyAttPower	+ rsLeft.n32PhyAttPower		;
		sNewFP.n32MagicAttPower		= n32MagicAttPower	+ rsLeft.n32MagicAttPower	;
		sNewFP.n32PhyDefAbility		= n32PhyDefAbility	+ rsLeft.n32PhyDefAbility	;
		sNewFP.n32MagicDefAbility	= n32MagicDefAbility+ rsLeft.n32MagicDefAbility	;
		sNewFP.n32MoveSpeed			= n32MoveSpeed		+ rsLeft.n32MoveSpeed		;
		sNewFP.n32AttackSpeed		= n32AttackSpeed	+ rsLeft.n32AttackSpeed		;
		sNewFP.n32AttackDist		= n32AttackDist		+ rsLeft.n32AttackDist		;
		sNewFP.n32MaxHP				= n32MaxHP			+ rsLeft.n32MaxHP			;
		sNewFP.n32MaxMP				= n32MaxMP			+ rsLeft.n32MaxMP			;
		sNewFP.n32HPRecover			= n32HPRecover		+ rsLeft.n32HPRecover		;
		sNewFP.n32MPRecover			= n32MPRecover		+ rsLeft.n32MPRecover		;
		sNewFP.n32ReliveSecond		= n32ReliveSecond	+ rsLeft.n32ReliveSecond	;

		sNewFP.n32CriPersent		= n32CriPersent		+ rsLeft.n32CriPersent		;
		sNewFP.n32CriHarm			= n32CriHarm		+ rsLeft.n32CriHarm			;
		sNewFP.n32CPRecover			= n32CPRecover		+ rsLeft.n32CPRecover		;

		sNewFP.n32DizzinessCounter	= n32DizzinessCounter	+ rsLeft.n32DizzinessCounter	;
		sNewFP.n32SilenceCounter	= n32SilenceCounter		+ rsLeft.n32SilenceCounter		;
		sNewFP.n32DisarmCounter		= n32DisarmCounter		+ rsLeft.n32DisarmCounter		;
		sNewFP.n32RestrainCounter	= n32RestrainCounter	+ rsLeft.n32RestrainCounter		;
		sNewFP.n32InvisibleCounter  = n32InvisibleCounter   + rsLeft.n32InvisibleCounter    ;

		return sNewFP;
	}

	void	Clear(){
		n32PhyAttPower		= 0;
		n32MagicAttPower	= 0;
		n32PhyDefAbility	= 0;
		n32MagicDefAbility	= 0;
		n32MoveSpeed		= 0;
		n32AttackSpeed		= 0;
		n32AttackDist		= 0;
		n32MaxHP			= 0;
		n32MaxMP			= 0;
		n32HPRecover		= 0;
		n32MPRecover		= 0;
		n32ReliveSecond		= 0;

		n32CriPersent		= 0;
		n32CriHarm			= 0;
		n32CPRecover		= 0;

		n32DizzinessCounter = 0;
		n32SilenceCounter	= 0;
		n32DisarmCounter	= 0;
		n32RestrainCounter	= 0;
		n32InvisibleCounter = 0;
	}						

	static SFightProperty getTotalFP(SFightProperty& sFPBase ,SFightProperty& sFPPercent){
		SFightProperty newFP;
		newFP.n32PhyAttPower		=	(INT32)(sFPBase.n32PhyAttPower * (1 + (float)sFPPercent.n32PhyAttPower / c_fPersentDevide));
		newFP.n32MagicAttPower		=	(INT32)(sFPBase.n32MagicAttPower * (1 + (float)sFPPercent.n32MagicAttPower / c_fPersentDevide));
		newFP.n32PhyDefAbility		=	(INT32)(sFPBase.n32PhyDefAbility * (1 + (float)sFPPercent.n32PhyDefAbility / c_fPersentDevide));
		newFP.n32MagicDefAbility	=	(INT32)(sFPBase.n32MagicDefAbility * (1 + (float)sFPPercent.n32MagicDefAbility / c_fPersentDevide));
		newFP.n32MoveSpeed			=	(INT32)(sFPBase.n32MoveSpeed * (1 + (float)sFPPercent.n32MoveSpeed / c_fPersentDevide));
		newFP.n32AttackSpeed		=	(INT32)(sFPBase.n32AttackSpeed / (1 +  (float)sFPPercent.n32AttackSpeed / c_fPersentDevide));
		newFP.n32AttackDist			=	(INT32)(sFPBase.n32AttackDist * (1 + (float)sFPPercent.n32AttackDist / c_fPersentDevide));
		newFP.n32MaxHP				=	(INT32)(sFPBase.n32MaxHP * (1 + (float)sFPPercent.n32MaxHP / c_fPersentDevide));
		newFP.n32MaxMP				=	(INT32)(sFPBase.n32MaxMP * (1 + (float)sFPPercent.n32MaxMP / c_fPersentDevide));
		newFP.n32HPRecover			=	(INT32)(sFPBase.n32HPRecover * (1 + (float)sFPPercent.n32HPRecover / c_fPersentDevide));
		newFP.n32MPRecover			=	(INT32)(sFPBase.n32MPRecover * (1 + (float)sFPPercent.n32MPRecover / c_fPersentDevide ));
		newFP.n32ReliveSecond		=	(INT32)(sFPBase.n32ReliveSecond* (1 + (float)sFPPercent.n32ReliveSecond / c_fPersentDevide));
		newFP.n32CriPersent			=	(INT32)(sFPPercent.n32CriPersent);
		newFP.n32CriHarm			=	(INT32)(sFPPercent.n32CriHarm);
		newFP.n32CPRecover			=	(INT32)(sFPBase.n32CPRecover * (1 + (float)sFPPercent.n32CPRecover / c_fPersentDevide));
		newFP.n32DizzinessCounter	=	(INT32)(sFPBase.n32DizzinessCounter);
		newFP.n32SilenceCounter		=	(INT32)(sFPBase.n32SilenceCounter);
		newFP.n32DisarmCounter		=	(INT32)(sFPBase.n32DisarmCounter);
		newFP.n32RestrainCounter	=	(INT32)(sFPBase.n32RestrainCounter);
		newFP.n32InvisibleCounter   =   (INT32)(sFPBase.n32InvisibleCounter);
		return newFP;
	}

	string GetFPString(){
		char sFpString[512];
		sprintf(sFpString, "n32PhyAttPower:%d, n32MagicAttPower:%d, n32PhyDefAbility:%d, n32MagicDefAbility:%d, n32MoveSpeed:%d n32AttackSpeed:%d,"
			"n32AttackDist:%d, n32MaxHP:%d, n32MaxMP:%d, n32HPRecover:%d, n32MPRecover:%d, n32ReliveSecond:%d.", n32PhyAttPower, n32MagicAttPower, n32PhyDefAbility
			, n32MagicDefAbility, n32MoveSpeed, n32AttackSpeed, n32AttackDist, n32MaxHP, n32MaxMP, n32HPRecover, n32MPRecover, n32ReliveSecond);

		return sFpString;
	}
};

enum EProperty{
	eProperty_None = 0,
	eProperty_PhyAttPower,
	eProperty_MagicAttPower,
	eProperty_PhyDefAbility,
	eProperty_MagicDefAbility,
	eProperty_MoveSpeed,
	eProperty_AttackSpeed,
	eProperty_MaxHP,
	eProperty_MaxMP,
	eProperty_HPRecover,
	eProperty_MPRecover,
	eProperty_ReliveSecond,
	eProperty_End,
};

struct SSSendRunesInfo{
	SSSendRunesInfo(){}
	SSSendRunesInfo(UINT32 eOT, INT16 Pos
		, INT16 RunesNum
		, INT8  RunesPosType) : eOT(eOT)
		, n16Pos(Pos)
		, n16RunesNum(RunesNum)
		, n8RunesPosType(RunesPosType){

	}
	UINT32 eOT;
	INT16 n16Pos;
	INT16 n16RunesNum;
	INT8  n8RunesPosType;
};

struct SSendData{
	UINT32	un32DestoryBuildings;
	UINT32	un32HeroKills;
	UINT32	un32DeadTimes;
	UINT32	un32Assist;
	UINT32	un32LastHit;

	//for log
	UINT32  un32RealSendHurt;	//��ʵ�˺��������
	UINT32  un32SkillPhySendHurt;	//������������˺�����
	UINT32  un32SkillMagicSendHurt;	//����ħ������˺����� 
	UINT32	un32SendHurt;	//����˺�ֵ����

	UINT32  un32RevRealHurt; //��ʵ�����˺�����
	UINT32  un32RevSkillPhyHurt;//���ܳ��������˺�����
	UINT32  un32RevSkillMagicHurt;//���ܳ���ħ���˺�����
	UINT32  un32RevHurt;	//�����˺�ֵ����

	UINT32  un32KillSolder;	//��ɱС����������
	UINT32  un32KillMonster; //��ɱҰ�ֻ���
	SSendData() : un32DestoryBuildings(0)
		, un32HeroKills(0)
		, un32DeadTimes(0)
		, un32Assist(0)
		, un32LastHit(0)
		,un32RealSendHurt(0)
		,un32SkillMagicSendHurt(0)
		,un32SkillPhySendHurt(0)
		,un32SendHurt(0)
		,un32RevRealHurt(0)
		,un32RevSkillPhyHurt(0)
		,un32RevSkillMagicHurt(0)
		,un32RevHurt(0)
		,un32KillSolder(0)
		,un32KillMonster(0)
	{

	}

	void Clear(){
		un32DestoryBuildings = 0;
		un32DeadTimes = 0;
		un32HeroKills = 0;
		un32Assist = 0;
		un32LastHit = 0;
		un32RealSendHurt=0;
		un32SkillMagicSendHurt=0;
		un32SkillPhySendHurt=0;
		un32SendHurt=0;
		un32RevRealHurt=0;
		un32RevSkillPhyHurt=0;
		un32RevSkillMagicHurt=0;
		un32RevHurt=0;
		un32KillSolder=0;
		un32KillMonster=0;
	}
};

struct SUserNetInfo
{
	INT32	n32GSID;
	INT32	n32GCNSID;

	SUserNetInfo()
		:n32GSID(0)
		, n32GCNSID(0)
	{
	}

	SUserNetInfo(INT32 n32GSID, INT32 n32GCNSID)
		: n32GSID(n32GSID)
		, n32GCNSID(n32GCNSID)
	{
	}

	void	operator	=	(const SUserNetInfo &crsRight)
	{
		n32GSID = crsRight.n32GSID;
		n32GCNSID = crsRight.n32GCNSID;
	}

	bool	operator == (const SUserNetInfo &crsRight)
	{
		if (n32GSID != crsRight.n32GSID || n32GCNSID != crsRight.n32GCNSID)
		{
			return false;
		}
		return true;
	}

	bool	operator != (const SUserNetInfo &crsRight)
	{
		if (n32GSID != crsRight.n32GSID || n32GCNSID != crsRight.n32GCNSID)
		{
			return true;
		}
		return false;
	}

	bool	operator<(const SUserNetInfo &crsRight)const
	{
		INT32 n32Cmp = memcmp(this, &crsRight, sizeof(SUserNetInfo));
		if (0 > n32Cmp)
		{
			return true;
		}
		return false;
	}

	void Clear()
	{
		n32GSID = 0;
		n32GCNSID = 0;
	}
	bool IsValid() const{
		return n32GCNSID > 0 && n32GSID > 0;
	}
};

struct SDownInfo{
	SDownInfo():un32Child1Type(0)
		, un32Child2Type(0){}
	SDownInfo(UINT32 child1, UINT32 child2):un32Child1Type(child1)
		, un32Child2Type(child2){}
	UINT32 un32Child1Type;
	UINT32 un32Child2Type;
};

struct SUpInfo{
	SUpInfo():un32ParentType(0)
		, un32BrotherType(0){}
	SUpInfo(UINT32 parent, UINT32 brother):un32ParentType(parent)
		, un32BrotherType(brother){}
	UINT32 un32ParentType;
	UINT32 un32BrotherType;
};
struct SGoodsCompose{
	SDownInfo sDownInfo;
	SUpInfo	sUpInfo[c_un32MaxGoodsDownInfoNum];
};
struct SGoodsEffect{
	SGoodsEffect():n32Atrr(0)
		, n32Val(0)
		, n32Percent(0){}
	INT32 n32Atrr;
	INT32 n32Val;
	INT32 n32Percent;
};

struct SGoodsCfg{
	UINT32				un32GoodsID;
	EObjectType			eOT;
	UINT8				un8TypeID;	
	SGoodsEffect		sGoodsEffect[c_un32MaxItemEffectNum];
	INT32				n32UseTimes;
	BOOLEAN				bUsedDestory;
	UINT32				un32SkillID;
	UINT32				lun32PassiveSkillID[c_n32MaxNextSkillEffectCfgNum];
	BOOLEAN				bUsedAfterBuyed;
	UINT32				un32CDTime;
	BOOLEAN				bUniqueID;
	INT32				n32OverlapTimes;
	INT32				n32CPCostType;
	INT32				n32CPCost;
	UINT8				un8FunctionType;
	UINT32				un32UniqueTypeID;
	INT32				n32CombineCPCost;
	SGoodsCompose		sGoodsCompose;
	bool				bIfCanBuyWhenDeath;
	SGoodsCfg(){
		memset(this,0,sizeof(*this));
	}
};

struct SHeroChooseCfg{
	UINT32 un32HeroID;
	INT32 n32IfGuide;
	char szName[32];
};

enum ERobotAIType{
	eRobotAIType_Guide,
	eRobotAIType_PvE,
	eRobotAIType_Match,
};

struct SRobotAICfg{
	ERobotAIType n32AiType;
	INT32 n32ID;
	INT32 n32ModelID;
	INT32 n32NodeType;
	INT32 n32ParentID;
	INT32 an32Parameters[16];
};

struct SRobotAIPathCfg{
	INT32 un32ID;
	INT32 n32MapID;
	INT32 n32CampID;
	INT32 n32PahtID;
	float fX;
	float fY;
	float fZ;
};

struct SUserMgrCfg 
{		
	UINT32	un32UserDBHostPort;
	CHAR	aszUserDBHostIP[c_n32DefaultNameLen];
	CHAR	aszUserDBUserName[c_n32DefaultNameLen * 2];
	CHAR	aszUserDBUserPwd[c_n32DefaultNameLen * 2];
	CHAR	aszUserDBName[c_n32DefaultNameLen * 2];
	CHAR	aszUserTableName[c_n32DefaultNameLen * 2];
};

enum EAttackWay{
	EAttackWay_Building = 0,
	EAttackWay_Near,
	EAttackWay_Range,
};

struct SNPCCfg{ 
	EObjectType	eOT;
	ERace	eRace;
	EAttendantCate	eAttendantCate;
	EMagicCate		eMagicCate;
	ENPCCate		eNPCCate;
	ENPCCateChild	eNPCCateChild;
	INT32			n32AttDist;
	EAICate			eAICate;
	UINT32			un32AITarID;
	INT32			n32PursueDist;
	INT32			n32GuardDist;
	EAttackMode		eAttMode;
	EAttackWay		eAttackWay;
	SFightProperty	sBaseFP;
	INT32			n32GotExp;
	INT32			n32KillGotCP;
	INT32			n32ConsumeCP;
	BOOLEAN			bIfCanControl;
	INT32			n32CollideRadius;
	UINT32			aun32SkillList[c_n32MaxNPCSkillNum];
	UINT32			lun32PassiveSkillID[c_n32MaxNextSkillEffectCfgNum];
	INT32			n32CampID;
	UINT32			un32ShopID;
	EWMGroup		eWMGroupCate;
	INT32			n32ConsumePer[eEffectCate_Restrain+1];
	INT32			n32AbsorbAttriChange[eEffectCate_Restrain+1];
	CVector3D		cEmitPos;
	CVector3D		cOnHitPos;
	BOOLEAN         bIsLocked;	//�Ƿ������
};

struct SHeroCfg{
	EObjectType	eOT;
	INT64		n64Cost;
	EMagicCate	eMagicCate;
	EAttackWay		eAttackWay;
	INT32		n32BaseExp;
	INT32		n32ExpGrowth;
	SFightProperty	sBaseFP;
	SFightProperty	sGrowthFP;
	INT32			n32CPRecover;
	INT32			n32CollideRadius;
	UINT32			aun32SkillList[c_n32MaxHeroSkillNum];
	UINT32			aun32PassitiveSkillList[c_n32MaxHeroPassitiveSkillNum];
	CVector3D		cEmitPos;
	CVector3D		cOnHitPos;
	UINT32			aun32BuyItemList[32];

	SHeroCfg()
	{
		memset(this, 0, sizeof(*this));
	}
};

struct SGoodCPInfo{
	UINT32		un32GoodsID;
	UINT8		un8CPType;
	INT32		n32CPCost;
};
struct SShopCfg{
	EObjectType	eOT;
	SGoodCPInfo		sGoodCPInfo[c_un32MaxGoodsChildNum];
};

struct SMapDataHeader{
	UINT32			un32MapID;
	INT32			n32XCellNum;
	INT32			n32ZCellNum;
};

struct SMapObjCfg{
	UINT32	un32ID;
	UINT32	un32MapID;
	EObjectType	eObjTypeID;
	UINT32	un32ObjIdx;
	INT32	n32CampID;
	CVector3D	cBornPos;
	CVector3D	cBorDir;
	INT32		n32Visibility;
	EAttackMode	eAttackMode;
};

struct SMapCfg{
	UINT32	un32MapID;
	UINT32	un32MapCfgSize;
	UINT32	un32MapObjNum;
	UINT32	un32HeaderDataOffset;
	UINT32	un32MapObjOffset;
	SMapDataHeader*	psMapHeader;
	SMapObjCfg	*psMapObjCfg;
	//string luaFileStr;
};

struct SMapLogicCfg{
	UINT32 MapId;
	string MapName;
	UINT32 MapPic;
	UINT32 SeatCount;//��������//
	vector<UINT32> PlayerModel;//���ģʽ//3v3 2v4 1v5 5v5//
};

///

#define MAX_TASK_PARAM 10
#define MAX_TASK_REWARD 5

enum TASK_TIME_TYPE
{
	TTT_Infinite,
	TTT_Daily,
};

enum TASK_TYPE
{
	TT_None,
	TT_KillPlayer,//��ɱ���
	TT_KillXiaobin,//��ɱС��
	TT_KillMonster,//��ɱҰ��
	TT_KillBuild,//��ɱ����
	TT_GamePlay,//����һ����Ϸ
	TT_GameWin,//ʤ��һ����Ϸ
	TT_GameGetCP,//��Ϸ���CP
	TT_GameUseCP,//��Ϸʹ��CP
};

struct STaskConfig
{
	UINT32 taskID;
	UINT32 nextTaskID;
	TASK_TIME_TYPE taskTimeType;
	TASK_TYPE taskType;
	UINT32 taskMaxCount;
	UINT32 taskParams[MAX_TASK_PARAM];
	ELoginRewardItemType eItemType[MAX_TASK_REWARD];
	UINT32 un32num[MAX_TASK_REWARD];
	STaskConfig() { memset(this,0,sizeof(STaskConfig)); }
};

///

enum EEffectCaculateCate{
	EEffectCaculateCate_None = 0,
	EEffectCaculateCate_SelfPhyAttack,//1.�Լ��﹥�ӳ�
	EEffectCaculateCate_SelfMagicAttack,//2.�Լ�ħ���ӳ�
	EEffectCaculateCate_SelfPhyDefence,//3.�Լ�����ӳ�
	EEffectCaculateCate_SelfMagicDefence,//4.�Լ�ħ���ӳ�
	EEffectCaculateCate_SelfNowHP,//5.�Լ���ǰ����ֵ�ӳ�
	EEffectCaculateCate_SelfMaxHP,//6.�Լ��������ֵ�ӳ�
	EEffectCaculateCate_SelfLostHpPercent,//7.�Լ���ʧ�����ȼӳ�(ÿ1%�ӳ�)
	EEffectCaculateCate_SelfNowMP,//8.�Լ���ǰħ��ֵ�ӳ�
	EEffectCaculateCate_SelfMaxMP,//9.�Լ����ħ��ֵ�ӳ�
	EEffectCaculateCate_SelfLostMpPercent,//10.�Լ���ʧħ���ȼӳ�(ÿ1%�ӳ�)
	EEffectCaculateCate_SelfLevel,//11.�Լ��ȼ��ӳ�
	EEffectCaculateCate_SelfMoveSpeed,//12.�Լ��ƶ��ٶȼӳ�(ÿ1���׼ӳ�)

	EEffectCaculateCate_TarPhyAttack = 21,//21.Ŀ���﹥�ӳ�
	EEffectCaculateCate_TarMagicAttack,//22.Ŀ��ħ���ӳ�
	EEffectCaculateCate_TarPhyDefence,//23.Ŀ������ӳ�
	EEffectCaculateCate_TarMagicDefence,//24.Ŀ��ħ���ӳ�
	EEffectCaculateCate_TarNowHP,//25.Ŀ�굱ǰ����ֵ�ӳ�
	EEffectCaculateCate_TarMaxHP,//26.Ŀ���������ֵ�ӳ�
	EEffectCaculateCate_TarLostHpPercent,//27.Ŀ����ʧ�����ȼӳ�(ÿ1%�ӳ�)
	EEffectCaculateCate_TarNowMP,//28.Ŀ�굱ǰħ��ֵ�ӳ�
	EEffectCaculateCate_TarMaxMP,//29.Ŀ�����ħ��ֵ�ӳ�
	EEffectCaculateCate_TarLostMpPercent,//30.Ŀ����ʧħ���ȼӳ�(ÿ1%�ӳ�)
	EEffectCaculateCate_TarLevel,//31.Ŀ��ȼ��ӳ�
	EEffectCaculateCate_TarMoveSpeed,//32.Ŀ���ƶ��ٶȼӳ�(ÿ1���׼ӳ�)

};

struct SEffectInfo{
	EEffectCate			eEffectCate;
	INT32				n32EffectBaseValue;//����ֵ�������˺������Ըı�
	INT32				n32EffectRate;//ǧ�ֱȸñ�����ֻ�������Ըı�
	EEffectCaculateCate eEffectAddCacuCate[c_n32MaxEffectCaculateCateNum];//�˺��Ļ���ֵ�ı�����
	INT32				eEffectAddCacuValue[c_n32MaxEffectCaculateCateNum];//�˺��Ļ���ֵ�ı�ֵ
	EEffectCaculateCate eEffectMultCacuCate[c_n32MaxEffectCaculateCateNum];//�˺��ı����ı�����
	INT32				eEffectMultCacuValue[c_n32MaxEffectCaculateCateNum];//�˺��ı����ı�ֵ
	BOOLEAN				bIfBlastAttack;
	INT32				n32BlastAttPercent;
	INT32				n32BlastAttRate;
	

	SEffectInfo(): eEffectCate(eEffectCate_None)
		, n32EffectBaseValue(0)
		, n32EffectRate(0)
		, bIfBlastAttack(0)
		, n32BlastAttPercent(0)
		, n32BlastAttRate(0)
		{
			for(int i=0;i<c_n32MaxEffectCaculateCateNum;i++){
				eEffectAddCacuCate[i] = EEffectCaculateCate_None;
				eEffectAddCacuValue[i] = 0;
				eEffectMultCacuCate[i] = EEffectCaculateCate_None;
				eEffectMultCacuValue[i] = 0;
			}
		}
};

//��һ����������
struct SSNextSkillEffectCfg{
	UINT32  un32SkillEffectID;//����ģ��id
	INT32   n32Delay;//���õȴ�ʱ��
	INT32	n32DependedArr[c_n32MaxDependSkillEffectCfgNum];
	SSNextSkillEffectCfg(): un32SkillEffectID(0)
		, n32Delay(0){
	}
};

//����ģ������
enum ESkillEffectType{
	eSkillEffectType_None = 0,
	eSkillEffectType_Caculate,
	eSkillEffectType_Emit,
	eSkillEffectType_Range,
	eSkillEffectType_Leading,
	eSkillEffectType_Summon,
	eSkillEffectType_Move,
	eSkillEffectType_Switch,
	eSkillEffectType_Purification,
	eSkillEffectType_Link,
	eSkillEffectType_Buf = 10,
};

//�����ļ���ģ������
struct SSkillEffectlBaseCfg{
	UINT32  un32SkillModelID;//����ģ��id
	ESkillEffectType eSkillModelType;//��������
	BOOLEAN	bIsCoolDown;//�Ƿ�ʼ����CD
	INT32	n32TriggerRate;//��������
	BOOLEAN	bIfAffectBuilding;//�Խ�����Ч
	BOOLEAN	bIfAffectHero;//��Ӣ����Ч
	BOOLEAN	bIfAffectMonster;//��NPC��Ч
	BOOLEAN	bIsCanMove;//�Ƿ������Ч��ά�ֽ׶��ƶ�
	BOOLEAN	bIsCanBreak;//�Ƿ���Ա������Ķ������
	ESkillModelTargetCate eTargetType;//buffֻ�ܶ�����Ŀ����Ч���ѷ��з���������
	ESkillBuffTarCate eBuffTarget;//buff����Ӷ����Լ�����Ŀ�� 
	INT32  n32ReleaseTimeDelay;		
	SSNextSkillEffectCfg	asSkillModelList[c_n32MaxNextSkillEffectCfgNum];

	SSkillEffectlBaseCfg():un32SkillModelID(0)
		, eSkillModelType(eSkillEffectType_None)
		, bIsCoolDown(FALSE)
		, n32TriggerRate(0)
		, bIfAffectBuilding(FALSE)
		, bIfAffectHero(FALSE)
		, bIfAffectMonster(FALSE)
		, bIsCanMove(TRUE)
		, bIsCanBreak(TRUE)
		, eTargetType(eSMTC_None){
	}
};

//�����༼��ģ�鼼������
enum ESkillModelEmitType{
	eSkillModelEmitType_Follow = 1,
	eSkillModelEmitType_Direct,
	eSkillModelEmitType_Boomerang,
	eSkillModelEmitType_Bounce,
	eSkillModelEmitType_Bounce_NoRepeat,
	eSkillModelEmitType_Area,
	eSkillModelEmitType_AutoFind,
};

//�����༼��ģ������
struct SSkillModelEmitCfg : public SSkillEffectlBaseCfg{
	INT32	n32UseMP;//����MP
	INT32	n32UseHP;//����HP
	INT32	n32UseCP;//����CP
	ESkillModelEmitType eEmitType;
	INT32		n32ProjFlySpeed;
	INT32		n32FlyPar1;
	INT32		n32FlyPar2;
	INT32		n32FlyPar3;
	BOOLEAN		bIsPenetrate;
	INT32		n32ProjectileLifeTime;
	INT32		n32ProjectileCollideRadius;
	INT32		n32ProjectileNum;
	INT32		n32ProjectileAngle;
};

//�����༼��ģ�鼼������
enum ESkillModelAccountType{
	eSkillModelAccountType_None = 0,
	eSkillModelAccountType_PhyDmg,
	eSkillModelAccountType_MagicDmg,
	eSkillModelAccountType_ChangeHp,
	eSkillModelAccountType_ChangeMp,
	eSkillModelAccountType_SuckBlood,
};

//�����༼��ģ������
struct SSkillModelAccountCfg : public SSkillEffectlBaseCfg{
	SEffectInfo sEffectInfo;
};

//�����༼��ģ������
struct SSkillModelLeadingCfg : public SSkillEffectlBaseCfg{
	INT32 eLeadingTime;
	BOOLEAN bIsCheckTargetSta;
};

//ʩ�ų���
enum ESkillReleaseWay{
	ESReleaseWay_NO_TARGET = 0,
	ESReleaseWay_NEED_TARGET_NO_TURN,
	ESReleaseWay_NEED_TARGET,
	ESReleaseWay_AUTO,
};

enum ESkillType{
	ESkillType_Plus = 1,
	ESkillType_Hurt,
	ESkillType_Control,
	ESkillType_Move,
	ESkillType_TransHome,
};

//�µļ�������
struct SSNewSkillCfg{
	UINT32	un32SkillID;//����id
	ESkillType eSkillType;//��������
	BOOLEAN bIfNomalAttack;//�Ƿ���ͨ����
	BOOLEAN bIsConsumeSkill;//�Ƿ���������
	ESkillReleaseWay eReleaseWay;//ʩ�ų���
	INT32	n32UpgradeLevel;//��Ӧ�ȼ�
	INT32	n32UseMP;//����MP
	INT32	n32UseHP;//����HP
	INT32	n32UseCP;//����CP
	INT32	n32PrepareMilsec;
	INT32   n32CoolDown;//��ȴʱ��
	INT32	n32ReleaseMilsec;//׼������ʱ��
	INT32	n32SkillLastTime;//���ܺ�ҡʱ��
	FLOAT	fReleaseDist;//�ͷž���
	ESkillUseWay	eUseWay;//���ܴ�����ʽ
	INT32	n32TriggerRate;//��������
	BOOLEAN	bIfAffectBuilding;//�Խ�����Ч
	BOOLEAN	bIfAffectHero;//��Ӣ����Ч
	BOOLEAN	bIfAffectMonster;//��NPC��Ч
	BOOLEAN	bIfCheckTarState;
	BOOLEAN	bIfImpact;//�Ƿ���˲������
	ESkillTargetCate	eSkillTargetCate;//����ʩ��ʱ��ѡ���Ŀ������
	SSNextSkillEffectCfg     asSkillModelList[c_n32MaxNextSkillEffectCfgNum];
};

enum EBuffType{
	eBuffType_Ohter = 0,//��������
	eBuffType_Positive,//����
	eBuffType_Negative,//����
};

//buf
struct SSkillModelBufCfg : public SSkillEffectlBaseCfg
{ 
	INT32   n32UseMp;
	INT32   n32UseHp;
	INT32   n32UseCP;  

	EBuffType	eBuffType;//����
	INT32   n32EffectLastTick;//����ʱ��
	INT32   n32EffectInterval;//���ʱ��
	EReplaceType    eReplaceType; //�ѵ�����
	INT32   n32ReplaceTimes; //�ѵ�����
	INT32   n32RejectId;	//����id
	INT32   n32ReplaceId;  //�滻id
	BOOLEAN bIfClearAtDie; //�����Ƿ�����
	BOOLEAN n32FlyEffectID;//����ID
	SSNextSkillEffectCfg	asSkillStartModelList[c_n32MaxNextSkillEffectCfgNum];	//��ʼ����ģ��
	SSNextSkillEffectCfg	asSkillIntervalModelList[c_n32MaxNextSkillEffectCfgNum]; //���ģ��id
	SSNextSkillEffectCfg	asSkillEndModelList[c_n32MaxNextSkillEffectCfgNum]; //����ģ��id  
	SEffectInfo sEffectInfo;

	SSkillModelBufCfg()
		: n32UseMp(0)
		, n32UseHp(0)
		, n32UseCP(0)
		, n32EffectLastTick(0)
		, n32EffectInterval(0)
		, eReplaceType(EReplaceType_None)
		, n32ReplaceTimes(0)
		, n32RejectId(0)
		, n32ReplaceId(0)
		, bIfClearAtDie(TRUE){
	}
};
//��Χ
struct SSkillModelRangeCfg : public SSkillEffectlBaseCfg
{ 
	INT32   n32UseMp;
	INT32   n32UseHp;
	INT32   n32UseCP; 

	ESkillAOECate    eSkillAOECate;
	INT32   n32RangeInterval;
	INT32   n32RangeTimes;
	ESkillShapeType  eSkillShapeType;
	INT32   n32RangePar1;
	INT32   n32RangePar2;
	INT32   n32MaxEffectObj;
	INT32   n32LifeTime; 
	char    szattackEffect[n_c32SkkEffectNum];

	INT32	n32ReleaseDist;

	BOOLEAN bIfHasEffect;

	SSkillModelRangeCfg()
	{
		memset(this, 0, sizeof(*this));
	}
};

//�ٻ��� 
struct SSkillModuleSummonCfg: public SSkillEffectlBaseCfg
{
	INT32   n32UseMp;
	INT32   n32UseHp;
	INT32   n32UseCP;  
	ESummonType			eSummonType;
	ESummonWayType		eSummonWayType;

	INT32  nNPCId[n_c32NPCNum]; //�ٻ���id
	INT32  n32SummonNum[n_c32NPCNum];//�ٻ�������
	INT32  n32Distance;				
	INT32  n32LifeTime; 

	SSkillModuleSummonCfg()
	{
		memset(this,0,sizeof(*this));
	}
};


//��������ϵͳ��ʼ

//�������ܴ�������
enum EPassiveSkillTriggerType
{
	EPassiveSkillTriggerType_None = 0,
	EPassiveSkillTriggerType_HeartBeat,
	EPassiveSkillTriggerType_Attack,
	EPassiveSkillTriggerType_Attacked,
	EPassiveSkillTriggerType_Hurted,
	EPassiveSkillTriggerType_Die,
	EPassiveSkillTriggerType_SkillAttack,
	EPassiveSkillTriggerType_UseSkill,
	EPassiveSkillTriggerType_TargetDie,
	EPassiveSkillTriggerType_NormalAttackCaculate_Before,
	EPassiveSkillTriggerType_NormalAttackCaculate_After,
	EPassiveSkillTriggerType_NormalAttackHurt,
	EPassiveSkillTriggerType_SkillHurt,
	EPassiveSkillTriggerType_Move,
	EPassiveSkillTriggerType_Max,
};


//������������
enum EPassiveSkillType
{
	EPassiveSkillType_None = 0,
	EPassiveSkillType_BloodSeek,
	EPassiveSkillType_Rebound,
	EPassiveSkillType_Relive,
};

enum EPassiveSkillTargetType
{
	EPassiveSkillTargetType_Self = 1,
	EPassiveSkillTargetType_Trigger,
	EPassiveSkillTargetType_Both,
};

enum EPassiveRangeType{
	EPassiveRangeType_All = 0,
	EPassiveRangeType_Near,
	EPassiveRangeType_Range,
};

struct SSPassiveSkilllCfg
{
	UINT32	un32PassiveSkillID;//��������id
	ESkillReleaseWay eReleaseWay;//ʩ�ų���
	INT32	n32UpgradeLevel;//��Ӧ�ȼ�
	INT32	n32UseMP;//����MP
	INT32	n32UseHP;//����HP
	INT32	n32UseCP;//����CP
	INT32	n32Cooldown;//��ȴʱ��,0��������ȴ
	EPassiveRangeType eRangeType;//��̴������͡�0������ʹ�á�1��ս��2Զ��
	EPassiveSkillTriggerType lePassiveSkillTriggerType[n_cPassiveSkillTriggerNum];//��������
	INT32	n32TriggerRate;//��������
	INT32	n32TriggerInterval;//����Ƶ��
	BOOLEAN	bIfAffectBuilding;//�Խ�����Ч
	BOOLEAN	bIfAffectHero;//��Ӣ����Ч
	BOOLEAN	bIfAffectMonster;//��NPC��Ч
	EPassiveSkillTargetType	ePassiveSkillTargetType;//���ܴ���ʱ��ѡ���Ŀ������
	BOOLEAN	bIfEffectOnDis;//�����Ƿ��Ƴ�
	SSNextSkillEffectCfg     asStartSkillModelList[c_n32MaxNextSkillEffectCfgNum];//��������ʱ��������������Ч��
	SSNextSkillEffectCfg     asEndSkillModelList[c_n32MaxNextSkillEffectCfgNum];//����ж��ʱ��������������Ч��
	SSNextSkillEffectCfg     asSkillModelList[c_n32MaxNextSkillEffectCfgNum];//�������������������Ч��
	INT32	lPassitiveEffectList[c_n32MaxNextSkillEffectCfgNum];//����������ı�������Ч��

	//��Ч����
	BOOLEAN bIfHasStartEffect;//�Ƿ����������Ч
	BOOLEAN bIfHasReleaseEffect;//�Ƿ���д�����Ч

	BOOLEAN	bIfSendColdDown;//�Ƿ���ͻ��˷�����ȴ��Ϣ

	SSPassiveSkilllCfg()
	{
		memset(this,0,sizeof(*this));
	}
};

//��Ѫ����
struct SSPassiveEffectCfg_BloodSeek
{
	INT32	n32PassitiveEffectID;//����ģ��ID
	INT32	n32BaseValue;//����ֵ
	INT32	n32Percent;//����ǧ�ֱ�
	INT32	n32TargetHealthPercent;//�Է��������ǧ�ֱ�
	INT32	n32SelfHealthPercent;//�Լ��������ǧ�ֱ�
};

//���˱���
struct SSPassiveEffectCfg_Rebound
{
	INT32	n32PassitiveEffectID;//����ģ��ID
	INT32	n32BaseValue;//����ֵ
	INT32	n32Percent;//����ǧ�ֱ�
	INT32	n32TargetHealthPercent;//�Է��������ǧ�ֱ�
	INT32	n32SelfHealthPercent;//�Լ��������ǧ�ֱ�
};

//�����
struct SSPassiveEffectCfg_Relive
{
	INT32	n32PassitiveEffectID;//����ģ��ID
	INT32	n32WaitMilSec;//����ȴ�ʱ��
	INT32	n32BaseHP;//��������HP
	INT32	n32PercentHP;//HPǧ�ֱ�
	INT32	n32BaseMP;//��������MP
	INT32	n32PercentMP;//MPǧ�ֱ�
};


//��������ϵͳ����

enum ESkillEffectMoveType{
	ESkillEffectMoveType_HOME = 1,//�س�
	ESkillEffectMoveType_Absolute,//�ƶ���Ŀ�������
	ESkillEffectMoveType_Opposite,//�����л���������ƶ�
};

enum ESkillEffectMovedTargetType{
	ESkillEffectMovedTargetType_Self = 1,//�Լ�
	ESkillEffectMovedTargetType_Target,//Ŀ��
};

enum ESkillEffectMoveToTargetType{
	ESkillEffectMoveToTargetType_Hit_Anger = 0,//�����ܻ��Ƕ�
	ESkillEffectMoveToTargetType_Self,//�Լ�
	ESkillEffectMoveToTargetType_Target,//ģ���Ŀ��
	ESkillEffectMoveToTargetType_Target_Anger,//�����ܻ�Ŀ��ĽǶ�
	ESkillEffectMoveToTargetType_Master_Anger,//����ʩ���ߵĽǶ�
	ESkillEffectMoveToTargetType_SkillTarget,//����ʩ��ʱ���Ŀ��
};

//λ�Ƽ���ģ��
struct SSkillModelMoveCfg : public SSkillEffectlBaseCfg{
	INT32	n32UseMP;//����MP
	INT32	n32UseHP;//����HP
	INT32	n32UseCP;//����CP
	ESkillEffectMoveType eMoveType;//�ƶ�����
	ESkillEffectMovedTargetType eMovedTargetType;//�ƶ�������
	ESkillEffectMoveToTargetType eMoveToTargetType;//�ƶ�Ŀ������
	INT32	n32Angle;//����ƶ��Ƕ�
	INT32	n32Distance;//����ƶ�����
	INT32	n32Speed;//�ƶ��ٶ�
};

//���ؼ���ģ��
struct SSkillModelSwitchCfg : public SSkillEffectlBaseCfg{
	INT32	n32UseMP;//����MP
	INT32	n32UseHP;//����HP
	INT32	n32UseCP;//����CP
	INT32	lPassitiveEffectList[c_n32MaxNextSkillEffectCfgNum];//���صı�������Ч��
	SSkillModelSwitchCfg()
	{
		memset(this,0,sizeof(*this));
	}
};

enum	EPurificationType{
	ePurType_byType = 1,
	ePurType_byID,
	ePurType_byEffect,
};

//��������ģ��
struct SSkillModelPurificationCfg : public SSkillEffectlBaseCfg{
	INT32	n32UseMP;//����MP
	INT32	n32UseHP;//����HP
	INT32	n32UseCP;//����CP
	EPurificationType ePurType;//��������
	INT32	lPurParameters[c_n32MaxNextSkillEffectCfgNum];//����
	INT32	n32MaxNum;//��󾻻�����
	SSkillModelPurificationCfg()
	{
		memset(this,0,sizeof(*this));
	}
};

enum	ELinkStartPointType{
	eLinkStartPointType_Releaser = 1,
	eLinkStartPointType_ReleaserPos,
};

//���Ӽ���ģ��
struct SSkillModelLinkCfg : public SSkillEffectlBaseCfg{
	INT32	n32UseMP;//����MP
	INT32	n32UseHP;//����HP
	INT32	n32UseCP;//����CP
	BOOLEAN bIfCanBeBreak;//�Ƿ���Ա����
	ELinkStartPointType eStartPointType;//�����������
	BOOLEAN bIfMoveBreak;//�Ƿ�ᱻ�ƶ����
	INT32	n32FarthestDistance;//������
	INT32	n32LastTime;//����ʱ��
	SSNextSkillEffectCfg	asBreakModelList[c_n32MaxNextSkillEffectCfgNum];
	SSNextSkillEffectCfg	asFinishModelList[c_n32MaxNextSkillEffectCfgNum];
	SSkillModelLinkCfg()
	{
		memset(this,0,sizeof(*this));
	}
};

struct SUserLvUpExp
{
	UINT16 un16UserLv;
	UINT32 un32LvUpExp;
};

struct SRunesSlotCfg{
	EObjectType eOT;
	UINT8		un8Level;
	UINT8		un8OpenLevel;
};

struct SRunesComposeInfo{
	SRunesComposeInfo():eOTMin((EObjectType)0)
		, eOTMax((EObjectType)0){
	}
	EObjectType eOTMin;
	EObjectType eOTMax;
};

struct SUserLvUpExpCfg
{
	UINT16 un16UserLv;
	UINT32 un32LvUpExp;
};

enum GoodsType
{
	eGoodsType_None,
	eGoodsType_Hero,
	eGoodsType_Skin,
	eGoodsType_Rune
};

enum EHeroKind
{
	eHeroKind_None = 0,
	eHeroKind_DPS = 1,
	eHeroKind_Magic = 2,
	eHeroKind_ASS = 3,
	eHeroKind_Tank = 4,
};

enum ESkinType{
	eSkin_None = 0,
};

enum EConsumeType
{
	eConsumeType_Free = 0,
	eConsumeType_Gold = 1,
	eConsumeType_Diamond = 2,
};

enum LobbyType
{
	LobbyNull = -1,
	LobbyEle = 0, //������
	LobbyMid = 1, //�м���
	LobbyHey = 2, //�߼���
	LobbyTaW , 
	LobbyPve1 ,
	LobbyTowerDef,
	LobbyPvp007 ,
	LobbyGuid_1 ,
	LobbyGuid_2,
	LobbyGuid_3 ,
	LobbyGuid_4 ,
};

struct SUserBuyGoods
{
	UINT32  n32GoodId;
	UINT32  n32GoodsType;
	UINT32  nTotal; 

	SUserBuyGoods() {memset(this,0,sizeof(*this));}
};

struct SDBCfg 
{
	UINT32	un32DBHostPort;
	CHAR	aszDBHostIP[c_n32DefaultNameLen];
	CHAR	aszDBUserName[c_n32DefaultNameLen * 2];
	CHAR	aszDBUserPwd[c_n32DefaultNameLen * 2];
	CHAR	aszDBName[c_n32DefaultNameLen * 2];
	CHAR	aszUpgradeScriptDir[c_n32DefaultNameLen * 20];

	SDBCfg() { memset(this,0,sizeof(*this)); }
};


enum EMailCurtState
{
	eMailState_None = 0, 
	eMailState_New, 
	eMailState_LookedButNotGotGift,
	eMailState_Look, 
	eMailState_Del,
};
 

struct MailDBData 
{
	INT64		objIdx;
	INT32		mailId;
	INT32		channelId; 
	EMailCurtState		curtState;
	EMailType   mailType; //�ʼ����� 
	INT64		n64CreateTime ;//�ʼ�����ʱ��(mCreateTime����ʱ��)
	INT64		n64EndTime ; //�ʼ�����ʱ�� 

	string		mailTitle;
	string		mailContent; 
	string		mailGift;	//�ʼ����type:key:value eg:1:1:1000;2:2:1000;3:goodsid:1;3:goodsid:2;
	string		szSender; 
	string		mCreateTime;
	string		mEndTime; 
	 
	bool		bIfPerDel;	 
	bool		bIfNewMail;  

	MailDBData():objIdx(0), mailId(0), channelId(0), curtState(eMailState_None), mailType(eMailType_None), n64CreateTime(0),n64EndTime(0){}
	~MailDBData(){}
};

struct UserMailDBData 
{
	INT32		mailId;
	EMailCurtState mState;
	UserMailDBData():mailId(0), mState(eMailState_None){}
	UserMailDBData(INT32 mailId, EMailCurtState mState):mailId(mailId), mState(mState){}
};

struct SUserOfflineMsg
{
	UINT64				sSenderObjIdx;
	UINT64				sReceiverObjIdx;
	TIME_MILSEC			tMsgSendTime;
	CHAR				szMessageInfo[c_n32DefaultNameLen * 5];
};
	class	CFunction{

	public:
		static SGUID_KEY		MakeGUID(EObjectType eObjectType, UINT64 un64ObjIndex)
		{
			return un64ObjIndex;
		}

		static INT32	SplitInt(const CHAR *pszStr, INT32 *pn32IntBuff, INT32 n32IntBuffSize){
			if (NULL == pszStr || NULL == pn32IntBuff || n32IntBuffSize <= 0){
				return 0;
			}

			const char *pszTemp = pszStr;
			INT32 n32FindIntNum = 0;

			while (n32FindIntNum < n32IntBuffSize && *pszTemp != '\0'){
				//go to the first number char.
				while (*pszTemp != '\0'){
					if (*pszTemp >='0' && *pszTemp <= '9'){
						break;
					}else if (*pszTemp == '-' && (*(pszTemp + 1) >='0' && *(pszTemp + 1) <= '9')){
						break;
					}
					pszTemp++;
				}

				pn32IntBuff[n32FindIntNum++] = atoi(pszTemp);

				//go to the end of the number.
				while (*pszTemp != '\0'){
					if (*pszTemp >='0' && *pszTemp <= '9'){
						pszTemp++;
					}else if (*pszTemp == '-' && (*(pszTemp + 1) >='0' && *(pszTemp + 1) <= '9')){
						pszTemp++;
					}else{
						break;
					}				
				}
			}

			return n32FindIntNum;
		}

		static INT32	SplitFloat(const CHAR *pszStr, FLOAT *pfFloatBuff, INT32 n32FloatBuffSize){
			if (NULL == pszStr || NULL == pfFloatBuff || n32FloatBuffSize <= 0){
				return 0;
			}

			const char *pszTemp = pszStr;
			INT32 n32FindIntNum = 0;

			while (n32FindIntNum < n32FloatBuffSize && *pszTemp != '\0'){
				//go to the first number char.
				while (*pszTemp != '\0'){
					if (*pszTemp >='0' && *pszTemp <= '9'){
						break;
					}				
					else if (*pszTemp == '-' && (*(pszTemp + 1) >='0' && *(pszTemp + 1) <= '9')){
						break;
					}
					else if (*pszTemp == '.' && (*(pszTemp + 1) >= '0' && *(pszTemp + 1) <= '9')){
						break;
					}
					pszTemp++;
				}

				pfFloatBuff[n32FindIntNum++] = (FLOAT)atof(pszTemp);

				//go to the end of the number.
				while (*pszTemp != '\0'){
					if (*pszTemp >='0' && *pszTemp <= '9'){
						pszTemp++;
					}else if (*pszTemp == '-' && (*(pszTemp + 1) >='0' && *(pszTemp + 1) <= '9')){
						pszTemp++;
					}else if (*pszTemp == '.' && (*(pszTemp + 1) >= '0' && *(pszTemp + 1) <= '9')){
						pszTemp++;
					}else{
						break;
					}
				}
			}

			return n32FindIntNum;
		}

		static	bool	IfEnemy(INT32 n32LeftCamp, INT32 n32RightCamp){
			if (0 == n32LeftCamp || 0 == n32RightCamp || n32LeftCamp == n32RightCamp){
				return false;
			}
			if (n32LeftCamp % 2 == n32RightCamp %2 ){
				return false;
			}
			return true;
		}

		static	bool IfImpact(const CVector3D &crsPos1, float fRadius1, const CVector3D &crsPos2, float fRadius2){
			float fMiniImpactDist = fRadius1 +fRadius2;
			CVector3D cTempPos = crsPos2;
			cTempPos = cTempPos - crsPos1;
			cTempPos.m_fY = 0;
			if (cTempPos.GetAbs(cTempPos.m_fX) + cTempPos.GetAbs(cTempPos.m_fY) + cTempPos.GetAbs(cTempPos.m_fZ) <= fMiniImpactDist){
				return true;
			}
			float fLength = cTempPos.length();
			if (fLength <= fMiniImpactDist){
				return true;
			}
			return false;
		}

		static	FLOAT	GetAbountDistXZ(const CVector3D &crsLeft, const CVector3D &crsRight){
			CVector3D cDist = crsLeft - crsRight;
			cDist.m_fY = 0;
			return cDist.length();
		}

		static EIntDir	GetIntDirByPoint(INT32 n32X1, INT32 n32Z1, INT32 n32X2, INT32 n32Z2){
			EIntDir eIntDir = (EIntDir)g_Dir64To8(g_GetDirIndex(n32X1, n32Z1, n32X2, n32Z2));
			return eIntDir;
		}

		static	EIntDir	GetIntDirByIndx(INT32 n32BeginX, INT32 n32BeginZ, INT32 n32EndX, INT32 n32EndZ){
			INT32 n32XDiff = n32EndX - n32BeginX;
			INT32 n32ZDiff = n32EndZ - n32BeginZ;
			return GetIntDirByIndxDiff(n32XDiff, n32ZDiff);
		}

		static	EIntDir	GetIntDirByIndxDiff(INT32 n32XDiff, INT32 n32ZDiff){
			EIntDir eDir = eIntDir_Invalid;
			if (0 == n32XDiff){
				if (0 > n32ZDiff){
					eDir = eIntDir_Below;
				}else if (0 < n32ZDiff){
					eDir = eIntDir_Up;
				}
			}else if (0 > n32XDiff){
				if (0 > n32ZDiff){
					eDir = eIntDir_BelowLeft;
				}else if (0 == n32ZDiff){
					eDir = eIntDir_Left;
				}else if (0 < n32ZDiff){
					eDir = eIntDir_UpLeft;
				}
			}else if (0 < n32XDiff){
				if (0 > n32ZDiff){
					eDir = eIntDir_BelowRight;
				}else if (0 == n32ZDiff){
					eDir = eIntDir_Right;
				}else if (0 < n32ZDiff){
					eDir = eIntDir_UpRight;
				}
			}
			return eDir;
		}

		static INT32	GetIntDiffByIntDir(EIntDir eIntDir, INT32 &rn32XDiff, INT32 &rn32ZDiff){
			if (eIntDir_UpLeft == eIntDir){
				rn32XDiff = -1;
				rn32ZDiff = 1;
			}else if (eIntDir_Up == eIntDir){
				rn32XDiff = 0;
				rn32ZDiff = 1;
			}else if (eIntDir_UpRight == eIntDir){
				rn32XDiff = 1;
				rn32ZDiff = 1;
			}else if (eIntDir_Left == eIntDir){
				rn32XDiff = -1;
				rn32ZDiff = 0;
			}else if (eIntDir_Right == eIntDir){
				rn32XDiff = 1;
				rn32ZDiff = 0;
			}else if (eIntDir_BelowLeft == eIntDir){
				rn32XDiff = -1;
				rn32ZDiff = -1;
			}else if (eIntDir_Below == eIntDir){
				rn32XDiff = 0;
				rn32ZDiff = -1;
			}else if (eIntDir_BelowRight == eIntDir){
				rn32XDiff = 1;
				rn32ZDiff = -1;
			}else{
				rn32XDiff = 0;
				rn32ZDiff = 0;
			}
			return eNormal;
		}

		static double GetPointDistance(const CVector3D &crcP1, const CVector3D &crcP2)   
		{  
			return sqrt((crcP1.m_fX-crcP2.m_fX)*(crcP1.m_fX-crcP2.m_fX)+(crcP1.m_fZ-crcP2.m_fZ)*(crcP1.m_fZ-crcP2.m_fZ)); 
		}

		static double GetNearestDistance(const CVector3D &crcPA, const CVector3D &crcPB, const CVector3D &crcP3)
		{
			double a,b,c;  
			a=GetPointDistance(crcPB,crcP3);  
			if(a<=0.00001){
				return 0.0f;
			}		
			b=GetPointDistance(crcPA,crcP3);
			if(b<=0.00001){
				return 0.0f;
			}
			c=GetPointDistance(crcPA,crcPB);  
			if(c<=0.00001) {
				return a;//���PA��PB������ͬ�����˳������������ؾ���   
			}
			if(a*a>=b*b+c*c){//--------ͼ3--------   
				return b;      //����Ƕ۽Ƿ���b   
			}
			if(b*b>=a*a+c*c){//--------ͼ4-------   
				return a;      //����Ƕ۽Ƿ���a   
			}
			double l=(a+b+c)/2;     //�ܳ���һ��   
			double s=sqrt(l*(l-a)*(l-b)*(l-c));  //���׹�ʽ�������Ҳ������ʸ����   
			return 2*s/c;  
		} 

		static INT32  GetGameRandomN(std::default_random_engine & sGenerator, INT32 beginN,  INT32  endN)
		{ 	 
			std::uniform_int_distribution<int> distribution(beginN, endN);

			INT32  nRet = distribution(sGenerator);
			return nRet;
		}

		static INT64 GetCurrentUTCTime(){
			static LARGE_INTEGER s_frequency;
			static BOOL s_use_qpc = QueryPerformanceFrequency(&s_frequency);
			if (s_use_qpc) {
				LARGE_INTEGER now;
				QueryPerformanceCounter(&now);
				return (1000LL * now.QuadPart) / s_frequency.QuadPart;
			} else {
				return GetTickCount();
			}
		}

		//2014/5/9 17:41:12
	static	std::string GetCurtFormatTime(time_t t )
		{	 
			time_t curt; 
			struct tm * ptm;
			if (t > 0)
			{
				curt = t;
			}else
			{
				time(&curt); 
			}

			ptm = localtime(&curt);

			char szTime[32]={0};
			sprintf(szTime,"%d-%d-%d %d:%d:%d",ptm->tm_year + 1900,ptm->tm_mon + 1, ptm->tm_mday,ptm->tm_hour,ptm->tm_min,ptm->tm_sec);

			return string(szTime);
		}
	static	void GetYMDHMSInfo(std::string & str,const char* signd, INT32 &p1,INT32& p2, INT32& p3)
		{
			std::vector<std::string> tVec;   
			boost::algorithm::split(  tVec,str, boost::algorithm::is_any_of(signd) ); 
			if (tVec.size() != 3)
			{
				return;
			}
			p1= atoi(tVec[0].c_str());
			p2= atoi(tVec[1].c_str());
			p3= atoi(tVec[2].c_str()); 
		}
		//xxx-xxx-xxx hh:mm:ss
	static	INT64  FormatTime2TimeT(const char * dt)
		{
			if(NULL == dt  )
			{
				return 0;
			}
			std::string timeStr(dt);

			INT32 y,m,d,mh,ms,mss;
			std::vector<std::string> tVec; 
			boost::algorithm::split( tVec, timeStr, boost::algorithm::is_any_of(" ") ); 
			if (tVec.size() != 2)
			{
				return 0;
			}
			GetYMDHMSInfo(tVec[0],"-",y,m,d);
			GetYMDHMSInfo(tVec[1],":",mh,ms,mss);
			CTime  t(y,m,d,mh,ms,mss);  

			return t.GetTime();
		}

		//xxx-xx-xx hh:mm:ss
	static	bool CompareTime(time_t st, const char * dt)
		{
			if(NULL == dt || st < 1)
			{
				return false;
			}
#if 0
			std::string  smt = GetCurtFormatTime(st);

			char cdump;

			stringstream mystream(smt);

			mystream >> y >> cdump >> m >> cdump >> d >> cdump >> h >> cdump >> ms >> cdump >> mss;
			CTime  t1(y,m,d,h,ms,mss);

			mystream.clear();
			mystream.str(dt);
			mystream >> y >> cdump >> m >> cdump >> d >> cdump >> h >> cdump >> ms >> cdump >> mss;
			CTime  t2(y,m,d,h,ms,mss);

			if( ( t2 - t1).GetTotalSeconds() > 0)
			{
				return true ;
			}
#endif
			INT64 crt = FormatTime2TimeT(dt);

			if( crt >= st  )
			{
				return true ;
			}
			return false;		
		} 

		
	};

	//�ַ�װ��: 
	template<class T>
	void addto_string(std::string &result, const T &t)
	{
		ostringstream myoss;
		myoss << t;
		result += myoss.str();
	}  

	enum EMapType{
		eMT_Normal = 0,
	};

	enum EMapAIType{
		eMAIT_Normal = 0,
	};
	enum eMapObjType
	{
		eObj_Build_HomeBase		= 0, 
		eObj_Build_Arrowhead,		//����

		eObj_Build_Shop,

		eObj_Ohter = 20,


		eBuild_End,
	};

	struct SMapObjInfo
	{
		UINT32	un32ObjIdx;
		eMapObjType eType; 

		CVector3D cPos;
		CVector3D cDir; 
	};

	

	struct SCellInfo{
		UINT16 un16XCellIdx;
		UINT16 un16ZCellIdx;
	};

	
	
//////////////////////////////////�����������/////////////////////////////////////////
	struct SHeroBornPos 
	{ 
		CVector3D bPos;
		CVector3D bPosDir;
		CVector3D bRelivePos;

		SHeroBornPos(){bPos.Zero();bPosDir.Zero();bRelivePos.Zero();};
		~SHeroBornPos(){}
	};

	 
	struct SBornChariotCfg
	{
		INT32	charSolderBornTimes;	//�����̱��Ĳ���
		INT32	chariotSolderIdx;	//���̳����

		SBornChariotCfg() {memset(this,0,sizeof(*this));}
	};

	struct SSuperSolderCfg 
	{
		INT32				 pathId;					//����������Ӧ��·��
		std::vector<INT32>   altarIdx ;					//��̳���
		std::vector<INT32>   superSolderIdx ;			//���������

		SSuperSolderCfg() { memset(this,0,sizeof(*this));}

		void Set(SSuperSolderCfg &t )
		{
			altarIdx = t.altarIdx;
			superSolderIdx = t.superSolderIdx;
		}
	};

	struct SSolderGoWayPointCfg
	{
		INT32		camp;
		std::vector<CVector3D> vecPoint;
	};

	struct SMapSolderInfoCfg 
	{
		INT32	baseBuildIdxCfg;			//���ر��
		//INT32	campIdCfg;					//��Ӫ
		INT32	totalSolderCfg;				//���γ�������
		INT32	solderTimeSpaceCfg;			//��������ʱ����
		INT32	everyTimeSpace;				//��������ʱ����

		std::vector<INT32>	solderIdxCfg;				//С�����

		SBornChariotCfg	mChariotSolderCfg;	//�����̳����� 
		SSuperSolderCfg  mSuperSolderCfg;	//���������� 

		CVector3D  bornPosCfg;					//��������
		CVector3D  bornDirCfg;					//�������� 
		SMapSolderInfoCfg(){memset(this,0,sizeof(*this));}

		void Set(SMapSolderInfoCfg & t)
		{
			baseBuildIdxCfg = t.baseBuildIdxCfg;
			//campIdCfg = t.campIdCfg;
			totalSolderCfg = t.totalSolderCfg;
			solderTimeSpaceCfg = t.solderTimeSpaceCfg;
			everyTimeSpace = t.everyTimeSpace;
			bornPosCfg = t.bornPosCfg;
			bornDirCfg = t.bornDirCfg;
			for (int i=0; i< t.solderIdxCfg.size(); i++)
			{
				solderIdxCfg.push_back(t.solderIdxCfg[i]);
			}

			mChariotSolderCfg = t.mChariotSolderCfg;

			mSuperSolderCfg.Set(t.mSuperSolderCfg);
		}
	};

	struct SMapCurtBornSolderInfo
	{
		INT32   curtBornSolderPos;			//��ǰ������λ��
		INT32	curtBornSolderTimes;		//��ǰ��������

		bool	bSuperState;				 //��������״̬ 
		
		std::vector<INT32>   curtBrokenAltarIdx; //��ǰ�򱬵ļ�̳����	

		SMapCurtBornSolderInfo(){memset(this,0,sizeof(*this));}

		~SMapCurtBornSolderInfo(){curtBrokenAltarIdx.clear();}

		void Set(SMapCurtBornSolderInfo & t)
		{
		   curtBornSolderPos = t.curtBornSolderPos;
		   curtBornSolderTimes = t.curtBornSolderTimes;
		   bSuperState = t.bSuperState;

		   for (int i=0; i < t.curtBrokenAltarIdx.size(); i++)
		   {
			   curtBrokenAltarIdx.push_back(t.curtBrokenAltarIdx[i]);
		   }
		}
	};

	struct SAltarSolderCfg
	{
		INT32  pathId;					//��̳����·��
		INT32  bornSolderSpaceTime;		//��̳������ ʱ����
		INT32  bornNum;					//��̳ÿ�γ�������
		INT32  maxSolderNum;			//��ͼ�ϼ�̳������������(-1������)

		CVector3D bornPos;				//��������
		CVector3D bornDir;				//��������

		SAltarSolderCfg(){memset(this,0,sizeof(*this));}

		~SAltarSolderCfg(){bornPos.Zero();bornDir.Zero();};
	};

	//SS�����ӳ�
	enum  EGameFunDelay
	{
		eDelay_None = 0,
		eDelay_Solder = 1, //�����ӳ�
		eDelay_PrimaryMonster,		//����Ұ��
		eDelay_HightMonster,//�߼�Ұ��
		eDelay_AltarSolder,	//��̳��
	};

	struct SGameDelayTimeCfg
	{
		INT64	mSoldeDelay;				//С�������ӳ�
		INT64   mPrimaryWMMonsterDelay;		//����Ұ�ֳ����ӳ�
		INT64   mHighWMMonsterDelay;			//�߼�Ұ�ֳ����ӳ�
		INT64   mAltarSolderDelay;			//��̳�����ӳ�

		SGameDelayTimeCfg(){memset(this,0,sizeof(*this));}
	};

	struct SGameWildMonsterCfg
	{
		INT32    lv;//�ȼ�
		INT32    num;//��������
		INT32	 refreshTime;		//����ˢ��ʱ��
		bool	 bIfRandom;			//�Ƿ����
		std::vector<INT32>	vecIdx;//Ұ��ID
		CVector3D   bornPos;		//��������
		CVector3D   bornDir;		//������������

		SGameWildMonsterCfg(){vecIdx.clear(); bornPos.Zero(); bornDir.Zero(); }
		~SGameWildMonsterCfg(){vecIdx.clear(); bornPos.Zero(); bornDir.Zero();}
	};


	struct CurtAltarBornSolder
	{
		INT32	monsterId;		//��ǰҰ��ID
		INT32	curtBornNum;	//��ǰ����������
		INT64   nextBornTime;	//��������ʱ��

		INT32			 campId;	//·��������Ӫ
		SAltarSolderCfg  mCfg;  //��̳����

		CurtAltarBornSolder(){memset(this,0,sizeof(*this));}
		~CurtAltarBornSolder(){}
	};

	struct CurtWildMonsterInfo
	{
		INT64	nextBornTimeCfg;
		INT64	nextBornTime;
		std::map<INT32/*monsterid*/,bool>  mapMonsterId;

		CurtWildMonsterInfo(){nextBornTimeCfg = 0;nextBornTime = 0; mapMonsterId.clear();}
		~CurtWildMonsterInfo(){mapMonsterId.clear();}
	};
	/////////////////////////////////��������/////////////////////////////////////////////

	//���ֽ�������
	enum EGuideAward
	{
		eAward_None = 0,
		eAward_Gold,
		eAward_Diamond,
		eAward_Other,
	};


	enum EGuideBornObjType
	{
		eGuideObjType_None = 0,
		eGuideObjType_Solder,		//С��
		eGuideObjType_Monster,		//Ұ��
		eGuideObjType_Hero,			//Ӣ��
	};
	enum EGuideRageObjType
	{
		eRage_None = 0,
		eRage_UserHero,	//���Ӣ��
		eRage_AiHero,		//AIӢ��
	};

	struct SGuideSolderCfg
	{
		INT32	  bornSpaceTimeCfg;	    //С��֮��ʱ����
		INT32	  bornAheadTimeCfg;		//ÿ��������ʱ����  

		INT32     campidCfg;			//��Ӫ
		INT32	  closeTaskIdCfg;		//�رոò�������id
		

		CVector3D bornPosCfg;			//������
		CVector3D bornDirCfg;			//�������� 

		char	altaridVecCfg[32];//��̳ID
		std::vector<CVector3D>	mGoPathPointCfg; //Ѱ·�� 
		std::vector<INT32/*objId*/>	vecObjIdCfg;//��������id

		SGuideSolderCfg(){memset(altaridVecCfg,0,sizeof(altaridVecCfg)); mGoPathPointCfg.clear();vecObjIdCfg.clear();}
		~SGuideSolderCfg(){}
	};

	enum EGuideHeroBornType
	{
		eHeroBornType_None = 0,
		eHeroBornType_Pos,		//���ó�����
		eHeroBornType_UserArround,		//�����Χ
	};
	struct SGuideHeroCfg 
	{
		INT32     objIdxCfg;
		INT32     campIdCfg;

		INT32     reliveTimeCfg;//����ʱ��

		bool	  ifRage;

		EGuideHeroBornType bornTypeCfg;

		//CVector3D bornPosCfg;
		//CVector3D relivePosCfg; 
		//CVector3D bornDirCfg; 
		
		std::vector<CVector3D>	mGoPathPointCfg; //Ѱ·�� 

		SGuideHeroCfg():objIdxCfg(0),campIdCfg(0),reliveTimeCfg(0),bornTypeCfg(eHeroBornType_None){mGoPathPointCfg.clear();} 
	};
	/* taskmanager.xml
		1,·������
		2,�����ť����
		3,��ɱ����
		4,ʱ���������
		5,��������
		6,��Ϸ��ͣ����
		7,������ʾ����
		8,��������
		9,��Ļ 
		10,��������
		11,�ƶ����������
		12,���嶯������
		13,�赲����
		14,������ʾ����
		15,����
		16,��Ӣ��
*/
	enum EChildTaskType
	{
		eTaskType_None = 0,
		eTaskType_Path,
		eTaskType_Button,
		eTaskType_Kill,
		eTaskType_TimeEvent,
		eTaskType_Straw,
		 eTaskType_Stop,
		 eTaskType_Display,
		 eTaskType_Award,
		 eTaskType_Tips,
		 eTaskType_Autio,
		 eTaskType_MoveRadio,
		 eTaskType_Animation,
		 eTaskType_Block,
		 eTaskType_ShowBox,
		 eTaskType_BornSolder,
		 eTaskType_BornHero,
	};
	//���� �������ͣ�
	enum EGuidDotype
	{
		eDotype_None = 0,
		eDotype_CompTask, //�������
		eDotype_BuyGoods, //����
		eDotype_BornSolder,//����
		eDotype_BornHero,//��Ӣ��
		eDotype_NextStep,
	};
	struct SGuideBattleCompTask 
	{
		EChildTaskType			childType;//������(���ڲ��Ҷ�Ӧ���ļ�)
		INT32					stepId;	//�����ͱ��

		SGuideBattleCompTask(){memset(this,0,sizeof(*this));}
		~SGuideBattleCompTask(){}
	}; 

	struct SGuideCurtBornSolder
	{
		INT32   curtBornSolderPos;			//��ǰ������λ�� 
		INT64	nextBornTime;				//�´γ���ʱ��

		SGuideSolderCfg	  cfg;

		SGuideCurtBornSolder(){memset(this,0,sizeof(*this));}
		~SGuideCurtBornSolder(){}
	}; 

	 enum EGuideHurtObjType
	 {
		 eHurtObj_None = 0,
		 eHurtObj_Arrow,		//����
		 eHurtObj_Altar,		//��̳
		 eHurtObj_Base,			//������
	 };
	 enum EGuideAtkType
	 {
		 eAtkType_None = 0,
		 eAtkType_Solder,		//С��
		 eAtkType_User,			//wanji9
		 eAtkType_All,			//����
	 };
	 struct SGuideHurtBuildCfg
	 {
		EGuideHurtObjType  objTypeCfg;
		INT32			   objIdxCfg;
		EGuideAtkType		atkTypeCfg;

		SGuideHurtBuildCfg():objTypeCfg(eHurtObj_None),objIdxCfg(0),atkTypeCfg(eAtkType_None){}
		~SGuideHurtBuildCfg(){}
	 };

	 struct SGuideCurtBuildBeHurt
	 { 
		 bool	  bBeHurt;					//�Ƿ��ʱ��������

		 SGuideHurtBuildCfg  cfg;

		 SGuideCurtBuildBeHurt() {memset(this,0,sizeof(*this));}
		 ~SGuideCurtBuildBeHurt(){}
	 };

	 struct CSGuideAward
	 {
		 INT32	taskId;
		 INT32  gold;
		 INT32  diamond;
		 INT32  heroid;
		 INT32  runeid;
		 INT32	skinid;
		 INT32  exp; 

		 CSGuideAward(){memset(this,0,sizeof(*this));}
		 ~CSGuideAward(){}
	 };
	 //����������ͼ����
	 enum  EGuideMapType
	 {
		 eGuideMapType_None = 0,
		 eGuideMapType_First,
		 eGuideMapType_Second,
	 };

	/////////////////////////////////////////////���ֽ���/////////////////////////////////////////

	 enum ENoticeFlag
	 {
		 eFlag_None = 0,
		 eFlag_OnSale = 1,
		 eFlag_Notice = 2,
		 eFlag_Services = 3,
	 };

	 enum ENoticeState
	 {
		 eState_None = 0,
		 eState_Hot = 1,
		 eState_New = 2,
	 };

	 struct SNotice
	 {
		 //�ֶΡ����ԡ��������¼�
		 INT64	noticeID;//���ݿ�����
		 UINT32 id;
		 EUserPlatform platform;
		 string title;
		 ENoticeFlag flag;
		 ENoticeState state;
		 int priority;
		 string msg;
		 UINT64 star_time;
		 UINT64 end_time;

		 SNotice():noticeID(0){
			 platform = ePlatform_PC;
			 title = "";
			 flag = eFlag_None;
			 state = eState_None;
			 priority = 0;
			 msg = "";
			 star_time = 0;
			 end_time = 0;
		 }
	 };
 

	 ////////////////////////////////////��Ϸ��־//////////////////////////////////////
	 //��־����
	#define  LOG_SIGN "#"  //�ֶηָ�����
	#define LOG_SIGN_FIRST ":" //�����ֶηָ�����
	#define LOG_SIGN_SECOND ";" //С���ֶηָ�����
	 #define LOG_SIGN_LEFT "(" //С���ֶηָ�����
	 #define LOG_SIGN_RIGHT ")" //С���ֶηָ�����
	 enum EGameLog
	 { 
		 eLog_None = 0,
		 eLog_Register, //Register
		 eLog_HeadUse,	//HeadUse
		 eLog_Login,	//Login
		 eLog_Logout,	//Logout

		 eLog_Guide = 10,	//Guide
		 eLog_Daily,	//DailyAward
		 eLog_Exchange,//eLog_Exchange
		 eLog_ChangeName,//eLog_ChangeName

		 eLog_CreateMatch=14,//CreateMatch
		 eLog_LogoutMatch,//LogouMatch
		 eLog_MatchEnd,	//FaceAI
		 eLog_CreateHouse, //CreateHouse
		 eLog_AddHouse,		//AddHouse
		 eLog_HouseStart,	//HouseStart

		 //buy
		 eLog_BuyHouse,		//BuyHouse
		 eLog_BuySkin,		//BuySkin
		 eLog_BuyRune,		//BuyRune
		 eLog_BuyGoods,		//BuyGoods
		 //use
		 eLog_RuneUse,		//RuneUse
		 eLog_RuneUnUse,		//RuneUnUse
		 eLog_RuneCompose,	//RuneCompose
		 eLog_RuneWashing,	//RuneWashing
		 //friend
		 eLog_FriendAdd,	//FirendAdd
		 eLog_FriendDel,	//FriendDel
		 eLog_EnemyFriendAdd,//EnemyFriendAdd
		 eLog_EnemyFriendDel,//EnemyFriendDel 
		 //��������
		 eLog_ChangeUseName, //ChagneUseName
		 eLog_UseInfoLogout, //UseInfoLogout
		 //chat
		 eLog_Chat,			//Chat
		 //UIEvent
		 eLog_UIEvent,		//UIEvent
		 //select hero
		 eLog_ChoseHero,	//ChoseHero
		 eLog_ChoseRune,	//ChoseRune
		 eLog_ChoseSkin,	//ChoseSkin
		 //����
		 eLog_UserDiscon = 40,//UserDiscon
		 eLog_UserRecon,		//UserRecon
		 eLog_KickUser,			//KickUser

		 //battle data 
		 eLog_BattleStart = 60,		//BattleStart 
		 eLog_BattleBuy,			//BattleBuy
		 //skill 71-80
		 eLog_BattleSkill = 71,			//		BattleSkill
		 eLog_BattleSkillHurt,			//BattleSkillPhysicalHurt  
		 eLog_BattleSkillEquip,				//BattleSkillEquip

		 //kill
		 eLog_BattleKillSolder=81,				//BattleKillSolder
		 eLog_BattleKillMonster,				//BattleKillMonster
		 eLog_BattleKillHero,					//BattleKillHero,
		 eLog_BattleKillBuild,					//BatlleKillBuild
		 eLog_BattleStrawMonster,				//BattleStrawMonster
		 eLog_BattleAltarSolder,				//BattleAltarSolder
		 eLog_BattleHeroMounKill,				//BattleHeroMounKill  Ӣ�۶�ɱ

		 //disc
		 eLog_BattleRecon = 95,						//BattleRecon
		 eLog_BattleUserOffLine,					//BattleKickUser

		 //other
		 eLog_BattleEnd = 110,					//BattleEnd
		 eLog_BattleSelGoods,					//BattleSelGoods
		 eLog_BattleExpersion,					//����

		 eLog_BattleGuideStart = 150,					//����������ʼ
		 eLog_BattleGuideCompStep,						//������ɵĲ���		
		 eLog_BattleGuideEnd,							//������������
	 };

	 
	  ////////////////////////////////////��Ϸ��־����//////////////////////////////////////