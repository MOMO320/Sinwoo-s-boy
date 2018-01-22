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
	void eraseTerrain() { _terrain.imageIndex = { 0,0 }; _terrain.isFrame = false; _terrain.TR_INDEX = TR_NONE; _terrain._image = NULL; }
	void setObject(tagTile_obj obj) { _object = obj; }
	void setObject(POINT parent) { _object._parent = parent; }
	POINT getParent() { return _object._parent; }
	POINT getVolume() { return _object.VOLUME; }
	bool isObject() { if (_object.OBJ_INDEX != OBJECT_NONE) return true; else return false; }
	void eraseObject() { _object.imageIndex = { 0,0 }; _object.isFrame = false; _object.OBJ_INDEX = OBJECT_NONE; _object.VOLUME = { 1,1 }; _object._image = NULL; _object._offSet = { 0,0 }; }


};