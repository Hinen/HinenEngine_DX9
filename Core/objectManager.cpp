#include "objectManager.h"


objectManager::objectManager()
{
}


objectManager::~objectManager()
{
}

void objectManager::addObject(gameObject *obj)
{
	// 오브젝트 벡터에 게임 오브젝트를 넣는다.
	_objectVector.push_back(obj);
}

void objectManager::addUi(gameObject *ui)
{
	// Ui 벡터에 게임 오브젝트를 넣는다.
	_uiVector.push_back(ui);
}

void objectManager::release()
{
	// 오브젝트 벡터와 Ui 벡터를 크기만큼 for문을 돌려서 삭제후
	for (int i = 0; i < _objectVector.size(); i++)
	{
		delete _objectVector[i];
	}
	for (int i = 0; i < _uiVector.size(); i++)
	{
		delete _uiVector[i];
	}

	// 벡터들을 비운다.
	_objectVector.clear();
	_uiVector.clear();
}

void objectManager::cameraMove(int x, int y)
{
	// 오브젝트의 크기만큼 for문을 돌린후
	for (int i = 0; i < _objectVector.size(); i++)
	{
		// 오브젝트 벡터 즉, Ui가 아닌 오브젝트들을 전부 이동시킨다.
		// 그럼 Ui는 가만히 있고 다른 오브젝트들은 전부 인자값 x, y만큼 움직인다.
		_objectVector[i]->setPos(_objectVector[i]->getPos().x - x, _objectVector[i]->getPos().y - x);
	}
}