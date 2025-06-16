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
	// �׷��� Ŭ������ �ʱ�ȭ�Ѵ�.
	graphicManager::getInstance()->init();

	// �׸��� ���� �����Ѵ�.
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
	// ���� �׷����� �����Ѵ�.
	// �� �������� �ؽ���, ������Ʈ ������ ���ԵǾ��ִ�.
	sceneManager::getInstance()->scene->release();
	graphicManager::getInstance()->release();
}

void system::mainLoop()
{
	// Render�� �����Ѵ�.
	graphicManager::getInstance()->update();
}