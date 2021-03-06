#pragma once
#include "gameNode.h"
#include "animation.h"
#include "aStar.h"

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
	ECondision_BackPatrol,
	ECondision_Detect,						//적이 플레이어를 찾았을떄
	ECondision_Hited						//플레이어에게 공격 당했을때
};

class player;

class enemyParent : public gameNode
{
protected:
	image*		 _Image;					//적의 이미지
	RECT		 _ImageRc;					//적의 피격 렉트  width는 웬만하면 타일의 사이즈 만큼 맞춰주세요
	animation*   _animation;
	RECT		 _DetectRc;					//적의 탐지 렉트
	RECT		 _AtkRc;					//적의 공격 렉트
	RECT		 _DefRc;
	RECT		 _rcBodyEnemy;				//적의 진짜 바디렉트


	EDIRECTION   _edirection;
	ECondistion   _eCondistion;
	int		 _x;						//적의 좌표X
	int		 _y;						//적의 좌표Y
	float		 _EnemySpeed;				//적의 스피드

	int			 _MAXHP;					//적의 최대 피격횟수
	int			 _CrrentHP;					//적의 현재 체력
	int			 _AtkPoint;					//적의 공격력
	int			 _Aggro;						//적의 어그로 <- 쓰실분들만 쓰세요;

	int			 _count;					//움직임 시간초
	int			 _freamCount;
	bool		  visible;					//렉트 보이게 하는 함수;
	bool		 _isDeath;

protected:
	//맵툴작업과 연관하여 쓸 변수들

	POINT			_renderPoint;	//랜더할 좌표
	vector<POINT>*	_vPatrol;		//패트롤 할 좌표 찍어둔 벡터
	int				_patrolIndex;	//패트롤 벡터에 접근하기 위한 인덱스번호
	bool			_reverse;		//패트롤 순환을 위한 bool변수

	aStar*			_aStar;
	aStarTile*		_nextTile;
public:
	enemyParent();
	~enemyParent();

	virtual HRESULT init();
	virtual HRESULT init(POINT potinsion);
	virtual HRESULT init(POINT potinsion, int direction);						//필수 
	virtual HRESULT init(POINT potinsion, int direction, vector<POINT>*  vPatrol);						//필수 
	//virtual HRESULT init(뿌려질 인덱스 번호 // 뿌려질 포인트 좌표 );					//필수 
	virtual void release();
	void render();
	virtual void draw();					//필수
	virtual void aniArri();					//필수 //방향 조절에 따른 애니매이션 조절
	virtual void update();
	virtual void update(player* player);
	virtual void move();					//필수
	virtual void move(player* player);
	virtual void Pattern();					//필수
	virtual void Pattern(player* player);					//필수
	void backmove(int PlayerX, int PlayerY);
	
	//virtual void Pattern(플레이어의 x, 플레이어의 y|| 플레이어의 렉트 || 플레이어의 인데스번호);	
	int *getAggro() { return &_Aggro; }
	void setAggro(int agro) { _Aggro = agro; }
	//현재 HP를 갖지고 감
	int getCrrentHP() { return _CrrentHP; }
	//현재 HP를 바꿔줌
	void setCrrentHP(int hp) { _CrrentHP -= hp; }			

	ECondistion getECondistion() { return _eCondistion; }
	void setECondistion(ECondistion condistion) { _eCondistion = condistion; }


	bool getisDeath() { return _isDeath; }
	void setisDeath(bool Death) { _isDeath = Death; }

	RECT getImageRC() { return _ImageRc; }

	RECT getDetectRc() { return _DetectRc; }
	RECT getDefRc() { return _DefRc; }

	animation* getAni() { return _animation; }
	POINT getPoint(){ return PointMake( _x, _y ); }

	//방향
	EDIRECTION getEDIRECTION() { return _edirection; }
	RECT getRcBodyEnemy() { return _rcBodyEnemy; }
};

