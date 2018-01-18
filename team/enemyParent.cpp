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
	_animation->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
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

}
