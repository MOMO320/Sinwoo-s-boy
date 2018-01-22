#pragma once
#include "enemyParent.h"
class redEye :
	public enemyParent
{
	
	RECT _detectedRC; //탐지렉트(부모클래스 추가시 삭제예정)
	int _immunCount;			//무적판정시간
	bool _isDetect;	//탐지했냐
public:
	redEye();
	~redEye();

	virtual HRESULT init();
	virtual void draw();
	virtual void aniArri();																					
	//virtual void move();
	virtual void Pattern();
};

