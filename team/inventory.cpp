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

	_vItem.push_back(_bow);
	_vItem.push_back(_boomerang);
	_vItem.push_back(_potion);
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
	IMAGEMANAGER->findImage("inventory")->render(getMemDC());
	for (int i = 0; i < _vItem.size(); ++i)
	{
		if (_vItem[i]->getIsVisible())
			_vItem[i]->getItemInvenImage()->render(getMemDC(), 150 + 100 * i, 30);
	}
}