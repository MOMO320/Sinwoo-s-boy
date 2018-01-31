#include "stdafx.h"
#include "BOSS.h"
#include "player.h"


BOSS::BOSS()
{
}


BOSS::~BOSS()
{
}

HRESULT BOSS::init(POINT pos)
{
	_Image = IMAGEMANAGER->addFrameImage("점프", "./image/Monster/변신점프기사.bmp", 0, 0, 1000, 636, 10, 3, true, RGB(255, 0, 255));


	int arrStand[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("BossStand", "점프", arrStand, 1, 2, false);

	int arrMove[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("BossMove", "점프", arrMove, 10, 25, true);

	int arrHit[] = { 10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("BossHit", "점프", arrHit, 8, 15, false, [&](int a)mutable->void { this->bossHit(a); });

	int arrAlone[] = { 20,21,22,23,24,25,26,27,28,29 };
	KEYANIMANAGER->addArrayFrameAnimation("BossAlone", "점프", arrAlone, 10, 10, true);





	initP.x = pos.x;
	initP.y = pos.y;
	//for (int i = 0; i < _vBullet.size(); ++i)
	//{
	//	_vBullet[i]
	//}
	for (int i = 0; i < 6; ++i)
	{
		tagBoss tempBoss;

		tempBoss.rc = RectMakeCenter(pos.x, pos.y, _Image->getFrameWidth(), _Image->getFrameHeight());

		if (i < 3)
		{
			tempBoss.x = pos.x;
			tempBoss.y = pos.y;
		}
		else if (i >= 3)
		{
			tempBoss.x = pos.x;
			tempBoss.y = pos.y;
		}

		tempBoss.cx = tempBoss.x = pos.x;
		tempBoss.cy = tempBoss.y = pos.y;

		tempBoss.angle = PI / 3 * i;

		tempBoss.bossdirection = ENEMY_STAND;
		tempBoss.animation = KEYANIMANAGER->findAnimation("BossStand");

		_vboss.push_back(tempBoss);
	}

	_MAXHP = _CrrentHP = 5;

	//_x = _x- cosf(_angle) * (_image->getFrameWidth());
	//_y = _y - (-sinf(_angle) * (_image->getFrameHeight()));



	_direction = ENEMY_STAND;



	_patternNum = 0;

	_d = 180;

	_count = 0;
	return S_OK;
}

void BOSS::draw()
{
	for (int i = 0; i < _vboss.size(); ++i)
	{
		_Image->aniCenterRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_vboss[i].cx), CAMERAMANAGER->CameraRelativePointY(_vboss[i].cy), _vboss[i].animation);
	}
}



void BOSS::move(player * player)
{
	_count++;

	if (_count == 100)
	{
		_patternNum++;
		for (int i = 0; i < _vboss.size(); ++i)
		{
			_vboss[i].bossdirection = ENEMY_MOVE;
			_vboss[i].animation = KEYANIMANAGER->findAnimation("BossMove");
			_vboss[i].animation->start();
		}
	}
	else if (_count == 300)
	{
		_patternNum++;
	}
	else if (_count == 600)
	{
		_patternNum++;
	}
	else if (_count == 900)
	{
		_patternNum++;
	}
	else if (_count == 1200)
	{
		_patternNum++;
	}
	else if (_count == 1500)
	{
		_patternNum++;

	}
	else if (_count == 1800 && _patternNum == 6)
	{
		_patternNum = 1;
		_count = 100;
	}
	if (KEYMANAGER->isOnceKeyDown('K'))
	{
		int i = RND->getInt(6);

		_vboss[i].bossdirection = ENEMY_HIT;
		_vboss[i].animation = KEYANIMANAGER->findAnimation("BossHit", i);
		_vboss[i].animation->start();

		_vboss[i].cy -= 100;
		_vboss[i].rc = RectMakeCenter(_vboss[i].cx, _vboss[i].cy, _Image->getFrameWidth(), _Image->getFrameHeight());


	}
	recycle();
	//_vboss[i].rc = RectMakeCenter(_vboss[i].cx, _vboss[i].cy, _Image->getFrameWidth(), _Image->getFrameHeight());
	//}

	Pattern(player);



}

void BOSS::Pattern(player * player)
{
	switch (_patternNum)
	{
	case STAND:
		//setTankPosition();
		break;
	case CIRCLESTAND:
		for (int i = 0; i < _vboss.size(); ++i)
		{
			if (_vboss[i].x >= initP.x + _d * cosf(_vboss[i].angle))
			{
				_vboss[i].x -= 3;
			}
			else if (_vboss[i].x <= initP.x + _d * cosf(_vboss[i].angle))
			{
				_vboss[i].x += 3;
			}

			if (_vboss[i].y >= initP.y + _d * (-sinf(_vboss[i].angle)))
			{
				_vboss[i].y -= 3;
			}
			else if (_vboss[i].y <= initP.y + _d * (-sinf(_vboss[i].angle)))
			{
				_vboss[i].y += 3;
			}
		}
		break;
	case CIRCLE:
		for (int i = 0; i < _vboss.size(); ++i)
		{
			_vboss[i].angle -= 0.04f;

			_vboss[i].x = initP.x + _d * cosf(_vboss[i].angle);
			_vboss[i].y = initP.y + _d * (-sinf(_vboss[i].angle));
		}
		break;
	case LITTELCIRCLE:
		for (int i = 0; i < _vboss.size(); ++i)
		{
			if (_d >= 120)_d--;

			_vboss[i].angle -= 0.04f;

			_vboss[i].x = initP.x + _d * cosf(_vboss[i].angle);
			_vboss[i].y = initP.y + _d * (-sinf(_vboss[i].angle));
		}
		break;
	case RECIRLE:
		if (_d <= 180)_d++;
		for (int i = 0; i < _vboss.size(); ++i)
		{
			if (_vboss[i].x >= initP.x + _d * cosf(_vboss[i].angle))
			{
				_vboss[i].x -= 3;
			}
			else if (_vboss[i].x <= initP.x + _d * cosf(_vboss[i].angle))
			{
				_vboss[i].x += 3;
			}

			if (_vboss[i].y >= initP.y + _d * (-sinf(_vboss[i].angle)))
			{
				_vboss[i].y -= 3;
			}
			else if (_vboss[i].y <= initP.y + _d * (-sinf(_vboss[i].angle)))
			{
				_vboss[i].y += 3;
			}

			_vboss[i].angle -= 0.04f;

			_vboss[i].x = initP.x + _d * cosf(_vboss[i].angle);
			_vboss[i].y = initP.y + _d * (-sinf(_vboss[i].angle));
		}
		break;
	case LINESTAND:
		for (int i = 0; i < _vboss.size(); ++i)
		{

			if (_vboss[i].x >= 100 * i)
			{
				_vboss[i].x -= 3;
			}
			else if (_vboss[i].x <= 100 * i)
			{
				_vboss[i].x += 3;
			}
			if (_vboss[i].y >= 50)
			{
				_vboss[i].y -= 2;
			}
		}
		break;
	case LINE:
		for (int i = 0; i < _vboss.size(); ++i)
		{
			if (_vboss[i].y >= 30 && _vboss[i].y <= 500)
			{
				_vboss[i].y += 2;
			}
		}
		break;
	case ALONE:
		for (int i = 0; i < _vboss.size(); ++i)
		{
			_vboss[i].bossdirection = ENEMY_ALONE;
			_vboss[i].animation = KEYANIMANAGER->findAnimation("BossAlone");
			_vboss[i].animation->start();
		}
		break;
	}
}

void BOSS::recycle()
{
	for (int i = 0; i < _vboss.size(); ++i)
	{
		if (_vboss[i].cx != _vboss[i].x || _vboss[i].cy != _vboss[i].y)
		{
			float theta, distance;

			theta = getAngle(_vboss[i].cx, _vboss[i].cy, _vboss[i].x, _vboss[i].y);
			distance = getDistance(_vboss[i].cx, _vboss[i].cy, _vboss[i].x, _vboss[i].y);

			_vboss[i].cx += cosf(theta)*(3);
			_vboss[i].cy += -sinf(theta)*(3);

			_vboss[i].rc = RectMakeCenter(_vboss[i].cx, _vboss[i].cy, _Image->getFrameWidth(), _Image->getFrameHeight());
		}
	}

}

//void BOSS::backmove(int PlayerX, int PlayerY)
//{
//	for (int i = 0; i < _vboss.size(); ++i)
//	{
//		float elapsedTime = TIMEMANAGER->getElapsedTime();
//		float moveSpeed = elapsedTime * _EnemySpeed;
//		_vboss[i].bossdirection = ENEMY_HIT;
//		if (_vboss[i].bossdirection = ENEMY_HIT)
//		{
//			_x += cosf(getAngle(PlayerX, PlayerY, _x, _y))  * (moveSpeed * 80);
//			_y += -sinf(getAngle(PlayerX, PlayerY, _x, _y)) * (moveSpeed * 80);
//			_vboss[i].animation = KEYANIMANAGER->findAnimation("BossHit", i);
//			_vboss[i].animation->start();
//		}
//
//		//_vboss[i].cy -= 100;
//		_vboss[i].rc = RectMakeCenter(_vboss[i].cx, _vboss[i].cy, _Image->getFrameWidth(), _Image->getFrameHeight());
//	}
//
//}

void BOSS::bossHit(int i)
{

	_vboss[i].bossdirection = ENEMY_MOVE;
	_vboss[i].animation = KEYANIMANAGER->findAnimation("BossMove");
	_vboss[i].animation->start();
}

void BOSS::collision(player * player)
{
	RECT temp;
	for (int i = 0; i < _vboss.size(); ++i)
	{
		/*if (IntersectRect(&temp, &_DetectRc, &player->getPlayerRC()))
		{
		_eCondistion = ECondision_Detect;
		}
		else
		{
		if (_eCondistion == ECondision_Detect)
		{
		_eCondistion = ECondision_BackPatrol;
		}
		else if (isback && _eCondistion == ECondision_BackPatrol)
		{
		_eCondistion = ECondision_Patrol;
		}
		}*/
		//if (IntersectRect(&temp, &_vboss[i].rc, &player->getPlayerRC()))
		//{
		//
		//}

	}
}