#include "stdafx.h"
#include "GreenSolider.h"


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

	//Ÿ�� �ε��� * 50
	//potinsion
	//_ImageRc = RectMakeCenter(potinsion.x + _Image->getFrameWidth()/2, potinsion.y + 50 - _Image->getFrameHeight() , 50, _Image->getFrameHeight());
	_ImageRc = RectMakeCenter(potinsion.x, potinsion.y , 50, _Image->getFrameHeight());
	
	patrolX = potinsion.x;
	patrolY = potinsion.y;

	//_x = potinsion.x;
	//_y = potinsion.y;
	_x = _ImageRc.left + ((_ImageRc.right - _ImageRc.left) / 2);
	_y = _ImageRc.top + ((_ImageRc.bottom - _ImageRc.top) / 2);
	_DetectRc = RectMake(0, 0, 0, 0);
	_DefRc = RectMakeCenter(_x, _y, 50, 50);
	_Aggro = -1;
	
	_eCondistion = ECondision_Patrol;
	_MAXHP = _CrrentHP = 1;
	_AtkPoint = 1;
	_EnemySpeed = 50;
	NomalCount = dellay =0;
	_isDeath = false;
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

	/*sprintf(test1, "%d, %d", (*_vPatrol)[0].x, (*_vPatrol)[0].y);

	sprintf(test2, "%d, %d", (*_vPatrol)[2].x, (*_vPatrol)[2].y);

	sprintf(test3, "%d, %d", (*_vPatrol)[5].x, (*_vPatrol)[5].y);
	sprintf(test4, "%d, %d", (*_vPatrol)[7].x, (*_vPatrol)[7].y);
	sprintf(test5, "%d, %d", (*_vPatrol)[10].x, (*_vPatrol)[10].y);*/

	_patrolIndex = 0;
	return S_OK;
}

void GreenSolider::draw()
{

	_Image->aniCenterRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), _animation);
	//RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_DefRc.left), CAMERAMANAGER->CameraRelativePointY(_DefRc.top), 50, 50);
//	setColorRect(getMemDC(), _rcBodyEnemy, 150, 100, 100);
	/*TextOut(getMemDC(), 200, 200, str, strlen(str));
	TextOut(getMemDC(), 200, 230, str2, strlen(str2));
	TextOut(getMemDC(), 200, 260, str3, strlen(str3));*/

	/*TextOut(getMemDC(), 100, 260, test1, strlen(test1));
	TextOut(getMemDC(), 200, 260, test2, strlen(test2));
	TextOut(getMemDC(), 300, 260, test3, strlen(test3));
	TextOut(getMemDC(), 400, 260, test4, strlen(test4));
	TextOut(getMemDC(), 500, 260, test5, strlen(test5));*/

}

void GreenSolider::aniArri()
{
	/*if (_eCondistion == ECondision_Patrol)
	{*/
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
	/*}*/
	//else if (_eCondistion == ECondision_Detect)
	//{
	//	
	//	switch (_edirection)
	//	{
	//	case EDIRECTION_LEFT:
	//	{

	//		int arrAni[] = { 8, 9 };
	//		_animation->setPlayFrame(arrAni, 2, true);

	//		//_animation->onceStart();
	//	}
	//	break;
	//	case EDIRECTION_UP:
	//	{
	//		int arrAni[] = { 12, 13 };
	//		_animation->setPlayFrame(arrAni, 2, true);
	//	}
	//	break;
	//	case EDIRECTION_RIGHT:
	//	{
	//		int arrAni[] = { 4, 5 };
	//		_animation->setPlayFrame(arrAni, 2, true);
	//	}
	//	break;
	//	case EDIRECTION_DOWN:
	//	{
	//		int arrAni[] = { 0, 1 };
	//		_animation->setPlayFrame(arrAni, 2, true);
	//	}
	//	break;
	//	}
	//}
}

void GreenSolider::move(RECT pleyer)
{
	float moveSpeed = 1;//TIMEMANAGER->getElapsedTime() *_EnemySpeed;
	if (_eCondistion == ECondision_Patrol)
	{		
		//�������϶�
		if (!_reverse)
		{
			//���� ������ �������ΰ�
			if ( _patrolIndex != _vPatrol->size()-1 && (*_vPatrol)[_patrolIndex].x < (*_vPatrol)[_patrolIndex + 1].x)
			{

				_edirection = EDIRECTION_RIGHT;
				_x += moveSpeed;
			}

			//���� ������ �����ΰ�
			else if (_patrolIndex != _vPatrol->size()-1 && (*_vPatrol)[_patrolIndex].x >(*_vPatrol)[_patrolIndex + 1].x)
			{
				_edirection = EDIRECTION_LEFT;
				_x -= moveSpeed;
			}

			//���� ������ �Ʒ����ΰ�
			else if (_patrolIndex != _vPatrol->size() - 1 && (*_vPatrol)[_patrolIndex].y < (*_vPatrol)[_patrolIndex + 1].y)
			{
				_edirection = EDIRECTION_DOWN;
				_y += moveSpeed;
			}

			//���� ������ �����ΰ� 
			else if (_patrolIndex != _vPatrol->size() - 1 && (*_vPatrol)[_patrolIndex].y >(*_vPatrol)[_patrolIndex + 1].y)
			{
				_edirection = EDIRECTION_UP;
				_y -= moveSpeed;
			}
		}
		//�������϶�
		else
		{
			if (_patrolIndex != 0 && (*_vPatrol)[_patrolIndex].x < (*_vPatrol)[_patrolIndex - 1].x)
			{

				_edirection = EDIRECTION_RIGHT;
				_x += moveSpeed;
			}

			//���� ������ �����ΰ�
			else if (_patrolIndex != 0 && (*_vPatrol)[_patrolIndex].x >(*_vPatrol)[_patrolIndex - 1].x)
			{
				_edirection = EDIRECTION_LEFT;
				_x -= moveSpeed;
			}

			//���� ������ �Ʒ����ΰ�
			else if (_patrolIndex != 0 && (*_vPatrol)[_patrolIndex].y < (*_vPatrol)[_patrolIndex - 1].y)
			{
				_edirection = EDIRECTION_DOWN;
				_y += moveSpeed;
			}

			//���� ������ �����ΰ� 
			else if (_patrolIndex != 0 && (*_vPatrol)[_patrolIndex].y >(*_vPatrol)[_patrolIndex - 1].y)
			{
				_edirection = EDIRECTION_UP;
				_y -= moveSpeed;
			}
		}
		////Ÿ�ϻ����ŭ ���ϱ�
		//_x = (*_vPatrol)[_patrolIndex].x * 50;
		//_y = (*_vPatrol)[_patrolIndex].y * 50;
		/*if (!isright)
		{
			_edirection = EDIRECTION_LEFT;
			_x -= moveSpeed;
			if (_x <800-200) isright = true;
		}
		else
		{
			_edirection = EDIRECTION_RIGHT;
			_x += moveSpeed;
			if (_x > 800+200) isright = false;
		}*/
	}
	else
	{
		//if (_eCondistion == ECondision_Detect)
		//{
		//	float moveSpeed = TIMEMANAGER->getElapsedTime() *_EnemySpeed;
		//	_x += cosf(getAngle(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y),
		//		pleyer.left+ ((pleyer.right- pleyer.left)/2), pleyer.top + ((pleyer.bottom - pleyer.top) / 2))) * moveSpeed*1.5;

		//	_y += -sinf(getAngle(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y),
		//		pleyer.left + ((pleyer.right - pleyer.left) / 2), pleyer.top + ((pleyer.bottom - pleyer.top) / 2))) * moveSpeed*1.5;
		//}
		//else if (_eCondistion == ECondision_BackPatrol)
		//{
		//	float moveSpeed = TIMEMANAGER->getElapsedTime() *_EnemySpeed;
		//	_x += cosf(getAngle(_x, _y, _x, patrolY /*, _x, _y*/)) * moveSpeed;
		//	_y += -sinf(getAngle(_x, _y, _x, patrolY /*, _x, _y*/)) * moveSpeed;

		//}
		
	}

	Pattern(pleyer);
	sprintf_s(str, "_eDirection: %d ", _edirection);
	sprintf_s(str2, "_eCondistion : %d", _eCondistion);
	sprintf_s(str3, "_y : %d", _y);
}

void GreenSolider::Pattern(RECT pleyer)
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

	
	if (_eCondistion == ECondision_Patrol)
	{
		switch (frameCount)
		{	//4��°
			case 0:
			{
				switch (_edirection)
				{
				case EDIRECTION_LEFT:
					//��
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)+25, CAMERAMANAGER->CameraRelativePointY(_y)-250, Patroltile * 3, Patroltile * 4); //Ÿ�� ������ ��ŭ ��������
					break;
				case EDIRECTION_UP:
					//������
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)+50, CAMERAMANAGER->CameraRelativePointY(_y)+25, Patroltile * 4, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
					break;
				case EDIRECTION_RIGHT:
					//�ٿ�
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)+25, CAMERAMANAGER->CameraRelativePointY(_y)+25, Patroltile * 3, Patroltile * 4); //Ÿ�� ������ ��ŭ ��������
					break;
				case EDIRECTION_DOWN:
					//����
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)-250, CAMERAMANAGER->CameraRelativePointY(_y)-25, Patroltile * 4, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
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
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)+25, CAMERAMANAGER->CameraRelativePointY(_y)+35, Patroltile * 3, Patroltile * 4);  //Ÿ�� ������ ��ŭ ��������
					break;
				case EDIRECTION_UP:
					//����
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)-250, CAMERAMANAGER->CameraRelativePointY(_y)-25, Patroltile * 4, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
					break;
				case EDIRECTION_RIGHT:
					//��
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)-25, CAMERAMANAGER->CameraRelativePointY(_y)-250, Patroltile * 3, Patroltile * 4); //Ÿ�� ������ ��ŭ ��������
					break;
				case EDIRECTION_DOWN:
					//������
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)+50, CAMERAMANAGER->CameraRelativePointY(_y)-25, Patroltile * 4, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
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
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)-250, CAMERAMANAGER->CameraRelativePointY(_y)-25, Patroltile * 4, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
				}
				break;
				case EDIRECTION_UP:
				{
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)-25, CAMERAMANAGER->CameraRelativePointY(_y)-250, Patroltile * 3, Patroltile * 4); //Ÿ�� ������ ��ŭ ��������
				}
				break;
				case EDIRECTION_RIGHT:
				{
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)+50, CAMERAMANAGER->CameraRelativePointY(_y)-25, Patroltile * 4, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
				}
				break;
				case EDIRECTION_DOWN:
				{
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x)-25, CAMERAMANAGER->CameraRelativePointY(_y)+50, Patroltile * 3, Patroltile * 4); //Ÿ�� ������ ��ŭ �������� 
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
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) - 250, CAMERAMANAGER->CameraRelativePointY(_y) - 25, Patroltile * 4, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
				}
				break;
				case EDIRECTION_UP:
				{
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) - 25, CAMERAMANAGER->CameraRelativePointY(_y) - 250, Patroltile * 3, Patroltile * 4); //Ÿ�� ������ ��ŭ ��������
				}
				break;
				case EDIRECTION_RIGHT:
				{
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) + 50, CAMERAMANAGER->CameraRelativePointY(_y) - 25, Patroltile * 4, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
				}
				break;
				case EDIRECTION_DOWN:
				{
					_DetectRc = RectMake(CAMERAMANAGER->CameraRelativePointX(_x) - 25, CAMERAMANAGER->CameraRelativePointY(_y) + 50, Patroltile * 3, Patroltile * 4); //Ÿ�� ������ ��ŭ �������� 
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
			if (pleyer.left + ((pleyer.right - pleyer.left) / 2) > CAMERAMANAGER->CameraRelativePointX(_x) && pleyer.top + ((pleyer.bottom - pleyer.top) / 2) > CAMERAMANAGER->CameraRelativePointY(_y))
			{
				_edirection = EDIRECTION_RIGHT;
				_DetectRc = RectMake(_x + 50, _y - 25, Patroltile * 4, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
																						//_animation->stop();
			}
			if (pleyer.left + ((pleyer.right - pleyer.left) / 2) > CAMERAMANAGER->CameraRelativePointX(_x) &&  pleyer.top + ((pleyer.bottom - pleyer.top) / 2) < CAMERAMANAGER->CameraRelativePointY(_y))
			{
				_edirection = EDIRECTION_UP; //_animation->stop();
				_DetectRc = RectMake(_x - 25, _y - 250, Patroltile * 3, Patroltile * 4); //Ÿ�� ������ ��ŭ ��������
			}
			if (pleyer.left + ((pleyer.right - pleyer.left) / 2) < CAMERAMANAGER->CameraRelativePointX(_x) &&  pleyer.top + ((pleyer.bottom - pleyer.top) / 2)> CAMERAMANAGER->CameraRelativePointY(_y))
			{
				_edirection = EDIRECTION_DOWN; //_animation->stop();
				_DetectRc = RectMake(_x - 25, _y + 30, Patroltile * 3, Patroltile * 4); //Ÿ�� ������ ��ŭ �������� 
			}
			if (pleyer.left + ((pleyer.right - pleyer.left) / 2) < CAMERAMANAGER->CameraRelativePointX(_x) &&  pleyer.top + ((pleyer.bottom - pleyer.top) / 2) < CAMERAMANAGER->CameraRelativePointY(_y))
			{
				_edirection = EDIRECTION_LEFT; //_animation->stop();
				_DetectRc = RectMake(_x - 250, _y - 25, Patroltile * 4, Patroltile * 3); //Ÿ�� ������ ��ŭ ��������
			}
		}
		else if (_eCondistion == ECondision_Hited)
		{
			dellay++;
			if (dellay > 80) {
				_eCondistion = ECondision_Detect;
				dellay = 0;
			}
		}
	}
	/*RECT temp;
	if (IntersectRect(&temp, &_DetectRc, &pleyer))
	{
		_animation->stop();
		setECondistion(ECondision_Detect);
		_animation->onceStart();
		
	}
	else
	{

		
		
	}*/
	
}


