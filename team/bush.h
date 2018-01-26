#pragma once
#include "objectParent.h"

class bush : public objectParent
{
private:

public:
	bush();
	~bush();

	HRESULT init(POINT point, player* player);
	void render();
	void update();

	virtual void move();
	//virtual void hide();

};

