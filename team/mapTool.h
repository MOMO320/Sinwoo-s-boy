#pragma once
#include "gameNode.h"
#include "SelectTile.h"
#include "drawArea.h"


enum SWITCH_TILE_LAYER
{
	TILE_TERRAIN,
	TILE_OBJECT,
	TILE_EVENT,
	TILE_CHARACTER,
	TILE_END,
};



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

