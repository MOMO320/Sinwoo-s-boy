#pragma once
#include "objectParent.h"

class gbox : public objectParent
{
public:
	gbox();
	~gbox();

	HRESULT init(POINT point);
	void render();

	virtual void open();

};

