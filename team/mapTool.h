#pragma once
#include "gameNode.h"
#include "SelectTile.h"
#include "drawArea.h"
#include "tileNode.h"





class mapTool : public gameNode
{
private:
	HWND _goMainSwitch;
	HWND _btn[4];
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


	void  setBtnSelect(int num);

	void setUp();
};

