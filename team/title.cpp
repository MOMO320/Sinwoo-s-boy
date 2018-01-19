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
		SCENEMANAGER->changeScene("ÆÄÀÏ");
	}
}

void title::update()
{
	//µ¹¶§¸¶´Ù Æ÷ÀÎÆ®¸¦ ¹Ù²ãÁÜ
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

	for (int i = IMAGEMANAGER->findImage("Å¸ÀÌÆ²ºþÂ¦ÀÌ")->getFrameX(); i < IMAGEMANAGER->findImage("Å¸ÀÌÆ²ºþÂ¦ÀÌ")->getMaxFrameX() + 1; ++i)
	{
		IMAGEMANAGER->findImage("Å¸ÀÌÆ²ºþÂ¦ÀÌ")->setFrameX(IMAGEMANAGER->findImage("Å¸ÀÌÆ²ºþÂ¦ÀÌ")->getFrameX() + 1);
		if (IMAGEMANAGER->findImage("Å¸ÀÌÆ²ºþÂ¦ÀÌ")->getFrameX()>IMAGEMANAGER->findImage("Å¸ÀÌÆ²ºþÂ¦ÀÌ")->getMaxFrameX())
		{
			IMAGEMANAGER->findImage("Å¸ÀÌÆ²ºþÂ¦ÀÌ")->setFrameX(0);
			if (_rot == 3) _rot = 0;
			else _rot++;
		}
	}

}

void title::render()
{
	IMAGEMANAGER->findImage("Å¸ÀÌÆ²")->render(getMemDC());

	//Å¸ÀÌÆ² ¹ÝÂ¦ÀÌ ¹½ÇÏ¸é Áö¿ò
	//IMAGEMANAGER->findImage("Å¸ÀÌÆ²ºþÂ¦ÀÌ")->frameRender(getMemDC(),_P.x,_P.y);

	IMAGEMANAGER->findImage("¾ÏÀü¿ë")->alphaRender(getMemDC(), _alpha);
}