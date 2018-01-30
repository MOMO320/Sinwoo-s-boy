#pragma once
#include "gameNode.h"
#include "shop.h"
#include "inventory.h"
#include "player.h"

class shopScene :
	public gameNode
{
private:

	shop* _shop;

	player* _mainPlayer;
	inventory* _inven;
public:
	shopScene();
	~shopScene();

	virtual HRESULT init(player* mainPlayer, inventory* inven);
	void release();
	void update();
	void render();
};

