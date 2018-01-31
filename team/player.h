#pragma once
#include "gameNode.h"
#include <string>
#include <map>
#include <vector>
#include "itemParent.h"
#include "inventory.h"


class enemyManager;

enum PLAYERSTATE {
	NORMAL,				// 일반
	SHIELD1,			// 방패1
	SHIELD2,			// 방패2
	CARRY,				// 물건들고 있을때
	PLAYEREND,
};

enum PLAYERMOVEMENET {

	DOWN_MOVE,			// 왼쪽으로 움직임			
	RIGHT_MOVE,
	UP_MOVE,
	LEFT_MOVE,

	DOWN_STOP,
	RIGHT_STOP,
	UP_STOP,
	LEFT_STOP

};

struct tagObject {
	RECT* rc;			 // 오브젝트 렉트
	float* centerObjX;	 // 오브젝트 중점좌표	
	float* centerObjY;
	bool isCarry;		 // 들수 있는 물건입니까?
	bool isCollision;	 // 충돌이 가능합니까?
	bool* isFire;		 // 플레이어가 던졋니?
	bool* isAttack;		 // 오브젝트를 때렷니?
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

	vector<tagObject> _vObject;			// 오브젝트 판정 렉트

private:

	image* _playerBmp;					// 플레이어 이미지

	animation* _playerMotion;

	RECT _rcPlayerCamera;				// 카메라 렉트
	RECT _rcPlayer;						// 실제 플레이어 렉트
	RECT* _rcAttack;					// 어텍렉트 포인터

	PLAYERSTATE _playerState;			// 플레이어 상태 (1.일반, 2.방패1, 3.방패2)
	PLAYERMOVEMENET _playerMovement;	// 플레이어 무브먼트

	float _absoluteX, _absoluteY;		// 절대좌표 x, y
	float _centerX, _centerY;			// 상대좌표 x, y

	float _speed;
	float _playerHP;					// 플레이어 HP

	int _shieldLevel;					// 방패 레벨
	int _sideWeapon;					// 보조 아이템 (0번 없음, 1번 부메랑, 2번 화살)
	int _keyPressure;					// 키 압력
	int _countDelay;					// 카운트 딜레이
	int _countAttack;					// 카운트 어택
	int _countReturn;
	int _countAlpha;					// 카운트 알파
	int _alphaValue;					// 알파값
	int _jumpDirection;					// 점프 할만큼의 거리
	int _currenJumpDirection;			// 현제 점프 길이

	bool _delayEnd;						// 딜레이 끝
	bool _loadStart;					// 

	bool _isAttack;						// 공격했습니까?
	bool _isDamage;						// 맞았습니까?
	bool _isDead;						// 죽었습니까?
	bool _isJump;						// 점프하냐?

	// 플레이어 방향(부메랑던질때 필요)
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

	void setupKeyValue();																													// 상태 키값 초기화
	void playerControl();																													// 키값 받는 함수
	void playerMovement();																													// 키를 받았을 때, 움직임 처리
	void upgradeShield(int shieldLevel);																									// 방패 업그레이드(0번이 일반, 1번이 방패1, 2번이 방패2)
	void setupCollisionObject(RECT* rcObj, float* centerX, float* centerY, bool isCarry, bool* isFire, bool* isAttack, bool* isOpen);		// 충돌 판정 오브젝트 입력(여기 들어간 오브젝트만 충돌 판정)
	void playerCollisionObject();																											// 플레이어와 오브젝트 충돌처리
	void playerSideWeapon();
	void playerDead();
	void playerAttack();
	void playerSlashAttack();																												// 플레이어 회전베기
	void playerObjectAttack();																												// 플레이어 오브젝트 공격
	void playerEnemyAttack();
	void playerDamage();																													// 플레이어 처 맞을 때
	void playerReturnIdle();
	void playerAlpha();																														// 플레이어 알파처리( 맞았을때 깜빡깜빡)	
	void playerTileCheck();																													// 플레이어 타일 체크
	void playerJump();																														// 플레이어 점프

	void deleteRcAttack();
	
	RECT getPlayerRC(){ return _rcPlayer; }
	POINT getPlayerRealpos() { return PointMake(_absoluteX, _absoluteY); }
	bool throwObject();																			// 물건 던지기
	bool playerCarry();																			// 플레이어가 어떤 오브젝트를 들수 있는지 판정
	bool carryState();																			// 플레이어가 물건을 가지고 있는 중이니?
	bool playerBoxOpen();																		// 플레이어 박스 오픈
	
	void startJump(POINT endTile);																											// 플레이어 점프


	void delay();																				// 일정한 시간이 지나면 false로 변경 됨


	void setSideWeapon(int sideWeapon) { _sideWeapon = sideWeapon; }
	void setQuickItemMemoryAddressLink(itemParent* item) { _quickItem = item; }
	void setPlayerHP(int damage) { _playerHP += damage; }										// 플레이어 체력깍는 함수

	itemParent* getQuickItem(){ return _quickItem; }
	PLAYERMOVEMENET getPLAYERMANET() { return _playerMovement; }

	void setEmAddressMemeryLink(enemyManager* em) { _em = em; }

	void setPlayerTileIndex(POINT tileIndex){
		_absoluteX = tileIndex.x*TILESIZE;
		_absoluteY = tileIndex.y*TILESIZE;
	}
};
