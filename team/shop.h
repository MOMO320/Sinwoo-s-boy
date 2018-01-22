#pragma once
#include "gameNode.h"
#include "itemParent.h"
#include "player.h"
#include "inventory.h"
#include <vector>

class heart;
class HPMaterial;
class arrow;

class shop :
	public gameNode
{
	//����� ��Ʈ
	//RECT _testRC;

	//���� �Ǹ� ����
	vector<itemParent*> _vShopItem;
	vector<itemParent*>::iterator _viShopItem;
	
	//��ſ� �÷��̾� ����
	player* _mainPlayer;

	//��ſ� �κ��丮 ����
	inventory* _inven;

	char test[128];
public:
	shop();
	~shop();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setPlayerAddressLink(player* mainPlayer){ _mainPlayer = mainPlayer; }
	void setInvenAddressLink(inventory* inven){ _inven = inven; }
};

