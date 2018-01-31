#include "stdafx.h"
#include "boomerang.h"
#include "player.h"

boomerang::boomerang()
{
}


boomerang::~boomerang()
{
}

HRESULT boomerang::init(){	
	/*
	image*	_itemImage;	//아이템 인벤토리 이미지
	float _x, _y;		//이미지의 중점

	bool _isVisible;	//인벤토리에서 이미지를 그릴것인지
	int _itemEffect;	//아이템 효과(포션 : 피회복, 무기 : 데미지 등등)

	tagItemType _itemType;		//아이템 종류
	tagItemState _itemState;	//아이템 상태
	*/

	//아이템 이미지
	_itemImage = IMAGEMANAGER->addFrameImage("boomerangthrow", "./image/item/부메랑(날리기).bmp", 160, 40,4,1, true, RGB(255, 0, 255));
		_itemInvenImage = IMAGEMANAGER->addImage("boomerang", "./image/item/부메랑(인벤,슬롯).bmp",100,100, true, RGB(255, 0, 255));
	_itemRightTopImage = IMAGEMANAGER->addImage("boomerangRightTop", "./image/item/부메랑(우측상단).bmp", 455, 157, true, RGB(255, 0, 255));

	//_isVisible = true;
	_isVisible = false;
	_itemEffect = 1;
	_itemType = WEAPON;
	_itemState = IDLE;

	_mainPlayer = NULL;

	_frameCount = 0;

	_isBack = false;
	return S_OK;
}

void boomerang::update()
{
	float angle;
	//날라가는상태일때만
	if (_itemState == THROW)
	{
		_frameCount++;
		if (_frameCount >= 39) _frameCount = 0;

		//날라감
		if (!_isBack && 
			getDistance(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y),
			_mainPlayer->getPlayerRC().left, _mainPlayer->getPlayerRC().top) <=250)
		{
			switch (_direction)
			{
				//좌 부터해서 시계방향으로 8방향
			case 0:
				//180
				angle = PI;
				break;
			case 1:
				angle = (PI / 4) * 3;
				break;
			case 2:
				angle = PI / 2;
				break;
			case 3:
				angle = PI / 4;
				break;
			case 4:
				angle = 0;
				break;
			case 5:
				angle = (PI / 4) * 7;
				break;
			case 6:
				angle = (PI / 2) * 3;
				break;
			case 7:
				angle = (PI / 4) * 5;
				break;
			default:
				break;
			}
		}
		//돌아옴
		else
		{
			_isBack = true;
			angle = getAngle(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), _mainPlayer->getPlayerRC().left, _mainPlayer->getPlayerRC().top);
			
		}

		RECT temp;
		//돌아오는중일때 플레이어 렉트와 충돌이냐
		if (_isBack &&
			IntersectRect(&temp, &_mainPlayer->getPlayerRC(),
			&RectMakeCenter(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), 40, 40)))
		{
			_isBack = false;
			_itemState = IDLE;
			//_angle = 0;
		}
		_x += cosf(angle) * 6;
		_y += -sinf(angle) * 6;

		
	}
}


void boomerang::render()
{
	if (_itemState == THROW)
		_itemImage->frameRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), _frameCount / 10,0 );
	//itemParent::render();
	//TextOut(getMemDC(), 300, 300, "test1", strlen("test"));
	//_itemImage->frameRender(getMemDC(), 250, 30);
}

void boomerang::fire(float x, float y, int direction){

	//날라가고 있는경우 리턴
	if (_itemState == THROW) return;

	_itemState = THROW;
	_x = x;
	_y = y;
	_direction = direction;
}