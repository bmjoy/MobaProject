/*
* file name			:SSIntersectObject.h
* file mark			:
* summary			:
*
* version			:1.0
* author			:LiuLu
* complete date		:August 4 2014
* summary			:
*
*/

#ifndef __SSIntersectObject_h__
#define __SSIntersectObject_h__

#include "stdafx.h"

namespace SceneServer{
//Ѱ·ϵͳ�õ���󣬿��Ա��ֵ�ͷ���
struct ColVector{
	FLOAT x;
	FLOAT y;

	ColVector():x(0.0f), y(0.0f){}
	ColVector(FLOAT x, FLOAT y):x(x), y(y){}

	ColVector operator + (const ColVector& v){
		return ColVector(x + v.x, y + v.y);
	}
	
	ColVector operator - (const ColVector& v){
		return ColVector(x - v.x, y - v.y);
	}

	friend ColVector operator * (FLOAT a, const ColVector& p1){
		return ColVector(a * p1.x , a * p1.y);
	}
	friend ColVector operator * ( const ColVector& p1, FLOAT a){
		return ColVector(p1.x * a, p1.y * a);
	}
	friend ColVector operator / ( const ColVector& p1, FLOAT a){
		if (a == 0.0f){
			return ColVector();
		}
		return ColVector(p1.x / a, p1.y / a);
	}
	ColVector operator / (FLOAT a){
		if (a == 0.0f){
			return ColVector();
		}
		return ColVector(this->x / a, this->y / a); 
	}
	ColVector antiscale(ColVector *pV, FLOAT a){
		if (a == 0.0f){
			return ColVector();
		}
		return ColVector(pV->x / a, pV->y / a);
	}
	bool operator == (const ColVector& v)  { return this->x == v.x && this->y == v.y; }
	bool operator != (const ColVector& v)  { return this->x != v.x || this->y != v.y; }

	ColVector Unit(){
		return antiscale(this, Length());
	}

	FLOAT Length(){
		return sqrt(LengthSqrt());
	}

	FLOAT LengthSqrt(){
		return (double)x*x + (double)y*y;
	}

};
//Ѱ·ϵͳ��Բ�����õ�Ͱ뾶��ʾһ��Բ
struct ColSphere{
	ColVector c;
	FLOAT r;
	ColSphere():r(0.0f){

	}
	ColSphere(ColVector& c, FLOAT r):c(c), r(r){

	}
};

//Ѱ·ϵͳ�ó����ζ��������ϽǺ����½��������ʾƽ����X��Y��ĳ����Ρ�
struct ColAABB{
	ColVector min;
	ColVector max;
};
}

#endif