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
	TCHAR* items[] = { TEXT("����Ʈž"), TEXT("����Ʈ����"),TEXT("����Ʈž"),
		TEXT("����Ʈ����"),TEXT("��"),TEXT("����"),TEXT("����(UNMOVE)"),TEXT("�������(����UNMOVE)"),
		TEXT("�������2"),TEXT("�������3"),TEXT("�������4"),TEXT("�������5"),
		TEXT("�������6"),TEXT("�������7"),TEXT("�������8"),TEXT("�������9"),
		TEXT("�������10"),TEXT("�������11"),TEXT("�������12"),TEXT("��ٴ�"),TEXT("��ٴ�2"),
		TEXT("���ٹ���"),TEXT("���ٹ���2"),TEXT("���ٹ���3") ,TEXT("���ٹ���4"),TEXT("���ٹ���5"),
		TEXT("��׸���1"),TEXT("��׸���2"),TEXT("��׸���3"),TEXT("��輱1"),
		TEXT("��輱2") ,TEXT("��輱3") };
	
	_comboBox = CreateWindow("combobox", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, TOOLSIZEX - 500, 70, 155, 1200, _hWnd, HMENU(BTN_COMBOBOX), _hInstance, NULL);
	
	for (int i = 0; i < 34; i++)
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
	case 7:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_HILL);
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
	case 8:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_HILL2);
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
	case 9:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_HILL3);
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
	case 10:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_HILL4);
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
	case 11:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_HILL5);
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
	case 12:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_HILL6);
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
	case 13:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_HILL7);
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
	case 14:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_HILL8);
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
	case 15:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_HILL9);
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
	case 16:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_HILL10);
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
	case 17:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_HILL11);
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
	case 18:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_HILL12);
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
	case 19:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_ROAD);
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
	case 20:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_ROAD2);
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
	case 21:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_LINE);
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
	case 22:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_LINE2);
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
	case 23:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_LINE3);
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
	case 24:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_LINE4);
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
	case 25:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_LINE5);
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
	case 26:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_SHADOW);
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
	case 27:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_SHADOW2);
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
	case 28:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_SHADOW3);
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
	case 29:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_BORDER);
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
	case 30:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_BORDER2);
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
	case 31:
		if (needFind)
		{
			if (_vSampleTr != NULL)SAFE_DELETE(_vSampleTr);

			vDecInfo * _vSampleDeco = TILEMANAGER->findDeco_Index(DECO_BORDER3);
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