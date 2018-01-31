#include "stdafx.h"
#include "player.h"
#include "enemyManager.h"

player::player()
{
	IGMAP->setPlayerInitF([&](POINT p)mutable->void { this->setPlayerTileIndex(p); });
	IGMAP->setinitFirst([&](POINT p)mutable->void{this->init(p); });
}


player::~player()
{
}


HRESULT player::init(POINT tileIndex) {

	_isTest = false;
	_mIterStateKey = _mStateKey.begin();

	_playerBmp = IMAGEMANAGER->addFrameImage("��ũ", "./image/playerImage/player.bmp", 1800, 7200, 12, 48, true, RGB(255, 0, 255));
	setupKeyValue();

	CAMERAMANAGER->setBackground(2400, 1200);
	CAMERAMANAGER->setStartBackground(0, 0);

	_absoluteX = tileIndex.x*TILESIZE;
	_absoluteY = tileIndex.y*TILESIZE;

	_rcPlayerCamera = RectMakeCenter(_absoluteX, _absoluteY, 48, 48);


	CAMERAMANAGER->setCameraCondition(true, CAMERA_AIMING);
	CAMERAMANAGER->setCameraCondition(false, CAMERA_AIMING);

	CAMERAMANAGER->setCameraAim(&_rcPlayerCamera);

	_centerX = CAMERAMANAGER->CameraRelativePointX(_absoluteX);
	_centerY = CAMERAMANAGER->CameraRelativePointY(_absoluteY);


	_rcPlayer = RectMakeCenter(_centerX, _centerY, 48, 48);

	_speed = 4.0f;
	_shieldLevel = 0;			// ���� ���� 0;
	_keyPressure = 0;
	_countDelay = 0;
	_countAttack = 0;
	_countReturn = 0;
	_sideWeapon = 2;
	_playerHP = 10;
	_alphaValue = 100;

	_delayEnd = false;
	_isAttack = false;
	_isDamage = false;
	_isDead = false;

	_playerState = NORMAL;
	_playerMovement = DOWN_STOP;

	_playerMotion = KEYANIMANAGER->findAnimation("����(�Ʒ���)(�Ϲ�)");

	//������ ���� ������ ������ �ΰ� �ʱ�ȭ(��ȣ)
	_quickItem = NULL;
	
	return S_OK;
}

void player::release() {

}
void player::update() {

	playerCollisionObject();
	playerObjectAttack();
	playerControl();
	playerMovement();
	playerEnemyAttack();
	playerReturnIdle();
	playerAlpha();
	playerTileCheck();

	deleteRcAttack();

	KEYANIMANAGER->update();

	delay();
}
void player::render() {

	setColorRect(getMemDC(), _rcPlayer, 150, 40, 130);
	if (_isTest) {
		setColorRect(getMemDC(), *_rcAttack, 40, 110, 140);
	}

	_playerBmp->aniAlphaCenterRender(getMemDC(), _centerX, _centerY, _playerMotion,_alphaValue);

	//�������� ���� �Ǿ��ٸ� �׷���(��ȣ)
	//UI �׷����� ������ �� ���ڿ� ���� �׷������� ����
	if (_quickItem != NULL)
		_quickItem->getItemInvenImage()->render(getMemDC(), 645, 10);

	showIntData(getMemDC(), "HP : %d", _playerHP, 10, 10);
}

void player::setupKeyValue() {

	_normalKey.push_back("����(�Ʒ���)(�Ϲ�)");
	_normalKey.push_back("����(������)(�Ϲ�)");
	_normalKey.push_back("����(����)(�Ϲ�)");
	_normalKey.push_back("����(����)(�Ϲ�)");
	_normalKey.push_back("�ȱ�(�Ʒ���)(�Ϲ�)");
	_normalKey.push_back("�ȱ�(������)(�Ϲ�)");
	_normalKey.push_back("�ȱ�(����)(�Ϲ�)");
	_normalKey.push_back("�ȱ�(����)(�Ϲ�)");

	_shieldKey1.push_back("����(�Ʒ���)(����1)");
	_shieldKey1.push_back("����(������)(����1)");
	_shieldKey1.push_back("����(����)(����1)");
	_shieldKey1.push_back("����(����)(����1)");
	_shieldKey1.push_back("�ȱ�(�Ʒ���)(����1)");
	_shieldKey1.push_back("�ȱ�(������)(����1)");
	_shieldKey1.push_back("�ȱ�(����)(����1)");
	_shieldKey1.push_back("�ȱ�(����)(����1)");

	_shieldKey2.push_back("����(�Ʒ���)(����2)");
	_shieldKey2.push_back("����(������)(����2)");
	_shieldKey2.push_back("����(����)(����2)");
	_shieldKey2.push_back("����(����)(����2)");
	_shieldKey2.push_back("�ȱ�(�Ʒ���)(����2)");
	_shieldKey2.push_back("�ȱ�(������)(����2)");
	_shieldKey2.push_back("�ȱ�(����)(����2)");
	_shieldKey2.push_back("�ȱ�(����)(����2)");

	_carryKey.push_back("���ǵ������(�Ʒ���)");
	_carryKey.push_back("���ǵ������(������)");
	_carryKey.push_back("���ǵ������(����)");
	_carryKey.push_back("���ǵ������(����)");
	_carryKey.push_back("���ǵ��ȱ�(�Ʒ���)");
	_carryKey.push_back("���ǵ��ȱ�(������)");
	_carryKey.push_back("���ǵ��ȱ�(����)");
	_carryKey.push_back("���ǵ��ȱ�(����)");


	_mStateKey.insert(pair<PLAYERSTATE, vector<string> >(NORMAL, _normalKey));
	_mStateKey.insert(pair<PLAYERSTATE, vector<string> >(SHIELD1, _shieldKey1));
	_mStateKey.insert(pair<PLAYERSTATE, vector<string> >(SHIELD2, _shieldKey2));
	_mStateKey.insert(pair<PLAYERSTATE, vector<string> >(CARRY, _carryKey));

	int downIdle_N[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("����(�Ʒ���)(�Ϲ�)", "��ũ", downIdle_N, 1, 1, false, 0);

	int rightIdle_N[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("����(������)(�Ϲ�)", "��ũ", rightIdle_N, 1, 1, false, 0);

	int upIdle_N[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("����(����)(�Ϲ�)", "��ũ", upIdle_N, 1, 1, false, 0);

	int leftIdle_N[] = { 3 };
	KEYANIMANAGER->addArrayFrameAnimation("����(����)(�Ϲ�)", "��ũ", leftIdle_N, 1, 1, false, 0);

	int downMove_N[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("�ȱ�(�Ʒ���)(�Ϲ�)", "��ũ", downMove_N, 8, 8, true, 3);

	int rightMove_N[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("�ȱ�(������)(�Ϲ�)", "��ũ", rightMove_N, 8, 8, true, 4);

	int upMove_N[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("�ȱ�(����)(�Ϲ�)", "��ũ", upMove_N, 8, 8, true, 5);

	int leftMove_N[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("�ȱ�(����)(�Ϲ�)", "��ũ", leftMove_N, 8, 8, true, 6);



	int downIdle_S1[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("����(�Ʒ���)(����1)", "��ũ", downIdle_S1, 1, 1, false, 1);

	int rightIdle_S1[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("����(������)(����1)", "��ũ", rightIdle_S1, 1, 1, false, 1);

	int upIdle_S1[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("����(����)(����1)", "��ũ", upIdle_S1, 1, 1, false, 1);

	int leftIdle_S1[] = { 3 };
	KEYANIMANAGER->addArrayFrameAnimation("����(����)(����1)", "��ũ", leftIdle_S1, 1, 1, false, 1);

	int downMove_S1[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("�ȱ�(�Ʒ���)(����1)", "��ũ", downMove_S1, 8, 8, true, 7);

	int rightMove_S1[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("�ȱ�(������)(����1)", "��ũ", rightMove_S1, 8, 8, true, 8);

	int upMove_S1[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("�ȱ�(����)(����1)", "��ũ", upMove_S1, 8, 8, true, 9);

	int leftMove_S1[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("�ȱ�(����)(����1)", "��ũ", leftMove_S1, 8, 8, true, 10);




	int downIdle_S2[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("����(�Ʒ���)(����2)", "��ũ", downIdle_S2, 1, 1, false, 2);

	int rightIdle_S2[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("����(������)(����2)", "��ũ", rightIdle_S2, 1, 1, false, 2);

	int upIdle_S2[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("����(����)(����2)", "��ũ", upIdle_S2, 1, 1, false, 2);

	int leftIdle_S2[] = { 3 };
	KEYANIMANAGER->addArrayFrameAnimation("����(����)(����2)", "��ũ", leftIdle_S2, 1, 1, false, 2);

	int downMove_S2[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("�ȱ�(�Ʒ���)(����2)", "��ũ", downMove_S2, 8, 8, true, 11);

	int rightMove_S2[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("�ȱ�(������)(����2)", "��ũ", rightMove_S2, 8, 8, true, 12);

	int upMove_S2[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("�ȱ�(����)(����2)", "��ũ", upMove_S2, 8, 8, true, 13);

	int leftMove_S2[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("�ȱ�(����)(����2)", "��ũ", leftMove_S2, 8, 8, true, 14);



	int downIdle_C[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("���ǵ������(�Ʒ���)", "��ũ", downIdle_N, 1, 1, false, 20);

	int rightIdle_C[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("���ǵ������(������)", "��ũ", rightIdle_N, 1, 1, false, 20);

	int upIdle_C[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("���ǵ������(����)", "��ũ", upIdle_N, 1, 1, false, 20);

	int leftIdle_C[] = { 3 };
	KEYANIMANAGER->addArrayFrameAnimation("���ǵ������(����)", "��ũ", leftIdle_N, 1, 1, false, 20);

	int downMove_C[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("���ǵ��ȱ�(�Ʒ���)", "��ũ", downMove_N, 6, 8, true, 21);

	int rightMove_C[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("���ǵ��ȱ�(������)", "��ũ", rightMove_N, 6, 8, true, 22);

	int upMove_C[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("���ǵ��ȱ�(����)", "��ũ", upMove_N, 6, 8, true, 23);

	int leftMove_C[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("���ǵ��ȱ�(����)", "��ũ", leftMove_N, 6, 8, true, 24);




	int downGrab[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("���(�Ʒ���)", "��ũ", downGrab, 1, 6, false, 15);

	int rightGrab[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("���(������)", "��ũ", rightGrab, 1, 6, false, 15);

	int upGrab[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("���(����)", "��ũ", upGrab, 1, 6, false, 15);

	int leftGrab[] = { 3 };
	KEYANIMANAGER->addArrayFrameAnimation("���(����)", "��ũ", leftGrab, 1, 6, false, 15);



	int downPush[] = { 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("�б�(�Ʒ���)", "��ũ", downPush, 5, 10, true, 16);

	int rightPush[] = { 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("�б�(������)", "��ũ", rightPush, 5, 10, true, 17);

	int upPush[] = { 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("�б�(����)", "��ũ", upPush, 5, 10, true, 18);

	int leftPush[] = { 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("�б�(����)", "��ũ", leftPush, 5, 10, true, 19);




	int downPowerUp[] = { 4 };
	KEYANIMANAGER->addArrayFrameAnimation("�������(�Ʒ���)", "��ũ", downPowerUp, 1, 12, false, 25);

	int rightPowerUp[] = { 4 };
	KEYANIMANAGER->addArrayFrameAnimation("�������(������)", "��ũ", rightPowerUp, 1, 12, false, 26);

	int upPowerUp[] = { 4 };
	KEYANIMANAGER->addArrayFrameAnimation("�������(����)", "��ũ", upPowerUp, 1, 12, false, 27);

	int leftPowerUp[] = { 4 };
	KEYANIMANAGER->addArrayFrameAnimation("�������(����)", "��ũ", leftPowerUp, 1, 12, false, 28);

	int downAttack[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("Į����(�Ʒ���)", "��ũ", downAttack, 6, 12, false, 25);

	int rightAttack[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("Į����(������)", "��ũ", rightAttack, 6, 12, false, 26);

	int upAttack[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("Į����(����)", "��ũ", upAttack, 6, 12, false, 27);

	int leftAttack[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("Į����(����)", "��ũ", leftAttack, 6, 12, false, 28);



	int downSlash[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("ȸ�����(�Ʒ���)", "��ũ", downSlash, 6, 14, false, 37);

	int rightSlash[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("ȸ�����(������)", "��ũ", rightSlash, 6, 14, false, 39);

	int upSlash[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("ȸ�����(����)", "��ũ", upSlash, 6, 14, false, 38);

	int leftSlash[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("ȸ�����(����)", "��ũ", leftSlash, 6, 14, false, 40);




	int downBoomerang[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("�θ޶�(�Ʒ���)", "��ũ", downBoomerang, 3, 10, false, 29);

	int rightBoomerang[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("�θ޶�(������)", "��ũ", rightBoomerang, 3, 10, false, 30);

	int upBoomerang[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("�θ޶�(����)", "��ũ", upBoomerang, 3, 10, false, 31);

	int leftBoomerang[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("�θ޶�(����)", "��ũ", leftBoomerang, 3, 10, false, 32);


	int downBow[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("Ȱ(�Ʒ���)", "��ũ", downBow, 3, 10, false, 33);

	int rightBow[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("Ȱ(������)", "��ũ", rightBow, 3, 10, false, 34);

	int upBow[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("Ȱ(����)", "��ũ", upBow, 3, 10, false, 35);

	int leftBow[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("Ȱ(����)", "��ũ", leftBow, 3, 10, false, 36);

	int dead[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("����", "��ũ", dead, 10, 10, false, 41);

	int falling[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("����(��������)", "��ũ", dead, 6, 4, false, 42);


	int downDamage[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("����(�Ʒ���)", "��ũ", downDamage, 1, 1, false, 43);

	int rightDamage[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("����(������)", "��ũ", rightDamage, 1, 1, false, 43);

	int upDamage[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("����(����)", "��ũ", upDamage, 1, 1, false, 43);

	int leftDamage[] = { 3 };
	KEYANIMANAGER->addArrayFrameAnimation("����(����)", "��ũ", leftDamage, 1, 1, false, 43);

}

void player::playerControl() {

	if (_playerHP <= 0) return;

	// Ű �з��� 50�� �ƴҶ� ��ũ�� ������ �� ����
	if (_keyPressure != 50) {

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN)) {
			_down = true;
			_isDamage = false;
			_countReturn = 0;
			_playerMovement = DOWN_MOVE;
			_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[4]);
			_playerMotion->start();
			IGMAP->checkMapEvent(_absoluteX / TILESIZE, _absoluteY / TILESIZE, EVENTMAP);
		}

		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) {
			_right = true;
			_isDamage = false;
			_countReturn = 0;
			_playerMovement = RIGHT_MOVE;
			_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[5]);
			_playerMotion->start();
			IGMAP->checkMapEvent(_absoluteX / TILESIZE, _absoluteY / TILESIZE, EVENTMAP);
		}

		if (KEYMANAGER->isOnceKeyDown(VK_UP)) {
			_up = true;
			_isDamage = false;
			_countReturn = 0;
			_playerMovement = UP_MOVE;
			_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[6]);
			_playerMotion->start();
			IGMAP->checkMapEvent(_absoluteX / TILESIZE, _absoluteY / TILESIZE, EVENTMAP);

			IGMAP->checkMoveEvent(_absoluteX / TILESIZE, (_absoluteY + TILESIZE/2)/ TILESIZE, EVENTMOVE);
		}

		if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) {
			_left = true;
			_isDamage = false;
			_countReturn = 0;
			_playerMovement = LEFT_MOVE;
			_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[7]);
			_playerMotion->start();
			IGMAP->checkMapEvent(_absoluteX / TILESIZE, _absoluteY / TILESIZE, EVENTMAP);
		}

		if (KEYMANAGER->isOnceKeyUp(VK_DOWN)) {
			_down = false;
			_isDamage = false;
			_countReturn = 0;
			if (_playerMovement == DOWN_MOVE || _playerMovement == DOWN_STOP) {
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[0]);
				_playerMotion->start();
				_playerMovement = DOWN_STOP;
			}
		}

		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT)) {
			_right = false;
			if (_playerMovement == RIGHT_MOVE || _playerMovement == RIGHT_STOP) {
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[1]);
				_playerMotion->start();
				_playerMovement = RIGHT_STOP;
			}
		}

		if (KEYMANAGER->isOnceKeyUp(VK_UP)) {
			_up = false;
			if (_playerMovement == UP_MOVE || _playerMovement == UP_STOP) {
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[2]);
				_playerMotion->start();
				_playerMovement = UP_STOP;
			}
		}

		if (KEYMANAGER->isOnceKeyUp(VK_LEFT)) {
			_left = false;
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
			_playerMotion = KEYANIMANAGER->findAnimation("���(�Ʒ���)");
			_playerMovement = DOWN_STOP;
			
			break;

		case RIGHT_MOVE: case RIGHT_STOP:
			_playerMotion = KEYANIMANAGER->findAnimation("���(������)");
			_playerMovement = RIGHT_STOP;
			
			break;

		case UP_MOVE: case UP_STOP:
			_playerMotion = KEYANIMANAGER->findAnimation("���(����)");
			
			_playerMovement = UP_STOP;
			break;

		case LEFT_MOVE: case LEFT_STOP:
			_playerMotion = KEYANIMANAGER->findAnimation("���(����)");
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
				_playerMotion = KEYANIMANAGER->findAnimation("���ǵ������(�Ʒ���)");
				_playerState = CARRY;
			}
			else {
				upgradeShield(_shieldLevel);
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[0]);
			}

			break;

		case RIGHT_MOVE: case RIGHT_STOP:
			if (playerCarry()) {
				_playerMotion = KEYANIMANAGER->findAnimation("���ǵ������(������)");
				_playerState = CARRY;
			}
			else {
				upgradeShield(_shieldLevel);
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[1]);
			}

			break;

		case UP_MOVE: case UP_STOP:
			if (playerCarry()) {
				_playerMotion = KEYANIMANAGER->findAnimation("���ǵ������(����)");
				_playerState = CARRY;
			}
			else {
				upgradeShield(_shieldLevel);
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[2]);
			}

			break;

		case LEFT_MOVE: case LEFT_STOP:
			if (playerCarry()) {
				_playerMotion = KEYANIMANAGER->findAnimation("���ǵ������(����)");
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


	if (KEYMANAGER->isOnceKeyDown('X')) {
		playerAttack();
	}


	if (KEYMANAGER->isStayKeyDown('X')) {

		if (carryState()) return;		// ������ ��� ���� ���� ������ �� ����
	
		_keyPressure++;

		switch (_playerMovement)
		{
		case DOWN_MOVE: case DOWN_STOP:
			if (_keyPressure < 50) {
				_playerMotion = KEYANIMANAGER->findAnimation("Į����(�Ʒ���)");
				_playerMotion->onceStart();
			
			}
			else {
				_playerMotion = KEYANIMANAGER->findAnimation("�������(�Ʒ���)");
				_keyPressure = 50;
			}
			_playerMovement = DOWN_STOP;
			break;

		case RIGHT_MOVE: case RIGHT_STOP:
			if (_keyPressure < 50) {
				_playerMotion = KEYANIMANAGER->findAnimation("Į����(������)");
				_playerMotion->onceStart();
			
			}
			else {
				_playerMotion = KEYANIMANAGER->findAnimation("�������(������)");
				_keyPressure = 50;
			}
			_playerMovement = RIGHT_STOP;
			break;

		case UP_MOVE: case UP_STOP:
			if (_keyPressure < 50) {
				_playerMotion = KEYANIMANAGER->findAnimation("Į����(����)");
				_playerMotion->onceStart();
				
			}
			else {
				_playerMotion = KEYANIMANAGER->findAnimation("�������(����)");
				_keyPressure = 50;
			}
			_playerMovement = UP_STOP;
			break;

		case LEFT_MOVE: case LEFT_STOP:
			if (_keyPressure < 50) {
				_playerMotion = KEYANIMANAGER->findAnimation("Į����(����)");
				_playerMotion->onceStart();
			
			}
			else {
				_playerMotion = KEYANIMANAGER->findAnimation("�������(����)");
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
				playerSlashAttack();
				_playerMotion = KEYANIMANAGER->findAnimation("ȸ�����(�Ʒ���)");
				_playerMotion->start();
			
			}
			else {
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[0]);
			}
			_keyPressure = 0;
			break;

		case RIGHT_STOP:
			if (_keyPressure >= 50) {
				playerSlashAttack();
				_playerMotion = KEYANIMANAGER->findAnimation("ȸ�����(������)");
				_playerMotion->start();
				
			}
			else {
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[1]);
			}
			_keyPressure = 0;
			break;

		case UP_STOP:
			if (_keyPressure >= 50) {
				playerSlashAttack();
				_playerMotion = KEYANIMANAGER->findAnimation("ȸ�����(����)");
				_playerMotion->start();
				
			}
			else {
				_playerMotion = KEYANIMANAGER->findAnimation(_mStateKey.find(_playerState)->second[2]);
			}
			_keyPressure = 0;
			break;

		case LEFT_STOP:
			if (_keyPressure >= 50) {
				playerSlashAttack();
				_playerMotion = KEYANIMANAGER->findAnimation("ȸ�����(����)");
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

	_rcPlayerCamera = RectMakeCenter(_absoluteX, _absoluteY, 48, 48);
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

void player::setupCollisionObject(RECT* rcObj, float* centerX, float* centerY, bool isCarry, bool* isFire, bool* isAttack) {
	
	tagObject object;
	object.rc = rcObj;
	object.centerObjX = centerX;
	object.centerObjY = centerY;
	object.isCarry = isCarry;
	object.isFire = isFire;
	object.isAttack = isAttack;
	object.isCollision = true;
	_vObject.push_back(object);

}

void player::playerCollisionObject() {

	for (int i = 0; i < _vObject.size(); ++i) {

		if (!_vObject[i].isCollision) {
			if (*_vObject[i].isFire) continue;
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
					_playerMotion = KEYANIMANAGER->findAnimation("�б�(�Ʒ���)");
					_playerMotion->start();
					_playerMovement = DOWN_STOP;
					break;

				case RIGHT_MOVE:
					_absoluteX -= (temp.right - temp.left) + 1;
					_playerMotion = KEYANIMANAGER->findAnimation("�б�(������)");
					_playerMotion->start();
					_playerMovement = RIGHT_STOP;
					break;

				case UP_MOVE:
					_absoluteY += (temp.bottom - temp.top) + 1;
					_playerMotion = KEYANIMANAGER->findAnimation("�б�(����)");
					_playerMotion->start();
					_playerMovement = UP_STOP;
					break;

				case LEFT_MOVE:
					_absoluteX += (temp.right - temp.left) + 1;
					_playerMotion = KEYANIMANAGER->findAnimation("�б�(����)");
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

		if (!_vObject[i].isCarry) continue;				// �� �� ���� �����̸� continue

		switch (_playerMovement)
		{
		case DOWN_MOVE: case DOWN_STOP:

			if (*_vObject[i].centerObjY - _absoluteY >= 45 && *_vObject[i].centerObjY - _absoluteY <= 55&&
				*_vObject[i].centerObjX-_absoluteX>= -24&& *_vObject[i].centerObjX - _absoluteX <= 24 ) {

				*_vObject[i].centerObjY = _absoluteY - 30;
				*_vObject[i].centerObjX = _absoluteX;
				_vObject[i].isCollision = false;

				ASTARINFO->settoOpen((*_vObject[i].centerObjX) / TILESIZE, (*_vObject[i].centerObjY) / TILESIZE);

				return true;
			}
			break;

		case RIGHT_MOVE: case RIGHT_STOP:

			if (*_vObject[i].centerObjX - _absoluteX >= 45 && *_vObject[i].centerObjX - _absoluteX <= 55 
				&&*_vObject[i].centerObjY - _absoluteY >= -24 && *_vObject[i].centerObjY - _absoluteY <= 24){

				*_vObject[i].centerObjY = _absoluteY - 30;
				*_vObject[i].centerObjX = _absoluteX;
				_vObject[i].isCollision = false;

				ASTARINFO->settoOpen((*_vObject[i].centerObjX) / TILESIZE, (*_vObject[i].centerObjY) / TILESIZE);

				return true;
			}

			break;

		case UP_MOVE: case UP_STOP:

			if (_absoluteY - (*_vObject[i].centerObjY) >= 45 && _absoluteY - (*_vObject[i].centerObjY) <= 55
				&& *_vObject[i].centerObjX - _absoluteX >= -24 && *_vObject[i].centerObjX - _absoluteX <= 24) {

				*_vObject[i].centerObjY = _absoluteY - 30;
				*_vObject[i].centerObjX = _absoluteX;
				_vObject[i].isCollision = false;

				ASTARINFO->settoOpen((*_vObject[i].centerObjX) / TILESIZE, (*_vObject[i].centerObjY) / TILESIZE);

				return true;
			}

			break;

		case LEFT_MOVE: case LEFT_STOP:

			if (_absoluteX - (*_vObject[i].centerObjX) >= 45 && _absoluteX - (*_vObject[i].centerObjX) <= 55&&
				*_vObject[i].centerObjY - _absoluteY >= -24 && *_vObject[i].centerObjY - _absoluteY <= 24) {

				*_vObject[i].centerObjY = _absoluteY - 30;
				*_vObject[i].centerObjX = _absoluteX;
				_vObject[i].isCollision = false;

				ASTARINFO->settoOpen((*_vObject[i].centerObjX) / TILESIZE, (*_vObject[i].centerObjY) / TILESIZE);

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

		*_vObject[i].isFire = true;

		return true;						//������
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

	if (_quickItem == NULL) return;
	switch (_sideWeapon)
	{
	case 1:

		switch (_playerMovement)
		{
		case DOWN_MOVE: case DOWN_STOP:
			if (_down&&_right) {
				_quickItem->useItem(_absoluteX, _absoluteY, 5);
			}
			else if (_down&&_left) {
				_quickItem->useItem(_absoluteX, _absoluteY, 7);
			}
			else if (_down) {
				_quickItem->useItem(_absoluteX, _absoluteY, 6);
			}
			_quickItem->useItem(_absoluteX, _absoluteY, 3);
			_playerMotion = KEYANIMANAGER->findAnimation("�θ޶�(�Ʒ���)");
			_playerMotion->start();
			_playerMovement = DOWN_STOP;
			break;

		case RIGHT_MOVE: case RIGHT_STOP:
			if (_right&&_up) {
				_quickItem->useItem(_absoluteX, _absoluteY, 3);
			}
			else if (_right&&_down) {
				_quickItem->useItem(_absoluteX, _absoluteY, 5);
			}
			else if (_right) {
				_quickItem->useItem(_absoluteX, _absoluteY, 4);
			}
			_playerMotion = KEYANIMANAGER->findAnimation("�θ޶�(������)");
			_playerMotion->start();
			_playerMovement = RIGHT_STOP;
			break;

		case UP_MOVE: case UP_STOP:
			if (_up&&_left) {
				_quickItem->useItem(_absoluteX, _absoluteY, 1);
			}
			else if (_up&&_right) {
				_quickItem->useItem(_absoluteX, _absoluteY, 3);
			}
			else if (_up) {
				_quickItem->useItem(_absoluteX, _absoluteY, 2);
			}
			_playerMotion = KEYANIMANAGER->findAnimation("�θ޶�(����)");
			_playerMotion->start();
			_playerMovement = UP_STOP;
			break;

		case LEFT_MOVE: case LEFT_STOP:
			if (_left&&_down) {
				_quickItem->useItem(_absoluteX, _absoluteY, 7);
			}
			else if (_left&&_up) {
				_quickItem->useItem(_absoluteX, _absoluteY, 1);
			}
			else if (_left) {
				_quickItem->useItem(_absoluteX, _absoluteY, 0);
			}
			_playerMotion = KEYANIMANAGER->findAnimation("�θ޶�(����)");
			_playerMotion->start();
			_playerMovement = LEFT_STOP;
			break;
		}

		break;

	case 2:

		switch (_playerMovement)
		{
		case DOWN_MOVE: case DOWN_STOP:
			_quickItem->useItem(_absoluteX, _absoluteY, 3);
			_playerMotion = KEYANIMANAGER->findAnimation("Ȱ(�Ʒ���)");
			_playerMotion->start();
			break;

		case RIGHT_MOVE: case RIGHT_STOP:
			_quickItem->useItem(_absoluteX, _absoluteY, 2);
			_playerMotion = KEYANIMANAGER->findAnimation("Ȱ(������)");
			_playerMotion->start();
			break;

		case UP_MOVE: case UP_STOP:
			_quickItem->useItem(_absoluteX, _absoluteY, 1);
			_playerMotion = KEYANIMANAGER->findAnimation("Ȱ(����)");
			_playerMotion->start();
			break;

		case LEFT_MOVE: case LEFT_STOP:
			_quickItem->useItem(_absoluteX, _absoluteY, 0);
			_playerMotion = KEYANIMANAGER->findAnimation("Ȱ(����)");
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

	if (_isDead) return;

	if (_playerHP <= 0) {
		_playerMotion = KEYANIMANAGER->findAnimation("����");
		_playerMotion->onceStart();
		_isDead = true;
	}

}

void player::playerAttack() {

	if (_keyPressure < 50) {
		RECT* rcAttack;
		rcAttack = new RECT;
		_countAttack = 0;
		switch (_playerMovement)
		{
		case DOWN_MOVE: case DOWN_STOP:
			*rcAttack = RectMakeCenter(_centerX, _centerY + 50, 50, 50);
			_rcAttack = rcAttack;
			break;

		case RIGHT_MOVE: case RIGHT_STOP:
			*rcAttack = RectMakeCenter(_centerX + 50, _centerY, 50, 50);
			_rcAttack = rcAttack;
			break;

		case UP_MOVE: case UP_STOP:
			*rcAttack = RectMakeCenter(_centerX, _centerY - 50, 50, 50);
			_rcAttack = rcAttack;
			break;

		case LEFT_MOVE: case LEFT_STOP:
			*rcAttack = RectMakeCenter(_centerX - 50, _centerY, 50, 50);
			_rcAttack = rcAttack;
			break;

		default:
			break;
		}

		_isAttack = true;
		_isTest = true;

	}
}

void player::playerSlashAttack() {
	
	RECT* rcAttack;
	rcAttack = new RECT;
	_countAttack = 0;
	*rcAttack = RectMakeCenter(_centerX, _centerY, 100, 100);
	_rcAttack = rcAttack;
	_isAttack = true;
	_isTest = true;

}

void player::deleteRcAttack() {

	if (_isAttack) {
		_countAttack++;

		if (_countAttack % 12 == 0) {
			SAFE_DELETE(_rcAttack);
			_countAttack = 0;
			_isAttack = false;
			_isTest = false;
		}
	}
}

void player::playerObjectAttack() {

	if (_isAttack) {

		for (int i = 0; i < _vObject.size(); ++i) {
			
			if (!_vObject[i].isCarry) continue;
			
			RECT temp;
			if (IntersectRect(&temp, &(*_vObject[i].rc), &(*_rcAttack))) {
				*_vObject[i].isAttack = true;
				break;
			}

		}

	}

}

void player::playerEnemyAttack() {
	
	if (_playerHP <= 0) return;

	if (_isAttack) {
		for (int i = 0; i < _em->getVEnemy().size(); ++i) {

			RECT temp;
			if (IntersectRect(&temp, &_em->getVEnemy()[i]->getRcBodyEnemy(), &*_rcAttack)) {
				_em->getVEnemy()[i]->backmove(_absoluteX, _absoluteY);
				_em->getVEnemy()[i]->setCrrentHP(1);
				SAFE_DELETE(_rcAttack);
				_countAttack = 0;
				_isAttack = false;
				_isTest = false;
				break;
			}
		}
	}

	for (int i = 0; i < _em->getVEnemy().size(); ++i) {
		RECT temp;
		if (IntersectRect(&temp, &_em->getVEnemy()[i]->getRcBodyEnemy(), &_rcPlayer)) {
			playerDamage();
			_playerHP--;

			if (_playerHP <= 0) playerDead();

			break;
		}
	}

}

void player::playerDamage() {


	switch (_playerMovement)
	{
	case DOWN_MOVE: case DOWN_STOP:
		_playerMotion = KEYANIMANAGER->findAnimation("����(�Ʒ���)");
		_playerMovement = DOWN_STOP;
		_absoluteY -= 35;
		_isDamage = true;
		break;

	case RIGHT_MOVE: case RIGHT_STOP:
		_playerMotion = KEYANIMANAGER->findAnimation("����(������)");
		_playerMovement = RIGHT_STOP;
		_absoluteX -= 35;
		_isDamage = true;
		break;

	case UP_MOVE: case UP_STOP:
		_playerMotion = KEYANIMANAGER->findAnimation("����(����)");
		_playerMovement = UP_STOP;
		_absoluteY += 35;
		_isDamage = true;
		break;

	case LEFT_MOVE: case LEFT_STOP:
		_playerMotion = KEYANIMANAGER->findAnimation("����(����)");
		_playerMovement = LEFT_STOP;
		_absoluteX += 35;
		_isDamage = true;
		break;

	default:
		break;
	}

}

void player::playerReturnIdle() {
	
	if (_playerHP <= 0) return;

	if (_isDamage)
	{
		_countReturn++;

		if (_countReturn % 15 == 0) {

			switch (_playerMovement)
			{
			case DOWN_MOVE: case DOWN_STOP:
				_playerMotion = KEYANIMANAGER->findAnimation("����(�Ʒ���)(�Ϲ�)");
				_playerMovement = DOWN_STOP;
				break;

			case RIGHT_MOVE: case RIGHT_STOP:
				_playerMotion = KEYANIMANAGER->findAnimation("����(������)(�Ϲ�)");
				_playerMovement = RIGHT_STOP;
				break;

			case UP_MOVE: case UP_STOP:
				_playerMotion = KEYANIMANAGER->findAnimation("����(����)(�Ϲ�)");
				_playerMovement = UP_STOP;
				break;

			case LEFT_MOVE: case LEFT_STOP:
				_playerMotion = KEYANIMANAGER->findAnimation("����(����)(�Ϲ�)");
				_playerMovement = LEFT_STOP;
				break;

			default:
				break;
			}

			_countReturn = 0;
			_isDamage = false;
		}
	}

}

void player::playerAlpha() {
	if (_isDamage) {
		_countAlpha++;

		if (_countAlpha < 5) {
			_alphaValue = 100;
		}
		else if (_countAlpha >= 5 && _countAlpha < 10) {
			_alphaValue = 255;
		}
		else if (_countAlpha >= 10 && _countAlpha < 15) {
			_alphaValue = 100;
		}
		else {
			_alphaValue = 255;
		}
	}
	else {
		_alphaValue = 255;
		_countAlpha = 0;
	}
}

void player::playerTileCheck() {

	switch (_playerMovement)
	{
	case DOWN_MOVE: case DOWN_STOP:
		if(!ASTARINFO->canGo(_rcPlayerCamera.left, _rcPlayerCamera.top+50)
			|| !ASTARINFO->canGo(_rcPlayerCamera.left+25, _rcPlayerCamera.top+50)
			|| !ASTARINFO->canGo(_rcPlayerCamera.left + 50, _rcPlayerCamera.top+50)) _absoluteY -= _speed;
		break;

	case RIGHT_MOVE: case RIGHT_STOP:
		if (!ASTARINFO->canGo(_rcPlayerCamera.left+50, _rcPlayerCamera.top)
			|| !ASTARINFO->canGo(_rcPlayerCamera.left+50, _rcPlayerCamera.top+25)
			|| !ASTARINFO->canGo(_rcPlayerCamera.left+50, _rcPlayerCamera.top+50)) _absoluteX -= _speed;
		break;

	case UP_MOVE: case UP_STOP:
		if (!ASTARINFO->canGo(_rcPlayerCamera.left, _rcPlayerCamera.top)
			|| !ASTARINFO->canGo(_rcPlayerCamera.left+25, _rcPlayerCamera.top)
			|| !ASTARINFO->canGo(_rcPlayerCamera.left+50, _rcPlayerCamera.top)) _absoluteY += _speed;
		break;

	case LEFT_MOVE: case LEFT_STOP:
		if (!ASTARINFO->canGo(_rcPlayerCamera.left, _rcPlayerCamera.top)
			|| !ASTARINFO->canGo(_rcPlayerCamera.left, _rcPlayerCamera.top + 25)
			|| !ASTARINFO->canGo(_rcPlayerCamera.left, _rcPlayerCamera.top + 50)) _absoluteX += _speed;
		break;

	default:
		break;
	}

}