// SSBattleMgr.cpp : ���� DLL Ӧ�ó���ĵ���������

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "SSBattle.h"
#include "SSBattleMgr.h"
#include "SSCfgMgr.h"
#include "SSWorkThreadMgr.h"
#include "SSUser.h"
#include "SSGuideBattle.h"

using namespace std;

namespace SceneServer{

INT32	CSSBattleMgr::OnMsgFromCS(const char* pData, int n32DataLength, int n32MsgID){
	CSMsgHandlerMap::iterator iter = m_asCSMsgHandler.find(n32MsgID);
	if (m_asCSMsgHandler.end() != iter){
		return (this->*iter->second)(pData, n32DataLength);
	}
	ELOG(LOG_WARNNING, "ProtocalID %d, msg size %d, have not msg handler.", n32MsgID, n32DataLength);
	return eEC_NullMsgHandler;
}

INT32	CSSBattleMgr::OnMsgFromCS_CreateBattle(const char* pData, int n32DataLength){
	BOOLEAN ifCreateSucc = FALSE;
	CSSBattle* pBattle = NULL;
	boost::shared_ptr<CSToSS::CreateBattle> pCreateBattle = ParseProtoMsgWithNewMemory<CSToSS::CreateBattle>(pData, n32DataLength);
	vector<CSSUser*> userVec;

	//�����Ϣ��Ч��
	if (!pCreateBattle) 
	{
		return eEC_NullPointer;
	}
	//�Ƿ���ڵ�battleId
	if( NULL != GetBattle(pCreateBattle->battleid()))
	{
		ELOG(LOG_WARNNING, "un64BattleID = %llu, un32MapID = %d  hase exist!  ", pCreateBattle->battleid(), pCreateBattle->mapid());
		return eEc_existBattle;
	}

	do{ 
		//����ս��
		if (pCreateBattle->battletype() == eBattleType_Guide1)
		{
			pBattle = new CSSGuideBattle( pCreateBattle->battleid(),(EBattleType)pCreateBattle->battletype(),this); 
		}
		else
		{
			pBattle = new CSSBattle(this,(EBattleType)pCreateBattle->battletype(),pCreateBattle->battleid());
		}
		if (NULL == pBattle){
			Assert(false && "Create a free battle fail!");
			break;
		}
		//��ȡ��ͼ��Ϣ
		if (eNormal != pBattle->LoadMapData(pCreateBattle->mapid())){
			Assert(false && "LoadMapData!");
			break;
		}
		//����ÿһ���˵���Ϣ
		BOOLEAN bInsertSucc = TRUE;
		for(UINT32 i = 0; i < pCreateBattle->userinfo_size(); i++){
			const CSToSS::CreateBattle_CreateBattleUserInfo* pUserInfo = &pCreateBattle->userinfo(i);
			SBattleUserInfo* pBattleUserInfo = pBattle->InsertUser();
			if(NULL == pBattleUserInfo){
				bInsertSucc = FALSE;
				Assert(false && "InsertUser!");
				break;
			}
			//�����AI���������AI��Ϣ
			if (pUserInfo->ifairobot()){
				pBattleUserInfo->ifAI = TRUE;
			}
			//�������AI���򴴽�User��Ϣ
			else{
				//����CSSUser
				SUserNetInfo pSUserNetInfo(pUserInfo->usernetinfo().n32gsid(),pUserInfo->usernetinfo().n32gcnsid());
				CSSUser *pcUser = GetCUserByNetInfo(pSUserNetInfo);
				if (NULL == pcUser){
					pcUser = AddUser(&pSUserNetInfo, pUserInfo->guid());
				}
				if (NULL == pcUser){
					bInsertSucc = FALSE;
					Assert(false && "AddUser!");
					break;
				}
				userVec.push_back(pcUser);

				pcUser->SetConnectState(TRUE);
				pcUser->SetNickName(pUserInfo->nickname());
				pcUser->SetDiamond(pUserInfo->diamond());
				pcUser->SetGold(pUserInfo->gold());
				pcUser->SetVipLevel(pUserInfo->viplv());
				for(int j=0;j<pUserInfo->canuseherolist_size();j++){
					pcUser->AddCanUseHeroID(pUserInfo->canuseherolist(j));
				}
				// ����û�� ��Щ
				//Assert(pcUser->GetCanUseHeroList()->size()>0);

				//������Ϣ
				vector<SRunePageParameter>* pRunePageVec = pcUser->GetRunePageVec();
				for (UINT32 iRunePage=0;iRunePage<pUserInfo->runepages_size();++iRunePage){
					SRunePageParameter page;
					const ::CSToSS::CreateBattle_CreateBattleUserInfo_RunePage* pRunePage = &pUserInfo->runepages(iRunePage);
					for (UINT32 iRuneEffect=0;iRuneEffect<pRunePage->runeeffects_size();++iRuneEffect){
						const ::CSToSS::CreateBattle_CreateBattleUserInfo_RunePage_RuneInfo* pRuneInfo = &pRunePage->runeeffects(iRuneEffect);
						INT32 effectId = pRuneInfo->effectid();
						float effectValue = pRuneInfo->effectvalue() + 0.5f;
						float effectPer = pRuneInfo->effectper() + 0.5f;

						switch(effectId){
						case eEffectCate_PhyAttack:
							if(effectValue != 0) page.fpBase.n32PhyAttPower += effectValue;
							if(effectPer != 0)   page.fpPercent.n32PhyAttPower += effectPer;
							break;
						case eEffectCate_MagicAttack:
							if(effectValue != 0) page.fpBase.n32MagicAttPower += effectValue;
							if(effectPer != 0)   page.fpPercent.n32MagicAttPower += effectPer;
							break;
						case eEffectCate_PhyDefense:
							if(effectValue != 0) page.fpBase.n32PhyDefAbility += effectValue;
							if(effectPer != 0)   page.fpPercent.n32PhyDefAbility += effectPer;
							break;
						case eEffectCate_MagicDefense:
							if(effectValue != 0) page.fpBase.n32MagicDefAbility += effectValue;
							if(effectPer != 0)   page.fpPercent.n32MagicDefAbility += effectPer;
							break;
						case eEffectCate_MoveSpeed:
							if(effectValue != 0) page.fpBase.n32MoveSpeed += effectValue;
							if(effectPer != 0)   page.fpPercent.n32MoveSpeed += effectPer;
							break;
						case eEffectCate_AttackSpeed:
							if(effectValue != 0) page.fpBase.n32AttackSpeed += effectValue;
							if(effectPer != 0)   page.fpPercent.n32AttackSpeed += effectPer;
							break;
						case eEffectCate_MaxHP:
							if(effectValue != 0) page.fpBase.n32MaxHP += effectValue;
							if(effectPer != 0)   page.fpPercent.n32MaxHP += effectPer;
							break;
						case eEffectCate_MaxMP:
							if(effectValue != 0) page.fpBase.n32MaxMP += effectValue;
							if(effectPer != 0)   page.fpPercent.n32MaxMP += effectPer;
							break;
						case eEffectCate_HPRecoverRate:
							if(effectValue != 0) page.fpBase.n32HPRecover += effectValue;
							if(effectPer != 0)   page.fpPercent.n32HPRecover += effectPer;
							break;
						case eEffectCate_MPRecoverRate:
							if(effectValue != 0) page.fpBase.n32MPRecover += effectValue;
							if(effectPer != 0)   page.fpPercent.n32MPRecover += effectPer;
							break;
						case eEffectCate_ReliveTime:
							if(effectValue != 0) page.fpBase.n32ReliveSecond += effectValue;
							if(effectPer != 0)   page.fpPercent.n32ReliveSecond += effectPer;
							break;
						case eEffectCate_CriPersent:
							if(effectValue != 0) page.fpBase.n32CriPersent += effectValue;
							if(effectPer != 0)   page.fpPercent.n32CriPersent += effectPer;
							break;
						case eEffectCate_CriHarm:
							if(effectValue != 0) page.fpBase.n32CriHarm += effectValue;
							if(effectPer != 0)   page.fpPercent.n32CriHarm += effectPer;
							break;
						case eEffectCate_CPRecover:
							if(effectValue != 0) page.fpBase.n32CPRecover += effectValue;
							if(effectPer != 0)   page.fpPercent.n32CPRecover += effectPer;
							break;
						case eEffectCAte_AttackDist:
							if(effectValue != 0) page.fpBase.n32AttackDist += effectValue;
							if(effectPer != 0)   page.fpPercent.n32AttackDist += effectPer;
							break;
						default:
							break;
						}
					}
					pRunePageVec->push_back(page);
				}
				//���Ķ�ȡ����

				pcUser->SetBattleID(pBattle->GetBattleID());
				pBattleUserInfo->piUser = pcUser;
			}
			//���е���Ϣ
			pBattleUserInfo->stNickName = pUserInfo->nickname();
			pBattleUserInfo->un16GrpID = pUserInfo->grpid();
			pBattleUserInfo->bIfOB = pUserInfo->ifob();
			pBattleUserInfo->bIfGM = pUserInfo->ifgm();
			pBattleUserInfo->un16Pos = pUserInfo->seat();
			pBattleUserInfo->un64Guid = pUserInfo->guid();
		}
		if(FALSE == bInsertSucc) break; 

		pBattle->InitBattleParamCfg(); 

		//���뵽ս����������
		m_cAllBattleMap[pBattle->GetBattleID()] = pBattle;
		//�����ɹ�
		ifCreateSucc = TRUE;
	}
	while(FALSE);

	//�������ʧ�ܣ�ɾ��ս��
	if(FALSE == ifCreateSucc && pBattle != NULL){
		delete pBattle;
		pBattle = NULL;
	} 
	//���ʹ��������CS������
	SSToCS::CreateBattleResponse sMsg;
	sMsg.set_battleid(pCreateBattle->battleid());
	sMsg.set_rst(ifCreateSucc);
	CSSWorkThreadMgr::GetInstance().PostMsgToCS(sMsg, sMsg.mgsid());
	//���Ϳ��Խ���ս������Ϣ���ͻ���
	GSToGC::BattleBaseInfo sMsgBattle;
	sMsgBattle.set_battleid(pCreateBattle->battleid());
	sMsgBattle.set_mapid(pCreateBattle->mapid());
	sMsgBattle.set_ifreconnect(false);
	for(auto iter = userVec.begin(); iter!=userVec.end();iter++){
		ELOG(LOG_SpecialDebug,"�������(%s)����ս��(%d)",(*iter)->GetNickName(),pCreateBattle->battleid());
		CSSWorkThreadMgr::GetInstance().PostMsgToGCLIULU((*iter)->GetUserNetInfo(), sMsgBattle, sMsgBattle.msgid());
	}
	if(NULL != pBattle)
		pBattle->OnBattleStateChange();

	return eNormal;
}

INT32 CSSBattleMgr::OnMsgFromCS_UserOnline(const char* pData, int n32DataLength)
{
	boost::shared_ptr<CSToSS::NotifyUserOnline> pMsgUserOnline = ParseProtoMsgWithNewMemory<CSToSS::NotifyUserOnline>(pData, n32DataLength);
	Assert(pMsgUserOnline);
	CSSUser* pUser = GetCUserByGUID(pMsgUserOnline->userguid());
	if (pUser==NULL) return eNormal;
	CSSBattle* pBattle = GetBattle(pMsgUserOnline->battleid());
	if (pBattle==NULL) return eNormal;
	INT32 pos = pBattle->GetUserSeatPos(pUser);
	if (pos==0) return eNormal;
	SUserNetInfo usernet(pMsgUserOnline->usernetinfo().n32gsid(),pMsgUserOnline->usernetinfo().n32gcnsid());
	pBattle->OnUserOnline(pos-1,usernet);
	return eNormal;
}

INT32 CSSBattleMgr::OnMsgFromCS_UserOffline(const char* pData, int n32DataLength)
{
	boost::shared_ptr<CSToSS::NotifyUserOffline> pMsgUserOffline = ParseProtoMsgWithNewMemory<CSToSS::NotifyUserOffline>(pData, n32DataLength);
	Assert(pMsgUserOffline);
	CSSUser* pUser = GetCUserByGUID(pMsgUserOffline->userguid());
	if (pUser==NULL) return eNormal;
	CSSBattle* pBattle = GetBattle(pMsgUserOffline->battleid());
	if (pBattle==NULL) return eNormal;
	INT32 pos = pBattle->GetUserSeatPos(pUser);
	if (pos==0) return eNormal;
	pBattle->OnUserOffline(pos-1);
	pBattle->OnBattleFinish();
	return eNormal;
}


 
}