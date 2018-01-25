#pragma once
#include "objectParent.h"

class box : public objectParent
{
public:
	box();
	~box();

	HRESULT init(POINT point);

	void render();
	void update();

	virtual void open();

};

