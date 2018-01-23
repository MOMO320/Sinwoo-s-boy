#pragma once
#include "objectParent.h"

class bottle : public objectParent
{
public:
	bottle();
	~bottle();

	HRESULT init(POINT point);
	void render();

	virtual void move();
};

