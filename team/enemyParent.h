#pragma once
#include "gameNode.h"
#include "animation.h"
enum EDIRECTION					//���� ����
{
	EDIRECTION_LEFT,
	EDIRECTION_UP,
	EDIRECTION_RIGHT,
	EDIRECTION_DOWN,
	EDIRECTION_NONE
};
enum ECondistion
{
	ECondision_Patrol,						//���� �⺻ ����
	ECondision_Ditect,						//���� �÷��̾ ã������
	ECondision_Hited						//�÷��̾�� ���� ��������
};

class enemyParent : public gameNode
{
protected:
	image*		 _Image;					//���� �̹���
	RECT		 _ImageRc;					//���� �ǰ� ��Ʈ  width�� �����ϸ� Ÿ���� ������ ��ŭ �����ּ���
	animation*   _animation;
	RECT		 _DitectRc;					//���� Ž�� ��Ʈ
	RECT		 _AtkRc;					//���� ���� ��Ʈ
	RECT		 _DefRc;
	EDIRECTION   _edirection;
	ECondistion   _eCondistion;
	float		 _x;						//���� ��ǥX
	float		 _y;						//���� ��ǥY
	float		 _EnemySpeed;				//���� ���ǵ�

	int			 _MAXHP;					//���� �ִ� �ǰ�Ƚ��
	int			 _CrrentHP;					//���� ���� ü��
	int			 _AtkPoint;					//���� ���ݷ�
	int			 _Agro;						//���� ��׷� <- ���Ǻе鸸 ������;

	int			 _count;					//������ �ð���
	int			 _freamCount;
	bool		  visible;					//��Ʈ ���̰� �ϴ� �Լ�;
	bool		 _isDeath;

public:
	enemyParent();
	~enemyParent();

	virtual HRESULT init();					//�ʼ� 
	virtual void release();
	void render();
	virtual void draw();					//�ʼ�
	virtual void aniArri();					//�ʼ� //���� ������ ���� �ִϸ��̼� ����
	virtual void update();
	virtual void move();					//�ʼ�
	void backmove(int PlayerX, int PlayerY, int enemyX, int enemyY);
	virtual void Pattern();					//�ʼ�


	int getCrrentHP() { return _CrrentHP; }
	void setCrrentHP(int hp) { _CrrentHP -= hp; }

	ECondistion getECondistion() { return _eCondistion; }
	void setECondistion(ECondistion hit) { _eCondistion = hit; }

	RECT getImageRC() { return _ImageRc; }

	RECT getDitectRC() { return _DitectRc; }

	animation* getAni() { return _animation; }

};

