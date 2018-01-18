#include "stdafx.h"
#include "tile.h"


tile::tile()
{
	_terrain.TR_INDEX = TR_NONE;
	_object.OBJ_INDEX = OBJECT_NONE;
}


tile::~tile()
{
}

HRESULT tile::init(int indexX, int indexY)
{
	rc = RectMake(indexX * TILESIZE, indexY * TILESIZE, TILESIZE, TILESIZE);

	return S_OK;
}

void tile::release(void)
{
}

void tile::update(void)
{
}

void tile::render(void)
{
	

}

void tile::Toolrender(HDC hdc , int cameraX , int cameraY)
{
	if (_terrain.TR_INDEX == TR_NONE && _object.OBJ_INDEX == OBJECT_NONE)
	{
		Rectangle(hdc, rc.left - cameraX , rc.top - cameraY, rc.right - cameraX, rc.bottom - cameraY);
	}
	else if (_terrain.TR_INDEX != TR_NONE)
	{
		_terrain._image->render(hdc, rc.left - cameraX, rc.top - cameraY, _terrain.imageIndex.x, _terrain.imageIndex.y, TILESIZE, TILESIZE);
	}
	else if (_object.OBJ_INDEX == OBJECT_NONE)
	{
		
	}
}
