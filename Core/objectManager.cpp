#include "objectManager.h"


objectManager::objectManager()
{
}


objectManager::~objectManager()
{
}

void objectManager::addObject(gameObject *obj)
{
	// ������Ʈ ���Ϳ� ���� ������Ʈ�� �ִ´�.
	_objectVector.push_back(obj);
}

void objectManager::addUi(gameObject *ui)
{
	// Ui ���Ϳ� ���� ������Ʈ�� �ִ´�.
	_uiVector.push_back(ui);
}

void objectManager::release()
{
	// ������Ʈ ���Ϳ� Ui ���͸� ũ�⸸ŭ for���� ������ ������
	for (int i = 0; i < _objectVector.size(); i++)
	{
		delete _objectVector[i];
	}
	for (int i = 0; i < _uiVector.size(); i++)
	{
		delete _uiVector[i];
	}

	// ���͵��� ����.
	_objectVector.clear();
	_uiVector.clear();
}

void objectManager::cameraMove(int x, int y)
{
	// ������Ʈ�� ũ�⸸ŭ for���� ������
	for (int i = 0; i < _objectVector.size(); i++)
	{
		// ������Ʈ ���� ��, Ui�� �ƴ� ������Ʈ���� ���� �̵���Ų��.
		// �׷� Ui�� ������ �ְ� �ٸ� ������Ʈ���� ���� ���ڰ� x, y��ŭ �����δ�.
		_objectVector[i]->setPos(_objectVector[i]->getPos().x - x, _objectVector[i]->getPos().y - x);
	}
}