#include "stdafx.h"
#include "BlueSolider.h"


BlueSolider::BlueSolider()
{
}


BlueSolider::~BlueSolider()
{

}

HRESULT BlueSolider::init()
{
	_Image = IMAGEMANAGER->addFrameImage("파란병사", "./image/Monster/BlueSoldier.bmp", 1112, 100, 12, 1, true, RGB(255, 0, 255));
	_ImageRc = RectMakeCenter(200, 400, 50, _Image->getFrameHeight());
	_animation = new animation;
	_animation->init(_Image->getWidth(), _Image->getHeight(), _Image->getFrameWidth(), _Image->getFrameHeight());
	patrolX = 200;
	patrolY =200;
	_x = _ImageRc.left + ((_ImageRc.right - _ImageRc.left) / 2);
	_y = _ImageRc.top + ((_ImageRc.bottom - _ImageRc.top) / 2);
	_DetectRc = RectMake(0, 0, 0, 0);

	_edirection = EDIRECTION_LEFT;
	_eCondistion = ECondision_Patrol;
	_MAXHP = _CrrentHP = 2;
	_AtkPoint = 1;
	_EnemySpeed = 50;
	NomalCount = 0;
	_isDeath = false;
	isright = false;
	_animation->start();
	_animation->setFPS(1);
	frameCount = 3;
	_Aggro = 0;

	return S_OK;
}
void BlueSolider::draw()   
{
	_Image->aniRender(getMemDC(), _ImageRc.left, _ImageRc.top, _animation);
	//_Image->aniCenterRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), _animation);
	Rectangle(getMemDC(), _DetectRc.left, _DetectRc.top, _DetectRc.right, _DetectRc.bottom);
	//RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePoint(_DetectRc).x, CAMERAMANAGER->CameraRelativePoint(_DetectRc).y, _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());
}
void BlueSolider::aniArri()
{
	
	if (_eCondistion == ECondision_Patrol)
	{
		switch (_edirection)
		{
		case EDIRECTION_LEFT:
		{
			int arrAni[] = { 6, 7, 8 };
			_animation->setPlayFrame(arrAni, 3, true);
		}
		break;
		case EDIRECTION_UP:
		{
			int arrAni[] = { 9, 10, 11 };
			_animation->setPlayFrame(arrAni, 3, true);
		}
		break;
		case EDIRECTION_RIGHT:
		{
			int arrAni[] = { 3, 4, 5 };
			_animation->setPlayFrame(arrAni, 3, true);

		}
		break;
		case EDIRECTION_DOWN:
		{
			int arrAni[] = { 0, 1, 2 };
			_animation->setPlayFrame(arrAni, 3, true);

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
			int arrAni[] = { 6 };
			_animation->setPlayFrame(arrAni, 1, true);
		}
		break;
		case EDIRECTION_UP:
		{
			int arrAni[] = { 9 };
			_animation->setPlayFrame(arrAni, 1, true);
		}
		break;
		case EDIRECTION_RIGHT:
		{
			int arrAni[] = { 3 };
			_animation->setPlayFrame(arrAni, 1, true);

		}
		break;
		case EDIRECTION_DOWN:
		{
			int arrAni[] = { 0 };
			_animation->setPlayFrame(arrAni, 1, true);

		}
		break;
		}
	}
}
void BlueSolider::move()
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
void BlueSolider::Pattern()
{
	NomalCount++;

	if (NomalCount % 24 == 0) {
		frameCount--;
		NomalCount = 0;
	}
	if (frameCount <= -1)frameCount = 3;

		if (_eCondistion == ECondision_Patrol)
		{
			switch (frameCount)
				{	//3번째
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
				//2번쨰
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
				//1번쨰
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
			if (_Aggro < 50) setAggro(50);
		}
		else
		{
			if (_y > patrolY)	setECondistion(ECondision_BackPatrol);
			else setECondistion(ECondision_Patrol);
			if (_Aggro>0) setAggro(0);

		}
	
}