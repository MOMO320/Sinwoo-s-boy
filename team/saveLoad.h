#pragma once
#include "gameNode.h"

class nameInput;

struct FUCKING {
	RECT rc;
	int alphabet;
	int locate;
};

enum MODE {
	CURSOR,
	COPY,
	DEL
};

class saveLoad :
	public gameNode
{
private:
	//���������Ǵ��Ͽ� ����
	//int _file;
	char _save1[64], _save2[64], _save3[64];

	MODE _mode;
	FUCKING _name[8];
	FUCKING _name2[8];
	FUCKING _name3[8];

	RECT tect;

	//Ŀ����
	POINT _P;
	RECT _fairy;
	int _cursor;
	int _count;

	//nameInput* NI;


	//ȭ���
	int _alpha;
	bool _alphaOn;
public:
	saveLoad();
	~saveLoad();
	HRESULT init();
	void release();
	void update();
	void render();

	void check();
	void load1();
	void save1();
	void load2();
	void save2();
	void load3();
	void save3();
	void copy(int source, int target);
	void alphabet1();
	void alphabet2();
	void alphabet3();
	void alphabetRend();


	//int getFile() { return _file; }
	//void setFile(int F) { _file = F; }
	//�����ۼ���
	//������ ������ ������
};

