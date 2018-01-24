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
void enemyParent::backmove(int PlayerX, int PlayerY, int enemyX, int enemyY)
{
	float elapsedTime = TIMEMANAGER->getElapsedTime();
	float moveSpeed = elapsedTime * _EnemySpeed;
	_eCondistion = ECondision_Hited;
	if (_eCondistion == ECondision_Hited)
	{
		_x += cosf(getAngle(PlayerX, PlayerY, enemyX, enemyY))  * (moveSpeed *20);
		_y += -sinf(getAngle(PlayerX, PlayerY, enemyX, enemyY)) * (moveSpeed *20);
	}
}
void enemyParent::Pattern()
{

}
