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
	_itemRightTopImage = IMAGEMANAGER->addImage("emptyRightTop", "./image/item/��(�������).bmp", 455, 157, true, RGB(255, 0, 255));
	_isVisible = true;
	//_isVisible = false;
	_itemEffect = 1;
	_itemType = POTION;
	_itemState = IDLE;
	_isFull = false;
	return S_OK;
}

void potion::update(){

	//�θ��� ������Ʈ�� ������
	itemParent::update();

	//�ڽŸ��� ������Ʈ
	if (_isFull)
	{
		_itemImage = _itemInvenImage = IMAGEMANAGER->findImage("HPpotion");
	}
	else
	{
		_itemImage = _itemInvenImage = IMAGEMANAGER->findImage("empty");
	}
	
}

void  potion::render()
{
	_itemImage->render(getMemDC(), 350, 40);
}