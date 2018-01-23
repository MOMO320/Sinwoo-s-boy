#pragma once
#include "gameNode.h"

class player;
class potion;

//������ ����
enum tagItemType{
	POTION,		//����
	MONEY,		//��
	WEAPON,		//����
	SHIELD		//����
};

//������ ����
enum tagItemState{
	IDLE,	//�⺻
	THROW	//������(Ȱor�θ޶�)
};

class itemParent :
	public gameNode
{

protected:
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
public:
	
	virtual HRESULT init();
	
	virtual HRESULT init(int x, int y); //�����ǸŸ� ���� init �����ε�
	virtual void release();
	virtual void update();
	virtual void render();

	//virtual void isGain();
	//������ ��ǥ ����
	void setX(float x){ _x = x; }	
	void setY(float y){ _y = y; }

	//������ ���
	void useItem();

	//������ ��Ʈ(������ǥ) ������ (�������� 40,40ũ���� ��Ʈ)
	RECT getRC(){ return RectMakeCenter(_x + _itemInvenImage->getWidth() / 2, _y + _itemInvenImage->getHeight() / 2, 40, 40); }
	//������ ��Ʈ(ī�޶� ��ǥ) ������ (�������� 40,40ũ���� ��Ʈ)
	RECT getCameraRC(){
		return RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x + _itemInvenImage->getWidth() / 2),
			CAMERAMANAGER->CameraRelativePointY(_y + _itemInvenImage->getHeight() / 2), 40, 40);
	}


	//������ ȿ�� ������
	int getItemEffect(){ return _itemEffect; }

	//������ ��ô �̹���
	image* getItemImage(){ return _itemImage; }

	//������ �κ� �̹���
	image* getItemInvenImage(){ return _itemInvenImage; }

	//�κ� ���� �̹���
	image* getItemRightTopImage(){ return _itemRightTopImage; }

	bool getIsVisible(){ return _isVisible; }
	void setIsVisible(bool isVisible){ _isVisible = isVisible; }

	int getPrice(){ return _price; }

	void setPlayer(player* mainPlayer){ _mainPlayer = mainPlayer; }

	itemParent();
	~itemParent();
};

