#pragma once
#include <boost/atomic.hpp>
#include <vector>
#include <map>
#include <random>
#include "RobotNPC.h"
#include "Player.h"
#include "Hero.h"
#include "../ELogging/ELogging/ThreadSafeQueue.h"
#include <boost/atomic.hpp>

enum EBattleMatchType
{
	eMatchType_None,
	eMatchType_VsAI,//�˻���ս(������ҵз�������)//
	eMatchType_Nomal,//��ͨ��ս//
	eMatchType_Tianti,//���ݶ�ս// 
	eMatchType_Total, 
};

enum RobotBattleState
{
	RBS_None,//�����ѡ��ƥ�䣬���䣬����������Ҳ�ɵȴ�������ң������ϲ��������
	RBS_InRoomAsMaster,//�����ѡ�������䣨��Ա����ȫ׼���ã�
	RBS_InRoomAsMasterStart,//�ȴ�����ս����..
	RBS_InRoomAsPlayer,//���ڷ������ˣ���ѡ��׼������
	RBS_InRoomAsPlayerReady,//���Ѿ�׼�����ˣ������ȡ��׼�����뿪����
	RBS_InTeamAsMaster,//�����Ҫ��С��������Ҳ����һ����·
	RBS_InTeamAsMasterMatch,//ǰ������ս�������߿���ѡ���뿪
	RBS_InTeamAsPlayer,//�㱻������������������뿪��
	RBS_InTeamAsPlayerMatch,//ǰ������ս�����������̫�����Ͽ��Ӱ�...
	RBS_InBattleNow,//��ʼս���ɣ���ס����Ӣ��
};

enum RobotBattleType
{
	RBT_None,
	RBT_Room,
	RBT_Match,
	RBT_Guide,
};

// ���ݽ�ɫ�������ʱ��δ����ս�������°��ݽ�ɫ
enum RobotRole
{
	RRIR_AsIdle,
	RRIR_AsRoomMaster,
	RRIR_AsRoomMate,
	RRIR_AsTeamMaster,
	//RRIR_AsTeamMate,
	RRIR_AsTotal,
};

enum ESSBattleState
{
	eSSBS_SelectHero = 0,
	eSSBS_SelectRune,
	eSSBS_Loading,
	eSSBS_Playing,
	eSSBS_Finished,
	eSSBS_Invalid = 0xFFFF,
};

enum RobotLoginState
{
	RLS_None,
	RLS_LsConnecting,
	RLS_LsConnected,
	RLS_LsAskLogin,
	RLS_LsAskLoginError,
	RLS_LsHadGetBsAddress,
	RLS_BsConnecting,
	RLS_BsConnected,
	RLS_BsAskLogin,
	RLS_BsAskLoginRet,
	RLS_BsHadGetGsAddress,
	RLS_GsConnecting,
	RLS_GsConnected,
	RLS_GsAskLogin,
	RLS_GsHadGetBaseInfo,
};

enum RobotAskState
{
	RS_AskNone,
	RS_AskCompleteUserInfo,//�����û���Ϣ
	RS_AskCompleteUserInfoFailed,//������Ϣʧ��
	RS_AskCompleteUserInfoOk,//������Ϣ�ɹ�
	RS_AskReEnterRoom,//�����ؽ�����
	RS_AskReEnterRoomFailed,//û�з���
	RS_AskMatchTeamList,//����ƥ�����
	RS_AskMatchTeamListFailed,//û�����
	RS_AskCreateMatchTeam,//����ƥ�����
	RS_AskCreateMatchTeamFailed,//����ƥ�����ʧ��
	RS_AskStartMatch,//��ʼƥ��
	RS_AskStartMatchFailed,//��ʼƥ��ʧ��
	RS_AskRoomList,//�����б�
	RS_AskRoomListFailed,//���󷿼��б�ʧ��
	RS_AskCreateRoom,//��������
	RS_AskAddRoom,//���뷿��
	RS_AskLeaveRoom,//�뿪����
	RS_AskReadyRoom,//׼������
	RS_AskCancelReadyRoom,//ȡ��׼��
	RS_AskStartRoom,//��ʼ����
	RS_AskStartRoomFailed,//��ʼ����ʧ��
	RS_AskChangeRoomSeat,//�л�����λ��
	RS_AskEnterBattle,//����ս��
	RS_AskEnterBattleFailed,//����ս��ʧ��
	RS_AskGMCmd,
	RS_AskTryToSelectHero,//����ѡ��Ӣ��
	RS_AskTryToSelectHeroFailed,//
	RS_AskTryToSelectHeroOk,//
	RS_AskSelectHero,//ѡ��Ӣ��
	RS_AskSelectHeroFailed,
	RS_AskSelectHeroOk,
	RS_AskLoadMapComplete,//��ͼ���
	RS_AskEnd,
};

namespace ReBot
{
	class CClientGameObject;
	class CRebotHero;
	class CRobotNPC;
	class CRobotPlayer;

	class CCClient
	{
		friend class CRobotMgr;

	public:
		CCClient(CRobotMgr* pMgr,UINT32 robotId);
		~CCClient();

	public:
		CRobotMgr* m_pRobotMgr;//������
		UINT32 m_un32RobotID;//�����˱��
		INT8 m_n8RobotSex;//�Ա�
		UINT32 m_un32HeaderID;//ͷ��
		INT32 m_n32NSID;//������
		INT32 m_n32SSID;//SSID
		EServerLinkType m_SLinkState;//��ǰ����(LS,BS,GS)
		RobotLoginState mLoginState;//��¼״̬
		RobotAskState m_eAskState;//����״̬
		ESSBattleState m_eServerBattleState;//������ս��״̬
		DWORD m_ServerStartTime;
		boost::atomic_bool m_bConnected;//�Ƿ�������
		boost::atomic_bool m_bSendConnect;//�Ƿ��ѷ�������
		SGUID_KEY m_UserGUID;//�û�guid
		UINT32 m_MapID;//���߳�ʼ����ս������//
		UINT64 m_un64BattleID;//���߳�ʼ����ս������
		RobotBattleType m_BattleType;//�û��Զ���ս������
		CRobotPlayer* m_pPlayer;//AI������
		UINT8 m_un8SeatPos;//����λ�ú�
		string m_sToken;//bs��������gs������
		string m_gateIp;//bs���ص�gate ip
		UINT32 m_gatePort;//bs���ص�gate port
		string m_szUserName;//�û���
		string m_szUserPwd;//����
		string m_szNickName;//�ǳ�
		string m_szUserNameRet;//GS���ص��û���
		map<UINT32,RobotTimes> m_RoomCounter;//���������
		std::vector<UINT32>	m_HeroVec;//��ѡӢ���б�
		GOMap m_pClientGameObjectMap;//��Ϸ����(���ߡ�ս����������)
		RobotRole m_Role;
		map<UINT32,SRoomInfo> mRoomlist;//���淿���б�
		bool mHadOnce;
		DWORD m_AskRoomListTime;
		DWORD m_AskAddRoomTime;
		DWORD m_RoomMasterWaitTime;
		DWORD m_DisConnectTime;
		map<UINT32,STeamInfo> mTeamList;//������Ϣ
		DWORD mTeamID;
		INT32 m_LastErrorCode;

	public:
		void		SetRobotMgr(CRobotMgr*	pRobotMgr) { m_pRobotMgr = pRobotMgr; }
		void		Connect();//��������
		void		EnterBattle(DWORD curTime);//����ս��
		void		PlayBattle(DWORD curTime);//ս���淨
		void		FinishBattle(DWORD curTime);//����ս��
		bool		HandleMsgFalter(INT32 n32NSID, const char* pMsg, int n32MsgLength, int n32MsgID);
		INT32		HandleMsg(INT32 n32NSID, const char* pMsg, int n32MsgLength, int n32MsgID);
		void		OnHeartBeat(DWORD curTime);
		CClientGameObject* GetGOByGUID(const SGUID_KEY& guid);
		GOMap&		GetGOMap(){return m_pClientGameObjectMap;}
		void		EraseObj(const SGUID_KEY& guid);
		void		ClearAllGO();
		std::string GetRandStr(INT32 n32Len);
		std::string GetRandStrFromNum(INT32 n32Len);

	public:
		INT32		OnNetConnected(INT32 n32NetSessionID);
		INT32		OnNetRealConnected(INT32 n32NetSessionID);
		INT32		OnNetDisconnected(INT32 n32NetSessionID);
		INT32		EmsgToLs_AskLogin(UINT platform,string uin,string sessionid);
		INT32		EmsgToBs_AskLogin(UINT platform,string uin,string sessionid);
		INT32		EmsgToGs_AskLogin(UINT platform,string name,string pass,string equip); 
		void		NetworkClose(EServerLinkType type);

	public:
		INT32		AskCompleteUserInfo(const CHAR *szNickname, UINT32 un32HeaderID, INT8 n8Sex);
		INT32		AskReEnterRoom();//�����ؽ�����
		INT32		AskMatchTeamList();//����ƥ���б�

	public:
		INT32		AskCreateMatchTeam(UINT32 mapid, EBattleMatchType matchType);
		INT32		AskStartMatch();
		INT32		AskRoomList();//���Ѳ���ѡ��
		INT32		AskCreateRoom();//��������ѡ��
		INT32		AskAddRoom(UINT32 room);
		INT32		AskStartRoom();
		INT32		AskLeaveRoom();
		INT32		AskChangeRoomSeat(INT32	n32NewSeat);
		INT32		AskReadyRoom();
		INT32		AskCancelRoom();

	public:
		INT32		AskEnterBattle(UINT64 un64BattleID);
		INT32		AskGMCmd(const char* gmCmd);//GM����
		INT32		AskTrySelectHero();
		INT32		AskSelectHero();
		INT32		AskLoadMapComplete();
		INT32		AskMoveDir(const CVector3D& cDir);
		INT32		AskBackToHome();
		INT32		AskMovePos(const CVector3D& cPos);
		INT32		AskStopMove();
		INT32		AskLockTar(const SGUID_KEY& sGUID);
		INT32		AskBuyGoods(INT32 n32Goods);
		INT32		AskUseGoods(UINT8 un8Pos);
		INT32		AskSellGoods(UINT8 un8Pos);
		INT32		AskMoveGoods(UINT8 un8FromPos, UINT8 un8ToPos);
		INT32		AskAutoAtk();
		INT32		AskUseSkill(UINT32 un32SkillID);
		INT32		AskAlwaysAutoAtk(INT8 n8Flag);
		INT32		AskReward();
		INT32		AskAbsorb();
		INT32		AskReportAltarStrawSolder(int n32MonsterID);

	private:
		INT32		OnMsgFromGS_GCAskPingRet(const char* pMsg,int n32MsgLength,int n32MsgID);	//message 1
		INT32		OnMsgFromGS_NotifyUserBaseInfo(const char* pMsg,int n32MsgLength,int n32MsgID);	//message 2
		INT32		OnMsgFromGS_GCAskRetError(const char* pMsg,int n32MsgLength,int n32MsgID);		//message 5
		INT32		OnMsgFromGS_IsOnSS(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsgFromGS_NotifyHeroList(const char* pMsg,int n32MsgLength,int n32MsgID);	//message 7
		INT32		OnMsgFromGS_NotifyBattleBaseInfo(const char* pMsg,int n32MsgLength,int n32MsgID);	//message 8
		INT32		OnMsgFromGS_NotifyBattleSeatPosInfo(const char* pMsg,int n32MsgLength,int n32MsgID);	//message 9
		INT32		OnMsgFromGS_NotifyBattleStateChange(const char* pMsg,int n32MsgLength,int n32MsgID);	//message 10
		INT32		OnMsgFromGS_NotifyCurBattleChange(const char* pMsg,int n32MsgLength,int n32MsgID);	//message 11
		INT32		OnMsgFromGS_NotifyGamgObjectAppear(const char* pMsg,int n32MsgLength,int n32MsgID);	//message 12
		INT32		OnMsgFromGS_NotifyGameObjectDisappear(const char* pMsg,int n32MsgLength,int n32MsgID);  //message 13
		INT32		OnMsgFromGS_NotifyGameObjectFreeState(const char* pMsg,int n32MsgLength,int n32MsgID);	//message 14
		INT32		OnMsgFromGS_NotifyGameObjectRunState(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsgFromGS_NotifyGameObjectPrepareSkillState(const char* pMsg,int n32MsgLength,int n32MsgID);	//message 18
		INT32		OnMsgFromGS_NotifyGameObjectReleaseSkillState(const char* pMsg,int n32MsgLength,int n32MsgID); //message 19
		INT32		OnMsgFromGS_NotifyGameObjectDeadState(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsgFromGS_NotifyBattleHeroInfo(const char* pMsg,int n32MsgLength,int n32MsgID);	//message 23	
		INT32		OnMsgFromGS_NotifyBattleTryHeroInfo(const char* pMsg,int n32MsgLength,int n32MsgID);	//message 23	
		INT32		OnMsgFromGS_NotifySelectTimeOut(const char* pMsg,int n32MsgLength,int n32MsgID); //message 32
		INT32		OnMsgFromGS_NotifyBroadBuildingDestroyByWho(const char* pMsg,int n32MsgLength,int n32MsgID); 
		INT32		OnMsgFromGS_NotifyCurCP(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsgFromGS_NotifySkillInfo(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsgFromGS_NotifyFightPropertyInfo(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsgFromGS_NotifyHPInfo(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsgFromGS_NotifyMPInfo(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsgFromGS_NotifyLevelInfo(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsgFromGS_NotifyFury(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsg_NotifyLeaveBattleSuccess();
		INT32		OnMsg_NotifyGoodsInfo(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsg_NotifyHeroInfo(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsg_NotifyPassitiveSkillLoad(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsg_NotifyPassitiveSkillUnLoad(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsg_NotifyHPChange(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsg_NotifyMPChange(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsg_NotifyPing(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsg_NotifyExp(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsg_NotifyHeroRebornTimes(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsg_NotifyCurDeadTimes(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsg_NotifySkillID(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32       OnMsg_NotifySdkLoginResult(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32       OnMsg_NotifyServerAddr(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32       OnMsg_OneClinetLoginCheckRet(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32       OnMsg_NotifyGateServerInfo(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32       OnMsg_NotifyAbsorbMonsterResult(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32       OnMsg_NotifyGoodsInfo(const char* pMsg,int n32MsgLength);
		INT32		OnMsg_NotifyRoomListRet(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsg_NotifyTeamBaseInfo(const char* pMsg,int n32MsgLength,int n32MsgID);
		INT32		OnMsg_NotifyTeamPlayerInfo(const char* pMsg,int n32MsgLength,int n32MsgID);
	};

}

