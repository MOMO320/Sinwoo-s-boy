#include "stdafx.h"
#include "objectManager.h"
#include "enemyManager.h"
#include "player.h"

objectManager::objectManager()
{
}
objectManager::~objectManager()
{
}

HRESULT objectManager::init(player* player) {

	// To. 수빈이 형에게
	// 형님 오브젝트가 많으면 많을수록 관리하기가 어려워져서 제가 따로 오브젝트 매니저를 만들었습니다.
	// 생성하는 건 밑에 보이시는 것처럼 set으로 해당좌표랑 player만 고정해주시면 끄읏~(개꿀~)
	// 형님이 해주셔야하는 것은, bottle.cpp에 가시면 제가 무브함수를 따로 만들어놧습니다.
	// 그것 보시고 나머지 던지는 오브젝트도 똑같이 그런식으로 move() 를 만들어주시면 됩니다 ^^
	// 주말에 연락드리고싶었으나, 카톡이... 뜨든!!!
	// 암튼 모르는것 있으면 언제나 물어봐주세영♡
	// From. 태호
	// *추신 : 이제 오브젝트 매니저 있으니깐, 메인게임에서 따로 만들어 주실필요는 없는 것같습니다 ^^
	//		   뿌잉

	_countDelay = 0;
	_isRemove = false;				//처음에는 재거하면 안된다  

	setBottle(PointMake(700, 1000), player);
	setBush  (PointMake(800, 1000), player);
	setBox   (PointMake(900, 1000), player);
	setGBox  (PointMake(1000, 1000), player);
	setStone (PointMake(1100, 1000), player);

	return S_OK;
}

void objectManager::release() {

}

void objectManager::update() {

	//deleteObject();
	enemyobject();

	for (int i = 0; i < _vObParent.size(); ++i) {
		//_vObParent[i]->update();
	}
	
}

void objectManager::render() {

	for (int i = 0; i < _vObParent.size(); ++i) 
	{
		_vObParent[i]->render();
	}

}

void objectManager::setBottle(POINT pos, player* player) {

	objectParent* obBottle;
	obBottle = new bottle;
	obBottle->init(pos, player);
	
	_vObParent.push_back(obBottle);

}
void objectManager::setBox(POINT pos, player* player) {
	
	objectParent* obBox;
	obBox = new box;
	obBox->init(pos, player);

	_vObParent.push_back(obBox);
}

void objectManager::setStone(POINT pos, player* player) {

	objectParent* obStone;
	obStone = new stone;
	obStone->init(pos, player);

	_vObParent.push_back(obStone);

}

void objectManager::setGBox(POINT pos, player* player) {

	objectParent* obGBox;
	obGBox = new gbox;
	obGBox->init(pos, player);

	_vObParent.push_back(obGBox);

}

void objectManager::setBush(POINT pos, player* player) {

	objectParent* obBush;
	obBush = new bush;
	obBush->init(pos, player);

	_vObParent.push_back(obBush);

}

void objectManager::deleteObject() {

	for (int i = 0; i < _vObParent.size(); ++i) {
		
		if (_vObParent[i]->getThrowDistance() >= 300) {
			deleteObject(i);
			break;
		}

		if (_vObParent[i]->getIsAttack()) {
			_isRemove = true;
			_arrNum = i;
			break;
		}

	}

	if (_isRemove) {
		_countDelay++;

		if (_countDelay % 20 == 0) {
			deleteObject(_arrNum);
			_countDelay = 0;
			_isRemove = false;
		}
	}

}

void objectManager::deleteObject(int arrNum) {
	SAFE_DELETE(_vObParent[arrNum]);
	_vObParent.erase(_vObParent.begin() + arrNum);
}

void objectManager::enemyobject()
{
	RECT temp;
	
	for (int i = 0; i < _em->getVEnemy().size(); ++i) {
		for (int j = 0; j < _vObParent.size(); ++j) {

			if (IntersectRect(&temp, &_em->getVEnemy()[i]->getRcBodyEnemy(), &_vObParent[j]->getObjectRC())) {
				_em->getVEnemy()[i]->backmove(_vObParent[j]->getCarryX(), _vObParent[j]->getCarryY());
				_em->getVEnemy()[i]->setCrrentHP(1);
				deleteObject(j);
				break;
			}
		}
	}
}


void objectManager::removeDelay() {

}