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


	//��������
	void setTerrain(tagTile_tr terrain) { _terrain = terrain; }
	void eraseTerrain() { _terrain.trKey = ""; _terrain.imageIndex.clear(); _terrain.isFrame = false; _terrain.TR_INDEX = TR_NONE; _terrain._image = NULL; }
	tagTile_tr getTR() { return _terrain; }
	//������Ʈ����
	void setObject(tagTile_obj obj) { _object = obj; }
	void setObject(POINT parent) { _object._parent = parent; }
	POINT getParent() { return _object._parent; }
	POINT getVolume() { return _object.VOLUME; }
	bool isObject() { if (_object.OBJ_INDEX != OBJECT_NONE) return true; else return false; }
	void eraseObject() { _object.objKey = ""; _object.imageIndex.clear(); _object.isFrame = false; _object.OBJ_INDEX = OBJECT_NONE; _object.VOLUME = { 1,1 }; _object._image = NULL; _object._offSet = { 0,0 }; }
	tagTile_obj getObject() { return _object; }
	//ĳ���Ͱ���
	void setCharacter(tagTile_character character) { _character = character; }
	void setCharacterAttribute(vector<POINT> vPatrolIndex) { _character.vPatrol = vPatrolIndex; }
	void setCharacterAttribute(string from) { _character.from = from; }
	void eraseCharacterAttribute() { _character.vPatrol.clear(); }
	void eraseCharacter() { _character.CHARACTER_INDEX = CHARACTER_NONE;  _character.initPoint = { 0,0 };  _character.vPatrol.clear(); _character._image = NULL; _character._offSet = { 0,0 }; }
	tagTile_character getCharacter() { return _character; }
	//���� ����
	void setDecoration(tagTile_deco deco) {
		bool addWeight;
		//if (deco.decoKey != "��" && deco.decoKey != "������Ÿ��" && deco.decoKey != "��������Ÿ��")
		//{
		//	addWeight = false;
		//}
		//else addWeight = true;

		if (!strncmp("��", deco.decoKey.c_str(), 1) && !strncmp("������Ÿ��", deco.decoKey.c_str(), 5), !strncmp("��������Ÿ��", deco.decoKey.c_str(), 6),
			!strncmp("����ٴ�",deco.decoKey.c_str(),4))
		{
			addWeight = false;
		}
		else addWeight = true;
		if (deco.weight >= 8)
		{
			if (weight - weight % 8 != 8)
			{
				_deco[3] = deco;
			}
		}
		else if (deco.weight >= 4)
		{
			if ((weight % 8 - weight % 4) != 4)
			{
				_deco[2] = deco;
			}
		}
		else if (deco.weight >= 2)
		{
			if ((weight % 4 - weight % 2) != 2)
			{
				_deco[1] = deco;
			}
		}
		else {
			if (weight % 2 != 1)
			{
				_deco[0] = deco;
			}
			else addWeight = false;
		}

		if (deco.weight == 0 && deco.DECO_INDEX != DECO_NONE)
		{
			if (deco.position == 0) _deco[0] = deco;
			 if (deco.position == 1) _deco[1] = deco;
			 if (deco.position == 2) _deco[2] = deco;
			 if (deco.position == 3) _deco[3] = deco;
		}

		if (addWeight) weight += deco.weight;

	}

	void eraseDecoration() {
		for (int i = 0; i < 4; i++)
		{
			_deco[i].decoKey = "";
			_deco[i].DECO_INDEX = DECO_NONE;
			_deco[i]._image = NULL;
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


	//�̺�Ʈ����
	void setEvent(EVENT EVENT_INDEX,ACTING_CONDITION ACT_CONDITION_INDEX,COLORREF color, string current,string next, int param1, int param2, int param3 ){
		_event.EVENT_INDEX = EVENT_INDEX; _event.ACT_INDEX = ACT_CONDITION_INDEX;
		_event.current = current; _event.next = next; _event.param1 = param1; _event.param2 = param2; _event.param3 = param3; _event.eventColor = color;
	}
	void eraseEvent() { _event.EVENT_INDEX = EVENT_NONE; _event.ACT_INDEX = ACT_CONDITION_NONE; _event.current = _event.next = ""; _event.param1 = _event.param2 = _event.param3 = 0; }
	tagTile_event getEvent() { return _event; }

	//Ÿ�� �ε� ����
	void loadTile(SAVELOAD_TILE loadTile);
};