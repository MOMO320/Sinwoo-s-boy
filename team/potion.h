#pragma once
#include "itemParent.h"
class potion :
	public itemParent
{
	bool _isFull;	//���� ���� ����ִ°�
public:
	potion();
	~potion();

	virtual HRESULT init();
	virtual void update();
	virtual void render();

	void setIsFull(bool isFull){ _isFull = isFull; }
	bool getIsFull(){ return _isFull; }
};

