#include "stdafx.h"
#include "heart.h"


heart::heart()
{
}


heart::~heart()
{
}
HRESULT heart::init(int x, int y)
{

	_itemImage =_itemInvenImage = IMAGEMANAGER->addImage("heart", "./image/item/��Ʈ.bmp", 50, 50, true, RGB(255, 0, 255));
	_itemRightTopImage =  NULL;

	_isVisible = true;
	//_isVisible = false;
	_itemEffect = 1;
	_itemType = WEAPON;
	_itemState = IDLE;

	_x = x; _y = y;

	_price = 150;

	_mainPlayer = NULL;

	return S_OK;
}
void heart::render()
{
	//TextOut(getMemDC(), 500, 300, "����", strlen("����"));
	_itemImage->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y));
}