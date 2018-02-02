#pragma once
#include "singletonBase.h"
#include <map>;
#include <vector>;

#define EVENTATTACK 111
#define EVENTPICK 112
#define EVENTBOX 113
#define EVENTMOVE 114
#define EVENTMAP 115
class tileNode;
class tile_inGame;
class player;

enum OBJPOSINDEX
{
	POS_BOTTLE,
	POS_BOX,
	POS_STONE,
	POS_GREATEBOX,
	POS_BUSH,
};



typedef std::function<void(POINT, player*)> objectInitF;
typedef std::function<void(POINT)> playerInitF;
typedef std::function<void(void)> eraseAllEnemyF;
typedef std::function<void(POINT,vector<POINT>*)> enemyInitF;
typedef std::function<void(void)> shopInit, objectClear;



struct tagCharPos
{
	CHARACTER CHAR_INDEX;
	string mapName;
	POINT index;
	string from;
	vector<POINT> vPatrol;


	tagCharPos()
	{
		CHAR_INDEX = CHARACTER_NONE;
		mapName = "";
		index = { -1,-1 };
		from = "";
	}
};

struct tagObjPos
{
	OBJPOSINDEX OPOSINDEX;
	string mapName;
	POINT index;
	
};

struct tagMap
{
	vector<tile_inGame*> vTile;
	string mapName;
	int tileX, tileY;
	vector<tagCharPos*> vPos;
	vector<tagObjPos*> vOPos;
};

class InGame_map : public singletonBase<InGame_map>
{
private:
	typedef vector<tile_inGame*> vTiles;
	typedef map<string, tagMap> mapMap;
private:
	mapMap	_mMapInfo;
	player* _player;
	string	_currentMapName;	//current 맵 key
	int		_tileXN;			//현재 맵의 x타일개수
	int		_tileYN;			//현재 맵의 y타일개수
	vTiles*	_currentMapTile;	//현재 맵의 타일 벡터
	vector<tagCharPos*>* _currentPos;
	vector<tagObjPos*>* _currentOPos;

	int _eventNum;
	//콜백함수
	playerInitF initPF,initFirst;
	enemyInitF addGreenSoldier, addBlueSoldier, addRedEye, addMace, addBoss;
	eraseAllEnemyF eraseEnemyF;
	shopInit shopInitF;
	objectInitF initBottle, initBox, initStone, initGBox, initBush;
	objectClear objClear;
	playerInitF playerMoveTo;
		//void setBottle(POINT pos, player* player);
		//void setBox(POINT pos, player* player);
		//void setStone(POINT pos, player* player);
		//void setGBox(POINT pos, player* player);
		//void setBush(POINT pos, player* player);

public:
	InGame_map();
	~InGame_map();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	bool isCurrentMap(string mapName) { if (!strcmp(_currentMapName.c_str(), mapName.c_str())) return true; else return false; }

	void loadMap();
	void changeMap(string mapkey);

	void setAddressLinkWithPlayer(player* p) { _player = p; }

	vector<tagCharPos*>* getCurrentPos() { return _currentPos; }

	void setShopInitF(shopInit func) { 
		shopInitF = move(func); 
	}


	void setEnemyInitF(enemyInitF Gs, enemyInitF bs) 
	{
		addGreenSoldier = move(Gs);
		addBlueSoldier = move(bs);
	}


	void setEraseEnemy(eraseAllEnemyF func) { 
		eraseEnemyF = move(func); 
	}
	void setPlayerInitF(playerInitF func) { 
		initPF = move(func); 
	}
	void setinitFirst(playerInitF func) {
		initFirst = move(func);
	}

	void setObjClear(objectClear func)
	{
		objClear = move(func);
	}

	void setInitObjectFunc(objectInitF bottle, objectInitF Box, objectInitF Stone, objectInitF GBox, objectInitF Bush)
	{
		initBottle = move(bottle);
		initBox = move(Box);
		initStone = move(Stone);
		initGBox = move(GBox);
		initBush = move(Bush);
	}
		//initBottle, initBox, initStone, initGBox, initBush
	void setPlayerMoveTo(playerInitF func)
	{
		playerMoveTo = move(func);
	}

	OBJECT checkAttackEvent(int tileX, int tileY, int eventNum);
	OBJECT checkPickEvent(int tileX, int tileY, int eventNum);
	void checkMapEvent(int tileX, int tileY, int eventNum );
	void checkMoveEvent(int tileX, int tileY, int eventNum);
	void checkJumpEvent(int tileX, int tileY);
	POINT getTileSize() { return { _tileXN,_tileYN }; }
};

