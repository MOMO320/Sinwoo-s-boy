#include "stdafx.h"
#include "boomerang.h"


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

	_isVisible = true;
	//_isVisible = false;
	_itemEffect = 1;
	_itemType = WEAPON;
	_itemState = IDLE;

	_mainPlayer = NULL;

	_frameCount = 0;
	return S_OK;
}

void boomerang::update()
{
	//���󰡴»����϶���
	if (_itemState == THROW)
	{
		_frameCount++;
		if (_frameCount >= 39) _frameCount = 0;
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