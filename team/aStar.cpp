#include "stdafx.h"
#include "aStar.h"


aStar::aStar()
{
}


aStar::~aStar()
{
}


HRESULT aStar::init(int playerIdX, int playerIdY)
{
	//setTiles(_enemyIdX, _enemyIdY,playerIdX,playerIdY);

	return S_OK;
}

void aStar::setTiles(int enemyIdX , int enemyIdY, int playerIdX, int playerIdY)
{
	_startTile = new aStarTile;
	_startTile->init(enemyIdX, enemyIdY);// 좌표 받아서 타일의 총 개수로 나눠서 인덱스로 변경해줘야함
	_startTile->setAttribute("start");

	_endTile = new aStarTile;
	_endTile->init(playerIdX, playerIdY);  //플레이어 좌표 받아서 타일개수로 나눠서 인덱스 화
	_endTile->setAttribute("end");

	_currentTile = _startTile;

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 20; ++j)
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
	
	int startX = currentTile->getIdX() - 1;
	int startY = currentTile->getIdY() - 1;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			aStarTile* _node = _vTotalList[(startY * TILENUMX) + startX + j+ (i* TILENUMX)];

			if (!_node->getIsOpen()) continue;
			if (_node->getAttribute() == "start") continue;
			if (_node->getAttribute() == "wall") continue;

			_node->setParentNode(_currentTile);

			bool addObj = true;

			for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
			{
				if (*_viOpenList == _node)
				{
					addObj = false;
					break;
				}
			}

			if (_node->getAttribute() != "end") _node->setcolor(RGB(128, 64, 28));
			if (!addObj) continue;

			_vOpenList.push_back(_node);
		}
	}

	return _vOpenList;
}

void aStar::pathFinder(aStarTile* currentTile)
{
	float tempTotalCost = 5000;
	aStarTile* tempTile;

	for (int i = 0; i < addOpenList(currentTile).size(); ++i)
	{
		_vOpenList[i]->setCostToGoal(
			abs(_endTile->getIdX() - _vOpenList[i]->getIdX()) +
			abs(_endTile->getIdY() - _vOpenList[i]->getIdY()) * 10);
		
		POINT center1 = _vOpenList[i]->getParentNode()->getParentNode()->getCenter();
		POINT center2 = _vOpenList[i]->getCenter();
	
		_vOpenList[i]->setCostFromStart((getDistance(center1.x, center1.y, center2.x, center2.y) > ASTARWIDTH) ? 14 : 10);
	}

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