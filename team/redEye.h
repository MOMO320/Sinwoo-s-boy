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
	
	RECT _detectedRC; //탐지렉트(부모클래스 추가시 삭제예정)
	int _immunCount;			//무적판정시간
	bool _isDetect;	//탐지했냐

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

	//애니메이션 배열 이닛함수
	void aniInit();
};

