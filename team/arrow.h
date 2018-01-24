#pragma once
#include "itemParent.h"
class arrow :
	public itemParent
{
private:
	//ȭ�� ����
	int _count;

	//ȭ���� �߻�?
	bool _isShot;

	//ȭ�����
	int _direction;
public:
	arrow();
	~arrow();

	//�κ��� �̴�
	virtual HRESULT init();
	//������ �̴�
	virtual HRESULT init(int x, int y);
	virtual void update();
	virtual void render();

	virtual void fire(float x, float y, int direction);

	//ȭ�� ���� ����,������
	void setCount(int count){ _count += count; }
	int getCount(){ return _count; }

	void setState(tagItemState itemState){ _itemState = itemState;}
	tagItemState getState(){ return _itemState; }
};

