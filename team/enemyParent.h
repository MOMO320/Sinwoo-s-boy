#pragma once
#include "gameNode.h"
#include "animation.h"
enum EDIRECTION					//���� ����
{
	EDIRECTION_LEFT,
	EDIRECTION_UP,
	EDIRECTION_RIGHT,
	EDIRECTION_DOWN
};
class enemyParent : public gameNode
{
private:
	image*		 _Image;					//���� �̹���
	RECT		 _ImageRc;					//���� �ǰ� ��Ʈ  width�� �����ϸ� Ÿ���� ������ ��ŭ �����ּ���
	animation*   _animation;
	RECT		 _AtkRc;					//���� ���� ��Ʈ
	EDIRECTION   _edirection;

	float		 _x;						//���� ��ǥX
	float		 _y;						//���� ��ǥY
	float		 _EnemySpeed;				//���� ���ǵ�

	int			 _MAXHP;					//���� �ִ� �ǰ�Ƚ��
	int			 _CrrentHP;					//���� ���� ü��
	int			 _AtkPoint;					//���� ���ݷ�
	int			 _Agro;						//���� ��׷� <- ���Ǻе鸸 ������;

	bool		  visible;					//��Ʈ ���̰� �ϴ� �Լ�;
	bool		 _isDeath;
public:
	enemyParent();
	~enemyParent();

	HRESULT init(const char* ImageName, POINT postion, EDIRECTION direction, int MAXHP, int AtkPoint);		//�̹��� ���� �̸� , ������ ��ġ, ��ġ�� ���� ����, �ִ� ü��, ���ݷ� 
	void release();
	void render();
	virtual void draw();
	virtual void aniArri();																					//���� ������ ���� �ִϸ��̼� ����
	virtual void update();
	virtual void move();
	virtual void Pattern();


	int getCrrentHP() { return _CrrentHP; }
	void setCrrentHP(int hp) { _CrrentHP -= hp; }
};

