#include "stdafx.h"
#include "InGame_map.h"


InGame_map::InGame_map()
{
}


InGame_map::~InGame_map()
{
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
		string loadTxt = vString[i];
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


		tagMap tempMap;
		tempMap.mapName = vArray[0];
		tempMap.tileX = atoi(vArray[1].c_str());
		tempMap.tileY = atoi(vArray[2].c_str());

		//이제 타일 로드
		int arrSize = tempMap.tileX*tempMap.tileY;
		SAVELOAD_TILE* saveTile = new SAVELOAD_TILE[arrSize];

		string loadMap = vString[i];
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

			tagTile_character tempChar = *TILEMANAGER->findChracter(saveTile[j].char_key);
			if (tempChar.CHARACTER_INDEX != CHARACTER_NONE)
			{

			}
		}



	}

	//=================================================================================



}
