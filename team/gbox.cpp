#include "stdafx.h"
#include "gbox.h"


gbox::gbox()
{
}


gbox::~gbox()
{
}

HRESULT gbox::init(POINT point)
{
	_objectImage = IMAGEMANAGER->addImage("닫힌큰상자", "./image/object/great_golden_box.bmp", 100, 75, true, RGB(255, 0, 255));
	_rcObject = RectMake(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), 80, 60);
	_centerX = _rcObject.left + ((_rcObject.right - _rcObject.left) / 2);
	_centerY = _rcObject.top + ((_rcObject.bottom - _rcObject.top) / 2);
	_objectType = OB_BOX; //던지기가 가능한 오브젝트
	_objectEffect = 9999;
	_x = point.x, _y = point.y;

	_objectState = BOX_CLOSE;
	_frameX = _frameCount = 0;


	return S_OK;
}

void gbox::render()
{
	if (_objectState == BOX_CLOSE)
	{
		IMAGEMANAGER->findImage("닫힌큰상자")->render(getMemDC(), _x, _y);
	}

	if (_objectState == BOX_OPEN)
	{
		_objectImage = IMAGEMANAGER->addImage("열린큰상자", "./image/object/open_great_golden_box.bmp", 100, 75, true, RGB(255, 0, 255));
		IMAGEMANAGER->findImage("열린큰상자")->render(getMemDC(), _x, _y);
	}

	Rectangle(getMemDC(), _rcObject.left, _rcObject.top, _rcObject.right, _rcObject.bottom);

}

void gbox::open()
{

}

void gbox::update()
{
	//	_player->setupCollisionObject(&_rcObject, &CAMERAMANAGER->CameraRelativePointX(_x), &CAMERAMANAGER->CameraRelativePointY(_y), true);


	_rcObject = RectMake(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), 40, 40);
}