#include "stdafx.h"
#include "Select_Obj.h"


Select_Obj::Select_Obj()
{
}


Select_Obj::~Select_Obj()
{
}

HRESULT Select_Obj::init()	 
{
	_tileImage = IMAGEMANAGER->findImage("testObject");
	return S_OK;
}

void Select_Obj::release()	 
{
}

void Select_Obj::update()	 
{
}

void Select_Obj::render()	 
{
	SelectTile::render();


}