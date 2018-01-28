#include "stdafx.h"
#include "aStar.h"


aStar::aStar()
{
}


aStar::~aStar()
{
}


HRESULT aStar::init(int enemyIdX, int enemyIdY, int playerIdX, int playerIdY)
{
	setTiles(enemyIdX, enemyIdY,playerIdX,playerIdY);

	return S_OK;
}

void aStar::setTiles(int enemyIdX , int enemyIdY, int playerIdX, int playerIdY)
{
	_startTile = new aStarTile;

	_startTile->init(enemyIdX, enemyIdY);// 좌표 받아서 타일의 총 개수로 나눠서 인덱스로 변경해줘야함
	_startTile->setAttribute("start");

	_endTile = new aStarTile;
	_endTile->init(playerIdX, playerIdY);//  플레이어 좌표 받아서 타일개수로 나눠서 인덱스 화

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

			int currentTile = (startY * TILENUMX) + startX + j + (i * TILENUMX);

			if (!_node->getIsOpen()) continue;
			if (_node->getAttribute() == "start") continue;
			if (_node->getAttribute() == "wall") continue;

			if (_vTotalList[currentTile + 1]->getAttribute() == "wall") continue;
			if (_vTotalList[currentTile + TILENUMX]->getAttribute() == "wall") continue;
			if (_vTotalList[currentTile + TILENUMX + 1]->getAttribute() == "wall") continue;


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

	return  _vOpenList;
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

		_vOpenList[i]->setTotalCost(_vOpenList[i]->getCostToGoal() + _vOpenList[i]->getCostFromStart());

		if (tempTotalCost > _vOpenList[i]->getTotalCost())
		{
			tempTotalCost = _vOpenList[i]->getTotalCost();
			tempTile = _vOpenList[i];	
		}

		bool addObj = true;
		for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
		{
			if (*_viOpenList == tempTile)
			{
				addObj = false;
				break;
			}
		}

		_vOpenList[i]->setIsOpen(false);
		if (!addObj) continue;

		_vOpenList.push_back(tempTile);
	}

	if (tempTile->getAttribute() == "end")
	{
		while (_currentTile->getParentNode() != NULL)
		{
			_currentTile->setcolor(RGB(22, 14, 128));
			_currentTile = _currentTile->getParentNode();
		}
		return;
	}
	_vCloseList.push_back(tempTile);

	for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
	{
		if (*_viOpenList == tempTile)
		{
			_viOpenList = _vOpenList.erase(_viOpenList);
			break;
		}
	}
	_currentTile = tempTile;
}

void aStar::release() 
{
}
void aStar::update()  
{
	if (KEYMANAGER->isOnceKeyDown('S')) _start = true;// pathFinder(_currentTile); 

	if (_start)
	{
		_count++;
		if (_count % 10 == 0)
		{
			pathFinder(_currentTile);
			_count = 0;
		}
	}
}
void aStar::render()  
{
	for (int i = 0; i < _vTotalList.size(); ++i)
	{
		_vTotalList[i]->render();
	}
}