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

	int _frameX;

	image* _black;
	int _alpha;//¾ËÆÄ·»´õ¿ë
	bool _alphaOn;
public:
	title();
	~title();
	HRESULT init();
	void release();
	void update();
	void render();
};

