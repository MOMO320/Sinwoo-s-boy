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

	return S_OK;
}

void tile_maptool::release(void)
{
}

void tile_maptool::update(void)
{
}

void tile_maptool::render(void)
{
	

}

void tile_maptool::Toolrender(HDC hdc , int cameraX , int cameraY) //맵부분 출력.
{
	if (_terrain.TR_INDEX == TR_NONE && _object.OBJ_INDEX == OBJECT_NONE)
	{
		Rectangle(hdc, rc.left - cameraX , rc.top - cameraY, rc.right - cameraX, rc.bottom - cameraY);
	}

	if (_terrain.TR_INDEX != TR_NONE)
	{
		Rectangle(hdc, rc.left - cameraX, rc.top - cameraY, rc.right - cameraX, rc.bottom - cameraY);
		_terrain._image->render(hdc, rc.left - cameraX, rc.top - cameraY, _terrain.imageIndex.x, _terrain.imageIndex.y, TILESIZE, TILESIZE);
		
	}

	if (_object.OBJ_INDEX != OBJECT_NONE && _objectRender)
	{
		//_object._image->render(hdc, rc.left - cameraX, rc.top - cameraY, _object.imageIndex.x, _object.imageIndex.y, TILESIZE,TILESIZE);
		//Rectangle(hdc, rc.left - cameraX, rc.top - cameraY, rc.right - cameraX, rc.bottom - cameraY);
		_object._image->render(hdc, rc.left - cameraX - TILESIZE * (_object.VOLUME.x-1) - _object._offSet.x, rc.top - cameraY - TILESIZE*(_object.VOLUME.y-1)-_object._offSet.y, _object.imageIndex.x, _object.imageIndex.y, _object.VOLUME.x *TILESIZE + _object._offSet.x, _object.VOLUME.y * TILESIZE + _object._offSet.y);
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
				RectangleMake(hdc, rc.left - cameraX - j *TILESIZE, rc.top - i *TILESIZE - cameraY, TILESIZE,TILESIZE);
			}
		}
		//RectangleMake(hdc, rc.left - cameraX - (_object.VOLUME.x - 1) *TILESIZE, rc.top - (_object.VOLUME.y - 1) *TILESIZE - cameraY, _object.VOLUME.x *TILESIZE, _object.VOLUME.y * TILESIZE);
		SelectObject(hdc, hop);
		SelectObject(hdc, hob);
		DeleteObject(hp);
		DeleteObject(hb);
	}

	char str[128];
	sprintf(str, "검출 변수 : %d", _pathDetect, str, strlen(str));
	TextOut(hdc, 300, 200, str, strlen(str));
}