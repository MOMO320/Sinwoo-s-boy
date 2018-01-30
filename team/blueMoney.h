#pragma once
#include "itemParent.h"
class blueMoney :
	public itemParent
{
public:
	blueMoney();
	~blueMoney();

	virtual HRESULT init(int x, int y);
	virtual void render();
};

