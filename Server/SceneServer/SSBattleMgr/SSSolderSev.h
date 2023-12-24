#ifndef SSSOLDER_H_
#define SSSOLDER_H_

namespace SceneServer{
	class SSSolderSev
	{
		INT64											m_tNPCNextBornCDMilsec;			//����ʱ��:�ӳ�ʱ��  ��������ʱ���ӳ�
		//bool											m_ifAltarBrokern;				//��̳�Ƿ񱻴� ���ڳ�������

		std::map<INT32/*pathId*/, SMapCurtBornSolderInfo >		m_curtSolderBornInfo;
	public:
		SSSolderSev();
		~SSSolderSev();  

		std::map<INT32/*pathId*/, SMapCurtBornSolderInfo >&  GetMapCurtBornSolderInfo(){return		m_curtSolderBornInfo;}

		bool							CheckBornSolder(INT64  curttime);	 

		void							SetNPCNextBornCDMisec(INT64 tcfg);  

		void							SetAltarBrokenAboutSuperSolder(INT32 pathId, INT32 altarIdx, std::vector<INT32>& altarCfg);

	private: 
		bool								Comp2Vector(std::vector<INT32> & v1, std::vector<INT32> & v2);
	};
}
#endif