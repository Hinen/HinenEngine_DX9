//////////////////////////////////////////////////////////////
///////////////////  ������Ʈ ���� Ŭ����  ///////////////////
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
	// ������Ʈ�� �߰��ϴ� �޼���
	void addObject(gameObject *obj);

	// Ui�� �߰��ϴ� �޼���
	void addUi(gameObject *ui);

	// ��� ���� ������Ʈ�� �����ϴ� �޼���
	void release();

	// ȭ���� ���ڰ� ��ŭ �̵��ϴ� �޼���
	void cameraMove(int x, int y);

private:
	// ������Ʈ�� ������ ������Ʈ ���Ϳ� Ui ����
	vector<gameObject*> _objectVector, _uiVector;
};

