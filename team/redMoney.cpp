#include "stdafx.h"
#include "redMoney.h"


redMoney::redMoney()
{
}


redMoney::~redMoney()
{
}

HRESULT redMoney::init(int x, int y)
{
	_itemImage = _itemInvenImage = _itemRightTopImage
		= IMAGEMANAGER->addImage("redmoney", "./image/item/redmoney.bmp", 23, 46, true, RGB(255, 0, 255));

	_x = x; _y = y;

	//1¿ø ½Àµæ
	_itemEffect = 10;

	_itemType = MONEY;
	_itemState = IDLE;

	return S_OK;
}

void redMoney::render()
{
	_itemImage->render(getMemDC(), _x, _y);
}
