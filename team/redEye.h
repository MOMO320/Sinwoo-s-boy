#pragma once
#include "enemyParent.h"
class redEye :
	public enemyParent
{
public:
	redEye();
	~redEye();

	virtual HRESULT init();
	virtual void draw();
	virtual void aniArri();																					
	virtual void move();
	virtual void Pattern();
};

