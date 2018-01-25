#include "stdafx.h"
#include "objectParent.h"
#include "player.h"


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

HRESULT objectParent::init(POINT point)
{

	return S_OK;
}



void objectParent::release()
{
}

void objectParent::update()
{
	move();
	open();
	//hide();
}

void objectParent::render()
{

}
