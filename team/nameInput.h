#pragma once
#include "gameNode.h"

struct FUCK{
	RECT rc;
	int alphabet;
	int locate;
};

class saveLoad;

class nameInput : public gameNode
{
private:
	int _nameCount;
	char _total[128];
	char cat[32];
	char _write[64];
	int _choice;

	char checking[128];
//	saveLoad* SL;


	//커서용
	POINT _P;
	RECT _fairy;
	FUCK _name[8];
	int _cursor;//0~51+52,53(지움,완료)
	POINT _locate[54];
	int _count;
public:
	nameInput();
	~nameInput();
	virtual HRESULT init(int choice);
	void release();
	void update();
	void render();
	void save1();
	void save2();
	void save3();
	void erase();
	void alphabet();
	void alphabetRend();
};

