#pragma once
#include "enemyParent.h"
class redEye :
	public enemyParent
{
	
	RECT _detectedRC; //Ž����Ʈ(�θ�Ŭ���� �߰��� ��������)
	int _immunCount;			//���������ð�
	bool _isDetect;	//Ž���߳�
public:
	redEye();
	~redEye();

	virtual HRESULT init();
	virtual void draw();
	virtual void aniArri();																					
	//virtual void move();
	virtual void Pattern();
};

