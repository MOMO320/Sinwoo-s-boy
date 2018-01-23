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
	_objectImage = IMAGEMANAGER->addImage("������", "./image/object/stone.bmp", 50, 50, true, RGB(255, 0, 255));
	_objectType = OB_THROW; //�����Ⱑ ������ ������Ʈ
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
		IMAGEMANAGER->findImage("������")->render(getMemDC(), _x, _y);
	}
}

void stone::move()
{

}