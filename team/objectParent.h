#pragma once
#include "gameNode.h"
#include "player.h"

class player;

enum tagObjectType
{
	OB_THROW,		//�����Ⱑ ������ ������Ʈ
	OB_BOX,			//����
	OB_SPARK,		//������
};

enum tagObjectState
{
	PUT,		//�����ִ� ����
	THROWING,	//���������ִ� ����
	ZIRIRI,		//����ũ ��������?
	BOX_OPEN,	//���� ��������
	BOX_CLOSE,	//���� ��������
};

enum tagObjectUDLR
{
	OB_UP,	 	//��
	OB_DOWN,	//�Ʒ�
	OB_LEFT,	//����
	OB_RIGHT	//������
};

class objectParent :
	public gameNode
{
protected:
	image* _objectImage;			//������Ʈ �̹���
	RECT _rcObject;					//��ǥ�޾ƿö� ���� ��Ʈ
	float _x, _y;					//������Ʈ ������ǥ
	float _centerX, _centerY;		//������Ʈ ������ ����� ��ǥ
	float _endX, _endY;				//�������� �������� ��ǥ
	float _carryX, _carryY;
	tagObjectType _objectType;		//������Ʈ ����
	tagObjectState _objectState;	//������Ʈ ���°�
	
	tagObjectUDLR _objectUDLR;		//������Ʈ �����¿�
	
	int _objectEffect;				//������Ʈ�� ȿ��
	int _throwDistance;				//�������� ����
	int _throwSpeed;				//�������� �ӵ�
	int _throwDirection;			//������ �� ���� (0�� �Ʒ�, 1�� ������, 2�� ���� 3�� ����)

	int _frameX;					//������
	int _frameCount;				//������ī��Ʈ
									
	float _throwDamage;				//�������� ������
	bool _isUp;						//����ֳľ���
	bool _respon;					//�������ǳ� �ȵǳ�
	bool _isFire;					//���󰬴�?
	bool _isAttack;					//����
	bool _isOpen;					//���ڿ���

	player * _player;

	//���� ������Ʈ
	vector<tagObject> _vObject;
	vector<tagObject>::iterator _viObject;


public:
	objectParent();
	~objectParent();

	//������Ʈ �ʱ�ȭ��
	virtual HRESULT init();
	virtual HRESULT init(POINT point, player* player);

	virtual void release();
	virtual void update();
	virtual void render();

	//������Ʈ�� �̵�

	virtual void move() {}

	virtual void open() {}
	virtual void hide() {}

	//������Ʈ�� ����
	virtual void removeObject(int arrNum);

	//������Ʈ ��ǥ�� �����ϱ�
	void setPoint(POINT point) { _x = point.x; _y = point.y; }
	RECT getItemRC() { return _rcObject; }

	//������ ���º���
	void setState(bool isThrow) { if (isThrow)_objectState = THROWING; else _objectState = PUT; }

	//������Ʈ�� ������
	int getState() { return _objectState; }

	float getX() { return _x; }
	float getY() { return _y; }
	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }
	void setEndY(float endY) { _endY = endY; }
	void setThrowPower(float throwDamage) { _throwDamage = throwDamage; }

	//���Ͱ��� ����������
	vector<tagObject> getVObject() { return _vObject; }
	vector<tagObject>::iterator getVIObject() { return _viObject; }


	int getThrowDistance() { return _throwDistance; }
	bool getIsAttack() { return _isAttack; }

};

