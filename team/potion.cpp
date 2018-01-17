#include "stdafx.h"
#include "potion.h"


potion::potion()
{
}


potion::~potion()
{

}

HRESULT  potion::init()
{
	_itemImage = _itemInvenImage = IMAGEMANAGER->addImage("empty", "./image/item/��.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("HPpotion", "./image/item/HP����.bmp", 100, 100, true, RGB(255, 0, 255));

	_isVisible = true;
	//_isVisible = false;
	_itemEffect = 1;
	_itemType = WEAPON;
	_itemState = IDLE;

	return S_OK;
}
void  potion::render()
{
	_itemImage->render(getMemDC(), 350, 40);
}