#include "stdafx.h"
#include "tile.h"


tile::tile()
{
	_terrain = NULL;
	_object = NULL;
}


tile::~tile()
{
}

HRESULT tile::init(int indexX, int indexY)
{
	return E_NOTIMPL;
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

void tile::Toolrender(void)
{
	if (_terrain == NULL && _object == NULL)
	{
		Rectangle(getToolMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	}
	else if (_terrain != NULL)
	{
		_terrain->_image->render(getToolMemDC(), rc.left, rc.top, _terrain->imageIndex.x, _terrain->imageIndex.y, TILESIZE, TILESIZE);
	}
	else if (_object != NULL)
	{
		
	}
}
