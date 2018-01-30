#pragma once
#include "enemyParent.h"
#define Patroltile 50
class BlueSolider : public enemyParent
{
private:
	int frameCount;
	int NomalCount;
	bool isright;
	bool isbottom;
	int patrolX, patrolY;
	char str[128];
	char str2[128];
	char str3[128];
public:
	BlueSolider();
	~BlueSolider();

	virtual HRESULT init(POINT potinsion, int direction);
	virtual void draw();
	virtual void aniArri();																					//방향 조절에 따른 애니매이션 조절
	virtual void move(RECT player);
	virtual void Pattern(RECT player);
	void Patrol(EDIRECTION direction);
};

