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

	IMAGEMANAGER->addImage("Å¸ÀÌÆ²È­¸é", "image/UI/Å¸ÀÌÆ².bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Å¸ÀÌÆ²ºþÂ¦ÀÌ", "image/UI/shiny.bmp", 300, 20, 15, 1, true, RGB(255, 0, 255));
	//ÁÂÇ¥(167,227)(349,335)(496,248)(580,338)
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
		SCENEMANAGER->changeScene("ÆÄÀÏ");
	}
}

void title::update() 
{
	//µ¹¶§¸¶´Ù Æ÷ÀÎÆ®¸¦ ¹Ù²ãÁÜ
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
	//for (int i = IMAGEMANAGER->findImage("Å¸ÀÌÆ²ºþÂ¦ÀÌ")->getFrameX(); i < IMAGEMANAGER->findImage("Å¸ÀÌÆ²ºþÂ¦ÀÌ")->getMaxFrameX()+1; ++i)
	//{
	//	IMAGEMANAGER->findImage("Å¸ÀÌÆ²ºþÂ¦ÀÌ")->setFrameX(IMAGEMANAGER->findImage("Å¸ÀÌÆ²ºþÂ¦ÀÌ")->getFrameX() + 1);
	//	if(IMAGEMANAGER->findImage("Å¸ÀÌÆ²ºþÂ¦ÀÌ")->getFrameX()>IMAGEMANAGER->findImage("Å¸ÀÌÆ²ºþÂ¦ÀÌ")->getMaxFrameX())
	//	{
	//		IMAGEMANAGER->findImage("Å¸ÀÌÆ²ºþÂ¦ÀÌ")->setFrameX(0);
	//		if (_rot == 3) _rot = 0;
	//		else _rot++;
	//		_count = 0;
	//	}
	//}
	
}

void title::render() 
{
	IMAGEMANAGER->findImage("Å¸ÀÌÆ²")->render(getMemDC());


	IMAGEMANAGER->findImage("Å¸ÀÌÆ²ºþÂ¦ÀÌ")->frameRender(getMemDC(),_P.x,_P.y);

	IMAGEMANAGER->findImage("¾ÏÀü¿ë")->alphaRender(getMemDC(),_alpha);
}