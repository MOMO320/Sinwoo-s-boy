#pragma once
#include "itemParent.h"
class potion :
	public itemParent
{
	bool _isFull;	//병에 무언가 담겨있는가
public:
	potion();
	~potion();

	virtual HRESULT init();
	virtual void update();
	virtual void render();
};

