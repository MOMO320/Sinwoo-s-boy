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
	image*		 _Image;					//적의 이미지
	RECT		 _ImageRc;					//적의 피격 렉트  width는 웬만하면 타일의 사이즈 만큼 맞춰주세요
	animation*   _animation;
	RECT		 _AtkRc;					//적의 공격 렉트
	EDIRECTION   _edirection;

	float		 _x;						//적의 좌표X
	float		 _y;						//적의 좌표Y
	float		 _EnemySpeed;				//적의 스피드

	int			 _MAXHP;					//적의 최대 피격횟수
	int			 _CrrentHP;					//적의 현재 체력
	int			 _AtkPoint;					//적의 공격력
	int			 _Agro;						//적의 어그로 <- 쓰실분들만 쓰세요;
	
	int			 _count;					//움직임 시간초
	bool		  visible;					//렉트 보이게 하는 함수;
	*/
	_Image = IMAGEMANAGER->addFrameImage("빨간눈알", "./image/Monster/빨간눈알.bmp", 600, 52, 12, 1, true, RGB(255, 0, 255));
	_ImageRc = RectMake(300, 300, _Image->getFrameWidth(), _Image->getFrameHeight());
	_animation = new animation;
	_animation->init(_Image->getWidth(), _Image->getHeight(), _Image->getFrameWidth(), _Image->getFrameHeight());
	_edirection = EDIRECTION_LEFT;
	_MAXHP = _CrrentHP = 1;
	_AtkPoint = 1;
	_EnemySpeed = 50;

	_isDeath = false;
	_animation->start();
	_animation->setFPS(1);
	_x = _ImageRc.left + ((_ImageRc.right - _ImageRc.left) / 2);
	_y = _ImageRc.top + ((_ImageRc.bottom - _ImageRc.top) / 2);

	return S_OK;
}
void redEye::draw()
{
	_Image->aniRender(getMemDC(), _ImageRc.left, _ImageRc.top, _animation);
}
void redEye::aniArri()
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
void redEye::move()
{

}
void redEye::Pattern()
{

}