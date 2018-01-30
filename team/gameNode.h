#pragma once
#include "image.h"

static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);
static image* _mapToolBuffer = IMAGEMANAGER->addImage("mapToolBuffer", TOOLSIZEX, TOOLSIZEY);

//�����ϱ� ���� ���漱��
class inventory;
class player;


class nameInput;
class saveLoad;
//�Ƹ� ĳ���Ͱ����ؼ��� �ʿ����� ������ ����



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
	
	virtual HRESULT init();		//�ʱ�ȭ �Լ�
	virtual HRESULT init(int Number);
	virtual HRESULT init(bool managerInit);
	virtual HRESULT init(player* mainPlayer, inventory* inven);

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

