#include "stdafx.h"
#include "mainSwitch.h"

#include "mainGame.h"
#include "mapTool.h"

HINSTANCE _hInstance;	//APP 메시지 번호
HWND	_hWnd;			//APP 고유 번호
LPTSTR _lpszClass = TEXT("Hexa API");		//윈도우 클래스 이름

POINT _ptMouse;
POINT _cameraPtMouse;
BOOL _isOnParent = TRUE;
BOOL _leftMouseButton = FALSE;

SWITCH_MAIN page;
BOOL _pageChange = TRUE;
mainSwitch _ms;
mainGame _mg;
mapTool _mt;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	//윈도우 프로시져 의 함수 프로토 타입

void setWindowsSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int cmdShow)
{
	MSG message;			//윈도우 메시지 구조체
	WNDCLASS wndClass;		//윈도우 정보 구조체

	//페이지 선택 화면
	page = PAGE_CHANGE;

	//페이지 게임 화면
	//page = PAGE_GAME;

	//페이지 맵툴 화면
	//page = PAGE_MAPTOOL;

	_hInstance = hInstance;

	wndClass.cbClsExtra = 0;										//클래스 여분 메모리 설정
	wndClass.cbWndExtra = 0;										//윈도우 여분 메모리 설정
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//윈도우 백그라운드 칼라
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					//윈도우 커서 모양
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				//윈도우 아이콘 모양
	wndClass.hInstance = hInstance;									//윈도우 인스턴스 번호
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						//윈도우 프로시져
	wndClass.lpszClassName = WINNAME;								//윈도우 클래스이름
	wndClass.lpszMenuName = NULL;									//윈도우 메뉴 이름
	wndClass.style = CS_HREDRAW | CS_VREDRAW;						//윈도우 창 스타일

	RegisterClass(&wndClass);			//윈도우 정보 등록

	_hWnd = CreateWindow(
		WINNAME,
		WINNAME,
		WS_OVERLAPPEDWINDOW |
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 			//윈도우 창 스타일
		WINSTARTX,						//윈도우 시작좌표 X
		WINSTARTY,						//윈도우 시작좌표 Y
		WINSIZEX,						//윈도우 창 가로크기(width)
		WINSIZEY,						//윈도우 창 세로크기(height)
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL);

	setWindowsSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	ShowWindow(_hWnd, cmdShow);		//윈도우 창 화면에 띄워라

	
	//메시지 루프
	//GetMessage : 윈도우 메시지가 발생하면 그때 처리한다
	//PeekMessage : 메시지가 들어오든 안오든 계속 돌고있다.
	
	/*
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);		//키보드 및 마우스 클릭 등 입력에 해당하는 순간 메시지 처리 담당
		DispatchMessage(&message);		//실제 발생한 메시지를 윈도우로 전달 담당
	}
	*/
	
	//게임용 타이머
	bool exit = false;
	while ( !exit )
	{
	
		switch (page)
		{
		case PAGE_CHANGE:
			if (_pageChange)
			{
				setWindowsSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);
				if (FAILED(_ms.init())) return 0;
				else _pageChange = FALSE;
			}
			if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
			{
				if (message.message == WM_QUIT) exit = true;
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
			else
			{
				TIMEMANAGER->update(60.0f);
				_ms.update();
				_ms.render();
			}
			break;
		case PAGE_GAME:
			if (_pageChange)
			{
				setWindowsSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);
				if (FAILED(_mg.init())) return 0;
				else _pageChange = FALSE;
			}
			if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
			{
				if (message.message == WM_QUIT) exit = true;
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
			else
			{
				TIMEMANAGER->update(60.0f);
				_mg.update();
				_mg.render();
			}
			break;
		case PAGE_MAPTOOL:
			if (_pageChange)
			{
				setWindowsSize(TOOLSTARTX, TOOLSTARTY, TOOLSIZEX, TOOLSIZEY);
				if (FAILED(_mt.init())) return 0;
				_pageChange = FALSE;
			}
			/*if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
			{
				if (message.message == WM_QUIT) exit = true;
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
			else
			{
				TIMEMANAGER->update(60.0f);
				_mt.update();
				_mt.render();
			}*/
			if (GetMessage(&message, 0, 0, 0))
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
			else exit = true;
			break;
		default:
			break;
		}
		
	}
	

	_mg.release();
	_ms.release();
	_mt.release();

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (page)
	{
	case PAGE_CHANGE:
		return _ms.MainProc(hWnd, iMessage, wParam, lParam);
	case PAGE_GAME:
		return _mg.MainProc(hWnd, iMessage, wParam, lParam);
		break;
	case PAGE_MAPTOOL:
		return _mt.MainProc(hWnd, iMessage, wParam, lParam);
		break;
	default:
		break;
	}
}

//클라이언트 영역 재조정 함수
void setWindowsSize(int x, int y, int width, int height)
{
	//윈도우 렉트
	RECT winRect;

	winRect.left = 0;
	winRect.top = 0;
	winRect.right = width;
	winRect.bottom = height;
	
	AdjustWindowRect(&winRect, WINSTYLE, false);

	SetWindowPos(_hWnd, NULL, x, y, (winRect.right - winRect.left),
		(winRect.bottom - winRect.top), SWP_NOZORDER | SWP_NOMOVE);
	MoveWindow(_hWnd, x, y, winRect.right - winRect.left, winRect.bottom - winRect.top, false);
}