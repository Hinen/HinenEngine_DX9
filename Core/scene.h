//////////////////////////////////////////////////////////////
////////////////////////  씬 클래스  /////////////////////////
//////////////////////////////////////////////////////////////


#pragma once
// 씬에서 사용할 다양한 헤더파일
#include "stdafx.h"
#include "graphicManager.h"
#include "collisionManager.h"
#include "objectManager.h"
#include "soundManager.h"
#include "textureManager.h"

class scene
{
public:
	scene();
	~scene();

	// 순수 가상함수와 가상함수로 다양성을 활용
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void release();

	// 오브젝트 매니저를 선언한다.
	objectManager obj;
};

