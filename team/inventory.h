#pragma once
#include "gameNode.h"
#include "bow.h"
#include "boomerang.h"

class inventory :
	public gameNode
{

	itemParent* _bow;
	itemParent* _boomerang;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	inventory();
	~inventory();
};

