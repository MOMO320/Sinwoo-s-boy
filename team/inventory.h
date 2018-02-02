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

	//뭔지 알지?
	int _money;

	player* _mainPlayer;	
	enemyManager* _em;
	//셀럭트 커서 깜빡임 위한 변수들
	bool _cursor;
	int _count;

	//셀렉트 커서 그려주는 x,y변수
	float _x, _y;

	//벡터에 가기 위한 인덱스 번호
	int _index;

	//초기설정을 위한 보이는 아이템 갯수
	int _visibleItemNum;

	//인벤 열었냐
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


	//화살갯수를 조정하기 위한 get함수
	bow* getBow(){ return (bow*)_bow; }
	potion* getPotion(){ return (potion*)_potion; }

	vector<itemParent*> getInvenItem(){ return _vItem; }
	void setVisibleItem(int num);
	inventory();
	~inventory();
};

