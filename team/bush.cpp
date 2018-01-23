#include "stdafx.h"
#include "bush.h"


bush::bush()
{
}


bush::~bush()
{
}

HRESULT bush::init(POINT point)
{
	_objectImage = IMAGEMANAGER->addImage("수풀", "./image/object/bush.bmp", 50, 50, true, RGB(255, 0, 255));
	_objectType = OB_THROW; //던지기가 가능한 오브젝트
	_objectEffect = 9999;
	_x = point.x, _y = point.y;

	_objectState = PUT;
	_frameX = _frameCount = 0;


	return S_OK;
}

void bush::render()
{
	if (_objectState == PUT)
	{
		IMAGEMANAGER->findImage("수풀")->render(getMemDC(), _x, _y);
	}
}

void bush::move()
{

}

void bush::hide()
{

}
