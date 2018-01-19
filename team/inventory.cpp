#include "stdafx.h"
#include "inventory.h"
#include "player.h"

inventory::inventory()
{
}


inventory::~inventory()
{

}

HRESULT inventory::init()
{
	IMAGEMANAGER->addImage("inventory", "./image/item/인벤토리.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("select", "./image/item/아이템선택.bmp", 100, 73, true, RGB(255, 0, 255));
	_bow = new bow;
	_bow->init();

	_boomerang = new boomerang;
	_boomerang->init();

	_potion = new potion;
	_potion->init();

	_vItem.push_back(_boomerang);
	_vItem.push_back(_bow);	
	_vItem.push_back(_potion);

	_cursor = _count = 0;
	_x = 150; _y = 50;
	_index = 0;
	_visibleItemNum = 0;
	_invenOpen = false;
	_money = 300;
	//for (int i = 0; i < _vItem.size(); i++)
	//{
	//	//아이템이 보이지 않으면 컨티뉴
	//	if (!_vItem[i]->getIsVisible()) continue;

	//	
	//	_visibleItemNum++;
	//}
	return S_OK;
}
void inventory::release()
{

}
void inventory::update()
{
	//아이템이 0개면
	if (!_visibleItemNum)
	{
		for (int i = 0; i < _vItem.size(); i++)
		{
			//아이템이 보이지 않으면 컨티뉴
			if (!_vItem[i]->getIsVisible()) continue;


			_visibleItemNum++;
			break;
		}
	}


	//아이템이 한개이상 있으면
	if (_visibleItemNum)
	{
		for (int i = 0; i < _vItem.size(); i++)
		{
			//아이템이 보이지 않으면 컨티뉴
			if (!_vItem[i]->getIsVisible()) continue;

			_vItem[i]->update();
		}
		//커서 깜빡임 업데이트
		_count++;
		if (_count % 30 == 0 && _visibleItemNum != 0)
		{
			if (_cursor == false) _cursor = true;
			else _cursor = false;

			_count = 0;
		}

		if (KEYMANAGER->isOnceKeyDown('Z') || KEYMANAGER->isOnceKeyDown('X'))
		{
			//퀵슬롯 등록
			_mainPlayer->setQuickItemMemoryAddressLink(_vItem[_index]);
			_invenOpen = false;
		}
		//아이템 커서 이동 
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) /*&& _visibleItemNum != 0*/)
		{
			_index++;
			//인덱스 범위 초과 예외처리
			if (_index > _vItem.size()-1) _index = 0;

			while (!_vItem[_index]->getIsVisible())
			{
				//인덱스 범위 초과 예외처리
				if (_index > _vItem.size()-1) _index = 0;
				//미 획득 상태면
				if (!_vItem[_index]->getIsVisible())
				{
					//다음 아이템을 가르켜라
					_index++;
				}

			}
		}

		if (KEYMANAGER->isOnceKeyDown(VK_LEFT) /*&& _visibleItemNum != 0*/)
		{
			_index--;
			//인덱스 범위 초과 예외처리
			if (_index < 0) _index = _vItem.size() - 1;

			while (!_vItem[_index]->getIsVisible())
			{
				//인덱스 범위 초과 예외처리
				if (_index < 0) _index = _vItem.size() - 1;

				//미 획득 상태면
				if (!_vItem[_index]->getIsVisible())
				{
					//다음 아이템을 가르켜라
					_index--;
				}
			}
		}
	}
}
void inventory::render()
{
	IMAGEMANAGER->findImage("inventory")->render(getMemDC());

	for (int i = 0; i < _vItem.size(); ++i)
	{
		if (_vItem[i]->getIsVisible())
			_vItem[i]->getItemInvenImage()->render(getMemDC(), 150 + 100 * i, 30);
	}
	_vItem[_index]->getItemRightTopImage()->render(getMemDC(), 1014, 18);

	if (_cursor)
	IMAGEMANAGER->findImage("select")->render(getMemDC(),_x + 100* _index,50);
}