#pragma once
#include "enemyParent.h"
class GreenSolider :	public enemyParent
{
public:
	GreenSolider();
	~GreenSolider();

	virtual HRESULT init();
	virtual void draw();
	virtual void aniArri();																					//방향 조절에 따른 애니매이션 조절
	virtual void Pattern();
};

