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

	_itemImage =_itemInvenImage = IMAGEMANAGER->addImage("heart", "./image/item/ÇÏÆ®.bmp", 50, 50, true, RGB(255, 0, 255));
	_itemRightTopImage =  NULL;

	_isVisible = true;
	//_isVisible = false;
	_itemEffect = 1;
	_itemType = WEAPON;
	_itemState = IDLE;

	_x = x; _y = y;

	_price = 150;

	return S_OK;
}
void heart::render()
{
	_itemImage->render(getMemDC(), _x, _y);
}