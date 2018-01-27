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

	needFind = false;

	_vSampleTr = NULL;
	_vSampleCharacter = NULL;
	_vSampleDeco = NULL;
	needFind = true;
	TCHAR* items[] = { TEXT("레프트탑"), TEXT("레프트바텀"),TEXT("라이트탑"),
		TEXT("라이트바텀"),TEXT("물"),TEXT("종합"),TEXT("던전(UNMOVE)") };
	
	_comboBox = CreateWindow("combobox", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, TOOLSIZEX - 500, 70, 155, 1200, _hWnd, HMENU(BTN_COMBOBOX), _hInstance, NULL);
	
	for (int i = 0; i < 8; i++)
	{
		SendMessage(_comboBox, CB_ADDSTRING, 0, (LPARAM)items[i]);
	}


	return S_OK;
}
void Select_Deco::release()
{
	DestroyWindow(_comboBox);
}
void Select_Deco::update()
{
	SelectTile::update();

	switch (ComboBox_GetCurSel(_comboBox))
	{
	case 0:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_LEFT_TOP);
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
		}
		break;
	case 1:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_LEFT_BOTTOM);
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
		}
		break;
	case 2:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_RIGHT_TOP);
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
		}
		break;
	case 3:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_RIGHT_BOTTOM);
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
		}
		break;
	case 4:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_WATER);
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
		}
		break;
	case 5:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_EMPTY);
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
		}
		break;
	case 6:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_DENGEON);
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
		}
		break;
	}
}
void Select_Deco::render()
{
	SelectTile::render();


}