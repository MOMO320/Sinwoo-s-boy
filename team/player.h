#pragma once
#include "gameNode.h"
#include <string>
#include <map>
#include <vector>
#include "itemParent.h"
#include "inventory.h"


class enemyManager;

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
	bool* isFire;		 // �÷��̾ ������?
	bool* isAttack;		 // ������Ʈ�� ���Ǵ�?
	bool* isOpen;
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
	RECT* _rcAttack;					// ���ط�Ʈ ������

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
	int _countAttack;					// ī��Ʈ ����
	int _countReturn;
	int _countAlpha;					// ī��Ʈ ����
	int _alphaValue;					// ���İ�
	int _jumpDirection;					// ���� �Ҹ�ŭ�� �Ÿ�
	int _currenJumpDirection;			// ���� ���� ����

	bool _delayEnd;						// ������ ��
	bool _loadStart;					// 

	bool _isAttack;						// �����߽��ϱ�?
	bool _isDamage;						// �¾ҽ��ϱ�?
	bool _isDead;						// �׾����ϱ�?
	bool _isJump;						// �����ϳ�?

	// �÷��̾� ����(�θ޶������� �ʿ�)
	bool _down;
	bool _right;
	bool _up;
	bool _left;

	bool _isTest;


	itemParent* _quickItem;

	enemyManager* _em;

public:
	player();
	~player();

	HRESULT init(POINT tileIndex);
	void release();
	void update();
	void render();

	void setupKeyValue();																													// ���� Ű�� �ʱ�ȭ
	void playerControl();																													// Ű�� �޴� �Լ�
	void playerMovement();																													// Ű�� �޾��� ��, ������ ó��
	void upgradeShield(int shieldLevel);																									// ���� ���׷��̵�(0���� �Ϲ�, 1���� ����1, 2���� ����2)
	void setupCollisionObject(RECT* rcObj, float* centerX, float* centerY, bool isCarry, bool* isFire, bool* isAttack, bool* isOpen);		// �浹 ���� ������Ʈ �Է�(���� �� ������Ʈ�� �浹 ����)
	void playerCollisionObject();																											// �÷��̾�� ������Ʈ �浹ó��
	void playerSideWeapon();
	void playerDead();
	void playerAttack();
	void playerSlashAttack();																												// �÷��̾� ȸ������
	void playerObjectAttack();																												// �÷��̾� ������Ʈ ����
	void playerEnemyAttack();
	void playerDamage();																													// �÷��̾� ó ���� ��
	void playerReturnIdle();
	void playerAlpha();																														// �÷��̾� ����ó��( �¾����� ��������)	
	void playerTileCheck();																													// �÷��̾� Ÿ�� üũ
	void playerJump();																														// �÷��̾� ����

	void deleteRcAttack();
	
	RECT getPlayerRC(){ return _rcPlayer; }
	POINT getPlayerRealpos() { return PointMake(_absoluteX, _absoluteY); }
	bool throwObject();																			// ���� ������
	bool playerCarry();																			// �÷��̾ � ������Ʈ�� ��� �ִ��� ����
	bool carryState();																			// �÷��̾ ������ ������ �ִ� ���̴�?
	bool playerBoxOpen();																		// �÷��̾� �ڽ� ����
	
	void startJump(POINT endTile);																											// �÷��̾� ����


	void delay();																				// ������ �ð��� ������ false�� ���� ��


	void setSideWeapon(int sideWeapon) { _sideWeapon = sideWeapon; }
	void setQuickItemMemoryAddressLink(itemParent* item) { _quickItem = item; }
	void setPlayerHP(int damage) { _playerHP += damage; }										// �÷��̾� ü�±�� �Լ�

	itemParent* getQuickItem(){ return _quickItem; }
	PLAYERMOVEMENET getPLAYERMANET() { return _playerMovement; }

	void setEmAddressMemeryLink(enemyManager* em) { _em = em; }

	void setPlayerTileIndex(POINT tileIndex){
		_absoluteX = tileIndex.x*TILESIZE;
		_absoluteY = tileIndex.y*TILESIZE;
	}
};
