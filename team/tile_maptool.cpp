#include "stdafx.h"
#include "tile_maptool.h"
#include "drawArea.h"


tile_maptool::tile_maptool()
{
	_terrain.TR_INDEX = TR_NONE;
	_object.OBJ_INDEX = OBJECT_NONE;
	_objectRender = false;
}


tile_maptool::~tile_maptool()
{
}

HRESULT tile_maptool::init(int indexX, int indexY)
{
	index = { indexX, indexY };
	rc = RectMake(index.x * TILESIZE, index.y * TILESIZE, TILESIZE, TILESIZE);
	timeCount = 0;
	return S_OK;
}

void tile_maptool::release(void)
{
}

void tile_maptool::update(void)
{

	timeCount++;
}

void tile_maptool::render(HDC hdc, int cameraX, int cameraY)
{
	if (_character.CHARACTER_INDEX != CHARACTER_NONE)
	{
		_character._image->frameRender(hdc, rc.left - _character._offSet.x - cameraX, rc.top - _character._offSet.y - cameraY, timeCount / 10 % _character._image->getMaxFrameX(), 0);
		HBRUSH hb, hob;
		hb = (HBRUSH)GetStockObject(NULL_BRUSH);
		hob = (HBRUSH)SelectObject(hdc, hb);
		HPEN hp, hop;
		hp = (HPEN)CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		hop = (HPEN)SelectObject(hdc, hp);
		RectangleMake(hdc, rc.left - cameraX, rc.top - cameraY, TILESIZE, TILESIZE);
		SelectObject(hdc, hop);
		SelectObject(hdc, hob);
		DeleteObject(hp);
		DeleteObject(hb);
	}

}

void tile_maptool::Toolrender(HDC hdc, int cameraX, int cameraY) //맵부분 출력.
{
	bool render = false;
	POINT clippingStart, clippingEnd;
	clippingStart = { cameraX, cameraY };
	clippingEnd = { cameraX + areaSizeX,cameraY + areaSizeY };

	if (rc.right > clippingStart.x && rc.left < clippingEnd.x
		&& rc.bottom > clippingStart.y && rc.top < clippingEnd.y) render = true;
	
	if (render)
	{
		if (_terrain.TR_INDEX == TR_NONE && _object.OBJ_INDEX == OBJECT_NONE)
		{
			Rectangle(hdc, rc.left - cameraX, rc.top - cameraY, rc.right - cameraX, rc.bottom - cameraY);
		}

		if (_terrain.TR_INDEX != TR_NONE)
		{
			Rectangle(hdc, rc.left - cameraX, rc.top - cameraY, rc.right - cameraX, rc.bottom - cameraY);
			_terrain._image->render(hdc, rc.left - cameraX, rc.top - cameraY, _terrain.imageIndex[timeCount / 10 % _terrain.maxFrame].x, _terrain.imageIndex[timeCount / 10 % _terrain.maxFrame].y, TILESIZE, TILESIZE);

		}

		for (int i = 0; i < 4; i++)
		{
			if (_deco[i].DECO_INDEX != DECO_NONE)
			{

			}
		}

		if (_object.OBJ_INDEX != OBJECT_NONE && _object._parent.x == index.x && _object._parent.y == index.y)
		{
			_object._image->render(hdc, rc.left - cameraX - TILESIZE * (_object.VOLUME.x - 1) - _object._offSet.x, rc.top - cameraY - TILESIZE*(_object.VOLUME.y - 1) - _object._offSet.y, _object.imageIndex[0].x, _object.imageIndex[0].y, _object.VOLUME.x *TILESIZE + _object._offSet.x, _object.VOLUME.y * TILESIZE + _object._offSet.y);
			HBRUSH hb, hob;
			hb = (HBRUSH)GetStockObject(NULL_BRUSH);
			hob = (HBRUSH)SelectObject(hdc, hb);
			HPEN hp, hop;
			hp = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
			hop = (HPEN)SelectObject(hdc, hp);
			for (int i = 0; i < _object.VOLUME.y; i++)
			{
				for (int j = 0; j < _object.VOLUME.x; j++)
				{
					RectangleMake(hdc, rc.left - cameraX - j *TILESIZE, rc.top - i *TILESIZE - cameraY, TILESIZE, TILESIZE);
				}
			}
			SelectObject(hdc, hop);
			SelectObject(hdc, hob);
			DeleteObject(hp);
			DeleteObject(hb);

		}
		
		if (_object.OBJ_INDEX != OBJECT_NONE && _object._parent.x == index.x && _object._parent.y == index.y && _object.isFrame)
		{
			_object._image->render(hdc, rc.left - cameraX - TILESIZE * (_object.VOLUME.x - 1) - _object._offSet.x, rc.top - cameraY - TILESIZE*(_object.VOLUME.y - 1) - _object._offSet.y, _object.imageIndex[timeCount / 10 % _object.maxFrame].x, _object.imageIndex[timeCount / 10 % _object.maxFrame].y, _object.VOLUME.x *TILESIZE + _object._offSet.x, _object.VOLUME.y * TILESIZE + _object._offSet.y);
			HBRUSH hb, hob;
			hb = (HBRUSH)GetStockObject(NULL_BRUSH);
			hob = (HBRUSH)SelectObject(hdc, hb);
			HPEN hp, hop;
			hp = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
			hop = (HPEN)SelectObject(hdc, hp);
			for (int i = 0; i < _object.VOLUME.y; i++)
			{
				for (int j = 0; j < _object.VOLUME.x; j++)
				{
					RectangleMake(hdc, rc.left - cameraX - j *TILESIZE, rc.top - i *TILESIZE - cameraY, TILESIZE, TILESIZE);
				}
			}
			SelectObject(hdc, hop);
			SelectObject(hdc, hob);
			DeleteObject(hp);
			DeleteObject(hb);
		}
		for (int i = 0; i < 4; i++)
		{
			if (_deco[i].DECO_INDEX != DECO_NONE)
			{
				_deco[i]._image->render(hdc, rc.left - cameraX, rc.top - cameraY, _deco[i].imageIndex[timeCount / 10 % _deco[i].maxFrame].x, _deco[i].imageIndex[timeCount / 10 % _deco[i].maxFrame].y, TILESIZE, TILESIZE);
			}
		}
		/*if (_character.CHARACTER_INDEX != CHARACTER_NONE)
		{
			_character._image->frameRender(hdc, rc.left - _character._offSet.x - cameraX, rc.top - _character._offSet.y - cameraY, timeCount / 10 % _character._image->getMaxFrameX(), 0);
			HBRUSH hb, hob;
			hb = (HBRUSH)GetStockObject(NULL_BRUSH);
			hob = (HBRUSH)SelectObject(hdc, hb);
			HPEN hp, hop;
			hp = (HPEN)CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
			hop = (HPEN)SelectObject(hdc, hp);
			RectangleMake(hdc, rc.left - cameraX, rc.top - cameraY, TILESIZE, TILESIZE);
			SelectObject(hdc, hop);
			SelectObject(hdc, hob);
			DeleteObject(hp);
			DeleteObject(hb);
		}*/

		if (_event.EVENT_INDEX != EVENT_NONE)
		{
			HBRUSH hb, hob;
			hb = (HBRUSH)CreateHatchBrush(HS_BDIAGONAL, _event.eventColor);
			hob = (HBRUSH)SelectObject(hdc, hb);
			HPEN hp, hop;
			hp = (HPEN)CreatePen(PS_SOLID, 5, _event.eventColor);
			hop = (HPEN)SelectObject(hdc, hp);
			RectangleMake(hdc, rc.left - cameraX, rc.top - cameraY, TILESIZE, TILESIZE);
			SelectObject(hdc, hop);
			SelectObject(hdc, hob);
			DeleteObject(hp);
			DeleteObject(hb);
		}
	}
}

void tile_maptool::loadTile(SAVELOAD_TILE loadTile)
{
	//지형
	if(TILEMANAGER->findTerrain(loadTile.tr_key) != NULL)
	_terrain = *TILEMANAGER->findTerrain(loadTile.tr_key);
	
	//오브젝트
	if (TILEMANAGER->findObj(loadTile.obj_key) != NULL)
	{
		_object = *TILEMANAGER->findObj(loadTile.obj_key);
	}
	_object._parent = loadTile.obj_parent;

	//데코
	for (int i = 0; i < 4; i++)
	{
		if(TILEMANAGER->findDec(loadTile.deco_key[i]) != NULL)
		_deco[i] = *TILEMANAGER->findDec(loadTile.deco_key[i]);
	}


	//캐릭터
	if (TILEMANAGER->findChracter(loadTile.char_key) != NULL)
	{
		_character = *TILEMANAGER->findChracter(loadTile.char_key);
		//_character.connectedMap = loadTile.char_connectedMap;
		_character.initPoint = loadTile.char_initPoint;
	}


	//이벤트
	_event.EVENT_INDEX = loadTile.EVENT_INDEX;
	_event.ACT_INDEX = loadTile.ACT_INDEX;
	_event.eventColor = loadTile.eventColor;
	_event.next = loadTile.next;
	_event.param1 = loadTile.event_param1;
}
