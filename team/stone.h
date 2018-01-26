#pragma once
#include "objectParent.h"

class stone : public objectParent
{
private:

public:
	stone();
	~stone();

	HRESULT init(POINT point, player* player);
	void render();
	void update();

	virtual void move();

};

