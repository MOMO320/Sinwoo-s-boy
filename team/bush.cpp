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
	_objectImage = IMAGEMANAGER->addImage("��Ǯ", "./image/object/bush.bmp", 50, 50, true, RGB(255, 0, 255));
	_objectType = OB_THROW; //�����Ⱑ ������ ������Ʈ
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
		IMAGEMANAGER->findImage("��Ǯ")->render(getMemDC(), _x, _y);
	}
}

void bush::move()
{

}

void bush::hide()
{

}
