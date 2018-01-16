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

}

void  mapTool::render()		  
{
	PatBlt(getToolMemDC(), 0, 0, TOOLSIZEX, TOOLSIZEY, WHITENESS);
	//==================== 건들지마라 ======================


	char str[128];
	sprintf(str, "맵툴페이지 입니다.");
	TextOut(getToolMemDC(), WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));
	sprintf(str, "%d %d",_ptMouse.x,_ptMouse.y);
	TextOut(getToolMemDC(), _ptMouse.x - 50, _ptMouse.y, str, strlen(str));
	
	if (currentTileMode != NULL)
	{
		currentTileMode->render();
	}


	//==================== 건들지마라 =======================
	this->getToolBuffer()->render(getHDC(), 0, 0);

}

void mapTool::setBtnSelect(int num)
{

	switch (num)
	{
	case BTN_TERRAIN:
		if (currentTileMode != NULL) {
			currentTileMode->release();
			SAFE_DELETE(currentTileMode);
		}
		currentTileMode = new Select_TR;
		currentTileMode->init();
	break;
	case BTN_OBJECT:
		if (currentTileMode != NULL) {
			currentTileMode->release();
			SAFE_DELETE(currentTileMode);
		}
		currentTileMode = new Select_Obj;
		currentTileMode->init();
	break;
	case BTN_EVENT:
		if (currentTileMode != NULL) {
			currentTileMode->release();
			SAFE_DELETE(currentTileMode);
		}
		currentTileMode = new Select_Event;
		currentTileMode->init();
	break;
	case BTN_CHARACTER:
		if (currentTileMode != NULL) {
			currentTileMode->release();
			SAFE_DELETE(currentTileMode);
		}
		currentTileMode = new Select_character;
		currentTileMode->init();
	break;
	case BTN_MAINPAGE:
		page = PAGE_CHANGE;
		_pageChange = TRUE;
		release();
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
		_btn[i] = CreateWindow("button", _btnName[i], WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, TOOLSIZEX - 500 + 110 * i, 10, 100, 30, _hWnd, HMENU(btnNum[i]), _hInstance, NULL);
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
	//윈도우 버튼등 입력 처리
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