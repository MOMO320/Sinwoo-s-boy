#pragma once
#include "itemParent.h"
class arrow :
	public itemParent
{
private:
	//화살 갯수
	int _count;

	//화살이 발사?
	bool _isShot;
public:
	arrow();
	~arrow();

	//인벤용 이닛
	virtual HRESULT init();
	//상점용 이닛
	virtual HRESULT init(int x, int y);
	virtual void update();
	virtual void render();

	void fire();

	//화살 갯수 접근,설정자
	void setCount(int count){ _count += count; }
	int getCount(){ return _count; }

	void setState(tagItemState itemState){ _itemState = itemState;}
	tagItemState getState(){ return _itemState; }
};

