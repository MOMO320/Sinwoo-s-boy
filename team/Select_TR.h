#pragma once
#include "SelectTile.h"
class Select_TR : public SelectTile
{
public:
	Select_TR();
	~Select_TR();

	HRESULT init();
	void release();
	void update();
	void render();
};

