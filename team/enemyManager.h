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

	int _backMoveCount;

	char str[128];
public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();
	void collision();
};

