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
	
	//��� �����(��ȣ)
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
	_em->update();

	_shop->update();
}

void mainGame::render()		//�׷��ִ� �Լ�(a.k.a WM_PAINT)
{
	//��� ��ȭ�� ����~
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================== �ǵ������� ======================

	char str[128];
	sprintf(str, "���ΰ����������Դϴ�.");
	TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));

	//��� �����(��ȣ)
	if (_inven->getInvenOpen())
	{
		_inven->render();
	}
	_em->render();

	_shop->render();
	//==================== �ǵ������� =======================
	
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
