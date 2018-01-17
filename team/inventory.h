#pragma once
#include "gameNode.h"
#include "bow.h"
#include "boomerang.h"
#include "potion.h"

#include <vector>

class inventory :
	public gameNode
{
	vector<itemParent*> _vItem;
	vector<itemParent*>::iterator _viItem;

	itemParent* _bow;
	itemParent* _boomerang;
	itemParent* _potion;

	//셀럭트 커서 깜빡임 위한 변수들
	bool _cursor;
	int _count;

	float _x, _y;
	//벡터에 가기 위한 인덱스 번호
	int _index;
	//초기설정을 위한 보이는 아이템 갯수
	int _visibleItemNum;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	inventory();
	~inventory();
};

