#include "stdafx.h"
#include "Select_TR.h"


Select_TR::Select_TR()
{
}


Select_TR::~Select_TR()
{
}


HRESULT Select_TR::init()		  
{
	_tileImage = NULL;

	TCHAR* items[] = { TEXT("기본지형"),TEXT("절벽") };

	_comboBox = CreateWindow("combobox", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, TOOLSIZEX - 500, 70, 155, 80, _hWnd, HMENU(BTN_COMBOBOX), _hInstance, NULL);
	
	for (int i = 0; i < 2; i++)
	{
		SendMessage(_comboBox, CB_ADDSTRING, 0, (LPARAM)items[i]);
	}

	return S_OK;
}

void Select_TR::release()		  
{
	DestroyWindow(_comboBox);
}

void Select_TR::update()		  
{
	switch (ComboBox_GetCurSel(_comboBox))
	{
	case 0:
		_tileImage = IMAGEMANAGER->findImage("기본타일");
		break;
	case 1:
		_tileImage = IMAGEMANAGER->findImage("절벽");
		break;
	}
}

void Select_TR::render()		  
{
	SelectTile::render();


}