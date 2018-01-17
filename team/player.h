#pragma once
#include "gameNode.h"
#include "itemParent.h"
#include "inventory.h"

class player :
	public gameNode
{

	//인벤토리 
	inventory* _inventory;

public:
	player();
	~player();

	void setInventoryMemoryAddressLink(inventory* inventory){ _inventory = inventory; }
};

