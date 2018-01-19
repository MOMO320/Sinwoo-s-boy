#pragma once
#include "SelectTile.h"
class Select_Obj : public SelectTile
{
public:
	Select_Obj();
	~Select_Obj();

	HRESULT init();
	void release();
	void update();
	void render();
};

