#pragma once
#include "gameNode.h"
#include"enemyManager.h"
#include "inventory.h"
#include "player.h"
#include "shop.h"
#include "redEye.h"

class mainGame : public gameNode
{
private:

	//��� �����(��ȣ)
	inventory* _inven;

	//��� �����(��ȣ)
	player* _mainPlayer;

	//���� �����(��ȣ)
	shop* _shop;

	//
	enemyParent* _redEye;

	//�� �����(����)
	enemyManager* _em;



public:
	virtual HRESULT init();			
	virtual void release();			
	virtual void update();			
	virtual void render();	


	mainGame();
	~mainGame();
};

