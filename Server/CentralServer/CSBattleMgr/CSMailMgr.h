#ifndef  CSMAILMGR_H_
#define CSMAILMGR_H_
#include "stdafx.h"
#include "Include/FBAll_Const.h"
#include <hash_map> 
#include <map>
#include<vector>
#include <string> 

using namespace std;
namespace CentralServer 
{ 
	class CCSUser;
	class CCSMailMgr
	{  
		INT32																				m_curtMaxMailIdx;

		//ȫ���ʼ�(����ʱ������,Ҳ����˵mailId �Ӵ�-->С)
		std::map<INT32, MailDBData>															m_mapGameMail;

		//��ʱ��ʱ���ʼ�,�ʼ�id,�Ƿ��ʼ�����
		std::map<INT64, std::map<INT32,bool> >												m_IfHasSendMail;
		//�����ʼ�
		std::map<INT64/*objIdx*/, std::map<INT32,tagMailState> >							m_mapPersonalMail;  

		INT64																				m_LastRefMailTime;
	public:
		CCSMailMgr(); 
		~CCSMailMgr(); 

		bool	CheckRefreshMail();

		void	setCurtMaxMailIdx(INT32 idx)													{m_curtMaxMailIdx  += idx;}
		INT32	getCurtMailIdx()																{m_curtMaxMailIdx++;   return m_curtMaxMailIdx;}


		bool	addGameMail(   const MailDBData  & mail); 
		std::map<INT32,tagMailState>*	GetUserMailState(UINT64 guid);

		std::map<INT32, MailDBData>		&			getCurtGameMail()								{return						m_mapGameMail;}

		//�ͻ��˲����ʼ�
		bool	closeOrGetMailGift(CCSUser *pUser, INT32 mailId );   

		INT32	getMailInfoById(INT64 objIdx,INT32 mailId,   GSToGC::MailInfo & mailInfo,INT32 &nstate); 


		bool	getPerMailListStr(const SUserDBData & userDb, GSToGC::NotifyMailList&  mailList);

		void	updatePerMailList( INT32 mailId, INT64  objIdx ,EMailCurtState eState);  

		void    changeMailState(INT64 objId,INT32 mailId,std::string &str, INT32 curtState); 


		void	RemoveObjId(INT64 objIdx);
		//save
		bool	UpdateGameMail(CSToDB::UpdateGameMail &msg); 

		void	addHasSendMailId(INT64 objIdx, INT32 mailId);

		bool	checkIfMailHasSend(INT64 objIdx, INT32 mailId); 

		void   addPersonalMail(INT64 objIdx, vector<UserMailDBData> &pmail	);
		//�Ƿ���ȡ
		bool   checkIfMailHasRecv(INT64 objIdx, INT32 mailId);
		//�Ƿ��ʼ�����
		bool  checkIfMailHasTimeOver(INT32 mailId);
		//�ʼ���Ϣ
		void  getShortMailMasg(INT64 objId, INT32 mailid,INT32 mailtype, std::string& mailtitle, INT32 mailState, GSToGC::NotifyMailList&  mailList);
	private:
		void	addPersonalMail( const MailDBData  & mail);    

	};
}

#endif