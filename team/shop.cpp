#include "stdafx.h"
#include "shop.h"
#include "heart.h"
#include "HPMaterial.h"
#include "arrow.h"

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

	itemParent* shopArrow = new arrow;
	shopArrow->init(900, WINSIZEY / 2 + 20);

	_vShopItem.push_back(shopArrow);

	_testRC = RectMakeCenter(500, WINSIZEY - 100, 50, 50);
	return S_OK;
}
void shop::release()
{

}
void shop::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_testRC.top -= 3;
		_testRC.bottom = _testRC.top + 50;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_testRC.right += 3;
		_testRC.left = _testRC.right - 50;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_testRC.top += 3;
		_testRC.bottom = _testRC.top + 50;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_testRC.right -= 3;
		_testRC.left = _testRC.right - 50;
	}
	for (int i = 0; i < _vShopItem.size(); ++i)
	{
		//구매해서 사라진 아이템이면 아무것도 하지 마라
		if (!_vShopItem[i]->getIsVisible()) continue;

		RECT temp;
		if (KEYMANAGER->isOnceKeyDown('Z') &&
			IntersectRect(&temp, &_testRC, &_vShopItem[i]->getRC()))
		{
			_vShopItem[i]->setIsVisible(false);
		}
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
			Rectangle(getMemDC(), _vShopItem[i]->getRC().left, _vShopItem[i]->getRC().top, _vShopItem[i]->getRC().right, _vShopItem[i]->getRC().bottom);
		}
	}
	Rectangle(getMemDC(), _testRC.left, _testRC.top, _testRC.right, _testRC.bottom);
}