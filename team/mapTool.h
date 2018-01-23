#pragma once
#include "gameNode.h"
#include "SelectTile.h"
#include "drawArea.h"
#include "tileNode.h"





class mapTool : public gameNode
{
private:
	//DRAW AREA ��ũ�ѹ�
	HWND _scrollvert;
	HWND _scrollhorz;

	//ó��ȭ������ ���� ��ư
	HWND _goMainSwitch;

	//Ÿ�� ���̾� ���� 4��
	HWND _btn[5];

	//Ÿ�� ���찳
	HWND eraser;
	//�� �߰�
	HWND addMapBtn;
	HWND addMapPage;
	HWND textMapName;
	HWND textMapSizeX, textMapSizeY;
	HWND addMapOK, addMapFALSE;
	HWND deleteMapBtn;


	//�ʼ���
	HWND comboBoxMap;
	
	//���̺� �ε�
	HWND save_load[4];



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

