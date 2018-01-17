#pragma once
#include "gameNode.h"
#include "bow.h"
#include "boomerang.h"
#include "potion.h"

class inventory :
	public gameNode
{

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

