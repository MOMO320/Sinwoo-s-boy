#include "stdafx.h"
#include "mainSwitch.h"

void mainSwitch::imageSetting()
{
	//캐슬 타일
	IMAGEMANAGER->addImage("캐슬기둥", "./image./mapTile./castle./캐슬기둥.bmp", 200, 350, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("캐슬문타일외", "./image./mapTile./castle./캐슬문타일+끝처리용타일+계단.bmp", 400, 400, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("캐슬바닥타일", "./image./mapTile./castle./캐슬바닥타일.bmp", 200, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("캐슬벽오른쪽타일", "./image./mapTile./castle./캐슬벽오른쪽타일.bmp", 300, 500, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("캐슬벽왼쪽타일", "./image./mapTile./castle./캐슬벽왼쪽타일.bmp", 150, 500, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("캐슬벽윗타일", "./image./mapTile./castle./캐슬벽윗타일.bmp", 500, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("캐슬벽타일", "./image./mapTile./castle./캐슬벽타일.bmp", 400, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("캐슬벽타일2", "./image./mapTile./castle./캐슬벽타일2.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("캐슬벽타일11", "./image./mapTile./castle./캐슬벽타일11.bmp", 150, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("캐슬타일1", "./image./mapTile./castle./캐슬타일1.bmp", 150, 150, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("다리난간", "./image./mapTile./castle./다리난간.bmp", 50, 500, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("하트타일", "./image./mapTile./castle./다리타일4.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("다리타일", "./image./mapTile./castle./다리타일5.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("다리타일2", "./image./mapTile./castle./다리타일66.bmp", 50, 50, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("그림자타일", "./image./mapTile./castle./그림자타일.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("다리", "./image./mapTile./castle./다리(500,450).bmp", 500, 450, true, RGB(255, 0, 255)); //통짜
	IMAGEMANAGER->addImage("다리타일", "./image./mapTile./castle./다리타일(왼오).bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("샛길", "./image./mapTile./castle./샛길.bmp", 50, 50, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("성길", "./image./mapTile./castle./성길.bmp", 150, 500, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("성데코타일", "./image./mapTile./castle./성데코.bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("성데코타일2", "./image./mapTile./castle./성데코2.bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("성문", "./image./mapTile./castle./성문(350,150).bmp", 350, 150, true, RGB(255, 0, 255)); //통짜  ??
	IMAGEMANAGER->addImage("정원장식", "./image./mapTile./castle./정원장식.bmp", 50, 60, true, RGB(255, 0, 255)); //통짜
	IMAGEMANAGER->addImage("정원장식긴것", "./image./mapTile./castle./정원장식긴거.bmp", 100, 250, true, RGB(255, 0, 255));	   //통짜
	IMAGEMANAGER->addImage("정원장식짧은것", "./image./mapTile./castle./정원장식짧은거.bmp", 250, 100, true, RGB(255, 0, 255));//통짜

	IMAGEMANAGER->addFrameImage("캐슬성문", "./image./mapTile./castle./캐슬성문.bmp",400,150,2,1,true, RGB(255, 0, 255)); //프레임 ??
	//마을 타일
	IMAGEMANAGER->addImage("마을장식1", "./image./mapTile./마을./마을장식1.bmp", 100, 100, true, RGB(255, 0, 255)); //통짜
	IMAGEMANAGER->addImage("마을장식타일", "./image./mapTile./마을./마을장식타일.bmp", 200, 200, true, RGB(255, 0, 255)); //데코레이션.
	IMAGEMANAGER->addImage("빨간집", "./image./mapTile./마을./빨간집.bmp", 300, 300, true, RGB(255, 0, 255)); //통짜
	IMAGEMANAGER->addImage("울타리", "./image./mapTile./마을./울타리.bmp", 300, 100, true, RGB(255, 0, 255)); //공용
	IMAGEMANAGER->addImage("파란집", "./image./mapTile./마을./파란집.bmp", 300, 300, true, RGB(255, 0, 255)); //통짜
	IMAGEMANAGER->addImage("풀벽", "./image./mapTile./마을./풀벽.bmp", 50, 100, true, RGB(255, 0, 255)); //통짜
	IMAGEMANAGER->addImage("풀벽가로", "./image./mapTile./마을./풀벽가로.bmp", 150, 50, true, RGB(255, 0, 255)); //통짜

	IMAGEMANAGER->addFrameImage("집문", "./image./mapTile./마을./마을장식1.bmp", 190, 97, 2,1,true, RGB(255, 0, 255)); //프레임
	//던전타일
	IMAGEMANAGER->addImage("갑옷장식", "./image./mapTile./던전타일./갑옷장식.bmp", 50, 50, true, RGB(255, 0, 255)); //통짜
	IMAGEMANAGER->addImage("던전계단", "./image./mapTile./던전타일./던전계단2.bmp", 400, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("던전바닥끝처리", "./image./mapTile./던전타일./던전바닥끝처리.bmp", 200, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("던전타일끝처리", "./image./mapTile./던전타일./던전타일끝처리.bmp", 200, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("던전바닥타일", "./image./mapTile./던전타일./던전바닥타일.bmp", 300, 150, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("던전벽타일", "./image./mapTile./던전타일./던전벽타일(100,100).bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("던전벽타일2", "./image./mapTile./던전타일./던전벽타일(200,200).bmp", 200, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("던전벽타일3", "./image./mapTile./던전타일./던전벽타일(350,400).bmp", 350, 400, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("던전벽타일좌상", "./image./mapTile./던전타일./던전벽타일좌상.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("던전벽타일좌하", "./image./mapTile./던전타일./던전벽타일좌하.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("던전벽타일우상", "./image./mapTile./던전타일./던전벽타일우상.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("던전벽타일우하", "./image./mapTile./던전타일./던전벽타일우하.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("던전물타일", "./image./mapTile./던전타일./던전타일1.bmp", 350, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("던전문", "./image./mapTile./던전타일./문.bmp", 400, 100, true, RGB(255, 0, 255)); //프레임
	IMAGEMANAGER->addImage("보스방진입", "./image./mapTile./던전타일./보스방진입(100,100).bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("던전장식타일", "./image./mapTile./던전타일./장식(MOVE).bmp", 300, 200, true, RGB(255, 0, 255)); //가는것
	IMAGEMANAGER->addImage("던전장식타일2", "./image./mapTile./던전타일./장식2(MOVE).bmp", 300, 400, true, RGB(255, 0, 255)); //가는것
	IMAGEMANAGER->addImage("던전장식타일3", "./image./mapTile./던전타일./장식(UNMOVE).bmp", 200, 250, true, RGB(255, 0, 255)); //못가는것
	IMAGEMANAGER->addImage("철창", "./image./mapTile./던전타일./철창.bmp", 500, 150, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("화덕장식", "./image./mapTile./던전타일./화덕장식.bmp", 100, 100, true, RGB(255, 0, 255));

	//물타일(프레임)
	IMAGEMANAGER->addFrameImage("물타일", "./image./mapTile./water./water.bmp", 1200, 300,24, 6, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("물타일2", "./image./mapTile./water./물2.bmp", 150, 100, 3, 2, false, RGB(255, 0, 255));
	//필드 오브젝트들
	IMAGEMANAGER->addImage("바깥오브젝트", "./image./mapTile./objectTile./outTerriorObject.bmp", 200, 300,true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("돌", "./image./mapTile./objectTile./돌.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("돌2", "./image./mapTile./objectTile./돌2.bmp", 100, 100, true, RGB(255, 0, 255));
	//기본타일들
	IMAGEMANAGER->addImage("일반타일", "./image./mapTile./언더레이어타일./기본타일 50 x 50.bmp", 200, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("길바닥", "./image./mapTile./언더레이어타일./길바닥.bmp", 400, 500, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("절벽", "./image./mapTile./언더레이어타일./절벽.bmp", 600, 600, true, RGB(255, 0, 255));
	//test
	IMAGEMANAGER->addImage("나무", "./image./mapTile./object./tree.bmp", 150, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("testTerrain", "./image./mapTile./test./terrain.bmp", 320, 96, 10, 3, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("testObject", "./image./mapTile./test./object.bmp", 320, 64, 10, 2, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("기본타일", "./image./mapTile./test./기본타일.bmp", 200, 200, 4, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("절벽", "./image./mapTile./test./절벽.bmp", 300, 600, 12, 24, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("오브젝트타일", "./image./mapTile./objectTile./outTerriorObject.bmp", 200, 300, 4, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("맵툴용캐릭터", "./image./mapTile./캐릭터./character.bmp", 440, 72, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("꽃", "./image./maptile./decoration./flower.bmp", 200, 200, 4, 4, true, RGB(255, 0, 255));
}

void mainSwitch::tileSetting()
{
	//타일
	TILEMANAGER->addTerrain("기본지형", "일반타일", { 0,0 }, { 3,3 }, TR_BASIC);
	//POINT arr[5] = { {0,0},{2,2},{0,3},{0,2},{3,1} };
	//TILEMANAGER->addTerrain("기본지형", "기본타일", arr, 5, TR_BASIC);
	TILEMANAGER->addTerrain("캐슬지형", "캐슬바닥타일", { 0,0 }, { 3,0 }, TR_CASTLE);
	TILEMANAGER->addTerrain("캐슬지형2", "그림자타일", { 0,0 }, { 0,0 }, TR_CASTLE);
	TILEMANAGER->addTerrain("다리타일", "다리타일", { 0,0 }, { 1,0 }, TR_CASTLE);
	TILEMANAGER->addTerrain("하트타일", "하트타일", { 0,0 }, { 1,0 }, TR_CASTLE);
	TILEMANAGER->addTerrain("다리타일2", "다리타일2", { 0,0 }, { 1,0 }, TR_CASTLE);
	TILEMANAGER->addTerrain("샛길", "샛길", { 0,0 }, { 0,0 }, TR_CASTLE);
	TILEMANAGER->addTerrain("바깥타일", "바깥오브젝트", { 0,0 }, { 3,5 }, TR_BASIC);
	TILEMANAGER->addTerrain("던전바닥끝처리", "던전바닥끝처리", { 0,0 }, { 3,0 }, TR_DENGEON);
	TILEMANAGER->addTerrain("던전바닥타일", "던전바닥타일", { 0,0 }, { 5,2 }, TR_DENGEON);
	TILEMANAGER->addTerrain("보스방진입", "보스방진입", { 0,0 }, { 1,1 }, TR_DENGEON);
	//POINT arr2[1] = { { 0,3} };
	TILEMANAGER->addObject("오브젝트타일", "오브젝트타일", { 0,2 }, { 1,1 }, { 0,0 }, OBJECT_PICK);
	TILEMANAGER->addObject("바깥오브젝트2", "돌", { 0,0 }, { 2,2 }, { 0,0 }, OBJECT_PICK);
	TILEMANAGER->addObject("바깥오브젝트3", "돌2", { 0,0 }, { 2,2 }, { 0,0 }, OBJECT_PICK);

	TILEMANAGER->addObject("트리", "나무", { 0,0 }, { 3,2 }, { 0,100 }, OBJECT_TREE);

	TILEMANAGER->addCharacter("플레이어", "맵툴용캐릭터", CHARACTER_PLAYER_POS, { 2,22 });
	//데코======
	POINT flowerArr1[4] = { {0,0},{1,0},{2,0},{3,0} };
	TILEMANAGER->addDecoration("꽃", "꽃", DECO_LEFT_TOP, true, flowerArr1, 4, 0);
	POINT flowerArr2[4] = { {0,1},{1,1},{2,1}, {3,1} };
	TILEMANAGER->addDecoration("꽃", "꽃", DECO_LEFT_BOTTOM, true, flowerArr2, 4, 0);
	POINT flowerArr3[4] = { { 0,2 },{ 1,2 },{ 2,2},{ 3,2 } };
	TILEMANAGER->addDecoration("꽃", "꽃", DECO_RIGHT_TOP, true, flowerArr3, 4, 0);
	POINT flowerArr4[4] = { { 0,3 },{ 1,3 },{ 2,3 },{ 3,3 } };
	TILEMANAGER->addDecoration("꽃", "꽃", DECO_RIGHT_BOTTOM, true, flowerArr4, 4, 0);
	POINT roadArr[1] = { {0,0} };
	POINT roadArr2[1] = { { 1,0 } };
	TILEMANAGER->addDecoration("성데코타일", "성데코타일", DECO_LEFT_BOTTOM, false, roadArr, 1, 0);
	TILEMANAGER->addDecoration("성데코타일", "성데코타일", DECO_LEFT_BOTTOM, false, roadArr2, 1, 0);
	TILEMANAGER->addDecoration("성데코타일", "성데코타일2", DECO_LEFT_BOTTOM, false, roadArr, 1, 0);
	TILEMANAGER->addDecoration("성데코타일", "성데코타일2", DECO_LEFT_BOTTOM, false, roadArr2, 1, 0);
	POINT townArr[12] = { {0,0},{0,1},{0,2},{0,3},{1,0},{1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3} };//수정해야됨
	TILEMANAGER->addDecoration("마을장식타일", "마을장식타일", DECO_LEFT_TOP, false, townArr, 12, 0); //수정해야됨
	POINT fence[12] = { {0,0},{0,1},{0,2},{0,3},{0,4},{0,5},{1,0},{1,1},{1,2},{1,3},{1,4},{1,5} };	//수정해야됨
	TILEMANAGER->addDecoration("울타리", "울타리", DECO_LEFT_BOTTOM, false, fence, 12, 0);		   	//수정해야됨

	//물
	POINT waterArr[3] = { {0,0},{1,0},{2,0} };
	TILEMANAGER->addDecoration("물타일2", "물타일2", DECO_LEFT_BOTTOM, true, waterArr, 3, 0);
	POINT waterArr2[3] = { {0,1},{1,1},{2,1} };
	TILEMANAGER->addDecoration("물타일", "물타일2", DECO_LEFT_BOTTOM, true, waterArr2, 3, 0);
	POINT wtArr[3] = { {2,4},{10,4},{18,4} };
	TILEMANAGER->addDecoration("물1", "물타일", DECO_LEFT_BOTTOM, true, wtArr, 3, 0);
	POINT wtArr2[3] = { {2,5},{10,5},{18,5} };
	TILEMANAGER->addDecoration("물2", "물타일", DECO_LEFT_BOTTOM, true, wtArr2, 3, 0);
	//필드오브젝트
	TILEMANAGER->addObject("바깥오브젝트", "바깥오브젝트", { 0,0 }, { 3,5 }, OBJECT_OUTSIDE);
	//캐슬타일
	//TILEMANAGER->addObject("기둥", "캐슬기둥", { 0,0 }, {4,6}, OBJECT_CASTLE);
	TILEMANAGER->addObject("기둥", "캐슬기둥", { 0,0 }, { 4,6 }, { 0,0 }, OBJECT_CASTLE);
	TILEMANAGER->addObject("캐슬문타일외", "캐슬문타일외", { 0,0 }, { 7 ,7 }, OBJECT_CASTLEPART);
	TILEMANAGER->addObject("캐슬벽오른쪽타일", "캐슬벽오른쪽타일", { 0,0 }, { 5,9 }, OBJECT_CASTLEPART2);
	TILEMANAGER->addObject("캐슬벽왼쪽타일", "캐슬벽왼쪽타일", { 0,0 }, { 2,9 }, OBJECT_CASTLEPART3);
	TILEMANAGER->addObject("캐슬벽윗타일", "캐슬벽윗타일", { 0,0 }, { 9,1 }, OBJECT_CASTLEPART4);
	TILEMANAGER->addObject("캐슬벽타일", "캐슬벽타일", { 0,0 }, { 7,5 }, OBJECT_CASTLEPART5);
	TILEMANAGER->addObject("캐슬벽타일2", "캐슬벽타일2",{0, 0}, { 1,1 }, OBJECT_CASTLEPART6);
	TILEMANAGER->addObject("캐슬벽타일11", "캐슬벽타일11", { 0,0 }, { 2,1 }, OBJECT_CASTLEPART7);
	TILEMANAGER->addObject("캐슬타일1", "캐슬타일1", { 0,0 }, { 2,2 }, OBJECT_CASTLEPART8);
	TILEMANAGER->addObject("다리난간", "다리난간", { 0,0 }, { 1,10 }, { 0,0 }, OBJECT_BRIDGE);
	TILEMANAGER->addObject("성문", "성문", { 0,0 }, { 7,3 }, { 0,0 }, OBJECT_ENTRANCE);
	TILEMANAGER->addObject("정원장식", "정원장식", { 0,0 }, { 0,0 }, OBJECT_GARDEN);
	TILEMANAGER->addObject("정원장식2", "정원장식긴것", { 0,0 }, { 2,5 }, { 0,0 }, OBJECT_GARDEN);
	TILEMANAGER->addObject("정원장식3", "정원장식짧은것", { 0,0 }, { 5,2 }, { 0,0 }, OBJECT_GARDEN);

	//마을타일
	TILEMANAGER->addObject("마을장식", "마을장식1", { 0,0 }, { 2,2 }, { 0,0 }, OBJECT_TOWN);
	TILEMANAGER->addObject("빨간집", "빨간집", { 0,0 }, { 6,6 }, { 0,0 }, OBJECT_TOWN);
	TILEMANAGER->addObject("파란집", "파란집", { 0,0 }, { 6,6 }, { 0,0 }, OBJECT_TOWN);
	TILEMANAGER->addObject("풀벽", "풀벽", { 0,0 }, { 1,2 }, { 0,0 }, OBJECT_TOWN);
	TILEMANAGER->addObject("풀벽가로", "풀벽가로", { 0,0 }, { 3,1 }, { 0,0 }, OBJECT_TOWN);

	//던전타일
	TILEMANAGER->addObject("갑옷장식", "갑옷장식", { 0,0 }, { 1,1 }, { 0,0 }, OBJECT_DENGEON);
	TILEMANAGER->addObject("던전계단", "던전계단", { 0,0 }, { 2,2 }, { 0,0 }, OBJECT_DENGEON);
	TILEMANAGER->addObject("던전계단2", "던전계단", { 2,0 }, { 2,2 }, { 0,0 }, OBJECT_DENGEON);
	TILEMANAGER->addObject("던전계단3", "던전계단", { 4,0 }, { 2,2 }, { 0,0 }, OBJECT_DENGEON);
	TILEMANAGER->addObject("던전계단4", "던전계단", { 6,0 }, { 2,2 }, { 0,0 }, OBJECT_DENGEON);

	TILEMANAGER->addObject("던전벽타일좌상", "던전벽타일좌상", { 0,0 }, { 2,2 }, { 0, 0}, OBJECT_DENGEON4);
	TILEMANAGER->addObject("던전벽타일좌하", "던전벽타일좌하", { 0,0 }, { 2,2 }, { 0, 0 }, OBJECT_DENGEON4);
	TILEMANAGER->addObject("던전벽타일우상", "던전벽타일우상", { 0,0 }, { 2,2 }, { 0, 0 }, OBJECT_DENGEON4);
	TILEMANAGER->addObject("던전벽타일우하", "던전벽타일우하", { 0,0 }, { 2,2 }, { 0, 0 }, OBJECT_DENGEON4);
	TILEMANAGER->addObject("던전벽타일2", "던전벽타일2", { 0,0 }, { 3,3 }, OBJECT_DENGEON2);
	TILEMANAGER->addObject("던전타일끝처리", "던전타일끝처리", { 0,0 }, { 3,0 }, OBJECT_DENGEON2);
	TILEMANAGER->addObject("던전벽타일3", "던전벽타일3", { 0,0 }, { 6,7 }, OBJECT_DENGEON3);
	TILEMANAGER->addObject("던전물타일", "던전물타일", { 0,0 }, { 7,4 }, { 0,0 }, OBJECT_DENGEON);
	TILEMANAGER->addObject("화덕장식", "화덕장식", { 0,0 }, { 2,2 }, { 0,0 }, OBJECT_DENGEON);
}