#pragma once
#include "gameNode.h"
#include"enemyManager.h"
#include "inventory.h"
#include "player.h"
#include "shop.h"
#include "redEye.h"
#include "objectParent.h"
#include "bottle.h"

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
	objectParent* _ob;




public:
	virtual HRESULT init();			
	virtual void release();			
	virtual void update();			
	virtual void render();	


	mainGame();
	~mainGame();
};

