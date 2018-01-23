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
	_vSampleTr = NULL;
	_vSampleObj = NULL;
	_vSampleCharacter = NULL;
	_vSampleEvent = NULL;
	frameCount = 0;
	timeCount = 0;
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

	timeCount++;
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
				_vSampleTile[i]->objInfo->_image->render(getToolMemDC(), _vSampleTile[i]->rc.left, _vSampleTile[i]->rc.top, _vSampleTile[i]->objInfo->imageIndex.x, _vSampleTile[i]->objInfo->imageIndex.y,
					TILESIZE * _vSampleTile[i]->objInfo->VOLUME.x + _vSampleTile[i]->objInfo->_offSet.x, TILESIZE * _vSampleTile[i]->objInfo->VOLUME.y + _vSampleTile[i]->objInfo->_offSet.y);

				if (KEYMANAGER->isToggleKey(VK_F1))
					Rectangle(getToolMemDC(), _vSampleTile[i]->rc.left, _vSampleTile[i]->rc.top, _vSampleTile[i]->rc.right, _vSampleTile[i]->rc.bottom);
				break;
			case TILE_EVENT:
				break;
			case TILE_CHARACTER:
				_vSampleTile[i]->chrInfo->_image->frameRender(getToolMemDC(), _vSampleTile[i]->rc.left, _vSampleTile[i]->rc.top, (timeCount / 10) % _vSampleTile[i]->chrInfo->_image->getMaxFrameX(), 0);
				break;
			case TILE_DECORATION:
				Rectangle(getToolMemDC(), _vSampleTile[i]->rc.left, _vSampleTile[i]->rc.top, _vSampleTile[i]->rc.right, _vSampleTile[i]->rc.bottom);
				_vSampleTile[i]->decoInfo->_image->render(getToolMemDC(), _vSampleTile[i]->rc.left, _vSampleTile[i]->rc.top,
					_vSampleTile[i]->decoInfo->imageIndex[timeCount / 10 % _vSampleTile[i]->decoInfo->imageIndex.size()].x, _vSampleTile[i]->decoInfo->imageIndex[timeCount / 10 % _vSampleTile[i]->decoInfo->imageIndex.size()].y,
					TILESIZE, TILESIZE);
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

BOOL SelectTile::keyDownUpdate(int key)
{
	switch (key)
	{
	case VK_LBUTTON:
		for (int i = 0; i < _vSampleTile.size(); i++)
		{
			if (PtInRect(&_vSampleTile[i]->rc, _ptMouse))
			{
				currentTileInfo = _vSampleTile[i];
				return true;
			}
		}
		break;
	}
	return false;
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