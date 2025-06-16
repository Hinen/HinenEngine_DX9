//////////////////////////////////////////////////////////////
//////////////////  ���� �����ϴ� Ŭ����  ////////////////////
//////////////////////////////////////////////////////////////


#pragma once
#include "stdafx.h"
#include "scene.h"

class sceneManager : public singleton<sceneManager>
{
public:
	// ���� ������ enum���� ����
	enum sceneType
	{
		eGame,
	};

public:
	sceneManager();
	~sceneManager();

public:
	// ���� �����Ѵ�.
	scene *scene;

	// ���� �����ϴ� �޼���
	void sceneChange(int whatScene);
};

