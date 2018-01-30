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

	// To. ������ ������
	// ���� ������Ʈ�� ������ �������� �����ϱⰡ ��������� ���� ���� ������Ʈ �Ŵ����� ��������ϴ�.
	// �����ϴ� �� �ؿ� ���̽ô� ��ó�� set���� �ش���ǥ�� player�� �������ֽø� ����~(����~)
	// ������ ���ּž��ϴ� ����, bottle.cpp�� ���ø� ���� �����Լ��� ���� �����J���ϴ�.
	// �װ� ���ð� ������ ������ ������Ʈ�� �Ȱ��� �׷������� move() �� ������ֽø� �˴ϴ� ^^
	// �ָ��� �����帮��;�����, ī����... �ߵ�!!!
	// ��ư �𸣴°� ������ ������ ������ּ�����
	// From. ��ȣ
	// *�߽� : ���� ������Ʈ �Ŵ��� �����ϱ�, ���ΰ��ӿ��� ���� ����� �ֽ��ʿ�� ���� �Ͱ����ϴ� ^^
	//		   ����

	_countDelay = 0;
	_isRemove = false;				//ó������ ����ϸ� �ȵȴ�  

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