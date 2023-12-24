// SSBattleMgr.cpp : ���� DLL Ӧ�ó���ĵ���������

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "SSBattle.h"
#include "SSBattleMgr.h"
#include "SSNPC.h"
#include "SSHero.h"
#include "SSWorkThreadMgr.h"
#include "SSUser.h"

using namespace std;

namespace SceneServer{

INT32 CSSBattleMgr::PostMsgToCS_SyncAllBattleInfo()
{
	SSToCS::SyncAllBattleInfo msg;
	UINT64 maxbattleId = 0;
	map<UINT64, CSSBattle*>::iterator it = m_cAllBattleMap.begin();
	for (;it!=m_cAllBattleMap.end();++it)
	{
		CSSBattle* pBattle = it->second;
		if (pBattle->GetBattleID()>maxbattleId)
		{
			maxbattleId = pBattle->GetBattleID();
		}
		if (pBattle->GetBattleState()==eSSBS_Playing)
		{
			msg.add_playbattle(pBattle->GetBattleID());// ���͸�battle����Ϣ��cs//
		}
	}
	msg.set_maxbattleid(maxbattleId);
	return CSSWorkThreadMgr::GetInstance().PostMsgToCS(msg, msg.mgsid());
}
}