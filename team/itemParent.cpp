#include "stdafx.h"
#include "itemParent.h"
#include "player.h"
#include "potion.h"

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
	TextOut(getMemDC(), 100, 100, "test", strlen("test"));
	//_itemImage->render(getMemDC(), 50, 50);
}

void itemParent::useItem()
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
			dynamic_cast<potion*>(this)->setIsFull(false);
		}
	}
	//�����ϰ�� ��� �Ұ��ΰ� .........................
}