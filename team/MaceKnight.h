#pragma once
#include "enemyParent.h"
#define Patroltile 50
class MaceKnight : public enemyParent
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

	image* _maceImage;
	RECT _maceRc;
	float _angle;
	float _cx, _cy;

	image* _maceLine;
	RECT _lineRc;
	float _lx, _ly;

	int _count;
	int _d;
	int _ld;
public:
	MaceKnight();
	~MaceKnight();

	virtual HRESULT init(POINT potinsion, int direction);
	virtual void draw();
	virtual void aniArri();																					//���� ������ ���� �ִϸ��̼� ����
	virtual void move();
	virtual void Pattern();
	void Patrol(EDIRECTION direction);
};


