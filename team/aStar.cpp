#include "stdafx.h"
#include "aStar.h"


aStar::aStar()
{
}


aStar::~aStar()
{
}


HRESULT aStar::init()
{
	setTiles();

	return S_OK;
}

void aStar::setTiles(int enemyIdX , int enemyIdY, int playerIdX, int playerIdY)
{
	_startTile = new aStarTile;
	_startTile->init(enemyIdX, enemyIdY) 좌표 받아서 타일의 총 개수로 나눠서 인덱스로 변경해줘야함
	_startTile->setAttribute("start");

	_endTile = new aStarTile;
	_endTile->init(playerIdX, playerIdY);  플레이어 좌표 받아서 타일개수로 나눠서 인덱스 화
	_endTile->setAttribute("end");

	_currentTile = _startTile;

	for (int i = 0; i < 50 /* Y타일 갯수*/; ++i)
	{
		for (int j = 0; j < 50;/*X 타일 갯수*/ ++j)
		{
			if (j == _startTile->getIdX() && i == _startTile->getIdY())
			{
				_startTile->setcolor(RGB(0, 255, 255));
				_vTotalList.push_back(_startTile);
				continue;
			}
			if (j == _endTile->getIdX() && i == _endTile->getIdY())
			{
				_endTile->setcolor(RGB(10, 120, 55));
				_vTotalList.push_back(_endTile);
				continue;
			}
			aStarTile* _node = new aStarTile;
			_node->init(j, i);
			_vTotalList.push_back(_node);
		}
	}


}

vector<aStarTile*> aStar::addOpenList(aStarTile* currentTile)
{
}

void aStar::pathFinder(aStarTile* currentTile)
{
}

void aStar::release() 
{
}
void aStar::update()  
{
}
void aStar::render()  
{
}