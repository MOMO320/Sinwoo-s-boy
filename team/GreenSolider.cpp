#include "stdafx.h"
#include "GreenSolider.h"


GreenSolider::GreenSolider()
{
}


GreenSolider::~GreenSolider()
{
}

HRESULT GreenSolider::init()
{
	_Image = IMAGEMANAGER->addFrameImage("녹색병사", "./image/Monster/GreenSoldier.bmp", 900, 79, 16, 1, true, RGB(255, 0, 255));
	_ImageRc = RectMakeCenter(200,200, 50, _Image->getFrameHeight());
	_animation = new animation;
	_animation->init(_Image->getWidth(), _Image->getHeight(), _Image->getFrameWidth(), _Image->getFrameHeight());
	patrolX = 200;
	patrolY = 200;
	_x = _ImageRc.left + ((_ImageRc.right - _ImageRc.left) / 2);
	_y = _ImageRc.top + ((_ImageRc.bottom - _ImageRc.top) / 2);
	_DetectRc = RectMake(0, 0, 0, 0);
	
	_edirection = EDIRECTION_LEFT;
	_eCondistion = ECondision_Patrol;
	_MAXHP = _CrrentHP = 1;
	_AtkPoint = 1;
	_EnemySpeed = 50;
	NomalCount = 0;
	_isDeath = false;
	_animation->start();
	_animation->setFPS(1);
	frameCount = 4;
	
	return S_OK;
}

void GreenSolider::draw()
{
	_Image->aniCenterRender(getMemDC(), _x, _y, _animation);
	Rectangle(getMemDC(), _DetectRc.left, _DetectRc.top, _DetectRc.right, _DetectRc.bottom);

}

void GreenSolider::aniArri()
{
	if (_eCondistion == ECondision_Patrol)
	{
		switch (_edirection)
		{
		case EDIRECTION_LEFT:
		{
			int arrAni[] = { 8, 9, 10, 11 };
			_animation->setPlayFrame(arrAni, 4, true);
		}
		break;
		case EDIRECTION_UP:
		{
			int arrAni[] = { 12, 13, 14, 15 };
			_animation->setPlayFrame(arrAni, 4, true);
		}
		break;
		case EDIRECTION_RIGHT:
		{
			int arrAni[] = { 4, 5, 6, 7 };
			_animation->setPlayFrame(arrAni, 4, true);
		}
		break;
		case EDIRECTION_DOWN:
		{
			int arrAni[] = { 0, 1, 2, 3 };
			_animation->setPlayFrame(arrAni, 4, true);
		}
		break;
		}
	}
	else if (_eCondistion == ECondision_Detect)
	{
		
		switch (_edirection)
		{
		case EDIRECTION_LEFT:
		{

			int arrAni[] = { 8, 9 };
			_animation->setPlayFrame(arrAni, 2, true);

			_animation->onceStart();
		}
		break;
		case EDIRECTION_UP:
		{
			int arrAni[] = { 12, 13 };
			_animation->setPlayFrame(arrAni, 2, true);
		}
		break;
		case EDIRECTION_RIGHT:
		{
			int arrAni[] = { 4, 5 };
			_animation->setPlayFrame(arrAni, 2, true);
		}
		break;
		case EDIRECTION_DOWN:
		{
			int arrAni[] = { 0, 1 };
			_animation->setPlayFrame(arrAni, 2, true);
		}
		break;
		}
	}
}

void GreenSolider::move()
{
	float moveSpeed = TIMEMANAGER->getElapsedTime() *_EnemySpeed;
	if (_eCondistion == ECondision_Patrol)
	{
		if (!isright)
		{
			_edirection = EDIRECTION_LEFT;
			_x -= moveSpeed;
			if (_x < WINSIZEX / 2 - 200) isright = true;
		}
		else
		{
			_edirection = EDIRECTION_RIGHT;
			_x += moveSpeed;
			if (_x > WINSIZEX / 2 + 200) isright = false;
		}
	}
	else
	{
		if (_eCondistion == ECondision_Detect)
		{
			float moveSpeed = TIMEMANAGER->getElapsedTime() *_EnemySpeed;
			_x += cosf(getAngle(_x, _y, _ptMouse.x, _ptMouse.y /*, _x, _y*/)) * moveSpeed*1.5;
			_y += -sinf(getAngle(_x, _y, _ptMouse.x, _ptMouse.y /*, _x, _y*/)) * moveSpeed*1.5;
		}
		else if (_eCondistion == ECondision_BackPatrol)
		{
			float moveSpeed = TIMEMANAGER->getElapsedTime() *_EnemySpeed;
			_x += cosf(getAngle(_x, _y, _x, patrolY /*, _x, _y*/)) * moveSpeed;
			_y += -sinf(getAngle(_x, _y, _x, patrolY /*, _x, _y*/)) * moveSpeed;

		}
	}
	Pattern();
}

void GreenSolider::Pattern()
{
	_DefRc = RectMakeCenter(_x, _y, 40, 50);


	NomalCount++;

	if (NomalCount % 24 == 0) {
		frameCount--;
		NomalCount = 0;
	}

	if (frameCount <= -1)frameCount = 4;

	
	if (_eCondistion == ECondision_Patrol)
	{
		switch (frameCount)
		{	//4번째
			case 0:
			{
				switch (_edirection)
				{
				case EDIRECTION_LEFT:
					//업
					_DetectRc = RectMake(_x - 25, _y - 250, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
					break;
				case EDIRECTION_UP:
					//오른쪽
					_DetectRc = RectMake(_x + 50, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
					break;
				case EDIRECTION_RIGHT:
					//다운
					_DetectRc = RectMake(_x - 25, _y + 30, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
					break;
				case EDIRECTION_DOWN:
					//왼쪽
					_DetectRc = RectMake(_x - 250, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
					break;
				}
			}
			break;
			//3번쨰
			case 1:
			{
				switch (_edirection)
				{
				case EDIRECTION_LEFT:
					//다운
					_DetectRc = RectMake(_x - 25, _y + 35, Patroltile * 3, Patroltile * 4);  //타일 사이즈 만큼 조정예정
					break;
				case EDIRECTION_UP:
					//왼쪽
					_DetectRc = RectMake(_x - 250, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
					break;
				case EDIRECTION_RIGHT:
					//업
					_DetectRc = RectMake(_x - 25, _y - 250, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
					break;
				case EDIRECTION_DOWN:
					//오른쪽
					_DetectRc = RectMake(_x + 50, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
					break;
				default:
					break;
				}

			}
			break;
			//2번쨰
			case 2:
			{

				switch (_edirection)
				{
				case EDIRECTION_LEFT:
				{
					_DetectRc = RectMake(_x - 250, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
				}
				break;
				case EDIRECTION_UP:
				{
					_DetectRc = RectMake(_x - 25, _y - 250, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
				}
				break;
				case EDIRECTION_RIGHT:
				{
					_DetectRc = RectMake(_x + 50, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
				}
				break;
				case EDIRECTION_DOWN:
				{
					_DetectRc = RectMake(_x - 25, _y + 30, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정 
				}
				break;
				}
			}
			break;

			//1번쨰
			case 3:
			{
				switch (_edirection)
				{
				case EDIRECTION_LEFT:
				{
					_DetectRc = RectMake(_x - 250, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
				}
				break;
				case EDIRECTION_UP:
				{
					_DetectRc = RectMake(_x - 25, _y - 250, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
				}
				break;
				case EDIRECTION_RIGHT:
				{
					_DetectRc = RectMake(_x + 50, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
				}
				break;
				case EDIRECTION_DOWN:
				{
					_DetectRc = RectMake(_x - 25, _y + 30, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
				}
				break;
				}
			}
			break;
		}
	}
	else
	{
		if (_eCondistion == ECondision_Detect)
		{
			//_DetectRc = RectMake(0, 0, 0, 0);
			_Aggro++;
			if (_ptMouse.x > _x && _ptMouse.y > _y)
			{
				_edirection = EDIRECTION_RIGHT;
				_DetectRc = RectMake(_x + 50, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
																						//_animation->stop();
			}
			if (_ptMouse.x > _x && _ptMouse.y < _y)
			{
				_edirection = EDIRECTION_UP; //_animation->stop();
				_DetectRc = RectMake(_x - 25, _y - 250, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
			}
			if (_ptMouse.x < _x && _ptMouse.y > _y)
			{
				_edirection = EDIRECTION_DOWN; //_animation->stop();
				_DetectRc = RectMake(_x - 25, _y + 30, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정 
			}
			if (_ptMouse.x < _x && _ptMouse.y < _y)
			{
				_edirection = EDIRECTION_LEFT; //_animation->stop();
				_DetectRc = RectMake(_x - 250, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
			}
			if (_Aggro < 350)
			{

			}
			else if (_Aggro > 350)
			{
				/*
				어택!
				*/
				_Aggro = 0;
			}
		}
	}
	RECT temp;
	if (IntersectRect(&temp, &_DetectRc, &RectMake(_ptMouse.x, _ptMouse.y, 50, 50)))
	{
		_animation->stop();
		setECondistion(ECondision_Detect);
		_animation->onceStart();
		//setAggro(50);
	}
	else
	{
		if (_y > patrolY)	setECondistion(ECondision_BackPatrol);
		else setECondistion(ECondision_Patrol);
		//setAggro(0);
	}

}


