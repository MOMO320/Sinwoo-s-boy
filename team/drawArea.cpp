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

	_cameraRc = RectMake(0,0, 800, 800);

	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			_tiles[i * TILEX + j].rc = RectMake(x + j * TILESIZE, y + i * TILESIZE, TILESIZE, TILESIZE);
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




}

void drawArea::render()	
{
	
	PatBlt(getAreaDC(), 0, 0, 800, 800, WHITENESS);
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			RectangleMake(getAreaDC(), x + j * TILESIZE - _camera.x,y + i * TILESIZE- _camera.y, TILESIZE, TILESIZE);

			//RectangleMake(getAreaDC(), x + j * TILESIZE, y + i * TILESIZE, TILESIZE, TILESIZE);
		}
	}
	char str[200];
	
	sprintf(str, "cameraX : %d, cameraY : %d", _camera.x, _camera.y, str, strlen(str));
	TextOut(getAreaDC(), 100, 100, str, strlen(str));
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		sprintf(str, "left : %d,top :%d", _tiles[i].rc.left, _tiles[i].rc.top);
		TextOut(getAreaDC(), _tiles[i].rc.left - _camera.x,_tiles[i].rc.top - _camera.y, str, strlen(str));
		sprintf(str, "left : %d,top :%d", _tiles[i].rc.left - _camera.x, _tiles[i].rc.top - _camera.y);
		TextOut(getAreaDC(), _tiles[i].rc.left - _camera.x, _tiles[i].rc.top - _camera.y+20, str, strlen(str));
	}
	HBRUSH hbrush, holdbrush;
	hbrush = (HBRUSH)GetStockObject(NULL_BRUSH); 
	holdbrush = (HBRUSH)SelectObject(getAreaDC(), hbrush);
	RectangleMake(getAreaDC(), _cameraRc.left, _cameraRc.top, 800, 800);
	DeleteObject(hbrush);
	
	getArea()->render(getToolMemDC(), 0, 0);
	
}

void drawArea::setCamera()
{
	int x, y;

	x = (_cameraRc.right + _cameraRc.left)/2;
	y = (_cameraRc.bottom + _cameraRc.top)/2;

	_camera.x = x;
	_camera.y = y;
}
