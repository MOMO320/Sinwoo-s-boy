#pragma once
#include "itemParent.h"
class arrow :
	public itemParent
{
private:
	//ȭ�� ����
	int _count;
public:
	arrow();
	~arrow();

	//�κ��� �̴�
	virtual HRESULT init();
	//������ �̴�
	virtual HRESULT init(int x, int y);
	virtual void render();

	//ȭ�� ���� ����,������
	void setCount(int count){ _count += count; }
	int getCount(){ return _count; }
};

