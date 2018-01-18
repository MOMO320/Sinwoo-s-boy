#include "stdafx.h"
#include "enemyParent.h"


enemyParent::enemyParent()
{
}


enemyParent::~enemyParent()
{

}


HRESULT enemyParent::init(const char* ImageName, POINT postion, EDIRECTION direction, int MAXHP, int AtkPoint)
{
	_Image = IMAGEMANAGER->findImage(ImageName);
	_ImageRc = RectMake(postion.x, postion.y, _Image->getFrameWidth(), _Image->getFrameHeight());
	_animation->setDefPlayFrame();
	_animation->start();
	_animation->setFPS(1);
	//_AtkRc = RectMake();					
	_edirection = direction;
	_MAXHP = _CrrentHP = MAXHP;
	_AtkPoint = AtkPoint;
	_EnemySpeed = 50;

	_isDeath = false;

	return S_OK;
}
void enemyParent::release()
{

}
void enemyParent::aniArri()
{
	switch (_edirection)
	{
	case EDIRECTION_LEFT:
	{
		int arrAni[] = { 8, 9, 10, 11 };
		_animation->setPlayFrame(arrAni, 8, true);

	}
	break;
	case EDIRECTION_UP:
	{
		int arrAni[] = { 12, 13, 14, 15 };
		_animation->setPlayFrame(arrAni, 12, true);

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
		_animation->setPlayFrame(arrAni, 0, true);

	}
	break;
	}
}
void enemyParent::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) {
		visible = true;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) {
		visible = false;
	}
	aniArri();
	move();
	_animation->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
}
void enemyParent::render()
{
	draw();
}
void enemyParent::draw()
{
	if (visible) RectangleMake(getMemDC(), _ImageRc.left, _ImageRc.top, _Image->getFrameWidth(), _Image->getFrameHeight());
	//else _Image->aniRender(getMemDC(), CAMERAMANAGER->CameraRelativePoint(_ImageRc).x, CAMERAMANAGER->CameraRelativePoint(_ImageRc).y,_animation);
	else _Image->aniRender(getMemDC(), _ImageRc.left, _ImageRc.top, _animation);
}
void enemyParent::move()
{
	_x = _ImageRc.left + ((_ImageRc.right - _ImageRc.left) / 2);
	_y = _ImageRc.top + ((_ImageRc.bottom - _ImageRc.top) / 2);
	float elapsedTime = TIMEMANAGER->getElapsedTime();
	float moveSpeed = elapsedTime * _EnemySpeed;

	switch (_edirection)
	{
	case EDIRECTION_LEFT:
	{
		_x -= moveSpeed;
	}
	break;
	case EDIRECTION_UP:
	{
		_y -= moveSpeed;
	}
	break;
	case EDIRECTION_RIGHT:
	{
		_x += moveSpeed;
	}
	break;
	case EDIRECTION_DOWN:
	{
		_y += moveSpeed;
	}
	break;
	default:
		break;
	}

	Pattern();
}
void enemyParent::Pattern()
{
	switch (0)
	{
	case 1:
	{
		//ÆÐÆ®·Ñ
	}
	break;
	}
}
