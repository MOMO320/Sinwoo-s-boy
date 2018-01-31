#include "stdafx.h"
#include "shopScene.h"


shopScene::shopScene()
{
}


shopScene::~shopScene()
{

}

HRESULT shopScene::init(player* mainPlayer, inventory* inven)
{
	_shop = new shop;
	_shop->init();

	_mainPlayer = new player;
	_mainPlayer = mainPlayer;

	_inven = new inventory;
	_inven = inven;

	_shop->setInvenAddressLink(_inven);
	_shop->setPlayerAddressLink(_mainPlayer);


	return S_OK;
}

void shopScene::release()
{

}

void shopScene::update()
{
	_shop->update();
}

void shopScene::render()
{
	_shop->render();
}
