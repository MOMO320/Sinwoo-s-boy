#include "stdafx.h"
#include "mainSwitch.h"

void mainSwitch::imageSetting()
{
	//캐슬 타일
	IMAGEMANAGER->addImage("캐슬기둥", "./image./mapTile./castle./캐슬기둥.bmp", 200, 350, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("캐슬문타일외", "./image./mapTile./castle./캐슬문타일+끝처리용타일+계단.bmp", 400, 400, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("캐슬바닥타일", "./image./mapTile./castle./캐슬바닥타일.bmp", 200, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("캐슬벽오른쪽타일", "./image./mapTile./castle./캐슬벽오른쪽타일.bmp", 300, 500, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("캐슬벽오른쪽타일22", "./image./mapTile./castle./캐슬벽오른쪽타일22.bmp", 300, 250, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("캐슬벽오른쪽타일33", "./image./mapTile./castle./캐슬벽오른쪽타일33.bmp", 300, 250, true, RGB(255, 0, 255));
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
	IMAGEMANAGER->addFrameImage("빨간집프레임", "./image/mapTile./마을./빨간집프레임.bmp", 600, 300, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("파란집프레임", "./image/mapTile./마을./파란집프레임.bmp", 600, 300, 2, 1, true, RGB(255, 0, 255));
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

	IMAGEMANAGER->addImage("wat", "./image./mapTile./water./wat.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("acac", "./image./mapTile./water./acac.bmp", 50, 50, true, RGB(255, 0, 255));
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
	IMAGEMANAGER->addFrameImage("MredEye", "./image./mapTile./캐릭터./redEye.bmp", 100, 52, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("MjumpKnight", "./image./mapTile./캐릭터./jumpKnight.bmp", 600, 140, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("MgreenS", "./image./mapTile./캐릭터./greenS.bmp", 224, 90, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("MgreenEye", "./image./mapTile./캐릭터./greenEye.bmp", 150, 78, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("MblueS", "./image./mapTile./캐릭터./blueS.bmp", 150, 61, 3, 1, true, RGB(255, 0, 255));
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
	IMAGEMANAGER->addImage("마룻바닥", "./image./mapTile./집인테./마룻바닥.bmp", 200, 100, true, RGB(255, 0, 255)); //데코//
	IMAGEMANAGER->addImage("집바닥", "./image./mapTile./집인테./집바닥.bmp", 200, 400, true, RGB(255, 0, 255)); //집바닥//
	IMAGEMANAGER->addImage("벽아래", "./image./mapTile./집인테./벽아래.bmp", 50, 100, true, RGB(255, 0, 255)); //오브젝트
	IMAGEMANAGER->addImage("벽위", "./image./mapTile./집인테./벽위.bmp", 50, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("벽오른쪽", "./image./mapTile./집인테./벽오른쪽.bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("벽왼쪽", "./image./mapTile./집인테./벽왼쪽.bmp", 100, 50, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("집인테타일", "./image./mapTile./집인테./집인테타일.bmp", 100, 50, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("상자", "./image./mapTile./집인테./상자.bmp", 100, 50,2,1 ,true, RGB(255, 0, 255)); //오브젝트

	IMAGEMANAGER->addImage("선반", "./image./mapTile./집인테./선반.bmp", 150, 50, true, RGB(255, 0, 255)); //데코
	IMAGEMANAGER->addImage("실내문", "./image./mapTile./집인테./실내문.bmp", 100, 100, true, RGB(255, 0, 255));//오브젝트

	IMAGEMANAGER->addImage("아래창문", "./image./mapTile./집인테./아래창문.bmp", 100, 50, true, RGB(255, 0, 255)); //데코
	IMAGEMANAGER->addImage("윗창문", "./image./mapTile./집인테./윗창문.bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("왼창문", "./image./mapTile./집인테./왼창문.bmp", 50, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("오른창문", "./image./mapTile./집인테./오른창문.bmp", 50, 100, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("오른쪽바텀모서리", "./image./mapTile./집인테./오른쪽바텀모서리.bmp", 100, 100, true, RGB(255, 0, 255)); //오브젝트
	IMAGEMANAGER->addImage("오른쪽탑모서리", "./image./mapTile./집인테./오른쪽탑모서리.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("왼쪽바텀모서리", "./image./mapTile./집인테./왼쪽바텀모서리.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("왼쪽탑모서리", "./image./mapTile./집인테./왼쪽탑모서리.bmp", 100, 100, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("의자", "./image./mapTile./집인테./의자.bmp", 50, 50, true, RGB(255, 0, 255)); //오브젝트
	IMAGEMANAGER->addImage("작은책상", "./image./mapTile./집인테./작은책상.bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("큰탁상", "./image./mapTile./집인테./큰탁상.bmp", 150, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("침대", "./image./mapTile./집인테./침대.bmp", 100, 100, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("항아리22", "./image./mapTile./집인테./항아리22.bmp", 50, 50, true, RGB(255, 0, 255)); //오브젝트
	IMAGEMANAGER->addImage("항아리타일", "./image./mapTile./집인테./항아리타일.bmp", 50, 50, true, RGB(255, 0, 255)); //타일
	IMAGEMANAGER->addImage("화덕222", "./image./mapTile./집인테./화덕222.bmp", 100, 100, true, RGB(255, 0, 255)); //오브젝트
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
	
	TILEMANAGER->addObject("항아", "항아리22", { 0,0 }, { 1,1 }, { 0,0 }, OBJECT_PICK);
	//절벽33
	//TILEMANAGER->addObject("절벽", "절벽1", { 0,0 }, { 5,5 }, OBJECT_HILL);
	//TILEMANAGER->addObject("절벽", "절벽2", { 0,0 }, { 5,5 }, OBJECT_HILL);
	//TILEMANAGER->addObject("절벽", "절벽3", { 0,0 }, { 5,5 }, OBJECT_HILL);
	//TILEMANAGER->addObject("절벽", "절벽4", { 0,0 }, { 5,5 }, OBJECT_HILL);

	TILEMANAGER->addObject("트리", "나무", { 0,0 }, { 3,2 }, { 0,100 }, OBJECT_TREE);

	//캐릭터
	TILEMANAGER->addCharacter("플레이어", "맵툴용캐릭터", CHARACTER_PLAYER_POS, { 2,22 });
	TILEMANAGER->addCharacter("파랑군인", "MblueS", CHARACTER_BLUESOLDIER_POS, { 0,0 });
	TILEMANAGER->addCharacter("초록눈", "MgreenEye", CHARACTER_GREENEYE_POS, { 28,12 });
	TILEMANAGER->addCharacter("초록군인", "MgreenS", CHARACTER_GREENSOLDIER_POS, { 3,30 });
	TILEMANAGER->addCharacter("점프나이트", "MjumpKnight", CHARACTER_JUMPKNIGHT_POS, { 23,86 });
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
	TILEMANAGER->addDecoration("던전데코", "던전장식타일4", DECO_LEFT_TOP, false, dd, 1, { 0,0 }, 1,0);
	TILEMANAGER->addDecoration("던전데코", "던전장식타일4", DECO_LEFT_TOP, false, dd1, 1, { 0,0 }, 1,0);
	TILEMANAGER->addDecoration("던전데코", "던전장식타일4", DECO_RIGHT_TOP, false, dd2, 1, { 0,0 }, 2,0);
	TILEMANAGER->addDecoration("던전데코", "던전장식타일4", DECO_LEFT_BOTTOM, false, dd3, 1, { 0,0 }, 4,0);
	TILEMANAGER->addDecoration("던전데코", "던전장식타일4", DECO_RIGHT_BOTTOM, false, dd4, 1, { 0,0 }, 8,0);

	POINT dc[1] = { {0,1} };
	POINT dc1[1] = { { 1,1 } };
	POINT dc2[1] = { { 2,1 } };
	POINT dc3[1] = { { 3,1 } };
	POINT dc4[1] = { { 4,1 } };
	TILEMANAGER->addDecoration("던전데코", "던전장식타일4", DECO_LEFT_BOTTOM, false, dc, 1, { 0,0 }, 4,0);
	TILEMANAGER->addDecoration("던전데코", "던전장식타일4", DECO_LEFT_TOP, false, dc1, 1, { 0,0 }, 1,0);
	TILEMANAGER->addDecoration("던전데코", "던전장식타일4", DECO_RIGHT_TOP, false, dc2, 1, { 0,0 }, 2,0);
	TILEMANAGER->addDecoration("던전데코", "던전장식타일4", DECO_LEFT_BOTTOM, false, dc3, 1, { 0,0 }, 4,0);
	TILEMANAGER->addDecoration("던전데코", "던전장식타일4", DECO_RIGHT_BOTTOM, false, dc4, 1, { 0,0 }, 8,0);
	POINT de[1] = { {0,2} };
	POINT de1[1] = { { 1,2 } };
	POINT de2[1] = { { 2,2 } };
	POINT de3[1] = { { 3,2 } };
	POINT de4[1] = { { 4,2 } };
	TILEMANAGER->addDecoration("던전데코", "던전장식타일4", DECO_RIGHT_TOP, false, de, 1, { 0,0 }, 2,0);
	TILEMANAGER->addDecoration("던전데코", "던전장식타일4", DECO_LEFT_TOP, false, de1, 1, { 0,0 }, 1,0);
	TILEMANAGER->addDecoration("던전데코", "던전장식타일4", DECO_RIGHT_TOP, false, de2, 1, { 0,0 }, 2,0);
	TILEMANAGER->addDecoration("던전데코", "던전장식타일4", DECO_LEFT_BOTTOM, false, de3, 1, { 0,0 }, 4,0);
	TILEMANAGER->addDecoration("던전데코", "던전장식타일4", DECO_RIGHT_BOTTOM, false, de4, 1, { 0,0 }, 8,0);
	POINT da[1] = { {0,3} };
	TILEMANAGER->addDecoration("던전데코", "던전장식타일4", DECO_RIGHT_BOTTOM, false, da, 1, { 0,0 }, 8,0);

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
	TILEMANAGER->addObject("캐슬벽오른타", "캐슬벽오른쪽타일", { 0,0 }, { 5,9 }, OBJECT_CASTLEPART2);
	TILEMANAGER->addObject("캐슬벽왼쪽타", "캐슬벽왼쪽타일", { 0,0 }, { 2,9 }, OBJECT_CASTLEPART3);
	TILEMANAGER->addObject("캐슬벽윗타일", "캐슬벽윗타일", { 0,0 }, { 9,1 }, OBJECT_CASTLEPART4);
	TILEMANAGER->addObject("캐슬벽타일", "캐슬벽타일", { 0,0 }, { 7,5 }, OBJECT_CASTLEPART5);
	TILEMANAGER->addObject("캐슬벽타일2", "캐슬벽타일2", { 0, 0 }, { 1,1 }, OBJECT_CASTLEPART6);
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
	//POINT house[2] = { {0,0},{1,0} };
	//TILEMANAGER->addFrameObject("빨", "빨간집프레임", house, 2, { 6,6 }, { 0,0 }, OBJECT_TOWN);
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
	POINT road37[1] = { {0,6} };
	POINT road38[1] = { { 1,6 } };
	POINT road39[1] = { { 2,6 } };
	POINT road40[1] = { { 3,6 } };
	POINT road41[1] = { { 4,6 } };
	POINT road42[1] = { { 5,6 } };
	POINT road43[1] = { { 0,7 } };
	POINT road44[1] = { { 1,7 } };
	POINT road45[1] = { { 2,7 } };
	POINT road46[1] = { { 3,7 } };
	POINT road47[1] = { { 4,7 } };
	POINT road48[1] = { { 5,7 } };
	//1장
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road1, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road2, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road3, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road4, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road5, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road6, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road7, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road8, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road9, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road10, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road11, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road12, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road13, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road14, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road15, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road16, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road17, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road18, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road19, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road20, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road21, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road22, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road23, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road24, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road25, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road26, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road27, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road28, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road29, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road30, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road31, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road32, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road33, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road34, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road35, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길바닥11", "길바닥11", DECO_ROAD, false, road36, 1, { 0,0 }, 0, 2);

	//2장
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road1, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road2, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road3, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road4, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road5, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road6, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road7, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road8, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road9, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road10, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road11, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road12, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road13, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road14, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road15, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road16, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road17, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road18, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road19, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road20, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road21, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road22, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road23, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길바닥11", "길바닥22", DECO_ROAD2, false, road24, 1, { 0,0 }, 0, 0);
	//3장
	//길줄무늬
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road1, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road2, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road3, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road4, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road5, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road6, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road7, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road8, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road9, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road10, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road11, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road12, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road13, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road14, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road15, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road16, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road17, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road18, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road19, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road20, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road21, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road22, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road23, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road24, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road25, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road26, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road27, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road28, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road29, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road30, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road31, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬", DECO_LINE, false, road32, 1, { 0,0 }, 0, 3);
	//길줄무늬2
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road1, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road2, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road3, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road4, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road5, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road6, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road7, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road8, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road9, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road10, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road11, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road12, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road13, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road14, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road15, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road16, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road17, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road18, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road19, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road20, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road21, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road22, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road23, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road24, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road25, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road26, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road27, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road28, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road29, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road30, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road31, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬22", DECO_LINE2, false, road32, 1, { 0,0 }, 0, 3);
	//길줄무늬3
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road1, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road2, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road3, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road4, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road5, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road6, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road7, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road8, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road9, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road10, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road11, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road12, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road13, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road14, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road15, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road16, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road17, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road18, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road19, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road20, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road21, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road22, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road23, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road24, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road25, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road26, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road27, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road28, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road29, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road30, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road31, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road32, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road33, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road34, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road35, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road36, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road37, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road38, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road39, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road40, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road41, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road42, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road43, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road44, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road45, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road46, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road47, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬33", DECO_LINE3, false, road48, 1, { 0,0 }, 0, 3);
	//길줄무늬44
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road1, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road2, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road3, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road4, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road5, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road6, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road7, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road8, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road9, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road10, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road11, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road12, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road13, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road14, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road15, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road16, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road17, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road18, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road19, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road20, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road21, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road22, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road23, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road24, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road25, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road26, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road27, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road28, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road29, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road30, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road31, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road32, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road33, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road34, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road35, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road36, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road37, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road38, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road39, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road40, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road41, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road42, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road43, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road44, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road45, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road46, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road47, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬44", DECO_LINE4, false, road48, 1, { 0,0 }, 0, 3);
	//길줄무늬55
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road1, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road2, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road3, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road4, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road5, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road6, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road7, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road8, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road9, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road10, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road11, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road12, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road13, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road14, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road15, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road16, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road17, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road18, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road19, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road20, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road21, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road22, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road23, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road24, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road25, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road26, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road27, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road28, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road29, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road30, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road31, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road32, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road33, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road34, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road35, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road36, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road37, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road38, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road39, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road40, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road41, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road42, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road43, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road44, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road45, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road46, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road47, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길줄무늬", "길줄무늬55", DECO_LINE5, false, road48, 1, { 0,0 }, 0, 3);
	//길그림자1
	TILEMANAGER->addDecoration("길그림자1", "길그림자1", DECO_SHADOW, false, road1, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길그림자1", "길그림자1", DECO_SHADOW, false, road2, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길그림자1", "길그림자1", DECO_SHADOW, false, road3, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길그림자1", "길그림자1", DECO_SHADOW, false, road4, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길그림자1", "길그림자1", DECO_SHADOW, false, road5, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길그림자1", "길그림자1", DECO_SHADOW, false, road6, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길그림자1", "길그림자1", DECO_SHADOW, false, road7, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길그림자1", "길그림자1", DECO_SHADOW, false, road8, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길그림자1", "길그림자1", DECO_SHADOW, false, road9, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길그림자1", "길그림자1", DECO_SHADOW, false, road10, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길그림자1", "길그림자1", DECO_SHADOW, false, road11, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길그림자1", "길그림자1", DECO_SHADOW, false, road12, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길그림자1", "길그림자1", DECO_SHADOW, false, road13, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길그림자1", "길그림자1", DECO_SHADOW, false, road14, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길그림자1", "길그림자1", DECO_SHADOW, false, road15, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길그림자1", "길그림자1", DECO_SHADOW, false, road16, 1, { 0,0 }, 0, 3);
	//길그림자2
	TILEMANAGER->addDecoration("길그림자2", "길그림자2", DECO_SHADOW2, false, road1, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길그림자2", "길그림자2", DECO_SHADOW2, false, road2, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길그림자2", "길그림자2", DECO_SHADOW2, false, road3, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길그림자2", "길그림자2", DECO_SHADOW2, false, road4, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길그림자2", "길그림자2", DECO_SHADOW2, false, road5, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길그림자2", "길그림자2", DECO_SHADOW2, false, road6, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길그림자2", "길그림자2", DECO_SHADOW2, false, road7, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길그림자2", "길그림자2", DECO_SHADOW2, false, road8, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길그림자2", "길그림자2", DECO_SHADOW2, false, road9, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길그림자2", "길그림자2", DECO_SHADOW2, false, road10, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길그림자2", "길그림자2", DECO_SHADOW2, false, road11, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길그림자2", "길그림자2", DECO_SHADOW2, false, road12, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길그림자2", "길그림자2", DECO_SHADOW2, false, road13, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길그림자2", "길그림자2", DECO_SHADOW2, false, road14, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길그림자2", "길그림자2", DECO_SHADOW2, false, road15, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길그림자2", "길그림자2", DECO_SHADOW2, false, road16, 1, { 0,0 }, 0, 3);
	//길그림자3
	TILEMANAGER->addDecoration("길그림자3", "길그림자3", DECO_SHADOW3, false, road1, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길그림자3", "길그림자3", DECO_SHADOW3, false, road2, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길그림자3", "길그림자3", DECO_SHADOW3, false, road3, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길그림자3", "길그림자3", DECO_SHADOW3, false, road4, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길그림자3", "길그림자3", DECO_SHADOW3, false, road5, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길그림자3", "길그림자3", DECO_SHADOW3, false, road6, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길그림자3", "길그림자3", DECO_SHADOW3, false, road7, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길그림자3", "길그림자3", DECO_SHADOW3, false, road8, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길그림자3", "길그림자3", DECO_SHADOW3, false, road9, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길그림자3", "길그림자3", DECO_SHADOW3, false, road10, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길그림자3", "길그림자3", DECO_SHADOW3, false, road11, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길그림자3", "길그림자3", DECO_SHADOW3, false, road12, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길그림자3", "길그림자3", DECO_SHADOW3, false, road13, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길그림자3", "길그림자3", DECO_SHADOW3, false, road14, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길그림자3", "길그림자3", DECO_SHADOW3, false, road15, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길그림자3", "길그림자3", DECO_SHADOW3, false, road16, 1, { 0,0 }, 0, 3);

	//길경계선1
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road1, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road2, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road3, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road4, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road5, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road6, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road7, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road8, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road9, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road10, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road11, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road12, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road13, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road14, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road15, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road16, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road17, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road18, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road19, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road20, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road21, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road22, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road23, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road24, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road25, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road26, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road27, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road28, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road29, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road30, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road31, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road32, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road33, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road34, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road35, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선1", "길경계선1", DECO_BORDER, false, road36, 1, { 0,0 }, 0, 3);
	//길경계선2
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road1, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road2, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road3, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road4, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road5, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road6, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road7, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road8, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road9, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road10, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road11, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road12, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road13, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road14, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road15, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road16, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road17, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road18, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road19, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road20, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road21, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road22, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road23, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road24, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road25, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road26, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road27, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road28, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road29, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road30, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road31, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road32, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road33, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road34, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road35, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선2", "길경계선2", DECO_BORDER2, false, road36, 1, { 0,0 }, 0, 3);
	//길경계선3
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road1, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road2, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road3, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road4, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road5, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road6, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road7, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road8, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road9, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road10, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road11, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road12, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road13, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road14, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road15, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road16, 1, { 0,0 }, 0, 3);

	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road19, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road20, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road21, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road22, 1, { 0,0 }, 0, 3);

	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road25, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road26, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road27, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road28, 1, { 0,0 }, 0, 3);

	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road31, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road32, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road33, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("길경계선3", "길경계선3", DECO_BORDER3, false, road34, 1, { 0,0 }, 0, 3);

	//절벽타일 ,15
	POINT hill1[1] = { { 0,0 } };
	POINT hill2[1] = { { 1,0 } };
	POINT hill3[1] = { { 2,0 } };
	POINT hill4[1] = { { 3,0 } };
	POINT hill5[1] = { { 4,0 } };
	POINT hill6[1] = { { 5,0 } };
	POINT hill7[1] = { { 0,1 } };
	POINT hill8[1] = { { 1,1 } };
	POINT hill9[1] = { { 2,1 } };
	POINT hill10[1] = { { 3,1 } };
	POINT hill11[1] = { { 4,1 } };
	POINT hill12[1] = { { 5,1 } };
	POINT hill13[1] = { { 0,2 } };
	POINT hill14[1] = { { 1,2 } };
	POINT hill15[1] = { { 2,2 } };
	POINT hill16[1] = { { 3,2 } };
	POINT hill17[1] = { { 4,2 } };
	POINT hill18[1] = { { 5,2 } };
	POINT hill19[1] = { { 0,3 } };
	POINT hill20[1] = { { 1,3 } };
	POINT hill21[1] = { { 2,3 } };
	POINT hill22[1] = { { 3,3 } };
	POINT hill23[1] = { { 4,3 } };
	POINT hill24[1] = { { 5,3 } };
	POINT hill25[1] = { { 0,4 } };
	POINT hill26[1] = { { 1,4 } };
	POINT hill27[1] = { { 2,4 } };
	POINT hill28[1] = { { 3,4 } };
	POINT hill29[1] = { { 4,4 } };
	POINT hill30[1] = { { 5,4 } };
	POINT hill31[1] = { { 0,5 } };
	POINT hill32[1] = { { 1,5 } };
	POINT hill33[1] = { { 2,5 } };
	POINT hill34[1] = { { 3,5 } };
	POINT hill35[1] = { { 4,5 } };
	POINT hill36[1] = { { 5,5 } };


	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill1, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill2, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill3, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill4, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill5, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill6, 1, { 0,0 }, 8, 0);

	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill7, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill8, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill9, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill10, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill11, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill12, 1, { 0,0 }, 8, 0);
																				 
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill13, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill14, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill15, 1, { 0,0 }, 0, 0);   // 이미지 수정 필요  비어있음
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill16, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill17, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill18, 1, { 0,0 }, 4, 0);
																				 
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill19, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill20, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill21, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill22, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill23, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill24, 1, { 0,0 }, 4, 0);
																				 
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill25, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill26, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill27, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill28, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill29, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill30, 1, { 0,0 }, 2, 0);
																				 
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill31, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill32, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill33, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill34, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill35, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽11", "절벽11", DECO_HILL, false, hill36, 1, { 0,0 }, 8, 0);

	POINT hhill1[1] = { { 0,0 } };
	POINT hhill2[1] = { { 1,0 } };
	POINT hhill3[1] = { { 2,0 } };
	POINT hhill4[1] = { { 3,0 } };
	POINT hhill5[1] = { { 4,0 } };
	POINT hhill6[1] = { { 5,0 } };
	POINT hhill7[1] = { { 0,1 } };
	POINT hhill8[1] = { { 1,1 } };
	POINT hhill9[1] = { { 2,1 } };
	POINT hhill10[1] = { { 3,1 } };
	POINT hhill11[1] = { { 4,1 } };
	POINT hhill12[1] = { { 5,1 } };
	POINT hhill13[1] = { { 0,2 } };
	POINT hhill14[1] = { { 1,2 } };
	POINT hhill15[1] = { { 2,2 } };
	POINT hhill16[1] = { { 3,2 } };
	POINT hhill17[1] = { { 4,2 } };
	POINT hhill18[1] = { { 5,2 } };
	POINT hhill19[1] = { { 0,3 } };
	POINT hhill20[1] = { { 1,3 } };
	POINT hhill21[1] = { { 2,3 } };
	POINT hhill22[1] = { { 3,3 } };
	POINT hhill23[1] = { { 4,3 } };
	POINT hhill24[1] = { { 5,3 } };
	POINT hhill25[1] = { { 0,4 } };
	POINT hhill26[1] = { { 1,4 } };
	POINT hhill27[1] = { { 2,4 } };
	POINT hhill28[1] = { { 3,4 } };
	POINT hhill29[1] = { { 4,4 } };
	POINT hhill30[1] = { { 5,4 } };
	POINT hhill31[1] = { { 0,5 } };
	POINT hhill32[1] = { { 1,5 } };
	POINT hhill33[1] = { { 2,5 } };
	POINT hhill34[1] = { { 3,5 } };
	POINT hhill35[1] = { { 4,5 } };
	POINT hhill36[1] = { { 5,5 } };

	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill1, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill2, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill3, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill4, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill5, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill6, 1, { 0,0 }, 2, 0);

	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill7, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill8, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill9, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill10, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill11, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill12, 1, { 0,0 }, 8, 0);
																					 
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill13, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill14, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill15, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill16, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill17, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill18, 1, { 0,0 }, 2, 0);
																					 
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill19, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill20, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill21, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill22, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill23, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill24, 1, { 0,0 }, 1, 0);
																					 
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill25, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill26, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill27, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill28, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill29, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill30, 1, { 0,0 }, 1, 0);
																					 
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill31, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill32, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill33, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill34, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill35, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽111", "절벽111", DECO_HILL2, false, hhill36, 1, { 0,0 }, 2, 0);


	POINT hhhill1[1] = { { 0,0 } };
	POINT hhhill2[1] = { { 1,0 } };
	POINT hhhill3[1] = { { 2,0 } };
	POINT hhhill4[1] = { { 3,0 } };
	POINT hhhill5[1] = { { 4,0 } };
	POINT hhhill6[1] = { { 5,0 } };
	POINT hhhill7[1] = { { 0,1 } };
	POINT hhhill8[1] = { { 1,1 } };
	POINT hhhill9[1] = { { 2,1 } };
	POINT hhhill10[1] = { { 3,1 } };
	POINT hhhill11[1] = { { 4,1 } };
	POINT hhhill12[1] = { { 5,1 } };
	POINT hhhill13[1] = { { 0,2 } };
	POINT hhhill14[1] = { { 1,2 } };
	POINT hhhill15[1] = { { 2,2 } };
	POINT hhhill16[1] = { { 3,2 } };
	POINT hhhill17[1] = { { 4,2 } };
	POINT hhhill18[1] = { { 5,2 } };
	POINT hhhill19[1] = { { 0,3 } };
	POINT hhhill20[1] = { { 1,3 } };
	POINT hhhill21[1] = { { 2,3 } };
	POINT hhhill22[1] = { { 3,3 } };
	POINT hhhill23[1] = { { 4,3 } };
	POINT hhhill24[1] = { { 5,3 } };
	POINT hhhill25[1] = { { 0,4 } };
	POINT hhhill26[1] = { { 1,4 } };
	POINT hhhill27[1] = { { 2,4 } };
	POINT hhhill28[1] = { { 3,4 } };
	POINT hhhill29[1] = { { 4,4 } };
	POINT hhhill30[1] = { { 5,4 } };
	POINT hhhill31[1] = { { 0,5 } };
	POINT hhhill32[1] = { { 1,5 } };
	POINT hhhill33[1] = { { 2,5 } };
	POINT hhhill34[1] = { { 3,5 } };
	POINT hhhill35[1] = { { 4,5 } };
	POINT hhhill36[1] = { { 5,5 } };

	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill1, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill2, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill3, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill4, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill5, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill6, 1, { 0,0 }, 2, 0);

	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill7, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill8, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill9, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill10, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill11, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill12, 1, { 0,0 }, 8, 0);
																						
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill13, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill14, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill15, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill16, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill17, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill18, 1, { 0,0 }, 1, 0);
																						
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill19, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill20, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill21, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill22, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill23, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill24, 1, { 0,0 }, 1, 0);
																						
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill25, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill26, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill27, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill28, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill29, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill30, 1, { 0,0 }, 2, 0);
																						
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill31, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill32, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill33, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill34, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill35, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽1111", "절벽1111", DECO_HILL3, false, hhhill36, 1, { 0,0 }, 1, 0);

	POINT hhhhill1[1] = { { 0,0 } };
	POINT hhhhill2[1] = { { 1,0 } };
	POINT hhhhill3[1] = { { 2,0 } };
	POINT hhhhill4[1] = { { 3,0 } };
	POINT hhhhill5[1] = { { 4,0 } };
	POINT hhhhill6[1] = { { 5,0 } };
	POINT hhhhill7[1] = { { 0,1 } };
	POINT hhhhill8[1] = { { 1,1 } };
	POINT hhhhill9[1] = { { 2,1 } };
	POINT hhhhill10[1] = { { 3,1 } };
	POINT hhhhill11[1] = { { 4,1 } };
	POINT hhhhill12[1] = { { 5,1 } };
	POINT hhhhill13[1] = { { 0,2 } };
	POINT hhhhill14[1] = { { 1,2 } };
	POINT hhhhill15[1] = { { 2,2 } };
	POINT hhhhill16[1] = { { 3,2 } };
	POINT hhhhill17[1] = { { 4,2 } };
	POINT hhhhill18[1] = { { 5,2 } };
	POINT hhhhill19[1] = { { 0,3 } };
	POINT hhhhill20[1] = { { 1,3 } };
	POINT hhhhill21[1] = { { 2,3 } };
	POINT hhhhill22[1] = { { 3,3 } };
	POINT hhhhill23[1] = { { 4,3 } };
	POINT hhhhill24[1] = { { 5,3 } };
	POINT hhhhill25[1] = { { 0,4 } };
	POINT hhhhill26[1] = { { 1,4 } };
	POINT hhhhill27[1] = { { 2,4 } };
	POINT hhhhill28[1] = { { 3,4 } };
	POINT hhhhill29[1] = { { 4,4 } };
	POINT hhhhill30[1] = { { 5,4 } };
	POINT hhhhill31[1] = { { 0,5 } };
	POINT hhhhill32[1] = { { 1,5 } };
	POINT hhhhill33[1] = { { 2,5 } };
	POINT hhhhill34[1] = { { 3,5 } };
	POINT hhhhill35[1] = { { 4,5 } };
	POINT hhhhill36[1] = { { 5,5 } };

	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill1, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill2, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill3, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill4, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill5, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill6, 1, { 0,0 }, 8, 0);

	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill7, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill8, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill9, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill10, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill11, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill12, 1, { 0,0 }, 4, 0);
																						   
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill13, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill14, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill15, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill16, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill17, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill18, 1, { 0,0 }, 4, 0);
																						   
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill19, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill20, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill21, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill22, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill23, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill24, 1, { 0,0 }, 8, 0);
																						   
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill25, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill26, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill27, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill28, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill29, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill30, 1, { 0,0 }, 2, 0);
																						   
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill31, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill32, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill33, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill34, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill35, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽11111", "절벽11111", DECO_HILL4, false, hhhhill36, 1, { 0,0 }, 8, 0);

	POINT qhill1[1] = { { 0,0 } };
	POINT qhill2[1] = { { 1,0 } };
	POINT qhill3[1] = { { 2,0 } };
	POINT qhill4[1] = { { 3,0 } };
	POINT qhill5[1] = { { 4,0 } };
	POINT qhill6[1] = { { 5,0 } };
	POINT qhill7[1] = { { 0,1 } };
	POINT qhill8[1] = { { 1,1 } };
	POINT qhill9[1] = { { 2,1 } };
	POINT qhill10[1] = { { 3,1 } };
	POINT qhill11[1] = { { 4,1 } };
	POINT qhill12[1] = { { 5,1 } };
	POINT qhill13[1] = { { 0,2 } };
	POINT qhill14[1] = { { 1,2 } };
	POINT qhill15[1] = { { 2,2 } };
	POINT qhill16[1] = { { 3,2 } };
	POINT qhill17[1] = { { 4,2 } };
	POINT qhill18[1] = { { 5,2 } };
	POINT qhill19[1] = { { 0,3 } };
	POINT qhill20[1] = { { 1,3 } };
	POINT qhill21[1] = { { 2,3 } };
	POINT qhill22[1] = { { 3,3 } };
	POINT qhill23[1] = { { 4,3 } };
	POINT qhill24[1] = { { 5,3 } };
	POINT qhill25[1] = { { 0,4 } };
	POINT qhill26[1] = { { 1,4 } };
	POINT qhill27[1] = { { 2,4 } };
	POINT qhill28[1] = { { 3,4 } };
	POINT qhill29[1] = { { 4,4 } };
	POINT qhill30[1] = { { 5,4 } };
	POINT qhill31[1] = { { 0,5 } };
	POINT qhill32[1] = { { 1,5 } };
	POINT qhill33[1] = { { 2,5 } };
	POINT qhill34[1] = { { 3,5 } };
	POINT qhill35[1] = { { 4,5 } };
	POINT qhill36[1] = { { 5,5 } };

	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill1, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill2, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill3, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill4, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill5, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill6, 1, { 0,0 }, 2, 0);

	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill7, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill8, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill9, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill10, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill11, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill12, 1, { 0,0 }, 2, 0);

	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill13, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill14, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill15, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill16, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill17, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill18, 1, { 0,0 }, 1, 0);
																				   
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill19, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill20, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill21, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill22, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill23, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill24, 1, { 0,0 }, 8, 0);
																				   
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill25, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill26, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill27, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill28, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill29, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill30, 1, { 0,0 }, 4, 0);
																				   
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill31, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill32, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill33, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill34, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill35, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽22", "절벽22", DECO_HILL5, false, qhill36, 1, { 0,0 }, 0, 0);

	POINT qqhill1[1] = { { 0,0 } };
	POINT qqhill2[1] = { { 1,0 } };
	POINT qqhill3[1] = { { 2,0 } };
	POINT qqhill4[1] = { { 3,0 } };
	POINT qqhill5[1] = { { 4,0 } };
	POINT qqhill6[1] = { { 5,0 } };
	POINT qqhill7[1] = { { 0,1 } };
	POINT qqhill8[1] = { { 1,1 } };
	POINT qqhill9[1] = { { 2,1 } };
	POINT qqhill10[1] = { { 3,1 } };
	POINT qqhill11[1] = { { 4,1 } };
	POINT qqhill12[1] = { { 5,1 } };
	POINT qqhill13[1] = { { 0,2 } };
	POINT qqhill14[1] = { { 1,2 } };
	POINT qqhill15[1] = { { 2,2 } };
	POINT qqhill16[1] = { { 3,2 } };
	POINT qqhill17[1] = { { 4,2 } };
	POINT qqhill18[1] = { { 5,2 } };
	POINT qqhill19[1] = { { 0,3 } };
	POINT qqhill20[1] = { { 1,3 } };
	POINT qqhill21[1] = { { 2,3 } };
	POINT qqhill22[1] = { { 3,3 } };
	POINT qqhill23[1] = { { 4,3 } };
	POINT qqhill24[1] = { { 5,3 } };
	POINT qqhill25[1] = { { 0,4 } };
	POINT qqhill26[1] = { { 1,4 } };
	POINT qqhill27[1] = { { 2,4 } };
	POINT qqhill28[1] = { { 3,4 } };
	POINT qqhill29[1] = { { 4,4 } };
	POINT qqhill30[1] = { { 5,4 } };
	POINT qqhill31[1] = { { 0,5 } };
	POINT qqhill32[1] = { { 1,5 } };
	POINT qqhill33[1] = { { 2,5 } };
	POINT qqhill34[1] = { { 3,5 } };
	POINT qqhill35[1] = { { 4,5 } };
	POINT qqhill36[1] = { { 5,5 } };

	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill1, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill2, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill3, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill4, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill5, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill6, 1, { 0,0 }, 2, 0);

	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill7, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill8, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill9, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill10, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill11, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill12, 1, { 0,0 }, 8, 0);

	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill13, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill14, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill15, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill16, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill17, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill18, 1, { 0,0 }, 4, 0);
																					  
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill19, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill20, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill21, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill22, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill23, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill24, 1, { 0,0 }, 8, 0);
																					  
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill25, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill26, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill27, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill28, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill29, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill30, 1, { 0,0 }, 2, 0);
																					  
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill31, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill32, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill33, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill34, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill35, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽222", "절벽222", DECO_HILL6, false, qqhill36, 1, { 0,0 }, 1, 0);

	POINT qqqhill1[1] = { { 0,0 } };
	POINT qqqhill2[1] = { { 1,0 } };
	POINT qqqhill3[1] = { { 2,0 } };
	POINT qqqhill4[1] = { { 3,0 } };
	POINT qqqhill5[1] = { { 4,0 } };
	POINT qqqhill6[1] = { { 5,0 } };
	POINT qqqhill7[1] = { { 0,1 } };
	POINT qqqhill8[1] = { { 1,1 } };
	POINT qqqhill9[1] = { { 2,1 } };
	POINT qqqhill10[1] = { { 3,1 } };
	POINT qqqhill11[1] = { { 4,1 } };
	POINT qqqhill12[1] = { { 5,1 } };
	POINT qqqhill13[1] = { { 0,2 } };
	POINT qqqhill14[1] = { { 1,2 } };
	POINT qqqhill15[1] = { { 2,2 } };
	POINT qqqhill16[1] = { { 3,2 } };
	POINT qqqhill17[1] = { { 4,2 } };
	POINT qqqhill18[1] = { { 5,2 } };
	POINT qqqhill19[1] = { { 0,3 } };
	POINT qqqhill20[1] = { { 1,3 } };
	POINT qqqhill21[1] = { { 2,3 } };
	POINT qqqhill22[1] = { { 3,3 } };
	POINT qqqhill23[1] = { { 4,3 } };
	POINT qqqhill24[1] = { { 5,3 } };
	POINT qqqhill25[1] = { { 0,4 } };
	POINT qqqhill26[1] = { { 1,4 } };
	POINT qqqhill27[1] = { { 2,4 } };
	POINT qqqhill28[1] = { { 3,4 } };
	POINT qqqhill29[1] = { { 4,4 } };
	POINT qqqhill30[1] = { { 5,4 } };
	POINT qqqhill31[1] = { { 0,5 } };
	POINT qqqhill32[1] = { { 1,5 } };
	POINT qqqhill33[1] = { { 2,5 } };
	POINT qqqhill34[1] = { { 3,5 } };
	POINT qqqhill35[1] = { { 4,5 } };
	POINT qqqhill36[1] = { { 5,5 } };

	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill1, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill2, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill3, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill4, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill5, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill6, 1, { 0,0 }, 4, 0);

	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill7, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill8, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill9, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill10, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill11, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill12, 1, { 0,0 }, 8, 0);

	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill13, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill14, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill15, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill16, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill17, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill18, 1, { 0,0 }, 2, 0);
																						 
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill19, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill20, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill21, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill22, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill23, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill24, 1, { 0,0 }, 1, 0);
																						 
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill25, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill26, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill27, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill28, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill29, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill30, 1, { 0,0 }, 2, 0);
																						 
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill31, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill32, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill33, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill34, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill35, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽2222", "절벽2222", DECO_HILL7, false, qqqhill36, 1, { 0,0 }, 8, 0);

	POINT qqqqhill1[1] = { { 0,0 } };
	POINT qqqqhill2[1] = { { 1,0 } };
	POINT qqqqhill3[1] = { { 2,0 } };
	POINT qqqqhill4[1] = { { 3,0 } };
	POINT qqqqhill5[1] = { { 4,0 } };
	POINT qqqqhill6[1] = { { 5,0 } };
	POINT qqqqhill7[1] = { { 0,1 } };
	POINT qqqqhill8[1] = { { 1,1 } };
	POINT qqqqhill9[1] = { { 2,1 } };
	POINT qqqqhill10[1] = { { 3,1 } };
	POINT qqqqhill11[1] = { { 4,1 } };
	POINT qqqqhill12[1] = { { 5,1 } };
	POINT qqqqhill13[1] = { { 0,2 } };
	POINT qqqqhill14[1] = { { 1,2 } };
	POINT qqqqhill15[1] = { { 2,2 } };
	POINT qqqqhill16[1] = { { 3,2 } };
	POINT qqqqhill17[1] = { { 4,2 } };
	POINT qqqqhill18[1] = { { 5,2 } };
	POINT qqqqhill19[1] = { { 0,3 } };
	POINT qqqqhill20[1] = { { 1,3 } };
	POINT qqqqhill21[1] = { { 2,3 } };
	POINT qqqqhill22[1] = { { 3,3 } };
	POINT qqqqhill23[1] = { { 4,3 } };
	POINT qqqqhill24[1] = { { 5,3 } };
	POINT qqqqhill25[1] = { { 0,4 } };
	POINT qqqqhill26[1] = { { 1,4 } };
	POINT qqqqhill27[1] = { { 2,4 } };
	POINT qqqqhill28[1] = { { 3,4 } };
	POINT qqqqhill29[1] = { { 4,4 } };
	POINT qqqqhill30[1] = { { 5,4 } };
	POINT qqqqhill31[1] = { { 0,5 } };
	POINT qqqqhill32[1] = { { 1,5 } };
	POINT qqqqhill33[1] = { { 2,5 } };
	POINT qqqqhill34[1] = { { 3,5 } };
	POINT qqqqhill35[1] = { { 4,5 } };
	POINT qqqqhill36[1] = { { 5,5 } };

	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill1, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill2, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill3, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill4, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill5, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill6, 1, { 0,0 }, 0, 0);

	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill7, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill8, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill9, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill10, 1, {0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill11, 1, {0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill12, 1, {0,0 }, 1, 0);

	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill13, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill14, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill15, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill16, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill17, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill18, 1, { 0,0 }, 2, 0);
																							  
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill19, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill20, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill21, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill22, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill23, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill24, 1, { 0,0 }, 4, 0);
																							  
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill25, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill26, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill27, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill28, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill29, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill30, 1, { 0,0 }, 8, 0);

	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill31, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill32, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill33, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill34, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill35, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽22222", "절벽22222", DECO_HILL8, false, qqqqhill36, 1, { 0,0 }, 8, 0);

	POINT whill1[1] = { { 0,0 } };
	POINT whill2[1] = { { 1,0 } };
	POINT whill3[1] = { { 2,0 } };
	POINT whill4[1] = { { 3,0 } };
	POINT whill5[1] = { { 0,1 } };
	POINT whill6[1] = { { 1,1 } };



	TILEMANAGER->addDecoration("절벽33", "절벽33", DECO_HILL9, false, whill1, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽33", "절벽33", DECO_HILL9, false, whill2, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽33", "절벽33", DECO_HILL9, false, whill3, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽33", "절벽33", DECO_HILL9, false, whill4, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽33", "절벽33", DECO_HILL9, false, whill5, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽33", "절벽33", DECO_HILL9, false, whill6, 1, { 0,0 }, 2, 0);


	POINT wwhill1[1] = { { 0,0 } };
	POINT wwhill2[1] = { { 1,0 } };
	POINT wwhill3[1] = { { 2,0 } };
	POINT wwhill4[1] = { { 3,0 } };
	POINT wwhill5[1] = { { 2,1 } };
	POINT wwhill6[1] = { { 3,1 } };



	TILEMANAGER->addDecoration("절벽333", "절벽333", DECO_HILL10, false, wwhill1, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽333", "절벽333", DECO_HILL10, false, wwhill2, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽333", "절벽333", DECO_HILL10, false, wwhill3, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽333", "절벽333", DECO_HILL10, false, wwhill4, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽333", "절벽333", DECO_HILL10, false, wwhill5, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽333", "절벽333", DECO_HILL10, false, wwhill6, 1, { 0,0 }, 8, 0);

	POINT wwwhill1[1] = { { 0,2 } };
	POINT wwwhill2[1] = { { 1,2 } };
	POINT wwwhill3[1] = { { 2,3 } };
	POINT wwwhill4[1] = { { 3,3 } };
	POINT wwwhill5[1] = { { 2,3 } };
	POINT wwwhill6[1] = { { 3,3 } };



	TILEMANAGER->addDecoration("절벽3333", "절벽3333", DECO_HILL11, false, wwwhill1, 1, { 0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽3333", "절벽3333", DECO_HILL11, false, wwwhill2, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽3333", "절벽3333", DECO_HILL11, false, wwwhill3, 1, { 0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽3333", "절벽3333", DECO_HILL11, false, wwwhill4, 1, { 0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽3333", "절벽3333", DECO_HILL11, false, wwwhill5, 1, { 0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽3333", "절벽3333", DECO_HILL11, false, wwwhill6, 1, { 0,0 }, 4, 0);


	POINT wwwwhill1[1] = { { 2,2 } };
	POINT wwwwhill2[1] = { { 3,2 } };
	POINT wwwwhill3[1] = { { 0,3 } };
	POINT wwwwhill4[1] = { { 1,3 } };
	POINT wwwwhill5[1] = { { 2,3 } };
	POINT wwwwhill6[1] = { { 3,3 } };



	TILEMANAGER->addDecoration("절벽33333", "절벽33333", DECO_HILL12, false, wwwwhill1, 1, {0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽33333", "절벽33333", DECO_HILL12, false, wwwwhill2, 1, {0,0 }, 2, 0);
	TILEMANAGER->addDecoration("절벽33333", "절벽33333", DECO_HILL12, false, wwwwhill3, 1, {0,0 }, 8, 0);
	TILEMANAGER->addDecoration("절벽33333", "절벽33333", DECO_HILL12, false, wwwwhill4, 1, {0,0 }, 1, 0);
	TILEMANAGER->addDecoration("절벽33333", "절벽33333", DECO_HILL12, false, wwwwhill5, 1, {0,0 }, 4, 0);
	TILEMANAGER->addDecoration("절벽33333", "절벽33333", DECO_HILL12, false, wwwwhill6, 1, {0,0 }, 8, 0);


	//마을
	POINT ab1[1] = { {0,0} };
	POINT ab2[1] = { { 1,0 } };
	POINT ab3[1] = { { 2,0 } };
	POINT ab4[1] = { { 3,0 } };
	POINT ab5[1] = { { 0,1 } };
	POINT ab6[1] = { { 1,1 } };
	POINT ab7[1] = { { 2,1 } };
	POINT ab8[1] = { { 3,1 } };
	TILEMANAGER->addDecoration("마룻바닥", "마룻바닥", DECO_EMPTY, false, ab1, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("마룻바닥", "마룻바닥", DECO_EMPTY, false, ab2, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("마룻바닥", "마룻바닥", DECO_EMPTY, false, ab3, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("마룻바닥", "마룻바닥", DECO_EMPTY, false, ab4, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("마룻바닥", "마룻바닥", DECO_EMPTY, false, ab5, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("마룻바닥", "마룻바닥", DECO_EMPTY, false, ab6, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("마룻바닥", "마룻바닥", DECO_EMPTY, false, ab7, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("마룻바닥", "마룻바닥", DECO_EMPTY, false, ab8, 1, { 0,0 }, 0, 3);

	POINT aaa1[1] = { {0,0} };
	POINT aaa2[1] = { { 1,0 } };
	POINT aaa3[1] = { { 2,0 } };
	POINT aaa4[1] = { { 3,0 } };
	POINT aaa5[1] = { { 0,1 } };
	POINT aaa6[1] = { { 1,1 } };
	POINT aaa7[1] = { { 2,1 } };
	POINT aaa8[1] = { { 3,1 } };
	POINT aaa9[1] = { { 0,2 } };
	POINT aaa10[1] = { { 1,2 } };
	POINT aaa11[1] = { { 2,2 } };
	POINT aaa12[1] = { { 3,2 } };
	POINT aaa13[1] = { { 0,3 } };
	POINT aaa14[1] = { { 1,3 } };
	POINT aaa15[1] = { { 2,3 } };
	POINT aaa16[1] = { { 3,3 } };
	POINT aaa17[1] = { { 0,4 } };
	POINT aaa18[1] = { { 1,4 } };
	POINT aaa19[1] = { { 2,4 } };
	POINT aaa20[1] = { { 3,4 } };
	POINT aaa21[1] = { { 0,5 } };
	POINT aaa22[1] = { { 1,5 } };
	POINT aaa23[1] = { { 2,5 } };
	POINT aaa24[1] = { { 3,5 } };
	POINT aaa25[1] = { { 0,6 } };
	POINT aaa26[1] = { { 1,6 } };
	POINT aaa27[1] = { { 2,6 } };
	POINT aaa28[1] = { { 3,6 } };
	POINT aaa29[1] = { { 0,7 } };
	POINT aaa30[1] = { { 1,7 } };
	POINT aaa31[1] = { { 2,7 } };
	POINT aaa32[1] = { { 3,7 } };
	
	//집바닥
	TILEMANAGER->addDecoration("집바닥", "집바닥",DECO_HOUSE, false, aaa1, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa2, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa3, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa4, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa5, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa6, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa7, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa8, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa9, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa10, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa11, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa12, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa13, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa14, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa15, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa16, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa17, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa18, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa19, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa20, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa21, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa22, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa23, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa24, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa25, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa26, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa27, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa28, 1, { 0,0 }, 0, 3);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa29, 1, { 0,0 }, 0, 0);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa30, 1, { 0,0 }, 0, 2);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa31, 1, { 0,0 }, 0, 1);
	TILEMANAGER->addDecoration("집바닥", "집바닥", DECO_HOUSE, false, aaa32, 1, { 0,0 }, 0, 3);
	
	//d
	TILEMANAGER->addObject("벽아래", "벽아래", { 0,0 }, { 1,2 }, { 0,0 }, OBJECT_HOUSE);
	TILEMANAGER->addObject("벽위", "벽위", { 0,0 }, { 1,2 }, { 0,0 }, OBJECT_HOUSE);
	TILEMANAGER->addObject("벽오른쪽", "벽오른쪽", { 0,0 }, { 2,1 }, { 0,0 }, OBJECT_HOUSE);
	TILEMANAGER->addObject("벽왼쪽", "벽왼쪽", { 0,0 }, { 2,1 }, { 0,0 }, OBJECT_HOUSE);

	TILEMANAGER->addObject("오바서리", "오른쪽바텀모서리", { 0,0 }, { 2,2 }, { 0,0 }, OBJECT_HOUSE1);
	TILEMANAGER->addObject("오탑서리", "오른쪽탑모서리", { 0,0 }, { 2,2 }, { 0,0 }, OBJECT_HOUSE1);
	TILEMANAGER->addObject("왼바서리", "왼쪽바텀모서리", { 0,0 }, { 2,2 }, { 0,0 }, OBJECT_HOUSE1);
	TILEMANAGER->addObject("왼탑서리", "왼쪽탑모서리", { 0,0 }, { 2,2 }, { 0,0 }, OBJECT_HOUSE1);

	TILEMANAGER->addObject("작은책상", "작은책상", { 0,0 }, { 2,1 }, { 0,0 }, OBJECT_HOUSE2);
	TILEMANAGER->addObject("의자", "의자", { 0,0 }, { 1,1 }, { 0,0 }, OBJECT_HOUSE2);
	TILEMANAGER->addObject("큰탁상", "큰탁상", { 0,0 }, { 3,2 }, { 0,0 }, OBJECT_HOUSE2);
	TILEMANAGER->addObject("침대", "침대", { 0,0 }, { 2,2 }, { 0,0 }, OBJECT_HOUSE2);
	TILEMANAGER->addObject("실내문", "실내문", { 0,0 }, { 2,2 }, { 0,0 }, OBJECT_HOUSE2);

	TILEMANAGER->addTerrain("항타", "항아리타일", { 0,0 }, TR_BASIC);
	TILEMANAGER->addTerrain("집타", "집인테타일", { 0,0 }, TR_BASIC);
	//POINT bx[2] = { {0,0},{1,0} };
	//TILEMANAGER->addFrameObject("상자", "상자", bx, 2, { 0,0 }, { 0,0 }, OBJECT_HOUSE);

	POINT ko[1] = { {0,0} };
	POINT ko1[1] = { {1,0} };
	POINT ko2[1] = { {2,0} };

	POINT kkz1[1] = { {0,0} };
	POINT kkz2[1] = { {1,0} };
	POINT kkz3[1] = { { 0,1 } };
	POINT kkz4[1] = { { 1,1 } };

	POINT kp[1] = { {0,0} };
	POINT kp1[1] = { { 1,0 } };

	POINT kv[1] = { {0,0} };
	POINT kv2[1] = { {0,1} };
	TILEMANAGER->addDecoration("윗창문", "윗창문", DECO_HOUSE1, false, kp, 1, { 0,0 }, 15, 0);
	TILEMANAGER->addDecoration("윗창문", "윗창문", DECO_HOUSE1, false, kp1, 1, { 0,0 }, 15, 0);
	TILEMANAGER->addDecoration("아래창문", "아래창문", DECO_HOUSE1, false, kp, 1, { 0,0 }, 15, 0);
	TILEMANAGER->addDecoration("아래창문", "아래창문", DECO_HOUSE1, false, kp1, 1, { 0,0 }, 15, 0);
	TILEMANAGER->addDecoration("왼창문", "왼창문", DECO_HOUSE1, false, kv, 1, { 0,0 }, 15, 0);
	TILEMANAGER->addDecoration("왼창문", "왼창문", DECO_HOUSE1, false, kv2, 1, { 0,0 }, 15, 0);
	TILEMANAGER->addDecoration("오른창문", "오른창문", DECO_HOUSE1, false, kv, 1, { 0,0 }, 15, 0);
	TILEMANAGER->addDecoration("오른창문", "오른창문", DECO_HOUSE1, false, kv2, 1, { 0,0 }, 15, 0);

	TILEMANAGER->addDecoration("선반", "선반", DECO_HOUSE1, false, ko, 1, { 0,0 }, 15, 0);
	TILEMANAGER->addDecoration("선반", "선반", DECO_HOUSE1, false, ko1, 1, { 0,0 }, 15, 0);
	TILEMANAGER->addDecoration("선반", "선반", DECO_HOUSE1, false, ko2, 1, { 0,0 }, 15, 0);

	TILEMANAGER->addDecoration("화", "화덕222", DECO_HOUSE1, false, kkz1, 1, { 0,0 }, 15, 0);
	TILEMANAGER->addDecoration("화", "화덕222", DECO_HOUSE1, false, kkz2, 1, { 0,0 }, 15, 0);
	TILEMANAGER->addDecoration("화", "화덕222", DECO_HOUSE1, false, kkz3, 1, { 0,0 }, 15, 0);
	TILEMANAGER->addDecoration("화", "화덕222", DECO_HOUSE1, false, kkz4, 1, { 0,0 }, 15, 0);

	TILEMANAGER->addTerrain("wat", "wat", { 0,0 }, TR_BASIC);
	TILEMANAGER->addTerrain("acac", "acac", { 0,0 }, TR_BASIC);
}