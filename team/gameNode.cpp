#include "stdafx.h"
#include "gameNode.h"
#include "inventory.h"
#include "player.h"

gameNode::gameNode()
{
}


gameNode::~gameNode()
{

}

//HRESULT == MS디버깅 
//S_OK
//E_FAIL
//SUCCEDED
HRESULT gameNode::init()
{
	_hdc = GetDC(_hWnd);
	_managerInit = false;

	return S_OK;
}
HRESULT gameNode::init(int choice)
{
	_hdc = GetDC(_hWnd);
	_managerInit = false;
	return S_OK;
}

HRESULT gameNode::init(player* mainPlayer, inventory* inven)
{
	_hdc = GetDC(_hWnd);
	_managerInit = false;
	return S_OK;
}
HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;

	if ( _managerInit )
	{
		//타이머 셋팅 == 0.01
		//SetTimer(_hWnd, 1, 10, NULL);
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		TIMEMANAGER->init();
		SOUNDMANAGER->init();
		EFFECTMANAGER->init();
		SCENEMANAGER->init();
		KEYANIMANAGER->init();
		CAMERAMANAGER->init();
		TXTDATA->init();
		INIDATA->init();
	}


	return S_OK;
}

void gameNode::release()
{
	if ( _managerInit )
	{
		//KillTimer(_hWnd, 1);
		KEYMANAGER->releaseSingleton();
		IMAGEMANAGER->releaseSingleton();
		TIMEMANAGER->releaseSingleton();
		SOUNDMANAGER->releaseSingleton();
		EFFECTMANAGER->releaseSingleton();
		SCENEMANAGER->releaseSingleton();
		KEYANIMANAGER->releaseSingleton();
		CAMERAMANAGER->releaseSingleton();
		TXTDATA->releaseSingleton();
		INIDATA->releaseSingleton();
	}

	ReleaseDC(_hWnd, _hdc);
	
}
		
void gameNode::update()	
{
	CAMERAMANAGER->update();
	EFFECTMANAGER->update();
}
	
void gameNode::render()
{

}


LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;

	switch (iMessage)
	{
		case WM_MOUSEMOVE:
			GetCursorPos(&_ptMouse);
			ScreenToClient(_hWnd, &_ptMouse);
			/*
			_ptMouse.x = static_cast<float>LOWORD(lParam);
			_ptMouse.y = static_cast<float>HIWORD(lParam);*/

		break;
		case WM_KEYDOWN:
			switch (wParam)
			{
				case VK_ESCAPE:
					PostMessage(hWnd, WM_DESTROY, 0, 0);
				break;
			}
		break;

		case WM_DESTROY:
			//PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
