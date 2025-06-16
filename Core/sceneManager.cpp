#include "sceneManager.h"
#include "sGame.h"

sceneManager::sceneManager()
{
	// 씬을 처음에 초기화
	scene = NULL;
}


sceneManager::~sceneManager()
{
}

void sceneManager::sceneChange(int whatScene)
{
	// 만약 이전에 씬이 있다면
	if (scene)
	{
		// 씬을 해제하고 삭제한다.
		scene->release();
		delete scene;
	}

	// swtih 문으로 내가 변경할 씬을 찾는다.
	switch (whatScene)
	{
	// 해당 씬을 new로 메모리 할당을 한다.
	case eGame:
		scene = new sGame;
		break;
	}

	// 만약 새로 만든 씬이 있다면
	if (scene)
	{
		// 그 씬을 init한다. 
		scene->init();
	}
}