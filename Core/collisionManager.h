//////////////////////////////////////////////////////////////
/////////////////////  �浹üũ Ŭ����  //////////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"
#include "gameObject.h"

class collisionManager : public singleton<collisionManager>
{
public:
	collisionManager();
	~collisionManager();

	// �簢�� �浹
	bool rectCollisionCheck(gameObject *obj1, gameObject *obj2);

	// ���浹
	bool circleCheck(float x1, float y1, float x2, float y2, float size);
};

