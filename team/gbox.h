#pragma once
#include "objectParent.h"

class gbox : public objectParent
{
public:
	gbox();
	~gbox();

	HRESULT init(POINT point);
	void render();
	void update();

	virtual void open();

};

