
#pragma once

#define TILESIZE 50

enum SWITCH_TILE_LAYER
{
	TILE_TERRAIN,
	TILE_OBJECT,
	TILE_EVENT,
	TILE_CHARACTER,
	TILE_END,
};


enum TERRAIN
{
	TR_NONE,
	TR_BASIC,
	TR_CLIFF,
};

enum OBJECT
{
	OBJECT_PICK,
	OBJECT_STOP,
	OBJECT_NONE
};

enum DECORATION
{
	DECO_LEFT_TOP,
	DECO_RIGHT_TOP,
	DECO_LEFT_BOTTOM,
	DECO_RIGHT_BOTTOM,
	DECO_NONE
};

enum CHARACTER
{
	CHARACTER_NONE,
	CHARACTER_PLAYER_POS,
	CHARACTER_MONSTER_POS,
	CHARACTER_NPC_POS,
};

enum EVENT
{
	EVENT_NONE,
	EVENT_MOVE,
	EVENT_INTERACT,
	EVENT_PORT,
};

enum ACTING_CONDITION
{
	ACT_CONDITION_NONE,
	ACT_CONDITION_INTERSECTTILE,
	ACT_CONDITION_KEYDOWN,

};

struct tagTile_tr
{
	TERRAIN TR_INDEX;
	image* _image;
	POINT imageIndex;
	bool isFrame;

	tagTile_tr()
	{
		TR_INDEX = TR_BASIC;
		_image = NULL;
		imageIndex = { 0,0 };
		isFrame = false;
	}


};

struct tagTile_obj
{
	OBJECT OBJ_INDEX;
	image* _image;
	POINT imageIndex;
	POINT VOLUME;
	POINT _offSet;
	POINT _parent;
	bool isFrame;

	tagTile_obj()
	{
		OBJ_INDEX = OBJECT_NONE;
		_image = NULL;
		imageIndex = { 0,0 };
		VOLUME = { 1,1 };
		_offSet = { 0,0 };
		isFrame = false;
	}

};

struct tagTile_deco
{
	DECORATION DECO_INDEX;
	image* _image;
	POINT imageIndex;
	POINT _offset;

	int weight;

	tagTile_deco()
	{
		DECO_INDEX = DECO_NONE;
		_image = NULL;
		imageIndex = { 0,0 };
		weight = 0;
	}
};

struct tagTile_event
{
	EVENT EVENT_INDEX;
	ACTING_CONDITION ACT_INDEX;
	HBRUSH eventColor;
	int param1, param2, param3;

	tagTile_event()
	{
		EVENT_INDEX = EVENT_NONE;
		ACT_INDEX = ACT_CONDITION_NONE;
		eventColor = NULL;
		param1 = param2 = param3 = 0;
	}
};

struct tagTile_character
{
	CHARACTER CHARACTER_INDEX;
	image* _image;
	POINT initPoint;
	string connectedMap;
	POINT _offSet;
	vector<int> vPatrol;

	tagTile_character()
	{
		CHARACTER_INDEX = CHARACTER_NONE;
		_image = NULL;
		initPoint = { 0,0 };
	}
};