#include "stdafx.h"
#include "objectManager.h"
#include "player.h"

objectManager::objectManager()
{
}
objectManager::~objectManager()
{
}

HRESULT objectManager::init(player* player) {

	_bottle = new bottle;
	_bottle->init(PointMake(600, 1000), player);
	_box = new box;
	_box->init(PointMake(700, 1000), player);
	_gbox = new gbox;
	_gbox->init(PointMake(800, 1100), player);
	_bush = new bush;
	_bush->init(PointMake(900, 1000), player);
	_stone = new stone;
	_stone->init(PointMake(1000, 1000), player);

	return S_OK;
}

void objectManager::release() {

}

void objectManager::update() {

	_bottle->update();
	_box->update();
	_gbox->update();
	_bush->update();
	_stone->update();

}

void objectManager::render() {

	_bottle->render();
	_box->render();
	_gbox->render();
	_bush->render();
	_stone->render();

}