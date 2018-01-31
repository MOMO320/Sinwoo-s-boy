#include "stdafx.h"
#include "arrow.h"
#include "player.h"
#include "enemyManager.h"

arrow::arrow()
{
}


arrow::~arrow()
{

}
HRESULT arrow::init(){

	_itemImage = IMAGEMANAGER->addFrameImage("arrowthrow", "./image/item/ȭ��.bmp", 38, 152, 1, 4, true, RGB(255, 0, 255));
		_itemInvenImage = IMAGEMANAGER->addImage("arrow", "./image/item/ȭ��(����).bmp", 50, 50, true, RGB(255, 0, 255));
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
	_itemImage = IMAGEMANAGER->addFrameImage("arrowthrow", "./image/item/ȭ��.bmp", 38, 152, 1, 4, true, RGB(255, 0, 255));
	_itemInvenImage = IMAGEMANAGER->addImage("arrow", "./image/item/ȭ��(����).bmp", 50, 50, true, RGB(255, 0, 255));
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
		for (int i = 0; i < _em->getVEnemy().size(); ++i)
		{
			//���󰡴� ���߿� ���Ͱ� �¾ҳ�
			if (getDistance(_x, _y, _em->getVEnemy()[i]->getPoint().x, _em->getVEnemy()[i]->getPoint().y) < 25)
			{
				//������ �Ǹ� ���
				_em->getVEnemy()[i]->setCrrentHP(1);

				//ȭ���� ���´� ���ƿ´�.
				_itemState = IDLE;
			}
			//if (IntersectRect(&temp, &_em->getVEnemy()[i]->get))
		}
		if (_itemState == THROW &&
			getDistance(CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y),
			_mainPlayer->getPlayerRC().left, _mainPlayer->getPlayerRC().top) <= 250)
		{
			switch (_direction)
			{
				//��
			case 0:
				_x -= 7;
				break;

				//��
			case 1:
				_y -= 7;
				break;

				//��
			case 2:
				_x += 7;
				break;

				//��
			case 3:
				_y += 7;
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

	//ȭ���� ������� �̵��ϰų� ���𰡿� �ε����� ���°� ����
}

void arrow::render()
{
	

	if (_itemState == IDLE)
		_itemInvenImage->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y));

	else
	{
		//TextOut(getMemDC(), 500, 300, "����", strlen("����"));
		_itemImage->frameRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y),0,_direction);
	}
}

void arrow::fire(float x, float y, int direction)
{
	//ȭ���� 0����
	if (_count == 0) return;

	//1���� ��������
	if (_itemState == THROW) return;

	//ȭ���� ������
	//if (_isShot) return;

	//������� ���� ȭ���� �ְ� ���� �ʾҴٸ� ȭ���� �߻�ȴ�!

	//ȭ���� ���´� �߻����
	_itemState = THROW;
	SOUNDMANAGER->play("01.arrow", 1);
	//ȭ�� �߻� ��ġ
	_x = x;
	_y =y;
	//_isShot = true;

	//����
	_direction = direction;
	_count--;
}