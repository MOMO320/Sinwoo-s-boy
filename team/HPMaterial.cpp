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

	_itemImage = _itemInvenImage = IMAGEMANAGER->addImage("HPMaterial", "./image/item/HP¿°·á.bmp", 100, 100, true, RGB(255, 0, 255));
	_itemRightTopImage = NULL;

	_isVisible = true;
	//_isVisible = false;
	_itemEffect = 1;
	_itemType = WEAPON;
	_itemState = IDLE;

	_x = x; _y = y;

	_price = 150;

	_mainPlayer = NULL;

	return S_OK;
}
void HPMaterial::render()
{
	_itemImage->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y));
}