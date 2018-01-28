#pragma once
#include "gameNode.h"
#include "tileNode.h"
#include "tile_inGame.h"
#include <map>;
#include <vector>;


struct tagMap
{
	vector<tile_inGame*> vTile;
	string mapName;
	int tileX, tileY;
	vector<tagCharPos*> vPos;
};

struct tagCharPos
{
	CHARACTER CHAR_INDEX;
	string mapName;
	int index;
	string from;
	vector<POINT> vPatrol;

	tagCharPos()
	{
		CHAR_INDEX = CHARACTER_NONE;
		mapName = "";
		index = 0;
		from = "";
	}
};

class InGame_map
{
private:
	typedef map<string, tagMap> mapMap;
private:
	mapMap _mMapInfo;




public:
	InGame_map();
	~InGame_map();

	void loadMap();
};

