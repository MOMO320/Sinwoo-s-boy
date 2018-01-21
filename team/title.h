#pragma once
#include "gameNode.h"
class title :
	public gameNode
{
private:
	//¹ÝÂ¦ÀÌ¿ë
	POINT _P;
	int _rot;
	int _count;

	image* _black;
	int _alpha;//¾ËÆÄ·»´õ¿ë

public:
	title();
	~title();
	HRESULT init();
	void release();
	void update();
	void render();
};

