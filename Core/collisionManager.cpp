#include "collisionManager.h"


collisionManager::collisionManager()
{
}


collisionManager::~collisionManager()
{
}

bool collisionManager::rectCollisionCheck(gameObject *obj1, gameObject *obj2)
{
	// üũ�� �簢�� 2�� ����
	RECT rect1;
	RECT rect2;

	// �簢���� ����, ������, ��, �Ʒ��� ���� �������ش�.
	rect1.left = obj1->getPos().x - obj1->getSize().x / 2;
	rect1.right = obj1->getPos().x + obj1->getSize().x / 2;
	rect1.top = obj1->getPos().y - obj1->getSize().y / 2;
	rect1.bottom = obj1->getPos().y + obj1->getSize().y / 2;

	rect2.left = obj2->getPos().x - obj2->getSize().x / 2;
	rect2.right = obj2->getPos().x + obj2->getSize().x / 2;
	rect2.top = obj2->getPos().y - obj2->getSize().y / 2;
	rect2.bottom = obj2->getPos().y + obj2->getSize().y / 2;

	// �׸��� üũ����
	if (rect1.left < rect2.right &&
		rect1.top < rect2.bottom &&
		rect1.right > rect2.left &&
		rect1.bottom > rect2.top)
	{
		// �浹 �Ͻ� true�� ����
		return true;
	}

	// �浹�� �ƴҽ� false ����
	return false;
}


bool collisionManager::circleCheck(float x1, float y1, float x2, float y2, float size)
{
	// ���� �������� �Ÿ�, ���� �������� �̿��Ѵ�.

	if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= size * size)
	{
		// �浹 �Ͻ� true�� ����
		return true;
	}

	// �浹�� �ƴҽ� false ����
	return false;
}