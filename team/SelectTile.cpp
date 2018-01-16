#include "stdafx.h"
#include "SelectTile.h"


SelectTile::SelectTile()
{
}


SelectTile::~SelectTile()
{
}


HRESULT SelectTile::init()	 
{
	

	return S_OK;
}

void SelectTile::release()	 
{
	DestroyWindow(_comboBox);
}

void SelectTile::update()	 
{
}

void SelectTile::render()	 
{
	if(_tileImage != NULL)
	_tileImage->render(getToolMemDC(), 1000, 110,0,0,_tileImage->getWidth(),_tileImage->getHeight());

}

