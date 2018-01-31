#include "stdafx.h"
#include "aStarTile.h"


aStarTile::aStarTile()
	: _totalCost(0), _costFromStart(0),
	_costToGoal(0), _parentNode(NULL), _idX(0), _idY(0), _isOpen(true)
{
}


aStarTile::~aStarTile()
{

}

HRESULT aStarTile::init(int idX, int idY)
{/*
	_color = RGB(250, 150, 0);
	_brush = Brush(_color);
	_pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
*/
	_center = PointMake(idX * ASTARWIDTH + (ASTARWIDTH / 2),
		idY * ASTARHEIGHT + (ASTARHEIGHT / 2));

	_idX = idX;
	_idY = idY;

	_rc = RectMakeCenter(_center.x, _center.y, ASTARWIDTH, ASTARHEIGHT);

	return S_OK;
}
void aStarTile::release()
{
	DeleteObject(_brush);
	DeleteObject(_pen);
}
void aStarTile::update()
{

}
void aStarTile::render()
{
	/*SelectObject(getMemDC(), (HBRUSH)_brush);
	FillRect(getMemDC(), &_rc, _brush);

	SelectObject(getMemDC(), (HPEN)_pen);
	RectangleMake(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);*/
}