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

	for (int i = 0; i < _index.y; ++i)
	{
		for (int j = 0; j < _index.x * 2 ; ++j)
		{
			aStarTile* tempAstar1 = new aStarTile;
			aStarTile* tempAstar2 = new aStarTile;
			aStarTile* tempAstar3 = new aStarTile;
			aStarTile* tempAstar4 = new aStarTile;

			int x, y;
			if (j >= 20)
			{
				x = (j - 20)/2;
				y = i;
			}
			else
			{
				x = j/2;
				y = i;
			}

			int k = (*vtile)[y*_index.x + x]->getWeight();

			if (i / _index.x == 0)
			{
				
				tempAstar1->setIdX(j * 2);
				tempAstar1->setIdY(i * 2);
				tempAstar1->setIsOpen(true);

				
				tempAstar2->setIdX(j * 2 + 1);
				tempAstar2->setIdY(i * 2);
				tempAstar2->setIsOpen(true);

			

				if ((*vtile)[y*_index.x + x]->getiGOBJ().OBJ_INDEX != OBJECT_NONE)
				{
					tempAstar1->setIsOpen(false);
					tempAstar2->setIsOpen(false);
				}

				if (k != 0)
				{
					switch (k)
					{
					case 1:
						tempAstar1->setIsOpen(false);
						break;
					case 2:
						tempAstar2->setIsOpen(false);
						break;
					case 3:
						tempAstar1->setIsOpen(false);
						tempAstar2->setIsOpen(false);
						break;
					case 4:
						break;
					case 5:
						tempAstar1->setIsOpen(false);
						break;
					case 6:
						tempAstar2->setIsOpen(false);
						break;
					case 7:
						tempAstar1->setIsOpen(false);
						tempAstar2->setIsOpen(false);
						break;
					case 8:
						break;
					case 9:
						tempAstar1->setIsOpen(false);
						break;
					case 10:
						tempAstar2->setIsOpen(false);
						break;
					case 11:
						tempAstar1->setIsOpen(false);
						tempAstar2->setIsOpen(false);
						break;
					case 12:
						break;
					case 13:
						tempAstar1->setIsOpen(false);
						break;
					case 14:
						tempAstar2->setIsOpen(false);
						break;
					case 15: // 4 -> i/8 3-> i%8/4 2->i%8%4/2 1->i%8%4%2
						tempAstar1->setIsOpen(false);
						tempAstar2->setIsOpen(false);
						break;
					}
				}
			}

			if (i / _index.x == 1)
			{
				
				tempAstar3->setIdX(j * 2);
				tempAstar3->setIdY(i * 2 + 1);
				tempAstar3->setIsOpen(true);

				
				tempAstar4->setIdX(j * 2 + 1);
				tempAstar4->setIdY(i * 2 + 1);
				tempAstar4->setIsOpen(true);

				if ((*vtile)[y*_index.x + x]->getiGOBJ().OBJ_INDEX != OBJECT_NONE)
				{
					tempAstar3->setIsOpen(false);
					tempAstar4->setIsOpen(false);
				}
				if (k != 0)
				{
					switch (k)
					{
					case 1:
						break;
					case 2:
						break;
					case 3:
						break;
					case 4:
						tempAstar3->setIsOpen(false);
						break;
					case 5:
						tempAstar3->setIsOpen(false);
						break;
					case 6:
						tempAstar3->setIsOpen(false);
						break;
					case 7:
						tempAstar3->setIsOpen(false);
						break;
					case 8:
						tempAstar4->setIsOpen(false);
						break;
					case 9:
						tempAstar4->setIsOpen(false);
						break;
					case 10:
						tempAstar4->setIsOpen(false);
						break;
					case 11:
						tempAstar4->setIsOpen(false);
						break;
					case 12:
						tempAstar3->setIsOpen(false);
						tempAstar4->setIsOpen(false);
						break;
					case 13:
						tempAstar3->setIsOpen(false);
						tempAstar4->setIsOpen(false);
						break;
					case 14:
						tempAstar3->setIsOpen(false);
						tempAstar4->setIsOpen(false);
						break;
					case 15: // 4 -> i/8 3-> i%8/4 2->i%8%4/2 1->i%8%4%2
						tempAstar3->setIsOpen(false);
						tempAstar4->setIsOpen(false);
						break;
					}
				}
					
			}
			
			if (k / _index.x == 0)
			{
				tempAstarMap.vAstarTiles.push_back(tempAstar1);
				tempAstarMap.vAstarTiles.push_back(tempAstar2);
			}
			if (k / _index.x == 1)
			{
				tempAstarMap.vAstarTiles.push_back(tempAstar3);
				tempAstarMap.vAstarTiles.push_back(tempAstar4);
			}
			

		}
	}

	_mAStarInfo.insert(make_pair(key, tempAstarMap));


	return S_OK;
}
void aStarMapInfo::update()		 
{
}
void aStarMapInfo::loadMapInfo() 
{
}