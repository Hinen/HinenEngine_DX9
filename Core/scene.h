//////////////////////////////////////////////////////////////
////////////////////////  �� Ŭ����  /////////////////////////
//////////////////////////////////////////////////////////////


#pragma once
// ������ ����� �پ��� �������
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

	// ���� �����Լ��� �����Լ��� �پ缺�� Ȱ��
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void release();

	// ������Ʈ �Ŵ����� �����Ѵ�.
	objectManager obj;
};

