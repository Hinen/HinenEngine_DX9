#include "scene.h"

scene::scene()
{
}


scene::~scene()
{
}

void scene::release()
{
	// 텍스쳐와 오브젝트를 모두 해제한다.
	textureManager::getInstance()->release();
	obj.release();
}