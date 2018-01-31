#include "stdafx.h"
#include "mainGame.h"
#include "title.h"

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
	IMAGEMANAGER->addImage("암전용", "image/UI/black.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("커서요정", "image/UI/fairy.bmp", 96, 48, 2, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("대문자", "image/UI/대문자.bmp", 459, 30, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("소문자", "image/UI/소문자.bmp", 364, 30, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("UI숫자", "image/UI/number.bmp", 210, 21,10,1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("일반UI", "image/UI/number.bmp", 750, 147, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("던전UI", "image/UI/number.bmp", 750, 147, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("UI숫자", "image/UI/number.bmp", 210, 21,10,0, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("일반UI", "image/UI/UI(nomal).bmp", 750, 147, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("던전UI", "image/UI/UI(dungeon).bmp", 750, 147, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("체력", "image/UI/heart.bmp", 126, 42, true, RGB(255, 0, 255));

	SCENEMANAGER->addScene("파일", new saveLoad);
	SCENEMANAGER->addScene("입력창", new nameInput);
	//SCENEMANAGER->addScene("상점씬", new shopScene);
	//SCENEMANAGER->addScene("타이틀", new title);
	//SCENEMANAGER->addScene("인게임", new 인게임);
	//SCENEMANAGER->changeScene("타이틀");


	_player = new player;
		/*
	for (int i = 0; i < (*IGMAP->getCurrentPos()).size(); ++i) {

		if ((*IGMAP->getCurrentPos())[i]->CHAR_INDEX == CHARACTER_PLAYER_POS) {
			_player->init((*IGMAP->getCurrentPos())[i]->index);
		}

	}*/
	
	//출력 실험용(재호)
	_inven = new inventory;
	_inven->init();


	_om = new objectManager;
	_om->init(_player);

	/*_mainPlayer = new player;
	_mainPlayer->init();*/
	_shop = new shop;

	_em = new enemyManager;
	_em->init();
	IGMAP->init();
	_redEye = new redEye;
	//_redEye->init();

	_blueMoney = new blueMoney;
	_blueMoney->init(300,300);

	_redMoney = new redMoney;
	_redMoney->init(500,300);

	_orangeMoney = new orangeMoney;
	_orangeMoney->init(700,300);

	//_mainPlayer->setInventoryMemoryAddressLink(_inven);


	_player->setEmAddressMemeryLink(_em);
	_em->setAddressLinkPlayer(_player);
	_em->setAddressLinkObjectManager(_om);
	_om->setEmAddressMemoryLink(_em);
	_inven->setPlayerMemoryAddressLink(_player);
	_shop->setInvenAddressLink(_inven);
	_shop->setPlayerAddressLink(_player);

	//SCENEMANAGER->changeScene("상점씬",_player,_inven);


	//_bottle->setPlayerAddressLink(_player);
	//_bush->setPlayerAddressLink(_player);
	//_stone->setPlayerAddressLink(_player);


	//맵툴 로딩 테스트

	//IGMAP->changeMap("castleB1");

	/*for (int i = 0; i < IGMAP->getCurrentPos()->size(); ++i)
	{
		if ((*IGMAP->getCurrentPos())[i]->CHAR_INDEX == CHARACTER_GREENSOLDIER_POS)
		{
			_em->setGreenSolider((*IGMAP->getCurrentPos())[i]->index, &(*IGMAP->getCurrentPos())[i]->vPatrol);
		}
	}*/
	
	/*for (int i = 0;i< (*_map->getCurrentPos())[0]->vPatrol.size(); ++i)
	{
		_em->setGreenSolider((*_map->getCurrentPos())[0]->vPatrol[i]);
	}*/
	IGMAP->changeMap("shop");
		/*
		CHARACTER_NONE,
	CHARACTER_PLAYER_POS,
	CHARACTER_GREENEYE_POS,
	CHARACTER_REDEYE_POS,
	CHARACTER_JUMPKNIGHT_POS,
	CHARACTER_GREENSOLDIER_POS,
	CHARACTER_BLUESOLDIER_POS,
	CHARACTER_NPC_POS,
		*/
	return S_OK;
}

void mainGame::release()			//메모리 해제 함수
{
	gameNode::release();

	
}

void mainGame::update()				//연산 함수
{
	gameNode::update();
	IGMAP->update();
	//SCENEMANAGER->update();

	if (IGMAP->isCurrentMap("shop"))
	{
		_shop->update();
	}

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

		_om->update();
		//퀵슬롯의 아이템만 업데이트
		if (_player->getQuickItem() != NULL)
		_player->getQuickItem()->update();
		/*for (int i = 0; i < _inven->getInvenItem().size(); i++)
		{
			if (_inven)
			_inven->getInvenItem()[i]->update();
		}*/
	}

	//맵 테스트 -> 업데이트
}

void mainGame::render()		//그려주는 함수(a.k.a WM_PAINT)
{
	//흰색 도화지 한장~
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================== 건들지마라 ======================

	//IMAGEMANAGER->findImage("카메라테스트배경")->render(getMemDC(), 0, 0, CAMERAMANAGER->getCameraPoint().x, CAMERAMANAGER->getCameraPoint().y, WINSIZEX, WINSIZEY);
	IGMAP->render(getMemDC());
	char str[128];
	sprintf(str, "메인게임페이지입니다.");
	TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));
	//SCENEMANAGER->render();

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

	_om->render();

	_redMoney->render();
	_blueMoney->render();
	_orangeMoney->render();
	}
	if (IGMAP->isCurrentMap("shop"))
	{
		_shop->render();
	}

	IMAGEMANAGER->findImage("일반UI")->render(getMemDC());

	//돈파트

	IMAGEMANAGER->findImage("UI숫자")->frameRender(getMemDC(), 80, 40, (_inven->getMoney() / 100), 0);

	IMAGEMANAGER->findImage("UI숫자")->frameRender(getMemDC(), 104, 40, (_inven->getMoney() % 100) / 10, 0);

	IMAGEMANAGER->findImage("UI숫자")->frameRender(getMemDC(), 128, 40, (_inven->getMoney() % 10), 0);





	//화살파트



	IMAGEMANAGER->findImage("UI숫자")->frameRender(getMemDC(), 242, 40, _inven->getBow()->getArrow()->getCount() / 10, 0);

	IMAGEMANAGER->findImage("UI숫자")->frameRender(getMemDC(), 266, 40, _inven->getBow()->getArrow()->getCount() % 10, 0);



	//폭탄파트

	for (int i = 0; i < 2; ++i)

	{

		IMAGEMANAGER->findImage("UI숫자")->frameRender(getMemDC(), 168 + (i * 24), 40, 0, 0);

	}

	ASTARINFO->render(getMemDC());
	
	//==================== 건들지마라 =======================
	
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
