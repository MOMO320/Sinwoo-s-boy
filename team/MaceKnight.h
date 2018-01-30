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
	RECT _lineRc[4];
	float _lx[4], _ly[4];

	int _count;
	float _d;
	float _ld[4];
	float _speed;
public:
	MaceKnight();
	~MaceKnight();

	virtual HRESULT init(POINT potinsion, int direction);
	virtual void draw();
	virtual void aniArri();																					//방향 조절에 따른 애니매이션 조절
	virtual void move(RECT pleyer);
	virtual void Pattern(RECT pleyer);
	void Patrol(EDIRECTION direction);
};


