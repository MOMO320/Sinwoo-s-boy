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
	SelectTile::init();
	_vSampleTr = NULL;
	_vSampleObj = NULL;
	needFind = true;

	TCHAR* items[] = { TEXT("필드"),TEXT("나무"),TEXT("PICK") , TEXT("캐슬") , TEXT("캐슬파츠"),TEXT("캐슬파츠2"),
		TEXT("캐슬파츠3"), TEXT("캐슬파츠4"),TEXT("캐슬파츠5"),TEXT("캐슬파츠6"),TEXT("캐슬파츠7"),TEXT("캐슬파츠8"),
		TEXT("다리"),TEXT("성문"),TEXT("정원"),TEXT("마을장식"),TEXT("던전부품"),
		TEXT("던전벽타일"),TEXT("던전벽타일(이음새)"),TEXT("던전벽타일(모서리)"),TEXT("집내부"),
	TEXT("집내부2"),TEXT("집내부3")};

	_comboBox = CreateWindow("combobox", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, TOOLSIZEX - 500, 70, 155, 1200, _hWnd, HMENU(BTN_COMBOBOX), _hInstance, NULL);

	for (int i = 0; i < 24; i++)
	{
		SendMessage(_comboBox, CB_ADDSTRING, 0, (LPARAM)items[i]);
	}

	return S_OK;
}

void Select_Obj::release()
{
	SelectTile::release();
}

void Select_Obj::update()
{
	SelectTile::update();

	switch (ComboBox_GetCurSel(_comboBox))
	{
	case 0:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);

			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_OUTSIDE);
			currentTileInfo = NULL;

			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 1:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_TREE);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 2:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_PICK);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5) * TILESIZE * 2, 100 + (i / 5) * (TILESIZE), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 3:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_CASTLE);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 4:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_CASTLEPART);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 5:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_CASTLEPART2);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 6:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_CASTLEPART3);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 7:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_CASTLEPART4);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 8:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_CASTLEPART5);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 9:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_CASTLEPART6);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 10:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_CASTLEPART7);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 11:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_CASTLEPART8);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 12:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_BRIDGE);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 13:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_ENTRANCE);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 14:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_GARDEN);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE * 2, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 15:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_TOWN);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 1)*TILESIZE, 100 + (i) * (TILESIZE + 5) * 2.5, TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 16:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_DENGEON);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i / 6)*TILESIZE * 2, 100 + (i % 6) * (TILESIZE + 5) * 2, TILESIZE, TILESIZE);
				if (i == 5)temp->rc = RectMake(TOOLSIZEX - 500 + (i / 5)*TILESIZE * 2, 100 + (TILESIZE + 5) * 2, TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 17:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_DENGEON2);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 18:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_DENGEON3);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 19:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_DENGEON4);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE * 2, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 20:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_HOUSE);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE * 2, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 21:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_HOUSE1);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE * 2, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	case 22:
		if (needFind) {
			if (_vSampleTr != NULL) SAFE_DELETE(_vSampleTr);
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_HOUSE2);
			currentTileInfo = NULL;
			sampleVectorClear();

			for (int i = 0; i < _vSampleTr->size(); i++)
			{
				lpSampleInfo temp = new sampleInfo;
				temp->tileClass = TILE_OBJECT;
				temp->objInfo = (*_vSampleTr)[i];
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 1)*TILESIZE, 100 + (i % 5) * (TILESIZE + 50), TILESIZE, TILESIZE);
				_vSampleTile.push_back(temp);
			}

			needFind = false;
		}
		break;
	}
}

void Select_Obj::render()
{
	SelectTile::render();


}