//////////////////////////////////////////////////////////////
///////////////  �ؽ��ĸ� �����ϴ� Ŭ����  ///////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"

using namespace std;

// �ؽ��� ������ ����ִ� ����ü
struct textureInfo
{
	// ��� �� �ؽ��ĸ� �����ϰ� �ִ�.
	string path;
	LPDIRECT3DTEXTURE9 texture;
};

class textureManager : public singleton<textureManager>
{
public:
	textureManager();
	~textureManager();

public:
	// �ؽ��� �ҷ�����, ����
	LPDIRECT3DTEXTURE9 loadTexture(string path);
	void release();

private:
	// �ؽ��ĸ� ������ ����
	vector<textureInfo> textureVector;

	void addTexture(string path);
};

