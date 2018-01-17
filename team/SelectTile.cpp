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

