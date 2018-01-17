#pragma once
#include "gameNode.h"
#include "bow.h"
#include "boomerang.h"
#include "potion.h"

#include <vector>

class inventory :
	public gameNode
{
	vector<itemParent*> _vItem;
	vector<itemParent*>::iterator _viItem;

	itemParent* _bow;
	itemParent* _boomerang;
	itemParent* _potion;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	inventory();
	~inventory();
};

