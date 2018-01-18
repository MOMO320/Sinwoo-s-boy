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
	
	
	_scrollhorz = CreateWindow(TEXT("scrollbar"), NULL, WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_CHILD | WS_VISIBLE | SBS_HORZ, areaStartX+5, areaStartY+700, 800, 20, _hWnd, HMENU(BTN_SCROLL_VERT),
		_hInstance, NULL);

	_scrollvert = CreateWindow(TEXT("scrollbar"), NULL, WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_CHILD | WS_VISIBLE | SBS_VERT, areaStartX+ 800, areaStartY+ 5, 20, 700, _hWnd, HMENU(BTN_SCROLL_HORI),
		_hInstance, NULL);
	SetScrollRange(_scrollvert, SB_CTL, 0, 1000,false);
	

	SetScrollRange(_scrollhorz, SB_CTL, 0, 1000, false);


	for (int i = 0; i <TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			tile* temp;
			temp = new tile;
			temp->init(j,i);

			_vCurrentTile.push_back(temp);
		}
	}

	return S_OK;
}

void drawArea::release()
{
}

void drawArea::update()	
{



<<<<<<< HEAD
	_tileX = (_ptMouse.x + horzScrollMove - areaStartX)  / TILESIZE;
	_tileY = (_ptMouse.y + vertScrollMove - areaStartY) / TILESIZE;
=======
	_tileX = (_ptMouse.x + horzScrollMove )  / TILESIZE;
	_tileY = (_ptMouse.y + vertScrollMove ) / TILESIZE;
>>>>>>> 1a1d47c71d6b64f5fb83133e55d171978f8479ac
	_position = _tileX + _tileY * TILEX;

}

void drawArea::keyDownUpdate(int key)
{
	switch(key)
	{
	case VK_LBUTTON:
		if ((_tileX >= 0 && _tileX < TILEX) && (_tileY >= 0 && _tileY < TILEY) && _SelectedTile != NULL)
		{
			if (_SelectedTile->getSelectedTile() != NULL)
			{
<<<<<<< HEAD
				switch (_SelectedTile->getSelectedTile()->tileClass)
				{
				case TILE_TERRAIN:
					_vCurrentTile[_tileX + _tileY*TILEX]->setTerrain(*_SelectedTile->getSelectedTile()->trInfo);
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
=======
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
>>>>>>> 1a1d47c71d6b64f5fb83133e55d171978f8479ac
			}
		}
	break;
	}
}


void drawArea::render()	
{
	//drawArea 한번 초기화
	PatBlt(getAreaDC(), 0, 0, areaSizeX, areaSizeY, WHITENESS);
	//==========================================================================================================

	//drawArea 테두리
	HBRUSH hbrush, holdbrush;
	hbrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	holdbrush = (HBRUSH)SelectObject(getAreaDC(), hbrush);
	RectangleMake(getAreaDC(), 0,0, 800, 700);
	for (int i = 0; i < _vCurrentTile.size(); ++i)
	{
		_vCurrentTile[i]->Toolrender(getAreaDC(), horzScrollMove, vertScrollMove);
	}
<<<<<<< HEAD
	DeleteObject(hbrush);
=======

	//===========================================
	getArea()->render(getToolMemDC(), 0, 0);
>>>>>>> 1a1d47c71d6b64f5fb83133e55d171978f8479ac
	
	//타일 랜더
	




	//속성
	char str[200];
	sprintf(str, "_tileX : %d, _tileY : %d, _position : %d", _tileX, _tileY, _position, str, strlen(str));
	TextOut(getToolMemDC(), 1050,630,str,strlen(str));
	sprintf(str, "_ptMouse.x : %d, _ptMouse.y : %d", _ptMouse.x, _ptMouse.y, str, strlen(str));
	TextOut(getToolMemDC(), 1050, 660, str, strlen(str));
	sprintf(str, "asd : %d", vertScrollMove, str, strlen(str));
	TextOut(getToolMemDC(), 1050, 690, str, strlen(str));

	//=======================================================================================
	//drawArea 최종 출력
	getArea()->render(getToolMemDC(), areaStartX, areaStartY);
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
		//InvalidateRect(hWnd, NULL, FALSE);
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
		//InvalidateRect(hWnd, NULL, FALSE);
		break;
	}
	return (DefWindowProc(hWnd, imessage, wParam, lParam));
}

