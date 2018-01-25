#pragma once
#include "gameNode.h"
#include "aStarTile.h"
#include <vector>


class aStarMapInfo	: public gameNode
{
private:
	aStarTile* _aStarTile;
	int _mapSizeX;
	int _mapSizeY;
	int _tileNumX;
	int _tileNumY;
	int _tileSize;

public:
	aStarMapInfo();
	~aStarMapInfo();

	HRESULT init();
	void release();
	void update();
	void render();
	
	void loadMapInfo(int mapSizeX, int mapSizeY);
};

