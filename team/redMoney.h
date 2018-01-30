#pragma once
#include "itemParent.h"
class redMoney :
	public itemParent
{
public:
	redMoney();
	~redMoney();

	virtual HRESULT init(int x, int y);
	virtual void render();
};

