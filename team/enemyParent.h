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
	ECondision_BackPatrol,
	ECondision_Detect,						//���� �÷��̾ ã������
	ECondision_Hited						//�÷��̾�� ���� ��������
};

class enemyParent : public gameNode
{
protected:
	image*		 _Image;					//���� �̹���
	RECT		 _ImageRc;					//���� �ǰ� ��Ʈ  width�� �����ϸ� Ÿ���� ������ ��ŭ �����ּ���
	animation*   _animation;
	RECT		 _DetectRc;					//���� Ž�� ��Ʈ
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
	int			 _Aggro;						//���� ��׷� <- ���Ǻе鸸 ������;

	int			 _count;					//������ �ð���
	int			 _freamCount;
	bool		  visible;					//��Ʈ ���̰� �ϴ� �Լ�;
	bool		 _isDeath;

public:
	enemyParent();
	~enemyParent();

	virtual HRESULT init();
	virtual HRESULT init(POINT potinsion, int direction);						//�ʼ� 
	//virtual HRESULT init(�ѷ��� �ε��� ��ȣ // �ѷ��� ����Ʈ ��ǥ );					//�ʼ� 
	virtual void release();
	void render();
	virtual void draw();					//�ʼ�
	virtual void aniArri();					//�ʼ� //���� ������ ���� �ִϸ��̼� ����
	virtual void update();
	virtual void update(RECT player);
	virtual void move();					//�ʼ�
	virtual void move(RECT player);
	virtual void Pattern();					//�ʼ�
	virtual void Pattern(RECT player);					//�ʼ�
	void backmove(int PlayerX, int PlayerY, int enemyX, int enemyY);
	
	//virtual void Pattern(�÷��̾��� x, �÷��̾��� y|| �÷��̾��� ��Ʈ || �÷��̾��� �ε�����ȣ);	
	int *getAggro() { return &_Aggro; }
	void setAggro(int agro) { _Aggro = agro; }
	//���� HP�� ������ ��
	int getCrrentHP() { return _CrrentHP; }
	//���� HP�� �ٲ���
	void setCrrentHP(int hp) { _CrrentHP -= hp; }			

	ECondistion getECondistion() { return _eCondistion; }
	void setECondistion(ECondistion condistion) { _eCondistion = condistion; }


	bool getisDeath() { return _isDeath; }
	void setisDeath(bool Death) { _isDeath = Death; }

	RECT getImageRC() { return _ImageRc; }

	RECT getDetectRc() { return _DetectRc; }
	RECT getDefRc() { return _DefRc; }

	animation* getAni() { return _animation; }

};

