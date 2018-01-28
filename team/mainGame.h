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

	//플레이어(태호)
	player* _player;

	//출력 실험용(재호)
	inventory* _inven;

	//통신 실험용(재호)
	//player* _mainPlayer;

	//상점 실험용(재호)
	shop* _shop;

	//
	enemyParent* _redEye;

	//적 실험용(태현)
	enemyManager* _em;

	//오브젝트 실험용(수빈)
	objectParent* _bottle;
	objectParent* _box;	
	objectParent* _gbox;
	objectParent* _bush;
	objectParent* _stone;

	objectManager* _om;

	//UI(치송)
	gameNode* _show;
	gameNode* _saveLoad;
	gameNode* _nameInput;
	gameNode* _title;
	//gameNode* 인게임

public:
	virtual HRESULT init();			
	virtual void release();			
	virtual void update();			
	virtual void render();	


	mainGame();
	~mainGame();
};

