#pragma once
#include "gameNode.h"
#include "tileNode.h"
#include <vector>


class SelectTile : public gameNode
{
protected:

	HWND _comboBox;


	BOOL needFind;
	vTrInfo* _vSampleTr;
	vObjInfo* _vSampleObj;

	int PcomboIndex, comboIndex;


public:
	SelectTile();
	~SelectTile();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

