#include "stdafx.h"
#include "boomerang.h"
#include "player.h"

boomerang::boomerang()
{
}


boomerang::~boomerang()
{
}

HRESULT boomerang::init(){	
	/*
	image*	_itemImage;	//������ �κ��丮 �̹���
	float _x, _y;		//�̹����� ����

	bool _isVisible;	//�κ��丮���� �̹����� �׸�������
	int _itemEffect;	//������ ȿ��(���� : ��ȸ��, ���� : ������ ���)

	tagItemType _itemType;		//������ ����
	tagItemState _itemState;	//������ ����
	*/

	//������ �̹���
	_itemImage = IMAGEMANAGER->addFrameImage("boomerangthrow", "./image/item/�θ޶�(������).bmp", 160, 40,4,1, true, RGB(255, 0, 255));
		_itemInvenImage = IMAGEMANAGER->addImage("boomerang", "./image/item/�θ޶�(�κ�,����).bmp",100,100, true, RGB(255, 0, 255));
	_itemRightTopImage = IMAGEMANAGER->addImage("boomerangRightTop", "./image/item/�θ޶�(�������).bmp", 455, 157, true, RGB(255, 0, 255));

	//_isVisible = true;
	_isVisible = false;
	_itemEffect = 1;
	_itemType = WEAPON;
	_itemState = IDLE;

	_mainPlayer = NULL;

	_frameCount = 0;

	_isBack = false;
	return S_OK;
}

void boomerang::update()
{
	float angle;
	//���󰡴»����϶���
	if (_itemState == THROW)
	{
		_frameCount++;
		if (_frameCount >= 39) _frameCount = 0;

		//����
		if (!_isBack && 
			getDistance(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y),
			_mainPlayer->getPlayerRC().left, _mainPlayer->getPlayerRC().top) <=250)
		{
			switch (_direction)
			{
				//�� �����ؼ� �ð�������� 8����
			case 0:
				//180
				angle = PI;
				break;
			case 1:
				angle = (PI / 4) * 3;
				break;
			case 2:
				angle = PI / 2;
				break;
			case 3:
				angle = PI / 4;
				break;
			case 4:
				angle = 0;
				break;
			case 5:
				angle = (PI / 4) * 7;
				break;
			case 6:
				angle = (PI / 2) * 3;
				break;
			case 7:
				angle = (PI / 4) * 5;
				break;
			default:
				break;
			}
		}
		//���ƿ�
		else
		{
			_isBack = true;
			angle = getAngle(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), _mainPlayer->getPlayerRC().left, _mainPlayer->getPlayerRC().top);
			
		}

		RECT temp;
		//���ƿ������϶� �÷��̾� ��Ʈ�� �浹�̳�
		if (_isBack &&
			IntersectRect(&temp, &_mainPlayer->getPlayerRC(),
			&RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), 40, 40)))
		{
			_isBack = false;
			_itemState = IDLE;
			//_angle = 0;
		}
		_x += cosf(angle) * 6;
		_y += -sinf(angle) * 6;

		
	}
}


void boomerang::render()
{
	if (_itemState == THROW)
		_itemImage->frameRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), _frameCount / 10,0 );
	//itemParent::render();
	//TextOut(getMemDC(), 300, 300, "test1", strlen("test"));
	//_itemImage->frameRender(getMemDC(), 250, 30);
}

void boomerang::fire(float x, float y, int direction){

	//���󰡰� �ִ°�� ����
	if (_itemState == THROW) return;

	_itemState = THROW;
	_x = x;
	_y = y;
	_direction = direction;
}