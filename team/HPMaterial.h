#pragma once
#include "itemParent.h"
class HPMaterial :
	public itemParent
{
public:
	HPMaterial();
	~HPMaterial();

	virtual HRESULT init(int x, int y);
	//virtual void release();
	//virtual void update();
	virtual void render();
};

