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
	_itemImage = IMAGEMANAGER->addImage("empty", "./image/item/��.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("HPpotion", "./image/item/HP����.bmp", 100, 100, true, RGB(255, 0, 255));

	return S_OK;
}
void  potion::render()
{
	_itemImage->render(getMemDC(), 350, 40);
}