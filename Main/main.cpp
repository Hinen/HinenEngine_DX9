///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
/////////////////////     Hinen Engin      ////////////////////
/////////////////////     For 기능대회     ////////////////////
/////////////////////  제작 : 11기 박수빈  ////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

// 기능대회를 위한 기본적인 기능만이 포함되어 있습니다.
// 씬 변경, 텍스쳐 관리, 오브젝트 관리, 충돌체크, 사운드 출력, 애니메이션 기능
// 엔진을 수정하여 더 좋은 엔진으로 만들어서 사용하셔도 되지만 무단 배포 금지

#include "stdafx.h"
#include "System.h"

INT WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR, INT)
{
	// 시스템 클래스를 생성
	game::system cs;

	// 초기화 및 메세지루프와 릴리즈
	cs.init();

	cs.msgLoop();

	cs.release();
}