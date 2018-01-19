
#pragma once
#include "gameNode.h"
#include "tileNode.h"

class tile : public gameNode
{
private:
	
	POINT index;
	RECT rc;

	tagTile_tr _terrain;
	tagTile_obj _object;
	
	bool _objectRender;

	int _pathDetect; //길찾기 변수;
public:
	tile();
	~tile();

	HRESULT init(int indexX, int indexY);
	void release(void);
	void update(void);
	void render(void);
	void Toolrender(HDC hdc ,int cameraX, int cameraY);

	int getIdX(void) { return index.x; }
	int getIdY(void) { return index.y; }

	RECT getRect() { return rc; }

	void setObjectRender(bool state) { _objectRender = state; }

	void setPathDetector(int detector) { _pathDetect += detector; }

	POINT getCenter() { return { (rc.left + rc.right) / 2,(rc.top + rc.bottom) / 2 }; }

	void setTerrain(tagTile_tr terrain) { _terrain = terrain; }
	void setObject(tagTile_obj obj) { _object = obj; }


};
