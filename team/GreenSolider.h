#pragma once
#include "enemyParent.h"
#define Patroltile 100
class GreenSolider : public enemyParent
{
private:
	int frameCount;
	int NomalCount;
	int dellay;
	bool isback;
	int patrolX, patrolY;
	char test[128];
	char str2[128];
	char str3[128];

public:
	GreenSolider();
	~GreenSolider();

	virtual HRESULT init(POINT potinsion, int direction, vector<POINT>*  vPatrol);						//필수 
	//virtual HRESULT init(POINT potinsion, int direction);
	virtual void draw();
	virtual void aniArri();																					//방향 조절에 따른 애니매이션 조절
	virtual void move(player* player);
	virtual void Pattern(player* player);
	void collision(player* player);
};

