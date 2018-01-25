#pragma once
#include "gameNode.h"
#include "player.h"

class player;


enum tagObjectType
{
	OB_THROW,		//던지기가 가능한 오브젝트
	OB_BOX,			//상자
	OB_SPARK,		//전기방어
};

enum tagObjectState
{
	PUT,		//놓여있는 상태
	THROWING,	//던져지고있는 상태
	ZIRIRI,		//스파크 켜진상태?
	BOX_OPEN,	//상자 열린상태
	BOX_CLOSE,	//상자 닫힌상태
};


class objectParent :
	public gameNode
{
protected:
	image* _objectImage;			//오브젝트 이미지
	RECT _rcObject;					//좌표받아올때 써줄 렉트
	float _x, _y;					//오브젝트 중점좌표
	float _centerX, _centerY;		//오브젝트 중점을 잡아줄 좌표
	float _endX, _endY;				//던졌을때 보정해줄 좌표
	tagObjectType _objectType;		//오브젝트 종류
	tagObjectState _objectState;	//오브젝트 상태값
	int _objectEffect;				//오브젝트의 효과
									
	int _frameX;					//프레임
	int _frameCount;				//프레임카운트
									
	float _throwDamage;				//던졌을떄 데미지
	bool _isUp;						//들수있냐없냐
	bool _respon;					//리스폰되냐 안되냐
	bool _isFire;					//날라갔니?

	player * _player;

public:
	objectParent();
	~objectParent();

	//오브젝트 초기화값
	virtual HRESULT init();
	virtual HRESULT init(POINT point, player* player);

	virtual void release();
	virtual void update();
	virtual void render();

	//오브젝트의 이동
	virtual void move() {}
	virtual void open() {}
	virtual void hide() {}

	//오브젝트 좌표를 설정하기
	void setPoint(POINT point) { _x = point.x; _y = point.y; }
	RECT getItemRC() { return _rcObject; }

	//던질때 상태변경
	void setState(bool isThrow) { if (isThrow)_objectState = THROWING; else _objectState = PUT; }

	//오브젝트의 현상태
	int getState() { return _objectState; }

	float getX() { return _x; }
	float getY() { return _y; }
	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }
	void setEndY(float endY) { _endY = endY; }
	void setThrowPower(float throwDamage) { _throwDamage = throwDamage; }

	void setPlayerAddressLink(player*  player) { _player = player; }
};

