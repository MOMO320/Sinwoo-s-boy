#pragma once
#include "enemyParent.h"

enum tagState{
	LEFT = 0,
	TOP,
	RIGHT,
	DOWN,
	NODETECT,
	DETECT
};
class redEye :
	public enemyParent
{
	
	RECT _detectedRC; //Ž����Ʈ(�θ�Ŭ���� �߰��� ��������)
	int _immunCount;			//���������ð�
	bool _isDetect;	//Ž���߳�

	animation*   _ActionAnimation[6];
	//int			_LeftAni;
public:
	redEye();
	~redEye();

	virtual HRESULT init();
	virtual void draw();
	virtual void aniArri();																					
	virtual void move(){ Pattern(); }
	virtual void Pattern();

	//�ִϸ��̼� �迭 �̴��Լ�
	void aniInit();
};

