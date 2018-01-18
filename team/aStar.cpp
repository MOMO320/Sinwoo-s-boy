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
	//��� ����
	setTiles(1,2,3,4);

	return S_OK;
}

void aStar::setTiles(int enemyIdX , int enemyIdY, int playerIdX, int playerIdY)
{
	_startTile = new aStarTile;
	//_startTile->init(centerX /) ��ǥ �޾Ƽ� Ÿ���� �� ������ ������ �ε����� �����������
	_startTile->setAttribute("start");

	_endTile = new aStarTile;
	//_endTile->init();  �÷��̾� ��ǥ �޾Ƽ� Ÿ�ϰ����� ������ �ε��� ȭ
	_endTile->setAttribute("end");

	_currentTile = _startTile;

	for (int i = 0; i < 50 /* YŸ�� ����*/; ++i)
	{
		for (int j = 0; j < 50;/*X Ÿ�� ����*/ ++j)
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

			//��� ����
			/*aStarTile* _node = new aStarTile;
			_node->init(j, i);
			_vTotalList.push_back(_node);*/
		}
	}


}

//��ż���
//vector<aStarTile*> aStar::addOpenList(aStarTile* currentTile)
//{
//}

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