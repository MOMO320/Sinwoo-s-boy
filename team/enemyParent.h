#pragma once
#include "gameNode.h"
class enemyParent :
	public gameNode
{

	//A* 쓸때 몬스터의 타일 인덱스 번호로 넘겨주기
public:
	enemyParent();
	~enemyParent();
};

