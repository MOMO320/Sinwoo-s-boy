#include "stdafx.h"
#include "inventory.h"


inventory::inventory()
{
}


inventory::~inventory()
{

}

HRESULT inventory::init()
{
	IMAGEMANAGER->addImage("inventory", "./image/item/인벤토리.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_bow = new bow;
	_bow->init();

	_boomerang = new boomerang;
	_boomerang->init();

	_potion = new potion;
	_potion->init();
	return S_OK;
}
void inventory::release()
{

}
void inventory::update()
{

}
void inventory::render()
{
	IMAGEMANAGER->render("inventory", getMemDC());
	_bow->render();
	_boomerang->render();
	_potion->render();
}