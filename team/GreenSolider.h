#pragma once
#include "enemyParent.h"
#define Patroltile 50
class GreenSolider : public enemyParent
{
private:
	int frameCount;
	int NomalCount;
	char str[128];
	char str2[128];
	char str3[128];
public:
	GreenSolider();
	~GreenSolider();

	virtual HRESULT init();
	virtual void draw();
	virtual void aniArri();																					//���� ������ ���� �ִϸ��̼� ����
	virtual void Pattern();
};

