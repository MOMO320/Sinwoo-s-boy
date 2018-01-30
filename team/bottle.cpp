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
	_objectType = BOTTLE; //�����Ⱑ ������ ������Ʈ
	_objectEffect = 9999;
	_x = point.x, _y = point.y;

	_carryX = _x + 25;
	_carryY = _y + 25;
	_rcObject = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_carryX), CAMERAMANAGER->CameraRelativePointY(_carryY), 50, 50);
	_objectState = PUT;
	_frameX = _frameCount = 0;
	_throwDistance = 0;				//�������� ���� (ó���� 0 �ƴϰڽ��ϱ�??)
	_throwDirection = 0;
	_throwSpeed = 10;

	_isUp = false;
	_respon = false;
	_isFire = false;
	_isAttack = false;

	_player = player;
	_player->setupCollisionObject(&_rcObject, &_carryX, &_carryY, true, &_isFire, &_isAttack);

	return S_OK;
}

void bottle::render()
{	
	_objectImage->render(getMemDC(), _rcObject.left, _rcObject.top);
}

void bottle::update()
{

	_rcObject = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_carryX), CAMERAMANAGER->CameraRelativePointY(_carryY), 50, 50);


	if (_isFire)
	{
		move();
	}
	else 
	{
		switch (_player->getPLAYERMANET())
		{
		case DOWN_MOVE: case DOWN_STOP:
			_throwDirection = 0;
			break;
	
		case RIGHT_MOVE: case RIGHT_STOP:
			_throwDirection = 1;
			break;
	
		case UP_MOVE: case UP_STOP:
			_throwDirection = 2;
			break;
	
		case LEFT_MOVE: case LEFT_STOP:
			_throwDirection = 3;
			break;
	
		default:
			break;
		}
	}

}

void bottle::move()
{

	//if (_objectState == PUT) return;		(�ϴ� �̰� ���� ���� �ּ�ó���߽��ϴ�^^)

	if (_throwDistance >= 300) return;

	switch (_throwDirection)
	{
	case 0:
		_carryY += _throwSpeed;
		_throwDistance += _throwSpeed;
		if (_throwDistance >= 250) _carryY -= _throwSpeed/2;
		break;

	case 1:
		_carryX += _throwSpeed;
		_throwDistance += _throwSpeed;
		if (_throwDistance >= 250) _carryY += _throwSpeed / 2;
		break;

	case 2:
		_carryY -= _throwSpeed;
		_throwDistance += _throwSpeed;
		if (_throwDistance >= 250) _carryY += _throwSpeed / 2;
		break;

	case 3:
		_carryX -= _throwSpeed;
		_throwDistance += _throwSpeed;
		if (_throwDistance >= 250) _carryY += _throwSpeed / 2;
		break;

	default:
		break;
	}
}
