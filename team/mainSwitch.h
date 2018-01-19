#pragma once
#include "gameNode.h"


class mainSwitch : public gameNode
{

private:
	RECT _button1, _button2;

public:
	mainSwitch();
	~mainSwitch();

	HRESULT init();
	void release();
	void update();
	void render();

	void imageSetting();
	void tileSetting();
};

