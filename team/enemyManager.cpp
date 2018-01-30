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
	this->setGreenSolider();
	this->setMace();
	//this->setBlueSolider();
	EFFECTMANAGER->addEffect("Á×À½¶ì", "./image/Monster/ÀûÁ×À½ÀÌÆåÆ®.bmp", 350, 62, 50, 62, 1.0f, 0.1f, 10);
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
	crrentHPCheck();
}
void enemyManager::render()	
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->render();
	}
	EFFECTMANAGER->render();


}

void enemyManager::setGreenSolider()
{
	enemyParent* Gsolder;
	Gsolder = new GreenSolider();
	Gsolder->init(PointMake(700,800),0);
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
		_backMoveCount++;

		RECT temp;
		for (int i = 0; i < _vEnemy.size(); i++)
		{
			if (IntersectRect(&temp, &_vEnemy[i]->getRcBodyEnemy(), &_player->getPlayerRC()))
			{
				_player->setPlayerHP(-1);
			}
			// ºí·ç ³ªÀÌÆ® ¾î±×·Î
			if (IntersectRect(&temp, &_vEnemy[i]->getDetectRc(), &_player->getPlayerRC()))
			{
				for (int j = 0; j < _vAgro.size(); j++)
				{
					if (*_vEnemy[j]->getAggro() == -1)
					{
						
						_vEnemy[j]->setECondistion(ECondision_Detect);
						
					}
					else {
						if (*_vEnemy[i]->getAggro() < 0) continue;
					
						_vEnemy[j]->setECondistion(ECondision_Detect);
					

					}
				}
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
	
}

void enemyManager::crrentHPCheck()
{

	for (int i = 0; i < _vEnemy.size(); i++)
	{
		if (_vEnemy[i]->getCrrentHP() != 0) return;
		else if (_vEnemy[i]->getCrrentHP() <= 0) removeEnemy(i);
	}
}

void enemyManager::removeEnemy(int arrNum)
{

	EFFECTMANAGER->play("Á×À½¶ì",
		CAMERAMANAGER->CameraRelativePointX(_vEnemy[arrNum]->getImageRC().left + ((_vEnemy[arrNum]->getImageRC().right - _vEnemy[arrNum]->getImageRC().left) / 2)),
		CAMERAMANAGER->CameraRelativePointY(_vEnemy[arrNum]->getImageRC().top + ((_vEnemy[arrNum]->getImageRC().bottom - _vEnemy[arrNum]->getImageRC().top) / 2)));
	_vEnemy.erase(_vEnemy.begin() + arrNum);
	_vAgro.erase(_vAgro.begin() + arrNum);
	
}
