#pragma once
#include "enemyParent.h"
class GreenSolider :	public enemyParent
{
public:
	GreenSolider();
	~GreenSolider();

	virtual HRESULT init();
	virtual void draw();
	virtual void aniArri();																					//���� ������ ���� �ִϸ��̼� ����
	virtual void Pattern();
};

