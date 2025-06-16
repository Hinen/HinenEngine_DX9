//////////////////////////////////////////////////////////////
///////////////////  ���� ������Ʈ Ŭ����  ///////////////////
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
	// ����, visible
	float				degree;
	bool				visible;

	// �ؽ��� �ҷ�����
	void loadTexture(string path);

	// ������� ��ġ ����
	void setSize(int x, int y);
	void setPos(int x, int y);
	void setSize(D3DXVECTOR2 size);
	void setPos(D3DXVECTOR2 pos);

	// ������� ��ġ ��������
	LPDIRECT3DTEXTURE9 getTexture();
	D3DXVECTOR2 getSize();
	D3DXVECTOR2 getPos();

	// �ִϸ��̼�
	bool animation(string path, int frame, float delay);

private:
	// �ؽ���, ������
	LPDIRECT3DTEXTURE9	_texture;
	D3DXVECTOR2			_size;
	D3DXVECTOR2			_pos;

	// �ִϸ��̼��� ���� ��
	// ���� �� ����������, üũ�� ���� �ð�
	int					_nowFrame;
	float				_nowDelay;

};

