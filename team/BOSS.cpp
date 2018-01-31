#include "stdafx.h"
#include "BOSS.h"


BOSS::BOSS()
{
}


BOSS::~BOSS()
{
}

HRESULT BOSS::init(POINT pos)
{
	_Image = IMAGEMANAGER->addFrameImage("점프", "./image/Monster/변신점프기사.bmp", 0, 0, 1000, 636, 10, 3, true, RGB(255, 0, 255));

	//for (int i = 0; i < _vBullet.size(); ++i)
	//{
	//	_vBullet[i]
	//}
	for (int i = 0; i < _vboss.size(); ++i)
	{
		_vboss[i].rc = RectMakeCenter(pos.x, pos.y, _Image->getFrameWidth(), _Image->getFrameHeight());

		_vboss[i].x = pos.x;
		_vboss[i].y = pos.y;

		_vboss[i].angle = PI / 3 * i;
	}

	

	//_x = _x- cosf(_angle) * (_image->getFrameWidth());
	//_y = _y - (-sinf(_angle) * (_image->getFrameHeight()));


	int arrStand[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("BossStand", "점프", arrStand, 1, 2, false);

	int arrMove[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("BossMove", "점프", arrMove, 10, 25, true);

	int arrHit[] = { 10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("BossHit", "점프", arrHit, 8, 15, false, bossHit, this);

	int arrAlone[] = { 20,21,22,23,24,25,26,27,28,29 };
	KEYANIMANAGER->addArrayFrameAnimation("BossAlone", "점프", arrAlone, 10, 10, true);



	_direction = ENEMY_STAND;
	_animation = KEYANIMANAGER->findAnimation("BossStand");


	_patternNum = 0;

	_d = 180;

	_count = 0;
	return S_OK;
}

void BOSS::draw()
{
	for (int i = 0; i < _vboss.size(); ++i)
	{
		_Image->aniCenterRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_vboss[i].x), CAMERAMANAGER->CameraRelativePointY(_vboss[i].y), _animation);
	}
}



void BOSS::move(player * player)
{
	_count++;

	if (_count == 100)
	{
		_patternNum++;
		_direction = ENEMY_MOVE;
		_animation = KEYANIMANAGER->findAnimation("BossMove");
		_animation->start();
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
			if (_vboss[i].x >= 300 + _d * cosf(_vboss[i].angle))
			{
				_vboss[i].x -= 3;
			}
			else if (_vboss[i].x <= 300 + _d * cosf(_vboss[i].angle))
			{
				_vboss[i].x += 3;
			}

			if (_vboss[i].y >= 300 + _d * (-sinf(_vboss[i].angle)))
			{
				_vboss[i].y -= 3;
			}
			else if (_vboss[i].y <= 300 + _d * (-sinf(_vboss[i].angle)))
			{
				_vboss[i].y += 3;
			}
		}
		break;
	case CIRCLE:
		for (int i = 0; i < _vboss.size(); ++i)
		{
			_vboss[i].angle -= 0.04f;

			_vboss[i].x = 300 + _d * cosf(_vboss[i].angle);
			_vboss[i].y = 300 + _d * (-sinf(_vboss[i].angle));
		}
		break;
	case LITTELCIRCLE:
		for (int i = 0; i < _vboss.size(); ++i)
		{
			if (_d >= 120)_d--;

			_vboss[i].angle -= 0.04f;

			_vboss[i].x = 300 + _d * cosf(_vboss[i].angle);
			_vboss[i].y = 300 + _d * (-sinf(_vboss[i].angle));
		}
		break;
	case RECIRLE:
		if (_d <= 180)_d++;
		for (int i = 0; i < _vboss.size(); ++i)
		{
			if (_vboss[i].x >= 300 + _d * cosf(_vboss[i].angle))
			{
				_vboss[i].x -= 3;
			}
			else if (_vboss[i].x <= 300 + _d * cosf(_vboss[i].angle))
			{
				_vboss[i].x += 3;
			}

			if (_vboss[i].y >= 300 + _d * (-sinf(_vboss[i].angle)))
			{
				_vboss[i].y -= 3;
			}
			else if (_vboss[i].y <= 300 + _d * (-sinf(_vboss[i].angle)))
			{
				_vboss[i].y += 3;
			}

			_vboss[i].angle -= 0.04f;

			_vboss[i].x = 300 + _d * cosf(_vboss[i].angle);
			_vboss[i].y= 300 + _d * (-sinf(_vboss[i].angle));
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
		_direction = ENEMY_ALONE;
		_animation = KEYANIMANAGER->findAnimation("BossAlone");

		break;
	}
}

void BOSS::bossHit(void * obj)
{
	BOSS* k = (BOSS*)obj;

	k->setKnightDirection(ENEMY_MOVE);
	k->setKnightMotion(KEYANIMANAGER->findAnimation("BossMove"));
	k->getKnightMotion()->start();
}



