#pragma once
#include "objectParent.h"

class box : public objectParent
{
private:

public:
	box();
	~box();

	HRESULT init(POINT point, player* player);

	void render();
	void update();

	virtual void open();

};

