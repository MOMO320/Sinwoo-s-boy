#pragma once
#include "gameNode.h"
#include "inventory.h"

class mainGame : public gameNode
{
private:

	//출력 실험용(재호)
	inventory* _inven;

public:
	virtual HRESULT init();			
	virtual void release();			
	virtual void update();			
	virtual void render();	


	mainGame();
	~mainGame();
};

