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
	virtual void aniArri();																					//���� ������ ���� �ִϸ��̼� ����
	virtual void move(RECT player);
	virtual void Pattern(RECT player);
	void Patrol(EDIRECTION direction);
};

