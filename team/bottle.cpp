#include "stdafx.h"
#include "bottle.h"


bottle::bottle()
{

}


bottle::~bottle()
{
}

HRESULT bottle::init(POINT point)
{
	_objectImage = IMAGEMANAGER->addImage("�׾Ƹ�", "./image/object/bottle.bmp", 50, 50, true, RGB(255, 0, 255));
	_objectType = OB_THROW; //�����Ⱑ ������ ������Ʈ
	_objectEffect = 9999;
	_x = point.x, _y = point.y;

	_objectState = PUT;
	_frameX = _frameCount = 0;

	return S_OK;
}

void bottle::render()
{
	if (_objectState == PUT)
	{
		IMAGEMANAGER->findImage("�׾Ƹ�")->render(getMemDC(), _x, _y);
	}
}

void bottle::move()
{

}
