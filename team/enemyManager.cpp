#include "stdafx.h"
#include "enemyManager.h"
#include"player.h"
#include"objectManager.h"
enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{

}


HRESULT enemyManager::init()
{
	//this->setGreenSolider();
	//this->setMace();
	//this->setBlueSolider();
	IMAGEMANAGER->addImage("Á×À½¶ì", "./image/Monster/ÀûÁ×À½ÀÌÆåÆ®.bmp", 350, 62, true, RGB(255, 0, 255));
	EFFECTMANAGER->addEffect("Á×À½¶ì", "./image/Monster/ÀûÁ×À½ÀÌÆåÆ®.bmp", 350, 62, 7, 1, 1.0f, 0.1f, 10);
	_backMoveCount = 0;
	return S_OK;
}
void enemyManager::release()
{
	_effect->release();
}
void enemyManager::update()
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->update(_player->getPlayerRC());
	}

	collision();
}
void enemyManager::render()	
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->render();
	}
	EFFECTMANAGER->render();


}

void enemyManager::setGreenSolider(POINT pos, vector<POINT>* vPatrol)
{
	enemyParent* Gsolder;
	Gsolder = new GreenSolider();
	Gsolder->init(PointMake(pos.x * 50 , pos.y * 50 ),0, vPatrol);
	_vEnemy.push_back(Gsolder);
	_vAgro.push_back(Gsolder->getAggro());
}

void enemyManager::setBlueSolider()
{
	for (int i = 0; i < 2; i++)
	{
		enemyParent* Bsolder;
		Bsolder = new BlueSolider();
		Bsolder->init(PointMake(i * 200 + 50, i * 100 + 50), i);

		_vEnemy.push_back(Bsolder);
		_vAgro.push_back(Bsolder->getAggro());
	}
	
}

void enemyManager::setMace()
{
	_Mace = new MaceKnight;
	_Mace->init(PointMake(500, 800), 2);

	_vEnemy.push_back(_Mace);
	_vAgro.push_back(_Mace->getAggro());
}

void enemyManager::collision()
{
	_backMoveCount++;
	
	RECT temp;
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		//if (IntersectRect(&temp, &_vEnemy[i]->getDefRc(), &_player->getPlayerRC()))
		//{
		//	_vEnemy[i]->backmove(_player->getPlayerRC().left, _player->getPlayerRC().top, _vEnemy[i]->getImageRC().left, _vEnemy[i]->getImageRC().top);
		//	_vEnemy[i]->setECondistion(ECondision_Detect);
		//	//_vEnemy[i]->setAggro(50);
		//}
		//else
		//{
		//	_vEnemy[i]->setECondistion(ECondision_Patrol);
		//}

		// ºí·ç ³ªÀÌÆ® ¾î±×·Î
		/*if (IntersectRect(&temp, &_vEnemy[i]->getDetectRc(), &RectMakeCenter(_ptMouse.x, _ptMouse.y,50,50)))
		{
			for (int j = 0; j < _vAgro.size(); j++)
			{
				if (*_vEnemy[j]->getAggro() == -1) continue;
				else {
					if (*_vEnemy[i]->getAggro() < 0 ) continue;
						_vEnemy[j]->getAni()->stop();
						_vEnemy[j]->setECondistion(ECondision_Detect);
						_vEnemy[j]->getAni()->onceStart();
					
					}
			}
		}*/

		

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

	EFFECTMANAGER->play("Á×À½¶ì", _vEnemy[arrNum]->getImageRC().left, _vEnemy[arrNum]->getImageRC().top);
	SAFE_DELETE(_viEnemy[arrNum]);
	_vEnemy.erase(_vEnemy.begin() + arrNum);
	
}
