#pragma once
#include "gameNode.h"
#include "SelectTile.h"
#include "drawArea.h"
#include "tileNode.h"





class mapTool : public gameNode
{
private:
	//DRAW AREA 스크롤바
	HWND _scrollvert;
	HWND _scrollhorz;

	//처음화면으로 가는 버튼
	HWND _goMainSwitch;

	//타일 레이어 선택 4개
	HWND _btn[5];

	//타일 지우개
	HWND eraser;
	//맵 추가
	HWND addMapBtn;
	HWND addMapPage;
	HWND textMapName;
	HWND textMapSizeX, textMapSizeY;
	HWND addMapOK, addMapFALSE;
	HWND deleteMapBtn;


	//맵선택
	HWND comboBoxMap;
	
	//세이브 로드
	HWND save_load[4];



	BOOL popUpPage;
	SWITCH_TILE_LAYER _setTileMode;
	SelectTile* currentTileMode;
	drawArea* _drawArea;
	

public:
	mapTool();
	~mapTool();

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);
	HRESULT init();
	void release();
	void update();
	void render();


	void  setBtnSelect(WPARAM wParam);

	void setUp();
};

