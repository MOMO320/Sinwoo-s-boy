#include "stdafx.h"
#include "drawArea.h"
#include "SelectTile.h"

drawArea::drawArea()
{
}


drawArea::~drawArea()
{
}


HRESULT drawArea::init()
{
	_SelectedTile = NULL;
	_vCurrentTile = NULL;
	
	return S_OK;
}

void drawArea::release()
{
}

void drawArea::update()	
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))horzScrollMove -= 2;

	_tileX = (_ptMouse.x + horzScrollMove - areaStartX)  / TILESIZE;
	_tileY = (_ptMouse.y + vertScrollMove - areaStartY) / TILESIZE;
	
	
	_position = _tileX + _tileY * tileSizeX;

}

void drawArea::keyDownUpdate(int key)
{
	switch(key)
	{
	case VK_LBUTTON:
		if ((_tileX >= 0 && _tileX < tileSizeX) && (_tileY >= 0 && _tileY < tileSizeY) && _SelectedTile != NULL)
		{
			if (_SelectedTile->getSelectedTile() != NULL)
			{
				switch (_SelectedTile->getSelectedTile()->tileClass)
				{
				case TILE_TERRAIN:
					(*_vCurrentTile)[_tileX + _tileY*tileSizeX]->setTerrain(*_SelectedTile->getSelectedTile()->trInfo);
					break;
<<<<<<< HEAD
				case TILE_OBJECT:
					(*_vCurrentTile)[_tileX + _tileY * tileSizeX]->setObject(*_SelectedTile->getSelectedTile()->objInfo);
=======
				case TILE_OBJECT: 
					{
						for (int i = _tileY; i < _tileY + _SelectedTile->getSelectedTile()->objInfo->VOLUME.y; ++i)
						{
							for (int j = _tileX; j < _tileX + _SelectedTile->getSelectedTile()->objInfo->VOLUME.x; ++j)
							{
								if(i< TILEY && j< TILEX)
								(*_vCurrentTile)[j + i * tileSizeX]->setObject(*_SelectedTile->getSelectedTile()->objInfo);
							}
						}

						(*_vCurrentTile)[_tileY + _SelectedTile->getSelectedTile()->objInfo->VOLUME.y - 1 +
							(_tileY + _SelectedTile->getSelectedTile()->objInfo->VOLUME.y - 1) * tileSizeX]->setObjectRender(true);

					}
>>>>>>> 7e72a8df3f05061e6b6dffc3e80f6aaf781fa4f0
					break;
				case TILE_EVENT:
					break;
				case TILE_CHARACTER:
					break;
				case TILE_END:
					break;
				}
			}
		}
	break;
	}
}

void drawArea::addMap(LPSTR mapKey, int sizeX, int sizeY)
{
	if (mapKey != NULL)
	{
		tagMapMap tempMap;
		vector<tile*> vtempTile;
		for (int i = 0; i < sizeY; ++i)
		{
			for (int j = 0; j < sizeX; ++j)
			{
				tile* temp;
				temp = new tile;
				temp->init(j, i);

				vtempTile.push_back(temp);
			}
		}
		tempMap.tileX = sizeX;
		tempMap.tileY = sizeY;
		tempMap.fileName = mapKey;
		tempMap.vTile = vtempTile;
		_mMap.insert(make_pair(mapKey, tempMap));
	}
}

void drawArea::deleteMap(LPSTR mapKey)
{
	auto iter = _mMap.find(mapKey);
	if (iter != _mMap.end())
	{

	}
}

void drawArea::changeCurrentMapSet(string name)
{
	auto iter = _mMap.find(name);
	if ( iter != _mMap.end())
	{
		_vCurrentTile = &iter->second.vTile;
		tileSizeX = iter->second.tileX;
		tileSizeY = iter->second.tileY;
	}
	else _vCurrentTile = NULL;
}


void drawArea::render()	
{
	//drawArea 한번 초기화
	PatBlt(getAreaDC(), 0, 0, areaSizeX, areaSizeY, WHITENESS);
	//==========================================================================================================

	//drawArea 테두리
	HBRUSH hbrush, holdbrush;
	hbrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	holdbrush = (HBRUSH)SelectObject(getAreaDC(), hbrush);
	RectangleMake(getAreaDC(), 0, 0, areaSizeX, areaSizeY);
	//타일 랜더
	if (_vCurrentTile != NULL)
	{
		for (int i = 0; i < (*_vCurrentTile).size(); ++i)
		{
			(*_vCurrentTile)[i]->Toolrender(getAreaDC(), horzScrollMove, vertScrollMove);
		}
	}
	DeleteObject(hbrush);

	

	//속성
	char str[200];
	sprintf(str, "_tileX : %d, _tileY : %d, _position : %d", _tileX, _tileY, _position, str, strlen(str));
	TextOut(getToolMemDC(), 1050,630,str,strlen(str));
	sprintf(str, "_ptMouse.x : %d, _ptMouse.y : %d", _ptMouse.x, _ptMouse.y, str, strlen(str));
	TextOut(getToolMemDC(), 1050, 660, str, strlen(str));
	sprintf(str, "asd : %d", vertScrollMove, str, strlen(str));
	TextOut(getToolMemDC(), 1050, 690, str, strlen(str));

	//=======================================================================================
	//drawArea 최종 출력
	getArea()->render(getToolMemDC(), areaStartX, areaStartY);
}



