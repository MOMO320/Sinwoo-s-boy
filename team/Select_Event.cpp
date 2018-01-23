#include "stdafx.h"
#include "Select_Event.h"


Select_Event::Select_Event()
{
}


Select_Event::~Select_Event()
{
}


HRESULT Select_Event::init()		 
{
	SelectTile::init();
	_vSampleTr = NULL;
	_vSampleObj = NULL;
	_vSampleCharacter = NULL;
	_vSampleEvent = NULL;

	vTrInfo* _vSampleTr = TILEMANAGER->findTerrain_Index(TR_BASIC);
	currentTileInfo = NULL;

	sampleVectorClear();

	for (int i = 0; i < _vSampleTr->size(); i++)
	{
		lpSampleInfo temp = new sampleInfo;
		temp->tileClass = TILE_TERRAIN;
		temp->trInfo = (*_vSampleTr)[i];
		temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
		_vSampleTile.push_back(temp);
	}

	needFind = false;
	return S_OK;
}
void Select_Event::release()		 
{
}
void Select_Event::update()			 
{
}
void Select_Event::render()			
{
	SelectTile::render();


}
