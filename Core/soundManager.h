//////////////////////////////////////////////////////////////
///////////////  사운드를 출력하는 클래스  ///////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"

using namespace std;

class soundManager : public singleton<soundManager>
{
public:
	soundManager();
	~soundManager();

public:
	// 배경음을 출력하는 메서드
	void playBg(string path);

	// 효과음을 출력하는 메서드
	void playEf(string path);
};

