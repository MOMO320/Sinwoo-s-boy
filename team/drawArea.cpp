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
	
	for (int i = 0; i <TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			tile* temp;
			temp = new tile;
			temp->init(j,i);

			_vCurrentTile.push_back(temp);
		}
	}

	return S_OK;
}

void drawArea::release()
{
}

void drawArea::update()	
{

	_tileX = (_ptMouse.x + horzScrollMove - areaStartX)  / TILESIZE;
	_tileY = (_ptMouse.y + vertScrollMove - areaStartY) / TILESIZE;
	
	
	_position = _tileX + _tileY * TILEX;

}

void drawArea::keyDownUpdate(int key)
{
	switch(key)
	{
	case VK_LBUTTON:
		if ((_tileX >= 0 && _tileX < TILEX) && (_tileY >= 0 && _tileY < TILEY) && _SelectedTile != NULL)
		{
			if (_SelectedTile->getSelectedTile() != NULL)
			{
				switch (_SelectedTile->getSelectedTile()->tileClass)
				{
				case TILE_TERRAIN:
					_vCurrentTile[_tileX + _tileY * TILEX]->setTerrain(*_SelectedTile->getSelectedTile()->trInfo);
					break;
				case TILE_OBJECT:
					_vCurrentTile[_tileX + _tileY * TILEX]->setObject(*_SelectedTile->getSelectedTile()->objInfo);
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
	vector<tile*> vtempTile;
	for (int i = 0; i <sizeX; ++i)
	{
		for (int j = 0; j < sizeY; ++j)
		{
			tile* temp;
			temp = new tile;
			temp->init(j, i);

			vtempTile.push_back(temp);
		}
	}
	_mMap.insert(make_pair(mapKey, vtempTile));
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
	for (int i = 0; i < _vCurrentTile.size(); ++i)
	{
		_vCurrentTile[i]->Toolrender(getAreaDC(), horzScrollMove, vertScrollMove);
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



