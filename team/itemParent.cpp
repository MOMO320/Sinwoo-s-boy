#include "stdafx.h"
#include "itemParent.h"


itemParent::itemParent()
{
}


itemParent::~itemParent()
{

}


HRESULT itemParent::init()
{

	return S_OK;
}

HRESULT itemParent::init(int x, int y) //상점판매를 위한 init 오버로드
{

	return S_OK;
}

void itemParent::release()
{

}
void itemParent::update()
{

}
void itemParent::render()
{
	TextOut(getMemDC(), 100, 100, "test", strlen("test"));
	//_itemImage->render(getMemDC(), 50, 50);
}