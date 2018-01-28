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
	_throwDistance = 0;				//�������� ���� (ó���� 0 �ƴϰڽ��ϱ�??)
	_throwSpeed = 10;

	_isUp = false;
	_respon = false;
	_isFire = false;
	
	_player = player;
	_player->setupCollisionObject(&_rcObject, &_carryX, &_carryY, true, &_isFire);

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

	//if (_objectState == PUT) return;		(�ϴ� �̰� ���� ���� �ּ�ó���߽��ϴ�^^)

	if (_throwDistance >= 300) return;

	switch (_player->getPLAYERMANET())
	{
	case DOWN_MOVE: case DOWN_STOP:
		_carryY += _throwSpeed;
		_throwDistance += _throwSpeed;
		if (_throwDistance >= 250) _carryY -= _throwSpeed/2;
		break;

	case RIGHT_MOVE: case RIGHT_STOP:
		_carryX += _throwSpeed;
		_throwDistance += _throwSpeed;
		if (_throwDistance >= 250) _carryY += _throwSpeed / 2;
		break;

	case UP_MOVE: case UP_STOP:
		_carryY -= _throwSpeed;
		_throwDistance += _throwSpeed;
		if (_throwDistance >= 250) _carryY += _throwSpeed / 2;
		break;

	case LEFT_MOVE: case LEFT_STOP:
		_carryX -= _throwSpeed;
		_throwDistance += _throwSpeed;
		if (_throwDistance >= 250) _carryY += _throwSpeed / 2;
		break;

	default:
		break;
	}
}
