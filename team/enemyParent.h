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
protected:
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
	
	int			 _count;					//������ �ð���
	bool		  visible;					//��Ʈ ���̰� �ϴ� �Լ�;
	bool		 _isDeath;
public:
	enemyParent();
	~enemyParent();

	virtual HRESULT init();
	virtual void release();
			void render();
	virtual void draw();
	virtual void aniArri();																					//���� ������ ���� �ִϸ��̼� ����
	virtual void update();
	virtual void move();
	virtual void Pattern();


	int getCrrentHP() { return _CrrentHP; }
	void setCrrentHP(int hp) { _CrrentHP -= hp; }

	RECT getImageRC() { return _ImageRc; }

};

