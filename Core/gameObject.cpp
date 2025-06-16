#include "gameObject.h"
#include "textureManager.h"

gameObject::gameObject()
{
	// 각도를 0도, 0프레임, visible을 true로 설정
	degree = 0;
	_nowFrame = 0;
	visible = true;
}


gameObject::~gameObject()
{
}

void gameObject::loadTexture(string path)
{
	// 텍스쳐 클래스에서 텍스쳐를 불러온다
	_texture = textureManager::getInstance()->loadTexture(path);
}

LPDIRECT3DTEXTURE9 gameObject::getTexture()
{
	return _texture;
}

void gameObject::setSize(int x, int y)
{
	// 크기 벡터의 x, y값을 정한다
	_size.x = x;
	_size.y = y;
}

void gameObject::setPos(int x, int y)
{
	// 위치 벡터의 x, y값을 정한다
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
	// 만약 현재시간 - 저장된시간이 딜레이보다 크면
	if (GetTickCount() - _nowDelay >= delay)
	{
		// 저장시간에 현재 시간을 저장한다
		_nowDelay = GetTickCount();

		// 만약 현재 프레임이 목표 프레임과 같다면
		if (_nowDelay == frame)
		{
			// 현재 프레임을 0으로 주고
			_nowFrame = 0;

			// 시간 초기화
			_nowDelay = 0;

			// true값을 리턴한다.
			return true;
		}

		// 현재 프레임을 하나 늘리고
		_nowFrame++;
		path += to_string(_nowFrame);
		path += ".png";

		// 텍스쳐를 불러온후 바꾼다.
		loadTexture(path);
	}

	// 애니메이션이 끝이 아니라면 false을 리턴
	return false;
}