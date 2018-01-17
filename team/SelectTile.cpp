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
	if (_vSampleTr != NULL)
	{
		for (int i = 0; i < _vSampleTr->size(); i++)
		{
			(*_vSampleTr)[i]->_image->render(getToolMemDC(), TOOLSIZEX - 500 + (i % 5) * 50, 100 + (i / 5) * 50, (*_vSampleTr)[i]->imageIndex.x, (*_vSampleTr)[i]->imageIndex.y, 50, 50);
		}
	}
}

