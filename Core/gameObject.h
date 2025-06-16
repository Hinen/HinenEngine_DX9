//////////////////////////////////////////////////////////////
///////////////////  게임 오브젝트 클래스  ///////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"

using namespace std;

class gameObject
{
public:
	gameObject();
	~gameObject();

public:
	// 각도, visible
	float				degree;
	bool				visible;

	// 텍스쳐 불러오기
	void loadTexture(string path);

	// 사이즈와 위치 적용
	void setSize(int x, int y);
	void setPos(int x, int y);
	void setSize(D3DXVECTOR2 size);
	void setPos(D3DXVECTOR2 pos);

	// 사이즈와 위치 가져오기
	LPDIRECT3DTEXTURE9 getTexture();
	D3DXVECTOR2 getSize();
	D3DXVECTOR2 getPos();

	// 애니메이션
	bool animation(string path, int frame, float delay);

private:
	// 텍스쳐, 사이즈
	LPDIRECT3DTEXTURE9	_texture;
	D3DXVECTOR2			_size;
	D3DXVECTOR2			_pos;

	// 애니메이션을 위한 값
	// 현재 몇 프레임인지, 체크를 위한 시간
	int					_nowFrame;
	float				_nowDelay;

};

