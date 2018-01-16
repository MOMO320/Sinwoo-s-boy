#include "stdafx.h"
#include "bow.h"


bow::bow()
{
}


bow::~bow()
{

}

HRESULT bow::init(){
	_itemImage = IMAGEMANAGER->addImage("bow", "./image/È°(ÀÎº¥,½½·Ô).bmp", 100, 100, true, RGB(255, 0, 255));

	return S_OK;
}

void bow::render()
{
	_itemImage->render(getMemDC(), 150, 30);
}