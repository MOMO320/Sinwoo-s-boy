#include "stdafx.h"
#include "mainSwitch.h"

void mainSwitch::imageSetting()
{

	IMAGEMANAGER->addFrameImage("testTerrain", "./image./mapTile./test./terrain.bmp", 320, 96, 10, 3, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("testObject", "./image./mapTile./test./object.bmp", 320, 64, 10, 2, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�⺻Ÿ��", "./image./mapTile./test./�⺻Ÿ��.bmp", 200, 200, 4, 4, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "./image./mapTile./test./����.bmp", 300, 600, 12, 24, false, RGB(255, 0, 255));

}
