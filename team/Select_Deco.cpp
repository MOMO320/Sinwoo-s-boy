#include "stdafx.h"
#include "Select_Deco.h"


Select_Deco::Select_Deco()
{
}


Select_Deco::~Select_Deco()
{
}



HRESULT Select_Deco::init()
{
	SelectTile::init();

	vDecInfo* _vSampleDeco = TILEMANAGER->findAllDeco();
	currentTileInfo = NULL;

	sampleVectorClear();

	for (int i = 0; i < _vSampleDeco->size(); i++)
	{
		lpSampleInfo temp = new sampleInfo;
		temp->tileClass = TILE_DECORATION;
		temp->decoInfo = (*_vSampleDeco)[i];
		temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
		_vSampleTile.push_back(temp);
	}

	needFind = false;

	return S_OK;
}
void Select_Deco::release()
{
}
void Select_Deco::update()
{
	SelectTile::update();
}
void Select_Deco::render()
{
	SelectTile::render();


}