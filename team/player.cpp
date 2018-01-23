#include "stdafx.h"
#include "player.h"


player::player()
{
}


player::~player()
{
}


HRESULT player::init() {

	_mIterStateKey = _mStateKey.begin();

	_playerBmp = IMAGEMANAGER->addFrameImage("링크", "./image/playerImage/player.bmp", 1800, 7200, 12, 48, true, RGB(255, 0, 255));
	setupKeyValue();

	CAMERAMANAGER->setBackground(2400, 1200);
	CAMERAMANAGER->setStartBackground(0, 0);

	_absoluteX = 1000;
	_absoluteY = 800;

	_rcPlayerCamera = RectMakeCenter(_absoluteX, _absoluteY, 30, 30);


	CAMERAMANAGER->setCameraCondition(true, CAMERA_AIMING);
	CAMERAMANAGER->setCameraCondition(false, CAMERA_AIMING);

	CAMERAMANAGER->setCameraAim(&_rcPlayerCamera);

	_centerX = CAMERAMANAGER->CameraRelativePointX(_absoluteX);
	_centerY = CAMERAMANAGER->CameraRelativePointY(_absoluteY);


	_rcPlayer = RectMakeCenter(_centerX, _centerY, 48, 48);

	_speed = 4.0f;
	_shieldLevel = 0;			// 방패 레벨 0;
	_keyPressure = 0;
	_countDelay = 0;
	_sideWeapon = 2;
	_playerHP = 10;

	_delayEnd = false;

	_playerState = NORMAL;
	_playerMovement = DOWN_STOP;

	_playerMotion = KEYANIMANAGER->findAnimation("정지(아래쪽)(일반)");

	setupCollisionObject(&_rcObject, &_objCenterX, &_objCenterY, true);


	// 나중에 삭제용 오브젝트
	_objCenterX = 700;
	_objCenterY = 800;
	_rcCameraObject = RectMakeCenter(_objCenterX, _objCenterY, 50, 50);
	_rcObject = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_objCenterX), CAMERAMANAGER->CameraRelativePointY(_objCenterY), 50, 50);

	//안전을 위해 퀵슬롯 아이템 널값 초기화(재호)
	_quickItem = NULL;
	return S_OK;
}

void player::release() {

}
void player::update() {

	playerCollisionObject();
	playerControl();
	playerMovement();


	_rcCameraObject = RectMakeCenter(_objCenterX, _objCenterY, 50, 50);
	_rcObject = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_objCenterX), CAMERAMANAGER->CameraRelativePointY(_objCenterY), 50, 50);

	KEYANIMANAGER->update();

	playerDead();
	delay();
}
void player::render() {

	setColorRect(getMemDC(), _rcPlayer, 150, 40, 130);
	setColorRect(getMemDC(), _rcObject, 30, 150, 30);

	_playerBmp->aniCenterRender(getMemDC(), _centerX, _centerY, _playerMotion);

	showIntData(getMemDC(), "키 압력지수 : %d ", _keyPressure, 10, 500);

	//퀵슬롯이 연결 되었다면 그려라(재호)
	//UI 그려지면 오른쪽 위 상자에 맞춰 그려지도록 수정
	if (_quickItem != NULL)
		_quickItem->getItemImage()->render(getMemDC(), 100, 100);
}

void player::setupKeyValue() {

	_normalKey.push_back("정지(아래쪽)(일반)");
	_normalKey.push_back("정지(오른쪽)(일반)");
	_normalKey.push_back("정지(위쪽)(일반)");
	_normalKey.push_back("정지(왼쪽)(일반)");
	_normalKey.push_back("걷기(아래쪽)(일반)");
	_normalKey.push_back("걷기(오른쪽)(일반)");
	_normalKey.push_back("걷기(위쪽)(일반)");
	_normalKey.push_back("걷기(왼쪽)(일반)");

	_shieldKey1.push_back("정지(아래쪽)(방패1)");
	_shieldKey1.push_back("정지(오른쪽)(방패1)");
	_shieldKey1.push_back("정지(위쪽)(방패1)");
	_shieldKey1.push_back("정지(왼쪽)(방패1)");
	_shieldKey1.push_back("걷기(아래쪽)(방패1)");
	_shieldKey1.push_back("걷기(오른쪽)(방패1)");
	_shieldKey1.push_back("걷기(위쪽)(방패1)");
	_shieldKey1.push_back("걷기(왼쪽)(방패1)");

	_shieldKey2.push_back("정지(아래쪽)(방패2)");
	_shieldKey2.push_back("정지(오른쪽)(방패2)");
	_shieldKey2.push_back("정지(위쪽)(방패2)");
	_shieldKey2.push_back("정지(왼쪽)(방패2)");
	_shieldKey2.push_back("걷기(아래쪽)(방패2)");
	_shieldKey2.push_back("걷기(오른쪽)(방패2)");
	_shieldKey2.push_back("걷기(위쪽)(방패2)");
	_shieldKey2.push_back("걷기(왼쪽)(방패2)");

	_carryKey.push_back("물건들고정지(아래쪽)");
	_carryKey.push_back("물건들고정지(오른쪽)");
	_carryKey.push_back("물건들고정지(위쪽)");
	_carryKey.push_back("물건들고정지(왼쪽)");
	_carryKey.push_back("물건들고걷기(아래쪽)");
	_carryKey.push_back("물건들고걷기(오른쪽)");
	_carryKey.push_back("물건들고걷기(위쪽)");
	_carryKey.push_back("물건들고걷기(왼쪽)");


	_mStateKey.insert(pair<PLAYERSTATE, vector<string> >(NORMAL, _normalKey));
	_mStateKey.insert(pair<PLAYERSTATE, vector<string> >(SHIELD1, _shieldKey1));
	_mStateKey.insert(pair<PLAYERSTATE, vector<string> >(SHIELD2, _shieldKey2));
	_mStateKey.insert(pair<PLAYERSTATE, vector<string> >(CARRY, _carryKey));

	int downIdle_N[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("정지(아래쪽)(일반)", "링크", downIdle_N, 1, 1, false, 0);

	int rightIdle_N[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("정지(오른쪽)(일반)", "링크", rightIdle_N, 1, 1, false, 0);

	int upIdle_N[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("정지(위쪽)(일반)", "링크", upIdle_N, 1, 1, false, 0);

	int leftIdle_N[] = { 3 };
	KEYANIMANAGER->addArrayFrameAnimation("정지(왼쪽)(일반)", "링크", leftIdle_N, 1, 1, false, 0);

	int downMove_N[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("걷기(아래쪽)(일반)", "링크", downMove_N, 8, 8, true, 3);

	int rightMove_N[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("걷기(오른쪽)(일반)", "링크", rightMove_N, 8, 8, true, 4);

	int upMove_N[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("걷기(위쪽)(일반)", "링크", upMove_N, 8, 8, true, 5);

	int leftMove_N[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("걷기(왼쪽)(일반)", "링크", leftMove_N, 8, 8, true, 6);



	int downIdle_S1[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("정지(아래쪽)(방패1)", "링크", downIdle_S1, 1, 1, false, 1);

	int rightIdle_S1[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("정지(오른쪽)(방패1)", "링크", rightIdle_S1, 1, 1, false, 1);

	int upIdle_S1[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("정지(위쪽)(방패1)", "링크", upIdle_S1, 1, 1, false, 1);

	int leftIdle_S1[] = { 3 };
	KEYANIMANAGER->addArrayFrameAnimation("정지(왼쪽)(방패1)", "링크", leftIdle_S1, 1, 1, false, 1);

	int downMove_S1[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("걷기(아래쪽)(방패1)", "링크", downMove_S1, 8, 8, true, 7);

	int rightMove_S1[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("걷기(오른쪽)(방패1)", "링크", rightMove_S1, 8, 8, true, 8);

	int upMove_S1[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("걷기(위쪽)(방패1)", "링크", upMove_S1, 8, 8, true, 9);

	int leftMove_S1[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("걷기(왼쪽)(방패1)", "링크", leftMove_S1, 8, 8, true, 10);




	int downIdle_S2[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("정지(아래쪽)(방패2)", "링크", downIdle_S2, 1, 1, false, 2);

	int rightIdle_S2[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("정지(오른쪽)(방패2)", "링크", rightIdle_S2, 1, 1, false, 2);

	int upIdle_S2[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("정지(위쪽)(방패2)", "링크", upIdle_S2, 1, 1, false, 2);

	int leftIdle_S2[] = { 3 };
	KEYANIMANAGER->addArrayFrameAnimation("정지(왼쪽)(방패2)", "링크", leftIdle_S2, 1, 1, false, 2);

	int downMove_S2[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("걷기(아래쪽)(방패2)", "링크", downMove_S2, 8, 8, true, 11);

	int rightMove_S2[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("걷기(오른쪽)(방패2)", "링크", rightMove_S2, 8, 8, true, 12);

	int upMove_S2[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("걷기(위쪽)(방패2)", "링크", upMove_S2, 8, 8, true, 13);

	int leftMove_S2[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("걷기(왼쪽)(방패2)", "링크", leftMove_S2, 8, 8, true, 14);



	int downIdle_C[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("물건들고정지(아래쪽)", "링크", downIdle_N, 1, 1, false, 20);

	int rightIdle_C[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("물건들고정지(오른쪽)", "링크", rightIdle_N, 1, 1, false, 20);

	int upIdle_C[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("물건들고정지(위쪽)", "링크", upIdle_N, 1, 1, false, 20);

	int leftIdle_C[] = { 3 };
	KEYANIMANAGER->addArrayFrameAnimation("물건들고정지(왼쪽)", "링크", leftIdle_N, 1, 1, false, 20);

	int downMove_C[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("물건들고걷기(아래쪽)", "링크", downMove_N, 6, 8, true, 21);

	int rightMove_C[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("물건들고걷기(오른쪽)", "링크", rightMove_N, 6, 8, true, 22);

	int upMove_C[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("물건들고걷기(위쪽)", "링크", upMove_N, 6, 8, true, 23);

	int leftMove_C[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("물건들고걷기(왼쪽)", "링크", leftMove_N, 6, 8, true, 24);




	int downGrab[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("잡기(아래쪽)", "링크", downGrab, 1, 6, false, 15);

	int rightGrab[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("잡기(오른쪽)", "링크", rightGrab, 1, 6, false, 15);

	int upGrab[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("잡기(위쪽)", "링크", upGrab, 1, 6, false, 15);

	int leftGrab[] = { 3 };
	KEYANIMANAGER->addArrayFrameAnimation("잡기(왼쪽)", "링크", leftGrab, 1, 6, false, 15);



	int downPush[] = { 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("밀기(아래쪽)", "링크", downPush, 5, 10, true, 16);

	int rightPush[] = { 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("밀기(오른쪽)", "링크", rightPush, 5, 10, true, 17);

	int upPush[] = { 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("밀기(위쪽)", "링크", upPush, 5, 10, true, 18);

	int leftPush[] = { 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("밀기(왼쪽)", "링크", leftPush, 5, 10, true, 19);




	int downPowerUp[] = { 4 };
	KEYANIMANAGER->addArrayFrameAnimation("기모으기(아래쪽)", "링크", downPowerUp, 1, 12, false, 25);

	int rightPowerUp[] = { 4 };
	KEYANIMANAGER->addArrayFrameAnimation("기모으기(오른쪽)", "링크", rightPowerUp, 1, 12, false, 26);

	int upPowerUp[] = { 4 };
	KEYANIMANAGER->addArrayFrameAnimation("기모으기(위쪽)", "링크", upPowerUp, 1, 12, false, 27);

	int leftPowerUp[] = { 4 };
	KEYANIMANAGER->addArrayFrameAnimation("기모으기(왼쪽)", "링크", leftPowerUp, 1, 12, false, 28);

	int downAttack[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("칼공격(아래쪽)", "링크", downAttack, 6, 12, false, 25);

	int rightAttack[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("칼공격(오른쪽)", "링크", rightAttack, 6, 12, false, 26);

	int upAttack[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("칼공격(위쪽)", "링크", upAttack, 6, 12, false, 27);

	int leftAttack[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("칼공격(왼쪽)", "링크", leftAttack, 6, 12, false, 28);



	int downSlash[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("회전배기(아래쪽)", "링크", downSlash, 6, 14, false, 37);

	int rightSlash[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("회전배기(오른쪽)", "링크", rightSlash, 6, 14, false, 39);

	int upSlash[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("회전배기(위쪽)", "링크", upSlash, 6, 14, false, 38);

	int leftSlash[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("회전배기(왼쪽)", "링크", leftSlash, 6, 14, false, 40);




	int downBoomerang[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("부메랑(아래쪽)", "링크", downBoomerang, 3, 10, false, 29);

	int rightBoomerang[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("부메랑(오른쪽)", "링크", rightBoomerang, 3, 10, false, 30);

	int upBoomerang[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("부메랑(위쪽)", "링크", upBoomerang, 3, 10, false, 31);

	int leftBoomerang[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("부메랑(왼쪽)", "링크", leftBoomerang, 3, 10, false, 32);


	int downBow[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("활(아래쪽)", "링크", downBow, 3, 10, false, 33);

	int rightBow[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("활(오른쪽)", "링크", rightBow, 3, 10, false, 34);

	int upBow[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("활(위쪽)", "링크", upBow, 3, 10, false, 35);

	int leftBow[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("활(왼쪽)", "링크", leftBow, 3, 10, false, 36);

	int dead[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("죽음", "링크", dead, 10, 10, false, 41);

	int falling[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("죽음", "링크", dead, 6, 4, false, 42);

}

void player::playerControl() {

	if (_playerHP < 0) return;

	// 키 압력이 50이 아닐때 링크를 움직일 수 있음
	if (_keyPressure != 50) {
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN)) {
			_playerMovement = DOWN_MOVE;
			_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[4]);
			_playerMotion->start();
		}

		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) {
			_playerMovement = RIGHT_MOVE;
			_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[5]);
			_playerMotion->start();
		}

		if (KEYMANAGER->isOnceKeyDown(VK_UP)) {
			_playerMovement = UP_MOVE;
			_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[6]);
			_playerMotion->start();
		}

		if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) {
			_playerMovement = LEFT_MOVE;
			_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[7]);
			_playerMotion->start();
		}

		if (KEYMANAGER->isOnceKeyUp(VK_DOWN)) {
			if (_playerMovement == DOWN_MOVE || _playerMovement == DOWN_STOP) {
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[0]);
				_playerMotion->start();
				_playerMovement = DOWN_STOP;
			}
		}

		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT)) {
			if (_playerMovement == RIGHT_MOVE || _playerMovement == RIGHT_STOP) {
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[1]);
				_playerMotion->start();
				_playerMovement = RIGHT_STOP;
			}
		}

		if (KEYMANAGER->isOnceKeyUp(VK_UP)) {
			if (_playerMovement == UP_MOVE || _playerMovement == UP_STOP) {
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[2]);
				_playerMotion->start();
				_playerMovement = UP_STOP;
			}
		}

		if (KEYMANAGER->isOnceKeyUp(VK_LEFT)) {
			if (_playerMovement == LEFT_MOVE || _playerMovement == LEFT_STOP) {
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[3]);
				_playerMotion->start();
				_playerMovement = LEFT_STOP;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown('S')) {

		throwObject();

		switch (_playerMovement)
		{
		case DOWN_MOVE: case DOWN_STOP:
			_playerMotion = KEYANIMANAGER->findAnimation("잡기(아래쪽)");
			_playerMovement = DOWN_STOP;
			break;

		case RIGHT_MOVE: case RIGHT_STOP:
			_playerMotion = KEYANIMANAGER->findAnimation("잡기(오른쪽)");
			_playerMovement = RIGHT_STOP;
			break;

		case UP_MOVE: case UP_STOP:
			_playerMotion = KEYANIMANAGER->findAnimation("잡기(위쪽)");
			_playerMovement = UP_STOP;
			break;

		case LEFT_MOVE: case LEFT_STOP:
			_playerMotion = KEYANIMANAGER->findAnimation("잡기(왼쪽)");
			_playerMovement = LEFT_STOP;
			break;

		default:
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyUp('S')) {

		switch (_playerMovement)
		{
		case DOWN_MOVE: case DOWN_STOP:
			if (playerCarry()) {
				_playerMotion = KEYANIMANAGER->findAnimation("물건들고정지(아래쪽)");
				_playerState = CARRY;
			}
			else {
				upgradeShield(_shieldLevel);
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[0]);
			}

			break;

		case RIGHT_MOVE: case RIGHT_STOP:
			if (playerCarry()) {
				_playerMotion = KEYANIMANAGER->findAnimation("물건들고정지(오른쪽)");
				_playerState = CARRY;
			}
			else {
				upgradeShield(_shieldLevel);
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[1]);
			}

			break;

		case UP_MOVE: case UP_STOP:
			if (playerCarry()) {
				_playerMotion = KEYANIMANAGER->findAnimation("물건들고정지(위쪽)");
				_playerState = CARRY;
			}
			else {
				upgradeShield(_shieldLevel);
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[2]);
			}

			break;

		case LEFT_MOVE: case LEFT_STOP:
			if (playerCarry()) {
				_playerMotion = KEYANIMANAGER->findAnimation("물건들고정지(왼쪽)");
				_playerState = CARRY;
			}
			else {
				upgradeShield(_shieldLevel);
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[3]);
			}

			break;

		default:
			break;
		}
	}

	if (KEYMANAGER->isStayKeyDown('X')) {

		if (carryState()) return;		// 물건을 들고 있을 때는 공격할 수 없음

		_keyPressure++;

		switch (_playerMovement)
		{
		case DOWN_MOVE: case DOWN_STOP:
			if (_keyPressure < 50) {
				_playerMotion = KEYANIMANAGER->findAnimation("칼공격(아래쪽)");
				_playerMotion->onceStart();
			}
			else {
				_playerMotion = KEYANIMANAGER->findAnimation("기모으기(아래쪽)");
				_keyPressure = 50;
			}
			_playerMovement = DOWN_STOP;
			break;

		case RIGHT_MOVE: case RIGHT_STOP:
			if (_keyPressure < 50) {
				_playerMotion = KEYANIMANAGER->findAnimation("칼공격(오른쪽)");
				_playerMotion->onceStart();
			}
			else {
				_playerMotion = KEYANIMANAGER->findAnimation("기모으기(오른쪽)");
				_keyPressure = 50;
			}
			_playerMovement = RIGHT_STOP;
			break;

		case UP_MOVE: case UP_STOP:
			if (_keyPressure < 50) {
				_playerMotion = KEYANIMANAGER->findAnimation("칼공격(위쪽)");
				_playerMotion->onceStart();
			}
			else {
				_playerMotion = KEYANIMANAGER->findAnimation("기모으기(위쪽)");
				_keyPressure = 50;
			}
			_playerMovement = UP_STOP;
			break;

		case LEFT_MOVE: case LEFT_STOP:
			if (_keyPressure < 50) {
				_playerMotion = KEYANIMANAGER->findAnimation("칼공격(왼쪽)");
				_playerMotion->onceStart();
			}
			else {
				_playerMotion = KEYANIMANAGER->findAnimation("기모으기(왼쪽)");
				_keyPressure = 50;
			}
			_playerMovement = LEFT_STOP;
			break;

		default:
			break;
		}

	}

	if (KEYMANAGER->isOnceKeyUp('X')) {

		switch (_playerMovement) {
		case DOWN_STOP:
			if (_keyPressure >= 50) {
				_playerMotion = KEYANIMANAGER->findAnimation("회전배기(아래쪽)");
				_playerMotion->start();
			}
			else {
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[0]);
			}
			_keyPressure = 0;
			break;

		case RIGHT_STOP:
			if (_keyPressure >= 50) {
				_playerMotion = KEYANIMANAGER->findAnimation("회전배기(오른쪽)");
				_playerMotion->start();
			}
			else {
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[1]);
			}
			_keyPressure = 0;
			break;

		case UP_STOP:
			if (_keyPressure >= 50) {
				_playerMotion = KEYANIMANAGER->findAnimation("회전배기(위쪽)");
				_playerMotion->start();
			}
			else {
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[2]);
			}
			_keyPressure = 0;
			break;

		case LEFT_STOP:
			if (_keyPressure >= 50) {
				_playerMotion = KEYANIMANAGER->findAnimation("회전배기(왼쪽)");
				_playerMotion->start();
			}
			else {
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[3]);
			}
			_keyPressure = 0;
			break;
		}

	}

	if (KEYMANAGER->isOnceKeyDown('C')) {
		if (carryState()) return;
		if (_delayEnd) return;
		_delayEnd = true;

		playerSideWeapon();

	}

}

void player::playerMovement() {

	switch (_playerMovement)
	{

	case DOWN_MOVE:
		_absoluteY += _speed;
		break;

	case RIGHT_MOVE:
		_absoluteX += _speed;
		break;

	case UP_MOVE:
		_absoluteY -= _speed;
		break;

	case LEFT_MOVE:
		_absoluteX -= _speed;
		break;

	case DOWN_STOP: case RIGHT_STOP: case UP_STOP: case LEFT_STOP:

		break;

	default:
		break;
	}

	_rcPlayerCamera = RectMakeCenter(_absoluteX, _absoluteY, 30, 30);
	_centerX = CAMERAMANAGER->CameraRelativePointX(_absoluteX);
	_centerY = CAMERAMANAGER->CameraRelativePointY(_absoluteY);
	_rcPlayer = RectMakeCenter(_centerX, _centerY, 48, 48);

}

void player::upgradeShield(int shieldLevel) {

	_shieldLevel = shieldLevel;

	switch (_shieldLevel)
	{
	case 0:
		_playerState = NORMAL;

		break;

	case 1:
		_playerState = SHIELD1;
		break;

	case 2:
		_playerState = SHIELD2;
		break;

	default:
		break;
	}

	switch (_playerMovement) {
	case DOWN_STOP:
		_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[0]);
		break;

	case RIGHT_STOP:
		_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[1]);
		break;

	case UP_STOP:
		_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[2]);
		break;

	case LEFT_STOP:
		_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[3]);
		break;
	}

}

void player::setupCollisionObject(RECT* rcObj, float* centerX, float* centerY, bool isCarry) {
	tagObject object;
	object.rc = rcObj;
	object.centerObjX = centerX;
	object.centerObjY = centerY;
	object.isCarry = isCarry;
	object.isCollision = true;

	_vObject.push_back(object);
}

void player::playerCollisionObject() {

	for (int i = 0; i < _vObject.size(); ++i) {

		if (!_vObject[i].isCollision) {
			*_vObject[i].centerObjY = _absoluteY - 30;
			*_vObject[i].centerObjX = _absoluteX;
		}
		else {

			RECT temp;
			if (IntersectRect(&temp, _vObject[i].rc, &_rcPlayer)) {
				switch (_playerMovement)
				{
				case DOWN_MOVE:
					_absoluteY -= (temp.bottom - temp.top) + 1;
					_playerMotion = KEYANIMANAGER->findAnimation("밀기(아래쪽)");
					_playerMotion->start();
					_playerMovement = DOWN_STOP;
					break;

				case RIGHT_MOVE:
					_absoluteX -= (temp.right - temp.left) + 1;
					_playerMotion = KEYANIMANAGER->findAnimation("밀기(오른쪽)");
					_playerMotion->start();
					_playerMovement = RIGHT_STOP;
					break;

				case UP_MOVE:
					_absoluteY += (temp.bottom - temp.top) + 1;
					_playerMotion = KEYANIMANAGER->findAnimation("밀기(위쪽)");
					_playerMotion->start();
					_playerMovement = UP_STOP;
					break;

				case LEFT_MOVE:
					_absoluteX += (temp.right - temp.left) + 1;
					_playerMotion = KEYANIMANAGER->findAnimation("밀기(왼쪽)");
					_playerMotion->start();
					_playerMovement = LEFT_STOP;
					break;

				default:
					break;
				}
			}

		}

	}

}

bool player::playerCarry() {

	for (int i = 0; i < _vObject.size(); ++i) {

		if (!_vObject[i].isCarry) return false;				// 들 수 없는 물건이면 return

		switch (_playerMovement)
		{
		case DOWN_MOVE: case DOWN_STOP:

			if (*_vObject[i].centerObjY - _absoluteY >= 48 && *_vObject[i].centerObjY - _absoluteY <= 50) {

				*_vObject[i].centerObjY = _absoluteY - 30;
				*_vObject[i].centerObjX = _absoluteX;
				_vObject[i].isCollision = false;

				return true;
			}
			break;

		case RIGHT_MOVE: case RIGHT_STOP:

			if (*_vObject[i].centerObjX - _absoluteX >= 48 && *_vObject[i].centerObjX - _absoluteX <= 50) {

				*_vObject[i].centerObjY = _absoluteY - 30;
				*_vObject[i].centerObjX = _absoluteX;
				_vObject[i].isCollision = false;

				return true;
			}

			break;

		case UP_MOVE: case UP_STOP:

			if (_absoluteY - (*_vObject[i].centerObjY) >= 48 && _absoluteY - (*_vObject[i].centerObjY) <= 50) {

				*_vObject[i].centerObjY = _absoluteY - 30;
				*_vObject[i].centerObjX = _absoluteX;
				_vObject[i].isCollision = false;

				return true;
			}

			break;

		case LEFT_MOVE: case LEFT_STOP:

			if (_absoluteX - (*_vObject[i].centerObjX) >= 48 && _absoluteX - (*_vObject[i].centerObjX) <= 50) {

				*_vObject[i].centerObjY = _absoluteY - 30;
				*_vObject[i].centerObjX = _absoluteX;
				_vObject[i].isCollision = false;

				return true;
			}

			break;

		default:
			break;
		}

	}

	return false;
}

bool player::throwObject() {

	for (int i = 0; i < _vObject.size(); ++i) {

		if (_vObject[i].isCollision) continue;

		_vObject.erase(_vObject.begin() + i);
		return true;						//던젔음
	}

	return false;
}

bool player::carryState() {

	for (int i = 0; i < _vObject.size(); ++i) {

		if (!_vObject[i].isCollision) {
			return true;
		}
	}

	return false;
}

void player::playerSideWeapon() {

	switch (_sideWeapon)
	{
	case 1:

		switch (_playerMovement)
		{
		case DOWN_MOVE: case DOWN_STOP:

			_playerMotion = KEYANIMANAGER->findAnimation("부메랑(아래쪽)");
			_playerMotion->start();
			break;

		case RIGHT_MOVE: case RIGHT_STOP:

			_playerMotion = KEYANIMANAGER->findAnimation("부메랑(오른쪽)");
			_playerMotion->start();
			break;

		case UP_MOVE: case UP_STOP:

			_playerMotion = KEYANIMANAGER->findAnimation("부메랑(위쪽)");
			_playerMotion->start();
			break;

		case LEFT_MOVE: case LEFT_STOP:

			_playerMotion = KEYANIMANAGER->findAnimation("부메랑(왼쪽)");
			_playerMotion->start();
			break;
		}

		break;

	case 2:

		switch (_playerMovement)
		{
		case DOWN_MOVE: case DOWN_STOP:

			_playerMotion = KEYANIMANAGER->findAnimation("활(아래쪽)");
			_playerMotion->start();
			break;

		case RIGHT_MOVE: case RIGHT_STOP:

			_playerMotion = KEYANIMANAGER->findAnimation("활(오른쪽)");
			_playerMotion->start();
			break;

		case UP_MOVE: case UP_STOP:

			_playerMotion = KEYANIMANAGER->findAnimation("활(위쪽)");
			_playerMotion->start();
			break;

		case LEFT_MOVE: case LEFT_STOP:

			_playerMotion = KEYANIMANAGER->findAnimation("활(왼쪽)");
			_playerMotion->start();
			break;
		}

		break;

	default:
		break;
	}

}

void player::delay() {

	if (_delayEnd) {
		_countDelay++;
		if (_countDelay % 50 == 0) {
			_delayEnd = false;
			_countDelay = 0;
		}
	}

}

void player::playerDead() {

	if (_playerHP < 0) {
		_playerMotion = KEYANIMANAGER->findAnimation("죽음");
		_playerMotion->start();
	}

}