#include "stdafx.h"
#include "bow.h"
#include "arrow.h"

bow::bow()
{
}


bow::~bow()
{

}

HRESULT bow::init(){
	_itemImage =_itemInvenImage = IMAGEMANAGER->addImage("bow", "./image/item/활(인벤,슬롯).bmp", 100, 100, true, RGB(255, 0, 255));
	_itemRightTopImage = IMAGEMANAGER->addImage("bowRightTop", "./image/item/활(우측상단).bmp", 455, 157, true, RGB(255, 0, 255));

	//_isVisible = true;
	_isVisible = false;
	_itemEffect = 1;
	_itemType = WEAPON;
	_itemState = IDLE;

	_arrow = new arrow;
	_arrow->init();

	_mainPlayer = NULL;

	return S_OK;
}
void bow::update()
{
	_arrow->update();
	//if (_itemState == THROW)
	//{
	//	//활의 상태가 쓰로우면 화살의 발사함수를 호출함
	//	_arrow->fire();

	//	
	//}
}

void bow::render()
{

	// _itemImage->render(getMemDC(), 150, 30);

	//화살의 상태가 발사면 화살을 그려라
	if (_arrow->getState() == THROW)
	{
		_arrow->render();
	}
}

void bow::fire(float x, float y, int direction){
	_arrow->fire(x,y,direction);
}