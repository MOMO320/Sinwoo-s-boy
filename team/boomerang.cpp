#include "stdafx.h"
#include "boomerang.h"


boomerang::boomerang()
{
}


boomerang::~boomerang()
{
}

HRESULT boomerang::init(){
	_itemImage = IMAGEMANAGER->addImage("boomerang", "./image/item/ºÎ¸Ş¶û(ÀÎº¥,½½·Ô).bmp", 100, 100, true, RGB(255, 0, 255));

	return S_OK;
}

void boomerang::render()
{
	_itemImage->render(getMemDC(), 250, 30);
}