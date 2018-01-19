#pragma once
#include "gameNode.h"
#include "GreenSolider.h"
#include <vector>

class enemyManager :	public gameNode
{
private:

	vector<enemyParent*> _vEnemy;
	vector<enemyParent*>::iterator _viEnemy;

	enemyParent* _GreenSolider;
public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();
};

