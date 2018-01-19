#pragma once
#include "enemyParent.h"
#define Patroltile 50
class GreenSolider : public enemyParent
{
private:
	int frameCount;
	int NomalCount;
	char str[128];
	char str2[128];
	char str3[128];
public:
	GreenSolider();
	~GreenSolider();

	virtual HRESULT init();
	virtual void draw();
	virtual void aniArri();																					//방향 조절에 따른 애니매이션 조절
	virtual void Pattern();
};

