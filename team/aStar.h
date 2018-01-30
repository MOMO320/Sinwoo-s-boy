#pragma once
#include "gameNode.h"
#include "aStarTile.h"
#include <vector>
#include <string>


class aStar : public gameNode
{
private:
	// 전체 타일 
	vector<aStarTile*> _vTotalList;
	vector<aStarTile*>::iterator _viTotalList;

	// 열려 있는 타일
	vector<aStarTile*> _vOpenList;
	vector<aStarTile*>::iterator _viOpenList;

	vector<aStarTile*> _vCloseList;
	vector<aStarTile*>::iterator _viCloseList;

	aStarTile* _startTile;
	aStarTile* _endTile;
	aStarTile* _currentTile;

	int _count;
	bool _start;


public:
	aStar();
	~aStar();

	HRESULT init(int enemyPosX, int enemyPosY, int playerPosX, int playerPosY);
	void release();
	void update();
	void render();
	void setTiles(int enemyPosX, int enemyPosY, int playerPosX, int playerPosY);
	aStarTile* getNextTile() { }
	void pathFinder(aStarTile* currentTile);
	vector<aStarTile*> addOpenList(aStarTile* currentTile);
	
};

