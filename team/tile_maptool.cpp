#include "stdafx.h"
#include "tile_maptool.h"


tile_maptool::tile_maptool()
{
	_terrain.TR_INDEX = TR_NONE;
	_object.OBJ_INDEX = OBJECT_NONE;
	_objectRender = false;
	_pathDetect = 0;
}


tile_maptool::~tile_maptool()
{
}

HRESULT tile_maptool::init(int indexX, int indexY)
{
	rc = RectMake(indexX * TILESIZE, indexY * TILESIZE, TILESIZE, TILESIZE);
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

void tile_maptool::render(void)
{


}

void tile_maptool::Toolrender(HDC hdc, int cameraX, int cameraY) //¸ÊºÎºÐ Ãâ·Â.
{
	if (_terrain.TR_INDEX == TR_NONE && _object.OBJ_INDEX == OBJECT_NONE)
	{
		Rectangle(hdc, rc.left - cameraX, rc.top - cameraY, rc.right - cameraX, rc.bottom - cameraY);
	}

	if (_terrain.TR_INDEX != TR_NONE)
	{
		Rectangle(hdc, rc.left - cameraX, rc.top - cameraY, rc.right - cameraX, rc.bottom - cameraY);
		_terrain._image->render(hdc, rc.left - cameraX, rc.top - cameraY, _terrain.imageIndex.x, _terrain.imageIndex.y, TILESIZE, TILESIZE);

	}

	for (int i = 0; i < 4; i++)
	{
		if (_deco[i].DECO_INDEX != DECO_NONE)
		{
		}
	}

	if (_object.OBJ_INDEX != OBJECT_NONE && _objectRender)
	{
		_object._image->render(hdc, rc.left - cameraX - TILESIZE * (_object.VOLUME.x - 1) - _object._offSet.x, rc.top - cameraY - TILESIZE*(_object.VOLUME.y - 1) - _object._offSet.y, _object.imageIndex.x, _object.imageIndex.y, _object.VOLUME.x *TILESIZE + _object._offSet.x, _object.VOLUME.y * TILESIZE + _object._offSet.y);
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
			_deco[i]._image->render(hdc, rc.left, rc.top, _deco[i].imageIndex[timeCount / 10 % _deco[i].maxFrame].x, _deco[i].imageIndex[timeCount / 10 % _deco[i].maxFrame].y, TILESIZE, TILESIZE);
		}
	}
	if (_character.CHARACTER_INDEX != CHARACTER_NONE)
	{
		_character._image->frameRender(hdc, rc.left - _character._offSet.x - cameraX, rc.top - _character._offSet.y - cameraY, timeCount / 10 % _character._image->getMaxFrameX(), 0);
		HBRUSH hb, hob;
		hb = (HBRUSH)GetStockObject(NULL_BRUSH);
		hob = (HBRUSH)SelectObject(hdc, hb);
		HPEN hp, hop;
		hp = (HPEN)CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		hop = (HPEN)SelectObject(hdc, hp);
		RectangleMake(hdc, rc.left - cameraX, rc.top, TILESIZE, TILESIZE);
		SelectObject(hdc, hop);
		SelectObject(hdc, hob);
		DeleteObject(hp);
		DeleteObject(hb);
	}
}