#include "stdafx.h"
#include "mainSwitch.h"


mainSwitch::mainSwitch()
{
}


mainSwitch::~mainSwitch()
{
}

HRESULT mainSwitch::init()
{
	gameNode::init(true);

	imageSetting();
	tileSetting();
	soundSetting();

	_button1 = RectMakeCenter(WINSIZEX / 4, WINSIZEY / 2, 100, 50);
	_button2 = RectMakeCenter(WINSIZEX / 4 * 3, WINSIZEY / 2, 100, 50);


	return S_OK;
}

void mainSwitch::release()
{
	gameNode::release();
}

void mainSwitch::update()
{
	gameNode::update();


	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_button1, _ptMouse))
		{
			page = PAGE_GAME;
			_pageChange = TRUE;
		}
		else if (PtInRect(&_button2, _ptMouse))
		{
			page = PAGE_MAPTOOL;
			_pageChange = TRUE;
		}
	}
}

void mainSwitch::render()
{
	//��� ��ȭ�� ����~
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================== �ǵ������� ======================


	char str[128];
	easyRectangle(getMemDC(), &_button1);
	sprintf(str, "���ΰ���");
	TextOut(getMemDC(), _button1.left + 5, _button1.top + 20, str, strlen(str));
	easyRectangle(getMemDC(), &_button2);
	sprintf(str, "����");
	TextOut(getMemDC(), _button2.left + 20, _button2.top + 20, str, strlen(str));



	//==================== �ǵ������� =======================

	this->getBackBuffer()->render(getHDC(), 0, 0);
}