#include "stdafx.h"
#include "bow.h"
#include "arrow.h"

bow::bow()
{
}


bow::~bow()
{

}

HRESULT bow::init(){
	_itemImage =_itemInvenImage = IMAGEMANAGER->addImage("bow", "./image/item/Ȱ(�κ�,����).bmp", 100, 100, true, RGB(255, 0, 255));
	_itemRightTopImage = IMAGEMANAGER->addImage("bowRightTop", "./image/item/Ȱ(�������).bmp", 455, 157, true, RGB(255, 0, 255));

	_isVisible = true;
	//_isVisible = false;
	_itemEffect = 1;
	_itemType = WEAPON;
	_itemState = IDLE;

	_arrow = new arrow;
	_arrow->init();

	return S_OK;
}

void bow::render()
{
	_itemImage->render(getMemDC(), 150, 30);
}