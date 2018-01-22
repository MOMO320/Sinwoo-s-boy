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
	//실험용 렉트
	//RECT _testRC;

	//상점 판매 벡터
	vector<itemParent*> _vShopItem;
	vector<itemParent*>::iterator _viShopItem;
	
	//통신용 플레이어 변수
	player* _mainPlayer;

	//통신용 인벤토리 변수
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

