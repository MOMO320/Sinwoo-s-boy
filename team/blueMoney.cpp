#include "stdafx.h"
#include "blueMoney.h"


blueMoney::blueMoney()
{
}


blueMoney::~blueMoney()
{

}

HRESULT blueMoney::init(int x, int y)
{
	/*
	image*	_itemImage;			//������ ��ô �̹���(�θ޶� �� �������� �ִ� �̹���)
	image*  _itemInvenImage;	//������ �κ��丮 �̹���(����)
	image*  _itemRightTopImage;	//������ �κ��丮 ���� �̹���(����)

	float _x, _y;		//�̹����� ����

	bool _isVisible;	//�κ��丮���� �̹����� �׸�������
	int _itemEffect;	//������ ȿ��(���� : ��ȸ��, ���� : ������ ���)

	//�����Ǹ� ����
	int _price;

	tagItemType _itemType;		//������ ����
	tagItemState _itemState;	//������ ����

	player* _mainPlayer;

	bool test1;
	char test2[120];
	
	*/
	_itemImage = _itemInvenImage = _itemRightTopImage
		= IMAGEMANAGER->addImage("bluemoney", "./image/item/bluemoney.bmp", 23, 46, true, RGB(255, 0, 255));

	_x = x; _y = y;

	//1�� ����
	_itemEffect = 1;

	_itemType = MONEY;
	_itemState = IDLE;

	return S_OK;
}

void blueMoney::render()
{
	_itemImage->render(getMemDC(),_x,_y);
}
