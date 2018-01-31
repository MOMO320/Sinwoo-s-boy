#pragma once
#include "gameNode.h"
#include "bow.h"
#include "boomerang.h"
#include "potion.h"
#include "arrow.h"
#include <vector>

class player;
class enemyManager;

class inventory :
	public gameNode
{
	vector<itemParent*> _vItem;
	vector<itemParent*>::iterator _viItem;

	itemParent* _bow;
	itemParent* _boomerang;
	itemParent* _potion;

	//���� ����?
	int _money;

	player* _mainPlayer;	
	enemyManager* _em;
	//����Ʈ Ŀ�� ������ ���� ������
	bool _cursor;
	int _count;

	//����Ʈ Ŀ�� �׷��ִ� x,y����
	float _x, _y;

	//���Ϳ� ���� ���� �ε��� ��ȣ
	int _index;

	//�ʱ⼳���� ���� ���̴� ������ ����
	int _visibleItemNum;

	//�κ� ������
	bool _invenOpen;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	void setMoney(int money){ _money += money; }
	int getMoney() { return _money; }

	void setPlayerMemoryAddressLink(player* player){ _mainPlayer = player; }
	void setEMMemoryAddressLink(enemyManager* em){ _em = em; }

	void setInvenOpen(bool invenOpen){ _invenOpen = invenOpen; }
	bool getInvenOpen(){ return _invenOpen; }


	//ȭ�찹���� �����ϱ� ���� get�Լ�
	bow* getBow(){ return (bow*)_bow; }
	potion* getPotion(){ return (potion*)_potion; }

	vector<itemParent*> getInvenItem(){ return _vItem; }
	void setVisibleItem(int num);
	inventory();
	~inventory();
};

