/*
* file name			:SSMoveObjectHolder.h
* file mark			:
* summary			:
*
* version			:1.0
* author			:LiuLu
* complete date		:Auguest 8 2014
* summary			:
*
*/

#ifndef __ISSMoveObjectHolder_h__
#define __ISSMoveObjectHolder_h__

#include "stdafx.h"

namespace SceneServer{


class ISSMoveObjectHolder
{
public:
	virtual ~ISSMoveObjectHolder(){}

	//�����¼�֪ͨ�ĳ���ӿ�
	virtual void				OnStopMove() = 0;
};

}

#endif