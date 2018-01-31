#include "stdafx.h"
#include "GreenSolider.h"
#include "player.h"

GreenSolider::GreenSolider()
{
}


GreenSolider::~GreenSolider()
{
}

HRESULT GreenSolider::init(POINT potinsion, int direction, vector<POINT>*  vPatrol)					//�ʼ� 
{
	_Image = IMAGEMANAGER->addFrameImage("�������", "./image/Monster/GreenSoldier.bmp", 900, 79, 16, 1, true, RGB(255, 0, 255));
	_animation = new animation;
	_animation->init(_Image->getWidth(), _Image->getHeight(), _Image->getFrameWidth(), _Image->getFrameHeight());
	_ImageRc = RectMakeCenter(potinsion.x, potinsion.y , 50, _Image->getFrameHeight());
	patrolX = potinsion.x;
	patrolY = potinsion.y;
	_x = _ImageRc.left + ((_ImageRc.right - _ImageRc.left) / 2);
	_y = _ImageRc.top + ((_ImageRc.bottom - _ImageRc.top) / 2);
	_DetectRc = RectMake(0, 0, 0, 0);
	_DefRc = RectMakeCenter(_x, _y, 50, 50);
	_Aggro = -1;
	
	_eCondistion = ECondision_Detect;
	_MAXHP = _CrrentHP = 1;
	_AtkPoint = 1;
	_EnemySpeed = 1;
	NomalCount = dellay =0;
	isback = false;
	_animation->start();
	_animation->setFPS(1);
	frameCount = 0;
	
	//�����(��ȣ)
	_vPatrol = vPatrol;

	//�ʱ⿣ +1��
	_reverse = false;
	//_renderPoint = potinsion;

	//���¹��� �ʱ�ȭ
	//���� ������ �������ΰ�
	if ((*_vPatrol)[0].x < (*_vPatrol)[1].x)
	{
		_edirection = EDIRECTION_RIGHT;
	}

	//���� ������ �����ΰ�
	else if ((*_vPatrol)[0].x > (*_vPatrol)[1].x)
	{
		_edirection = EDIRECTION_LEFT;
	}
	
	//���� ������ �Ʒ����ΰ�
	else if ((*_vPatrol)[0].y < (*_vPatrol)[1].y)
	{
		_edirection = EDIRECTION_DOWN;
	}

	//���� ������ �����ΰ� 
	else if ((*_vPatrol)[0].y > (*_vPatrol)[1].y)
	{
		_edirection = EDIRECTION_UP;
	}

	_patrolIndex = 0;

	_aStar = new aStar;
	_nextTile = new aStarTile; 
	return S_OK;
}

void GreenSolider::draw()
{

	
	//RectangleMakeCenter(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_DetectRc.left + ((_DetectRc.right -_DetectRc.left)/2)),
	//							CAMERAMANAGER->CameraRelativePointY(_DetectRc.top+ ((_DetectRc.bottom -_DetectRc.top)/2)), Patroltile*3, Patroltile * 3);

	_Image->aniCenterRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), _animation);

	TextOut(getMemDC(), 200, 330, test, strlen(test));
	TextOut(getMemDC(), 200, 360, str2, strlen(str2));
	//TextOut(getMemDC(), 200, 390, str3, strlen(str3));*/

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

void GreenSolider::move(player* player)
{
	
	if (_eCondistion == ECondision_Patrol)
	{		

		int idX = _x / 50; //����ִ� x�ε���
		int idY = _y / 50; //����ִ� y�ε���

						   //1�� �����ϴٰ� ��Ʈ�� ������ ����� �����ϸ� 1�� ����
		if (!_reverse && _patrolIndex == _vPatrol->size() - 1)
		{
			_reverse = true;
		}
		//1�� �����ϴٰ� �ε����� 0�� �����ϸ� 1�� ����
		else if (_reverse && _patrolIndex == 0)
		{
			_reverse = false;
		}

		//���������� ���� �ִ���
		if (_edirection == EDIRECTION_RIGHT)
		{
			//X�� ���ϸ� ��
			if (idX > (*_vPatrol)[_patrolIndex].x)
			{
				if (!_reverse)	_patrolIndex++;
				else _patrolIndex--;
			}

		}
		//�������� ���� �ִ� ��
		if (_edirection == EDIRECTION_LEFT)
		{
			//X�� ���ϸ� ��
			if (idX < (*_vPatrol)[_patrolIndex].x)
			{
				if (!_reverse)	_patrolIndex++;
				else _patrolIndex--;
			}
		}
		//���� ���� �ִ� ��
		if (_edirection == EDIRECTION_UP)
		{
			//y�� ���ϸ� ��
			if (idY < (*_vPatrol)[_patrolIndex].y)
			{
				if (!_reverse)	_patrolIndex++;
				else _patrolIndex--;
			}
		}
		//�Ʒ��� ���� �ִ� ��
		if (_edirection == EDIRECTION_DOWN)
		{
			//y�� ���ϸ� ��
			if (idY >(*_vPatrol)[_patrolIndex].y)
			{
				if (!_reverse)	_patrolIndex++;
				else _patrolIndex--;
			}
		}
		//�������϶�
		if (!_reverse)
		{
			//���� ������ �������ΰ�
			if ( _patrolIndex != _vPatrol->size()-1 && (*_vPatrol)[_patrolIndex].x < (*_vPatrol)[_patrolIndex + 1].x)
			{

				_edirection = EDIRECTION_RIGHT;
				_x += _EnemySpeed;
			}

			//���� ������ �����ΰ�
			else if (_patrolIndex != _vPatrol->size()-1 && (*_vPatrol)[_patrolIndex].x >(*_vPatrol)[_patrolIndex + 1].x)
			{
				_edirection = EDIRECTION_LEFT;
				_x -= _EnemySpeed;
			}

			//���� ������ �Ʒ����ΰ�
			else if (_patrolIndex != _vPatrol->size() - 1 && (*_vPatrol)[_patrolIndex].y < (*_vPatrol)[_patrolIndex + 1].y)
			{
				_edirection = EDIRECTION_DOWN;
				_y += _EnemySpeed;
			}

			//���� ������ �����ΰ� 
			else if (_patrolIndex != _vPatrol->size() - 1 && (*_vPatrol)[_patrolIndex].y >(*_vPatrol)[_patrolIndex + 1].y)
			{
				_edirection = EDIRECTION_UP;
				_y -= _EnemySpeed;
			}
		}
		//�������϶�
		else
		{
			if (_patrolIndex != 0 && (*_vPatrol)[_patrolIndex].x < (*_vPatrol)[_patrolIndex - 1].x)
			{

				_edirection = EDIRECTION_RIGHT;
				_x += _EnemySpeed;
			}

			//���� ������ �����ΰ�
			else if (_patrolIndex != 0 && (*_vPatrol)[_patrolIndex].x >(*_vPatrol)[_patrolIndex - 1].x)
			{
				_edirection = EDIRECTION_LEFT;
				_x -= _EnemySpeed;
			}

			//���� ������ �Ʒ����ΰ�
			else if (_patrolIndex != 0 && (*_vPatrol)[_patrolIndex].y < (*_vPatrol)[_patrolIndex - 1].y)
			{
				_edirection = EDIRECTION_DOWN;
				_y += _EnemySpeed;
			}

			//���� ������ �����ΰ� 
			else if (_patrolIndex != 0 && (*_vPatrol)[_patrolIndex].y >(*_vPatrol)[_patrolIndex - 1].y)
			{
				_edirection = EDIRECTION_UP;
				_y -= _EnemySpeed;
			}
		}
		_ImageRc = RectMakeCenter(_x, _y, 50, _Image->getFrameHeight());
	}
	else if (_eCondistion == ECondision_Detect)
	{
		/*if (KEYMANAGER->isOnceKeyDown('W'))
		{*/
			_aStar->setTiles(_x, _ImageRc.bottom, player->getPlayerRealpos().x, player->getPlayerRealpos().y);
			_nextTile = _aStar->getNextTile();
			if (_nextTile != NULL)
			{
				//_x = _nextTile->getIdX() * 25;
				//_y = _nextTile->getIdY() * 25;
					int idX = _x / 25; //����ִ� x�ε���
				int idY = _ImageRc.bottom / 25; //����ִ� y�ε���

				/*int IDX = _aStar->getNextTile()->getIdX();
				int IDY = _aStar->getNextTile()->getIdY();*/

				if (_nextTile->getIdX() > idX)
				{
					_edirection = EDIRECTION_RIGHT;
					_x += _EnemySpeed *1.5;

				}
				if (_nextTile->getIdY()  < idY)
				{
					_edirection = EDIRECTION_UP;
					_y -= _EnemySpeed *1.5;
				}
				if (_nextTile->getIdY()  > idY)
				{
					_edirection = EDIRECTION_DOWN;
					_y += _EnemySpeed *1.5;
				}
				if (_nextTile->getIdX() < idX)
				{
					_edirection = EDIRECTION_LEFT;
					_x -= _EnemySpeed *1.5;
				}

				_ImageRc = RectMakeCenter(_x, _y, 50, _Image->getFrameHeight());
				///*if(_ImageRc.bottom / 25 == _nexttile->getIdY())*/
				sprintf_s(str2, "%d, %d ", _nextTile->getIdX()* 25, _nextTile->getIdY() * 25);
			}
		//}
	}

	else if (_eCondistion == ECondision_BackPatrol)
	{
		_aStar->setTiles(_x, _ImageRc.bottom, (*_vPatrol)[0].x * 50, (*_vPatrol)[0].y * 50);
		_nextTile = _aStar->getNextTile();
		if (_nextTile != NULL)
		{
			int idX = _x / 25; //����ִ� x�ε���
			int idY = _ImageRc.bottom / 25; //����ִ� y�ε���
			if (_nextTile->getIdX() > idX)
			{
				_edirection = EDIRECTION_RIGHT;
				_x += _EnemySpeed *1.5;
			}
			if (_nextTile->getIdY() < idY)
			{
				_edirection = EDIRECTION_UP;
				_y -= _EnemySpeed *1.5;
			}
			if (_nextTile->getIdY() > idY)
			{
				_edirection = EDIRECTION_DOWN;
				_y += _EnemySpeed *1.5;
			}
			if (_nextTile->getIdX() < idX)
			{
				_edirection = EDIRECTION_LEFT;
				_x -= _EnemySpeed *1.5;
			}
			sprintf_s(test, "_nextTile->getIdX() :%d     _nextTile->getIdY() :%d", _nextTile->getIdX(), _nextTile->getIdY());
			sprintf_s(str2, "(*_vPatrol)[0].x : %d, (*_vPatrol)[0].y  : %d", (*_vPatrol)[0].x, (*_vPatrol)[0].y);
			sprintf_s(str3, "idX : %d  idY : %d", idX, idY);
			_ImageRc = RectMakeCenter(_x, _y, 50, _Image->getFrameHeight());
			if (_x / 50 == (*_vPatrol)[0].x && _y / 50 == (*_vPatrol)[0].y) isback = true;
			else isback = false;
			//_eCondistion = ECondision_Patrol;

		}
	}
	collision(player);
	Pattern(player);
	
	sprintf_s(test, "%d, %d ", player->getPlayerRealpos().x, player->getPlayerRealpos().y);
	/*sprintf_s(str2, "_eCondistion : %d", _eCondistion);
	sprintf_s(str3, "_y : %d", _y);*/
	//sprintf_s(test, "ECondicon :%d", _eCondistion);
}

void GreenSolider::Pattern(player* player)
{
	// �̷��� �����ǥ��Ʈ�� ������ָ� ��!
	_DefRc = RectMakeCenter(_x, _y, 40, 50);
	_rcBodyEnemy = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), 50, 50);

	NomalCount++;

	if (NomalCount % 24 == 0) {
		frameCount--;
		NomalCount = 0;
	}

	if (frameCount <= -1)frameCount = 4;

	
	if (_eCondistion == ECondision_Patrol || _eCondistion == ECondision_BackPatrol)
	{
		switch (frameCount)
		{	//4��°
			case 0:
			{
				switch (_edirection)
				{
				case EDIRECTION_LEFT:
					//��
					_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
					break;
				case EDIRECTION_UP:
					//������
					_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
					break;
				case EDIRECTION_RIGHT:
					//�ٿ�
					_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
					break;
				case EDIRECTION_DOWN:
					//����
					_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
					break;
				}
			}
			break;
			//3����
			case 1:
			{
				switch (_edirection)
				{
				case EDIRECTION_LEFT:
					//�ٿ�
					_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3);  //Ÿ�� ������ ��ŭ ��������
					break;
				case EDIRECTION_UP:
					//����
					_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
					break;
				case EDIRECTION_RIGHT:
					//��
					_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
					break;
				case EDIRECTION_DOWN:
					//������
					_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
					break;
				default:
					break;
				}

			}
			break;
			//2����
			case 2:
			{

				switch (_edirection)
				{
				case EDIRECTION_LEFT:
				{
					_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
				}
				break;
				case EDIRECTION_UP:
				{
					_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
				}
				break;
				case EDIRECTION_RIGHT:
				{
					_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
				}
				break;
				case EDIRECTION_DOWN:
				{
					_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ �������� 
				}
				break;
				}
			}
			break;

			//1����
			case 3:
			{
				switch (_edirection)
				{
				case EDIRECTION_LEFT:
				{
					_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y) , Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
				}
				break;
				case EDIRECTION_UP:
				{
					_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x) , CAMERAMANAGER->CameraRelativePointY(_y) , Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
				}
				break;
				case EDIRECTION_RIGHT:
				{
					_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
				}
				break;
				case EDIRECTION_DOWN:
				{
					_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ �������� 
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

			if (player->getPlayerRC().left + ((player->getPlayerRC().right - player->getPlayerRC().left) / 2) >	CAMERAMANAGER->CameraRelativePointX(_x) && 
				player->getPlayerRC().top + ((player->getPlayerRC().bottom - player->getPlayerRC().top) / 2) >	CAMERAMANAGER->CameraRelativePointY(_y))
			{
				_edirection = EDIRECTION_RIGHT;
				_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
																						//_animation->stop();
			}
			if (player->getPlayerRC().left + ((player->getPlayerRC().right - player->getPlayerRC().left) / 2) > CAMERAMANAGER->CameraRelativePointX(_x) && player->getPlayerRC().top + ((player->getPlayerRC().bottom - player->getPlayerRC().top) / 2) < CAMERAMANAGER->CameraRelativePointY(_y))
			{
				_edirection = EDIRECTION_UP; //_animation->stop();
				_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
			}
			if (player->getPlayerRC().left + ((player->getPlayerRC().right - player->getPlayerRC().left) / 2) < CAMERAMANAGER->CameraRelativePointX(_x) && player->getPlayerRC().top + ((player->getPlayerRC().bottom - player->getPlayerRC().top) / 2) > CAMERAMANAGER->CameraRelativePointY(_y))
			{
				_edirection = EDIRECTION_DOWN; //_animation->stop();
				_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
			}
			if (player->getPlayerRC().left + ((player->getPlayerRC().right - player->getPlayerRC().left) / 2) < CAMERAMANAGER->CameraRelativePointX(_x) && player->getPlayerRC().top + ((player->getPlayerRC().bottom - player->getPlayerRC().top) / 2) < CAMERAMANAGER->CameraRelativePointY(_y))
			{
				_edirection = EDIRECTION_LEFT; //_animation->stop();
				_DetectRc = RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), Patroltile * 3, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
			}
		}
	}
	

}

void GreenSolider::collision(player * player)
{
	RECT temp;

	
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
	
}


