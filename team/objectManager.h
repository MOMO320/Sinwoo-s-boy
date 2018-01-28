#pragma once
#include "gameNode.h"
#include "bottle.h"
#include "box.h"
#include "stone.h"
#include "gbox.h"
#include "bush.h"

class objectManager:public gameNode
{
private:
	objectParent* _bottle;
	objectParent* _box;
	objectParent* _gbox;
	objectParent* _bush;
	objectParent* _stone;
public:
	objectManager();
	~objectManager();
	
	HRESULT init(player* player);
	void release();
	void update();
	void render();

};

