#include "stdafx.h"
#include "mapTool.h"
#include "Select_character.h"
#include "Select_Event.h"
#include "Select_Obj.h"
#include "Select_Deco.h"
#include "Select_TR.h"

#pragma comment(lib,"UxTheme.lib")

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
	popUpPage = FALSE;
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
	//DestroyWindow(_scrollhorz);
	//DestroyWindow(_scrollvert);
	DestroyWindow(addMapBtn);
	DestroyWindow(deleteMapBtn);
	DestroyWindow(addMapPage);
	DestroyWindow(comboBoxMap);

	/*
	HWND _goMainSwitch;
	HWND _btn[4];
	HWND addMapBtn;
	HWND addMapPage;
	HWND textMapName;
	HWND textMapSizeX, textMapSizeY;
	HWND addMapOK, addMapFALSE;
	HWND deleteMapBtn;
	*/


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

	if (!popUpPage)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (currentTileMode != NULL)
			{
				if (currentTileMode->keyDownUpdate(VK_LBUTTON))
				{
					SendMessage(eraser, BM_SETCHECK, BST_UNCHECKED, 0);
					_drawArea->setEraser(false);
				}
			}
		}
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON) && PtInRect(&RectMake(areaStartX, areaStartY, areaSizeX, areaSizeY), _ptMouse))
		{
			_drawArea->keyDownUpdate(VK_LBUTTON);
		}
	}

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

	if (addMapPage != NULL)
	{
		HDC childDC = GetDC(addMapPage);
		char str[128];
		sprintf(str, "맵 이름 : ");
		TextOut(childDC, 10, 25, str, strlen(str));
		sprintf(str, "X 타일 수 : ");
		TextOut(childDC, 10, 55, str, strlen(str));
		sprintf(str, "Y 타일 수 : ");
		TextOut(childDC, 10, 85, str, strlen(str));
	}

	//==================== 건들지마라 =======================
	this->getToolBuffer()->render(getHDC(), 0, 0);

}


//버튼 클릭시 상태 변경 설정
void mapTool::setBtnSelect(WPARAM wParam)
{
	if (!popUpPage)
	{
		int itemIndex;
		switch (LOWORD(wParam))
		{
		case BTN_TERRAIN:
			if (currentTileMode != NULL) {
				_drawArea->LinkWithSelectTile(NULL);
				currentTileMode->release();
				SAFE_DELETE(currentTileMode);
			}
			currentTileMode = new Select_TR;
			currentTileMode->init();
			_drawArea->setCurrentLayer(TILE_TERRAIN);
			_drawArea->LinkWithSelectTile(currentTileMode);
			SendMessage(eraser, BM_SETCHECK, BST_UNCHECKED, 0);
			_drawArea->setEraser(false);
			break;
		case BTN_OBJECT:
			if (currentTileMode != NULL) {
				_drawArea->LinkWithSelectTile(NULL);
				currentTileMode->release();
				SAFE_DELETE(currentTileMode);
			}
			currentTileMode = new Select_Obj;
			currentTileMode->init();
			_drawArea->setCurrentLayer(TILE_OBJECT);
			_drawArea->LinkWithSelectTile(currentTileMode);
			SendMessage(eraser, BM_SETCHECK, BST_UNCHECKED, 0);
			_drawArea->setEraser(false);
			break;
		case BTN_DECO:
			if (currentTileMode != NULL) {
				_drawArea->LinkWithSelectTile(NULL);
				currentTileMode->release();
				SAFE_DELETE(currentTileMode);
			}
			currentTileMode = new Select_Deco;
			currentTileMode->init();
			_drawArea->setCurrentLayer(TILE_DECORATION);
			_drawArea->LinkWithSelectTile(currentTileMode);
			SendMessage(eraser, BM_SETCHECK, BST_UNCHECKED, 0);
			_drawArea->setEraser(false);

			break;
		case BTN_EVENT:
			if (currentTileMode != NULL) {
				_drawArea->LinkWithSelectTile(NULL);
				currentTileMode->release();
				SAFE_DELETE(currentTileMode);
			}
			currentTileMode = new Select_Event;
			currentTileMode->init();
			_drawArea->setCurrentLayer(TILE_EVENT);
			_drawArea->LinkWithSelectTile(currentTileMode);
			SendMessage(eraser, BM_SETCHECK, BST_UNCHECKED, 0);
			_drawArea->setEraser(false);
			break;
		case BTN_CHARACTER:
			if (currentTileMode != NULL) {
				_drawArea->LinkWithSelectTile(NULL);
				currentTileMode->release();
				SAFE_DELETE(currentTileMode);
			}
			currentTileMode = new Select_character;
			currentTileMode->init();
			_drawArea->setCurrentLayer(TILE_CHARACTER);
			_drawArea->LinkWithSelectTile(currentTileMode);
			SendMessage(eraser, BM_SETCHECK, BST_UNCHECKED, 0);
			_drawArea->setEraser(false);
			break;
		case BTN_MAINPAGE:
			page = PAGE_CHANGE;
			_pageChange = TRUE;
			release();
			break;
		case BTN_ADD_MAP:
			addMapPage = CreateWindow(WINNAME, TEXT("addMapPage"), WS_POPUPWINDOW | WS_VISIBLE, areaStartX + 115, areaStartY - 40 + 110, 200, 160, _hWnd, 0, _hInstance, NULL);
			//SetWindowPos(addMapPage, addMapBtn,WINSTARTX+ areaStartX+100,WINSTARTY+ areaStartY - 40, 230, 220, SWP_NOZORDER);
			textMapName = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 80, 20, 100, 25, addMapPage, HMENU(TEXT_ADD_MAPNAME), _hInstance, NULL);
			textMapSizeX = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 100, 50, 80, 25, addMapPage, HMENU(TEXT_ADD_MAPX), _hInstance, NULL);
			textMapSizeY = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 100, 80, 80, 25, addMapPage, HMENU(TEXT_ADD_MAPY), _hInstance, NULL);
			addMapOK = CreateWindow("button", "추가", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 130, 110, 50, 30, addMapPage, HMENU(BTN_ADD_MAP_OK), _hInstance, NULL);
			addMapFALSE = CreateWindow("button", "취소", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 70, 110, 50, 30, addMapPage, HMENU(BTN_ADD_MAP_NO), _hInstance, NULL);
			popUpPage = TRUE;
			SendMessage(eraser, BM_SETCHECK, BST_UNCHECKED, 0);
			_drawArea->setEraser(false);
			break;
		case BTN_DELETE_MAP:
			itemIndex = SendMessage(comboBoxMap, CB_GETCURSEL, 0, 0);
			char c[128];
			GetDlgItemText(_hWnd, COMBOBOX_MAP_KIND, c, 127);
			SendMessage(comboBoxMap, CB_DELETESTRING, (WPARAM)(itemIndex), (LPARAM)0);
			_drawArea->deleteMap(c);
			SendMessage(comboBoxMap, CB_SETCURSEL, (WPARAM)(itemIndex - 1), (LPARAM)0);
			GetDlgItemText(_hWnd, COMBOBOX_MAP_KIND, c, 127);
			_drawArea->changeCurrentMapSet(c);
			SendMessage(eraser, BM_SETCHECK, BST_UNCHECKED, 0);
			_drawArea->setEraser(false);
			break;
		case COMBOBOX_MAP_KIND:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				itemIndex = SendMessage(comboBoxMap, CB_GETCURSEL, 0, 0);
				char str[128];
				GetDlgItemText(_hWnd, COMBOBOX_MAP_KIND, str, 127);
				_drawArea->changeCurrentMapSet(str);
			}
			SendMessage(eraser, BM_SETCHECK, BST_UNCHECKED, 0);
			_drawArea->setEraser(false);
			break;
		case BTN_ERASER:
			if (SendMessage(eraser, BM_GETCHECK, 0, 0) == BST_UNCHECKED)
			{
				SendMessage(eraser, BM_SETCHECK, BST_CHECKED, 0);
				_drawArea->setEraser(true);
			}
			else
			{
				SendMessage(eraser, BM_SETCHECK, BST_UNCHECKED, 0);
				_drawArea->setEraser(false);
			}
		}
	}
	else
	{
		int currentItem;
		switch (LOWORD(wParam))
		{
		case BTN_ADD_MAP_OK:
			char mapName[256];
			char sizeX[256], sizeY[256];
			GetWindowText(textMapName, mapName, 256);
			GetWindowText(textMapSizeX, sizeX, 256);
			GetWindowText(textMapSizeY, sizeY, 256);
			if (mapName != NULL && atoi(sizeX) > 0 && atoi(sizeY) > 0)
			{
				_drawArea->addMap(mapName, atoi(sizeX), atoi(sizeY));
				DestroyWindow(addMapPage);
				SendMessage(comboBoxMap, CB_ADDSTRING, 0, (LPARAM)mapName);
			}
			currentItem = SendMessage(comboBoxMap, CB_GETCOUNT, 0, 0);
			SendMessage(comboBoxMap, CB_SETCURSEL, (WPARAM)(currentItem - 1), (LPARAM)0);
			_drawArea->changeCurrentMapSet(mapName);

			popUpPage = FALSE;
			break;
		case BTN_ADD_MAP_NO:

			DestroyWindow(addMapPage);
			popUpPage = FALSE;
			break;
		}
	}
}

void mapTool::setUp()
{
	//==========================================================================================================================================================================================
	//윈도우 버튼 설정
	//==========================================================================================================================================================================================

	_goMainSwitch = CreateWindow("button", "처음으로", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, TOOLSIZEY - 100, 100, 30, _hWnd, HMENU(BTN_MAINPAGE), _hInstance, NULL);
	addMapBtn = CreateWindow("button", "addMap", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, areaStartX, areaStartY - 40, 80, 30, _hWnd, HMENU(BTN_ADD_MAP), _hInstance, NULL);
	deleteMapBtn = CreateWindow("button", "deleteMap", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, areaStartX + areaSizeX - 100, areaStartY - 40, 100, 30, _hWnd, HMENU(BTN_DELETE_MAP), _hInstance, NULL);

	eraser = CreateWindow("button", "eraser", WS_CHILD | WS_VISIBLE | BS_CHECKBOX, TOOLSIZEX - 620, 80, 100, 30, _hWnd, HMENU(BTN_ERASER), _hInstance, NULL);



	LPCSTR _btnName[5];
	_btnName[0] = "지형";
	_btnName[1] = "오브젝트";
	_btnName[2] = "데코";
	_btnName[3] = "캐릭터/몬스터";
	_btnName[4] = "이벤트";
	int btnNum[5];
	btnNum[0] = BTN_TERRAIN;
	btnNum[1] = BTN_OBJECT;
	btnNum[2] = BTN_DECO;
	btnNum[3] = BTN_CHARACTER;
	btnNum[4] = BTN_EVENT;

	for (int i = 0; i < 5; ++i)
	{
		_btn[i] = CreateWindow("button", _btnName[i], WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, TOOLSIZEX - 500 + 110 * i, 10, 100, 30, _hWnd, HMENU(btnNum[i]), _hInstance, NULL);
		if (i == 0) SetWindowPos(_btn[i], _goMainSwitch, TOOLSIZEX - 500 + 90 * i, 10, 80, 30, SWP_NOMOVE | SWP_NOZORDER);
		else if (i > 0) SetWindowPos(_btn[i], _btn[i - 1], TOOLSIZEX - 500 + 90 * i, 10, 80, 30, SWP_NOMOVE | SWP_NOZORDER);
	}
	//==========================================================================================================================================================================================

	//==========================================================================================================================================================================================
	// 타일설정
	_drawArea = new drawArea;
	_drawArea->init();

	//맵리스트박스
	comboBoxMap = CreateWindow("combobox", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, areaStartX + 100, areaStartY - 35, 110, 200, _hWnd, HMENU(COMBOBOX_MAP_KIND), _hInstance, NULL);

	//==========================================================================================================================================================================================

	//==========================================================================================================================================================================================
	// 처음실행시 설정

	currentTileMode = NULL;
	//==========================================================================================================================================================================================

	//윈도우 핸들 z-order설정

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
	case WM_CTLCOLORSTATIC:
		if ((HWND)lParam == eraser)
			return (LONG)GetStockObject(WHITE_BRUSH);
		
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		render();

		EndPaint(hWnd, &ps);
	}
	break;
	//윈도우 버튼등 입력 처리
	case WM_CREATE:
		break;
	case WM_COMMAND:
		setBtnSelect(wParam);
		break;
	case WM_TIMER:
		InvalidateRect(_hWnd, NULL, false);
		update();
		break;
	case WM_VSCROLL:  // 스크롤바 처리 
		_drawArea->sendvertScrollMessage(wParam);
		
		break;
	case WM_HSCROLL:
		_drawArea->sendhorzScrollMessage(wParam);
		
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
