#pragma once
#include "SelectTile.h"
class Select_character : public SelectTile
{
public:
	Select_character();
	~Select_character();

	HRESULT init();
	void release();
	void update();
	void render();
};

