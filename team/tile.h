#pragma once
#include "gameNode.h"
#include "tileNode.h"


class tile : public gameNode
{
private:
	
	POINT index;
	RECT rc;

	tagTile_tr* _terrain;
	tagTile_obj* _object;
	



public:
	tile();
	~tile();

	HRESULT init(int indexX, int indexY);
	void release(void);
	void update(void);
	void render(void);
	void Toolrender(void);

	int getIdX(void) { return index.x; }
	int getIdY(void) { return index.y; }

	RECT getRect() { return rc; }

	POINT getCenter() { return { (rc.left + rc.right) / 2,(rc.top + rc.bottom) / 2 }; }

	void setTerrain(tagTile_tr* terrain) { _terrain = terrain; }
	void setObject(tagTile_obj* obj) { _object = obj; }


};

