#include "stdafx.h"
#include "BlueSolider.h"


BlueSolider::BlueSolider()
{
}


BlueSolider::~BlueSolider()
{

}

HRESULT BlueSolider::init(POINT potinsion, int direction, vector<POINT>*  vPatrol)
{
	_Image = IMAGEMANAGER->addFrameImage("파란병사", "./image/Monster/BlueSoldier.bmp", 1112, 100, 12, 1, true, RGB(255, 0, 255));
	_animation = new animation;
	_animation->init(_Image->getWidth(), _Image->getHeight(), _Image->getFrameWidth(), _Image->getFrameHeight());
	
	//타일 인덱스 * 50
	//potinsion
	//_ImageRc = RectMakeCenter(potinsion.x + _Image->getFrameWidth()/2, potinsion.y + 50 - _Image->getFrameHeight() , 50, _Image->getFrameHeight());
	_ImageRc = RectMakeCenter(potinsion.x, potinsion.y, _Image->getFrameWidth(), _Image->getFrameHeight());

	
	patrolX = potinsion.x;
	patrolY = potinsion.y;

	_x = _ImageRc.left + ((_ImageRc.right - _ImageRc.left) / 2);
	_y = _ImageRc.top + ((_ImageRc.bottom - _ImageRc.top) / 2);
	_DetectRc = RectMake(0, 0, 0, 0);
	_DefRc = RectMakeCenter(_x, _y, 50, 50);
	_Aggro = 0;

	
	_eCondistion = ECondision_Patrol;
	_MAXHP = _CrrentHP = 2;
	_AtkPoint = 1;
	_EnemySpeed = 1;
	NomalCount = 0;
	_animation->start();
	_animation->setFPS(1);
	frameCount = 3;
	
	_vPatrol = vPatrol;
	//초기엔 +1씩
	_reverse = false;
	//보는방향 초기화
	//내가 갈곳이 오른쪽인가
	if ((*_vPatrol)[0].x < (*_vPatrol)[1].x)
	{
		_edirection = EDIRECTION_RIGHT;
	}

	//내가 갈곳이 왼쪽인가
	else if ((*_vPatrol)[0].x >(*_vPatrol)[1].x)
	{
		_edirection = EDIRECTION_LEFT;
	}

	//내가 갈곳이 아래쪽인가
	else if ((*_vPatrol)[0].y < (*_vPatrol)[1].y)
	{
		_edirection = EDIRECTION_DOWN;
	}

	//내가 갈곳이 위쪽인가 
	else if ((*_vPatrol)[0].y >(*_vPatrol)[1].y)
	{
		_edirection = EDIRECTION_UP;
	}

	_patrolIndex = 0;
	return S_OK;
}
void BlueSolider::draw()
{
	_Image->aniCenterRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), _animation);
	//RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_DetectRc.left), CAMERAMANAGER->CameraRelativePointY(_DetectRc.top), Patroltile*3, Patroltile*3);
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
void BlueSolider::move(RECT pleyer)
{
	
	if (_eCondistion == ECondision_Patrol)
	{
		int idX = _x / 50; //밟고있는 x인덱스
		int idY = _y / 50; //밟고있는 y인덱스

						   //1씩 증가하다가 패트롤 벡터의 사이즈에 도달하면 1씩 감소
		if (!_reverse && _patrolIndex == _vPatrol->size() - 1)
		{
			_reverse = true;
		}
		//1씩 감소하다가 인덱스가 0에 도달하면 1씩 증가
		else if (_reverse && _patrolIndex == 0)
		{
			_reverse = false;
		}

		//오른쪽으로 가고 있는중
		if (_edirection == EDIRECTION_RIGHT)
		{
			//X만 비교하면 됨
			if (idX > (*_vPatrol)[_patrolIndex].x)
			{
				if (!_reverse)	_patrolIndex++;
				else _patrolIndex--;
			}

		}
		//왼쪽으로 가고 있는 중
		if (_edirection == EDIRECTION_LEFT)
		{
			//X만 비교하면 됨
			if (idX < (*_vPatrol)[_patrolIndex].x)
			{
				if (!_reverse)	_patrolIndex++;
				else _patrolIndex--;
			}
		}
		//위로 가고 있는 중
		if (_edirection == EDIRECTION_UP)
		{
			//y만 비교하면 됨
			if (idY < (*_vPatrol)[_patrolIndex].y)
			{
				if (!_reverse)	_patrolIndex++;
				else _patrolIndex--;
			}
		}
		//아래로 가고 있는 중
		if (_edirection == EDIRECTION_DOWN)
		{
			//y만 비교하면 됨
			if (idY >(*_vPatrol)[_patrolIndex].y)
			{
				if (!_reverse)	_patrolIndex++;
				else _patrolIndex--;
			}
		}
		//정방향일때
		if (!_reverse)
		{
			//내가 갈곳이 오른쪽인가
			if (_patrolIndex != _vPatrol->size() - 1 && (*_vPatrol)[_patrolIndex].x < (*_vPatrol)[_patrolIndex + 1].x)
			{

				_edirection = EDIRECTION_RIGHT;
				_x += _EnemySpeed;
			}

			//내가 갈곳이 왼쪽인가
			else if (_patrolIndex != _vPatrol->size() - 1 && (*_vPatrol)[_patrolIndex].x >(*_vPatrol)[_patrolIndex + 1].x)
			{
				_edirection = EDIRECTION_LEFT;
				_x -= _EnemySpeed;
			}

			//내가 갈곳이 아래쪽인가
			else if (_patrolIndex != _vPatrol->size() - 1 && (*_vPatrol)[_patrolIndex].y < (*_vPatrol)[_patrolIndex + 1].y)
			{
				_edirection = EDIRECTION_DOWN;
				_y += _EnemySpeed;
			}

			//내가 갈곳이 위쪽인가 
			else if (_patrolIndex != _vPatrol->size() - 1 && (*_vPatrol)[_patrolIndex].y >(*_vPatrol)[_patrolIndex + 1].y)
			{
				_edirection = EDIRECTION_UP;
				_y -= _EnemySpeed;
			}
		}
		//역방향일때
		else
		{
			if (_patrolIndex != 0 && (*_vPatrol)[_patrolIndex].x < (*_vPatrol)[_patrolIndex - 1].x)
			{

				_edirection = EDIRECTION_RIGHT;
				_x += _EnemySpeed;
			}

			//내가 갈곳이 왼쪽인가
			else if (_patrolIndex != 0 && (*_vPatrol)[_patrolIndex].x >(*_vPatrol)[_patrolIndex - 1].x)
			{
				_edirection = EDIRECTION_LEFT;
				_x -= _EnemySpeed;
			}

			//내가 갈곳이 아래쪽인가
			else if (_patrolIndex != 0 && (*_vPatrol)[_patrolIndex].y < (*_vPatrol)[_patrolIndex - 1].y)
			{
				_edirection = EDIRECTION_DOWN;
				_y += _EnemySpeed;
			}

			//내가 갈곳이 위쪽인가 
			else if (_patrolIndex != 0 && (*_vPatrol)[_patrolIndex].y >(*_vPatrol)[_patrolIndex - 1].y)
			{
				_edirection = EDIRECTION_UP;
				_y -= _EnemySpeed;
			}
		}

	}
	else
	{
		if (_eCondistion == ECondision_Detect)
		{
			
			_x += cosf(getAngle(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), pleyer.left + ((pleyer.right - pleyer.left) / 2), pleyer.top + ((pleyer.bottom - pleyer.top) / 2))) * _EnemySpeed*1.5;
			_y += -sinf(getAngle(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), pleyer.left + ((pleyer.right - pleyer.left) / 2), pleyer.top + ((pleyer.bottom - pleyer.top) / 2))) * _EnemySpeed*1.5;
			/*
			float moveSpeed = TIMEMANAGER->getElapsedTime() *_EnemySpeed;

			if (_astar->getNexttile()->getIdX()*32 > _x && _astar->getNexttile()->getIdY() * 32 > _y)
			{
			_x += moveSpeed;
			}
			if (_astar->getNexttile()->getIdX() * 32 && _astar->getNexttile()->getIdY() * 32 < _y)
			{
			_y -= moveSpeed;
			}
			if (_astar->getNexttile()->getIdX() * 32< _x &&_astar->getNexttile()->getIdY() * 32 > _y)
			{
			_y += moveSpeed;
			}
			if (_astar->getNexttile()->getIdX() * 32< _x && _astar->getNexttile()->getIdY() * 32 < _y)
			{
			_x -= moveSpeed;
			}
			*/
		}
		else if (_eCondistion == ECondision_BackPatrol)
		{
			//a* 패트롤 랜덤 좌표
			
			_x += cosf(getAngle(_x, _y, patrolX, patrolY /*, _x, _y*/)) * _EnemySpeed*1.5;;
			_y += -sinf(getAngle(_x, _y, patrolX, patrolY /*, _x, _y*/)) * _EnemySpeed*1.5;

		}
	}
	Pattern(pleyer);
}
void BlueSolider::Pattern(RECT pleyer)
{
	_DefRc = RectMakeCenter(_x, _y, 50, 50);
	_rcBodyEnemy = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), 50, 50);

	if (_eCondistion == ECondision_Detect)
	{
		setAggro(50);
	}
	NomalCount++;

	if (NomalCount % 24 == 0) {
		frameCount--;
		NomalCount = 0;
	}

	if (frameCount <= -1)frameCount = 3;

	//RECT temp;

	//if (IntersectRect(&temp, &_DetectRc, &RectMake(_ptMouse.x, _ptMouse.y, 50, 50)))
	//{
	//	_animation->stop();
	//	setECondistion(ECondision_Detect);
	//	_animation->stop();
	//	_animation->onceStart();
	//}
	//else
	//{
	//	/*if (_y > patrolY)	setECondistion(ECondision_BackPatrol);
	//	else*/ setECondistion(ECondision_Patrol);
	//	//if (_Aggro>0) setAggro(0);

	//}
	if (_eCondistion == ECondision_Patrol)
	{
		_Aggro = 0;
		switch (frameCount)
		{	//3번째
		case 0:
		{
			switch (_edirection)
			{
			case EDIRECTION_LEFT:
				//업
				_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) - 25, CAMERAMANAGER->CameraRelativePointY(_y) - 250, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
				break;
			case EDIRECTION_UP:
				//오른쪽
				_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) + 50, CAMERAMANAGER->CameraRelativePointY(_y) - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
				break;
			case EDIRECTION_RIGHT:
				//다운
				_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) - 25, CAMERAMANAGER->CameraRelativePointY(_y) + 30, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
				break;
			case EDIRECTION_DOWN:
				//왼쪽
				_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) - 250, CAMERAMANAGER->CameraRelativePointY(_y) - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
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
				_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) - 25, CAMERAMANAGER->CameraRelativePointY(_y) + 35, Patroltile * 3, Patroltile * 4);  //타일 사이즈 만큼 조정예정
				break;
			case EDIRECTION_UP:
				//왼쪽
				_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) - 250, CAMERAMANAGER->CameraRelativePointY(_y) - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
				break;
			case EDIRECTION_RIGHT:
				//업
				_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) - 25, CAMERAMANAGER->CameraRelativePointY(_y) - 250, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
				break;
			case EDIRECTION_DOWN:
				//오른쪽
				_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) + 50, CAMERAMANAGER->CameraRelativePointY(_y) - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
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
				_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) - 250, CAMERAMANAGER->CameraRelativePointY(_y) - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
			}
			break;
			case EDIRECTION_UP:
			{
				_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) - 25, CAMERAMANAGER->CameraRelativePointY(_y) - 250, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
			}
			break;
			case EDIRECTION_RIGHT:
			{
				_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) + 50, CAMERAMANAGER->CameraRelativePointY(_y) - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
			}
			break;
			case EDIRECTION_DOWN:
			{
				_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) - 25, CAMERAMANAGER->CameraRelativePointY(_y) + 30, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정 
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
			_animation->stop();
			_animation->onceStart();
			_Aggro = 50;
			

			_Aggro++;
			if (_Aggro < 350)
			{
				
				if (pleyer.left + ((pleyer.right - pleyer.left) / 2) > CAMERAMANAGER->CameraRelativePointX(_x) && pleyer.top + ((pleyer.bottom - pleyer.top) / 2) > CAMERAMANAGER->CameraRelativePointY(_y))
				{
					_edirection = EDIRECTION_RIGHT;
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) + 50, CAMERAMANAGER->CameraRelativePointY(_y) - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
																																									  //_animation->stop();
				}
				if (pleyer.left + ((pleyer.right - pleyer.left) / 2) > CAMERAMANAGER->CameraRelativePointX(_x) && pleyer.top + ((pleyer.bottom - pleyer.top) / 2) < CAMERAMANAGER->CameraRelativePointY(_y))
				{
					_edirection = EDIRECTION_UP; //_animation->stop();
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) - 25, CAMERAMANAGER->CameraRelativePointY(_y) - 250, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
				}
				if (pleyer.left + ((pleyer.right - pleyer.left) / 2) < CAMERAMANAGER->CameraRelativePointX(_x) && pleyer.top + ((pleyer.bottom - pleyer.top) / 2)> CAMERAMANAGER->CameraRelativePointY(_y))
				{
					_edirection = EDIRECTION_DOWN; //_animation->stop();
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) - 25, CAMERAMANAGER->CameraRelativePointY(_y) + 30, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정 
				}
				if (pleyer.left + ((pleyer.right - pleyer.left) / 2) < CAMERAMANAGER->CameraRelativePointX(_x) && pleyer.top + ((pleyer.bottom - pleyer.top) / 2) < CAMERAMANAGER->CameraRelativePointY(_y))
				{
					_edirection = EDIRECTION_LEFT; //_animation->stop();
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) - 250, CAMERAMANAGER->CameraRelativePointY(_y) - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
				}
			}
		}

	}


}
