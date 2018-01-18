#pragma once
#include "gameNode.h"
#include "GreenSolider.h"
class enemyManager :	public gameNode
{
private:
	GreenSolider* _GreenSolider;
public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();
};

