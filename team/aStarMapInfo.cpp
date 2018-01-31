#include "stdafx.h"
#include "aStarMapInfo.h"


aStarMapInfo::aStarMapInfo()
{
}


aStarMapInfo::~aStarMapInfo()
{
}

HRESULT aStarMapInfo::init(string key,int xSize, int ySize, vector<tile_inGame*>* vtile)
{
	tagAStarMap tempAstarMap;

	tempAstarMap.tileX = xSize*2;
	tempAstarMap.tileY = ySize*2;
	
	POINT _index;
	_index.x = xSize;
	_index.y = ySize;
	for (int i = 0; i < _index.y*2; i++)
	{
		for (int j = 0; j < _index.x*2; j++)
		{
			aStarTile* tempAstar = new aStarTile;

			tile_inGame* temp = (*vtile)[i/2*_index.x + j/2];
			
			tempAstar->setIdX(j);
			tempAstar->setIdY(i);

			if (temp->getiGOBJ().OBJ_INDEX != OBJECT_NONE)
			{
				tempAstar->setIsOpen(false);
				tempAstarMap.vAstarTiles.push_back(tempAstar);
				continue;
			}
			if (temp->getWeight() != 0)
			{
				if (j / 2 == 0 && i / 2 == 0)   
				{
					if(temp->getWeight()%2 == 1)
					tempAstar->setIsOpen(false);
				}
				if (j / 2 == 1 && i / 2 == 0)
				{
					if((temp->getWeight()- temp->getWeight()%2)%4/2 ==1)
						tempAstar->setIsOpen(false);
				}
				if (j / 2 == 0 && i / 2 == 1)
				{
					if ((temp->getWeight() - temp->getWeight() % 4) % 8 / 4 == 1)
						tempAstar->setIsOpen(false);
				}
				if (j / 2 == 1 && i / 2 == 1)
				{
					if ((temp->getWeight() - temp->getWeight() % 8) % 16 / 8 == 1)
						tempAstar->setIsOpen(false);
				}
			}
			tempAstarMap.vAstarTiles.push_back(tempAstar);
		}
	}

	//for (int i = 0; i < _index.y;i++)
	//{
	//	for (int j = 0; j < _index.x*2 ; j++)
	//	{
	//		aStarTile* tempAstar1 = new aStarTile;
	//		aStarTile* tempAstar2 = new aStarTile;
	//		aStarTile* tempAstar3 = new aStarTile;
	//		aStarTile* tempAstar4 = new aStarTile;

	//		int x, y;
	//		if (j >= _index.x)
	//		{
	//			x = (j - _index.x)/2;
	//			y = i;
	//		}
	//		else
	//		{
	//			x = j/2;
	//			y = i;
	//		}

	//		int k = (*vtile)[y*_index.x + x]->getWeight();

	//		tile_inGame* temp = (*vtile)[y*_index.x + x];
	//		if (j / _index.x== 0)
	//		{
	//			
	//			tempAstar1->setIdX(j * 2);
	//			tempAstar1->setIdY(i * 2);
	//			tempAstar1->setIsOpen(true);

	//			
	//			tempAstar2->setIdX(j * 2 + 1);
	//			tempAstar2->setIdY(i * 2);
	//			tempAstar2->setIsOpen(true);

	//		

	//			if ((*vtile)[y*_index.x + x]->getiGOBJ().OBJ_INDEX != OBJECT_NONE)
	//			{
	//				tempAstar1->setIsOpen(false);
	//				tempAstar2->setIsOpen(false);
	//			}

	//			if (k != 0)
	//			{
	//				switch (k)
	//				{
	//				case 1:
	//					tempAstar1->setIsOpen(false);
	//					break;
	//				case 2:
	//					tempAstar2->setIsOpen(false);
	//					break;
	//				case 3:
	//					tempAstar1->setIsOpen(false);
	//					tempAstar2->setIsOpen(false);
	//					break;
	//				case 4:
	//					break;
	//				case 5:
	//					tempAstar1->setIsOpen(false);
	//					break;
	//				case 6:
	//					tempAstar2->setIsOpen(false);
	//					break;
	//				case 7:
	//					tempAstar1->setIsOpen(false);
	//					tempAstar2->setIsOpen(false);
	//					break;
	//				case 8:
	//					break;
	//				case 9:
	//					tempAstar1->setIsOpen(false);
	//					break;
	//				case 10:
	//					tempAstar2->setIsOpen(false);
	//					break;
	//				case 11:
	//					tempAstar1->setIsOpen(false);
	//					tempAstar2->setIsOpen(false);
	//					break;
	//				case 12:
	//					break;
	//				case 13:
	//					tempAstar1->setIsOpen(false);
	//					break;
	//				case 14:
	//					tempAstar2->setIsOpen(false);
	//					break;
	//				case 15: // 4 -> i/8 3-> i%8/4 2->i%8%4/2 1->i%8%4%2
	//					tempAstar1->setIsOpen(false);
	//					tempAstar2->setIsOpen(false);
	//					break;
	//				}
	//			}
	//		}

	//		if (j / _index.x == 1)
	//		{
	//			
	//			tempAstar3->setIdX(j * 2 - _index.x*2);
	//			tempAstar3->setIdY(i * 2 + 1);
	//			tempAstar3->setIsOpen(true);

	//			
	//			tempAstar4->setIdX(j * 2 + 1- _index.x * 2);
	//			tempAstar4->setIdY(i * 2 + 1);
	//			tempAstar4->setIsOpen(true);

	//			if ((*vtile)[y*_index.x + x]->getiGOBJ().OBJ_INDEX != OBJECT_NONE)
	//			{
	//				tempAstar3->setIsOpen(false);
	//				tempAstar4->setIsOpen(false);
	//			}
	//			if (k != 0)
	//			{
	//				switch (k)
	//				{
	//				case 1:
	//					break;
	//				case 2:
	//					break;
	//				case 3:
	//					break;
	//				case 4:
	//					tempAstar3->setIsOpen(false);
	//					break;
	//				case 5:
	//					tempAstar3->setIsOpen(false);
	//					break;
	//				case 6:
	//					tempAstar3->setIsOpen(false);
	//					break;
	//				case 7:
	//					tempAstar3->setIsOpen(false);
	//					break;
	//				case 8:
	//					tempAstar4->setIsOpen(false);
	//					break;
	//				case 9:
	//					tempAstar4->setIsOpen(false);
	//					break;
	//				case 10:
	//					tempAstar4->setIsOpen(false);
	//					break;
	//				case 11:
	//					tempAstar4->setIsOpen(false);
	//					break;
	//				case 12:
	//					tempAstar3->setIsOpen(false);
	//					tempAstar4->setIsOpen(false);
	//					break;
	//				case 13:
	//					tempAstar3->setIsOpen(false);
	//					tempAstar4->setIsOpen(false);
	//					break;
	//				case 14:
	//					tempAstar3->setIsOpen(false);
	//					tempAstar4->setIsOpen(false);
	//					break;
	//				case 15: // 4 -> i/8 3-> i%8/4 2->i%8%4/2 1->i%8%4%2
	//					tempAstar3->setIsOpen(false);
	//					tempAstar4->setIsOpen(false);
	//					break;
	//				}
	//			}
	//				
	//		}
	//		
	//		if (j / _index.x == 0)
	//		{
	//			tempAstarMap.vAstarTiles.push_back(tempAstar1);
	//			tempAstarMap.vAstarTiles.push_back(tempAstar2);
	//		}
	//		if (j / _index.x == 1)
	//		{
	//			tempAstarMap.vAstarTiles.push_back(tempAstar3);
	//			tempAstarMap.vAstarTiles.push_back(tempAstar4);
	//		}
	//		
	//		int jkj = 0;
	//	}
	//}

	_mAStarInfo.insert(make_pair(key, tempAstarMap));


	return S_OK;
}
void aStarMapInfo::update()		 
{
}
void aStarMapInfo::loadMapInfo() 
{
}

void aStarMapInfo::render(HDC hdc)
{
	for (int i = 0; i < (*_currentAstar).size(); ++i)
	{
		HBRUSH hob, hb;
		HPEN hp, hop;
		hb = (HBRUSH)GetStockObject(NULL_BRUSH);
		hob = (HBRUSH)SelectObject(hdc, hb);
		if ((*_currentAstar)[i]->getIsOpen())
			hp = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		else
			hp = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		hop = (HPEN)SelectObject(hdc, hp);

		RectangleMake(hdc, (*_currentAstar)[i]->getIdX() * 25- CAMERAMANAGER->getCameraPoint().x, (*_currentAstar)[i]->getIdY() * 25 - CAMERAMANAGER->getCameraPoint().y, 25, 25);

		SelectObject(hdc, hop);
		SelectObject(hdc, hob);
		DeleteObject(hp);
		DeleteObject(hb);

	}
}
