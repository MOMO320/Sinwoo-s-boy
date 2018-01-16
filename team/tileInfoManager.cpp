#include "stdafx.h"
#include "tileInfoManager.h"


tileInfoManager::tileInfoManager()
{
}


tileInfoManager::~tileInfoManager()
{
}


HRESULT tileInfoManager::init()
{

	return S_OK;
}
void tileInfoManager::release()
{

}


tagTILE_TR* tileInfoManager::addTerrain(string strKey, TERRAIN TRindex, const char* fileName, int width, int height, bool trans, COLORREF transColor)
{
	tagTILE_TR* tr = findTerrain(strKey);

	return tr;
}

tagTILE_TR* tileInfoManager::addTerrain(string strKey, TERRAIN TRindex, const char* fileName, int sourX, int sourY, int width, int height, bool trans, COLORREF transColor)
{
	tagTILE_TR* tr = findTerrain(strKey);

	return tr;
}


tagTILE_TR* tileInfoManager::addTerrain(string strKey, TERRAIN TRindex, const char* fileName, int sourX, int sourY, int width, int height, int destX, int destY, bool trans, COLORREF transColor)
{
	tagTILE_TR* tr = findTerrain(strKey);

	return tr;
}

tagTILE_TR* tileInfoManager::addFrameTerrain(string strKey, TERRAIN TRindex, const char* fileName, int sourX, int sourY, int widht, int height, bool trans, COLORREF transColor)
{
	tagTILE_TR* tr = findTerrain(strKey);

	return tr;
}

tagTILE_OBJ* tileInfoManager::addObject(string strKey, OBJECT OBJindex, const char* fileName, int width, int height, int volumeX, int volumeY, bool trans, COLORREF transColor)
{
	tagTILE_OBJ* tr = findObject(strKey);

	return tr;
}

tagTILE_OBJ* tileInfoManager::addFrameObject(string strKey, OBJECT OBJindex, const char* fileName, int width, int height, int frameX, int frameY, int volumeX, int volumeY, bool trans, COLORREF transColor)
{
	tagTILE_OBJ* tr = findObject(strKey);

	return tr;
}

tagTILE_TR* tileInfoManager::findTerrain(string strKey)
{
	tagTILE_TR* tr = findTerrain(strKey);

	return tr;
}

tagTILE_OBJ* tileInfoManager::findObject(string strKey)
{
	tagTILE_OBJ* tr = findObject(strKey);

	return tr;
}

BOOL tileInfoManager::deleteTerrain(string strKey)
{
	return 0;
}

BOOL tileInfoManager::deleteObject(string strKey)
{
	return 0;
}


BOOL tileInfoManager::deleteAll(void)																																										
{
	return 0;
}
