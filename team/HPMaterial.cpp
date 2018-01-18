#include "stdafx.h"
#include "HPMaterial.h"


HPMaterial::HPMaterial()
{
}


HPMaterial::~HPMaterial()
{

}

HRESULT HPMaterial::init(int x, int y)
{

	_itemImage = IMAGEMANAGER->addImage("HPMaterial", "./image/item/HP¿°·á.bmp", 100, 100, true, RGB(255, 0, 255));
	_itemRightTopImage = _itemInvenImage = NULL;

	_isVisible = true;
	//_isVisible = false;
	_itemEffect = 1;
	_itemType = WEAPON;
	_itemState = IDLE;

	_x = x; _y = y;

	_price = 150;
}
void HPMaterial::render()
{
	_itemImage->render(getMemDC(), _x, _y);
}