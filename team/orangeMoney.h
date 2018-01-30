#pragma once
#include "itemParent.h"
class orangeMoney :
	public itemParent
{
public:
	orangeMoney();
	~orangeMoney();

	virtual HRESULT init(int x, int y);
	virtual void render();
};

