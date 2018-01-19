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
	return S_OK;
}
void enemyManager::release()
{

}
void enemyManager::update()	
{
	_GreenSolider->update();
}
void enemyManager::render()	
{
	_GreenSolider->render();
}