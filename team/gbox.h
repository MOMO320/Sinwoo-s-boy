#pragma once
#include "objectParent.h"

class gbox : public objectParent
{
private:

	//player* _play;

public:
	gbox();
	~gbox();

	HRESULT init(POINT point, player* player);
	void render();
	void update();

	virtual void open();

};

