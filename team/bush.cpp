#include "stdafx.h"
#include "bush.h"


bush::bush()
{
}


bush::~bush()
{
}

HRESULT bush::init(POINT point, player* player)
{
	_objectImage = IMAGEMANAGER->addImage("수풀", "./image/object/bush.bmp", 50, 50, true, RGB(255, 0, 255));
	//_centerX = _rcObject.left + ((_rcObject.right - _rcObject.left) / 2);
	//_centerY = _rcObject.top + ((_rcObject.bottom - _rcObject.top) / 2);
	_objectType = OB_THROW; //던지기가 가능한 오브젝트
	_objectEffect = 9999;
	_x = point.x, _y = point.y;

	_carryX = _x + 25;
	_carryY = _y + 25;
	_rcObject = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_carryX), CAMERAMANAGER->CameraRelativePointY(_carryY), 50, 50);
	_objectState = PUT;
	_frameX = _frameCount = 0;

	_isUp = false;
	_respon = false;
	_isFire = false;

	player->setupCollisionObject(&_rcObject, &_carryX, &_carryY, true,&_isFire);

	return S_OK;
}

void bush::render()
{
	if (_objectState == PUT)
	{
		_objectImage->render(getMemDC(), _rcObject.left, _rcObject.top);
	}
	//_objectImage = IMAGEMANAGER->addFrameImage("벌목", "./image/object/bulmok.bmp", 400, 50, 1, 8, true, RGB(255, 0, 255));


	Rectangle(getMemDC(), _rcObject.left, _rcObject.top, _rcObject.right, _rcObject.bottom);

}

void bush::move()
{

	if (_objectState == PUT) return;
	

	switch (_objectUDLR)
	{
	case OB_UP:
		_y -= 5;

		break;
	case OB_DOWN:
		_y += 5;
		break;
	case OB_LEFT:
		_x -= 5;

		break;
	case OB_RIGHT:
		_x += 5;

		break;


	default:
		break;
	}
}

void bush::update()
{
	//	_player->setupCollisionObject(&_rcObject, &CAMERAMANAGER->CameraRelativePointX(_x), &CAMERAMANAGER->CameraRelativePointY(_y), true);
	if (_isFire)
	{
		move();
	}

	_rcObject = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_carryX), CAMERAMANAGER->CameraRelativePointY(_carryY), 50, 50);
}