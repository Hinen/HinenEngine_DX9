#include "sGame.h"


sGame::sGame()
{
}


sGame::~sGame()
{
}

// �ʱ�ȭ �Լ�
void sGame::init()
{
	// ����� ���
	soundManager::getInstance()->playBg("Resource/bg.mp3");

	// ĳ���͸� �޸� �Ҵ����� �ؽ��ĸ� �ҷ�����, ũ��, ��ġ���� �ش�.
	_char = new oChar;
	_char->loadTexture("Resource/ĳ����.png");
	_char->setSize(200, 200);
	_char->setPos(100, 100);

	// ������Ʈ ���Ϳ� ĳ���͸� �ִ´�.
	obj.addObject(_char);
}

// ������Ʈ, �� �����Ӹ��� ȣ��ȴ�.
void sGame::update()
{
	render();

	// ĳ������ Key�޼��带 �ҷ��´�.
	_char->key();

	// �浹üũ�� �ϰ��ʹٸ� �浹üũ �޼������ ��ȯ���� bool ���̹Ƿ�
	// if�� �Ἥ �⵿üũ Ȯ���� �� �� �ִ�.
	// ������� 
	//
	//if (collisionManager::getInstance()->circleCheck(_char->getPos().x, _char->getPos().y, _enemy->getPos().x, _enemy->getPos().y, 200))
	//{
	//	//m_Enemy��� ������Ʈ�� �����ؼ� ĳ������ x, y��, ���� x, y���� �Ѱ��ְ� �浹üũ ����� �ְ�
	//	//�浹üũ �޼����� ��ȯ���� true �� �浹�� �Ȱ� �̱� ������ �浹�� �ȴٸ� �ؿ� ȿ������ ��µɰ��̴�.
	//
	//	//ȿ���� ���
	//	soundManager::getInstance()->playEf("Resource/ex.wav");
	//}
}

// �׸���
void sGame::render()
{
	// ĳ���� �׸���
	graphicManager::getInstance()->render(_char);
}