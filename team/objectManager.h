#pragma once
#include "gameNode.h"
#include "bottle.h"
#include "box.h"
#include "stone.h"
#include "gbox.h"
#include "bush.h"

class enemyManager;

class objectManager:public gameNode
{
private:

	vector<objectParent*> _vObParent;
	enemyManager* _em;

	int _countDelay;
	int _arrNum;		//���ϴ� ������Ʈ�� �迭 ��ȣ
	bool _isRemove;		//��� �ұ?
	

public:
	objectManager();
	~objectManager();
	
	HRESULT init(player* player);
	void release();
	void update();
	void render();

	void setBottle(POINT pos, player* player);
	void setBox(POINT pos, player* player);
	void setStone(POINT pos, player* player);
	void setGBox(POINT pos, player* player);
	void setBush(POINT pos, player* player);

	void deleteObject();
	void deleteObject(int arrNum);
	void enemyobject();
	void removeDelay();

	void setEmAddressMemoryLink(enemyManager* em) { _em = em; }
};

