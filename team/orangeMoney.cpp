#include "stdafx.h"
#include "orangeMoney.h"


orangeMoney::orangeMoney()
{
}


orangeMoney::~orangeMoney()
{
}

HRESULT orangeMoney::init(int x, int y)
{
	_itemImage = _itemInvenImage = _itemRightTopImage
		= IMAGEMANAGER->addImage("orangemoney", "./image/item/orangemoney.bmp", 23, 46, true, RGB(255, 0, 255));

	_x = x; _y = y;

	//1¿ø ½Àµæ
	_itemEffect = 5;

	_itemType = MONEY;
	_itemState = IDLE;

	return S_OK;
}

void orangeMoney::render()
{
	_itemImage->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y));
}
