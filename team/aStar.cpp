#include "stdafx.h"
#include "aStar.h"


aStar::aStar()
{
}


aStar::~aStar()
{
}


HRESULT aStar::init(int enemyPosX, int enemyPosY, int playerPosX, int playerPosY)
{

	setTiles(enemyPosX, enemyPosY, playerPosX, playerPosY);

	return S_OK;
}

void aStar::setTiles(int enemyPosX, int enemyPosY, int playerPosX, int playerPosY)
{
	_startTile = new aStarTile;

	_startTile->init(enemyPosX/ASTARWIDTH, enemyPosY/ASTARHEIGHT);// 좌표 받아서 타일의 총 개수로 나눠서 인덱스로 변경해줘야함
	_startTile->setAttribute("start");


	_endTile = new aStarTile;
	_endTile->init(playerPosX/ ASTARWIDTH, playerPosY/ ASTARHEIGHT);  //플레이어 좌표 받아서 타일개수로 나눠서 인덱스 화

	_endTile->setAttribute("end");

	_currentTile = _startTile;

	for (int i = 0; i < ASTARINFO->getcurrentSize().y; ++i)
	{
		for (int j = 0; j < ASTARINFO->getcurrentSize().x; ++j)
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
			_node->setIsOpen((*ASTARINFO->getcurrentAStar())[j + i * ASTARINFO->getcurrentSize().x]->getIsOpen());
			
			
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
			aStarTile* _node = _vTotalList[(startY * ASTARINFO->getcurrentSize().x) + startX + j+ (i* ASTARINFO->getcurrentSize().x)];

			int currentTile = (startY *ASTARINFO->getcurrentSize().x) + startX + j + (i * ASTARINFO->getcurrentSize().x);

			if (!_node->getIsOpen()) continue;
			if (_node->getAttribute() == "start") continue;
			if (_node->getAttribute() == "wall") continue;

			if (_vTotalList[currentTile + 1]->getIsOpen() != true) continue;
			if (_vTotalList[currentTile + ASTARINFO->getcurrentSize().x]->getIsOpen() != true) continue;
			if (_vTotalList[currentTile + ASTARINFO->getcurrentSize().x + 1]->getIsOpen() != true) continue;


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
	
}
void aStar::render()  
{
	for (int i = 0; i < _vTotalList.size(); ++i)
	{
		_vTotalList[i]->render();
	}
}

aStarTile* aStar::getNextTile()
{ 
	pathFinder(_currentTile);

	return _vCloseList[0];
}