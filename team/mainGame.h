#pragma once
#include "gameNode.h"
#include"enemyManager.h"
#include "inventory.h"
#include "player.h"
#include "shop.h"
#include "redEye.h"
#include "objectParent.h"
#include "bottle.h"
#include "box.h"
#include "gbox.h"
#include "stone.h"
#include "bush.h"
#include "saveLoad.h"
#include "nameInput.h"
#include "objectManager.h"


class mainGame : public gameNode
{
private:

	//�÷��̾�(��ȣ)
	player* _player;

	//��� �����(��ȣ)
	inventory* _inven;

	//��� �����(��ȣ)
	//player* _mainPlayer;

	//���� �����(��ȣ)
	shop* _shop;

	//
	enemyParent* _redEye;

	//�� �����(����)
	enemyManager* _em;

	//������Ʈ �����(����)
	objectParent* _bottle;
	objectParent* _box;	
	objectParent* _gbox;
	objectParent* _bush;
	objectParent* _stone;

	objectManager* _om;

	//UI(ġ��)
	gameNode* _show;
	gameNode* _saveLoad;
	gameNode* _nameInput;
	gameNode* _title;
	//gameNode* �ΰ���

public:
	virtual HRESULT init();			
	virtual void release();			
	virtual void update();			
	virtual void render();	


	mainGame();
	~mainGame();
};

