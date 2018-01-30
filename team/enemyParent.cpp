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
		//���� ������ �������ΰ�
		if ((*_vPatrol)[_patrolIndex].x < (*_vPatrol)[_patrolIndex+1].x)
		{
			
			_edirection = EDIRECTION_RIGHT;
			_x += moveSpeed;
		}

		//���� ������ �����ΰ�
		else if ((*_vPatrol)[_patrolIndex].x >(*_vPatrol)[_patrolIndex + 1].x)
		{
			_edirection = EDIRECTION_LEFT;
			_x -= moveSpeed;
		}

		//���� ������ �Ʒ����ΰ�
		else if ((*_vPatrol)[_patrolIndex].y < (*_vPatrol)[_patrolIndex + 1].y)
		{
			_edirection = EDIRECTION_DOWN;
			_y += moveSpeed;
		}

		//���� ������ �����ΰ� 
		else if ((*_vPatrol)[_patrolIndex].y >(*_vPatrol)[_patrolIndex + 1].y)
		{
			_edirection = EDIRECTION_UP;
			_y -= moveSpeed;
		}
	*/
	int idX = _x / 50; //����ִ� x�ε���
	int idY = _y / 50; //����ִ� y�ε���

	//1�� �����ϴٰ� ��Ʈ�� ������ ����� �����ϸ� 1�� ����
	if (!_reverse && _patrolIndex == _vPatrol->size()-1)
	{
		_reverse = true;
	}
	//1�� �����ϴٰ� �ε����� 0�� �����ϸ� 1�� ����
	else if (_reverse && _patrolIndex == 0)
	{
		_reverse = false;
	}

	//���������� ���� �ִ���
	if (_edirection == EDIRECTION_RIGHT)
	{
		//X�� ���ϸ� ��
		if (idX > (*_vPatrol)[_patrolIndex].x)
		{
			if (!_reverse)	_patrolIndex++;
			else _patrolIndex--;
		}
		
	}
	//�������� ���� �ִ� ��
	if (_edirection == EDIRECTION_LEFT)
	{
		//X�� ���ϸ� ��
		if (idX < (*_vPatrol)[_patrolIndex].x)
		{
			if (!_reverse)	_patrolIndex++;
			else _patrolIndex--;
		}
	}
	//���� ���� �ִ� ��
	if (_edirection == EDIRECTION_UP)
	{
		//y�� ���ϸ� ��
		if (idY < (*_vPatrol)[_patrolIndex].y)
		{
			if (!_reverse)	_patrolIndex++;
			else _patrolIndex--;
		}
	}
	//�Ʒ��� ���� �ִ� ��
	if (_edirection == EDIRECTION_DOWN)
	{
		//y�� ���ϸ� ��
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
