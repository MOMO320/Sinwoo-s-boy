#pragma once
#include "gameNode.h"

//아이템 종류
enum tagItemType{
	POTION,		//포션
	MONEY,		//돈
	WEAPON,		//무기
	SHIELD		//방패
};

//아이템 상태
enum tagItemState{
	IDLE,	//기본
	THROW	//던져짐(활or부메랑)
};

class itemParent :
	public gameNode
{

protected:
	image*	_itemImage;			//아이템 투척 이미지
	image*  _itemInvenImage;	//아이템 인벤토리 이미지
	image*  _itemRightTopImage;	//아이템 인벤토리 우상단 이미지

	float _x, _y;		//이미지의 중점

	bool _isVisible;	//인벤토리에서 이미지를 그릴것인지
	int _itemEffect;	//아이템 효과(포션 : 피회복, 무기 : 데미지 등등)

	tagItemType _itemType;		//아이템 종류
	tagItemState _itemState;	//아이템 상태

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//virtual void isGain();
	//아이템 좌표 설정
	void setX(float x){ _x = x; }	
	void setY(float y){ _y = y; }

	//아이템 렉트 접근자 (중점에서 40,40크기의 렉트)
	RECT getRC(){ return RectMakeCenter(_x, _y, 40, 40); }	

	//아이템 효과 접근자
	int getItemEffect(){ return _itemEffect; }

	//아이템 투척 이미지
	image* getItemImage(){ return _itemImage; }

	//아이템 인벤 이미지
	image* getItemInvenImage(){ return _itemInvenImage; }

	//인벤 우상단 이미지
	image* getItemRightTopImage(){ return _itemRightTopImage; }

	bool getIsVisible(){ return _isVisible; }

	itemParent();
	~itemParent();
};

