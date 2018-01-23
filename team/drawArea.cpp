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
	currentLayer = TILE_END;
	eraser = FALSE;
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
	
	if (_vCurrentTile != NULL)
	{
		for (int i = 0; i < _vCurrentTile->size(); ++i)
		{
			(*_vCurrentTile)[i]->update();
		}
	}
	_position = _tileX + _tileY * tileSizeX;

}

void drawArea::keyDownUpdate(int key)
{
	if (!eraser)
	{
		switch (key)
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
					case TILE_OBJECT:
					{
						if (_tileX + _SelectedTile->getSelectedTile()->objInfo->VOLUME.x - 1 < tileSizeX && _tileY + _SelectedTile->getSelectedTile()->objInfo->VOLUME.y < tileSizeY)
						{
							bool add = true;
							for (int i = _tileY; i < _tileY + _SelectedTile->getSelectedTile()->objInfo->VOLUME.y; ++i)
							{
								for (int j = _tileX; j < _tileX + _SelectedTile->getSelectedTile()->objInfo->VOLUME.x; ++j)
								{
									if ((*_vCurrentTile)[j + i * tileSizeX]->isObject() || (*_vCurrentTile)[j + i * tileSizeX]->isDeco())
									{
										add = false;
										break;
									}
								}
								if (!add) break;
							}

							if (add)
							{
								for (int i = _tileY; i < _tileY + _SelectedTile->getSelectedTile()->objInfo->VOLUME.y; ++i)
								{
									for (int j = _tileX; j < _tileX + _SelectedTile->getSelectedTile()->objInfo->VOLUME.x; ++j)
									{
										if (i < tileSizeY && j < tileSizeX)
										{
											(*_vCurrentTile)[j + i * tileSizeX]->setObject(*_SelectedTile->getSelectedTile()->objInfo);
											(*_vCurrentTile)[j + i * tileSizeX]->setObject({ _tileX + _SelectedTile->getSelectedTile()->objInfo->VOLUME.x - 1,_tileY + _SelectedTile->getSelectedTile()->objInfo->VOLUME.y - 1 });
											if (i == _tileY + _SelectedTile->getSelectedTile()->objInfo->VOLUME.y - 1 && j == _tileX + _SelectedTile->getSelectedTile()->objInfo->VOLUME.x - 1)
											{
												(*_vCurrentTile)[j + i * tileSizeX]->setObjectRender(true);
											}
											else
											{
												(*_vCurrentTile)[j + i * tileSizeX]->setObjectRender(false);
											}
										}
									}
								}
							}
						}
					}
					break;
					case TILE_DECORATION:
						(*_vCurrentTile)[_tileX + _tileY*tileSizeX]->setDecoration(*_SelectedTile->getSelectedTile()->decoInfo);
					break;
					case TILE_EVENT:
						break;
					case TILE_CHARACTER:
						if(!(*_vCurrentTile)[_tileX + _tileY*tileSizeX]->isObject())
						(*_vCurrentTile)[_tileX + _tileY*tileSizeX]->setCharacter(*_SelectedTile->getSelectedTile()->chrInfo);
						break;
					case TILE_END:
						break;
					}
				}
			}
			break;
		}
	}
	else
	{
		switch (key)
		{
		case VK_LBUTTON:
			if ((_tileX >= 0 && _tileX < tileSizeX) && (_tileY >= 0 && _tileY < tileSizeY) && _SelectedTile != NULL)
			{
					switch (currentLayer)
					{
					case TILE_TERRAIN:
						(*_vCurrentTile)[_tileX + _tileY*tileSizeX]->eraseTerrain();
					break;
					case TILE_OBJECT:
						if ((*_vCurrentTile)[_tileX + _tileY*tileSizeX]->isObject())
						{
							int x, y, vx, vy;
							x = (*_vCurrentTile)[_tileX + _tileY*tileSizeX]->getParent().x;
							y = (*_vCurrentTile)[_tileX + _tileY*tileSizeX]->getParent().y;
							vx = (*_vCurrentTile)[_tileX + _tileY*tileSizeX]->getVolume().x;
							vy = (*_vCurrentTile)[_tileX + _tileY*tileSizeX]->getVolume().y;
							x += 1 - vx;
							y += 1 - vy;
							for (int i = y; i < y + vy; i++)
							{
								for (int j = x; j < x + vx; j++)
								{
									(*_vCurrentTile)[j + i*tileSizeX]->eraseObject();
								}
							}
						}
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
	}
}

void drawArea::addMap(LPSTR mapKey, int sizeX, int sizeY)
{
	if (mapKey != NULL)
	{
		tagMapMap tempMap;
		vector<tile_maptool*> vtempTile;
		for (int i = 0; i < sizeY; ++i)
		{
			for (int j = 0; j < sizeX; ++j)
			{
				tile_maptool* temp;
				temp = new tile_maptool;
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
		for (int a = 0; a < iter->second.vTile.size(); a++)
		{
			delete iter->second.vTile[a];
			iter->second.vTile[a] = NULL;
		}

		_mMap.erase(iter);
	}
}

void drawArea::changeCurrentMapSet(string name)
{
	auto iter = _mMap.find(name);
	if ( iter != _mMap.end())
	{
		_vCurrentTile = &iter->second.vTile;
		currentName = name;
		tileSizeX = iter->second.tileX;
		tileSizeY = iter->second.tileY;
	}
	else _vCurrentTile = NULL;
}

void drawArea::saveMap()
{
	const int arrSize = _vCurrentTile->size();
	SAVELOAD_TILE* saveTile = new SAVELOAD_TILE[arrSize];

	for (int i = 0; i < arrSize; ++i)
	{
		tagTile_tr tempTR = (*_vCurrentTile)[i]->getTR();
		saveTile[i].TR_INDEX = tempTR.TR_INDEX;
		saveTile[i].tr_Iname = tempTR.imageName;
		saveTile[i].tr_isFrame = tempTR.isFrame;
		saveTile[i].tr_imageIndex = tempTR.imageIndex;
		saveTile[i].tr_MaxFrame = tempTR.maxFrame;
		
		tagTile_obj tempObj = (*_vCurrentTile)[i]->getObject();
		saveTile[i].OBJ_INDEX = tempObj.OBJ_INDEX;
		saveTile[i].obj_Iname = tempObj.imageName;
		saveTile[i].obj_volume = tempObj.VOLUME;
		saveTile[i].obj_imageIndex = tempObj.imageIndex;
		saveTile[i].obj_offSet = tempObj._offSet;
		saveTile[i].obj_parent = tempObj._parent;
		saveTile[i].obj_isFrame = tempObj.isFrame;

		for (int j = 0; j < 4; ++j)
		{
			tagTile_deco tempDeco = (*_vCurrentTile)[i]->getDeco(j);
			saveTile[i].DECO_INDEX[j] = tempDeco.DECO_INDEX;
			saveTile[i].deco_Iname[j] = tempDeco.imageName;
			saveTile[i].deco_imageIndex[j] = tempDeco.imageIndex;
			saveTile[i].deco_maxFrame[j] = tempDeco.maxFrame;
			saveTile[i].deco_offset[j] = tempDeco._offset;
			saveTile[i].deco_weight[j] = tempDeco.weight;
			saveTile[i].deco_isFrame[j] = tempDeco.isFrame;
		}

		tagTile_character tempChar = (*_vCurrentTile)[i]->getCharacter();
		saveTile[i].CHARACTER_INDEX = tempChar.CHARACTER_INDEX;
		saveTile[i].char_Iname = tempChar.imageName;
		saveTile[i].char_initPoint = tempChar.initPoint;
		saveTile[i].char_connectedMap = tempChar.connectedMap;
		saveTile[i].char_offset = tempChar._offSet;
		saveTile[i].char_patrol = tempChar.vPatrol;

		tagTile_event tempEvent = (*_vCurrentTile)[i]->getEvent();
		saveTile[i].EVNET_INDEX = tempEvent.EVENT_INDEX;
		saveTile[i].ACT_INDEX = tempEvent.ACT_INDEX;
		saveTile[i].eventColor = tempEvent.eventColor;
		saveTile[i].event_param1 = tempEvent.param1;
		saveTile[i].event_param2 = tempEvent.param2;
		saveTile[i].event_param3 = tempEvent.param3;
	}

	HANDLE file;
	DWORD write;
	string fileName, tempName;
	fileName = currentName;
	
	
	tempName = "./map./";
	tempName.append(fileName);
	tempName.append(".map");
	
	file = CreateFile(tempName.c_str(), GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, saveTile, sizeof(SAVELOAD_TILE)*arrSize, &write, NULL);
	CloseHandle(file);


}

void drawArea::saveMapAll()
{
}

void drawArea::loadMap(string fileName)
{
	
}

void drawArea::loadMapAll()
{
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
