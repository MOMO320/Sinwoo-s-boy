#include "stdafx.h"
#include "objectParent.h"


objectParent::objectParent()
{
}


objectParent::~objectParent()
{
}



HRESULT objectParent::init()
{

	return S_OK;
}

HRESULT objectParent::init(POINT point, player* player)
{

	return S_OK;
}



void objectParent::release()
{
}

void objectParent::update()
{
	//move();
	//open();
	//hide();
}

void objectParent::render()
{

}

void objectParent::removeObject(int arrNum)
{
	_vObject.erase(_vObject.begin() + arrNum);
}
