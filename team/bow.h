#pragma once
#include "itemParent.h"

class arrow;

class bow :
	public itemParent
{
private:
	//활에는 화살이 있어야지?
	arrow* _arrow;

public:
	bow();
	~bow();

	virtual HRESULT init();
	virtual void update();
	virtual void render();

	arrow* getArrow(){ return _arrow; }
};

