#pragma once
#include "gameNode.h"
class nameInput :
	public gameNode
{
public:
	nameInput();
	~nameInput();
	HRESULT init();
	void release();
	void update();
	void render();
};