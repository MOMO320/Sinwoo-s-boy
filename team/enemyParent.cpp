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

HRESULT enemyParent::init(POINT potinsion, int derection)
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
	_ImageRc = RectMakeCenter(_x, _y, _Image->getFrameWidth(), _Image->getFrameHeight());

}
void enemyParent::update(RECT player)
{
	_animation->frameUpdate(TIMEMANAGER->getElapsedTime() * 2);
	aniArri();
	move(player);
	_ImageRc = RectMakeCenter(_x, _y, _Image->getFrameWidth(), _Image->getFrameHeight());
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
	Pattern();
}
void enemyParent::move(RECT player)
{
	Pattern(player);
}
void enemyParent::backmove(int PlayerX, int PlayerY)
{
	_animation->stop();
	float elapsedTime = TIMEMANAGER->getElapsedTime();
	float moveSpeed = elapsedTime * _EnemySpeed;
	_eCondistion = ECondision_Hited;
	if (_eCondistion == ECondision_Hited)
	{
		_x += cosf(getAngle(PlayerX, PlayerY, _x, _y))  * (moveSpeed *80);
		_y += -sinf(getAngle(PlayerX, PlayerY, _x, _y)) * (moveSpeed *80);
	}
	_animation->onceStart();

}
void enemyParent::Pattern()
{

}

void enemyParent::Pattern(RECT player)
{
}
