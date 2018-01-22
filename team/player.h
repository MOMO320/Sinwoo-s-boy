#pragma once
#include "gameNode.h"
#include <string>
#include <map>
#include <vector>
#include "itemParent.h"
#include "inventory.h"
#include "itemParent.h"


enum PLAYERSTATE {
	NORMAL,				// �Ϲ�
	SHIELD1,			// ����1
	SHIELD2,			// ����2
	CARRY,				// ���ǵ�� ������
	PLAYEREND,
};

enum PLAYERMOVEMENET {

	DOWN_MOVE,			// �������� ������			
	RIGHT_MOVE,
	UP_MOVE,
	LEFT_MOVE,

	DOWN_STOP,
	RIGHT_STOP,
	UP_STOP,
	LEFT_STOP

};

struct tagObject {
	RECT* rc;			 // ������Ʈ ��Ʈ
	float* centerObjX;	 // ������Ʈ ������ǥ	
	float* centerObjY;
	bool isCarry;		 // ��� �ִ� �����Դϱ�?
	bool isCollision;	 // �浹�� �����մϱ�?
};

class player :public gameNode
{
private:
	typedef vector<string> stateKeyName;
	stateKeyName _normalKey;
	stateKeyName _shieldKey1;
	stateKeyName _shieldKey2;
	stateKeyName _carryKey;

	map<PLAYERSTATE, vector<string> > _mStateKey;
	map<PLAYERSTATE, vector<string> >::iterator _mIterStateKey;

	vector<tagObject> _vObject;			// ������Ʈ ���� ��Ʈ

private:

	image* _playerBmp;					// �÷��̾� �̹���

	animation* _playerMotion;

	RECT _rcPlayerCamera;				// ī�޶� ��Ʈ
	RECT _rcPlayer;						// ���� �÷��̾� ��Ʈ

	PLAYERSTATE _playerState;			// �÷��̾� ���� (1.�Ϲ�, 2.����1, 3.����2)
	PLAYERMOVEMENET _playerMovement;	// �÷��̾� �����Ʈ

	float _absoluteX, _absoluteY;		// ������ǥ x, y
	float _centerX, _centerY;			// �����ǥ x, y

	float _speed;
	float _playerHP;					// �÷��̾� HP

	int _shieldLevel;					// ���� ����
	int _sideWeapon;					// ���� ������ (0�� ����, 1�� �θ޶�, 2�� ȭ��)
	int _keyPressure;					// Ű �з�
	int _countDelay;					// ī��Ʈ ������

	bool _delayEnd;						// ������ ��

	itemParent* _quickItem;

	// ���߿� ������ testRect
	RECT _rcCameraObject;				// ������ ������Ʈ
	RECT _rcObject;
	float _objCenterX, _objCenterY;


public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();

	void setupKeyValue();																		// ���� Ű�� �ʱ�ȭ
	void playerControl();																		// Ű�� �޴� �Լ�
	void playerMovement();																		// Ű�� �޾��� ��, ������ ó��
	void upgradeShield(int shieldLevel);														// ���� ���׷��̵�(0���� �Ϲ�, 1���� ����1, 2���� ����2)
	void setupCollisionObject(RECT* rcObj, float* centerX, float* centerY, bool isCarry);		// �浹 ���� ������Ʈ �Է�(���� �� ������Ʈ�� �浹 ����)
	void playerCollisionObject();																// �÷��̾�� ������Ʈ �浹ó��
	void playerSideWeapon();
	void playerDead();

	
	RECT getPlayerRC(){ return _rcPlayer; }

	bool throwObject();																			// ���� ������
	bool playerCarry();																			// �÷��̾ � ������Ʈ�� ��� �ִ��� ����
	bool carryState();																			// �÷��̾ ������ ������ �ִ� ���̴�?

	void delay();																				// ������ �ð��� ������ false�� ���� ��

	void setSideWeapon(int sideWeapon) { _sideWeapon = sideWeapon; }
	void setQuickItemMemoryAddressLink(itemParent* item) { _quickItem = item; }
};
