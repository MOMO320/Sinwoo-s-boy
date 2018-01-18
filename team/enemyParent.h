#pragma once
#include "gameNode.h"
class enemyParent :
	public gameNode
{

	//A* 쓸때 몬스터의 중점좌표 인자로 넘겨주기
public:
	enemyParent();
	~enemyParent();
};

