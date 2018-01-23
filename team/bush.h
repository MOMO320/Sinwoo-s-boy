#pragma once
#include "objectParent.h"

class bush : public objectParent
{
public:
	bush();
	~bush();

	HRESULT init(POINT point);
	void render();

	virtual void move();
	virtual void hide();
};

