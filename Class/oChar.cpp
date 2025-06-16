#include "oChar.h"


oChar::oChar()
{
}


oChar::~oChar()
{
}

void oChar::key()
{
	// ����Ű ��
	if (GetKeyState(VK_UP) & 0x8000)
	{
		// ���͸� �����ϰ� ����ȭ���� ������ �ӵ��� ������Ʈ�� ������ �������� �̵�
		D3DXVECTOR2 vec = D3DXVECTOR2(cos(D3DXToRadian(degree)), sin(D3DXToRadian(degree)));
		D3DXVec2Normalize(&vec, &vec);
		setPos(getPos() + vec * 6 /* �ӵ� */);
	}

	// ����Ű �Ʒ�
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		// ���͸� �����ϰ� ����ȭ���� ������ �ӵ��� ������Ʈ�� ������ �������� �̵�
		D3DXVECTOR2 vec = D3DXVECTOR2(cos(D3DXToRadian(degree)), sin(D3DXToRadian(degree)));
		D3DXVec2Normalize(&vec, &vec);
		setPos(getPos() - vec * 6 /* �ӵ� */);
	}

	// ����Ű ����
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		// ������ 2�� ����.
		degree -= 2;
	}

	// ����Ű ������
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		// ������ 2�� ���Ѵ�.
		degree += 2;
	}
}