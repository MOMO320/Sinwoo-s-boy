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
	_itemInvenImage = IMAGEMANAGER->addImage("boomerang", "./image/item/�θ޶�(�κ�,����).bmp",100,100, true, RGB(255, 0, 255));


	_isVisible = true;
	//_isVisible = false;
	_itemEffect = 1;
	_itemType = WEAPON;
	_itemState = IDLE;

	return S_OK;
}

void boomerang::render()
{
	//_itemImage->frameRender(getMemDC(), 250, 30);
}