#include "stdafx.h"
#include "enemyManager.h"


enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{

}


HRESULT enemyManager::init()
{
	_GreenSolider = new GreenSolider();
	_GreenSolider->init();
	_backMoveCount = 0;
	return S_OK;
}
void enemyManager::release()
{

}
void enemyManager::update()
{
	_GreenSolider->update();
	collision();
}
void enemyManager::render()	
{
	_GreenSolider->render();
	TextOut(getMemDC(), 200, 200, str, strlen(str));
}

void enemyManager::collision()
{
	_backMoveCount++;
	sprintf_s(str, "_backMoveCount : %d", _backMoveCount);
	RECT temp;
	if (IntersectRect(&temp, &_GreenSolider->getImageRC(), &RectMake(_ptMouse.x, _ptMouse.y, 50, 50)))
	{
		_GreenSolider->backmove(_ptMouse.x, _ptMouse.y , _GreenSolider->getImageRC().left, _GreenSolider->getImageRC().top);
		_GreenSolider->setECondistion(ECondision_Hited);
		_GreenSolider->getAni()->stop();
	}
	if (_GreenSolider->getECondistion() == ECondision_Hited)
	{
		if (_backMoveCount > 80)
		{
			_GreenSolider->setECondistion(ECondision_Ditect);
			_backMoveCount = 0;
		}
	}
}
