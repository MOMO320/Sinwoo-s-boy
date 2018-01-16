#include "stdafx.h"
#include "drawArea.h"


drawArea::drawArea()
{
}


drawArea::~drawArea()
{
}


HRESULT drawArea::init()
{
	x = 0;
	y = 0;

	_camera.x = 0;
	_camera.y = 0;

	//setCamera();

	_cameraRc = RectMake(0,0, CAMERASIZEX, CAMERASIZEY);

	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			_tiles[i * TILEX + j].rc = RectMake(x + j * 50, y + i * 50, TILESIZE, TILESIZE);
		}
	}

	_scrollhorz = CreateWindow(TEXT("scrollbar"), NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ, 5, 700, 700, 20, _hWnd, HMENU(BTN_SCROLL_VERT),
		_hInstance, NULL);

	_scrollvert = CreateWindow(TEXT("scrollbar"), NULL, WS_CHILD | WS_VISIBLE | SBS_VERT, 800, 5, 20, 600, _hWnd, HMENU(BTN_SCROLL_HORI),
		_hInstance, NULL);
	SetScrollRange(_scrollvert, SB_CTL, 0, 255, false);
	SetScrollPos(_scrollvert, SB_CTL, 50, TRUE);

	return S_OK;
}

void drawArea::release()
{
}

void drawArea::update()	
{
	//setCamera();

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_camera.x -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_camera.x += 3;
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_camera.y -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_camera.y += 3;
	}


	//_cameraRc = RectMake(0, 0, CAMERASIZEX, CAMERASIZEY);

}

void drawArea::render()	
{
	RectangleMake(getToolMemDC(),_cameraRc.left , _cameraRc.top , CAMERASIZEX, CAMERASIZEY);

	//for (int i = 0; i < TILEX * TILEY; ++i)
	//{
	//	Rectangle(getToolMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].rc.right, _tiles[i].rc.bottom);
	//}
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			RectangleMake(getToolMemDC(), x + j * 50 - _camera.x ,y + i * 50 - _camera.y, TILESIZE, TILESIZE);
		}
	}
}

void drawArea::setCamera()
{
	int x, y;

	x = (_cameraRc.right + _cameraRc.left)/2;
	y = (_cameraRc.bottom + _cameraRc.top)/2;

	_camera.x = x;
	_camera.y = y;
}
