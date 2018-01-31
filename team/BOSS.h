#pragma once
#include "enemyParent.h"

enum ENEMY_DIRECTION
{
	ENEMY_STAND,
	ENEMY_MOVE,
	ENEMY_HIT,
	ENEMY_ALONE,
	ENEMY_DEAD
};
enum BOSS_PATTERN
{
	STAND,
	CIRCLESTAND,
	CIRCLE,
	LITTELCIRCLE,
	RECIRLE,
	LINESTAND,
	LINE,
	ALONE
};


class BOSS : public enemyParent
{
private:
	ENEMY_DIRECTION	_direction;
	BOSS_PATTERN _bossPattern;

	RECT			_rc[6];
	float			_x[6], _y[6];
	float			_cx[6], _cy[6];
	float			_speed;
	float			_angle[6];

	int _d;
	int _count;
	int _patternNum;

public:
	BOSS();
	~BOSS();

	virtual HRESULT init();
	virtual void draw();
	virtual void move();
	virtual void Pattern();

	static void bossHit(void* obj);

	ENEMY_DIRECTION getKnightDirection(void) { return _direction; }
	void setKnightDirection(ENEMY_DIRECTION direction) { _direction = direction; }

	//기사의 모션 접근자, 설정자
	animation* getKnightMotion(void) { return _animation; }
	void setKnightMotion(animation* ani) { _animation = ani; }
};



