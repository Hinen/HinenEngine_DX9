#include "gameObject.h"
#include "textureManager.h"

gameObject::gameObject()
{
	// ������ 0��, 0������, visible�� true�� ����
	degree = 0;
	_nowFrame = 0;
	visible = true;
}


gameObject::~gameObject()
{
}

void gameObject::loadTexture(string path)
{
	// �ؽ��� Ŭ�������� �ؽ��ĸ� �ҷ��´�
	_texture = textureManager::getInstance()->loadTexture(path);
}

LPDIRECT3DTEXTURE9 gameObject::getTexture()
{
	return _texture;
}

void gameObject::setSize(int x, int y)
{
	// ũ�� ������ x, y���� ���Ѵ�
	_size.x = x;
	_size.y = y;
}

void gameObject::setPos(int x, int y)
{
	// ��ġ ������ x, y���� ���Ѵ�
	_pos.x = x;
	_pos.y = y;
}

void gameObject::setSize(D3DXVECTOR2 size)
{
	_size = size;
}

void gameObject::setPos(D3DXVECTOR2 pos)
{
	_pos = pos;
}

D3DXVECTOR2 gameObject::getSize()
{
	return _size;
}

D3DXVECTOR2 gameObject::getPos()
{
	return _pos;
}

bool gameObject::animation(string path, int frame, float delay)
{
	// ���� ����ð� - ����Ƚð��� �����̺��� ũ��
	if (GetTickCount() - _nowDelay >= delay)
	{
		// ����ð��� ���� �ð��� �����Ѵ�
		_nowDelay = GetTickCount();

		// ���� ���� �������� ��ǥ �����Ӱ� ���ٸ�
		if (_nowDelay == frame)
		{
			// ���� �������� 0���� �ְ�
			_nowFrame = 0;

			// �ð� �ʱ�ȭ
			_nowDelay = 0;

			// true���� �����Ѵ�.
			return true;
		}

		// ���� �������� �ϳ� �ø���
		_nowFrame++;
		path += to_string(_nowFrame);
		path += ".png";

		// �ؽ��ĸ� �ҷ����� �ٲ۴�.
		loadTexture(path);
	}

	// �ִϸ��̼��� ���� �ƴ϶�� false�� ����
	return false;
}