#pragma once
#include "gameNode.h"
#include "itemParent.h"
#include "inventory.h"
#include "itemParent.h"

class player :
	public gameNode
{

	//인벤토리 
	//inventory* _inventory;
	itemParent* _quickItem;

public:
	player();
	~player();

	void setQuickItemMemoryAddressLink(itemParent* item){ _quickItem = item; }
	//void setInventoryMemoryAddressLink(inventory* inventory){ _inventory = inventory; }
};

