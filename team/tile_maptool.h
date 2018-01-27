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
	void eraseObject() { _object.imageIndex.clear(); _object.isFrame = false; _object.OBJ_INDEX = OBJECT_NONE; _object.VOLUME = { 1,1 }; _object._image = NULL; _object._offSet = { 0,0 }; }
	tagTile_obj getObject() { return _object; }
	//캐릭터관련
	void setCharacter(tagTile_character character) { _character = character; }
	void setCharacterAttribute(vector<POINT> vPatrolIndex) { _character.vPatrol = vPatrolIndex; }
	void eraseCharacterAttribute() { _character.vPatrol.clear(); }
	void eraseCharacter() { _character.CHARACTER_INDEX = CHARACTER_NONE;  _character.initPoint = { 0,0 };  _character.vPatrol.clear(); _character._image = NULL; _character._offSet = { 0,0 }; }
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
		case DECO_WATER:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_EMPTY:
			_deco[3] = deco;
			weight += _deco[3].weight;
		case DECO_DENGEON:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_DENGEON2:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_HILL:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_HILL2:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_HILL3:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_HILL4:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_HILL5:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_HILL6:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_HILL7:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_HILL8:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_HILL9:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_HILL10:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_HILL11:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_HILL12:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_HILL13:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_HILL14:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_HILL15:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_HILL16:
			_deco[3] = deco;
			weight += _deco[3].weight;
			break;
		case DECO_ROAD:
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
	void setEvent(EVENT EVENT_INDEX,ACTING_CONDITION ACT_CONDITION_INDEX,COLORREF color, string current,string next, int param1, int param2, int param3 ){
		_event.EVENT_INDEX = EVENT_INDEX; _event.ACT_INDEX = ACT_CONDITION_INDEX;
		_event.current = current; _event.next = next; _event.param1 = param1; _event.param2 = param2; _event.param3 = param3; _event.eventColor = color;
	}
	void eraseEvent() { _event.EVENT_INDEX = EVENT_NONE; _event.ACT_INDEX = ACT_CONDITION_NONE; _event.current = _event.next = ""; _event.param1 = _event.param2 = _event.param3 = 0; }
	tagTile_event getEvent() { return _event; }

	//타일 로드 관련
	void loadTile(SAVELOAD_TILE loadTile);
};