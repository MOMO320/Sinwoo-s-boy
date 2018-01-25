#pragma once
#include "gameNode.h"
#include "SelectTile.h"
#include "drawArea.h"
#include "tileNode.h"




class mapTool : public gameNode
{
private:
	
	HWND _goMainSwitch;

	//Ÿ�� ���̾� ���� 4��
	HWND _btn[4];

	//Ÿ�� ���찳
	HWND eraser;
	//�� �߰�
	HWND addMapBtn;
	HWND addMapPage;
	HWND textMapName;
	HWND textMapSizeX, textMapSizeY;
	HWND addMapOK, addMapFALSE;
	HWND deleteMapBtn;

//Ÿ�� ���� �Ӽ� ����
	BOOL setAttribute;
	//basic
	HWND setAttribute_Page;

	HWND setAttribute_pageSelect;
	HWND setAttribute_btnOK;
	HWND setAttribute_btnNO;
	//character Attribute
	HWND setAttribute_Char_Patrol;//üũ�ڽ�?
	//event Attribute
	HWND setAttribute_Ev_Index; //�޺��ڽ� show - EVENT ENUM
	HWND setAttribute_Ev_ActCondition; //�޺��ڽ� show - ACT CONDITION
	HWND setAttribute_Ev_color; // �� �Է�
		//index-> �ٸ��� �̵��� ���� �� ��
	HWND setAttribute_Ev_InputParam;


	//�ʼ���
	HWND comboBoxMap;
	
	//���̺� �ε�
	HWND save_load[4];



	PAGE_INDEX current_PAGE;
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

