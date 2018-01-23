#pragma once
#include "SelectTile.h"
class Select_Deco : public SelectTile
{

public:
	Select_Deco();
	~Select_Deco();


	HRESULT init();
	void release();
	void update();
	void render();
};

