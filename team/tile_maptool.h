#pragma once
#include "gameNode.h"
#include "tileNode.h"

class tile_maptool : public gameNode
{
private:
	
	POINT index;
	RECT rc;

	tagTile_tr _terrain;
	tagTile_obj _object;
	tagTile_deco _deco[4];
	tagTile_character _character;
	tagTile_event _event;
	int weight;

	bool _objectRender;

	int timeCount;
public:
	tile_maptool();
	~tile_maptool();

	HRESULT init(int indexX, int indexY);
	void release(void);
	void update(void);
	void render(void);
	void Toolrender(HDC hdc ,int cameraX, int cameraY);

	int getIdX(void) { return index.x; }
	int getIdY(void) { return index.y; }

	RECT getRect() { return rc; }

	void setObjectRender(bool state) { _objectRender = state; }

	POINT getCenter() { return { (rc.left + rc.right) / 2,(rc.top + rc.bottom) / 2 }; }


	//지형관련
	void setTerrain(tagTile_tr terrain) { _terrain = terrain; }
	void eraseTerrain() { _terrain.imageIndex.clear(); _terrain.isFrame = false; _terrain.TR_INDEX = TR_NONE; _terrain._image = NULL; }
	tagTile_tr getTR() { return _terrain; }
	//오브젝트관련
	void setObject(tagTile_obj obj) { _object = obj; }
	void setObject(POINT parent) { _object._parent = parent; }
	POINT getParent() { return _object._parent; }
	POINT getVolume() { return _object.VOLUME; }
	bool isObject() { if (_object.OBJ_INDEX != OBJECT_NONE) return true; else return false; }
	void eraseObject() { _object.imageIndex = { 0,0 }; _object.isFrame = false; _object.OBJ_INDEX = OBJECT_NONE; _object.VOLUME = { 1,1 }; _object._image = NULL; _object._offSet = { 0,0 }; }
	tagTile_obj getObject() { return _object; }
	//캐릭터관련
	void setCharacter(tagTile_character character) { _character = character; }
	void eraseCharacter() { _character.CHARACTER_INDEX = CHARACTER_NONE; _character.connectedMap = ""; _character.initPoint = { 0,0 };  _character.vPatrol.clear(); _character._image = NULL; _character._offSet = { 0,0 }; }
	tagTile_character getCharacter() { return _character; }
	//데코 관련
	void setDecoration(tagTile_deco deco) {
		switch (deco.DECO_INDEX)
		{
		case DECO_LEFT_TOP:
			_deco[0] = deco;
			weight += _deco[0].weight;
			break;
		case DECO_RIGHT_TOP:
			_deco[1] = deco;
			weight += _deco[1].weight;
			break;
		case DECO_LEFT_BOTTOM:
			_deco[2] = deco;
			weight += _deco[2].weight;
			break;
		case DECO_RIGHT_BOTTOM:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_NONE:
			break;
		}
	}
	void eraseDecoration() {
		for (int i = 0; i < 4; i++)
		{
			_deco[i].DECO_INDEX = DECO_NONE;
			_deco[i].imageIndex.clear();
			_deco[i].isFrame = false;
			_deco[i].maxFrame = 1;
			_deco[i].weight = 0;
			_deco[i]._image = NULL;
			_deco[i]._offset = { 0,0 };
		}
		weight = 0;
	}
	BOOL isDeco() { for (int i = 0; i < 4; i++) { if (_deco[i].DECO_INDEX != DECO_NONE) return true; } return false; }
	tagTile_deco getDeco(int i) { if (i < 4) return _deco[i]; else return _deco[0]; }


	//이벤트관련

	tagTile_event getEvent() { return _event; }
};