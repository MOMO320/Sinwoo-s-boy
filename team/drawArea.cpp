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

	

	_scrollhorz = CreateWindow(TEXT("scrollbar"), NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ, 5, 700, 800, 20, _hWnd, HMENU(BTN_SCROLL_VERT),
		_hInstance, NULL);

	_scrollvert = CreateWindow(TEXT("scrollbar"), NULL, WS_CHILD | WS_VISIBLE | SBS_VERT, 800, 5, 20, 700, _hWnd, HMENU(BTN_SCROLL_HORI),
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
	SetScrollRange(_scrollvert, SB_CTL, 0, 255, true);
	SetScrollPos(_scrollvert, SB_CTL, 255, true);

	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			_tiles[i * TILEX + j].rc = RectMake(x + j * TILESIZE, y+ i * TILESIZE, TILESIZE, TILESIZE);
		}
	}
	//setCamera();

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_camera.x -= 2;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_camera.x += 2;
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_camera.y -= 2;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_camera.y += 2;
	}


	_tileX = (_ptMouse.x + _camera.x + x + _camera.x)  / TILESIZE;
	_tileY = (_ptMouse.y + _camera.y + y + _camera.y) / TILESIZE;

	_position = _tileX + _tileY * TILEX;

}

void drawArea::render()	
{
	
	PatBlt(getAreaDC(), 0, 0, 800, 800, WHITENESS);
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			if (PtInRect(&_tiles[i * TILEX + j].rc, { _ptMouse.x + _camera.x - x + _camera.x , _ptMouse.y + _camera.y -y + _camera.y }))
			{
				HBRUSH hBrush, oldBrush;
				hBrush = CreateSolidBrush(RGB(0, 200, 255));
				oldBrush = (HBRUSH)SelectObject(getAreaDC(), hBrush);
				
				RectangleMake(getAreaDC(), x - _camera.x + j * TILESIZE - _camera.x, y - _camera.y + i * TILESIZE - _camera.y, TILESIZE, TILESIZE);
				SelectObject(getAreaDC(), oldBrush);
				DeleteObject(hBrush);
			}

			else RectangleMake(getAreaDC(), x - _camera.x + j * TILESIZE - _camera.x, y - _camera.y + i * TILESIZE - _camera.y, TILESIZE, TILESIZE);

			//RectangleMake(getAreaDC(), x + j * TILESIZE, y + i * TILESIZE, TILESIZE, TILESIZE);
		}
	}
	char str[200];
	
	sprintf(str, "cameraX : %d, cameraY : %d", _camera.x, _camera.y, str, strlen(str));
	TextOut(getAreaDC(), 100, 100, str, strlen(str));
	sprintf(str, "_tileX : %d, _tileY : %d, _position : %d", _tileX, _tileY, _position, str, strlen(str));
	TextOut(getAreaDC(),100,200,str,strlen(str));

	sprintf(str, "_ptMouse.x : %d, _ptMouse.y : %d", _ptMouse.x, _ptMouse.y, str, strlen(str));
	TextOut(getAreaDC(), 100, 250, str, strlen(str));
	//for (int i = 0; i < TILEX * TILEY; ++i)
	//{
	//	//sprintf(str, "left : %d,top :%d", _tiles[i].rc.left, _tiles[i].rc.top);
	//	//TextOut(getAreaDC(), _tiles[i].rc.left - _camera.x,_tiles[i].rc.top - _camera.y, str, strlen(str));
	//	sprintf(str, "left : %d,top :%d", _tiles[i].rc.left - _camera.x, _tiles[i].rc.top - _camera.y);
	//	TextOut(getAreaDC(), _tiles[i].rc.left - _camera.x - x - _camera.x, _tiles[i].rc.top - _camera.y - y - _camera.y, str, strlen(str));
	//}
	HBRUSH hbrush, holdbrush;
	hbrush = (HBRUSH)GetStockObject(NULL_BRUSH); 
	holdbrush = (HBRUSH)SelectObject(getAreaDC(), hbrush);
	RectangleMake(getAreaDC(), _cameraRc.left, _cameraRc.top, 800, 700);
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
