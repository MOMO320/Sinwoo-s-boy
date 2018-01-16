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

	return S_OK;
}

void drawArea::release()
{
}

void drawArea::update()	
{
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			_tiles[i * TILEX + j].rc = RectMake(x + j * 50,y + i * 50, TILESIZE, TILESIZE);
		}
	}

	_scrollhorz = CreateWindow(TEXT("scrollbar"), NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ, 5, 700, 700, 20, _hWnd, HMENU(BTN_SCROLL_VERT),
		_hInstance, NULL);

	_scrollvert = CreateWindow(TEXT("scrollbar"), NULL, WS_CHILD | WS_VISIBLE | SBS_VERT, 800, 5, 20, 600, _hWnd, HMENU(BTN_SCROLL_VERT),
		_hInstance, NULL);

	
}

void drawArea::render()	
{
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		Rectangle(getToolMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].rc.right, _tiles[i].rc.bottom);
	}
}
