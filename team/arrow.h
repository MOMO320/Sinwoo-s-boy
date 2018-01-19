#pragma once
#include "itemParent.h"
class arrow :
	public itemParent
{
private:
	//화살 갯수
	int _count;
public:
	arrow();
	~arrow();

	//인벤용 이닛
	virtual HRESULT init();
	//상점용 이닛
	virtual HRESULT init(int x, int y);
	virtual void render();

	//화살 갯수 접근,설정자
	void setCount(int count){ _count += count; }
	int getCount(){ return _count; }
};

