#pragma once
#include "gameNode.h"
#include "tileNode.h"

class tile_inGame : public gameNode
{
private:
	POINT index;
	RECT rc;

	//����
	iG_TR _terrain;
	//������Ʈ
	iG_OBJ _object;
	
	//����
	iG_DECO _deco[4];
	int weight;
	//�̺�Ʈ
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

