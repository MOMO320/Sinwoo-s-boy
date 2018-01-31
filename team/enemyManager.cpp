#include "stdafx.h"
#include "enemyManager.h"
#include"player.h"
#include"objectManager.h"
enemyManager::enemyManager()
{
	IGMAP->setEraseEnemy([&]()mutable->void { removeAll(); });
	IGMAP->setEnemyInitF([&](POINT p, vector<POINT>* vp)mutable->void {setGreenSolider(p, vp); });

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
		(*_viEnemy)->update(_player);
	}

	collision();
	crrentHPCheck();
}
void enemyManager::render()	
{
	for (int i = 0; i < _vMoney.size(); ++i  )
	{
		_vMoney[i]->render();
	}
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->render();
	}
	EFFECTMANAGER->render();
	TextOut(getMemDC(), 200, 200, str, strlen(str));

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
		Bsolder->init(PointMake(700 + 50*i, 700 + 50*i), i);

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
		// ºí·ç ³ªÀÌÆ® ¾î±×·Î
		if (IntersectRect(&temp, &_vEnemy[i]->getDetectRc(), &_player->getPlayerRC()))
		{
			for (int j = 0; j < _vAgro.size(); j++)
			{
				if (*_vEnemy[j]->getAggro() == -1) continue;
				else {
					if (*_vEnemy[i]->getAggro() < 0) continue;
					_vEnemy[j]->getAni()->stop();
					_vEnemy[j]->setECondistion(ECondision_Detect);
					_vEnemy[j]->getAni()->onceStart();

				}
			}
		}
		else 
		{
			if (*_vEnemy[i]->getAggro() == -1) continue;
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
	int rndNum = RND->getFromIntTo(0, 99);
	//blue 1 red 10 orange 5 4 3 2 1
	//40ÆÛ È®·ü
	if (rndNum < 40)
	{
		itemParent* tempMoney = new blueMoney;
		tempMoney->init(_vEnemy[arrNum]->getImageRC().left + ((_vEnemy[arrNum]->getImageRC().right - _vEnemy[arrNum]->getImageRC().left) / 2)
			, _vEnemy[arrNum]->getImageRC().top + ((_vEnemy[arrNum]->getImageRC().bottom - _vEnemy[arrNum]->getImageRC().top) / 2));
	}
	else if (40 <= rndNum && rndNum < 70)
	{
		itemParent* tempMoney = new orangeMoney;
		tempMoney->init(_vEnemy[arrNum]->getImageRC().left + ((_vEnemy[arrNum]->getImageRC().right - _vEnemy[arrNum]->getImageRC().left) / 2)
			, _vEnemy[arrNum]->getImageRC().top + ((_vEnemy[arrNum]->getImageRC().bottom - _vEnemy[arrNum]->getImageRC().top) / 2));
	}
	else if ( 70 <= rndNum && rndNum < 90)
	{
		itemParent* tempMoney = new redMoney;
		tempMoney->init(_vEnemy[arrNum]->getImageRC().left + ((_vEnemy[arrNum]->getImageRC().right - _vEnemy[arrNum]->getImageRC().left) / 2)
			, _vEnemy[arrNum]->getImageRC().top + ((_vEnemy[arrNum]->getImageRC().bottom - _vEnemy[arrNum]->getImageRC().top) / 2));
	}
	EFFECTMANAGER->play("Á×À½¶ì",
		CAMERAMANAGER->CameraRelativePointX(_vEnemy[arrNum]->getImageRC().left + ((_vEnemy[arrNum]->getImageRC().right - _vEnemy[arrNum]->getImageRC().left) / 2)),
		CAMERAMANAGER->CameraRelativePointY(_vEnemy[arrNum]->getImageRC().top + ((_vEnemy[arrNum]->getImageRC().bottom - _vEnemy[arrNum]->getImageRC().top) / 2)));
	_vEnemy.erase(_vEnemy.begin() + arrNum);
	_vAgro.erase(_vAgro.begin() + arrNum);
	
}

void enemyManager::removeAll()
{
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		SAFE_DELETE(_vEnemy[i]);
	}
	for (int j= 0; j < _vAgro.size(); j++) {
		SAFE_DELETE(_vAgro[j]);
	}
	_vEnemy.clear();
	_vAgro.clear();
}
