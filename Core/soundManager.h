//////////////////////////////////////////////////////////////
///////////////  ���带 ����ϴ� Ŭ����  ///////////////////
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
	// ������� ����ϴ� �޼���
	void playBg(string path);

	// ȿ������ ����ϴ� �޼���
	void playEf(string path);
};

