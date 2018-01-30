#pragma once
#include "gameNode.h"
#include "GreenSolider.h"
#include "BlueSolider.h"
#include "MaceKnight.h"
#include "effect.h"
#include <vector>

class player;
class objectManager;

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
	objectManager* _om;
	enemyParent* _GreenSolider;
	enemyParent* _BlueSolider;
	enemyParent* _Mace;
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
	void setGreenSolider(POINT pos, vector<POINT>* vPatrol);
	void setBlueSolider();
	void setMace();
	void collision();
	void crrentHPCheck();
	void removeEnemy(int arrNum);
	void removeAll();
	void setAddressLinkPlayer(player* player) { _player = player; }
	void setAddressLinkObjectManager(objectManager* objectManager) { _om = objectManager; }
	vector<enemyParent*> getVEnemy() { return _vEnemy; }

};

