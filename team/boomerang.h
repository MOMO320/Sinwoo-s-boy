#pragma once
#include "itemParent.h"

class player;

class boomerang :
	public itemParent
{
	//������ ī��Ʈ
	int _frameCount;

	//���󰡴� ����
	int _direction;
	//���ƿ������̳�
	bool _isBack; 
public:
	boomerang();
	~boomerang();

	virtual HRESULT init();
	virtual void update();
	virtual void render();

	virtual void fire(float x, float y, int direction);
};

