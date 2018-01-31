#include "stdafx.h"
#include "shop.h"
#include "heart.h"
#include "HPMaterial.h"
#include "arrow.h"

shop::shop()
{
	IGMAP->setShopInitF( [&]()->void { init(); });
}


shop::~shop()
{

}

HRESULT shop::init()
{
	//�����Ǹ� ������ ���� ����
	itemParent* shopHPMaterial = new HPMaterial;
	shopHPMaterial->init(175,325);

	_vShopItem.push_back(shopHPMaterial);

	itemParent* shopHeart = new heart;
	shopHeart->init(350, 350);

	_vShopItem.push_back(shopHeart);

	itemParent* shopArrow = new arrow;
	shopArrow->init(500, 350);

	_vShopItem.push_back(shopArrow);

	//_testRC = RectMakeCenter(500, WINSIZEY - 100, 50, 50);
	return S_OK;
}
void shop::release()
{

}
void shop::update()
{
	/*if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_testRC.top -= 3;
		_testRC.bottom = _testRC.top + 50;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_testRC.right += 3;
		_testRC.left = _testRC.right - 50;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_testRC.top += 3;
		_testRC.bottom = _testRC.top + 50;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_testRC.right -= 3;
		_testRC.left = _testRC.right - 50;
	}*/
	for (int i = 0; i < _vShopItem.size(); ++i)
	{
		//�����ؼ� ����� �������̸� �ƹ��͵� ���� ����
		if (!_vShopItem[i]->getIsVisible()) continue;

		//�浹 & ZŰ �Է½� ������ ����
		RECT temp;
		if (IntersectRect(&temp, &_mainPlayer->getPlayerRC(), &_vShopItem[i]->getCameraRC()))
		{
			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				//���� �������� �������� ���ݺ��� �������
				if (_inven->getMoney() >= _vShopItem[i]->getPrice())
				{
					//������ ������

					//���� ����ϰ��
					if (i == 0)
					{
						//������ ���� ���� �ϰ�� �������� ���Ѵ�.
						//������ ����ִ� ���°� �ƴҰ�� �������� ���Ѵ�.
						if (!_inven->getPotion()->getIsVisible()
							|| _inven->getPotion()->getIsFull())
						{
							continue;
						}

						//�� ���� �ϰ��
						if (!_inven->getPotion()->getIsFull())
						{
							_inven->getPotion()->setIsFull(true);
						}
					}
					//��Ʈ�ϰ��
					if (i == 1)
					{
						_mainPlayer->setPlayerHP(1);
					}
					//�������� ȭ���ϰ�� ȭ�찹�� ����
					if (i == 2)
					{
						_inven->getBow()->getArrow()->setCount(10);
					}

					_vShopItem[i]->setIsVisible(false);
					_inven->setMoney(-(_vShopItem[i]->getPrice()));
				}
			}
		}
	}

	sprintf(test, "ȭ�찹�� : %d ", _inven->getBow()->getArrow()->getCount());
}
void shop::render()
{
	for (int i = 0; i < _vShopItem.size(); ++i)
	{
		//�������� ���̳� --> ���� ���� �ȵ� --> �׷���
		if (_vShopItem[i]->getIsVisible())
		{
			
			_vShopItem[i]->render();
		//	CAMERAMANAGER->re
			RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_vShopItem[i]->getRC().left), CAMERAMANAGER->CameraRelativePointY(_vShopItem[i]->getRC().top)
				,40,40);
			//Rectangle(getMemDC(), _vShopItem[i]->getRC().left, _vShopItem[i]->getRC().top, _vShopItem[i]->getRC().right, _vShopItem[i]->getRC().bottom);
		}
	}
	//Rectangle(getMemDC(), _mainPlayer->getPlayerRC().left, _mainPlayer->getPlayerRC().top, _mainPlayer->getPlayerRC().right, _mainPlayer->getPlayerRC().bottom);

	TextOut(getMemDC(), 100, 100, test, strlen(test));
}