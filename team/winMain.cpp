#include "stdafx.h"
#include "mainSwitch.h"

#include "mainGame.h"
#include "mapTool.h"

HINSTANCE _hInstance;	//APP �޽��� ��ȣ
HWND	_hWnd;			//APP ���� ��ȣ
LPTSTR _lpszClass = TEXT("Hexa API");		//������ Ŭ���� �̸�

POINT _ptMouse;
BOOL _leftMouseButton = FALSE;

PAGE page;
BOOL _pageChange = TRUE;
mainSwitch _ms;
mainGame _mg;
mapTool _mt;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	//������ ���ν��� �� �Լ� ������ Ÿ��

void setWindowsSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int cmdShow)
{
	MSG message;			//������ �޽��� ����ü
	WNDCLASS wndClass;		//������ ���� ����ü

	//������ ���� ȭ��
	//page = PAGE_CHANGE;

	//������ ���� ȭ��
	page = PAGE_GAME;

	//������ ���� ȭ��
	//page = PAGE_MAPTOOL;

	_hInstance = hInstance;

	wndClass.cbClsExtra = 0;										//Ŭ���� ���� �޸� ����
	wndClass.cbWndExtra = 0;										//������ ���� �޸� ����
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//������ ��׶��� Į��
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					//������ Ŀ�� ���
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				//������ ������ ���
	wndClass.hInstance = hInstance;									//������ �ν��Ͻ� ��ȣ
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						//������ ���ν���
	wndClass.lpszClassName = WINNAME;								//������ Ŭ�����̸�
	wndClass.lpszMenuName = NULL;									//������ �޴� �̸�
	wndClass.style = CS_HREDRAW | CS_VREDRAW;						//������ â ��Ÿ��

	RegisterClass(&wndClass);			//������ ���� ���

	_hWnd = CreateWindow(
		WINNAME,
		WINNAME,
		WS_OVERLAPPEDWINDOW,			//������ â ��Ÿ��
		WINSTARTX,						//������ ������ǥ X
		WINSTARTY,						//������ ������ǥ Y
		WINSIZEX,						//������ â ����ũ��(width)
		WINSIZEY,						//������ â ����ũ��(height)
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL);

	setWindowsSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	ShowWindow(_hWnd, cmdShow);		//������ â ȭ�鿡 �����

	
	//�޽��� ����
	//GetMessage : ������ �޽����� �߻��ϸ� �׶� ó���Ѵ�
	//PeekMessage : �޽����� ������ �ȿ��� ��� �����ִ�.
	
	/*
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);		//Ű���� �� ���콺 Ŭ�� �� �Է¿� �ش��ϴ� ���� �޽��� ó�� ���
		DispatchMessage(&message);		//���� �߻��� �޽����� ������� ���� ���
	}
	*/
	
	//���ӿ� Ÿ�̸�
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

//Ŭ���̾�Ʈ ���� ������ �Լ�
void setWindowsSize(int x, int y, int width, int height)
{
	//������ ��Ʈ
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