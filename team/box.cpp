#include "stdafx.h"
#include "box.h"


box::box()
{

}


box::~box()
{
}

HRESULT box::init(POINT point, player* player)
{
	_objectImage = IMAGEMANAGER->addImage("닫힌상자", "./image/object/golden_box.bmp", 50, 50, true, RGB(255, 0, 255));
	_rcObject = RectMake(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), 40, 40);
	_centerX = _rcObject.left + ((_rcObject.right - _rcObject.left) / 2);
	_centerY = _rcObject.top + ((_rcObject.bottom - _rcObject.top) / 2);
	_objectType = OB_BOX; //던지기가 가능한 오브젝트
	_objectEffect = 9999;
	_x = point.x, _y = point.y;

	_objectState = BOX_CLOSE;
	_frameX = _frameCount = 0;


	return S_OK;
}

void box::render()
{
	if (_objectState == BOX_CLOSE)
	{
		_objectImage->render(getMemDC(), _rcObject.left, _rcObject.top);
	}

	if (_objectState == BOX_OPEN)
	{
		_objectImage = IMAGEMANAGER->addImage("열린상자", "./image/object/open_golden_box.bmp", 50, 50, true, RGB(255, 0, 255));
		_objectImage->render(getMemDC(), _rcObject.left, _rcObject.top);
	}

	Rectangle(getMemDC(), _rcObject.left, _rcObject.top, _rcObject.right, _rcObject.bottom);

}

void box::open()
{

}

void box::update()
{
	//	_player->setupCollisionObject(&_rcObject, &CAMERAMANAGER->CameraRelativePointX(_x), &CAMERAMANAGER->CameraRelativePointY(_y), true);


	_rcObject = RectMake(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), 40, 40);
}