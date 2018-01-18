#pragma once
#include "gameNode.h"
#include "inventory.h"
#include "player.h"

class mainGame : public gameNode
{
private:

	//출력 실험용(재호)
	inventory* _inven;

	//통신 실험용(재호)
	player* _mainPlayer;

public:
	virtual HRESULT init();			
	virtual void release();			
	virtual void update();			
	virtual void render();	


	mainGame();
	~mainGame();
};

