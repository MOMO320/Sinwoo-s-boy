#pragma once
#include "gameNode.h"
#include "itemParent.h"
#include "inventory.h"

class player :
	public gameNode
{

	//�κ��丮 
	inventory* _inventory;

public:
	player();
	~player();

	void setInventoryMemoryAddressLink(inventory* inventory){ _inventory = inventory; }
};

