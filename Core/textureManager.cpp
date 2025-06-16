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
	// ������ �����ŭ for���� ������.
	for (int i = 0; i < textureVector.size(); i++)
	{
		// ���� ã������ �̹����� path�� ���Ͱ� ������ �ִ� path�� ���� ���ٸ�
		// �̹� ���;ȿ� ����ҷ��� �̹����� �ִٴ� ���̹Ƿ�
		if (path == textureVector[i].path)
		{
			// ���;��� �ؽ��ĸ� �������ش�.
			return textureVector[i].texture;
		}
	}

	// ���� �̹����� ���Ϳ� ���ٸ� �̹����� �߰����� �ٽ� ������.
	addTexture(path);
	return loadTexture(path);
}

void textureManager::addTexture(string path)
{
	// �ӽ� �ؽ��� ������ ����,
	textureInfo Info;

	// Info�� path�� �߰��ҷ��� path�� �ִ´�.
	Info.path = path;

	// �ؽ��ĸ� �����ϴ� �޼���
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

	// path�� �ؽ��Ŀ� ���� �־��ٸ� �� Info�� ���Ϳ� �ִ´�.
	textureVector.push_back(Info);
}

void textureManager::release()
{
	// ������ �����ŭ for���� ������.
	for (int i = 0; i < textureVector.size(); i++)
	{
		// ��� ���;��� �ؽ��ĸ� �����Ѵ�.
		textureVector[i].texture->Release();
	}
	
	// ���͸� ����.
	textureVector.clear();
}