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
	_ImageRc = RectMake(300, 300, _Image->getFrameWidth(), _Image->getFrameHeight());
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

	_immunCount = 0;

	return S_OK;
}
void redEye::draw()
{
	
	_Image->aniRender(getMemDC(), _ImageRc.left, _ImageRc.top, _animation);
	char test[120];
	sprintf(test, "%d", _animation->getNowPlayeIndex());
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
							int arrAni[] = { 4, 5 };
							_animation->setPlayFrame(arrAni, 2, true);

	}
		break;
	case EDIRECTION_UP:
	{
						  int arrAni[] = { 9,10,11,10 };
						  _animation->setPlayFrame(arrAni, 4, true);

	}
		break;
	case EDIRECTION_RIGHT:
	{
							 int arrAni[] = {2, 3 };
							 _animation->setPlayFrame(arrAni, 2, true);

	}
		break;
	case EDIRECTION_DOWN:
	{
							int arrAni[] = {6,7,8,7 };
							_animation->setPlayFrame(arrAni, 4, true);

	}
		break;
	case EDIRECTION_NONE:
		{
			int arrAni[] = { 0, 1 ,7};
			_animation->setPlayFrame(arrAni, 3, false);
		}
		break;
	}
}

void redEye::Pattern()
{
	//�����ൿ�̳�
	if (_edirection == EDIRECTION_NONE)
	{
		if (_animation->getNowPlayeIndex() == 2)
			_edirection = EDIRECTION_LEFT;
	}
}