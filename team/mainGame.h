#pragma once
#include "gameNode.h"
#include "inventory.h"

class mainGame : public gameNode
{
private:
public:
	virtual HRESULT init();			
	virtual void release();			
	virtual void update();			
	virtual void render();	


	mainGame();
	~mainGame();
};

