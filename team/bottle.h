#pragma once
#include "objectParent.h"



class bottle : public objectParent
{
private:

	player* _play;

	float _carryX, _carryY;

	bool _isSetting;
	
public:
	bottle();
	~bottle();

	HRESULT init(POINT point, player* player);
	void render();
	void update();

	virtual void move();

};

