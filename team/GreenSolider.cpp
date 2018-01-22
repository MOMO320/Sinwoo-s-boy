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
	_ImageRc = RectMake(WINSIZEX / 2, WINSIZEY / 2, 50, _Image->getFrameHeight());
	_animation = new animation;
	_animation->init(_Image->getWidth(), _Image->getHeight(), _Image->getFrameWidth(), _Image->getFrameHeight());
	_DitectRc = RectMake(0, 0, 0, 0);
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
	_x = _ImageRc.left + ((_ImageRc.right - _ImageRc.left) / 2);
	_y = _ImageRc.top + ((_ImageRc.bottom - _ImageRc.top) / 2);
	return S_OK;
}

void GreenSolider::draw()
{
	_Image->aniRender(getMemDC(), _ImageRc.left, _ImageRc.top, _animation);
	//Rectangle(getMemDC(), _ImageRc.left, _ImageRc.top, _ImageRc.right, _ImageRc.bottom);
	Rectangle(getMemDC(), _AtkRc.left, _AtkRc.top, _AtkRc.right, _AtkRc.bottom);
	//TextOut(getMemDC(), 50, 50, str, strlen(str));
	//TextOut(getMemDC(), 50, 100, str2, strlen(str2));
	TextOut(getMemDC(), 50, 200, str3, strlen(str3));
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
	else if (_eCondistion == ECondision_Ditect)
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

void GreenSolider::Pattern()
{


	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD4)) {
		_edirection = EDIRECTION_LEFT;
	}
	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD6)) {
		_edirection = EDIRECTION_RIGHT;
	}
	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD8)) {
		_edirection = EDIRECTION_UP;
	}
	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD5)) {
		_edirection = EDIRECTION_DOWN;
	}


	NomalCount++;

	if (NomalCount % 24 == 0) {
		frameCount--;
		NomalCount = 0;
	}
	sprintf_s(str3, "_edirection : %d", _edirection);
	if (frameCount <= -1)frameCount = 4;
	switch (frameCount)
	{	//4번째
	case 0:
	{
		switch (_edirection)
		{
		case EDIRECTION_LEFT:
			//업
			_DitectRc = RectMake(_x - 25, _y - 250, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
			break;
		case EDIRECTION_UP:
			//오른쪽
			_DitectRc = RectMake(_x + 50, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
			break;
		case EDIRECTION_RIGHT:
			//다운
			_DitectRc = RectMake(_x - 25, _y + 30, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
			break;
		case EDIRECTION_DOWN:
			//왼쪽
			_DitectRc = RectMake(_x - 250, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
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
			_DitectRc = RectMake(_x - 25, _y + 35, Patroltile * 3, Patroltile * 4);  //타일 사이즈 만큼 조정예정
			break;
		case EDIRECTION_UP:
			//왼쪽
			_DitectRc = RectMake(_x - 250, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
			break;
		case EDIRECTION_RIGHT:
			//업
			_DitectRc = RectMake(_x - 25, _y - 250, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
			break;
		case EDIRECTION_DOWN:
			//오른쪽
			_DitectRc = RectMake(_x + 50, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
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
			_DitectRc = RectMake(_x - 250, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
		}
		break;
		case EDIRECTION_UP:
		{
			_DitectRc = RectMake(_x - 25, _y - 250, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
		}
		break;
		case EDIRECTION_RIGHT:
		{
			_DitectRc = RectMake(_x + 50, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
		}
		break;
		case EDIRECTION_DOWN:
		{
			_DitectRc = RectMake(_x - 25, _y + 30, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정 
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
			_DitectRc = RectMake(_x - 250, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
		}
		break;
		case EDIRECTION_UP:
		{
			_DitectRc = RectMake(_x - 25, _y - 250, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
		}
		break;
		case EDIRECTION_RIGHT:
		{
			_DitectRc = RectMake(_x + 50, _y - 25, Patroltile * 4, Patroltile * 3); //타일 사이즈 만큼 조정예정
		}
		break;
		case EDIRECTION_DOWN:
		{
			_DitectRc = RectMake(_x - 25, _y + 30, Patroltile * 3, Patroltile * 4); //타일 사이즈 만큼 조정예정
		}
		break;
		}
	}
	break;
	}

}


