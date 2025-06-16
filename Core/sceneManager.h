//////////////////////////////////////////////////////////////
//////////////////  씬을 관리하는 클래스  ////////////////////
//////////////////////////////////////////////////////////////


#pragma once
#include "stdafx.h"
#include "scene.h"

class sceneManager : public singleton<sceneManager>
{
public:
	// 씬의 종류를 enum으로 선언
	enum sceneType
	{
		eGame,
	};

public:
	sceneManager();
	~sceneManager();

public:
	// 씬을 선언한다.
	scene *scene;

	// 씬을 변경하는 메서드
	void sceneChange(int whatScene);
};

