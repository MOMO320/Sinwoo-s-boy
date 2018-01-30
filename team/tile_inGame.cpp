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
	index = { x,y };
	rc = RectMake(index.x*TILESIZE, index.y* TILESIZE, TILESIZE, TILESIZE);
	timeCount = 0;
	return S_OK;
}

void tile_inGame::release()
{
}

void tile_inGame::update()
{
	timeCount++;
}

void tile_inGame::render()
{
	//타일 클리핑 화면밖영역 랜더링 X
	int cameraX, cameraY;
	cameraX = CAMERAMANAGER->getCameraPoint().x;
	cameraY = CAMERAMANAGER->getCameraPoint().y;
	bool render = false;
	POINT clippingStart, clippingEnd;
	clippingStart = { cameraX,cameraY };
	clippingEnd = { cameraX + WINSIZEX ,cameraY + WINSIZEY };

	if (rc.right > clippingStart.x && rc.left < clippingEnd.x
		|| rc.bottom > clippingStart.y && rc.top < clippingEnd.y) render = true;

	if (render)
	{
		//지형 랜더
		if (_terrain.TR_INDEX != TR_NONE)
		{
			_terrain._image->render(getMemDC(), rc.left - cameraX, rc.top - cameraY,
				_terrain.imageIndex[timeCount / 10 % _terrain.maxFrame].x, _terrain.imageIndex[timeCount / 10 % _terrain.maxFrame].y,
				TILESIZE, TILESIZE);
		}

		//데코 랜더
		for (int i = 0; i < 4; i++)
		{
			if (_deco[i].DECO_INDEX != DECO_NONE)
			{
				_deco[i]._image->render(getMemDC(), rc.left - cameraX, rc.top - cameraY,
					_deco[i].imageIndex[timeCount / 10 % _deco[i].maxFrame].x, _deco[i].imageIndex[timeCount / 10 % _deco[i].maxFrame].y,
					TILESIZE, TILESIZE);
			}
		}

		//오브젝트 랜더
		if (_object.OBJ_INDEX != OBJECT_NONE && _object._parent.x == index.x && _object._parent.y == index.y)
		{
			_object._image->render(getMemDC(), rc.left - TILESIZE* (_object.VOLUME.x - 1) - _object._offset.x - cameraX,
				rc.top - TILESIZE* (_object.VOLUME.y - 1) - _object._offset.y - cameraY,
				_object.imageIndex[timeCount / 10 % _object.maxFrame].x, _object.imageIndex[timeCount / 10 % _object.maxFrame].y,
				_object.VOLUME.x*TILESIZE + _object._offset.x, _object.VOLUME.y* TILESIZE + _object._offset.y);
		}
	}

}

void tile_inGame::loadTile(SAVELOAD_TILE loadTile)
{
	if (TILEMANAGER->findTerrain(loadTile.tr_key) != NULL)
	{
		tagTile_tr tempTR = *TILEMANAGER->findTerrain(loadTile.tr_key);
		//지형
		_terrain.TR_INDEX = tempTR.TR_INDEX;
		_terrain._image = tempTR._image;
		_terrain.imageIndex = tempTR.imageIndex;
		_terrain.isFrame = tempTR.isFrame;
		_terrain.maxFrame = tempTR.maxFrame;
	}
	if (TILEMANAGER->findObj(loadTile.obj_key) != NULL)
	{
		tagTile_obj tempObj = *TILEMANAGER->findObj(loadTile.obj_key);
		//오브젝트
		_object.OBJ_INDEX = tempObj.OBJ_INDEX;
		_object._image = tempObj._image;
		_object.imageIndex = tempObj.imageIndex;
		_object._offset = tempObj._offSet;
		_object.isFrame = tempObj.isFrame;
		_object._parent = loadTile.obj_parent;
		_object.maxFrame = tempObj.maxFrame;
		_object.VOLUME = tempObj.VOLUME;

	}
	tagTile_deco tempDeco[4];
	for (int i = 0; i < 4; i++)
	{
		if (TILEMANAGER->findDec(loadTile.deco_key[i]) != NULL)
		{
			tempDeco[i] = *TILEMANAGER->findDec(loadTile.deco_key[i]);
			//데코
			_deco[i].DECO_INDEX = tempDeco[i].DECO_INDEX;
			_deco[i]._image = tempDeco[i]._image;
			_deco[i].imageIndex = tempDeco[i].imageIndex;
			_deco[i]._offset = tempDeco[i]._offset;
			_deco[i].isFrame = tempDeco[i].isFrame;
			_deco[i].maxFrame = tempDeco[i].maxFrame;
			weight += tempDeco[i].weight;
		}
		if (weight >= 15) weight = 15;
	}

	//이벤트
	_event.EVENT_INDEX = loadTile.EVENT_INDEX;
	_event.ACT_INDEX = loadTile.ACT_INDEX;
	_event.next = loadTile.next;
	_event.param1 = loadTile.event_param1;

}

