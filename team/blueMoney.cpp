#include "stdafx.h"
#include "blueMoney.h"


blueMoney::blueMoney()
{
}


blueMoney::~blueMoney()
{

}

HRESULT blueMoney::init(int x, int y)
{
	/*
	image*	_itemImage;			//아이템 투척 이미지(부메랑 등 프레임이 있는 이미지)
	image*  _itemInvenImage;	//아이템 인벤토리 이미지(단일)
	image*  _itemRightTopImage;	//아이템 인벤토리 우상단 이미지(단일)

	float _x, _y;		//이미지의 중점

	bool _isVisible;	//인벤토리에서 이미지를 그릴것인지
	int _itemEffect;	//아이템 효과(포션 : 피회복, 무기 : 데미지 등등)

	//상점판매 가격
	int _price;

	tagItemType _itemType;		//아이템 종류
	tagItemState _itemState;	//아이템 상태

	player* _mainPlayer;

	bool test1;
	char test2[120];
	
	*/
	_itemImage = _itemInvenImage = _itemRightTopImage
		= IMAGEMANAGER->addImage("bluemoney", "./image/item/bluemoney.bmp", 23, 46, true, RGB(255, 0, 255));

	_x = x; _y = y;

	//1원 습득
	_itemEffect = 1;

	_itemType = MONEY;
	_itemState = IDLE;

	return S_OK;
}

void blueMoney::render()
{
	_itemImage->render(getMemDC(),_x,_y);
}
