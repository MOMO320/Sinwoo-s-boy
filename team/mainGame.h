#pragma once
#include "gameNode.h"
#include"enemyManager.h"
#include "inventory.h"
#include "player.h"

class mainGame : public gameNode
{
private:

	//��� �����(��ȣ)
	inventory* _inven;

	//��� �����(��ȣ)
	player* _mainPlayer;

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

