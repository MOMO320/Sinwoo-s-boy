#include "stdafx.h"
#include "gbox.h"


gbox::gbox()
{
}


gbox::~gbox()
{
}

HRESULT gbox::init(POINT point, player* player)
{
	_objectImage = IMAGEMANAGER->addImage("닫힌큰상자", "./image/object/great_golden_box.bmp", 100, 75, true, RGB(255, 0, 255));
	_rcObject = RectMake(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), 80, 60);
	//_centerX = _rcObject.left + ((_rcObject.right - _rcObject.left) / 2);
	//_centerY = _rcObject.top + ((_rcObject.bottom - _rcObject.top) / 2);
	_objectType = OB_BOX; //던지기가 가능한 오브젝트
	_objectEffect = 9999;
	_x = point.x, _y = point.y;

	_carryX = _x + 25;
	_carryY = _y + 25;

	_objectState = BOX_CLOSE;
	_frameX = _frameCount = 0;

	_isUp = false;
	_isAttack = false;
	_isOpen = false;

	_player = player;
	_player->setupCollisionObject(&_rcObject, &_carryX, &_carryY, false, &_isFire, &_isAttack);

	return S_OK;
}

void gbox::render()
{
	if (_objectState == BOX_CLOSE)
	{
		_objectImage->render(getMemDC(), _rcObject.left, _rcObject.top);
	}

	else if (_objectState == BOX_OPEN)
	{
		_objectImage = IMAGEMANAGER->addImage("열린큰상자", "./image/object/open_great_golden_box.bmp", 100, 75, true, RGB(255, 0, 255));
		_objectImage->render(getMemDC(), _rcObject.left, _rcObject.top);
	}
}

void gbox::open()
{

}

void gbox::update()
{
	//	_player->setupCollisionObject(&_rcObject, &CAMERAMANAGER->CameraRelativePointX(_x), &CAMERAMANAGER->CameraRelativePointY(_y), true);


	_rcObject = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_carryX), CAMERAMANAGER->CameraRelativePointY(_carryY), 80, 60);
}