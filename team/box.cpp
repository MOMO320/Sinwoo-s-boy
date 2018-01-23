#include "stdafx.h"
#include "box.h"


box::box()
{

}


box::~box()
{
}

HRESULT box::init(POINT point)
{
	_objectImage = IMAGEMANAGER->addImage("상자", "./image/object/golden_box.bmp", 50, 50, true, RGB(255, 0, 255));
	_objectType = OB_BOX; //던지기가 가능한 오브젝트
	_objectEffect = 9999;
	_x = point.x, _y = point.y;

	_objectState = PUT;
	_frameX = _frameCount = 0;


	return S_OK;
}

void box::render()
{
	if (_objectState == PUT)
	{
		IMAGEMANAGER->findImage("상자")->render(getMemDC(), _x, _y);
	}
}

void box::open()
{
}

