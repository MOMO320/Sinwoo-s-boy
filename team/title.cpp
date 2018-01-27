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
	_P = PointMake(152, 218);
	_alphaOn = false;
	_frameX = 0;
	_rot = 0;
	_count = 0;
	_alpha = 0;

	


	return S_OK;
}

void title::release()
{
	
}

void title::update() 
{
	//�������� ����Ʈ�� �ٲ���
	switch (_rot)
	{
		case 0:
			_P = PointMake(152, 218);
		break;
		case 1:
			_P = PointMake(339, 324);
		break;
		case 2:
			_P = PointMake(484, 223);
		break;
		case 3:
			_P = PointMake(570, 326);
		break;
	}

	if (KEYMANAGER->isOnceKeyDown('Z')||
		KEYMANAGER->isOnceKeyDown('X')||
		KEYMANAGER->isOnceKeyDown('C')||
		KEYMANAGER->isOnceKeyDown(VK_LEFT)||
		KEYMANAGER->isOnceKeyDown(VK_RIGHT)||
		KEYMANAGER->isOnceKeyDown(VK_UP)||
		KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_alphaOn = true;
	}
	if (_alphaOn) _alpha += 5;
	if (_alpha > 255)
	{
		SCENEMANAGER->changeScene("����");
		_alpha = 0;
	}
	_count++;
	if (_count % 2 == 0)
	{
		_frameX++;
		if (_frameX > 15)
		{
			_frameX = 0;
			if (_rot == 3) _rot = 0;
			else _rot++;
			_count = 0;
		}
	}
}

void title::render() 
{
	IMAGEMANAGER->findImage("Ÿ��Ʋȭ��")->render(getMemDC());


	IMAGEMANAGER->findImage("Ÿ��Ʋ��¦��")->frameRender(getMemDC(),_P.x,_P.y,_frameX,0);

	IMAGEMANAGER->findImage("������")->alphaRender(getMemDC(),_alpha);

	//char str[128];
	//sprintf(str, "%d, %d", _P.x, _P.y);
	//TextOut(getMemDC(), 10, 10, str, strlen(str));
}