#include "stdafx.h"
#include "SelectTile.h"


SelectTile::SelectTile()
	: needFind(false)
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

	
	
}

void SelectTile::render()
{
	if (_vSampleTile.size() != 0) // 샘플타일부분.
	{
		for (int i = 0; i < _vSampleTile.size(); i++)
		{
			switch (_vSampleTile[i]->tileClass)
			{
			case TILE_TERRAIN:
				_vSampleTile[i]->trInfo->_image->render(getToolMemDC(), _vSampleTile[i]->rc.left, _vSampleTile[i]->rc.top, _vSampleTile[i]->trInfo->imageIndex.x, _vSampleTile[i]->trInfo->imageIndex.y, TILESIZE, TILESIZE);
				break;
			case TILE_OBJECT:
				_vSampleTile[i]->objInfo->_image->render(getToolMemDC(), _vSampleTile[i]->rc.left , _vSampleTile[i]->rc.top, _vSampleTile[i]->objInfo->imageIndex.x, _vSampleTile[i]->objInfo->imageIndex.y, 
					TILESIZE * _vSampleTile[i]->objInfo->VOLUME.x, TILESIZE * _vSampleTile[i]->objInfo->VOLUME.y);

				if (KEYMANAGER->isToggleKey(VK_F1))
					Rectangle(getToolMemDC(), _vSampleTile[i]->rc.left, _vSampleTile[i]->rc.top, _vSampleTile[i]->rc.right, _vSampleTile[i]->rc.bottom);
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
			//if (_vSampleTile[i]->tileClass != TR_NONE)
			//{
			//	char str[128];
			//	sprintf(str, "%d %d", _vSampleTile[i]->trInfo->imageIndex.x, _vSampleTile[i]->trInfo->imageIndex.y);
			//	TextOut(getToolMemDC(), _ptMouse.x + 10, _ptMouse.y + 10, str, strlen(str));
			//}
		}
	}

	
	
}

void SelectTile::keyDownUpdate(int key)
{
	switch(key)
	{
	case VK_LBUTTON:
		for (int i = 0; i < _vSampleTile.size(); i++)
		{
			if (PtInRect(&_vSampleTile[i]->rc, _ptMouse))
			{
				currentTileInfo = _vSampleTile[i];
			}
		}
	break;
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

