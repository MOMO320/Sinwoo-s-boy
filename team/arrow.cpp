#include "stdafx.h"
#include "arrow.h"
#include "player.h"

arrow::arrow()
{
}


arrow::~arrow()
{

}
HRESULT arrow::init(){

	_itemImage = IMAGEMANAGER->addFrameImage("arrowthrow", "./image/item/화살.bmp", 38, 152, 1, 4, true, RGB(255, 0, 255));
		_itemInvenImage = IMAGEMANAGER->addImage("arrow", "./image/item/화살(상점).bmp", 50, 50, true, RGB(255, 0, 255));
	_itemRightTopImage = NULL;

	_isVisible = true;
	//_isVisible = false;
	_itemEffect = 1;
	_itemType = WEAPON;
	_itemState = IDLE;

	_mainPlayer = NULL;

	_price = 150;

	_count = 10;

	_isShot = false;
	_direction = 0;
	return S_OK;
}
HRESULT arrow::init(int x, int y)
{
	_itemImage = IMAGEMANAGER->addFrameImage("arrowthrow", "./image/item/화살.bmp", 38, 152, 1, 4, true, RGB(255, 0, 255));
	_itemInvenImage = IMAGEMANAGER->addImage("arrow", "./image/item/화살(상점).bmp", 50, 50, true, RGB(255, 0, 255));
	_itemRightTopImage =  NULL;

	_isVisible = true;
	//_isVisible = false;
	_itemEffect = 1;
	_itemType = WEAPON;
	_itemState = IDLE;

	_x = x; _y = y;

	_price = 150;

	_count = 0;
	return S_OK;
}

void arrow::update()
{
	if (_itemState == THROW)
	{
		if (getDistance(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y),
			_mainPlayer->getPlayerRC().left, _mainPlayer->getPlayerRC().top) <= 250)
		{
			switch (_direction)
			{
				//왼
			case 0:
				_x -= 5;
				break;

				//위
			case 1:
				_y -= 5;
				break;

				//오
			case 2:
				_x += 5;
				break;

				//아
			case 3:
				_y += 5;
				break;
			default:
				break;
			}
		}
		else
		{
			_itemState = IDLE;
		}
	}

	//화살이 어느정도 이동하거나 무언가에 부딪히면 상태값 변경
}

void arrow::render()
{
	

	if (_itemState == IDLE)
		_itemInvenImage->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y));

	else
	{
		//TextOut(getMemDC(), 500, 300, "제발", strlen("제발"));
		_itemImage->frameRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y),0,_direction);
	}
}

void arrow::fire(float x, float y, int direction)
{
	//화살이 0개면
	if (_count == 0) return;

	//1개만 쏴지도록
	if (_itemState == THROW) return;

	//화살이 쏴졌냐
	//if (_isShot) return;

	//여기까지 오면 화살이 있고 쏘지 않았다면 화살이 발사된다!

	//화살의 상태는 발사상태
	_itemState = THROW;

	//화살 발사 위치
	_x = x;
	_y =y;
	//_isShot = true;

	//방향
	_direction = direction;
}