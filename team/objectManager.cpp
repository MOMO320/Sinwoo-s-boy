#include "stdafx.h"
#include "objectManager.h"
#include "enemyManager.h"
#include "player.h"

objectManager::objectManager()
{
	IGMAP->setInitObjectFunc(
		[&](POINT p, player* player)mutable->void {this->setBottle(p, player); },
		[&](POINT p, player* player)mutable->void {this->setBox(p, player); },
		[&](POINT p, player* player)mutable->void {this->setStone(p, player); },
		[&](POINT p, player* player)mutable->void {this->setGBox(p, player); },
		[&](POINT p, player* player)mutable->void {this->setBush(p, player); }
	);
}
objectManager::~objectManager()
{
}

HRESULT objectManager::init(player* player) {

	EFFECTMANAGER->addEffect("항아리부서짐", "./image/object/bottle_broken.bmp", 400, 50, 50, 50, 1.0f, 0.3f, 5);
	EFFECTMANAGER->addEffect("부쉬부서짐", "./image/object/bulmok.bmp", 400, 50, 50, 50, 1.0f, 0.3f, 5);

	setBottle(PointMake(200, 300), player);
	setBush  (PointMake(300, 300), player);
	setBox   (PointMake(400, 300), player);
	setGBox  (PointMake(500, 300), player);
	setStone (PointMake(600, 300), player);

	return S_OK;
}

void objectManager::release() {

}

void objectManager::update() {


	deleteObject();
	enemyobject();

	for (int i = 0; i < _vObParent.size(); ++i) {
		_vObParent[i]->update();
	}
	
}

void objectManager::render() {

	for (int i = 0; i < _vObParent.size(); ++i) 
	{
		_vObParent[i]->render();
	}
	EFFECTMANAGER->render();
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
			removeEffect(_vObParent[i]->getOBJECTTYPE(), CAMERAMANAGER->CameraRelativePointX(_vObParent[i]->getCarryX()), CAMERAMANAGER->CameraRelativePointY(_vObParent[i]->getCarryY()));
			deleteObject(i);
			break;
		}

		if (_vObParent[i]->getIsAttack()) {
			removeEffect(_vObParent[i]->getOBJECTTYPE(), CAMERAMANAGER->CameraRelativePointX(_vObParent[i]->getCarryX()), CAMERAMANAGER->CameraRelativePointY(_vObParent[i]->getCarryY()));
			ASTARINFO->settoOpen(_vObParent[i]->getCarryX() / TILESIZE, _vObParent[i]->getCarryY() / TILESIZE);
			deleteObject(i);
			break;
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
				removeEffect(_vObParent[j]->getOBJECTTYPE(), CAMERAMANAGER->CameraRelativePointX(_vObParent[j]->getCarryX()), CAMERAMANAGER->CameraRelativePointY(_vObParent[j]->getCarryY()));
				deleteObject(j);
				break;
			}
		}
	}
}

void objectManager::removeEffect(OBJECTTYPE objectType, float centerX, float centerY) {

	switch (objectType)
	{
		case BOTTLE:
			EFFECTMANAGER->play("항아리부서짐", centerX, centerY);
			break;

		case BOX:
			break;

		case GBOX:
			break;

		case BUSH:
			EFFECTMANAGER->play("부쉬부서짐", centerX, centerY);
			break;

		case STONE:
			break;

		default:
			break;
	}

}

void objectManager::allObjectClear() {
	for (int i = 0; i < _vObParent.size(); ++i) {
		SAFE_DELETE(_vObParent[i]);
		if (i == _vObParent.size() - 1) {
			_vObParent.clear();
		}
	}
}