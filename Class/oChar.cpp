#include "oChar.h"


oChar::oChar()
{
}


oChar::~oChar()
{
}

void oChar::key()
{
	// 방향키 위
	if (GetKeyState(VK_UP) & 0x8000)
	{
		// 벡터를 선언하고 정규화이후 일정한 속도로 오브젝트의 각도의 방향으로 이동
		D3DXVECTOR2 vec = D3DXVECTOR2(cos(D3DXToRadian(degree)), sin(D3DXToRadian(degree)));
		D3DXVec2Normalize(&vec, &vec);
		setPos(getPos() + vec * 6 /* 속도 */);
	}

	// 방향키 아래
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		// 벡터를 선언하고 정규화이후 일정한 속도로 오브젝트의 각도의 방향으로 이동
		D3DXVECTOR2 vec = D3DXVECTOR2(cos(D3DXToRadian(degree)), sin(D3DXToRadian(degree)));
		D3DXVec2Normalize(&vec, &vec);
		setPos(getPos() - vec * 6 /* 속도 */);
	}

	// 방향키 왼쪽
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		// 각도를 2를 뺀다.
		degree -= 2;
	}

	// 방향키 오른쪽
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		// 각도를 2를 더한다.
		degree += 2;
	}
}