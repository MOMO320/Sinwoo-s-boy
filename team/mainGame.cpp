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
	
	IMAGEMANAGER->addImage("카메라테스트배경", "./image/playerImage/background03.bmp", 2400, 1200, true, RGB(255, 0, 255));

	_player = new player;
	_player->init();

	//출력 실험용(재호)
	_inven = new inventory;
	_inven->init();

	_shop = new shop;
	_shop->init();

	/*_mainPlayer = new player;
	_mainPlayer->init();*/

	_em = new enemyManager;
	_em->init();

	_redEye = new redEye;
	//_redEye->init();

	_bottle = new bottle;
	_bottle->init(PointMake(600, 1000),_player);
	_box = new box;
	_box->init(PointMake(700, 1000), _player);
	_gbox = new gbox;
	_gbox->init(PointMake(800, 1000), _player);
	_bush = new bush;
	_bush->init(PointMake(900, 1000), _player);
	_stone = new stone;
	_stone->init(PointMake(1000, 1000), _player);

	//_mainPlayer->setInventoryMemoryAddressLink(_inven);
	_em->setAddressLinkPlayer(_player);
	_inven->setPlayerMemoryAddressLink(_player);
	_shop->setInvenAddressLink(_inven);
	_shop->setPlayerAddressLink(_player);

	_bottle->setPlayerAddressLink(_player);

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
	//인벤이 열려있지 않다면 다른 업데이트들 진행
	else
	{
		_em->update();
		//_redEye->update();

		_shop->update();

		_player->update();
		_bottle->update();
		_box->update();
		_gbox->update();
		_bush->update();
		_stone->update();

		//퀵슬롯의 아이템만 업데이트
		if (_player->getQuickItem() != NULL)
		_player->getQuickItem()->update();
		/*for (int i = 0; i < _inven->getInvenItem().size(); i++)
		{
			if (_inven)
			_inven->getInvenItem()[i]->update();
		}*/
	}
}

void mainGame::render()		//그려주는 함수(a.k.a WM_PAINT)
{
	//흰색 도화지 한장~
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================== 건들지마라 ======================

	IMAGEMANAGER->findImage("카메라테스트배경")->render(getMemDC(), 0, 0, CAMERAMANAGER->getCameraPoint().x, CAMERAMANAGER->getCameraPoint().y, WINSIZEX, WINSIZEY);

	char str[128];
	sprintf(str, "메인게임페이지입니다.");
	TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));

	//출력 실험용(재호)
	if (_inven->getInvenOpen())
	{
		_inven->render();
	}
	else
	{

		//아이템 사용시 날라가는 렌더
		if (_player->getQuickItem() != NULL)
		_player->getQuickItem()->render();

	//_shop->render();
	_em->render();
	//_redEye->render();
	_player->render();
	_bottle->render();
	_box->render();
	_gbox->render();
	_bush->render();
	_stone->render();
	}
	//==================== 건들지마라 =======================
	
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
