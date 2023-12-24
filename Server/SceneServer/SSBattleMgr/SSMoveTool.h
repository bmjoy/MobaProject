/*
* file name			:SSMoveTool.h
* file mark			:
* summary			:
*
* version			:1.0
* author			:LiuLu
* complete date		:August 4 2014
* summary			:
*
*/

#ifndef __SSMoveTool_h__
#define __SSMoveTool_h__

#include "stdafx.h"
#include "SSIntersectObject.h"

namespace SceneServer{


class CSSMoveTool
{
public:
	static FLOAT	Dot(float x1, float y1, float x2, float y2){return x1*x2 + y1*y2;}//������
	static FLOAT	Dot(ColVector v1, ColVector v2){return v1.x*v2.x + v1.y*v2.y;}//������
	static INT32	IntersectRaySphere(ColVector p, ColVector d, ColSphere s, float &time, ColVector &q);//����߶κ�Բ��ָ��ʱ�䷶Χ���Ƿ���ཻ
	static INT32	IntersectSphereSphere(ColSphere s1, ColVector v1, ColSphere s2, ColVector v2,float &time, ColVector &q);//�������Բ��ָ��ʱ�䷶Χ���Ƿ���ཻ

	static float	SqDistPointAABB(ColVector& p, ColAABB& b);//����Բ�ͳ���������ƽ��

	static bool	IfImpact(ColSphere& s1, ColSphere& s2);//�������Բ�Ƿ���ײ
	static bool	IfImpact(ColSphere& s, ColAABB& aabb);//���Բ�ͳ������Ƿ���ײ

	static bool	IfInTheSameBlock(float x1, float y1, float x2, float y2){return (INT32)x1/100 == (INT32)x2/100 && (INT32)y1/100 == (INT32)y2/100;}
};

}

#endif