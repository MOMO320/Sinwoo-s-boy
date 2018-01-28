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
	IMAGEMANAGER->addImage("성문", "./image./mapTile./castle./성문(350,150).bmp", 350, 150, true, RGB(255, 0, 255)); //통짜  ??
	IMAGEMANAGER->addImage("정원장식", "./image./mapTile./castle./정원장식.bmp", 50, 60, true, RGB(255, 0, 255)); //통짜
	IMAGEMANAGER->addImage("정원장식긴것", "./image./mapTile./castle./정원장식긴거.bmp", 100, 250, true, RGB(255, 0, 255));	   //통짜
	IMAGEMANAGER->addImage("정원장식짧은것", "./image./mapTile./castle./정원장식짧은거.bmp", 250, 100, true, RGB(255, 0, 255));//통짜

	IMAGEMANAGER->addFrameImage("캐슬성문", "./image./mapTile./castle./캐슬성문.bmp", 400, 150, 2, 1, true, RGB(255, 0, 255)); //프레임 ??
																													   //마을 타일
	IMAGEMANAGER->addImage("마을장식1", "./image./mapTile./마을./마을장식1.bmp", 100, 100, true, RGB(255, 0, 255)); //통짜
	IMAGEMANAGER->addImage("마을장식타일", "./image./mapTile./마을./마을장식타일.bmp", 200, 200, true, RGB(255, 0, 255)); //데코레이션.
	IMAGEMANAGER->addImage("빨간집", "./image./mapTile./마을./빨간집.bmp", 300, 300, true, RGB(255, 0, 255)); //통짜
	IMAGEMANAGER->addImage("울타리", "./image./mapTile./마을./울타리.bmp", 300, 100, true, RGB(255, 0, 255)); //공용
	IMAGEMANAGER->addImage("파란집", "./image./mapTile./마을./파란집.bmp", 300, 300, true, RGB(255, 0, 255)); //통짜
	IMAGEMANAGER->addImage("풀벽", "./image./mapTile./마을./풀벽.bmp", 50, 100, true, RGB(255, 0, 255)); //통짜
	IMAGEMANAGER->addImage("풀벽가로", "./image./mapTile./마을./풀벽가로.bmp", 150, 50, true, RGB(255, 0, 255)); //통짜

	IMAGEMANAGER->addFrameImage("집문", "./image./mapTile./마을./마을장식1.bmp", 190, 97, 2, 1, true, RGB(255, 0, 255)); //프레임
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
	IMAGEMANAGER->addImage("던전장식타일3", "./image./mapTile./던전타일./장식(UNMOVE).bmp", 200, 250, true, RGB(255, 0, 255)); //가는것
	IMAGEMANAGER->addImage("던전장식타일4", "./image./mapTile./던전타일./장식UNMOVE.bmp", 300, 200, true, RGB(255, 0, 255)); //못가는것
	IMAGEMANAGER->addImage("철창", "./image./mapTile./던전타일./철창.bmp", 500, 150, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("화덕장식", "./image./mapTile./던전타일./화덕장식.bmp", 100, 100, true, RGB(255, 0, 255));

	//물타일(프레임)
	IMAGEMANAGER->addFrameImage("물타일", "./image./mapTile./water./water.bmp", 1200, 300, 24, 6, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("물타일2", "./image./mapTile./water./물2.bmp", 150, 100, 3, 2, false, RGB(255, 0, 255));
	//필드 오브젝트들
	IMAGEMANAGER->addImage("바깥오브젝트", "./image./mapTile./objectTile./outTerriorObject.bmp", 200, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("돌", "./image./mapTile./objectTile./돌.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("돌2", "./image./mapTile./objectTile./돌2.bmp", 100, 100, true, RGB(255, 0, 255));
	//기본타일들
	IMAGEMANAGER->addImage("일반타일", "./image./mapTile./언더레이어타일./기본타일 50 x 50.bmp", 200, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("길바닥", "./image./mapTile./언더레이어타일./길바닥.bmp", 400, 500, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("절벽33", "./image./mapTile./언더레이어타일./절벽.bmp", 600, 600, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("절벽1", "./image./mapTile./언더레이어타일./절벽1.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("절벽2", "./image./mapTile./언더레이어타일./절벽2.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("절벽3", "./image./mapTile./언더레이어타일./절벽3.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("절벽4", "./image./mapTile./언더레이어타일./절벽4.bmp", 300, 300, true, RGB(255, 0, 255));
	//test
	IMAGEMANAGER->addImage("나무", "./image./mapTile./object./tree.bmp", 150, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("testTerrain", "./image./mapTile./test./terrain.bmp", 320, 96, 10, 3, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("testObject", "./image./mapTile./test./object.bmp", 320, 64, 10, 2, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("기본타일", "./image./mapTile./test./기본타일.bmp", 200, 200, 4, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("절벽", "./image./mapTile./test./절벽.bmp", 300, 600, 12, 24, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("오브젝트타일", "./image./mapTile./objectTile./outTerriorObject.bmp", 200, 300, 4, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("맵툴용캐릭터", "./image./mapTile./캐릭터./character.bmp", 440, 72, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("꽃", "./image./maptile./decoration./flower.bmp", 200, 200, 4, 4, true, RGB(255, 0, 255));

	//절벽(이거로 통일)
	IMAGEMANAGER->addImage("절벽11", "./image./mapTile./절벽타일./절벽타일11.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("절벽111", "./image./mapTile./절벽타일./절벽타일111.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("절벽1111", "./image./mapTile./절벽타일./절벽타일1111.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("절벽11111", "./image./mapTile./절벽타일./절벽타일11111.bmp", 300, 300, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("절벽22", "./image./mapTile./절벽타일./절벽타일22.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("절벽222", "./image./mapTile./절벽타일./절벽타일222.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("절벽2222", "./image./mapTile./절벽타일./절벽타일2222.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("절벽22222", "./image./mapTile./절벽타일./절벽타일22222.bmp", 300, 300, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("절벽33", "./image./mapTile./절벽타일./절벽타일33.bmp", 200, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("절벽333", "./image./mapTile./절벽타일./절벽타일333.bmp", 200, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("절벽3333", "./image./mapTile./절벽타일./절벽타일3333.bmp", 200, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("절벽33333", "./image./mapTile./절벽타일./절벽타일33333.bmp", 200, 200, true, RGB(255, 0, 255));

	//길바닥(이놈으로 통일)
	IMAGEMANAGER->addImage("길바닥11", "./image./mapTile./길바닥./길바닥11.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("길바닥22", "./image./mapTile./길바닥./길바닥22.bmp", 300, 200, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("길그림자1", "./image./mapTile./길바닥./길그림자1.bmp", 300, 150, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("길그림자2", "./image./mapTile./길바닥./길그림자2.bmp", 300, 150, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("길그림자3", "./image./mapTile./길바닥./길그림자3.bmp", 300, 150, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("길줄무늬", "./image./mapTile./길바닥./길줄무늬.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("길줄무늬22", "./image./mapTile./길바닥./길줄무늬22.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("길줄무늬33", "./image./mapTile./길바닥./길줄무늬33.bmp", 300, 400, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("길줄무늬44", "./image./mapTile./길바닥./길줄무늬44.bmp", 300, 400, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("길줄무늬55", "./image./mapTile./길바닥./길줄무늬55.bmp", 300, 400, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("길경계선1", "./image./mapTile./길바닥./길경계선1.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("길경계선2", "./image./mapTile./길바닥./길경계선2.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("길경계선3", "./image./mapTile./길바닥./길경계선3.bmp", 300, 300, true, RGB(255, 0, 255));

	//실내인테리어들, 던전포함(오브젝트)
	IMAGEMANAGER->addImage("등불", "./image./mapTile./장식./큰등불(100,100).bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("큰등불", "./image./mapTile./장식./큰등불(프레임)(100,100).bmp", 300, 100,3 ,1,true, RGB(255, 0, 255));  //프레임
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

	//절벽33
	//TILEMANAGER->addObject("절벽", "절벽1", { 0,0 }, { 5,5 }, OBJECT_HILL);
	//TILEMANAGER->addObject("절벽", "절벽2", { 0,0 }, { 5,5 }, OBJECT_HILL);
	//TILEMANAGER->addObject("절벽", "절벽3", { 0,0 }, { 5,5 }, OBJECT_HILL);
	//TILEMANAGER->addObject("절벽", "절벽4", { 0,0 }, { 5,5 }, OBJECT_HILL);

	//TILEMANAGER->addObject("트리", "나무", { 0,0 }, { 3,2 }, { 0,100 }, OBJECT_STOP);

	TILEMANAGER->addCharacter("플레이어", "맵툴용캐릭터", CHARACTER_PLAYER_POS, { 2,22 });
	//일반장식
	POINT flowerArr1[4] = { { 0,0 },{ 1,0 },{ 2,0 },{ 3,0 } };
	TILEMANAGER->addDecoration("꽃", "꽃", DECO_EMPTY, true, flowerArr1, 4, { 0,0 }, 0,0);
	POINT flowerArr2[4] = { { 0,1 },{ 1,1 },{ 2,1 },{ 3,1 } };
	TILEMANAGER->addDecoration("꽃", "꽃", DECO_EMPTY, true, flowerArr2, 4, { 0,0 }, 0,1);
	POINT flowerArr3[4] = { { 0,2 },{ 1,2 },{ 2,2 },{ 3,2 } };
	TILEMANAGER->addDecoration("꽃", "꽃", DECO_EMPTY, true, flowerArr3, 4, { 0,0 }, 0,2);
	POINT flowerArr4[4] = { { 0,3 },{ 1,3 },{ 2,3 },{ 3,3 } };
	TILEMANAGER->addDecoration("꽃", "꽃", DECO_EMPTY, true, flowerArr4, 4, { 0,0 }, 0,3);

	POINT roadArr[1] = { { 0,0 } };
	POINT roadArr2[1] = { { 1,0 } };

	TILEMANAGER->addDecoration("성데코타일", "성데코타일", DECO_EMPTY, false, roadArr, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("성데코타일", "성데코타일", DECO_EMPTY, false, roadArr2, 1, { 0,0 }, 0,0);

	//던전장식타일2
	POINT dec[1] = { {0,0} };
	POINT dec1[1] = { {1,0} };
	POINT dec2[1] = { {2,0} };
	POINT dec3[1] = { {3,0} };
	POINT dec4[1] = { { 4,0 } };
	POINT dec5[1] = { { 5,0 } };
	POINT decc[1] = { {0,1} };
	POINT decc1[1] = { { 1,1 } };
	POINT decc2[1] = { { 2,1 } };
	POINT decc3[1] = { { 3,1 } };
	POINT decc4[1] = { { 4,1 } };
	POINT decc5[1] = { { 5,1 } };
	POINT decq[1] = { {0,2} };
	POINT decq1[1] = { { 1,2 } };
	POINT decq2[1] = { { 2,2 } };
	POINT decq3[1] = { { 3,2 } };
	POINT decq4[1] = { { 4,2 } };
	POINT decq5[1] = { { 5,2 } };
	POINT decw[1] = { {0,3} };
	POINT decw1[1] = { { 1,3 } };
	POINT decw2[1] = { { 2,3 } };
	POINT decw3[1] = { { 3,3 } };
	POINT decw4[1] = { { 4,3 } };
	POINT decw5[1] = { { 5,3 } };

	POINT dece[1] = { {0,4} };
	POINT dece1[1] = { { 1,4 } };
	POINT dece2[1] = { { 2,4 } };
	POINT dece3[1] = { { 3,4 } };

	POINT deca[1] = { {0,5} };
	POINT deca1[1] = { { 1,5 } };
	POINT deca2[1] = { { 2,5 } };
	POINT deca3[1] = { { 3,5 } };

	POINT decs[1] = { {0,6} };
	POINT decs1[1] = { { 1,6 } };
	POINT decs2[1] = { { 2,6 } };
	POINT decs3[1] = { { 3,6 } };
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, dec, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, dec1, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, dec2, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, dec3, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, dec4, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, dec5, 1, { 0,0 }, 0,0);

	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decc, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decc1, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decc2, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decc3, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decc4, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decc5, 1, { 0,0 }, 0,0);

	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decq, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decq1, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decq2, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decq3, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decq4, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decq5, 1, { 0,0 }, 0,0);

	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decw, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decw1, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decw2, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decw3, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decw4, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decw5, 1, { 0,0 }, 0,0);

	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, dece, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, dece1, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, dece2, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, dece3, 1, { 0,0 }, 0,0);

	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, deca, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, deca1, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, deca2, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, deca3, 1, { 0,0 }, 0,0);

	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decs, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decs1, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decs2, 1, { 0,0 }, 0,0);
	TILEMANAGER->addDecoration("던전데코타일", "던전장식타일2", DECO_DENGEON, false, decs3, 1, { 0,0 }, 0,0);

	//던전장식(UNMOVE)
	POINT dd[1] = { {0,0} };
	POINT dd1[1] = { { 1,0 } };
	POINT dd2[1] = { { 2,0 } };
	POINT dd3[1] = { { 3,0 } };
	POINT dd4[1] = { { 4,0 } };
	TILEMANAGER->addDecoration("던전데코(UNMOVE)", "던전장식타일4", DECO_LEFT_TOP, false, dd, 1, { 0,0 }, 1,0);
	TILEMANAGER->addDecoration("던전데코(UNMOVE)", "던전장식타일4", DECO_LEFT_TOP, false, dd1, 1, { 0,0 }, 1,0);
	TILEMANAGER->addDecoration("던전데코(UNMOVE)", "던전장식타일4", DECO_RIGHT_TOP, false, dd2, 1, { 0,0 }, 2,0);
	TILEMANAGER->addDecoration("던전데코(UNMOVE)", "던전장식타일4", DECO_LEFT_BOTTOM, false, dd3, 1, { 0,0 }, 4,0);
	TILEMANAGER->addDecoration("던전데코(UNMOVE)", "던전장식타일4", DECO_RIGHT_BOTTOM, false, dd4, 1, { 0,0 }, 8,0);

	POINT dc[1] = { {0,1} };
	POINT dc1[1] = { { 1,1 } };
	POINT dc2[1] = { { 2,1 } };
	POINT dc3[1] = { { 3,1 } };
	POINT dc4[1] = { { 4,1 } };
	TILEMANAGER->addDecoration("던전데코(UNMOVE)", "던전장식타일4", DECO_LEFT_BOTTOM, false, dc, 1, { 0,0 }, 4,0);
	TILEMANAGER->addDecoration("던전데코(UNMOVE)", "던전장식타일4", DECO_LEFT_TOP, false, dc1, 1, { 0,0 }, 1,0);
	TILEMANAGER->addDecoration("던전데코(UNMOVE)", "던전장식타일4", DECO_RIGHT_TOP, false, dc2, 1, { 0,0 }, 2,0);
	TILEMANAGER->addDecoration("던전데코(UNMOVE)", "던전장식타일4", DECO_LEFT_BOTTOM, false, dc3, 1, { 0,0 }, 4,0);
	TILEMANAGER->addDecoration("던전데코(UNMOVE)", "던전장식타일4", DECO_RIGHT_BOTTOM, false, dc4, 1, { 0,0 }, 8,0);
	POINT de[1] = { {0,2} };
	POINT de1[1] = { { 1,2 } };
	POINT de2[1] = { { 2,2 } };
	POINT de3[1] = { { 3,2 } };
	POINT de4[1] = { { 4,2 } };
	TILEMANAGER->addDecoration("던전데코(UNMOVE)", "던전장식타일4", DECO_RIGHT_TOP, false, de, 1, { 0,0 }, 2,0);
	TILEMANAGER->addDecoration("던전데코(UNMOVE)", "던전장식타일4", DECO_LEFT_TOP, false, de1, 1, { 0,0 }, 1,0);
	TILEMANAGER->addDecoration("던전데코(UNMOVE)", "던전장식타일4", DECO_RIGHT_TOP, false, de2, 1, { 0,0 }, 2,0);
	TILEMANAGER->addDecoration("던전데코(UNMOVE)", "던전장식타일4", DECO_LEFT_BOTTOM, false, de3, 1, { 0,0 }, 4,0);
	TILEMANAGER->addDecoration("던전데코(UNMOVE)", "던전장식타일4", DECO_RIGHT_BOTTOM, false, de4, 1, { 0,0 }, 8,0);
	POINT da[1] = { {0,3} };
	TILEMANAGER->addDecoration("던전데코(UNMOVE)", "던전장식타일4", DECO_RIGHT_BOTTOM, false, da, 1, { 0,0 }, 8,0);

	//물
	POINT waArr[3] = { {2,0},{10,0},{18,0} };          //맨위 
	POINT waArr2[3] = { {3,0},{11,0},{19,0} };		   //맨위 
	POINT waArr3[3] = { {4,0},{12,0},{20,0} };		   //맨위 
	POINT waArr4[3] = { { 5,0 },{ 13,0 },{ 21,0 } };   //맨위 

	POINT waAr[3] = { { 2,1 },{ 10,1 },{ 18,1 } }; 	 //바로아래,
	POINT waAr2[3] = { { 3,1 },{ 11,1 },{ 19,1 } };	 //바로아래,
	POINT waAr3[3] = { { 4,1 },{ 12,1 },{ 20,1 } };	 //바로아래,
	POINT waAr4[3] = { { 5,1 },{ 13,1 },{ 21,1 } };	 //바로아래,

	POINT waAq[3] = { {0,2},{8,2},{16,2} };
	POINT waAq2[3] = { { 1,2 },{ 9,2},{ 17,2 } };
	POINT waAq3[3] = { { 2,2 },{ 10,2 },{ 18,2 } };
	POINT waAq6[3] = { { 5,2 },{ 13,2 },{ 21,2 } };
	POINT waAq7[3] = { { 6,2 },{ 14,2 },{ 22,2 } };
	POINT waAq8[3] = { { 7,2 },{ 15,2 },{ 23,2 } };

	POINT waAw[3] = { {0,3},{8,3},{16,3} };
	POINT waAw2[3] = { { 1,3 },{ 9,3 },{ 17,3 } };
	POINT waAw3[3] = { { 2,3 },{ 10,3 },{ 18,3 } };
	POINT waAw4[3] = { { 5,3 },{ 13,3 },{ 21,3 } };
	POINT waAw5[3] = { { 6,3 },{ 14,3 },{ 22,3 } };
	POINT waAw6[3] = { { 7,3 },{ 15,3 },{ 23,3 } };

	POINT waAe[3] = { {2,4},{10,4},{18,4} };
	POINT waAe2[3] = { { 3,4 },{ 11,4 },{ 19,4 } };
	POINT waAe3[3] = { { 4,4 },{ 12,4 },{ 20,4 } };
	POINT waAe4[3] = { { 5,4 },{ 13,4 },{ 21,4 } };

	POINT waAt[3] = { {2,5},{10,5},{18,5} };
	POINT waAt2[3] = { { 3,5 },{ 11,5 },{ 19,5 } };
	POINT waAt3[3] = { { 4,5 },{ 12,5 },{ 20,5 } };
	POINT waAt4[3] = { { 5,5 },{ 13,5 },{ 21,5 } };
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waArr, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waArr2, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waArr3, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waArr4, 3, { 0,0 }, 15,0);

	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAr, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAr2, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAr3, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAr4, 3, { 0,0 }, 15,0);

	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAq, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAq2, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAq3, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAq6, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAq7, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAq8, 3, { 0,0 }, 15,0);

	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAw, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAw2, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAw3, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAw4, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAw5, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAw6, 3, { 0,0 }, 15,0);

	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAe, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAe2, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAe3, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAe4, 3, { 0,0 }, 15,0);

	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAt, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAt2, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAt3, 3, { 0,0 }, 15,0);
	TILEMANAGER->addDecoration("물물", "물타일", DECO_WATER, true, waAt4, 3, { 0,0 }, 15,0);
	//===작은웨이브2개

	POINT waterArr[3] = { { 0,0 },{ 1,0 },{ 2,0 } };
	TILEMANAGER->addDecoration("물타일2", "물타일2", DECO_WATER, true, waterArr, 3, { 0,0 }, 15,0);
	POINT waterArr2[3] = { { 0,1 },{ 1,1 },{ 2,1 } };
	TILEMANAGER->addDecoration("물타일", "물타일2", DECO_WATER, true, waterArr2, 3, { 0,0 }, 15,0);

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
	TILEMANAGER->addObject("캐슬벽타일2", "캐슬벽타일2", { 0, 0 }, { 1,1 }, OBJECT_CASTLEPART6);
	TILEMANAGER->addObject("캐슬벽타일11", "캐슬벽타일11", { 0,0 }, { 2,1 }, OBJECT_CASTLEPART7);
	TILEMANAGER->addObject("캐슬타일1", "캐슬타일1", { 0,0 }, { 2,2 }, OBJECT_CASTLEPART8);
	TILEMANAGER->addObject("다리난간", "다리난간", { 0,0 }, { 1,10 }, { 0,0 }, OBJECT_BRIDGE);
	TILEMANAGER->addObject("성문", "성문", { 0,0 }, { 7,3 }, { 0,0 }, OBJECT_ENTRANCE);
	TILEMANAGER->addObject("정원장식", "정원장식", { 0,0 }, { 0,0 }, OBJECT_GARDEN);
	//TILEMANAGER->addObject("정원장식2", "정원장식긴것", { 0,0 }, { 2,5 }, { 0,0 }, OBJECT_GARDEN2);
	//TILEMANAGER->addObject("정원장식3", "정원장식짧은것", { 0,0 }, { 5,2 }, { 0,0 }, OBJECT_GARDEN3);

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

	TILEMANAGER->addObject("던전벽타일좌상", "던전벽타일좌상", { 0,0 }, { 2,2 }, { 0, 0 }, OBJECT_DENGEON4);
	TILEMANAGER->addObject("던전벽타일좌하", "던전벽타일좌하", { 0,0 }, { 2,2 }, { 0, 0 }, OBJECT_DENGEON4);
	TILEMANAGER->addObject("던전벽타일우상", "던전벽타일우상", { 0,0 }, { 2,2 }, { 0, 0 }, OBJECT_DENGEON4);
	TILEMANAGER->addObject("던전벽타일우하", "던전벽타일우하", { 0,0 }, { 2,2 }, { 0, 0 }, OBJECT_DENGEON4);
	TILEMANAGER->addObject("던전벽타일2", "던전벽타일2", { 0,0 }, { 3,3 }, OBJECT_DENGEON2);
	TILEMANAGER->addObject("던전타일끝처리", "던전타일끝처리", { 0,0 }, { 3,0 }, OBJECT_DENGEON2);
	TILEMANAGER->addObject("던전벽타일3", "던전벽타일3", { 0,0 }, { 6,7 }, OBJECT_DENGEON3);
	TILEMANAGER->addObject("던전물타일", "던전물타일", { 0,0 }, { 7,4 }, { 0,0 }, OBJECT_DENGEON);
	TILEMANAGER->addObject("화덕장식", "화덕장식", { 0,0 }, { 2,2 }, { 0,0 }, OBJECT_DENGEON);


	//절벽타일 ,15

	//TILEMANAGER->addDecoration("절벽11", "절벽11", { 0,0 }, { 5,5 }, false, DECO_HILL, 0,0);
	//TILEMANAGER->addDecoration("절벽11", "절벽111", { 0,0 }, { 5,5 }, false, DECO_HILL2, 0,1);
	//TILEMANAGER->addDecoration("절벽11", "절벽1111", { 0,0 }, { 5,5 }, false, DECO_HILL3, 0,2);
	//TILEMANAGER->addDecoration("절벽11", "절벽11111", { 0,0 }, { 5,5 }, false, DECO_HILL4, 0,3);
	//
	//TILEMANAGER->addDecoration("절벽11", "절벽22", { 0,0 }, { 5,5 }, false, DECO_HILL5, 15);
	//TILEMANAGER->addDecoration("절벽11", "절벽222", { 0,0 }, { 5,5 }, false, DECO_HILL6, 15);
	//TILEMANAGER->addDecoration("절벽11", "절벽2222", { 0,0 }, { 5,5 }, false, DECO_HILL7, 15);
	//TILEMANAGER->addDecoration("절벽11", "절벽22222", { 0,0 }, { 5,5 }, false, DECO_HILL8, 15);
	//
	//TILEMANAGER->addDecoration("절벽22", "절벽33", { 0,0 }, { 3,1 }, false, DECO_HILL9, 15);
	//TILEMANAGER->addDecoration("절벽22", "절벽333", { 0,0 }, { 3,1 }, false, DECO_HILL10, 15);
	//TILEMANAGER->addDecoration("절벽22", "절벽3333", { 0,0 }, { 3,3 }, false, DECO_HILL11, 15);
	//TILEMANAGER->addDecoration("절벽22", "절벽33333", { 0,0 }, {3,3 }, false, DECO_HILL12, 15);
	//
	////길바닥, 0
	//TILEMANAGER->addDecoration("길바닥11", "길바닥11", { 0,0 }, { 5,5 }, false, DECO_ROAD, 0);
	//TILEMANAGER->addDecoration("길바닥11", "길바닥22", { 0,0 }, { 5,3 }, false, DECO_ROAD2, 0);
	//
	//TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", { 0,0 }, { 5,5 }, false, DECO_LINE, 0);
	//TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", { 0,0 }, { 5,5 }, false, DECO_LINE2, 0);
	//TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", { 0,0 }, { 5,7 }, false, DECO_LINE3, 0);
	//TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", { 0,0 }, { 5,7 }, false, DECO_LINE4, 0);
	//TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", { 0,0 }, { 5,7 }, false, DECO_LINE5, 0);
	//
	//TILEMANAGER->addDecoration("길그림자1", "길그림자1", { 0,0 }, { 5,2 }, false, DECO_SHADOW, 0);
	//TILEMANAGER->addDecoration("길그림자1", "길그림자2", { 0,0 }, { 5,2 }, false, DECO_SHADOW2, 0);
	//TILEMANAGER->addDecoration("길그림자1", "길그림자3", { 0,0 }, { 5,2 }, false, DECO_SHADOW3, 0);
	//
	//TILEMANAGER->addDecoration("길경계선1", "길경계선1", { 0,0 }, { 5,5 }, false, DECO_BORDER, 0);
	//TILEMANAGER->addDecoration("길경계선1", "길경계선2", { 0,0 }, { 5,5 }, false, DECO_BORDER2, 0);
	//TILEMANAGER->addDecoration("길경계선1", "길경계선3", { 0,0 }, { 5,5 }, false, DECO_BORDER3, 0);

	//마을장식
	POINT townArr1[1] = { {0,0} };
	POINT townArr2[1] = { { 1,0 } };
	POINT townArr3[1] = { { 2,0 } };
	POINT townArr4[1] = { { 3,0 } };
	POINT townArr5[1] = { { 0,1 } };
	POINT townArr6[1] = { { 1,1 } };
	POINT townArr7[1] = { { 2,1 } };
	POINT townArr8[1] = { { 3,1 } };
	POINT townArr9[1] = { { 0,2 } };
	POINT townArr10[1] = { { 1,2 } };
	POINT townArr11[1] = { { 2,2 } };
	POINT townArr12[1] = { { 3,2 } };
	TILEMANAGER->addDecoration("마을장식타일", "마을장식타일", DECO_EMPTY, false, townArr1, 1, { 0,0 }, 0, 0); //수정해야됨
	TILEMANAGER->addDecoration("마을장식타일", "마을장식타일", DECO_EMPTY, false, townArr2, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("마을장식타일", "마을장식타일", DECO_EMPTY, false, townArr3, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("마을장식타일", "마을장식타일", DECO_EMPTY, false, townArr4, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("마을장식타일", "마을장식타일", DECO_EMPTY, false, townArr5, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("마을장식타일", "마을장식타일", DECO_EMPTY, false, townArr6, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("마을장식타일", "마을장식타일", DECO_EMPTY, false, townArr7, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("마을장식타일", "마을장식타일", DECO_EMPTY, false, townArr8, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("마을장식타일", "마을장식타일", DECO_EMPTY, false, townArr9, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("마을장식타일", "마을장식타일", DECO_EMPTY, false, townArr10, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("마을장식타일", "마을장식타일", DECO_EMPTY, false, townArr11, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("마을장식타일", "마을장식타일", DECO_EMPTY, false, townArr12, 1, { 0,0 }, 0, 0);

	//울타리
	POINT fence1[1] = { {0,0} };
	POINT fence2[2] = { {1,0} };
	POINT fence3[3] = { {2,0} };
	POINT fence4[4] = { {3,0} };
	
	POINT fence5[1] = { { 0,1 } };
	POINT fence6[1] = { { 1,1 } };
	TILEMANAGER->addDecoration("울타리", "울타리", DECO_EMPTY, false, fence1, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("울타리", "울타리", DECO_EMPTY, false, fence2, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("울타리", "울타리", DECO_EMPTY, false, fence3, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("울타리", "울타리", DECO_EMPTY, false, fence4, 1, { 0,0 }, 0, 3);

	TILEMANAGER->addDecoration("울타리", "울타리", DECO_EMPTY, false, fence5, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("울타리", "울타리", DECO_EMPTY, false, fence6, 1, { 0,0 }, 0, 1);

	//길바닥
	POINT road1[1] = { {0,0} };
	POINT road2[1] = { { 1,0 } };
	POINT road3[1] = { { 2,0 } };
	POINT road4[1] = { { 3,0 } };
	POINT road5[1] = { { 4,0 } };
	POINT road6[1] = { { 5,0 } };
	POINT road7[1] = { { 0,1 } };
	POINT road8[1] = { { 1,1 } };
	POINT road9[1] = { { 2,1 } };
	POINT road10[1] = { { 3,1 } };
	POINT road11[1] = { { 4,1 } };
	POINT road12[1] = { { 5,1 } };
	POINT road13[1] = { { 0,2 } };
	POINT road14[1] = { { 1,2 } };
	POINT road15[1] = { { 2,2 } };
	POINT road16[1] = { { 3,2 } };
	POINT road17[1] = { { 4,2 } };
	POINT road18[1] = { { 5,2 } };
	POINT road19[1] = { { 0,3 } };
	POINT road20[1] = { { 1,3 } };
	POINT road21[1] = { { 2,3 } };
	POINT road22[1] = { { 3,3 } };
	POINT road23[1] = { { 4,3 } };
	POINT road24[1] = { { 5,3 } };
	POINT road25[1] = { { 0,4 } };
	POINT road26[1] = { { 1,4 } };
	POINT road27[1] = { { 2,4 } };
	POINT road28[1] = { { 3,4 } };
	POINT road29[1] = { { 4,4 } };
	POINT road30[1] = { { 5,4 } };
	POINT road31[1] = { { 0,5 } };
	POINT road32[1] = { { 1,5 } };
	POINT road33[1] = { { 2,5 } };
	POINT road34[1] = { { 3,5 } };
	POINT road35[1] = { { 4,5 } };
	POINT road36[1] = { { 5,5 } };

	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road1, 1, { 0,0 }, 0, 1);
	
}