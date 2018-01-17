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
	currentTileTr = NULL;
	currentTileObj = NULL;

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
	if (_vSampleTr != NULL)
	{
		for (int i = 0; i < _vSampleTr->size(); i++)
		{
			(*_vSampleTr)[i]->_image->render(getToolMemDC(), TOOLSIZEX - 500 + (i % 5) * (TILESIZE+5), 100 + (i / 5) * (TILESIZE+5), (*_vSampleTr)[i]->imageIndex.x, (*_vSampleTr)[i]->imageIndex.y, TILESIZE, TILESIZE);
		}
	}
}

