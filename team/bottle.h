#pragma once
#include "objectParent.h"

class bottle : public objectParent
{
private:

public:
	bottle();
	~bottle();

	player * _player;

	HRESULT init(POINT point, player* player);
	void render();
	void update();

	virtual void move();

};

