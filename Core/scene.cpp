#include "scene.h"

scene::scene()
{
}


scene::~scene()
{
}

void scene::release()
{
	// �ؽ��Ŀ� ������Ʈ�� ��� �����Ѵ�.
	textureManager::getInstance()->release();
	obj.release();
}