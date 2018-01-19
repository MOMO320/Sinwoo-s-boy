#include "stdafx.h"
#include "tile.h"


tile::tile()
{
	_terrain.TR_INDEX = TR_NONE;
	_object.OBJ_INDEX = OBJECT_NONE;
	_objectRender = false;
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

void tile::Toolrender(HDC hdc , int cameraX , int cameraY) //¸ÊºÎºÐ Ãâ·Â.
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
	if (_object.OBJ_INDEX != OBJECT_NONE )
	{
		Rectangle(hdc, rc.left - cameraX, rc.top - cameraY, rc.right - cameraX, rc.bottom - cameraY);
		_object._image->render(hdc, rc.left - cameraX - TILESIZE* (_object.VOLUME.x-1)-_object._offSet.x, rc.top - cameraY - TILESIZE*(_object.VOLUME.y-1)-_object._offSet.y, _object.imageIndex.x, _object.imageIndex.y, _object.VOLUME.x *TILESIZE, _object.VOLUME.y * TILESIZE);
		
	}
}
