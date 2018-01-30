#pragma once
#include "singletonBase.h"
#include <map>;
#include <vector>;

class tileNode;
class tile_inGame;

typedef std::function<void(POINT)> playerInitF;
typedef std::function<void(void)> eraseAllEnemyF;
typedef std::function<void(POINT,vector<POINT>*)> initEnemyF;

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

struct tagMap
{
	vector<tile_inGame*> vTile;
	string mapName;
	int tileX, tileY;
	vector<tagCharPos*> vPos;
};

class InGame_map : public singletonBase<InGame_map>
{
private:
	typedef vector<tile_inGame*> vTiles;
	typedef map<string, tagMap> mapMap;
private:
	mapMap	_mMapInfo;

	string	_currentMapName;	//current �� key
	int		_tileXN;			//���� ���� xŸ�ϰ���
	int		_tileYN;			//���� ���� yŸ�ϰ���
	vTiles*	_currentMapTile;	//���� ���� Ÿ�� ����
	vector<tagCharPos*>* _currentPos;


	//�ݹ��Լ�
	initEnemyF initEnemyF[5];
	eraseAllEnemyF eraseEnemy;


public:
	InGame_map();
	~InGame_map();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void loadMap();
	void changeMap(string mapkey);

	vector<tagCharPos*>* getCurrentPos() { return _currentPos; }



	bool checkEvent(int tileX, int tileY);

	POINT getTileSize() { return { _tileXN,_tileYN }; }
};

