#include "stdafx.h"
#include "gbox.h"


gbox::gbox()
{
}


gbox::~gbox()
{
}

HRESULT gbox::init(POINT point)
{
	_objectImage = IMAGEMANAGER->addImage("ū����", "./image/object/great_golden_box.bmp", 100, 75, true, RGB(255, 0, 255));
	_objectType = OB_BOX; //�����Ⱑ ������ ������Ʈ
	_objectEffect = 9999;
	_x = point.x, _y = point.y;

	_objectState = PUT;
	_frameX = _frameCount = 0;


	return S_OK;
}

void gbox::render()
{
	if (_objectState == PUT)
	{
		IMAGEMANAGER->findImage("ū����")->render(getMemDC(), _x, _y);
	}
}

void gbox::open()
{

}