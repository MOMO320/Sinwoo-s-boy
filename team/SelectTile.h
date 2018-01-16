#pragma once
#include "gameNode.h"


class SelectTile : public gameNode
{
protected:
	
	HWND _comboBox;

	image* _tileImage;



public:
	SelectTile();
	~SelectTile();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

