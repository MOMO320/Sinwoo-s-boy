#include "stdafx.h"
#include "mainGame.h"
#include "title.h"

mainGame::mainGame()
{
}

mainGame::~mainGame()
{
}

HRESULT mainGame::init()			//�ʱ�ȭ �Լ�
{
	gameNode::init();
	
	
	IMAGEMANAGER->addImage("ī�޶��׽�Ʈ���", "./image/playerImage/background03.bmp", 2400, 1200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������", "image/UI/black.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Ŀ������", "image/UI/fairy.bmp", 96, 48, 2, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("�빮��", "image/UI/�빮��.bmp", 459, 30, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ҹ���", "image/UI/�ҹ���.bmp", 364, 30, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("UI����", "image/UI/number.bmp", 210, 21,10,1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�Ϲ�UI", "image/UI/number.bmp", 750, 147, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����UI", "image/UI/number.bmp", 750, 147, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("UI����", "image/UI/number.bmp", 210, 21,10,0, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�Ϲ�UI", "image/UI/UI(nomal).bmp", 750, 147, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����UI", "image/UI/UI(dungeon).bmp", 750, 147, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("ü��", "image/UI/heart.bmp", 126, 42, true, RGB(255, 0, 255));

	SCENEMANAGER->addScene("����", new saveLoad);
	SCENEMANAGER->addScene("�Է�â", new nameInput);
	//SCENEMANAGER->addScene("������", new shopScene);
	//SCENEMANAGER->addScene("Ÿ��Ʋ", new title);
	//SCENEMANAGER->addScene("�ΰ���", new �ΰ���);
	//SCENEMANAGER->changeScene("Ÿ��Ʋ");


	_player = new player;
		/*
	for (int i = 0; i < (*IGMAP->getCurrentPos()).size(); ++i) {

		if ((*IGMAP->getCurrentPos())[i]->CHAR_INDEX == CHARACTER_PLAYER_POS) {
			_player->init((*IGMAP->getCurrentPos())[i]->index);
		}

	}*/
	
	//��� �����(��ȣ)
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

	//SCENEMANAGER->changeScene("������",_player,_inven);


	//_bottle->setPlayerAddressLink(_player);
	//_bush->setPlayerAddressLink(_player);
	//_stone->setPlayerAddressLink(_player);


	//���� �ε� �׽�Ʈ

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

void mainGame::release()			//�޸� ���� �Լ�
{
	gameNode::release();

	
}

void mainGame::update()				//���� �Լ�
{
	gameNode::update();
	IGMAP->update();
	//SCENEMANAGER->update();

	if (IGMAP->isCurrentMap("shop"))
	{
		_shop->update();
	}

	//�齺���̽��� ����
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		//�κ��� �ȿ���������
		if (!_inven->getInvenOpen())
		{
			//�κ��� �����
			_inven->setInvenOpen(true);
		}

		//�κ��� ����������
		else
		{
			//�ݾƶ�
			_inven->setInvenOpen(false);
		}
	}
	//�κ��� ������������ ������Ʈ ����
	if (_inven->getInvenOpen())
	{
		_inven->update();
	}
	//�κ��� �������� �ʴٸ� �ٸ� ������Ʈ�� ����
	else
	{
		_em->update();
		//_redEye->update();

		_shop->update();

		_player->update();

		_om->update();
		//�������� �����۸� ������Ʈ
		if (_player->getQuickItem() != NULL)
		_player->getQuickItem()->update();
		/*for (int i = 0; i < _inven->getInvenItem().size(); i++)
		{
			if (_inven)
			_inven->getInvenItem()[i]->update();
		}*/
	}

	//�� �׽�Ʈ -> ������Ʈ
}

void mainGame::render()		//�׷��ִ� �Լ�(a.k.a WM_PAINT)
{
	//��� ��ȭ�� ����~
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================== �ǵ������� ======================

	//IMAGEMANAGER->findImage("ī�޶��׽�Ʈ���")->render(getMemDC(), 0, 0, CAMERAMANAGER->getCameraPoint().x, CAMERAMANAGER->getCameraPoint().y, WINSIZEX, WINSIZEY);
	IGMAP->render(getMemDC());
	char str[128];
	sprintf(str, "���ΰ����������Դϴ�.");
	TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));
	//SCENEMANAGER->render();

	//��� �����(��ȣ)
	if (_inven->getInvenOpen())
	{
		_inven->render();
	}
	else
	{

		//������ ���� ���󰡴� ����
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

	IMAGEMANAGER->findImage("�Ϲ�UI")->render(getMemDC());

	//����Ʈ

	IMAGEMANAGER->findImage("UI����")->frameRender(getMemDC(), 80, 40, (_inven->getMoney() / 100), 0);

	IMAGEMANAGER->findImage("UI����")->frameRender(getMemDC(), 104, 40, (_inven->getMoney() % 100) / 10, 0);

	IMAGEMANAGER->findImage("UI����")->frameRender(getMemDC(), 128, 40, (_inven->getMoney() % 10), 0);





	//ȭ����Ʈ



	IMAGEMANAGER->findImage("UI����")->frameRender(getMemDC(), 242, 40, _inven->getBow()->getArrow()->getCount() / 10, 0);

	IMAGEMANAGER->findImage("UI����")->frameRender(getMemDC(), 266, 40, _inven->getBow()->getArrow()->getCount() % 10, 0);



	//��ź��Ʈ

	for (int i = 0; i < 2; ++i)

	{

		IMAGEMANAGER->findImage("UI����")->frameRender(getMemDC(), 168 + (i * 24), 40, 0, 0);

	}

	ASTARINFO->render(getMemDC());
	
	//==================== �ǵ������� =======================
	
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
