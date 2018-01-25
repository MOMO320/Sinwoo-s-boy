#include "stdafx.h"
#include "aStarMapInfo.h"


aStarMapInfo::aStarMapInfo()
	:_mapSizeX(0), _mapSizeY(0), _tileNumX(0), _tileNumY(0), _tileSize(50)
{
}


aStarMapInfo::~aStarMapInfo()
{
}

HRESULT aStarMapInfo::init()	
{
	return S_OK;
}
void aStarMapInfo::release()	
{
}
void aStarMapInfo::update()		
{
}
void aStarMapInfo::render()		
{
}
void aStarMapInfo::loadMapInfo(int mapSizeX, int mapSizeY)
{
	_mapSizeX = mapSizeX;
	_mapSizeY = mapSizeY;
	_tileNumX = _mapSizeX / _tileSize;
	_tileNumY = _mapSizeY / _tileSize;
}
