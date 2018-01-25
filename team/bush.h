#pragma once
#include "objectParent.h"

class bush : public objectParent
{
private:

public:
	bush();
	~bush();

	player * _player;

	HRESULT init(POINT point, player* player);
	void render();
	void update();

	virtual void move();
	//virtual void hide();

};

