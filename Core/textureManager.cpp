#include "textureManager.h"
#include "graphicManager.h"

textureManager::textureManager()
{
}


textureManager::~textureManager()
{
}

LPDIRECT3DTEXTURE9 textureManager::loadTexture(string path)
{
	// 벡터의 사이즈만큼 for문을 돌린다.
	for (int i = 0; i < textureVector.size(); i++)
	{
		// 만약 찾을려는 이미지의 path와 벡터가 가지고 있는 path의 값이 같다면
		// 이미 벡터안에 사용할려는 이미지가 있다는 뜻이므로
		if (path == textureVector[i].path)
		{
			// 벡터안의 텍스쳐를 리턴해준다.
			return textureVector[i].texture;
		}
	}

	// 만약 이미지가 벡터에 없다면 이미지를 추가한후 다시 돌린다.
	addTexture(path);
	return loadTexture(path);
}

void textureManager::addTexture(string path)
{
	// 임시 텍스쳐 정보를 선언,
	textureInfo Info;

	// Info의 path에 추가할려는 path를 넣는다.
	Info.path = path;

	// 텍스쳐를 생성하는 메서드
	D3DXCreateTextureFromFileEx(graphicManager::getInstance()->getDevice(),
								Info.path.c_str(),
								D3DX_DEFAULT_NONPOW2,
								D3DX_DEFAULT_NONPOW2,
								1,
								0,
								D3DFMT_UNKNOWN,
								D3DPOOL_MANAGED,
								1,
								1,
								NULL,
								NULL,
								NULL,
								&Info.texture);

	// path와 텍스쳐에 값을 넣었다면 이 Info를 벡터에 넣는다.
	textureVector.push_back(Info);
}

void textureManager::release()
{
	// 벡터의 사이즈만큼 for문을 돌린다.
	for (int i = 0; i < textureVector.size(); i++)
	{
		// 모든 벡터안의 텍스쳐를 해제한다.
		textureVector[i].texture->Release();
	}
	
	// 벡터를 비운다.
	textureVector.clear();
}