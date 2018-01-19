#pragma once
#include "gameNode.h"
#include "SelectTile.h"
#include "drawArea.h"
#include "tileNode.h"





class mapTool : public gameNode
{
private:
	HWND _scrollvert;
	HWND _scrollhorz;
	HWND _goMainSwitch;
	HWND _btn[4];
	HWND addMapBtn;
	HWND addMapPage;
	HWND textMapName;
	HWND textMapSizeX, textMapSizeY;
	HWND addMapOK, addMapFALSE;
	HWND comboBoxMap;
	HWND deleteMapBtn;


	HWND eraser;

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

