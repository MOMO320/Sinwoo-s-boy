#include "stdafx.h"
#include "mainGame.h"

mainGame::mainGame()
{
}

mainGame::~mainGame()
{
}

HRESULT mainGame::init()			//초기화 함수
{
	gameNode::init();
	
	//출력 실험용(재호)
	_inven = new inventory;
	_inven->init();

	_shop = new shop;
	_shop->init();

	_mainPlayer = new player;
	_mainPlayer->init();

	_em = new enemyManager;
	_em->init();

	//_mainPlayer->setInventoryMemoryAddressLink(_inven);
	_inven->setPlayerMemoryAddressLink(_mainPlayer);
	_shop->setInvenAddressLink(_inven);

	return S_OK;
}

void mainGame::release()			//메모리 해제 함수
{
	gameNode::release();

	
}

void mainGame::update()				//연산 함수
{
	gameNode::update();

	//백스페이스로 오픈
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		//인벤이 안열려있으면
		if (!_inven->getInvenOpen())
		{
			//인벤을 열어라
			_inven->setInvenOpen(true);
		}

		//인벤이 열려있으면
		else
		{
			//닫아라
			_inven->setInvenOpen(false);
		}
	}
	//인벤이 열려있을때만 업데이트 진행
	if (_inven->getInvenOpen())
	{
		_inven->update();
	}
	_em->update();

	_shop->update();
}

void mainGame::render()		//그려주는 함수(a.k.a WM_PAINT)
{
	//흰색 도화지 한장~
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================== 건들지마라 ======================

	char str[128];
	sprintf(str, "메인게임페이지입니다.");
	TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));

	//출력 실험용(재호)
	if (_inven->getInvenOpen())
	{
		_inven->render();
	}
	_em->render();

	_shop->render();
	//==================== 건들지마라 =======================
	
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
