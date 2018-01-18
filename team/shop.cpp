#include "stdafx.h"
#include "shop.h"
#include "heart.h"
#include "HPMaterial.h"

shop::shop()
{
}


shop::~shop()
{

}

HRESULT shop::init()
{
	//상점판매 아이템 벡터 저장
	itemParent* shopHPMaterial = new HPMaterial;
	shopHPMaterial->init(100,WINSIZEY/2);

	_vShopItem.push_back(shopHPMaterial);

	itemParent* shopHeart = new heart;
	shopHeart->init(500, WINSIZEY/2 + 20);

	_vShopItem.push_back(shopHeart);

	return S_OK;
}
void shop::release()
{

}
void shop::update()
{
	for (int i = 0; i < _vShopItem.size(); ++i)
	{
		
	}
}
void shop::render()
{
	for (int i = 0; i < _vShopItem.size(); ++i)
	{
		//아이템이 보이냐 --> 구매 아직 안됨 --> 그려라
		if (_vShopItem[i]->getIsVisible())
		{
			_vShopItem[i]->render();
		}
	}
}