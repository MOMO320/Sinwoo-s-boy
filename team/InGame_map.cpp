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
	changeMap("start");

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

void InGame_map::render()	  
{
	if (_currentMapTile != NULL)
	{
		for (int i = 0; i < _currentMapTile->size(); ++i)
		{
			(*_currentMapTile)[i]->render();
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

		char str[128];
		DWORD read;
		string loadTxt = "./map./";
		loadTxt.append(vString[i]);
		loadTxt.append(".txt");


		file = CreateFile(loadTxt.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		ReadFile(file, str, 128, &read, NULL);

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
			/* 인게임에선 안쓸듯!
			tagTile_character tempChar = *TILEMANAGER->findChracter(saveTile[j].char_key);
			if (tempChar.CHARACTER_INDEX != CHARACTER_NONE)
			{

			}*/
		}



		_mMapInfo.insert(make_pair(tempMap.mapName, tempMap));
	}

	//=================================================================================
}

void InGame_map::changeMap(string mapkey)
{
	auto iter = _mMapInfo.find(mapkey);
	if (iter != _mMapInfo.end())
	{
		_currentMapName = iter->second.mapName;
		_tileXN = iter->second.tileX;
		_tileYN = iter->second.tileY;
		_currentMapTile = &iter->second.vTile;
		_currentPos = &iter->second.vPos;
	}

}
