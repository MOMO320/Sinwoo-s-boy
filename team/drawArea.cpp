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

	_scrollhorz = CreateWindow(TEXT("scrollbar"), NULL, WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_CHILD | WS_VISIBLE | SBS_HORZ, areaStartX, areaStartY + areaSizeY + 10, areaSizeX, 20, _hWnd, HMENU(BTN_SCROLL_VERT),
		_hInstance, NULL);

	_scrollvert = CreateWindow(TEXT("scrollbar"), NULL, WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_CHILD | WS_VISIBLE | SBS_VERT, areaStartX + areaSizeX + 5, areaStartY + 5, 20, areaSizeY, _hWnd, HMENU(BTN_SCROLL_HORI),
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

	if (KEYMANAGER->isStayKeyDown(VK_SHIFT))
	{
		_click = true;
		temp.x = horzScrollMove + _ptMouse.x;
		temp.y = vertScrollMove + _ptMouse.y;
	}
	else if (_vCurrentTile != NULL)
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
							if (_tileX + _SelectedTile->getSelectedTile()->objInfo->VOLUME.x - 1 < tileSizeX && _tileY + _SelectedTile->getSelectedTile()->objInfo->VOLUME.y -1 < tileSizeY)
							{
								bool add = true;
								for (int i = _tileY; i < _tileY + _SelectedTile->getSelectedTile()->objInfo->VOLUME.y; ++i)
								{
									for (int j = _tileX; j < _tileX + _SelectedTile->getSelectedTile()->objInfo->VOLUME.x; ++j)
									{
										//|| (*_vCurrentTile)[j + i * tileSizeX]->isDeco() <- 조건에서 deco는 뺌
										if ((*_vCurrentTile)[j + i * tileSizeX]->isObject())
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
							if (!(*_vCurrentTile)[_tileX + _tileY*tileSizeX]->isObject())
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
					case TILE_DECORATION:
						(*_vCurrentTile)[_tileX + _tileY*tileSizeX]->eraseDecoration();
						break;
					case TILE_EVENT:
						(*_vCurrentTile)[_tileX + _tileY*tileSizeX]->eraseEvent();
						break;
					case TILE_CHARACTER:
						(*_vCurrentTile)[_tileX + _tileY*tileSizeX]->eraseCharacter();
						break;
					case TILE_END:

						break;
					}
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
		tileSizeX = 0;
		tileSizeY = 0;
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
	char pos[1000];
	ZeroMemory(pos, sizeof(pos));

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

		tagTile_character tempCharacter = (*_vCurrentTile)[i]->getCharacter();
		saveTile[i].char_key = tempCharacter.charKey;

		tagTile_event tempEvent = (*_vCurrentTile)[i]->getEvent();
		saveTile[i].EVENT_INDEX = tempEvent.EVENT_INDEX;
		saveTile[i].ACT_INDEX = tempEvent.ACT_INDEX;
		saveTile[i].eventColor = tempEvent.eventColor;
		saveTile[i].event_param1 = tempEvent.param1;

		if ((*_vCurrentTile)[i]->getCharacter().CHARACTER_INDEX != CHARACTER_NONE)
		{
			char vSize[128];
			char indexNum[128];
			char char_character_index[128];
			ZeroMemory(vSize, sizeof(vSize));
			ZeroMemory(indexNum, sizeof(indexNum));
			ZeroMemory(char_character_index, sizeof(char_character_index));
			itoa((int)(*_vCurrentTile)[i]->getCharacter().CHARACTER_INDEX, char_character_index, 10);
			itoa((*_vCurrentTile)[i]->getCharacter().vPatrol.size(), vSize, 10);
			itoa(i, indexNum, 10);
			
			strcat(pos, "|");
			strcat(pos, char_character_index);
			// "|(int)CHARACTER_INDEX"
			strcat_s(pos,",");
			strcat_s(pos, indexNum);
			// "|(int)CHARACTER_INDEX,타일번호(i)"
			strcat_s(pos, ",");
			strcat_s(pos, (*_vCurrentTile)[i]->getCharacter().from.c_str());
			// "|(int)CHARACTER_INDEX,타일번호(i),from"
			strcat_s(pos, ",");
			strcat_s(pos, vSize);
			// "|(int)CHARACTER_INDEX,타일번호(i),from,(vPtrol의사이즈)"
			for (int k = 0; k < (*_vCurrentTile)[i]->getCharacter().vPatrol.size(); ++k)
			{
				char patrolIndex[128];
				ZeroMemory(patrolIndex, sizeof(patrolIndex));
				strcat_s(pos, ",");
				itoa((*_vCurrentTile)[i]->getCharacter().vPatrol[k].x + (*_vCurrentTile)[i]->getCharacter().vPatrol[k].y*tileSizeX, patrolIndex, 10);
				strcat_s(pos, patrolIndex);
			}
			//"|(int)CHARACTER_INDEX,타일번호(i),from,(vPtrol의사이즈),vPatrol[0],[1],[2],..."

		}
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
	char str[1000];
	char sizeX[128];
	char sizeY[128];
	ZeroMemory(str, sizeof(str));
	ZeroMemory(sizeX, sizeof(sizeX));
	itoa(tileSizeX, sizeX,10);
	ZeroMemory(sizeY, sizeof(sizeY));
	itoa(tileSizeY, sizeY, 10);

	strncat_s(str, 1000, currentName.c_str(), strlen(currentName.c_str()));
	strcat_s(str, ",");
	strncat_s(str, 1000, sizeX, strlen(sizeX));
	strcat_s(str, ",");
	strncat_s(str, 1000, sizeY, strlen(sizeY));
	strncat_s(str, 1000, pos, strlen(pos));
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

void drawArea::saveMap(string mmapName, int tileSizeX, int tileSizeY)
{
	const int arrSize = tileSizeX*tileSizeY;
	SAVELOAD_TILE* saveTile = new SAVELOAD_TILE[arrSize];

	auto tiles = _mMap.find(mmapName);

	if (tiles == _mMap.end()) return;

	char pos[1000];
	ZeroMemory(pos, sizeof(pos));

	for (int i = 0; i < arrSize; ++i)
	{
		tagTile_tr tempTR = (tiles->second.vTile)[i]->getTR();
		saveTile[i].tr_key = tempTR.trKey;

		tagTile_obj tempObj = (tiles->second.vTile)[i]->getObject();
		saveTile[i].obj_key = tempObj.objKey;
		saveTile[i].obj_parent = tempObj._parent;

		for (int j = 0; j < 4; ++j)
		{
			tagTile_deco tempDeco = (tiles->second.vTile)[i]->getDeco(j);
			saveTile[i].deco_key[j] = tempDeco.decoKey;
		}

		tagTile_event tempEvent = (tiles->second.vTile)[i]->getEvent();
		saveTile[i].EVENT_INDEX = tempEvent.EVENT_INDEX;
		saveTile[i].next = tempEvent.next;
		saveTile[i].ACT_INDEX = tempEvent.ACT_INDEX;
		saveTile[i].eventColor = tempEvent.eventColor;
		saveTile[i].event_param1 = tempEvent.param1;

		tagTile_character tempCharacter = (tiles->second.vTile)[i]->getCharacter();
		saveTile[i].char_key = tempCharacter.charKey;

		if ((tiles->second.vTile)[i]->getCharacter().CHARACTER_INDEX != CHARACTER_NONE)
		{
			char vSize[128];
			char indexNum[128];
			char char_character_index[128];
			ZeroMemory(vSize, sizeof(vSize));
			ZeroMemory(indexNum, sizeof(indexNum));
			ZeroMemory(char_character_index, sizeof(char_character_index));
			itoa((int)(tiles->second.vTile)[i]->getCharacter().CHARACTER_INDEX, char_character_index, 10);
			itoa((tiles->second.vTile)[i]->getCharacter().vPatrol.size(), vSize, 10);
			itoa(i, indexNum, 10);

			strcat(pos, "|");
			strcat(pos, char_character_index);
			// "|(int)CHARACTER_INDEX"
			strcat_s(pos, ",");
			strcat_s(pos, indexNum);
			// "|(int)CHARACTER_INDEX,타일번호(i)"
			strcat_s(pos, ",");
			strcat_s(pos, (tiles->second.vTile)[i]->getCharacter().from.c_str());
			// "|(int)CHARACTER_INDEX,타일번호(i),from"
			strcat_s(pos, ",");
			strcat_s(pos, vSize);
			// "|(int)CHARACTER_INDEX,타일번호(i),from,(vPtrol의사이즈)"
			for (int k = 0; k < (tiles->second.vTile)[i]->getCharacter().vPatrol.size(); ++k)
			{
				char patrolIndex[128];
				ZeroMemory(patrolIndex, sizeof(patrolIndex));
				strcat_s(pos, ",");
				itoa((tiles->second.vTile)[i]->getCharacter().vPatrol[k].x + (tiles->second.vTile)[i]->getCharacter().vPatrol[k].y*tileSizeX, patrolIndex, 10);
				strcat_s(pos, patrolIndex);
			}
			//"|(int)CHARACTER_INDEX,타일번호(i),from,(vPtrol의사이즈),vPatrol[0],[1],[2],..."

		}
	}

	HANDLE file;
	DWORD write;
	string fileName, tempName;
	fileName = mmapName;


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
	char str[1000];
	char sizeX[128];
	char sizeY[128];
	ZeroMemory(str, sizeof(str));
	ZeroMemory(sizeX, sizeof(sizeX));
	itoa(tileSizeX, sizeX, 10);
	ZeroMemory(sizeY, sizeof(sizeY));
	itoa(tileSizeY, sizeY, 10);

	strncat_s(str, 1000, mmapName.c_str(), strlen(mmapName.c_str()));
	strcat_s(str, ",");
	strncat_s(str, 1000, sizeX, strlen(sizeX));
	strcat_s(str, ",");
	strncat_s(str, 1000, sizeY, strlen(sizeY));
	strncat_s(str, 1000, pos, strlen(pos));

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
	auto iter = _mMap.begin();
	for (; iter != _mMap.end(); ++iter)
	{
		tagMapMap temp = iter->second;
		saveMap(temp.fileName, temp.tileX, temp.tileY);
	}
}

string drawArea::loadMap(string fileName)
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

	//맵정보와 캐릭터 pos 로드
	tagMapMap tempMapMap;

	vector<string> vArrayI;
	char* tempI;
	char* separatorI = "|";
	char* tokenI;
	tokenI = strtok(str, separatorI);
	vArrayI.push_back(tokenI);
	while (NULL != (tokenI = strtok(NULL, separatorI)))
	{
		vArrayI.push_back(tokenI);
	}

	vector<string> vArray;
	char* temp = (char*)vArrayI[0].c_str();
	char* separator = ",";
	char* token;

	token = strtok(temp, separator);
	vArray.push_back(token);

	while (NULL != (token = strtok(NULL, separator)))
	{
		vArray.push_back(token);
	}

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

	CloseHandle(file);
	for (int i = 0; i < arrSize; ++i)
	{
		tile_maptool* tempTile = new tile_maptool;
		tempTile->init(i%tempMapMap.tileX, i / tempMapMap.tileX);
		bool load = true;
<<<<<<< HEAD
=======

>>>>>>> 82846e949acef4278bed35eb9782212e29590bd0
		if (load)
		{
			tempTile->loadTile(saveTile[i]);
		}
		tempMapMap.vTile.push_back(tempTile);
	}

	if (vArrayI.size() > 1)
	{
		for (int i = 1; i < vArrayI.size(); ++i)
		{
			//"|(int)CHARACTER_INDEX,타일번호(i),from,(vPtrol의사이즈),vPatrol[0],[1],[2],..."
			vector<string> vArray;
			char* temp = (char*)vArrayI[i].c_str();
			char* separator = ",";
			char* token;

			token = strtok(temp, separator);
			vArray.push_back(token);

			while (NULL != (token = strtok(NULL, separator)))
			{
				vArray.push_back(token);
			}

			int tileNum = atoi(vArray[1].c_str());
			tagTile_character tempCharacter;

			tempCharacter.CHARACTER_INDEX = (CHARACTER)atoi(vArray[0].c_str());
			tempCharacter.from = vArray[2];
			

			int patrolSize = atoi(vArray[3].c_str());
			if (patrolSize > 0)
			{
				for (int j = 4; j < vArray.size(); ++j)
				{
					int indexNum = atoi(vArray[j].c_str());
					tempCharacter.vPatrol.push_back({ indexNum%tempMapMap.tileX,indexNum / tempMapMap.tileX });
				}
			}

			tempMapMap.vTile[tileNum]->setCharacterAttribute(tempCharacter.vPatrol);
			tempMapMap.vTile[tileNum]->setCharacterAttribute(tempCharacter.from);
		}
	}

	
	addMap_load(tempMapMap);


	return tempMapMap.fileName;

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

vector<string>* drawArea::loadMapAll()
{
	vector<string>* vString = new vector<string>;

	_finddata_t fd;
	long handle;
	int result = 1;
	int k = 0;
	handle = _findfirst("map\\*.map", &fd);
	if (handle == -1) return NULL;
	while (result != -1)
	{
		string tempName = "./map./";
		tempName.append(fd.name);
		loadMap(tempName);

		string addName = fd.name;
		int ori_length = addName.length();
		(*vString).push_back(addName.erase(ori_length - 4, ori_length));


		result = _findnext(handle, &fd);
	}

	_findclose(handle);

	return vString;
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
	SelectObject(getAreaDC(), holdbrush);
	DeleteObject(hbrush);
	//타일 랜더

	char str[200];

	SetBkMode(getAreaDC(), TRANSPARENT);
	vector<int> vcharTile;
	if (_vCurrentTile != NULL)
	{
		for (int i = 0; i < (*_vCurrentTile).size(); ++i)
		{
			if ((*_vCurrentTile)[i]->getCharacter().CHARACTER_INDEX != CHARACTER_NONE)
			{
				vcharTile.push_back(i);
			}
			(*_vCurrentTile)[i]->Toolrender(getAreaDC(), horzScrollMove, vertScrollMove);
			sprintf(str, "%d", i);
			TextOut(getAreaDC(), (i%tileSizeX)*TILESIZE + TILESIZE/2 - strlen(str)/2*8 - horzScrollMove, (i/tileSizeX)*TILESIZE + 15 - vertScrollMove, str, strlen(str));
		}
	}
	
	for (int i = 0; i < vcharTile.size(); ++i)
	{
		(*_vCurrentTile)[vcharTile[i]]->render(getAreaDC(), horzScrollMove, vertScrollMove);
	}

	if (mouseOnTile())
	{
		tagTile_event tempEv = (*_vCurrentTile)[_tileX + _tileY*tileSizeX]->getEvent();
		switch (tempEv.EVENT_INDEX)
		{
			case EVENT_MOVE:
				sprintf(str, "%d 타일로 이동", tempEv.param1);
				RectangleMake(getAreaDC(), _ptMouse.x - areaStartX, _ptMouse.y - areaStartY, strlen(str) * 10, 35);
				TextOut(getAreaDC(), _ptMouse.x - areaStartX + 20, _ptMouse.y - areaStartY + 10, str, strlen(str));
			break;
			case EVENT_INTERACT:

			break;
			case EVENT_PORT:
				sprintf(str, "\"%s\" 맵으로 이동", tempEv.next.c_str());
				RectangleMake(getAreaDC(), _ptMouse.x - areaStartX, _ptMouse.y - areaStartY, strlen(str)*10, 35);
				TextOut(getAreaDC(), _ptMouse.x - areaStartX + 20, _ptMouse.y - areaStartY + 10, str, strlen(str));
			break;
		}
	}

	if (mouseOnTile())
	{
		tagTile_character tempCr = (*_vCurrentTile)[_tileX + _tileY*tileSizeX]->getCharacter();
		switch (tempCr.CHARACTER_INDEX)
		{
			case CHARACTER_PLAYER_POS:
			{
				if (tempCr.from.size() > 0)
				{
					if (!strcmp(tempCr.from.c_str(), "start"))
					{
						sprintf(str, "시작위치");	
						RectangleMake(getAreaDC(), _ptMouse.x - areaStartX, _ptMouse.y - areaStartY, strlen(str) * 13, 35);

					}
					else
					{
						sprintf(str, "\"%s\"에서 이동", tempCr.from.c_str());
						RectangleMake(getAreaDC(), _ptMouse.x - areaStartX, _ptMouse.y - areaStartY, strlen(str) * 10, 35);
					}
					TextOut(getAreaDC(), _ptMouse.x - areaStartX + 20, _ptMouse.y - areaStartY + 10, str, strlen(str));
				}
			}
			break;
			case CHARACTER_GREENEYE_POS: case CHARACTER_REDEYE_POS: case CHARACTER_JUMPKNIGHT_POS:
			case CHARACTER_GREENSOLDIER_POS: case CHARACTER_BLUESOLDIER_POS: case CHARACTER_NPC_POS:
				if (tempCr.vPatrol.size() != 0)
				{
					HBRUSH hb, hob;
					HPEN hp, hop;
					//hb = (HBRUSH)GetStockObject(NULL_BRUSH);
					hb = CreateSolidBrush(RGB(255, 0, 255));
					hob = (HBRUSH)SelectObject(getAreaDC(), hb);
					hp = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
					hop = (HPEN)SelectObject(getAreaDC(), hp);
					for (int i = 0; i < tempCr.vPatrol.size(); ++i)
					{
						int x = (*_vCurrentTile)[tempCr.vPatrol[i].x + tempCr.vPatrol[i].y*tileSizeX]->getRect().left;
						int y = (*_vCurrentTile)[tempCr.vPatrol[i].x + tempCr.vPatrol[i].y*tileSizeX]->getRect().top;
						RectangleMake(getAreaDC(), x, y, TILESIZE, TILESIZE);
						char patrolNumbering[128];
						sprintf(patrolNumbering, "%d", i + 1);
						SetBkMode(getAreaDC(), TRANSPARENT);
						TextOut(getAreaDC(), x + 10, y + TILESIZE / 2 - 10, patrolNumbering, strlen(patrolNumbering));
					}
					SelectObject(getAreaDC(), hob);
					SelectObject(getAreaDC(), hop);
					DeleteObject(hb);
					DeleteObject(hp);
				}
			break;
		}
	}
	

	//속성
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
		vertScrollMove += 10;
	}
	else
	{
		vertScrollMove -= 10;
	}
}

void drawArea::sendMouseMove(LPARAM lParam)
{
	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		_click = false;
	}
	if (_click)
	{
		vertScrollMove = -_ptMouse.y + temp.y;
		horzScrollMove = -_ptMouse.x + temp.x;
	}
}

void drawArea::addSide(int a)
{
	int k = 0;
	switch (a)
	{
	case 0: //left
		tileSizeX++;
		for (auto i = _vCurrentTile->begin(); i != _vCurrentTile->end();)
		{
			if ((*i)->getIdX() != 0) {
				
				(*i)->init((*i)->getIdX() + 1, k);
				i++;
				continue;
			}

			(*i)->init((*i)->getIdX() + 1, k);
			tile_maptool* temp;
			temp = new tile_maptool;
			temp->init(0, k);
			i = _vCurrentTile->insert(i, temp);
			i++;
			k++;

		}
		break;
	case 1: //top
		tileSizeY++;

		break;
	case 2: //right
		tileSizeX++;

		break;
	case 3: //bottom
		tileSizeY++;

		break;

	}

}



