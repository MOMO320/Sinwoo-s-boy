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
	ENEMY_DIRECTION bossdirection;
	animation* animation;
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
	POINT initP;

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
	virtual void recycle();
	//virtual void backmove(int PlayerX, int PlayerY);

	void bossHit(int i);

	void collision(player* player);


	//RECT getRcBodyEnemy() { return _vboss.rc; }

	ENEMY_DIRECTION getKnightDirection(void) { return _direction; }
	void setKnightDirection(ENEMY_DIRECTION direction) { _direction = direction; }

	//����� ��� ������, ������
	animation* getKnightMotion(void) { return _animation; }
	void setKnightMotion(animation* ani) { _animation = ani; }

};


