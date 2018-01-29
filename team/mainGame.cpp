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
	IMAGEMANAGER->addImage("UI����", "image/UI/number.bmp", 210, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�Ϲ�UI", "image/UI/number.bmp", 750, 147, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����UI", "image/UI/number.bmp", 750, 147, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ü��", "image/UI/heart.bmp", 126, 42, true, RGB(255, 0, 255));

	SCENEMANAGER->addScene("����", new saveLoad);
	SCENEMANAGER->addScene("�Է�â", new nameInput);
	//SCENEMANAGER->addScene("Ÿ��Ʋ", new title);
	//SCENEMANAGER->addScene("�ΰ���", new �ΰ���);
	SCENEMANAGER->changeScene("Ÿ��Ʋ");


	_player = new player;
	_player->init();

	//��� �����(��ȣ)
	_inven = new inventory;
	_inven->init();

	_shop = new shop;
	_shop->init();

	_om = new objectManager;
	_om->init(_player);

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
	_gbox->init(PointMake(800, 1100), _player);
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
	_bush->setPlayerAddressLink(_player);
	_stone->setPlayerAddressLink(_player);

	//���� �ε� �׽�Ʈ
//	_map = new InGame_map;
//	_map->init();

	return S_OK;
}

void mainGame::release()			//�޸� ���� �Լ�
{
	gameNode::release();

	
}

void mainGame::update()				//���� �Լ�
{
	gameNode::update();

	SCENEMANAGER->update();

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
		_bottle->update();
		_box->update();
		_gbox->update();
		_bush->update();
		_stone->update();

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
//	_map->update();
}

void mainGame::render()		//�׷��ִ� �Լ�(a.k.a WM_PAINT)
{
	//��� ��ȭ�� ����~
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================== �ǵ������� ======================

	IMAGEMANAGER->findImage("ī�޶��׽�Ʈ���")->render(getMemDC(), 0, 0, CAMERAMANAGER->getCameraPoint().x, CAMERAMANAGER->getCameraPoint().y, WINSIZEX, WINSIZEY);

	char str[128];
	sprintf(str, "���ΰ����������Դϴ�.");
	TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));
	//�� �׽�Ʈ -> ����
//	_map->render();
	SCENEMANAGER->render();

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
	_bottle->render();
	_box->render();
	_gbox->render();
	_bush->render();
	_stone->render();

	_om->render();

	}

	
	//==================== �ǵ������� =======================
	
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
