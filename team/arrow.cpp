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

	_mainPlayer = NULL;

	_price = 150;

	_count = 0;

	_isShot = false;

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

void arrow::update()
{

}

void arrow::render()
{
	TextOut(getMemDC(), 500, 300, "제발", strlen("제발"));

	if (_itemState == IDLE)
	_itemImage->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y));
	else
		_itemImage->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y));
}

void arrow::fire()
{
	//화살이 0개면
	if (_count == 0) return;

	//1개만 쏴지도록
	if (_itemState == THROW) return;

	//화살이 쏴졌냐
	if (_isShot) return;

	//여기까지 오면 화살이 있고 쏘지 않았다면 화살이 발사된다!

	//화살의 상태는 발사상태
	_itemState = THROW;

	//화살 발사 위치
	_x = 1000;
	_y = 800;
	_isShot = true;
}