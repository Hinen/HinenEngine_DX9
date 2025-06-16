#include "sceneManager.h"
#include "sGame.h"

sceneManager::sceneManager()
{
	// ���� ó���� �ʱ�ȭ
	scene = NULL;
}


sceneManager::~sceneManager()
{
}

void sceneManager::sceneChange(int whatScene)
{
	// ���� ������ ���� �ִٸ�
	if (scene)
	{
		// ���� �����ϰ� �����Ѵ�.
		scene->release();
		delete scene;
	}

	// swtih ������ ���� ������ ���� ã�´�.
	switch (whatScene)
	{
	// �ش� ���� new�� �޸� �Ҵ��� �Ѵ�.
	case eGame:
		scene = new sGame;
		break;
	}

	// ���� ���� ���� ���� �ִٸ�
	if (scene)
	{
		// �� ���� init�Ѵ�. 
		scene->init();
	}
}