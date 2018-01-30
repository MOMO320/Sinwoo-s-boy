#include "stdafx.h"
#include "stone.h"


stone::stone()
{
}


stone::~stone()
{
}

HRESULT stone::init(POINT point, player* player)
{
	_objectImage = IMAGEMANAGER->addImage("도오올", "./image/object/stone.bmp", 50, 50, true, RGB(255, 0, 255));
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

	_throwDistance = 0; //거리 디폴트값
	_throwDirection = 0;
	_throwSpeed = 10;	//오브젝트의 스피드값

	_isUp = false;
	_respon = false;
	_isFire = false;
	_isAttack = false;

	_player = player;
	_player->setupCollisionObject(&_rcObject, &_carryX, &_carryY, true, &_isFire, &_isAttack);


	return S_OK;
}

void stone::render()
{
	if (_throwDistance >= 300)
	{
		_objectImage->frameRender(getMemDC(), _objectImage->getFrameWidth(), _objectImage->getFrameHeight());
	}
	else
	{
		_objectImage->render(getMemDC(), _rcObject.left, _rcObject.top);
	}
}

void stone::move()
{
	//if (_objectState == PUT) return;
	if (_throwDistance >= 300)
	{
		_objectImage = IMAGEMANAGER->addFrameImage("부셔짐", "./image/object/bottle_broken.bmp", 400, 50, 8, 1, true, RGB(255, 0, 255));
		return;
	}

	switch (_throwDirection)
	{
	case 0:		//아래방향
		_carryY += _throwSpeed;
		_throwDistance += _throwSpeed;
		if (_throwDistance >= 250) _carryY -= _throwSpeed / 2;
		break;

	case 1:		//오른쪽방향
		_carryX += _throwSpeed;
		_throwDistance += _throwSpeed;
		if (_throwDistance >= 250) _carryY += _throwSpeed / 2;
		break;

	case 2:		//위방향
		_carryY -= _throwSpeed;
		_throwDistance -= _throwSpeed;
		if (_throwDistance >= 250) _carryY += _throwSpeed / 2;
		break;

	case 3:		//왼쪽방향
		_carryX -= _throwSpeed;
		_throwDistance += _throwSpeed;
		if (_throwDistance >= 250) _carryY += _throwSpeed / 2;
		break;


	default:
		break;
	}
}

void stone::update()
{
	_rcObject = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_carryX), CAMERAMANAGER->CameraRelativePointY(_carryY), 50, 50);

	//	_player->setupCollisionObject(&_rcObject, &CAMERAMANAGER->CameraRelativePointX(_x), &CAMERAMANAGER->CameraRelativePointY(_y), true);
	//만약 던지면(쏘면)
	if (_isFire)
	{
		move();		//움직임 함수
	}

	//플레이어의 상태를 가져옵니다.
	else
	{
		switch (_player->getPLAYERMANET())
		{
		case DOWN_MOVE: case DOWN_STOP://플레이어가 아래로 움직였거나, 아래를 바라보며 멈출때
			_throwDirection = 0;	   //플레이어 상태는 아래를 보고있다.
			break;
	
		case RIGHT_MOVE: case RIGHT_STOP://플레이어가 오른쪽으로 움직였거나, 오른쪽을 바라보며 멈출때
			_throwDirection = 1;	     //플레이어 상태는 오른쪽를 보고있다.
			break;
	
		case UP_MOVE: case UP_STOP:		//플레이어가 위로 움직였거나, 위를 바라보며 멈출때
			_throwDirection = 2;	    //플레이어 상태는 위를 보고있다.
			break;
	
		case LEFT_MOVE: case LEFT_STOP://플레이어가 왼쪽로 움직였거나, 왼쪽를 바라보며 멈출때
			_throwDirection = 3;	   //플레이어 상태는 왼쪽를 보고있다.
			break;
	
		default:
			break;
		}
	}
}