#include "stdafx.h"
#include "mainSwitch.h"

void mainSwitch::imageSetting()
{
	IMAGEMANAGER->addImage("나무", "./image./mapTile./object./tree.bmp", 150, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("testTerrain", "./image./mapTile./test./terrain.bmp", 320, 96, 10, 3, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("testObject", "./image./mapTile./test./object.bmp", 320, 64, 10, 2, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("기본타일", "./image./mapTile./test./기본타일.bmp", 200, 200, 4, 4, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("절벽", "./image./mapTile./test./절벽.bmp", 300, 600, 12, 24, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("오브젝트타일", "./image./mapTile./objectTile./outTerriorObject.bmp", 200, 300, 4, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("맵툴용캐릭터", "./image./mapTile./캐릭터./character.bmp", 440, 72, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("꽃", "./image./maptile./decoration./flower.bmp", 200, 200, 4, 4, true, RGB(255, 0, 255));
}

void mainSwitch::tileSetting()
{

	//TILEMANAGER->addTerrain("기본지형", "기본타일", { 0,0 }, { 2,1 }, TR_BASIC);
	POINT arr[5] = { {0,0},{2,2},{0,3},{0,2},{3,1} };
	TILEMANAGER->addTerrain("기본지형", "기본타일", arr, 5, TR_BASIC);

	//POINT arr2[1] = { { 0,3} };
	TILEMANAGER->addObject("오브젝트타일", "오브젝트타일", { 0,2 }, { 1,1 }, { 0,0 }, OBJECT_PICK);

	TILEMANAGER->addObject("트리", "나무", { 0,0 }, { 3,2 }, { 0,100 }, OBJECT_STOP);

	TILEMANAGER->addCharacter("플레이어", "맵툴용캐릭터", CHARACTER_PLAYER_POS, { 2,22 });

	POINT flowerArr1[4] = { {0,0},{1,0},{2,0},{3,0} };
	TILEMANAGER->addDecoration("꽃", "꽃", DECO_LEFT_TOP, true, flowerArr1, 4, 1);
	POINT flowerArr2[4] = { {0,1},{1,1},{2,1}, {3,1} };
	TILEMANAGER->addDecoration("꽃", "꽃", DECO_LEFT_BOTTOM, true, flowerArr2, 4, 4);
	POINT flowerArr3[4] = { { 0,2 },{ 1,2 },{ 2,2},{ 3,2 } };
	TILEMANAGER->addDecoration("꽃", "꽃", DECO_RIGHT_TOP, true, flowerArr3, 4, 2);
	POINT flowerArr4[4] = { { 0,3 },{ 1,3 },{ 2,3 },{ 3,3 } };
	TILEMANAGER->addDecoration("꽃", "꽃", DECO_RIGHT_BOTTOM, true, flowerArr4, 4, 8);
}