#pragma once
#include "singletonBase.h"
#include "aStarTile.h"
#include "tile_inGame.h"
#include <map>	
#include <vector>

struct tagAStarMap
{
	int tileX;
	int tileY;
	vector<aStarTile*> vAstarTiles;
};

typedef map < string, tagAStarMap> mAStarInfo;

class aStarMapInfo	:public singletonBase<aStarMapInfo>
{

private:
	
	mAStarInfo _mAStarInfo;
	vector<aStarTile*>* _currentAstar;
	int _currentAStarTileX;
	int _currentAStarTileY;
	
public:
	aStarMapInfo();
	~aStarMapInfo();

	HRESULT init(string key, int xSize, int ySize, vector<tile_inGame*>* vtile);
	void update();
	void loadMapInfo();

	void changeAstar(string key) {
		auto aStar = _mAStarInfo.find(key);
		if (aStar == _mAStarInfo.end()) return;

		_currentAstar = &aStar->second.vAstarTiles;
		_currentAStarTileX = aStar->second.tileX;
		_currentAStarTileY = aStar->second.tileY;
	}

	vector<aStarTile*>* getcurrentAStar() { return _currentAstar; }
	POINT getcurrentSize() { return { _currentAStarTileX,_currentAStarTileY }; }
};
