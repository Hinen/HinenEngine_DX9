//////////////////////////////////////////////////////////////
///////////////////  오브젝트 관리 클래스  ///////////////////
//////////////////////////////////////////////////////////////


#pragma once
#include "stdafx.h"
#include "gameObject.h"

using namespace std;

class objectManager
{
public:
	objectManager();
	~objectManager();

public:
	// 오브젝트를 추가하는 메서드
	void addObject(gameObject *obj);

	// Ui를 추가하는 메서드
	void addUi(gameObject *ui);

	// 모든 게임 오브젝트를 해제하는 메서드
	void release();

	// 화면을 인자값 만큼 이동하는 메서드
	void cameraMove(int x, int y);

private:
	// 오브젝트를 관리할 오브젝트 벡터와 Ui 벡터
	vector<gameObject*> _objectVector, _uiVector;
};

