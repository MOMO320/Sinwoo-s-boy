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
void enemyParent::update(RECT player)
{
	/*if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		_patrolIndex++;
		if (_patrolIndex >= _vPatrol->size())
			_patrolIndex = 0;
	}*/

	/*
		//내가 갈곳이 오른쪽인가
		if ((*_vPatrol)[_patrolIndex].x < (*_vPatrol)[_patrolIndex+1].x)
		{
			
			_edirection = EDIRECTION_RIGHT;
			_x += moveSpeed;
		}

		//내가 갈곳이 왼쪽인가
		else if ((*_vPatrol)[_patrolIndex].x >(*_vPatrol)[_patrolIndex + 1].x)
		{
			_edirection = EDIRECTION_LEFT;
			_x -= moveSpeed;
		}

		//내가 갈곳이 아래쪽인가
		else if ((*_vPatrol)[_patrolIndex].y < (*_vPatrol)[_patrolIndex + 1].y)
		{
			_edirection = EDIRECTION_DOWN;
			_y += moveSpeed;
		}

		//내가 갈곳이 위쪽인가 
		else if ((*_vPatrol)[_patrolIndex].y >(*_vPatrol)[_patrolIndex + 1].y)
		{
			_edirection = EDIRECTION_UP;
			_y -= moveSpeed;
		}
	*/
	int idX = _x / 50; //밟고있는 x인덱스
	int idY = _y / 50; //밟고있는 y인덱스

	//1씩 증가하다가 패트롤 벡터의 사이즈에 도달하면 1씩 감소
	if (!_reverse && _patrolIndex == _vPatrol->size()-1)
	{
		_reverse = true;
	}
	//1씩 감소하다가 인덱스가 0에 도달하면 1씩 증가
	else if (_reverse && _patrolIndex == 0)
	{
		_reverse = false;
	}

	//오른쪽으로 가고 있는중
	if (_edirection == EDIRECTION_RIGHT)
	{
		//X만 비교하면 됨
		if (idX > (*_vPatrol)[_patrolIndex].x)
		{
			if (!_reverse)	_patrolIndex++;
			else _patrolIndex--;
		}
		
	}
	//왼쪽으로 가고 있는 중
	if (_edirection == EDIRECTION_LEFT)
	{
		//X만 비교하면 됨
		if (idX < (*_vPatrol)[_patrolIndex].x)
		{
			if (!_reverse)	_patrolIndex++;
			else _patrolIndex--;
		}
	}
	//위로 가고 있는 중
	if (_edirection == EDIRECTION_UP)
	{
		//y만 비교하면 됨
		if (idY < (*_vPatrol)[_patrolIndex].y)
		{
			if (!_reverse)	_patrolIndex++;
			else _patrolIndex--;
		}
	}
	//아래로 가고 있는 중
	if (_edirection == EDIRECTION_DOWN)
	{
		//y만 비교하면 됨
		if (idY > (*_vPatrol)[_patrolIndex].y)
		{
			if (!_reverse)	_patrolIndex++;
			else _patrolIndex--;
		}
	}
	_animation->frameUpdate(TIMEMANAGER->getElapsedTime() * 2);
	aniArri();
	move(player);
	//_ImageRc = RectMakeCenter(_x, _y, _Image->getFrameWidth(), _Image->getFrameHeight());
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
