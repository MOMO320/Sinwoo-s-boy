#pragma once
#include "itemParent.h"
class bow :
	public itemParent
{
public:
	bow();
	~bow();

	virtual HRESULT init();
	virtual void render();
};

