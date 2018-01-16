#pragma once
#include "gameNode.h"
#include "tileNode.h"

#define TILESIZE 50

#define TILEX 5
#define TILEY 5

#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

struct tagtiles
{
	RECT rc;
};
class drawArea : public gameNode
{
private:
	int x, y;
	HWND _scrollvert;
	HWND _scrollhorz;
	tagtiles _tiles[TILEX * TILEY];

	int _tileX, _tileY; //타일인덱스 구하는 용도.
	int _position;  //현재 타일의 인덱스.
public:
	drawArea();
	~drawArea();

	HRESULT init();
	void release();
	void update();
	void render();
};

