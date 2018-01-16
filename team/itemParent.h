#pragma once
#include "gameNode.h"
class itemParent :
	public gameNode
{
protected:
	image*	_itemImage;


public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	itemParent();
	~itemParent();
};

