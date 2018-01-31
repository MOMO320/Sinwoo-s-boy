#include "stdafx.h"
#include "InGame_map.h"


InGame_map::InGame_map()
{
}


InGame_map::~InGame_map()
{
}


HRESULT InGame_map::init()	  
{
	loadMap();
	changeMap("필드");
	return S_OK;
}

void InGame_map::release()	  
{
}

void InGame_map::update()	  
{
	if (_currentMapTile != NULL)
	{
		for (int i = 0; i < _currentMapTile->size(); ++i)
		{
			(*_currentMapTile)[i]->update();
		}
	}

	
}

void InGame_map::render(HDC hdc)	  
{
	if (_currentMapTile != NULL)
	{
		for (int i = 0; i < _currentMapTile->size(); ++i)
		{
			(*_currentMapTile)[i]->render(hdc);
		}
	}

}

void InGame_map::loadMap()
{

	//폴더에서 .map파일명 벡터에 모두 저장====================================================
	vector<string> vString;

	_finddata_t fd;
	long handle;
	int result = 1;
	int k = 0;
	handle = _findfirst("map\\*.map", &fd);
	if (handle == -1) return ;
	while (result != -1)
	{
		string tempName = "./map./";
		tempName.append(fd.name);
		// ^^ tempName이 "./map./___.map"이 된다.

		string addName = fd.name;
		int ori_length = addName.length();
		vString.push_back(addName.erase(ori_length - 4, ori_length));
		//(*vString)에는 "./map./___"만 담기게 된다.

		result = _findnext(handle, &fd);
	}

	_findclose(handle);
	//=================================================================================

	// 본격 로드 시작 ===================================================================
	for (int i = 0; i < vString.size(); ++i)
	{

		HANDLE file;

		char str[4096];
		DWORD read;
		string loadTxt = "./map./";
		loadTxt.append(vString[i]);
		loadTxt.append(".txt");


		file = CreateFile(loadTxt.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		ReadFile(file, str, 4096, &read, NULL);

		CloseHandle(file);

		//맵정보 & pos 로드===========================================================
		tagMap tempMap;

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

		tempMap.mapName = vArray[0];
		tempMap.tileX = atoi(vArray[1].c_str());
		tempMap.tileY = atoi(vArray[2].c_str());

		
		
		if (vArrayI.size() > 1)
		{
			for (int i = 1; i < vArrayI.size(); ++i)
			{
				tagCharPos* tempPos = new tagCharPos;
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

				tempPos->mapName = tempMap.mapName;
				tempPos->index = { atoi(vArray[1].c_str()) % tempMap.tileX,atoi(vArray[1].c_str()) / tempMap.tileX};
				tempPos->CHAR_INDEX = (CHARACTER)atoi(vArray[0].c_str());
				tempPos->from = vArray[2];
				
				int patrolSize = atoi(vArray[3].c_str());
				if (patrolSize > 0)
				{
					for (int j = 4; j < vArray.size(); ++j)
					{
						int patrolNum = atoi(vArray[j].c_str());
						tempPos->vPatrol.push_back({ patrolNum%tempMap.tileX,patrolNum / tempMap.tileX });
					}
				}
				tempMap.vPos.push_back(tempPos);
			}
		}

		//=========================================================================


		//이제 타일 로드
		int arrSize = tempMap.tileX*tempMap.tileY;
		SAVELOAD_TILE* saveTile = new SAVELOAD_TILE[arrSize];

		string loadMap = "./map./";
		loadMap.append(vString[i]);
		loadMap.append(".map");

		file = CreateFile(loadMap.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		ReadFile(file, saveTile, sizeof(SAVELOAD_TILE)*arrSize, &read, NULL);

		CloseHandle(file);

		for (int j = 0; j < arrSize; ++j)
		{
			tile_inGame* tempTile = new tile_inGame;
			tempTile->init(j%tempMap.tileX, j / tempMap.tileX);
			tempTile->loadTile(saveTile[j]);
			tempMap.vTile.push_back(tempTile);
			
			if (!strcmp(saveTile[j].obj_key.c_str(), "돌") ||
				!strcmp(saveTile[j].obj_key.c_str(), "항아") ||
				!strcmp(saveTile[j].obj_key.c_str(), "상좌") ||
				!strcmp(saveTile[j].obj_key.c_str(), "빅좌") ||
				!strcmp(saveTile[j].obj_key.c_str(), "오브젝트타일"))
			{
				if (saveTile[j].obj_parent.x + saveTile[j].obj_parent.y*tempMap.tileX == j)
				{
					tagObjPos* tempOP = new tagObjPos;
					tempOP->index = { j%tempMap.tileX, j / tempMap.tileX };
					
					if (!strcmp(saveTile[j].obj_key.c_str(), "돌")) tempOP->OPOSINDEX = POS_STONE;
					else if (!strcmp(saveTile[j].obj_key.c_str(), "항아")) tempOP->OPOSINDEX = POS_BOTTLE;
					else if (!strcmp(saveTile[j].obj_key.c_str(), "상좌")) tempOP->OPOSINDEX = POS_BOX;
					else if (!strcmp(saveTile[j].obj_key.c_str(), "빅좌")) tempOP->OPOSINDEX = POS_GREATEBOX;
					else if (!strcmp(saveTile[j].obj_key.c_str(), "오브젝트타일")) tempOP->OPOSINDEX = POS_BUSH;

					tempOP->mapName = tempMap.mapName;
					tempMap.vOPos.push_back(tempOP);
				}
			}
		}

		ASTARINFO->init(tempMap.mapName, tempMap.tileX, tempMap.tileY, &tempMap.vTile);

		_mMapInfo.insert(make_pair(tempMap.mapName, tempMap));
	}

	//=================================================================================
}

void InGame_map::changeMap(string mapkey)
{
	auto iter = _mMapInfo.find(mapkey);
	if (iter != _mMapInfo.end())
	{
		string prevMap = _currentMapName;
		_currentMapName = iter->second.mapName;
		_tileXN = iter->second.tileX;
		_tileYN = iter->second.tileY;
		_currentMapTile = &iter->second.vTile;
		_currentPos = &iter->second.vPos;
		_currentOPos = &iter->second.vOPos;


		if (!strcmp(_currentMapName.c_str(), "shop"))
		{
			shopInitF();
		}

		//eraseEnemyF();

		for (int i = 0; i < (*_currentPos).size(); ++i)
		{
			switch ((*_currentPos)[i]->CHAR_INDEX)
			{
			case CHARACTER_PLAYER_POS:
				if (!strcmp((*_currentPos)[i]->from.c_str(), prevMap.c_str()))
				{
					initPF((*_currentPos)[i]->index);
				}
				else if (!strcmp((*_currentPos)[i]->from.c_str(), "성성성"))
				{
					initFirst((*_currentPos)[i]->index);
				}
			break;
			case CHARACTER_GREENSOLDIER_POS:
				addGreenSoldier((*_currentPos)[i]->index, &(*_currentPos)[i]->vPatrol);
			break;
			}
		}

		for (int i = 0; i < (*_currentOPos).size(); ++i)
		{
			switch ((*_currentOPos)[i]->OPOSINDEX)
			{
				//initBottle, initBox, initStone, initGBox, initBush
			case POS_BOTTLE:
				initBottle({ (*_currentOPos)[i]->index.x*TILESIZE ,(*_currentOPos)[i]->index.y*TILESIZE }, _player);
			break;
			case POS_BOX:
				initBox({ (*_currentOPos)[i]->index.x*TILESIZE ,(*_currentOPos)[i]->index.y*TILESIZE }, _player);
			break;
			case POS_STONE:
				initStone({ (*_currentOPos)[i]->index.x*TILESIZE ,(*_currentOPos)[i]->index.y*TILESIZE }, _player);
			break;
			case POS_GREATEBOX:
				initGBox({ (*_currentOPos)[i]->index.x*TILESIZE ,(*_currentOPos)[i]->index.y*TILESIZE }, _player);
			break;
			case POS_BUSH:
				initBush({ (*_currentOPos)[i]->index.x*TILESIZE ,(*_currentOPos)[i]->index.y*TILESIZE }, _player);
			break;
			}
		}


	}


	CAMERAMANAGER->setStartBackground(0, 0);
	CAMERAMANAGER->setBackground((_tileXN)*TILESIZE, (_tileYN)*TILESIZE);
		ASTARINFO->changeAstar(mapkey);
	
}

OBJECT InGame_map::checkPickEvent(int tileX, int tileY, int eventNum)
{
	//_eventNum = eventNum;
	//
	//if (_eventNum == EVENTPICK)
	//{
	//	if ((*_currentMapTile)[tileX + tileY * _tileXN]->getigEVENT().ACT_INDEX == ACT_CONDITION_PICK_UP
	//		&& (*_currentMapTile)[tileX + tileY * _tileXN]->getiGOBJ().OBJ_INDEX == OBJECT_PICK)
	//	{
	//		(*_currentMapTile)[tileX + tileY * _tileXN]->eraseObject();
	//		return OBJECT_PICK; //오브젝트 인덱스 반환
	//	}
	//}
	//if (_eventNum == EVENTBOX)
	//{
	//	if ((*_currentMapTile)[tileX + tileY * _tileXN]->getigEVENT().ACT_INDEX == ACT_CONDITION_PICK_UP
	//		&& (*_currentMapTile)[tileX + tileY * _tileXN]->getiGOBJ().OBJ_INDEX == OBJECT_BOX)
	//	{
	//		POINT temp = (*_currentMapTile)[tileX + tileY * _tileXN]->getIndex();
	//			(*_currentMapTile)[temp.x + temp.y * _tileXN]->setObjMaxFrame(1);
	//		return OBJECT_BOX;
	//	}
	//}
	return OBJECT_NONE;
}

void InGame_map::checkMapEvent(int tileX, int tileY, int eventNum)
{
	if ((*_currentMapTile)[tileX + tileY * _tileXN]->getigEVENT().ACT_INDEX == ACT_CONDITION_INTERSECTTILE
		&& (*_currentMapTile)[tileX + tileY * _tileXN]->getigEVENT().EVENT_INDEX == EVENT_PORT)
	{
		changeMap((*_currentMapTile)[tileX + tileY * _tileXN]->getigEVENT().next);
	}
}

void InGame_map::checkMoveEvent(int tileX, int tileY, int eventNum)
{
	if ((*_currentMapTile)[tileX + tileY * _tileXN]->getigEVENT().ACT_INDEX == ACT_CONDITION_INTERSECTTILE
		&& (*_currentMapTile)[tileX + tileY * _tileXN]->getigEVENT().EVENT_INDEX == EVENT_INTERACT)
	{
		POINT temp = (*_currentMapTile)[(*_currentMapTile)[tileX + tileY * _tileXN]->getigEVENT().param1]->getObjParent();
		if(temp.x != -1 && temp.y != -1 )
		(*_currentMapTile)[temp.x + temp.y * _tileXN]->setObjMaxFrame(1);

	}

	//if ((*_currentMapTile)[tileX + tileY * _tileXN]->getigEVENT().ACT_INDEX == ACT_CONDITION_KEYDOWN
	//	&& (*_currentMapTile)[tileX + tileY * _tileXN]->getigEVENT().EVENT_INDEX == EVENT_MOVE)
	//{
	//	(*_currentMapTile)[tileX + tileY * _tileXN])
	//}
}

OBJECT InGame_map::checkAttackEvent(int tileX, int tileY, int eventNum)
{

	//EVENT_INDEX -> INTERACT MOMVE MAPCHANGE
	//ACT_CONDITION -> 인터섹트렉트, 공격키, 드는키.
	//_eventNum = eventNum;
	//if ((*_currentMapTile)[tileX + tileY * _tileXN]->getigEVENT().ACT_INDEX == ACT_CONDITION_PICK_UP
	//	&& (*_currentMapTile)[tileX + tileY * _tileXN]->getiGOBJ().OBJ_INDEX == OBJECT_PICK && _eventNum == EVENTATTACK)
	//{
	//	(*_currentMapTile)[tileX + tileY * _tileXN]->eraseObject();
	//	return OBJECT_PICK;
	//}
	//
	return OBJECT_NONE;
}
