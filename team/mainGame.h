#pragma once
#include "gameNode.h"
#include "inventory.h"

class mainGame : public gameNode
{
private:

	//��� �����(��ȣ)
	inventory* _inven;

public:
	virtual HRESULT init();			
	virtual void release();			
	virtual void update();			
	virtual void render();	


	mainGame();
	~mainGame();
};

