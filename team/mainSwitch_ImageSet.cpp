#include "stdafx.h"
#include "mainSwitch.h"

void mainSwitch::imageSetting()
{
	//ĳ�� Ÿ��
	IMAGEMANAGER->addImage("ĳ�����", "./image./mapTile./castle./ĳ�����.bmp", 200, 350, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ĳ����Ÿ�Ͽ�", "./image./mapTile./castle./ĳ����Ÿ��+��ó����Ÿ��+���.bmp", 400, 400, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ĳ���ٴ�Ÿ��", "./image./mapTile./castle./ĳ���ٴ�Ÿ��.bmp", 200, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ĳ����������Ÿ��", "./image./mapTile./castle./ĳ����������Ÿ��.bmp", 300, 500, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ĳ��������Ÿ��", "./image./mapTile./castle./ĳ��������Ÿ��.bmp", 150, 500, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ĳ������Ÿ��", "./image./mapTile./castle./ĳ������Ÿ��.bmp", 500, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ĳ����Ÿ��", "./image./mapTile./castle./ĳ����Ÿ��.bmp", 400, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ĳ����Ÿ��2", "./image./mapTile./castle./ĳ����Ÿ��2.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ĳ����Ÿ��11", "./image./mapTile./castle./ĳ����Ÿ��11.bmp", 150, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ĳ��Ÿ��1", "./image./mapTile./castle./ĳ����Ÿ��1.bmp", 150, 150, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("�׸���Ÿ��", "./image./mapTile./castle./�׸���Ÿ��.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ٸ�", "./image./mapTile./castle./�ٸ�(500,450).bmp", 500, 450, true, RGB(255, 0, 255)); //��¥
	IMAGEMANAGER->addImage("�ٸ�Ÿ��", "./image./mapTile./castle./�ٸ�Ÿ��(�޿�).bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "./image./mapTile./castle./����.bmp", 50, 50, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("����", "./image./mapTile./castle./����.bmp", 168, 500, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������Ÿ��", "./image./mapTile./castle./������.bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "./image./mapTile./castle./����(350,150).bmp", 350, 150, true, RGB(255, 0, 255)); //��¥
	IMAGEMANAGER->addImage("�������", "./image./mapTile./castle./�������.bmp", 50, 60, true, RGB(255, 0, 255)); //��¥
	IMAGEMANAGER->addImage("������ı��", "./image./mapTile./castle./������ı��.bmp", 100, 250, true, RGB(255, 0, 255));	   //��¥
	IMAGEMANAGER->addImage("�������ª����", "./image./mapTile./castle./�������ª����.bmp", 250, 100, true, RGB(255, 0, 255));//��¥

	IMAGEMANAGER->addFrameImage("ĳ������", "./image./mapTile./castle./ĳ������.bmp",400,150,2,1,true, RGB(255, 0, 255)); //�̺�Ʈ
	//���� Ÿ��
	IMAGEMANAGER->addImage("�������1", "./image./mapTile./����./�������1.bmp", 100, 100, true, RGB(255, 0, 255)); //��¥
	IMAGEMANAGER->addImage("�������Ÿ��", "./image./mapTile./����./�������Ÿ��.bmp", 200, 200, true, RGB(255, 0, 255)); //���ڷ��̼�.
	IMAGEMANAGER->addImage("������", "./image./mapTile./����./������.bmp", 300, 300, true, RGB(255, 0, 255)); //��¥
	IMAGEMANAGER->addImage("��Ÿ��", "./image./mapTile./����./��Ÿ��.bmp", 300, 100, true, RGB(255, 0, 255)); //����
	IMAGEMANAGER->addImage("�Ķ���", "./image./mapTile./����./�Ķ���.bmp", 300, 300, true, RGB(255, 0, 255)); //��¥
	IMAGEMANAGER->addImage("Ǯ��", "./image./mapTile./����./Ǯ��.bmp", 50, 100, true, RGB(255, 0, 255)); //��¥
	IMAGEMANAGER->addImage("Ǯ������", "./image./mapTile./����./Ǯ������.bmp", 150, 50, true, RGB(255, 0, 255)); //��¥

	IMAGEMANAGER->addFrameImage("����", "./image./mapTile./����./�������1.bmp", 190, 97, 2,1,true, RGB(255, 0, 255)); //�̺�Ʈ
	//����Ÿ��
	IMAGEMANAGER->addImage("�������", "./image./mapTile./����Ÿ��./�������.bmp", 150, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������", "./image./mapTile./����Ÿ��./�������.bmp", 400, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����ٴڳ�ó��", "./image./mapTile./����Ÿ��./�����ٴڳ�ó��.bmp", 200, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����ٴڳ�ó��2", "./image./mapTile./����Ÿ��./�����ٴڳ�ó��2.bmp", 200, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����ٴ�Ÿ��", "./image./mapTile./����Ÿ��./�������.bmp", 300, 150, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������Ÿ��", "./image./mapTile./����Ÿ��./������Ÿ��(100,100).bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������Ÿ��2", "./image./mapTile./����Ÿ��./������Ÿ��(200,200).bmp", 200, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������Ÿ��3", "./image./mapTile./����Ÿ��./������Ÿ��(350,400).bmp", 350, 400, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������Ÿ��", "./image./mapTile./����Ÿ��./����Ÿ��1.bmp", 350, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������", "./image./mapTile./����Ÿ��./��.bmp", 400, 100, true, RGB(255, 0, 255)); //�̺�Ʈ
	IMAGEMANAGER->addImage("����������", "./image./mapTile./����Ÿ��./����������(100,100).bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������Ÿ��", "./image./mapTile./����Ÿ��./���(MOVE).bmp", 300, 200, true, RGB(255, 0, 255)); //���°�
	IMAGEMANAGER->addImage("�������Ÿ��2", "./image./mapTile./����Ÿ��./���2(MOVE).bmp", 300, 400, true, RGB(255, 0, 255)); //���°�
	IMAGEMANAGER->addImage("�������Ÿ��3", "./image./mapTile./����Ÿ��./���(UNMOVE).bmp", 200, 250, true, RGB(255, 0, 255)); //�����°�
	IMAGEMANAGER->addImage("öâ", "./image./mapTile./����Ÿ��./öâ.bmp", 500, 150, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ȭ�����", "./image./mapTile./����Ÿ��./ȭ�����.bmp", 200, 150, true, RGB(255, 0, 255));

	//��Ÿ��(������)
	IMAGEMANAGER->addFrameImage("��Ÿ��", "./image./mapTile./water./water.bmp", 1200, 300, 3, 1, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿ��2", "./image./mapTile./water./water2.bmp", 600, 200, 3, 1, false, RGB(255, 0, 255));
	//�ʵ� ������Ʈ��
	IMAGEMANAGER->addFrameImage("�ٱ�������Ʈ", "./image./mapTile./objectTile./outTerriorObject.bmp", 200, 300, 4,6,true, RGB(255, 0, 255));
	//�⺻Ÿ�ϵ�
	IMAGEMANAGER->addImage("�Ϲ�Ÿ��", "./image./mapTile./������̾�Ÿ��./�⺻Ÿ�� 50 x 50.bmp", 200, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ٴ�", "./image./mapTile./������̾�Ÿ��./��ٴ�.bmp", 400, 500, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "./image./mapTile./������̾�Ÿ��./����.bmp", 600, 600, true, RGB(255, 0, 255));
	//test
	IMAGEMANAGER->addImage("����", "./image./mapTile./object./tree.bmp", 150, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("testTerrain", "./image./mapTile./test./terrain.bmp", 320, 96, 10, 3, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("testObject", "./image./mapTile./test./object.bmp", 320, 64, 10, 2, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�⺻Ÿ��", "./image./mapTile./test./�⺻Ÿ��.bmp", 200, 200, 4, 4, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "./image./mapTile./test./����.bmp", 300, 600, 12, 24, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������ƮŸ��", "./image./mapTile./objectTile./outTerriorObject.bmp", 200, 300, 4, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������ĳ����", "./image./mapTile./ĳ����./character.bmp", 440, 72, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��", "./image./maptile./decoration./flower.bmp", 200, 200, 4, 4, true, RGB(255, 0, 255));
}

void mainSwitch::tileSetting()
{

	//TILEMANAGER->addTerrain("�⺻����", "�⺻Ÿ��", { 0,0 }, { 2,1 }, TR_BASIC);
	POINT arr[5] = { {0,0},{2,2},{0,3},{0,2},{3,1} };
	TILEMANAGER->addTerrain("�⺻����", "�⺻Ÿ��", arr, 5, TR_BASIC);

	//POINT arr2[1] = { { 0,3} };
	TILEMANAGER->addObject("������ƮŸ��", "������ƮŸ��", { 0,2 }, { 1,1 }, { 0,0 }, OBJECT_PICK);

	TILEMANAGER->addObject("Ʈ��", "����", { 0,0 }, { 3,2 }, { 0,100 }, OBJECT_STOP);

	TILEMANAGER->addCharacter("�÷��̾�", "������ĳ����", CHARACTER_PLAYER_POS, { 2,22 });

	POINT flowerArr1[4] = { {0,0},{1,0},{2,0},{3,0} };
	TILEMANAGER->addDecoration("��", "��", DECO_LEFT_TOP, true, flowerArr1, 4, 0);
	POINT flowerArr2[4] = { {0,1},{1,1},{2,1}, {3,1} };
	TILEMANAGER->addDecoration("��", "��", DECO_LEFT_BOTTOM, true, flowerArr2, 4, 0);
	POINT flowerArr3[4] = { { 0,2 },{ 1,2 },{ 2,2},{ 3,2 } };
	TILEMANAGER->addDecoration("��", "��", DECO_RIGHT_TOP, true, flowerArr3, 4, 0);
	POINT flowerArr4[4] = { { 0,3 },{ 1,3 },{ 2,3 },{ 3,3 } };
	TILEMANAGER->addDecoration("��", "��", DECO_RIGHT_BOTTOM, true, flowerArr4, 4, 0);

	//ĳ��Ÿ��

}