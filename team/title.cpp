#include "stdafx.h"
#include "title.h"


title::title()
{
}


title::~title()
{
}

HRESULT title::init()
{


	return S_OK;
}

void title::release()
{
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		SCENEMANAGER->changeScene("����");
	}
}

void title::update()
{
	//�������� ����Ʈ�� �ٲ���
	switch (_rot)
	{
	case 0:

		break;
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	}

	for (int i = IMAGEMANAGER->findImage("Ÿ��Ʋ��¦��")->getFrameX(); i < IMAGEMANAGER->findImage("Ÿ��Ʋ��¦��")->getMaxFrameX() + 1; ++i)
	{
		IMAGEMANAGER->findImage("Ÿ��Ʋ��¦��")->setFrameX(IMAGEMANAGER->findImage("Ÿ��Ʋ��¦��")->getFrameX() + 1);
		if (IMAGEMANAGER->findImage("Ÿ��Ʋ��¦��")->getFrameX()>IMAGEMANAGER->findImage("Ÿ��Ʋ��¦��")->getMaxFrameX())
		{
			IMAGEMANAGER->findImage("Ÿ��Ʋ��¦��")->setFrameX(0);
			if (_rot == 3) _rot = 0;
			else _rot++;
		}
	}

}

void title::render()
{
	IMAGEMANAGER->findImage("Ÿ��Ʋ")->render(getMemDC());

	//Ÿ��Ʋ ��¦�� ���ϸ� ����
	//IMAGEMANAGER->findImage("Ÿ��Ʋ��¦��")->frameRender(getMemDC(),_P.x,_P.y);

	IMAGEMANAGER->findImage("������")->alphaRender(getMemDC(), _alpha);
}