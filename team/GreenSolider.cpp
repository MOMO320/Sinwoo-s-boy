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
	//"./image/item/È°(ÀÎº¥,½½·Ô).bmp"
	_Image = IMAGEMANAGER->addFrameImage("³ì»öº´»ç", "./image/Monster/GreenSoldier.bmp", 900, 79, 16, 1, true, RGB(255, 0, 255));
	_ImageRc = RectMake(WINSIZEX / 2, WINSIZEY / 2, _Image->getFrameWidth(), _Image->getFrameHeight());
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

void GreenSolider::draw()
{
	_Image->aniRender(getMemDC(), _ImageRc.left, _ImageRc.top, _animation);
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

}


