#pragma once
#include "gameNode.h"
class saveLoad :
	public gameNode
{
public:
	saveLoad();
	~saveLoad();
	HRESULT init();
	void release();
	void update();
	void render();

	void load();
	void save();
	void copy();
	void del();
};

