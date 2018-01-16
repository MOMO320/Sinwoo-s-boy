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
	IMAGEMANAGER->addImage("inventory", "./image/인벤토리.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

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
}