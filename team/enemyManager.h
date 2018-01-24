#pragma once
#include "gameNode.h"
#include "GreenSolider.h"
#include "BlueSolider.h"
#include <vector>

class player;

class enemyManager :public gameNode
{
private:

	vector<enemyParent*> _vEnemy;
	vector<enemyParent*>::iterator _viEnemy;

	vector<int*> _vAgro;
	vector<int*>::iterator _viAgro;

private:

	enemyParent* _GreenSolider;
	enemyParent* _BlueSolider;
	int _backMoveCount;

	char str[128];
public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();
	void setGreenSolider();
	void setBlueSolider();
	void collision();
	void removeEnemy(int arrNum);
};

