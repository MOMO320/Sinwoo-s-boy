#pragma once
#include "objectParent.h"

class stone : public objectParent
{
public:
	stone();
	~stone();

	HRESULT init(POINT point);
	void render();
	void update();

	virtual void move();

};

