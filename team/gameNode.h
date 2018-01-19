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
	
	virtual HRESULT init();		//�ʱ�ȭ �Լ�
	virtual HRESULT init(bool managerInit);
	virtual void release();		//�޸� ���� �Լ�
	virtual void update();		//���� �Լ�
	virtual void render();		//�׷��ִ� �Լ�(a.k.a WM_PAINT)

	//����� ������
	image* getBackBuffer() { return _backBuffer; }
	image* getToolBuffer() { return _mapToolBuffer; }

	//�޸�DC ������
	HDC getToolMemDC() { return _mapToolBuffer->getMemDC(); }
	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }



	virtual LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

	gameNode();
	virtual ~gameNode();
};

