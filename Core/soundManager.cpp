#include "soundManager.h"


soundManager::soundManager()
{
}


soundManager::~soundManager()
{
}

void soundManager::playBg(string path)
{
	// mcisendstring���� �����ϰ� ������� �ҷ��´�.
	string name;
	name = "open ";
	name += path;
	name += " type mpegvideo alias A";

	mciSendString(name.c_str(), NULL, NULL, NULL);

	// �׸��� ���ѹݺ� ���
	mciSendString("play A notify repeat", NULL, NULL, NULL);
}

void soundManager::playEf(string path)
{
	// ȿ���� ������ ����Ѵ�.
	sndPlaySound(path.c_str(), SND_ASYNC);
}