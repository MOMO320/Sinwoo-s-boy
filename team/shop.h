#pragma once
#include "gameNode.h"
#include "itemParent.h"
#include <vector>

class heart;
class HPMaterial;


class shop :
	public gameNode
{

	//상점 판매 벡터
	vector<itemParent*> _vShopItem;
	vector<itemParent*>::iterator _viShopItem;
	
public:
	shop();
	~shop();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

