#pragma once
#include "gameNode.h"
#include "tileNode.h"

class tile_inGame : public gameNode
{
private:
	POINT index;
	RECT rc;

	//지형
	iG_TR _terrain;
	//오브젝트
	iG_OBJ _object;
	
	//데코
	iG_DECO _deco[4];
	int weight;
	//이벤트
	iG_EVENT _event;

	int timeCount;

public:
	tile_inGame();
	~tile_inGame();


	HRESULT init(int x, int y);
	void release();
	void update();
	void render();


	void loadTile(SAVELOAD_TILE loadTile);
};

