#pragma once
#include "gameNode.h"
class inventory :
	public gameNode
{
public:

	HRESULT init();
	void release();
	void update();
	void render();

	inventory();
	~inventory();
};

