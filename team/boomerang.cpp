#include "stdafx.h"
#include "boomerang.h"


boomerang::boomerang()
{
}


boomerang::~boomerang()
{
}

HRESULT boomerang::init(){


	
	/*
	image*	_itemImage;	//아이템 인벤토리 이미지
	float _x, _y;		//이미지의 중점

	bool _isVisible;	//인벤토리에서 이미지를 그릴것인지
	int _itemEffect;	//아이템 효과(포션 : 피회복, 무기 : 데미지 등등)

	tagItemType _itemType;		//아이템 종류
	tagItemState _itemState;	//아이템 상태
	*/

	//아이템 이미지
	_itemInvenImage = IMAGEMANAGER->addImage("boomerang", "./image/item/부메랑(인벤,슬롯).bmp",100,100, true, RGB(255, 0, 255));


	_isVisible = true;
	//_isVisible = false;
	_itemEffect = 1;
	_itemType = WEAPON;
	_itemState = IDLE;

	return S_OK;
}

void boomerang::render()
{
	//_itemImage->frameRender(getMemDC(), 250, 30);
}