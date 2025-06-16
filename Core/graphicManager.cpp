#include "graphicManager.h"
#include "sceneManager.h"

graphicManager::graphicManager()
{
}


graphicManager::~graphicManager()
{
}

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// ���� ���Ͻ���

	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void graphicManager::init()
{
	// ������ Ŭ������ ������ ����
	_wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		"D3D Tutorial", NULL
	};
	RegisterClassEx(&_wc);

	// �����츦 ������
	_hWnd = CreateWindow("D3D Tutorial", "D3D Tutorial 01: CreateDevice",
		WS_OVERLAPPEDWINDOW, 100, 100, 800, 600,
		NULL, NULL, _wc.hInstance, NULL);

	// �����ְ� ������Ʈ�� �Ѵ�.
	ShowWindow(_hWnd, SW_SHOWDEFAULT);
	UpdateWindow(_hWnd);

	// D3D �ʱ�ȭ
	_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	// true�� â���, false�� ��üȭ��
	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = 800;
	d3dpp.BackBufferHeight = 600;

	// ����̽� ����
	_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &_pd3dDevice);

	// ��������Ʈ�� ��Ʈ�� ����
	createSprite();
	createFont();
}

void graphicManager::createSprite()
{
	// ��������Ʈ ����
	D3DXCreateSprite(_pd3dDevice, &_pSprite);
}

void graphicManager::createFont()
{
	// ��Ʈ ����
	D3DXCreateFont(_pd3dDevice, 30, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, NULL, NULL, NULL, "��������ü", &_pFont);
}

void graphicManager::update()
{
	renderStart();

	// �ش� ���� ������Ʈ�� ���ְ�
	sceneManager::getInstance()->scene->update();

	renderEnd();
}

void graphicManager::renderStart()
{
	// ȭ���� �����ϰ� �� ��, ����
	_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	_pd3dDevice->BeginScene();
}

void graphicManager::render(gameObject *obj)
{
	// ������Ʈ�� visible�� true�� ��쿡�� �׸���.
	if (obj->visible == true)
	{
		// ������Ʈ�� ������
		RECT size;
		size.top = 0;
		size.left = 0;
		size.right = obj->getSize().x;
		size.bottom = obj->getSize().y;

		// ������Ʈ�� �������� �޴´�.
		// Radian���� ��ȯ�� ������ ȸ���� ����
		float radian = D3DXToRadian(obj->degree);

		// ��Ʈ���� ����
		D3DXMATRIX mat;

		// ȸ��, �̵�, ����, ������
		D3DXMATRIX rot;
		D3DXMATRIX trns;
		D3DXMATRIX center;
		D3DXMATRIX centerL;

		// ������ķ� �ʱ�ȭ
		D3DXMatrixIdentity(&mat);
		D3DXMatrixIdentity(&rot);
		D3DXMatrixIdentity(&trns);
		D3DXMatrixIdentity(&center);
		D3DXMatrixIdentity(&centerL);

		// Z���� �������� degree�� ��ŭ ȸ��
		D3DXMatrixRotationZ(&rot, radian);

		// ����� ����
		D3DXMatrixInverse(&centerL, NULL, &center);

		// ���Ͱ��� �̵�(��ġ)���� ����
		D3DXMatrixTranslation(&centerL, -obj->getSize().x / 2, -obj->getSize().y / 2, 0);
		D3DXMatrixTranslation(&trns, obj->getPos().x, obj->getPos().y, 0);

		// ��ü ��Ʈ������ ������
		mat = centerL * rot * center * trns;

		// ����
		_pSprite->SetTransform(&mat);

		_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

		// Render
		_pSprite->Draw(obj->getTexture(), &size, NULL, NULL, 0xffffffff);

		_pSprite->End();
	}
}

void graphicManager::drawText(string Text, int x, int y, D3DXCOLOR color)
{
	// ������ ����
	RECT size;
	size.top = y;
	size.left = x;
	size.right = 0;
	size.bottom = 0;

	_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	// Render
	_pFont->DrawTextA(_pSprite, Text.c_str(), -1, &size, DT_NOCLIP, color);

	_pSprite->End();
}

void graphicManager::renderEnd()
{
	// ������ ����
	_pd3dDevice->EndScene();
	_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

LPDIRECT3DDEVICE9 graphicManager::getDevice()
{
	return _pd3dDevice;
}

void graphicManager::release()
{
	// ����̽��� D3D, ��������Ʈ, ��Ʈ ����

	if (_pd3dDevice != NULL)
		_pd3dDevice->Release();

	if (_pD3D != NULL)
		_pD3D->Release();

	if (_pSprite != NULL)
		_pSprite->Release();

	if (_pFont != NULL)
		_pFont->Release();
}