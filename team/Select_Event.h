#pragma once
#include "SelectTile.h"
class Select_Event : public SelectTile
{
public:
	Select_Event();
	~Select_Event();

	HRESULT init();
	void release();
	void update();
	void render();
};

