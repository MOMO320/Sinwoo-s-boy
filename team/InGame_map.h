#pragma once
#include "gameNode.h"
#include "tileNode.h"
#include "tile_inGame.h"
#include <map>;
#include <vector>;




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

struct tagMap
{
	vector<tile_inGame*> vTile;
	string mapName;
	int tileX, tileY;
	vector<tagCharPos*> vPos;
};

class InGame_map : public gameNode
{
private:
	typedef vector<tile_inGame*> vTiles;
	typedef map<string, tagMap> mapMap;
private:
	mapMap	_mMapInfo;

	string	_currentMapName;	//current 맵 key
	int		_tileXN;			//현재 맵의 x타일개수
	int		_tileYN;			//현재 맵의 y타일개수
	vTiles*	_currentMapTile;	//현재 맵의 타일 벡터
	vector<tagCharPos*>* _currentPos;



public:
	InGame_map();
	~InGame_map();

	HRESULT init();
	void release();
	void update();
	void render();

	void loadMap();
	void changeMap(string mapkey);

	vector<tagCharPos*>* getCurrentPos() { return _currentPos; }
};

