#include "stdafx.h"
#include "enemyParent.h"


enemyParent::enemyParent()
{
}


enemyParent::~enemyParent()
{

}


HRESULT enemyParent::init()
{

	return S_OK;
}
void enemyParent::release()
{

}
void enemyParent::aniArri()
{

}
void enemyParent::update()
{
	_animation->frameUpdate(TIMEMANAGER->getElapsedTime() * 2);
	aniArri();
	move();

}
void enemyParent::render()
{
	draw();
}
void enemyParent::draw()
{

}
void enemyParent::move()
{
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

	_ImageRc = RectMakeCenter(_x, _y, _Image->getFrameWidth(), _Image->getFrameHeight());
	Pattern();
}
void enemyParent::Pattern()
{

}
