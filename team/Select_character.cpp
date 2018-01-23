#include "stdafx.h"
#include "Select_character.h"


Select_character::Select_character()
{
}


Select_character::~Select_character()
{
}

HRESULT Select_character::init()		 
{
	SelectTile::init();

	vCharInfo* _vSampleChar = TILEMANAGER->findAllCharacter();
	currentTileInfo = NULL;

	sampleVectorClear();

	for (int i = 0; i < _vSampleChar->size(); i++)
	{
		lpSampleInfo temp = new sampleInfo;
		temp->tileClass = TILE_CHARACTER;
		temp->chrInfo = (*_vSampleChar)[i];
		temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
		_vSampleTile.push_back(temp);
	}

	needFind = false;

	return S_OK;
}
void Select_character::release()		 
{
}
void Select_character::update()			 
{
	SelectTile::update();
}
void Select_character::render()			 
{
	SelectTile::render();


}
