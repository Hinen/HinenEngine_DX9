//////////////////////////////////////////////////////////////
///////////////  텍스쳐를 관리하는 클래스  ///////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"

using namespace std;

// 텍스쳐 정보를 담고있는 구조체
struct textureInfo
{
	// 경로 와 텍스쳐를 포함하고 있다.
	string path;
	LPDIRECT3DTEXTURE9 texture;
};

class textureManager : public singleton<textureManager>
{
public:
	textureManager();
	~textureManager();

public:
	// 텍스쳐 불러오기, 해제
	LPDIRECT3DTEXTURE9 loadTexture(string path);
	void release();

private:
	// 텍스쳐를 관리할 벡터
	vector<textureInfo> textureVector;

	void addTexture(string path);
};

