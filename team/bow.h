#pragma once
#include "itemParent.h"

class arrow;

class bow :
	public itemParent
{
private:
	//Ȱ���� ȭ���� �־����?
	arrow* _arrow;

public:
	bow();
	~bow();

	virtual HRESULT init();
	virtual void update();
	virtual void render();

	arrow* getArrow(){ return _arrow; }
};

