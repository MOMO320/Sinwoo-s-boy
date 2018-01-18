#include "stdafx.h"
#include "mapTool.h"
#include "Select_character.h"
#include "Select_Event.h"
#include "Select_Obj.h"
#include "Select_TR.h"


mapTool::mapTool()
{
}


mapTool::~mapTool()
{
}


HRESULT mapTool::init()
{
	gameNode::init();
	
	//타이머 셋팅 == 0.01
	SetTimer(_hWnd, 1, 10, NULL);

	setUp();


	return S_OK;
}
void  mapTool::release()	  
{

	for (int i = 0; i < TILE_END; i++)
	{
		DestroyWindow(_btn[i]);
	}
	DestroyWindow(_goMainSwitch);
	KillTimer(_hWnd, 1);
}

void  mapTool::update()		  
{
	gameNode::update();

	if (currentTileMode != NULL)
	{
		currentTileMode->update();
	}


	_drawArea->update();
	UpdateWindow(addMapPage);
	ShowWindow(addMapPage, 1);

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (currentTileMode != NULL) currentTileMode->keyDownUpdate(VK_LBUTTON);
	}
	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		_drawArea->keyDownUpdate(VK_LBUTTON);
	}

	if (_leftMouseButton) _leftMouseButton = FALSE;
}

void  mapTool::render()		  
{
	PatBlt(getToolMemDC(), 0, 0, TOOLSIZEX, TOOLSIZEY, WHITENESS);
	//==================== 건들지마라 ======================

	_drawArea->render();

	
	
	if (currentTileMode != NULL)
	{
		currentTileMode->render();
	}

	
	//==================== 건들지마라 =======================
	this->getToolBuffer()->render(getHDC(), 0, 0);

}


//버튼 클릭시 상태 변경 설정
void mapTool::setBtnSelect(int num)
{

	switch (num)
	{
	case BTN_TERRAIN:
		if (currentTileMode != NULL) {
			_drawArea->LinkWithSelectTile(NULL);
			currentTileMode->release();
			SAFE_DELETE(currentTileMode);
		}
		currentTileMode = new Select_TR;
		currentTileMode->init();
		_drawArea->LinkWithSelectTile(currentTileMode);
	break;
	case BTN_OBJECT:
		if (currentTileMode != NULL) {
			_drawArea->LinkWithSelectTile(NULL);
			currentTileMode->release();
			SAFE_DELETE(currentTileMode);
		}
		currentTileMode = new Select_Obj;
		currentTileMode->init();
		_drawArea->LinkWithSelectTile(currentTileMode);
	break;
	case BTN_EVENT:
		if (currentTileMode != NULL) {
			_drawArea->LinkWithSelectTile(NULL);
			currentTileMode->release();
			SAFE_DELETE(currentTileMode);
		}
		currentTileMode = new Select_Event;
		currentTileMode->init();
		_drawArea->LinkWithSelectTile(currentTileMode);
	break;
	case BTN_CHARACTER:
		if (currentTileMode != NULL) {
			_drawArea->LinkWithSelectTile(NULL);
			currentTileMode->release();
			SAFE_DELETE(currentTileMode);
		}
		currentTileMode = new Select_character;
		currentTileMode->init();
		_drawArea->LinkWithSelectTile(currentTileMode);
	break;
	case BTN_MAINPAGE:
		page = PAGE_CHANGE;
		_pageChange = TRUE;
		release();
	break;
	case BTN_ADD_MAP:
		addMapPage = CreateWindow(WINNAME, TEXT("addMapPage"), WS_POPUPWINDOW | WS_VISIBLE, areaStartX + 115, areaStartY - 40 + 110, 200, 160, _hWnd,0, _hInstance, NULL);
		//SetWindowPos(addMapPage, addMapBtn,WINSTARTX+ areaStartX+100,WINSTARTY+ areaStartY - 40, 230, 220, SWP_NOZORDER);
		textMapName = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 80, 20, 100, 25, addMapPage, HMENU(TEXT_ADD_MAPNAME), _hInstance, NULL);
		textMapSizeX = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 100, 50, 80, 25, addMapPage, HMENU(TEXT_ADD_MAPX), _hInstance, NULL);
		textMapSizeY = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 100, 80, 80, 25, addMapPage, HMENU(TEXT_ADD_MAPY), _hInstance, NULL);
		addMapOK = CreateWindow("button", "추가", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 130, 110, 50, 30, addMapPage, HMENU(BTN_ADD_MAP_OK), _hInstance, NULL);
		addMapFALSE = CreateWindow("button", "취소", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 70, 110, 50, 30, addMapPage, HMENU(BTN_ADD_MAP_OK), _hInstance, NULL);

		break;
	default:
	break;
	}
}

void mapTool::setUp()
{
	//==========================================================================================================================================================================================
	//윈도우 버튼 설정
	//==========================================================================================================================================================================================

	_goMainSwitch = CreateWindow("button", "처음으로", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, TOOLSIZEY - 100, 100, 30, _hWnd, HMENU(BTN_MAINPAGE), _hInstance, NULL);
	
	addMapBtn = CreateWindow("button", "addMap",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, areaStartX, areaStartY - 40, 80, 30, _hWnd, HMENU(BTN_ADD_MAP), _hInstance, NULL);
	


	LPCSTR _btnName[4];
	_btnName[0] = "지형";
	_btnName[1] = "오브젝트";
	_btnName[2] = "이벤트";
	_btnName[3] = "캐릭터/몬스터";
	int btnNum[4];
	btnNum[0] = BTN_TERRAIN;
	btnNum[1] = BTN_OBJECT;
	btnNum[2] = BTN_EVENT;
	btnNum[3] = BTN_CHARACTER;

	for (int i = 0; i < TILE_END; ++i)
	{
		_btn[i] = CreateWindow("button", _btnName[i],WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, TOOLSIZEX - 500 + 110 * i, 10, 100, 30, _hWnd, HMENU(btnNum[i]), _hInstance, NULL);
		if(i == 0 ) SetWindowPos(_btn[i],_goMainSwitch, TOOLSIZEX - 500 + 110 * i, 10, 100, 30, SWP_NOMOVE | SWP_NOZORDER);
		else if (i > 0) SetWindowPos(_btn[i], _btn[i - 1], TOOLSIZEX - 500 + 110 * i, 10, 100, 30, SWP_NOMOVE | SWP_NOZORDER);
	}


	//==========================================================================================================================================================================================
	
	//==========================================================================================================================================================================================
	// 타일설정
	_drawArea = new drawArea;
	_drawArea->init();
	

	//==========================================================================================================================================================================================

	//==========================================================================================================================================================================================
	// 처음실행시 설정

	currentTileMode = NULL;
	//==========================================================================================================================================================================================

	//윈도우 핸들 z-order설정
	/*
	_scrollvert;
	_scrollhorz;


	*/
	SetWindowPos(_scrollvert, _hWnd, areaStartX + 800, areaStartY + 5, 20, 700, SWP_NOMOVE | SWP_NOZORDER);
	SetWindowPos(_scrollhorz, _scrollvert, areaStartX + 5, areaStartY + 700, 800, 20, SWP_NOMOVE | SWP_NOZORDER);
	SetWindowPos(_goMainSwitch, _scrollhorz, 10, TOOLSIZEY - 100, 100,30,  SWP_NOMOVE | SWP_NOZORDER);
	for (int i = 0; i < TILE_END; ++i)
	{
		if (i == 0) SetWindowPos(_btn[i], _goMainSwitch, TOOLSIZEX - 500 + 110 * i, 10, 100, 30, SWP_NOMOVE | SWP_NOZORDER);
		else if (i > 0) SetWindowPos(_btn[i], _btn[i - 1], TOOLSIZEX - 500 + 110 * i, 10, 100, 30, SWP_NOMOVE | SWP_NOZORDER);
	}
	SetWindowPos(addMapBtn, _btn[BTN_CHARACTER], areaStartX, areaStartY - 40, 80, 30, SWP_NOMOVE | SWP_NOZORDER);
}



LRESULT mapTool::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	gameNode::MainProc(hWnd, iMessage, wParam, lParam);

	PAINTSTRUCT ps;
	HDC hdc;

	switch (iMessage)
	{
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		render();

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_VSCROLL:  // 스크롤바 처리
		_drawArea->getScrollhWnd(hWnd,iMessage,wParam,lParam);
		break;
	case WM_HSCROLL:
		_drawArea->getScrollhWnd(hWnd, iMessage, wParam, lParam);
		break;
	//윈도우 버튼등 입력 처리
	case WM_CREATE:
		break;
	case WM_COMMAND:
			setBtnSelect(LOWORD(wParam));
	break;
	case WM_TIMER:
		InvalidateRect(_hWnd, NULL, false);
		update();
	break;
	}
	

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
