#pragma once
#include "gameNode.h"

class drawArea : public gameNode
{
private:

public:
	drawArea();
	~drawArea();

	HRESULT init();
	void release();
	void update();
	void render();
};

