#pragma once
#include "gameNode.h"
#include "tileNode.h"
#include <vector>

#define tileAreaX 900
#define tileAreaY 100
#define tileAreaSizeX 500
#define tileAreaSizeY 800

static image* tileArea = IMAGEMANAGER->addImage("¿ÃπÃ¡ˆ", 500, 800);

typedef struct tagSampleTileInfo
{
	SWITCH_TILE_LAYER tileClass;
	tagTile_tr* trInfo;
	tagTile_obj* objInfo;
	tagTile_deco* decoInfo;
	tagTile_character* chrInfo;
	tagTile_event* eventInfo;
	RECT rc;

	tagSampleTileInfo()
	{
		tileClass = TILE_END;
		trInfo = NULL;
		objInfo = NULL;
		decoInfo = NULL;
		chrInfo = NULL;
		eventInfo = NULL;

	}
}sampleInfo, *lpSampleInfo;

typedef vector<lpSampleInfo> vSampleTile;

class SelectTile : public gameNode
{

protected:
	HWND _scrollX;
	HWND _scrollY;
	HWND _comboBox;


	BOOL needFind;
	vTrInfo* _vSampleTr;
	vObjInfo* _vSampleObj;
	vEvInfo* _vSampleEvent;
	vCharInfo* _vSampleCharacter;
	vDecInfo* _vSampleDeco;
	vSampleTile _vSampleTile; // <<<<<<<<<<

	sampleInfo* currentTileInfo;
	
	int PcomboIndex, comboIndex;

	int frameCount, timeCount;


public:
	SelectTile();
	~SelectTile();
	image* getTileArea() { return tileArea; }
	HDC getTileAreaDC() { return tileArea->getMemDC(); }
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	BOOL keyDownUpdate(int key);

	void sampleVectorClear();

	sampleInfo* getSelectedTile() { if (currentTileInfo != NULL) return currentTileInfo; else return NULL; }

};

