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
	_objectImage = IMAGEMANAGER->addImage("������", "./image/object/stone.bmp", 50, 50, true, RGB(255, 0, 255));
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

	_throwDistance = 0; //�Ÿ� ����Ʈ��
	_throwDirection = 0;
	_throwSpeed = 10;	//������Ʈ�� ���ǵ尪

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
		_objectImage = IMAGEMANAGER->addFrameImage("�μ���", "./image/object/bottle_broken.bmp", 400, 50, 8, 1, true, RGB(255, 0, 255));
		return;
	}

	switch (_throwDirection)
	{
	case 0:		//�Ʒ�����
		_carryY += _throwSpeed;
		_throwDistance += _throwSpeed;
		if (_throwDistance >= 250) _carryY -= _throwSpeed / 2;
		break;

	case 1:		//�����ʹ���
		_carryX += _throwSpeed;
		_throwDistance += _throwSpeed;
		if (_throwDistance >= 250) _carryY += _throwSpeed / 2;
		break;

	case 2:		//������
		_carryY -= _throwSpeed;
		_throwDistance -= _throwSpeed;
		if (_throwDistance >= 250) _carryY += _throwSpeed / 2;
		break;

	case 3:		//���ʹ���
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
	//���� ������(���)
	if (_isFire)
	{
		move();		//������ �Լ�
	}

	//�÷��̾��� ���¸� �����ɴϴ�.
	else
	{
		switch (_player->getPLAYERMANET())
		{
		case DOWN_MOVE: case DOWN_STOP://�÷��̾ �Ʒ��� �������ų�, �Ʒ��� �ٶ󺸸� ���⶧
			_throwDirection = 0;	   //�÷��̾� ���´� �Ʒ��� �����ִ�.
			break;
	
		case RIGHT_MOVE: case RIGHT_STOP://�÷��̾ ���������� �������ų�, �������� �ٶ󺸸� ���⶧
			_throwDirection = 1;	     //�÷��̾� ���´� �����ʸ� �����ִ�.
			break;
	
		case UP_MOVE: case UP_STOP:		//�÷��̾ ���� �������ų�, ���� �ٶ󺸸� ���⶧
			_throwDirection = 2;	    //�÷��̾� ���´� ���� �����ִ�.
			break;
	
		case LEFT_MOVE: case LEFT_STOP://�÷��̾ ���ʷ� �������ų�, ���ʸ� �ٶ󺸸� ���⶧
			_throwDirection = 3;	   //�÷��̾� ���´� ���ʸ� �����ִ�.
			break;
	
		default:
			break;
		}
	}
}