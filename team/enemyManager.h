#pragma once
#include "gameNode.h"
#include "GreenSolider.h"
#include "BlueSolider.h"
#include "effect.h"
#include <vector>

class player;

class enemyManager :public gameNode
{
private:
	effect* _effect;
	vector<enemyParent*> _vEnemy;
	vector<enemyParent*>::iterator _viEnemy;

	vector<int*> _vAgro;
	vector<int*>::iterator _viAgro;

private:
	player* _player;
	enemyParent* _GreenSolider;
	enemyParent* _BlueSolider;
	int _backMoveCount;

	char str[128];
	char str2[128];
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
	void setAddressLinkPlayer(player* player) { _player = player; }

	vector<enemyParent*> getVEnemy() { return _vEnemy; }

};

