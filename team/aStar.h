#pragma once
#include "gameNode.h"
#include "aStarTile.h"
#include <vector>
#include <string>


class aStar : public gameNode
{
private:
	// ��ü Ÿ�� 
	vector<aStarTile*> _vTotalList;
	vector<aStarTile*>::iterator _viTotalList;

	// ���� �ִ� Ÿ��
	vector<aStarTile*> _vOpenList;
	vector<aStarTile*>::iterator _viOpenList;

	vector<aStarTile*> _vCloseList;
	vector<aStarTile*>::iterator _viCloseList;

	aStarTile* _startTile;
	aStarTile* _endTile;
	aStarTile* _currentTile;


public:
	aStar();
	~aStar();

	HRESULT init();

	void setTiles(int enemyIdX, int enemyIdY, int playerIdX, int playerIdY);

	//��ż���
	//vector<aStarTile*> addOpenList(aStarTile* currentTile);

	void pathFinder(aStarTile* currentTile);

	void release();
	void update();
	void render();
};

