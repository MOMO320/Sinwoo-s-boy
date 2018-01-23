#include "stdafx.h"
#include "stone.h"


stone::stone()
{
}


stone::~stone()
{
}

HRESULT stone::init(POINT point)
{
	_objectImage = IMAGEMANAGER->addImage("도오올", "./image/object/stone.bmp", 50, 50, true, RGB(255, 0, 255));
	_objectType = OB_THROW; //던지기가 가능한 오브젝트
	_objectEffect = 9999;
	_x = point.x, _y = point.y;

	_objectState = PUT;
	_frameX = _frameCount = 0;


	return S_OK;
}

void stone::render()
{
	if (_objectState == PUT)
	{
		IMAGEMANAGER->findImage("도오올")->render(getMemDC(), _x, _y);
	}
}

void stone::move()
{

}