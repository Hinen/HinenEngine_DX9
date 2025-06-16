#include "system.h"
#include "graphicManager.h"
#include "sceneManager.h"

using namespace game;

system::system()
{
}


system::~system()
{
}

void system::init()
{
	// 그래픽 클래스를 초기화한다.
	graphicManager::getInstance()->init();

	// 그리고 씬을 변경한다.
	sceneManager::getInstance()->sceneChange(sceneManager::eGame);
}

void system::msgLoop()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			mainLoop();
		}
	}
}

void system::release()
{
	// 씬과 그래픽을 해제한다.
	// 씬 해제에는 텍스쳐, 오브젝트 해제도 포함되어있다.
	sceneManager::getInstance()->scene->release();
	graphicManager::getInstance()->release();
}

void system::mainLoop()
{
	// Render을 시작한다.
	graphicManager::getInstance()->update();
}