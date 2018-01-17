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
	currentTileInfo = NULL;
	return S_OK;
}

void SelectTile::release()
{
	DestroyWindow(_comboBox);
}

void SelectTile::update()
{
	comboIndex = ComboBox_GetCurSel(_comboBox);
	if (comboIndex != PcomboIndex)
	{
		PcomboIndex = comboIndex;
		needFind = true;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < _vSampleTile.size(); i++)
		{
			if (PtInRect(&_vSampleTile[i]->rc, _ptMouse))
			{
				currentTileInfo = _vSampleTile[i];
			}
		}
	}
	
}

void SelectTile::render()
{
	if (_vSampleTile.size() != 0)
	{
		for (int i = 0; i < _vSampleTile.size(); i++)
		{
			switch (_vSampleTile[i]->tileClass)
			{
			case TILE_TERRAIN:
				_vSampleTile[i]->trInfo->_image->render(getToolMemDC(), _vSampleTile[i]->rc.left, _vSampleTile[i]->rc.top, _vSampleTile[i]->trInfo->imageIndex.x, _vSampleTile[i]->trInfo->imageIndex.y, TILESIZE, TILESIZE);
				break;
			case TILE_OBJECT:
				break;
			case TILE_EVENT:
				break;
			case TILE_CHARACTER:
				break;
			case TILE_END:
				break;
			default:
				break;
			}
		}
	}

	for (int i = 0; i < _vSampleTile.size(); i++)
	{
		if (PtInRect(&_vSampleTile[i]->rc, _ptMouse))
		{
			RectangleMake(getToolMemDC(), _ptMouse.x, _ptMouse.y, 80, 60);
			char str[128];
			sprintf(str, "%d %d", _vSampleTile[i]->trInfo->imageIndex.x, _vSampleTile[i]->trInfo->imageIndex.y);
			TextOut(getToolMemDC(), _ptMouse.x + 10, _ptMouse.y + 10, str, strlen(str));
		}
	}

	if (currentTileInfo != NULL)
	{
		RectangleMake(getToolMemDC(), _ptMouse.x, _ptMouse.y, 80, 60);
		char str[128];
		sprintf(str, "%d %d", currentTileInfo->trInfo->imageIndex.x, currentTileInfo->trInfo->imageIndex.y);
		TextOut(getToolMemDC(), _ptMouse.x + 10, _ptMouse.y + 10, str, strlen(str));
	}
	
}

void SelectTile::sampleVectorClear()
{
	for (int i = 0; i < _vSampleTile.size(); ++i)
	{
		delete _vSampleTile[i];
		_vSampleTile[i] = NULL;
	}

	_vSampleTile.clear();
}

