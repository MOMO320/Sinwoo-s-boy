#include "stdafx.h"
#include "redEye.h"


redEye::redEye()
{
}


redEye::~redEye()
{

}

HRESULT redEye::init()
{
	/*
	image*		 _Image;					//���� �̹���
	RECT		 _ImageRc;					//���� �ǰ� ��Ʈ  width�� �����ϸ� Ÿ���� ������ ��ŭ �����ּ���
	animation*   _animation;
	RECT		 _AtkRc;					//���� ���� ��Ʈ
	EDIRECTION   _edirection;

	float		 _x;						//���� ��ǥX
	float		 _y;						//���� ��ǥY
	float		 _EnemySpeed;				//���� ���ǵ�

	int			 _MAXHP;					//���� �ִ� �ǰ�Ƚ��
	int			 _CrrentHP;					//���� ���� ü��
	int			 _AtkPoint;					//���� ���ݷ�
	int			 _Agro;						//���� ��׷� <- ���Ǻе鸸 ������;
	
	int			 _count;					//������ �ð���
	bool		  visible;					//��Ʈ ���̰� �ϴ� �Լ�;
	*/
	_Image = IMAGEMANAGER->addFrameImage("��������", "./image/Monster/��������.bmp", 600, 52, 12, 1, true, RGB(255, 0, 255));
	_ImageRc = RectMake(900, 800, _Image->getFrameWidth(), _Image->getFrameHeight());
	_animation = new animation;
	_animation->init(_Image->getWidth(), _Image->getHeight(), _Image->getFrameWidth(), _Image->getFrameHeight());
	_edirection = EDIRECTION_NONE;
	_MAXHP = _CrrentHP = 1;
	_AtkPoint = 1;
	_EnemySpeed = 50;

	_isDeath = false;
	_animation->start();
	_animation->setFPS(1);
	_x = _ImageRc.left + ((_ImageRc.right - _ImageRc.left) / 2);
	_y = _ImageRc.top + ((_ImageRc.bottom - _ImageRc.top) / 2);

	//----------------------------------------------------
	//������ ���� �̴�
	//-----------------------------------------------------
	_immunCount = 0;
	_isDetect = false;
	_detectedRC = RectMakeCenter(_x, _y, 300, 300);

	aniInit();

	return S_OK;
}
void redEye::draw()
{
	//Rectangle(getMemDC(), _detectedRC.left, _detectedRC.top, _detectedRC.right, _detectedRC.bottom);
	//_Image->aniRender(getMemDC(), _ImageRc.left, _ImageRc.top, _animation);	
	_Image->aniRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_ImageRc.left), CAMERAMANAGER->CameraRelativePointY(_ImageRc.top), _animation);	
	char test[120];
	sprintf(test, "%d, %d, %d", _animation->getNowPlayIndex(), _ptMouse.x + CAMERAMANAGER->getCameraPoint().x, _ptMouse.y+CAMERAMANAGER->getCameraPoint().y);
	TextOut(getMemDC(), 200, 100, test, strlen(test));
	//to_string(_animation->getFramePos().x);
}
void redEye::aniArri()
{
	//_animation->get
	switch (_edirection)
	{
	case EDIRECTION_LEFT:
	{
							_animation = _ActionAnimation[LEFT];
							/*_animation->start();
							/*int arrAni[] = { 4, 5 };
							_animation->setPlayFrame(arrAni, 2, true);
							_animation->onceStart();*/
	}
		break;
	case EDIRECTION_UP:
	{
						  _animation = _ActionAnimation[TOP];
						  /* _animation->start();
						 /* int arrAni[] = { 9,10,11,10 };
						  _animation->setPlayFrame(arrAni, 4, true);
						  _animation->onceStart();*/
	}
		break;
	case EDIRECTION_RIGHT:
	{
							 _animation = _ActionAnimation[RIGHT];
							 /*_animation->start();
							/* int arrAni[] = {2, 3 };
							 _animation->setPlayFrame(arrAni, 2, true);
							 _animation->onceStart();*/
	}
		break;
	case EDIRECTION_DOWN:
	{
							_animation = _ActionAnimation[DOWN];
							/*_animation->start();
							/*int arrAni[] = {6,7,8,7 };
							_animation->setPlayFrame(arrAni, 4, true);
							_animation->onceStart();*/
	}
		break;
	case EDIRECTION_NONE:
		{
						
							//Ž�� ���� ��Ȳ�̸�
							if (!_isDetect)
							{
								_animation = _ActionAnimation[NODETECT];
								/*_animation->start();
								/*int arrAni[] = { 0 };
								_animation->setPlayFrame(arrAni, 1, true);*/
							}
							//Ž��������
							else
							{
								_animation = _ActionAnimation[DETECT];
								/*_animation->start();
								/*int arrAni[] = { 0, 1, 7, 7 };
								_animation->setPlayFrame(arrAni, 4, false);*/
							}
							//_animation->onceStart();
			
		}break;
	}
}

void redEye::Pattern()
{
	//1. ��ҿ� �� ���� ����
	//2. Ž�� ��Ʈ�� �÷��̾� ������ ���� --- �̶����� ����
	//3. �÷��̾����� �ٰ���
	//4. ���� �Ÿ� �������� �ٽ� ������ ����

	//�����ൿ�̳�
	if (_edirection == EDIRECTION_NONE)
	{
		//Ž�������� ��������
		if (_isDetect)
		{			
			//���� �������� ������
			if (_animation->getNowPlayIndex() == 3)
			{
				_edirection = EDIRECTION_LEFT;
				//_animation->stop();
			}			
		}
		//Ž�������� �ȵ�� ������ ��� Ž��
		else
		{
			/*RECT temp;
			if (IntersectRect(&temp, &_detectedRC, ))*/
			if (PtInRect(&_detectedRC,
				_cameraPtMouse))
	/*			PointMake(_ptMouse.x + CAMERAMANAGER->getCameraPoint().x, _ptMouse.y + CAMERAMANAGER->getCameraPoint().y)))*/
			{
				_isDetect = true;
			}
		}
	}
	//�����ൿ ���� �ൿ�ε� Ž������ �����
	else
	{
		if (!PtInRect(&_detectedRC, 
			_cameraPtMouse))
			/*PointMake(_ptMouse.x + CAMERAMANAGER->getCameraPoint().x, _ptMouse.y + CAMERAMANAGER->getCameraPoint().y)))*/
		{
			_isDetect = false;
			_edirection = EDIRECTION_NONE;
			//_animation->stop();
		}

		//Ž�������� ���Դ�.
		//����� �ൿ����
		else
		{
			float moveSpeed = TIMEMANAGER->getElapsedTime() *_EnemySpeed;
			_immunCount++;
			if (_cameraPtMouse.x > _x && _cameraPtMouse.y > _y)
			{
				_edirection = EDIRECTION_RIGHT;
				//_animation->stop();
			}
			if (_cameraPtMouse.x > _x && _cameraPtMouse.y < _y)
			{
				_edirection = EDIRECTION_UP; //_animation->stop();
			}
			if (_cameraPtMouse.x < _x && _cameraPtMouse.y > _y)
			{
				_edirection = EDIRECTION_DOWN; //_animation->stop();
			}
			if (_cameraPtMouse.x < _x && _cameraPtMouse.y < _y)
			{
				_edirection = EDIRECTION_LEFT; //_animation->stop();
			}

			_x += cosf(getAngle(_x, _y, _cameraPtMouse.x, _cameraPtMouse.y /*, _x, _y*/)) * moveSpeed;
			_y += -sinf(getAngle(_x, _y, _cameraPtMouse.x, _cameraPtMouse.y /*, _x, _y*/)) * moveSpeed;
			_detectedRC = RectMakeCenter(_x, _y, 300, 300);

			if (_immunCount == 200)
			{				
				_edirection = EDIRECTION_NONE;
				_immunCount = 0;
			}
		}
	}
}

void redEye::aniInit()
{
	int leftAni[] = { 4, 5 };
	_ActionAnimation[LEFT] = new animation;
	_ActionAnimation[LEFT]->init(_Image->getWidth(), _Image->getHeight(), _Image->getFrameWidth(), _Image->getFrameHeight());
	_ActionAnimation[LEFT]->start();
	_ActionAnimation[LEFT]->setFPS(1);
	_ActionAnimation[LEFT]->setPlayFrame(leftAni, 2, true);

	int topAni[] = { 9, 10, 11, 10 };
	_ActionAnimation[TOP] = new animation;
	_ActionAnimation[TOP]->init(_Image->getWidth(), _Image->getHeight(), _Image->getFrameWidth(), _Image->getFrameHeight());
	_ActionAnimation[TOP]->start();
	_ActionAnimation[TOP]->setFPS(1);
	_ActionAnimation[TOP]->setPlayFrame(topAni, 4, true);

	int rightAni[] = { 2, 3 };
	_ActionAnimation[RIGHT] = new animation;
	_ActionAnimation[RIGHT]->init(_Image->getWidth(), _Image->getHeight(), _Image->getFrameWidth(), _Image->getFrameHeight());
	_ActionAnimation[RIGHT]->start();
	_ActionAnimation[RIGHT]->setFPS(1);
	_ActionAnimation[RIGHT]->setPlayFrame(rightAni, 2, true);

	int downAni[] = { 6, 7, 8, 7 };
	_ActionAnimation[DOWN] = new animation;
	_ActionAnimation[DOWN]->init(_Image->getWidth(), _Image->getHeight(), _Image->getFrameWidth(), _Image->getFrameHeight());
	_ActionAnimation[DOWN]->start();
	_ActionAnimation[DOWN]->setFPS(1);
	_ActionAnimation[DOWN]->setPlayFrame(downAni, 4, true);

	int noDetectAni[] = { 0 };
	_ActionAnimation[NODETECT] = new animation;
	_ActionAnimation[NODETECT]->init(_Image->getWidth(), _Image->getHeight(), _Image->getFrameWidth(), _Image->getFrameHeight());
	_ActionAnimation[NODETECT]->start();
	_ActionAnimation[NODETECT]->setFPS(1);
	_ActionAnimation[NODETECT]->setPlayFrame(noDetectAni, 1, true);

	int detectAni[] = { 0, 1, 7, 7 };
	_ActionAnimation[DETECT] = new animation;
	_ActionAnimation[DETECT]->init(_Image->getWidth(), _Image->getHeight(), _Image->getFrameWidth(), _Image->getFrameHeight());
	_ActionAnimation[DETECT]->start();
	_ActionAnimation[DETECT]->setFPS(1);
	_ActionAnimation[DETECT]->setPlayFrame(detectAni, 4, true);
}