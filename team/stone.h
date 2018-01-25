#pragma once
#include "objectParent.h"

class stone : public objectParent
{
private:

public:
	stone();
	~stone();

	player * _player;

	HRESULT init(POINT point, player* player);
	void render();
	void update();

	virtual void move();

};

