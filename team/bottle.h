#pragma once
#include "objectParent.h"



class bottle : public objectParent
{
private:

	player* _play;

	float _pointX, _pointY;

public:
	bottle();
	~bottle();

	HRESULT init(POINT point);
	void render();
	void update();

	virtual void move();

};

