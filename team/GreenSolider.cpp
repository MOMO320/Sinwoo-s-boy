#include "stdafx.h"
#include "GreenSolider.h"


GreenSolider::GreenSolider()
{
}


GreenSolider::~GreenSolider()
{
}

HRESULT GreenSolider::init(POINT potinsion, int direction, vector<POINT>*  vPatrol)					//필수 
{
	_Image = IMAGEMANAGER->addFrameImage("녹색병사", "./image/Monster/GreenSoldier.bmp", 900, 79, 16, 1, true, RGB(255, 0, 255));
	_animation = new animation;
	_animation->init(_Image->getWidth(), _Image->getHeight(), _Image->getFrameWidth(), _Image->getFrameHeight());

	//타일 인덱스 * 50
	//potinsion
	//_ImageRc = RectMakeCenter(potinsion.x + _Image->getFrameWidth()/2, potinsion.y + 50 - _Image->getFrameHeight() , 50, _Image->getFrameHeight());
	_ImageRc = RectMakeCenter(potinsion.x, potinsion.y , 50, _Image->getFrameHeight());
	
	patrolX = potinsion.x;
	patrolY = potinsion.y;

	
	_x = _ImageRc.left + ((_ImageRc.right - _ImageRc.left) / 2);
	_y = _ImageRc.top + ((_ImageRc.bottom - _ImageRc.top) / 2);
	_DetectRc = RectMake(0, 0, 0, 0);
	_DefRc = RectMakeCenter(_x, _y, 50, 50);
	_Aggro = -1;
	
	_eCondistion = ECondision_Patrol;
	_MAXHP = _CrrentHP = 1;
	_AtkPoint = 1;
	_EnemySpeed = 1;
	NomalCount = dellay =0;
	_isDeath = false;
	_animation->start();
	_animation->setFPS(1);
	frameCount = 0;
	
	//실험용(재호)
	_vPatrol = vPatrol;

	//초기엔 +1씩
	_reverse = false;
	//_renderPoint = potinsion;

	//보는방향 초기화
	//내가 갈곳이 오른쪽인가
	if ((*_vPatrol)[0].x < (*_vPatrol)[1].x)
	{
		_edirection = EDIRECTION_RIGHT;
	}

	//내가 갈곳이 왼쪽인가
	else if ((*_vPatrol)[0].x > (*_vPatrol)[1].x)
	{
		_edirection = EDIRECTION_LEFT;
	}
	
	//내가 갈곳이 아래쪽인가
	else if ((*_vPatrol)[0].y < (*_vPatrol)[1].y)
	{
		_edirection = EDIRECTION_DOWN;
	}

	//내가 갈곳이 위쪽인가 
	else if ((*_vPatrol)[0].y > (*_vPatrol)[1].y)
	{
		_edirection = EDIRECTION_UP;
	}

	_patrolIndex = 0;
	return S_OK;
}

void GreenSolider::draw()
{

	_Image->aniCenterRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), _animation);
	//RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_DefRc.left), CAMERAMANAGER->CameraRelativePointY(_DefRc.top), 50, 50);

	/*TextOut(getMemDC(), 200, 200, str, strlen(str));
	TextOut(getMemDC(), 200, 230, str2, strlen(str2));
	TextOut(getMemDC(), 200, 260, str3, strlen(str3));*/

}

void GreenSolider::aniArri()
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

void GreenSolider::move(RECT pleyer)
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
			if ( _patrolIndex != _vPatrol->size()-1 && (*_vPatrol)[_patrolIndex].x < (*_vPatrol)[_patrolIndex + 1].x)
			{

				_edirection = EDIRECTION_RIGHT;
				_x += _EnemySpeed;
			}

			//내가 갈곳이 왼쪽인가
			else if (_patrolIndex != _vPatrol->size()-1 && (*_vPatrol)[_patrolIndex].x >(*_vPatrol)[_patrolIndex + 1].x)
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
		}
		else if (_eCondistion == ECondision_BackPatrol)
		{

		}
	}

	Pattern(pleyer);
	sprintf_s(str, "_eDirection: %d ", _edirection);
	sprintf_s(str2, "_eCondistion : %d", _eCondistion);
	sprintf_s(str3, "_y : %d", _y);
}

void GreenSolider::Pattern(RECT pleyer)
{
	// 이렇게 상대좌표렉트를 만들어주면 됨!
	_DefRc = RectMakeCenter(_x, _y, 40, 50);
	_rcBodyEnemy = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), 50, 50);

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
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)+25, CAMERAMANAGER->CameraRelativePointY(_y)-250, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
					break;
				case EDIRECTION_UP:
					//오른쪽
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)+50, CAMERAMANAGER->CameraRelativePointY(_y)+25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
					break;
				case EDIRECTION_RIGHT:
					//다운
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)+25, CAMERAMANAGER->CameraRelativePointY(_y)+25, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
					break;
				case EDIRECTION_DOWN:
					//왼쪽
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)-250, CAMERAMANAGER->CameraRelativePointY(_y)-25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
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
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)+25, CAMERAMANAGER->CameraRelativePointY(_y)+35, Patroltile * 3, Patroltile * 4);  //타일 사이즈 만큼 조정예정
					break;
				case EDIRECTION_UP:
					//왼쪽
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)-250, CAMERAMANAGER->CameraRelativePointY(_y)-25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
					break;
				case EDIRECTION_RIGHT:
					//업
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)-25, CAMERAMANAGER->CameraRelativePointY(_y)-250, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
					break;
				case EDIRECTION_DOWN:
					//오른쪽
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)+50, CAMERAMANAGER->CameraRelativePointY(_y)-25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
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
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)-250, CAMERAMANAGER->CameraRelativePointY(_y)-25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
				}
				break;
				case EDIRECTION_UP:
				{
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)-25, CAMERAMANAGER->CameraRelativePointY(_y)-250, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
				}
				break;
				case EDIRECTION_RIGHT:
				{
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)+50, CAMERAMANAGER->CameraRelativePointY(_y)-25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
				}
				break;
				case EDIRECTION_DOWN:
				{
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)-25, CAMERAMANAGER->CameraRelativePointY(_y)+50, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정 
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
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) - 25, CAMERAMANAGER->CameraRelativePointY(_y) + 50, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정 
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

			if (pleyer.left + ((pleyer.right - pleyer.left) / 2) > CAMERAMANAGER->CameraRelativePointX(_x) && pleyer.top + ((pleyer.bottom - pleyer.top) / 2) > CAMERAMANAGER->CameraRelativePointY(_y))
			{
				_edirection = EDIRECTION_RIGHT;
				_DetectRc = RectMake(_x + 50, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
																						//_animation->stop();
			}
			if (pleyer.left + ((pleyer.right - pleyer.left) / 2) > CAMERAMANAGER->CameraRelativePointX(_x) && pleyer.top + ((pleyer.bottom - pleyer.top) / 2) < CAMERAMANAGER->CameraRelativePointY(_y))
			{
				_edirection = EDIRECTION_UP; //_animation->stop();
				_DetectRc = RectMake(_x - 25, _y - 250, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
			}
			if (pleyer.left + ((pleyer.right - pleyer.left) / 2) < CAMERAMANAGER->CameraRelativePointX(_x) && pleyer.top + ((pleyer.bottom - pleyer.top) / 2) > CAMERAMANAGER->CameraRelativePointY(_y))
			{
				_edirection = EDIRECTION_DOWN; //_animation->stop();
				_DetectRc = RectMake(_x - 25, _y + 30, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정 
			}
			if (pleyer.left + ((pleyer.right - pleyer.left) / 2) < CAMERAMANAGER->CameraRelativePointX(_x) && pleyer.top + ((pleyer.bottom - pleyer.top) / 2) < CAMERAMANAGER->CameraRelativePointY(_y))
			{
				_edirection = EDIRECTION_LEFT; //_animation->stop();
				_DetectRc = RectMake(_x - 250, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
			}
		}
	}
	
}


