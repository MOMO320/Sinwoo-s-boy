#include "stdafx.h"
#include "enemyParent.h"
#include "player.h"

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
HRESULT enemyParent::init(POINT potinsion, int direction, vector<POINT>*  vPatrol)
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
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		_patrolIndex++;
		if (_patrolIndex > _vPatrol->size())
			_patrolIndex = 0;
	}

	_animation->frameUpdate(TIMEMANAGER->getElapsedTime() * 2);
	aniArri();
	move();
	_ImageRc = RectMakeCenter(_x, _y, _Image->getFrameWidth(), _Image->getFrameHeight());

}
void enemyParent::update(player* player)
{
	_animation->frameUpdate(TIMEMANAGER->getElapsedTime() * 2);
	aniArri();
	move(player);
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
void enemyParent::move(player* player)
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

void enemyParent::Pattern(player* player)
{
}
