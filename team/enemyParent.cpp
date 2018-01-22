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
	_eCondistion = ECondision_Patrol;
	_isDeath = false;
	_count = 0;
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
	float elapsedTime = TIMEMANAGER->getElapsedTime();
	float moveSpeed = elapsedTime * _EnemySpeed;
	if (_eCondistion == ECondision_Patrol)
	{
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
	}
	else if (_eCondistion == ECondision_Ditect)
	{
		switch (_edirection)
		{
		case EDIRECTION_LEFT:
		{
			_x -= moveSpeed*2;
		}
		break;
		case EDIRECTION_UP:
		{
			_y -= moveSpeed*2;
		}
		break;
		case EDIRECTION_RIGHT:
		{
			_x += moveSpeed*2;
		}
		break;
		case EDIRECTION_DOWN:
		{
			_y += moveSpeed*2;
		}
		break;
		default:
			break;
		}
	}
	
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
