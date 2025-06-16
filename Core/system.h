//////////////////////////////////////////////////////////////
/////////////////  게임의 시스템 클래스  /////////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"

namespace game
{
	class system
	{
	public:
		system();
		~system();

		// 초기화, 메세지루프, 릴리즈, 그리고 메인 루프로 이루어져있다.
		void init();
		void msgLoop();
		void release();

	private:
		// 실제로 게임이 돌아가는 부분은 메세지루프 - 메인루프이다.
		void mainLoop();
	};
}
