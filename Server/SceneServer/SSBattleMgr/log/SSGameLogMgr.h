#pragma once
#include "../../CommonCPlus/Include/FBAll_Const.h"
#include <map> 
#include <vector>
using std::map;

  namespace SceneServer{

class CSSGameLogMgr
{  
	struct SkillHurt
	{  
		INT32  heroid;   //Ӣ��id
		INT32  phyHurt; //�����˺�
		INT32  magHurt; //ħ���˺�
		INT32  realHurt; //ֱ���˺�  

		INT32  num;//ʹ�ô���	

		SkillHurt():heroid(0),phyHurt(0),magHurt(0),realHurt(0), num(0){}
		~SkillHurt(){}
	};
	std::map<INT64/*mapid*/,std::map<INT64/*battleid*/,std::map<INT64/*userid*/,std::map<INT32/*skillId*/,SkillHurt> > > >  mSkillHurt;

	INT64								mLastRefshTime; 
public:
	CSSGameLogMgr();
	~CSSGameLogMgr(); 

	static CSSGameLogMgr &GetInstance()	{static CSSGameLogMgr  oo; return oo;}  
 
	void							AddSkillHurt(  INT64 mapid ,INT64 bid,INT64 userid, INT32 heroId ,INT32 skillId, INT32 hurtValue, EEffectCate ec);

	void							RefreshLog(INT64 mapid ,INT64 bid, INT64 bstarttime,INT64  curt);

	  
	void							RefreshGameLog( INT64 mapid ,INT64 bid, INT64 bstarttime  );

	void							AddBattleLog(EGameLog eLog, INT32 bid,INT32 mapid, INT32 param);	
	 
	void							AddBattleLog(EGameLog eLog, INT32 bid,INT32 mapid, std::string & log ); 
private:
	void							PosBattleLogs(EGameLog eLog, std::string & logStr);
};

}