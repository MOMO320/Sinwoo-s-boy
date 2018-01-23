#include "stdafx.h"
#include "arrow.h"


arrow::arrow()
{
}


arrow::~arrow()
{

}
HRESULT arrow::init(){

	_itemImage = _itemInvenImage = IMAGEMANAGER->addImage("arrow", "./image/item/ȭ��.bmp", 50, 50, true, RGB(255, 0, 255));
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
	_itemImage = _itemInvenImage = IMAGEMANAGER->addImage("arrow", "./image/item/ȭ��.bmp", 50, 50, true, RGB(255, 0, 255));
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
	TextOut(getMemDC(), 500, 300, "����", strlen("����"));

	if (_itemState == IDLE)
	_itemImage->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y));
	else
		_itemImage->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y));
}

void arrow::fire()
{
	//ȭ���� 0����
	if (_count == 0) return;

	//1���� ��������
	if (_itemState == THROW) return;

	//ȭ���� ������
	if (_isShot) return;

	//������� ���� ȭ���� �ְ� ���� �ʾҴٸ� ȭ���� �߻�ȴ�!

	//ȭ���� ���´� �߻����
	_itemState = THROW;

	//ȭ�� �߻� ��ġ
	_x = 1000;
	_y = 800;
	_isShot = true;
}