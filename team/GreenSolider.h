#pragma once
#include "enemyParent.h"
#define Patroltile 50
class GreenSolider : public enemyParent
{
private:
	int frameCount;
	int NomalCount;
	int dellay;
	bool isright;
	int patrolX, patrolY;
	char str[128];
	char str2[128];
	char str3[128];

public:
	GreenSolider();
	~GreenSolider();

	virtual HRESULT init(POINT potinsion, int direction, vector<POINT>*  vPatrol);						//�ʼ� 
	//virtual HRESULT init(POINT potinsion, int direction);
	virtual void draw();
	virtual void aniArri();																					//���� ������ ���� �ִϸ��̼� ����
	virtual void move(RECT pleyer);
	virtual void Pattern(RECT pleyer);
};

