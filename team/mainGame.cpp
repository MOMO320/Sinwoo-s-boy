#include "stdafx.h"
#include "mainGame.h"

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

	_player = new player;
	_player->init();

	//��� �����(��ȣ)
	_inven = new inventory;
	_inven->init();

	_shop = new shop;
	_shop->init();

	/*_mainPlayer = new player;
	_mainPlayer->init();*/

	_em = new enemyManager;
	_em->init();

	_redEye = new redEye;
	_redEye->init();

	_bottle = new bottle;
	_bottle->init(PointMake(100, 400));
	_box = new box;
	_box->init(PointMake(200, 400));
	_gbox = new gbox;
	_gbox->init(PointMake(300, 400));
	_bush = new bush;
	_bush->init(PointMake(400, 400));
	_stone = new stone;
	_stone->init(PointMake(500, 400));

	//_mainPlayer->setInventoryMemoryAddressLink(_inven);
	_inven->setPlayerMemoryAddressLink(_player);
	_shop->setInvenAddressLink(_inven);
	_shop->setPlayerAddressLink(_player);

	return S_OK;
}

void mainGame::release()			//�޸� ���� �Լ�
{
	gameNode::release();

	
}

void mainGame::update()				//���� �Լ�
{
	gameNode::update();

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
		_redEye->update();

		_shop->update();

		_player->update();

		for (int i = 0; i < _inven->getInvenItem().size(); i++)
		{
			_inven->getInvenItem()[i]->update();
		}
	}
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

	//��� �����(��ȣ)
	if (_inven->getInvenOpen())
	{
		_inven->render();
	}
	else
	{
		_em->render();
		_redEye->render();
	_em->render();
	_redEye->render();

	_shop->render();
	_player->render();
	_bottle->render();
	_box->render();
	_gbox->render();
	_bush->render();
	_stone->render();
	}
	//==================== �ǵ������� =======================
	
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
