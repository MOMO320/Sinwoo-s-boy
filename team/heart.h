#pragma once
#include "itemParent.h"
class heart :
	public itemParent
{
public:
	heart();
	~heart();

	virtual HRESULT init(int x, int y);
	//virtual void release();
	//virtual void update();
	virtual void render();

};

