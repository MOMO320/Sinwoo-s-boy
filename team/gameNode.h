#pragma once
#include "image.h"

static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);
static image* _mapToolBuffer = IMAGEMANAGER->addImage("mapToolBuffer", TOOLSIZEX, TOOLSIZEY);

class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;

public:
	
	virtual HRESULT init();		//초기화 함수
	virtual HRESULT init(bool managerInit);
	virtual void release();		//메모리 해제 함수
	virtual void update();		//연산 함수
	virtual void render();		//그려주는 함수(a.k.a WM_PAINT)

	//백버퍼 접근자
	image* getBackBuffer() { return _backBuffer; }
	image* getToolBuffer() { return _mapToolBuffer; }

	//메모리DC 접근자
	HDC getToolMemDC() { return _mapToolBuffer->getMemDC(); }
	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }



	virtual LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

	gameNode();
	virtual ~gameNode();
};

