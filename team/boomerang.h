#pragma once
#include "itemParent.h"
class boomerang :
	public itemParent
{
public:
	boomerang();
	~boomerang();

	virtual HRESULT init();
	virtual void render();

};

