#pragma once
#include "itemParent.h"

class player;

class boomerang :
	public itemParent
{
	//프레임 카운트
	int _frameCount;

	//날라가는 방향
	int _direction;
	//돌아오는중이냐
	bool _isBack; 
public:
	boomerang();
	~boomerang();

	virtual HRESULT init();
	virtual void update();
	virtual void render();

	virtual void fire(float x, float y, int direction);
};

