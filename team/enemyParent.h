#pragma once
#include "gameNode.h"
#include "animation.h"
enum EDIRECTION					//적의 방향
{
	EDIRECTION_LEFT,
	EDIRECTION_UP,
	EDIRECTION_RIGHT,
	EDIRECTION_DOWN,
	EDIRECTION_NONE
};
enum ECondistion
{
	ECondision_Patrol,						//적의 기본 상태
	ECondision_Ditect,						//적이 플레이어를 찾았을떄
	ECondision_Hited						//플레이어에게 공격 당했을때
};

class enemyParent : public gameNode
{
protected:
	image*		 _Image;					//적의 이미지
	RECT		 _ImageRc;					//적의 피격 렉트  width는 웬만하면 타일의 사이즈 만큼 맞춰주세요
	animation*   _animation;
	RECT		 _DitectRc;					//적의 탐지 렉트
	RECT		 _AtkRc;					//적의 공격 렉트
	RECT		 _DefRc;
	EDIRECTION   _edirection;
	ECondistion   _eCondistion;
	float		 _x;						//적의 좌표X
	float		 _y;						//적의 좌표Y
	float		 _EnemySpeed;				//적의 스피드

	int			 _MAXHP;					//적의 최대 피격횟수
	int			 _CrrentHP;					//적의 현재 체력
	int			 _AtkPoint;					//적의 공격력
	int			 _Agro;						//적의 어그로 <- 쓰실분들만 쓰세요;

	int			 _count;					//움직임 시간초
	int			 _freamCount;
	bool		  visible;					//렉트 보이게 하는 함수;
	bool		 _isDeath;

public:
	enemyParent();
	~enemyParent();

	virtual HRESULT init();					//필수 
	virtual void release();
	void render();
	virtual void draw();					//필수
	virtual void aniArri();					//필수 //방향 조절에 따른 애니매이션 조절
	virtual void update();
	virtual void move();					//필수
	void backmove(int PlayerX, int PlayerY, int enemyX, int enemyY);
	virtual void Pattern();					//필수


	int getCrrentHP() { return _CrrentHP; }
	void setCrrentHP(int hp) { _CrrentHP -= hp; }

	ECondistion getECondistion() { return _eCondistion; }
	void setECondistion(ECondistion hit) { _eCondistion = hit; }

	RECT getImageRC() { return _ImageRc; }

	RECT getDitectRC() { return _DitectRc; }

	animation* getAni() { return _animation; }

};

