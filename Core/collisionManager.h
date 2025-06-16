//////////////////////////////////////////////////////////////
/////////////////////  충돌체크 클래스  //////////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"
#include "gameObject.h"

class collisionManager : public singleton<collisionManager>
{
public:
	collisionManager();
	~collisionManager();

	// 사각형 충돌
	bool rectCollisionCheck(gameObject *obj1, gameObject *obj2);

	// 원충돌
	bool circleCheck(float x1, float y1, float x2, float y2, float size);
};

