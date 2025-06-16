//////////////////////////////////////////////////////////////
////////////////////  �׷��� ���� Ŭ����  ////////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"
#include "gameObject.h"

using namespace std;

class graphicManager : public singleton<graphicManager>
{
public:
	graphicManager();
	~graphicManager();

public:
	// �ʱ�ȭ�� ����, Render, ����
	void init();
	void update();
	void render(gameObject *obj);
	void drawText(string Text, int x, int y, D3DXCOLOR color);
	void release();

	LPDIRECT3DDEVICE9 getDevice();

private:
	void renderStart();
	void renderEnd();
	void createSprite();
	void createFont();

private:
	LPDIRECT3D9         _pD3D;
	LPDIRECT3DDEVICE9   _pd3dDevice;
	LPD3DXSPRITE		_pSprite;
	LPD3DXFONT			_pFont;
	WNDCLASSEX			_wc;
	HWND				_hWnd;
};

