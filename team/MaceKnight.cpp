#include "stdafx.h"
#include "MaceKnight.h"


MaceKnight::MaceKnight()
{
}


MaceKnight::~MaceKnight()
{
}

HRESULT MaceKnight::init(POINT potinsion, int direction)
{
	_Image = IMAGEMANAGER->addFrameImage("철퇴기사", "./image/Monster/철퇴기사3.bmp", 700, 270, 10, 4, true, RGB(255, 0, 255));
	_ImageRc = RectMakeCenter(potinsion.x, potinsion.y, _Image->getFrameWidth(), _Image->getFrameHeight());
	_animation = new animation;
	_animation->init(_Image->getWidth(), _Image->getHeight(), _Image->getFrameWidth(), _Image->getFrameHeight());
	patrolX = potinsion.x;
	patrolY = potinsion.y;
	_x = _ImageRc.left + ((_ImageRc.right - _ImageRc.left) / 2);
	_y = _ImageRc.top + ((_ImageRc.bottom - _ImageRc.top) / 2);
	_DetectRc = RectMake(0, 0, 0, 0);
	_DefRc = RectMakeCenter(_x, _y, 50, 50);
	_edirection = (EDIRECTION)direction;
	Patrol(_edirection);
	_eCondistion = ECondision_Detect;
	_MAXHP = _CrrentHP = 2;
	_AtkPoint = 1;
	_EnemySpeed = 50;
	NomalCount = 0;
	_isDeath = false;
	_animation->start();
	_animation->setFPS(1);
	frameCount = 0;
	_Aggro = 0;

	_maceImage = IMAGEMANAGER->addImage("철퇴", "./image/Monster/철퇴.bmp", 30, 30, true, RGB(255, 0, 255));
	_cx = _x;
	_cy = _y;
	//_maceRc = RectMakeCenter(_cx, _cy,  _maceImage->getFrameWidth(), _maceImage->getFrameHeight());
	_angle = PI / 2;
	_d = 50;

	_maceLine = IMAGEMANAGER->addImage("철퇴줄", "./image/Monster/철퇴줄.bmp", 20, 20, true, RGB(255, 0, 255));
	_lx = _x;
	_ly = _y;
	_ld = 20;


	return E_NOTIMPL;
}

void MaceKnight::draw()
{
	_Image->aniCenterRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), _animation);
	//RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_DefRc.left), CAMERAMANAGER->CameraRelativePointY(_DefRc.top), 50, 50);
	//setColorRect(getMemDC(), _rcBodyEnemy, 150, 100, 100);
	_maceImage->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_cx), CAMERAMANAGER->CameraRelativePointY(_cy));
	_maceLine->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_lx), CAMERAMANAGER->CameraRelativePointY(_ly));
}

void MaceKnight::aniArri()
{
	if (_eCondistion == ECondision_Patrol)
	{
		switch (_edirection)
		{
		case EDIRECTION_LEFT:
		{
			int arrAni[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };
			_animation->setPlayFrame(arrAni, 33, true);
		}
		break;
		case EDIRECTION_UP:
		{
			int arrAni[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };

			_animation->setPlayFrame(arrAni, 33, true);
		}
		break;
		case EDIRECTION_RIGHT:
		{
			int arrAni[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 ,32 };

			_animation->setPlayFrame(arrAni, 33, true);
		}
		break;
		case EDIRECTION_DOWN:
		{
			int arrAni[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };

			_animation->setPlayFrame(arrAni, 33, true);
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

			int arrAni[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };

			_animation->setPlayFrame(arrAni, 33, true);

			_animation->onceStart();
		}
		break;
		case EDIRECTION_UP:
		{
			int arrAni[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };

			_animation->setPlayFrame(arrAni, 33, true);
		}
		break;
		case EDIRECTION_RIGHT:
		{
			int arrAni[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };

			_animation->setPlayFrame(arrAni, 33, true);
		}
		break;
		case EDIRECTION_DOWN:
		{
			int arrAni[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };

			_animation->setPlayFrame(arrAni, 33, true);
		}
		break;
		}
	}
}

void MaceKnight::move()
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


	_angle += 0.08f;

	_cx = _x + _d * cosf(_angle);
	_cy = _y + _d * (-sinf(_angle));

	_maceRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_cx), CAMERAMANAGER->CameraRelativePointY(_cy), _maceImage->getFrameWidth(), _maceImage->getFrameHeight());

	_lx = _x + _ld * cosf(_angle);
	_ly = _y + _ld * (-sinf(_angle));

	_maceRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_lx), CAMERAMANAGER->CameraRelativePointY(_ly), _maceImage->getFrameWidth(), _maceImage->getFrameHeight());


	Pattern();
}

void MaceKnight::Pattern()
{
	// 이렇게 상대좌표렉트를 만들어주면 됨!
	_DefRc = RectMakeCenter(_x, _y, 40, 50);
	_rcBodyEnemy = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), 50, 50);

	NomalCount++;

	if (NomalCount % 1 == 0) {
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
		}
	}
	RECT temp;
	if (IntersectRect(&temp, &_DetectRc, &RectMake(_ptMouse.x, _ptMouse.y, 50, 50)))
	{
		_animation->stop();
		setECondistion(ECondision_Detect);
		_animation->onceStart();

	}
	else
	{
		if (_y > patrolY)	setECondistion(ECondision_BackPatrol);
		else setECondistion(ECondision_Patrol);

	}


}

void MaceKnight::Patrol(EDIRECTION direction)
{

}
