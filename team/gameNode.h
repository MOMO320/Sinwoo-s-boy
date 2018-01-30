#pragma once
#include "image.h"

static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);
static image* _mapToolBuffer = IMAGEMANAGER->addImage("mapToolBuffer", TOOLSIZEX, TOOLSIZEY);

//상점하기 위한 전방선언
class inventory;
class player;


class nameInput;
class saveLoad;
//아마 캐릭터관련해서도 필요하지 않을까 싶음



class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;
protected:
	nameInput* NI;
	saveLoad* SL;

	int _choice;
public:
	
	virtual HRESULT init();		//초기화 함수
	virtual HRESULT init(int Number);
	virtual HRESULT init(bool managerInit);
	virtual HRESULT init(player* mainPlayer, inventory* inven);

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

	virtual nameInput* getNI() { return NI; }
	virtual saveLoad* getSL() { return SL; }

	virtual void setNI(nameInput* NAMEINPUT) {}
	virtual void setSL(saveLoad* SAVELOAD) {}

	int getFile() { return _choice; }
	void setFile(int FILE) { _choice = FILE; }

	virtual LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

	gameNode();
	virtual ~gameNode();
};

