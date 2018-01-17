#pragma once
#include "gameNode.h"
#include "bow.h"
#include "boomerang.h"
#include "potion.h"

#include <vector>

class inventory :
	public gameNode
{
	vector<itemParent*> _vItem;
	vector<itemParent*>::iterator _viItem;

	itemParent* _bow;
	itemParent* _boomerang;
	itemParent* _potion;

	//����Ʈ Ŀ�� ������ ���� ������
	bool _cursor;
	int _count;

	float _x, _y;
	//���Ϳ� ���� ���� �ε��� ��ȣ
	int _index;
	//�ʱ⼳���� ���� ���̴� ������ ����
	int _visibleItemNum;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	inventory();
	~inventory();
};

