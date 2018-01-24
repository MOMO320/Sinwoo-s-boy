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

	vertScrollMove = 0;
	horzScrollMove = 0;

	_maxCameraSize = 0;
	_minCameraSize = 300;

	_scrollhorz = CreateWindow(TEXT("scrollbar"), NULL, WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_CHILD | WS_VISIBLE | SBS_HORZ, areaStartX, areaStartY + 705, 800, 20, _hWnd, HMENU(BTN_SCROLL_VERT),
		_hInstance, NULL);

	_scrollvert = CreateWindow(TEXT("scrollbar"), NULL, WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_CHILD | WS_VISIBLE | SBS_VERT, areaStartX + 800, areaStartY + 5, 20, 700, _hWnd, HMENU(BTN_SCROLL_HORI),
		_hInstance, NULL);

	SetScrollRange(_scrollvert, SB_CTL, _maxCameraSize, _minCameraSize, false);


	SetScrollRange(_scrollhorz, SB_CTL, _maxCameraSize, _minCameraSize, false);

	SetScrollPos(_scrollvert, SB_CTL, 0, true);
	SetScrollPos(_scrollhorz, SB_CTL, 0, true);

	_click = false;
	return S_OK;
}

void drawArea::release()
{

}

void drawArea::update()	
{
	tileSize = tileSizeX * tileSizeY;

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

	_minCameraSize = tileSize * 1.2;
	SetScrollRange(_scrollvert, SB_CTL, _maxCameraSize, _minCameraSize, false);
	SetScrollRange(_scrollhorz, SB_CTL, _maxCameraSize, _minCameraSize, false);

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
		vertScrollMove = 0;
		horzScrollMove = 0;
		SetScrollPos(_scrollvert, SB_CTL, vertScrollMove, true);
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
		saveTile[i].tr_key = tempTR.trKey;

		tagTile_obj tempObj = (*_vCurrentTile)[i]->getObject();
		saveTile[i].obj_key = tempObj.objKey;
		saveTile[i].obj_parent = tempObj._parent;

		for (int j = 0; j < 4; ++j)
		{
			tagTile_deco tempDeco = (*_vCurrentTile)[i]->getDeco(j);
			saveTile[i].deco_key[j] = tempDeco.decoKey;
		}

		tagTile_character tempChar = (*_vCurrentTile)[i]->getCharacter();
		saveTile[i].char_key = tempChar.charKey;
		saveTile[i].char_initPoint = tempChar.initPoint;
		saveTile[i].char_connectedMap = tempChar.connectedMap;

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
	
	//.map저장
	file = CreateFile(tempName.c_str(), GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, saveTile, sizeof(SAVELOAD_TILE)*arrSize, &write, NULL);
	CloseHandle(file);

	//.txt저장

	string mapName, SizeX, SizeY;
	char str[128];
	char sizeX[128];
	char sizeY[128];
	ZeroMemory(str, sizeof(str));
	ZeroMemory(sizeX, sizeof(sizeX));
	itoa(tileSizeX, sizeX,10);
	ZeroMemory(sizeY, sizeof(sizeY));
	itoa(tileSizeY, sizeY, 10);

	strncat_s(str, 128, currentName.c_str(), 126);
	strcat(str, ",");
	strncat_s(str, 128, sizeX, 126);
	strcat(str, ",");
	strncat_s(str, 128, sizeY, 126);

	int a, b;
	a = atoi(sizeX);
	b = atoi(sizeY);


	tempName = "./map./";
	tempName.append(fileName);
	tempName.append(".txt");

	file = CreateFile(tempName.c_str(), GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, sizeof(str), &write, NULL);
	CloseHandle(file);

}

void drawArea::saveMapAll()
{
}

void drawArea::loadMap(string fileName)
{
	//fileName 은 파일 경로로 옴
	string tempName = fileName;
	int ori_length = tempName.length();
	
	tempName.erase(ori_length - 4, ori_length);
	//tempName에는 확장자를 제외한 나머지만 남음!

	HANDLE file;

	char str[128];
	DWORD read;
	string loadTxt = tempName;
	loadTxt.append(".txt");
	

	file = CreateFile(loadTxt.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, 128, &read, NULL);

	CloseHandle(file);

	vector<string> vArray;
	char* temp;
	char* separator = ",";
	char* token;

	token = strtok(str, separator);
	vArray.push_back(token);

	while (NULL != (token = strtok(NULL, separator)))
	{
		vArray.push_back(token);
	}
	
	
	tagMapMap tempMapMap;
	tempMapMap.fileName = vArray[0];
	tempMapMap.tileX = atoi(vArray[1].c_str());
	tempMapMap.tileY = atoi(vArray[2].c_str());

	//이제 타일 로드
	int arrSize = tempMapMap.tileX*tempMapMap.tileY;
	SAVELOAD_TILE* saveTile = new SAVELOAD_TILE[arrSize];

	string loadMap = tempName;
	loadMap.append(".map");

	file = CreateFile(loadMap.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	
	ReadFile(file, saveTile, sizeof(SAVELOAD_TILE)*arrSize, &read, NULL);

	for (int i = 0; i < arrSize; ++i)
	{
		tile_maptool* tempTile = new tile_maptool;
		tempTile->init(i%tempMapMap.tileX, i / tempMapMap.tileX);
		tempTile->loadTile(saveTile[i]);
		tempMapMap.vTile.push_back(tempTile);
	}

	
	addMap_load(tempMapMap);




}

void drawArea::addMap_load(tagMapMap mapmap)
{
	auto iter = _mMap.begin();

	for (; iter != _mMap.end(); iter++)
	{
		if (iter->first == mapmap.fileName)
		{
			_mMap.erase(iter);
			break;
		}
	}

	_mMap.insert(make_pair(mapmap.fileName, mapmap));

	changeCurrentMapSet(mapmap.fileName);

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

			if (PtInRect(&(*_vCurrentTile)[i]->getRect(), _ptMouse))
			{
				HBRUSH hb, hob;
				hb = CreateSolidBrush(RGB(20, 50, 200));
				hob = (HBRUSH)SelectObject(getAreaDC(), hb);
				DeleteObject(hb);
			}
		}
	}
	DeleteObject(hbrush);

	

	//속성
	char str[200];
	wsprintf(str, "_tileX : %d, _tileY : %d, _position : %d", _tileX, _tileY, _position, str, strlen(str));
	TextOut(getToolMemDC(), 1050,630,str,strlen(str));
	wsprintf(str, "_ptMouse.x : %d, _ptMouse.y : %d", _ptMouse.x, _ptMouse.y, str, strlen(str));
	TextOut(getToolMemDC(), 1050, 660, str, strlen(str));
	wsprintf(str, "vertScrollMove : %d", vertScrollMove, str, strlen(str));
	TextOut(getToolMemDC(), 1050, 690, str, strlen(str));
	wsprintf(str, "horzScrollMove : %d", horzScrollMove, str, strlen(str));
	TextOut(getToolMemDC(), 1050, 740, str, strlen(str));
	wsprintf(str, "temp.x : %d, temp.y : %d", temp.x, temp.y, str, strlen(str));
	TextOut(getToolMemDC(), 1050, 780, str, strlen(str));
	//=======================================================================================
	//drawArea 최종 출력
	getArea()->render(getToolMemDC(), areaStartX, areaStartY);
}

void drawArea::sendhorzScrollMessage(WPARAM wParam)
{
	switch (LOWORD(wParam))
	{
		horzScrollMove = HIWORD(wParam);
	case SB_LINELEFT: 
		horzScrollMove = max(_maxCameraSize, horzScrollMove - 5);
		break;
	case SB_LINERIGHT:
		horzScrollMove = min(_minCameraSize, horzScrollMove + 5);
		break;
	case SB_PAGELEFT:
		horzScrollMove = max(_maxCameraSize, horzScrollMove - 10);
		break;
	case SB_PAGERIGHT:
		horzScrollMove = min(_minCameraSize, horzScrollMove, +10);
		break;
	case SB_THUMBTRACK: 
		horzScrollMove = HIWORD(wParam);
		break;
	}
	SetScrollPos(_scrollhorz, SB_CTL, horzScrollMove, true);
	//InvalidateRect(hWnd, NULL, FALSE);
}

void drawArea::sendvertScrollMessage( WPARAM wParam)
{
	switch (LOWORD(wParam))
	{
		vertScrollMove = HIWORD(wParam);
	case SB_LINEUP:
		vertScrollMove = max(_maxCameraSize, vertScrollMove - 10);
		break;
	case SB_LINEDOWN:
		vertScrollMove = min(_minCameraSize, vertScrollMove + 10);
		break;
	case SB_PAGEUP:
		vertScrollMove = max(_maxCameraSize, vertScrollMove - 20);
		break;
	case SB_PAGEDOWN:
		vertScrollMove = min(_minCameraSize, vertScrollMove + 20);
		break;
	case SB_THUMBTRACK:
		vertScrollMove = HIWORD(wParam);
		break;
	}
	SetScrollPos(_scrollvert, SB_CTL, vertScrollMove, true);
}

void drawArea::sendWheelMessage(WPARAM wParam)
{
	if ((SHORT)HIWORD(wParam) > 0)
	{
		vertScrollMove += 5;
	}
	else
	{
		vertScrollMove -= 5;
	}
}

void drawArea::sendMouseMove(LPARAM lParam)
{
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		_click = true;
		temp.x = _ptMouse.x - vertScrollMove;
		temp.y = _ptMouse.y - horzScrollMove;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RBUTTON))
	{
		_click = false;
		temp.x = NULL;
		temp.y = NULL;
	}
	if (_click)
	{
		vertScrollMove = HIWORD(lParam) - temp.x;
		horzScrollMove = LOWORD(lParam) - temp.y;
	}
}



