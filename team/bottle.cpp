#include "stdafx.h"
#include "bottle.h"


bottle::bottle()
{

}


bottle::~bottle()
{
}

HRESULT bottle::init(POINT point,  player* player)
{
	_objectImage = IMAGEMANAGER->addImage("�׾Ƹ�", "./image/object/bottle.bmp", 50, 50, true, RGB(255, 0, 255));
	//_centerX = _rcObject.left + ((_rcObject.right - _rcObject.left) / 2);
	//_centerY = _rcObject.top + ((_rcObject.bottom - _rcObject.top) / 2);
	_objectType = OB_THROW; //�����Ⱑ ������ ������Ʈ
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
	
	player->setupCollisionObject(&_rcObject, &_carryX, &_carryY, true);

	return S_OK;
}

void bottle::render()
{
	if (_objectState == PUT)
	{
		_objectImage->render(getMemDC(), _rcObject.left, _rcObject.top);
	}
	//������
	//_objectImage = IMAGEMANAGER->addFrameImage("�μ���", "./image/object/bottle_broken.bmp", 400, 50,1,8, true, RGB(255, 0, 255));

	Rectangle(getMemDC(), _rcObject.left, _rcObject.top, _rcObject.right, _rcObject.bottom);
}

void bottle::update()
{
	_rcObject = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_carryX), CAMERAMANAGER->CameraRelativePointY(_carryY), 50, 50);
	if (_isFire) 
	{
		move();
	}

}

void bottle::move()
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
