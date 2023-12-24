/*
* file name			:SSGUParameter.h
* file mark			:
* summary			:
*
* version			:1.0
* author			:LiuLu
* complete date		:Nov 26 2014
* summary			:
*
*/

#pragma once

#include "stdafx.h"
#include "ISSParameterChangeCallBack.h"

namespace SceneServer{

	static const float c_fPersentDevide = 1000.0f;

	enum EGUParameterType{
		eParaType_Normal = 0,//ͨ�����ֱ�������
		eParaType_Status,//����ֻ������������޵�����
	};

	class CSSGUParameter
	{
	private:

		EGUParameterType	m_type;//��������
		bool		m_bIfOnlyOneMinusePercent;//�Ƿ���ٵı���ֻ�������ֵ
		INT32		m_value;//���յ�����ֵ
		INT32		m_baseValue;//����ֵ
		INT32		m_percent;//ǧ�ֱȸı���
		INT32		m_percentAdd;//ǧ�ֱ�������
		vector<INT32>		m_percentMinuseVec;//ǧ�ֱȼ������б�
		bool		m_bIfChanged;//ֵ�Ƿ񱻸ı��
		INT32		m_minValue;//��ֵ����Сֵ
		INT32		m_maxValue;//��ֵ�����ֵ
		bool		m_hasMinValue;//�Ƿ�����ֵ����Сֵ
		bool		m_hasMaxValue;//�Ƿ�����ֵ�����ֵ
		INT32		m_minBaseValue;//����ֵ����Сֵ
		INT32		m_maxBaseValue;//����ֵ�����ֵ
		bool		m_hasMinBaseValue;//�Ƿ��л���ֵ����Сֵ
		bool		m_hasMaxBaseValue;//�Ƿ��л���ֵ�����ֵ
		bool		m_bIfCountDown;//�Ƿ��յ�������

		CSSGUParameter*	m_pMaxValueCallBack;//���ֵ�ı�Ļص��ӿ�

		ISSParameterChangeCallBack* m_pValueCallback;//��ǰֵ�ı�Ļص��ӿ�

		map<INT32, INT8> m_uniqueMap;

		VOID		ChangeBaseValue(INT32 value);
		VOID		Recount();
		VOID		RecountSingleCaculatePercent();

	protected:
		

	public:
		~CSSGUParameter();
		CSSGUParameter();

		VOID		SetType(EGUParameterType type){m_type = type;}
		VOID		SetIfOnlyOneMinusePercent(bool value){m_bIfOnlyOneMinusePercent = value;}
		VOID		SetCountDown(bool value){m_bIfCountDown = value;}
		VOID		SetMinValue(INT32 value){m_hasMinValue = TRUE; m_minValue = value; if(m_value < m_minValue) m_value = m_minValue;}
		VOID		SetMaxValue(INT32 value){m_hasMaxValue = TRUE; m_maxValue = value; if(m_value > m_maxValue) m_value = m_maxValue;}
		VOID		SetMinBaseValue(INT32 value){m_hasMinBaseValue = TRUE; m_minBaseValue = value; if(m_baseValue < m_minBaseValue) m_baseValue = m_minBaseValue;}
		VOID		SetMaxBaseValue(INT32 value){m_hasMaxBaseValue = TRUE; m_maxBaseValue = value; if(m_baseValue > m_maxBaseValue) m_baseValue = m_maxBaseValue;}
		VOID		SetMaxValueChangeCallback(CSSGUParameter* callback){m_pMaxValueCallBack = callback;}
		bool		IfChanged(){return m_bIfChanged;}
		VOID		OnSend(){m_bIfChanged = FALSE;}
		VOID		AddBase(INT32 value,INT32 uniqueID = 0);
		VOID		RemoveBase(INT32 value,INT32 uniqueID = 0);
		VOID		AddPercent(INT32 value,INT32 uniqueID = 0);
		VOID		RemovePercent(INT32 value,INT32 uniqueID = 0);
		INT32		GetValue(){return m_value;}
		INT32		GetValueForSend(){m_bIfChanged = FALSE; return GetValue();}
		VOID		OnMaxValueChanged(INT32 oldValue,INT32 newValue);
		VOID		SetValueChangeCallback(ISSParameterChangeCallBack* pCallBack){m_pValueCallback = pCallBack;}
	};

}