#include "stdafx.h"
#include "tile_inGame.h"


tile_inGame::tile_inGame()
{
}


tile_inGame::~tile_inGame()
{
}

HRESULT tile_inGame::init(int x, int y)
{
	return E_NOTIMPL;
}

void tile_inGame::release()
{
}

void tile_inGame::update()
{
}

void tile_inGame::render()
{
}

void tile_inGame::loadTile(SAVELOAD_TILE loadTile)
{
	tagTile_tr tempTR = *TILEMANAGER->findTerrain(loadTile.tr_key);
	tagTile_obj tempObj = *TILEMANAGER->findObj(loadTile.obj_key);
	tagTile_deco tempDeco[4];
	for (int i = 0; i < 4; i++)
	{
		tempDeco[i] = *TILEMANAGER->findDec(loadTile.deco_key[i]);
	}
	
	//지형
	_terrain.TR_INDEX = tempTR.TR_INDEX;
	_terrain._image = tempTR._image;
	_terrain.imageIndex = tempTR.imageIndex;
	_terrain.isFrame = tempTR.isFrame;
	_terrain.maxFrame = tempTR.maxFrame;
	
	//오브젝트
	_object.OBJ_INDEX = tempObj.OBJ_INDEX;
	_object._image = tempObj._image;
	_object.imageIndex = tempObj.imageIndex;
	_object._offset = tempObj._offSet;
	_object.isFrame = tempObj.isFrame;
	_object._parent = tempObj._parent;
	_object.maxFrame = tempObj.maxFrame;

	//데코
	for (int i = 0; i < 4; i++)
	{
		_deco[i].DECO_INDEX = tempDeco[i].DECO_INDEX;
		_deco[i]._image = tempDeco[i]._image;
		_deco[i].imageIndex = tempDeco[i].imageIndex;
		_deco[i]._offset = tempDeco[i]._offset;
		_deco[i].isFrame = tempDeco[i].isFrame;
		_deco[i].maxFrame = tempDeco[i].maxFrame;
	}

	//이벤트
	_event.EVENT_INDEX = loadTile.EVENT_INDEX;
	_event.ACT_INDEX = loadTile.ACT_INDEX;
	_event.next = loadTile.next;
	_event.param1 = loadTile.event_param1;

}

