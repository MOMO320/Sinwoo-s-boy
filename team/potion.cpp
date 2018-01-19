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
	_itemImage = _itemInvenImage = IMAGEMANAGER->addImage("empty", "./image/item/빈병.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("HPpotion", "./image/item/HP포션.bmp", 100, 100, true, RGB(255, 0, 255));
	_itemRightTopImage = IMAGEMANAGER->addImage("emptyRightTop", "./image/item/빈병(우측상단).bmp", 455, 157, true, RGB(255, 0, 255));
	_isVisible = true;
	//_isVisible = false;
	_itemEffect = 1;
	_itemType = POTION;
	_itemState = IDLE;
	_isFull = false;
	return S_OK;
}

void potion::update(){

	//부모의 업데이트를 돌리고
	itemParent::update();

	//자신만의 업데이트
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