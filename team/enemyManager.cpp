#include "stdafx.h"
#include "enemyManager.h"
#include"player.h"

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{

}


HRESULT enemyManager::init()
{
	this->setGreenSolider();
	//this->setBlueSolider();
	_backMoveCount = 0;
	return S_OK;
}
void enemyManager::release()
{

}
void enemyManager::update()
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->update();
	}
	//collision();
}
void enemyManager::render()	
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->render();
	}
	//TextOut(getMemDC(), 200, 200, str, strlen(str));
}

void enemyManager::setGreenSolider()
{
	enemyParent* Gsolder;
	Gsolder = new GreenSolider();
	Gsolder->init();
	_vEnemy.push_back(Gsolder);
}

void enemyManager::setBlueSolider()
{
	for (int i = 0; i < 2; i++) {
		enemyParent* Bsolder;
		Bsolder = new BlueSolider();
		Bsolder->init();
		_vEnemy.push_back(Bsolder);
	}
	
}

void enemyManager::collision()
{
	_backMoveCount++;
	sprintf_s(str, "_backMoveCount : %d", _backMoveCount);
	RECT temp;
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		if (IntersectRect(&temp, &_vEnemy[i]->getDetectRc(), &RectMake(_ptMouse.x, _ptMouse.y, 50, 50)))
		{
			_vEnemy[i]->backmove(_ptMouse.x, _ptMouse.y , _vEnemy[i]->getImageRC().left, _vEnemy[i]->getImageRC().top);
			_vEnemy[i]->setECondistion(ECondision_Detect);
			_vEnemy[i]->setAggro(50);
			//_BlueSolider->getAni()->stop();
		}
		else
		{
			_vEnemy[i]->setECondistion(ECondision_Patrol);
		}
		if (_vEnemy[i]->getECondistion() == ECondision_Hited)
		{
			if (_backMoveCount > 80)
			{
				_vEnemy[i]->setECondistion(ECondision_Detect);
				_backMoveCount = 0;
			}
		}
	}
}

void enemyManager::removeEnemy(int arrNum)
{
	SAFE_DELETE(_viEnemy[arrNum]);
	_vEnemy.erase(_vEnemy.begin() + arrNum);
}
