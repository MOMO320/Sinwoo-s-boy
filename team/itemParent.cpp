#include "stdafx.h"
#include "itemParent.h"
#include "player.h"
#include "potion.h"
#include "enemyManager.h"


itemParent::itemParent()
{
}


itemParent::~itemParent()
{

}


HRESULT itemParent::init()
{

	return S_OK;
}

HRESULT itemParent::init(int x, int y) //�����ǸŸ� ���� init �����ε�
{

	return S_OK;
}

void itemParent::release()
{

}
void itemParent::update()
{

}
void itemParent::render()
{
	if (test1)
	{
		TextOut(getMemDC(), 10, 10, "����", strlen("����"));
	}
	TextOut(getMemDC(), 100, 100, "test", strlen("test"));
	//_itemImage->render(getMemDC(), 50, 50);
}

void itemParent::useItem(float x, float y, int direction)
{
	//1. �����Կ� �������� ��
	//2. �÷��̾�� ZŰ �Է½� �� �Լ� ȣ��
	//3. HP�����ϰ�� ��ȸ�� �����ϰ�� ��ô ��
	/*
	POTION,		//����
	MONEY,		//��
	WEAPON,		//����
	SHIELD		//����
	*/

	// ƣ������ �ȵ����� ����
	if (_mainPlayer == NULL) return;

	//���� ������ ���
	if (_itemType == POTION)
	{
		//������ ��������� --> HP���ǻ���
		if (dynamic_cast<potion*>(this)->getIsFull())
		{
			_mainPlayer->setPlayerHP(1);
			dynamic_cast<potion*>(this)->setIsFull(false);
		}
	}
	//�����ϰ�� ��� �Ұ��ΰ� .........................
	//������ Ÿ���� �����̸鼭 �������� ���� �����ϰ��
	else if (_itemType == WEAPON )
	{
		fire(x, y,direction);
		//test1 = true;
		//_itemState = THROW;
	}
}

void itemParent::fire(float x, float y, int direction)
{
	
}