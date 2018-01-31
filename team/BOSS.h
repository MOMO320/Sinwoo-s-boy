#pragma once
#include "enemyParent.h"
#include <vector>

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

struct tagBoss
{
	RECT  rc;
	float x, y;
	float cx, cy;
	float angle;
};

class BOSS : public enemyParent
{
private:
	ENEMY_DIRECTION	_direction;
	BOSS_PATTERN _bossPattern;

	vector<tagBoss> _vboss;

	//RECT			_rc[6];
	//float			_x[6], _y[6];
	//float			_cx[6], _cy[6];
	//float			_speed;
	//float			_angle[6];

	int _d;
	int _count;
	int _patternNum;

public:
	BOSS();
	~BOSS();

	virtual HRESULT init(POINT pos);
	virtual void draw();
	virtual void move(player * player);
	virtual void Pattern(player * player);

	static void bossHit(void* obj);

	ENEMY_DIRECTION getKnightDirection(void) { return _direction; }
	void setKnightDirection(ENEMY_DIRECTION direction) { _direction = direction; }

	//기사의 모션 접근자, 설정자
	animation* getKnightMotion(void) { return _animation; }
	void setKnightMotion(animation* ani) { _animation = ani; }
};



