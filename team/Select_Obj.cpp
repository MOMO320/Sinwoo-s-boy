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

	TCHAR* items[] = { TEXT("오브젝트지형"),TEXT("STOP"),TEXT("PICK") };

	_comboBox = CreateWindow("combobox", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, TOOLSIZEX - 500, 70, 155, 80, _hWnd, HMENU(BTN_COMBOBOX), _hInstance, NULL);

	for (int i = 0; i < 3; i++)
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

			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_NONE);
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
			vObjInfo* _vSampleTr = TILEMANAGER->findObject_Index(OBJECT_STOP);
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
				temp->rc = RectMake(TOOLSIZEX - 500 + (i % 5)*TILESIZE, 100 + (i / 5) * (TILESIZE + 5), TILESIZE, TILESIZE);
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