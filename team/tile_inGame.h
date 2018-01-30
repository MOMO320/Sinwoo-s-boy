#pragma once
#include "tileNode.h"

<<<<<<< HEAD
class tile_inGame 
=======
class tile_inGame
>>>>>>> f52a0dbee5c801b9b17e04b6f74b5dca5969b37d
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
	void render(HDC hdc);


	void loadTile(SAVELOAD_TILE loadTile);
	iG_OBJ getiGOBJ() { return _object; }
	iG_DECO getiGDECO() { return _deco[4]; }
	int getWeight() { return weight; }

	iG_EVENT getigEVENT() { return _event; }
};

