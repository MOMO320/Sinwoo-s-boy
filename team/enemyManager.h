#pragma once
#include "gameNode.h"
#include "GreenSolider.h"
#include "BlueSolider.h"
#include "MaceKnight.h"
#include "BOSS.h"
#include "effect.h"
#include "blueMoney.h"
#include "orangeMoney.h"
#include "redMoney.h"
#include <vector>

class player;
class objectManager;
class inventory;

class enemyManager :public gameNode
{
private:
	effect* _effect;
	vector<enemyParent*> _vEnemy;
	vector<enemyParent*>::iterator _viEnemy;

	vector<itemParent*> _vMoney;
	vector<itemParent*> _viMoney;

	vector<int*> _vAgro;
	vector<int*>::iterator _viAgro;

private:
	player* _player;
	objectManager* _om;
	enemyParent* _GreenSolider;
	enemyParent* _BlueSolider;
	enemyParent* _Mace;
	enemyParent* _boss;
	int _backMoveCount;

	//소지금을 올리기 위한 인벤토리 변수
	inventory* _inven;

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
	void setBoss(POINT pos);
	void collision();
	void crrentHPCheck();
	void removeEnemy(int arrNum);
	void removeAll();

	void setAddressLinkPlayer(player* player) { _player = player; }
	void setAddressLinkObjectManager(objectManager* objectManager) { _om = objectManager; }
	void setAddressLinkInventory(inventory* inven){ _inven = inven; }

	vector<enemyParent*> getVEnemy() { return _vEnemy; }

	void removeMoney(int arrNum);
	void moneyCollision();

};

