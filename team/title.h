#pragma once
#include "gameNode.h"
class title :
	public gameNode
{
private:
	//��¦�̿�
	POINT _P;
	int _rot;

	image* _twink;
	image* _black;
	int _alpha;//���ķ�����

public:
	title();
	~title();
	HRESULT init();
	void release();
	void update();
	void render();
};

