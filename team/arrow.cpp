#include "stdafx.h"
#include "arrow.h"


arrow::arrow()
{
}


arrow::~arrow()
{

}
HRESULT arrow::init(){

	_itemImage = _itemInvenImage = IMAGEMANAGER->addImage("arrow", "./image/item/화살.bmp", 50, 50, true, RGB(255, 0, 255));
	_itemRightTopImage = NULL;

	_isVisible = true;
	//_isVisible = false;
	_itemEffect = 1;
	_itemType = WEAPON;
	_itemState = IDLE;


	_price = 150;

	_count = 0;

	return S_OK;
}
HRESULT arrow::init(int x, int y)
{
	_itemImage = _itemInvenImage = IMAGEMANAGER->addImage("arrow", "./image/item/화살.bmp", 50, 50, true, RGB(255, 0, 255));
	_itemRightTopImage =  NULL;

	_isVisible = true;
	//_isVisible = false;
	_itemEffect = 1;
	_itemType = WEAPON;
	_itemState = IDLE;

	_x = x; _y = y;

	_price = 150;

	_count = 0;
	return S_OK;
}

void arrow::render()
{
	_itemImage->render(getMemDC(), _x, _y);
}