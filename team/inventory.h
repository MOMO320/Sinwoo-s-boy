#pragma once
#include "gameNode.h"
#include "bow.h"
class inventory :
	public gameNode
{

	itemParent* _bow;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	inventory();
	~inventory();
};

