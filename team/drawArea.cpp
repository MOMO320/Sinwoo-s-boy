#include "stdafx.h"
#include "drawArea.h"
#include "SelectTile.h"

drawArea::drawArea()
{
}


drawArea::~drawArea()
{
}


HRESULT drawArea::init()
{
	_SelectedTile = NULL;
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
	SetScrollRange(_scrollvert, SB_CTL, 0, 1000,false);
	//SetScrollPos(_scrollvert, SB_CTL, 150, TRUE);

	SetScrollRange(_scrollhorz, SB_CTL, 0, 1000, false);
	//SetScrollPos(_scrollhorz, SB_CTL, 0, TRUE);


	for (int i = 0; i <TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			tile* temp;
			temp = new tile;
			temp->init(j,i);

			_vtile.push_back(temp);
		}
	}

	return S_OK;
}

void drawArea::release()
{
}

void drawArea::update()	
{
	//SetScrollRange(_scrollvert, SB_CTL, 0, 255, true);
	//SetScrollPos(_scrollvert, SB_CTL, 255, true);



	_tileX = (_ptMouse.x + horzScrollMove )  / TILESIZE;
	_tileY = (_ptMouse.y + vertScrollMove ) / TILESIZE;
	_position = _tileX + _tileY * TILEX;

}

void drawArea::keyDownUpdate(int key)
{
	switch(key)
	{
	case VK_LBUTTON:
		if ((_tileX >= 0 && _tileX < TILEX) && (_tileY >= 0 && _tileY < TILEY) && _SelectedTile != NULL)
		{
			switch (_SelectedTile->getSelectedTile()->tileClass)
			{
			case TILE_TERRAIN:
				_vtile[_tileX + _tileY * TILEX]->setTerrain(*_SelectedTile->getSelectedTile()->trInfo);
				break;
			case TILE_OBJECT:
				break;
			case TILE_EVENT:
				break;
			case TILE_CHARACTER:
				break;
			case TILE_END:
				break;
			}
		}
	break;
	}
}


void drawArea::render()	
{
	
	PatBlt(getAreaDC(), 0, 0, 800, 800, WHITENESS);
	//for (int i = 0; i < TILEY; ++i)
	//{
	//	for (int j = 0; j < TILEX; ++j)
	//	{
	//		if (PtInRect(&_tiles[i * TILEX + j].rc, { _ptMouse.x + horzScrollMove - x + horzScrollMove , _ptMouse.y + vertScrollMove - y + vertScrollMove }))
	//		{
	//			HBRUSH hBrush, oldBrush;
	//			hBrush = CreateSolidBrush(RGB(0, 200, 255));
	//			oldBrush = (HBRUSH)SelectObject(getAreaDC(), hBrush);
	//			
	//			RectangleMake(getAreaDC(), x - horzScrollMove + j * TILESIZE - horzScrollMove, y - vertScrollMove + i * TILESIZE - vertScrollMove, TILESIZE, TILESIZE);
	//			SelectObject(getAreaDC(), oldBrush);
	//			DeleteObject(hBrush);
	//		}
	//
	//		else RectangleMake(getAreaDC(), x - horzScrollMove + j * TILESIZE - horzScrollMove, y - vertScrollMove + i * TILESIZE - vertScrollMove, TILESIZE, TILESIZE);
	//
	//		//RectangleMake(getAreaDC(), x + j * TILESIZE, y + i * TILESIZE, TILESIZE, TILESIZE);
	//	}
	//}
	char str[200];
	
	sprintf(str, "cameraX : %d, cameraY : %d", _camera.x, _camera.y, str, strlen(str));
	TextOut(getAreaDC(), 100, 100, str, strlen(str));
	sprintf(str, "_tileX : %d, _tileY : %d, _position : %d", _tileX, _tileY, _position, str, strlen(str));
	TextOut(getAreaDC(),100,200,str,strlen(str));

	sprintf(str, "_ptMouse.x : %d, _ptMouse.y : %d", _ptMouse.x, _ptMouse.y, str, strlen(str));
	TextOut(getAreaDC(), 100, 250, str, strlen(str));


	sprintf(str, "asd : %d", vertScrollMove, str, strlen(str));
	TextOut(getAreaDC(), 100, 300, str, strlen(str));

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
	for (int i = 0; i < _vtile.size(); ++i)
	{
		_vtile[i]->Toolrender(getAreaDC(), horzScrollMove,vertScrollMove);
	}

	//===========================================
	getArea()->render(getToolMemDC(), 0, 0);
	
	
}


LRESULT drawArea::getScrollhWnd(HWND hWnd, UINT imessage, WPARAM wParam, LPARAM lParam)
{
	switch (imessage)
	{
	case WM_VSCROLL:  // 스크롤바 처리
			switch (LOWORD(wParam))
			{
				//vertScrollMove = HIWORD(wParam);
			case SB_LINEUP: //화살표를 누를대 한단위 스크롤
				vertScrollMove = max(0, vertScrollMove - 10);
				break;
			case SB_LINEDOWN:
				vertScrollMove = min(1000, vertScrollMove + 10);
				break;
			case SB_PAGEUP: //스크롤바의 왼쪽을 누를때, 한 페이지를 스크롤
				vertScrollMove = max(0, vertScrollMove - 20);
				break;
			case SB_PAGEDOWN:
				vertScrollMove = min(1000, vertScrollMove + 20);
				break;
			case SB_THUMBTRACK: //스크롤바를 드래그중일때 (마우스 버튼을 놓을 때 까지 )
				vertScrollMove = HIWORD(wParam);
				break;
			}
		SetScrollPos(_scrollvert, SB_CTL, vertScrollMove, true);
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case WM_HSCROLL:
		switch (LOWORD(wParam))
		{
			horzScrollMove = HIWORD(wParam);
		case SB_LINELEFT: //화살표를 누를대 한단위 스크롤
			horzScrollMove = max(0, horzScrollMove - 5);
			break;
		case SB_LINERIGHT:
			horzScrollMove = min(1000, horzScrollMove + 5);
			break;
		case SB_PAGELEFT: //스크롤바의 왼쪽을 누를때, 한 페이지를 스크롤
			horzScrollMove = max(0, horzScrollMove - 10);
			break;
		case SB_PAGERIGHT:
			horzScrollMove = min(1000, horzScrollMove, +10);
			break;
		case SB_THUMBTRACK: //스크롤바를 드래그중일때 (마우스 버튼을 놓을 때 까지 )
			horzScrollMove = HIWORD(wParam);
			break;
		}
		SetScrollPos(_scrollhorz, SB_CTL, horzScrollMove, true);
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	}
	return (DefWindowProc(hWnd, imessage, wParam, lParam));
}

void drawArea::setCamera()
{
	int x, y;

	x = (_cameraRc.right + _cameraRc.left)/2;
	y = (_cameraRc.bottom + _cameraRc.top)/2;

	_camera.x = x;
	_camera.y = y;
}
