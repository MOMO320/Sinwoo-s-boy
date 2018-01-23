#include "stdafx.h"
#include "itemParent.h"
#include "player.h"
#include "potion.h"

itemParent::itemParent()
{
}


itemParent::~itemParent()
{

}


HRESULT itemParent::init()
{

	return S_OK;
}

HRESULT itemParent::init(int x, int y) //상점판매를 위한 init 오버로드
{

	return S_OK;
}

void itemParent::release()
{

}
void itemParent::update()
{

}
void itemParent::render()
{
	TextOut(getMemDC(), 100, 100, "test", strlen("test"));
	//_itemImage->render(getMemDC(), 50, 50);
}

void itemParent::useItem()
{
	//1. 퀵슬롯에 아이템이 들어감
	//2. 플레이어에서 Z키 입력시 이 함수 호출
	//3. HP포션일경우 피회복 무기일경우 투척 등
	/*
	POTION,		//포션
	MONEY,		//돈
	WEAPON,		//무기
	SHIELD		//방패
	*/

	// 튁슬롯이 안되있음 리턴
	if (_mainPlayer == NULL) return;

	//포션 아이템 사용
	if (_itemType == POTION)
	{
		//포션이 차있을경우 --> HP포션상태
		if (dynamic_cast<potion*>(this)->getIsFull())
		{
			dynamic_cast<potion*>(this)->setIsFull(false);
		}
	}
	//무기일경우 어떻게 할것인가 .........................
}