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

	IMAGEMANAGER->addImage("Ÿ��Ʋȭ��", "image/UI/Ÿ��Ʋ.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Ÿ��Ʋ��¦��", "image/UI/shiny.bmp", 300, 20, 15, 1, true, RGB(255, 0, 255));
	//��ǥ(167,227)(349,335)(496,248)(580,338)
	_P = PointMake(167, 227);
	_rot = 0;
	_count = 0;
	_alpha = 0;
	return S_OK;
}

void title::release()
{
	if (KEYMANAGER->AnyKeyDown())
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
			_P = PointMake(167, 227);
		break;
		case 1:
			_P = PointMake(349, 335);
		break;
		case 2:
			_P = PointMake(496, 248);
		break;
		case 3:
			_P = PointMake(580, 338);
		break;
	}


	//_count++;
	//if(_count/20==0)
	//for (int i = IMAGEMANAGER->findImage("Ÿ��Ʋ��¦��")->getFrameX(); i < IMAGEMANAGER->findImage("Ÿ��Ʋ��¦��")->getMaxFrameX()+1; ++i)
	//{
	//	IMAGEMANAGER->findImage("Ÿ��Ʋ��¦��")->setFrameX(IMAGEMANAGER->findImage("Ÿ��Ʋ��¦��")->getFrameX() + 1);
	//	if(IMAGEMANAGER->findImage("Ÿ��Ʋ��¦��")->getFrameX()>IMAGEMANAGER->findImage("Ÿ��Ʋ��¦��")->getMaxFrameX())
	//	{
	//		IMAGEMANAGER->findImage("Ÿ��Ʋ��¦��")->setFrameX(0);
	//		if (_rot == 3) _rot = 0;
	//		else _rot++;
	//		_count = 0;
	//	}
	//}
	
}

void title::render() 
{
	IMAGEMANAGER->findImage("Ÿ��Ʋ")->render(getMemDC());


	IMAGEMANAGER->findImage("Ÿ��Ʋ��¦��")->frameRender(getMemDC(),_P.x,_P.y);

	IMAGEMANAGER->findImage("������")->alphaRender(getMemDC(),_alpha);
}