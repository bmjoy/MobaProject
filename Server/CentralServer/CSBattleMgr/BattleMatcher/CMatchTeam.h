#pragma once

#include "Include/FBAll_Const.h"

class IMatchPlayer;

enum EBattleMatchType
{
	eMatchType_None,
	eMatchType_VsAI,//�˻���ս(������ҵз�������)//
	eMatchType_Nomal,//��ͨ��ս//
	eMatchType_Tianti,//���ݶ�ս// 
	eMatchType_Total, 
};

class CCSMatchTeam
{
public:
	CCSMatchTeam(EBattleMatchType matchType, UINT32 mapId);
	virtual ~CCSMatchTeam();
public:
	IMatchPlayer* GetLeader() { return mVPlayer.size()>0?mVPlayer[0]:NULL; }
	UINT32 GetPlayerCount() { return mVPlayer.size(); }
	bool AddOneUser(IMatchPlayer* pPlayer);
	bool RemoveOneUser(IMatchPlayer* pPlayer);
	bool Dissolve(IMatchPlayer* pPlayer);
	void Switch(bool isMatch);
	void Stop(IMatchPlayer* pPlayer);
	bool PushDataOnlinePlayer(IMatchPlayer* pPlayer);
	bool IsCanMatch() { return mInMatch==false && mStopedPlayer.size()==0; }
public:
	SMapLogicCfg* m_pMapLogicCfg;
	vector<IMatchPlayer*> mVPlayer;
	EBattleMatchType mMatchType;
	UINT32 mMapId;
	UINT32 mTeamId;
	bool mInMatch;
	map<UINT64,bool> mStopedPlayer;

	//use for log
	INT64   mStartTime;
};
