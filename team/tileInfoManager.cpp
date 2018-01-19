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

tagTile_tr * tileInfoManager::addTerrain(string tileKey, string imgKey, POINT index, TERRAIN trIndex)
{
	int k = 0;
	string a(tileKey);
	string b = to_string(k);
	a.append(b);

	tagTile_tr* tr = findTerrain(a);
	if (tr != NULL)
	{
		k++;
		while (tr != NULL)
		{
			a = tileKey;
			b = to_string(k);
			a.append(b);
			tr = findTerrain(a);
			if (tr != NULL) k++;
		}
	}
	int a;
	int b;
	int c = k;

	if (tr != NULL) return tr;

	tr = new tagTile_tr;
	tr->_image = IMAGEMANAGER->findImage(imgKey);
	tr->imageIndex = { index.x * TILESIZE,index.y * TILESIZE };
	tr->TR_INDEX = trIndex;

	_mTILE_TR.insert(make_pair(tileKey, tr));

	return tr;
}

tagTile_tr * tileInfoManager::addTerrain(string tileKey, string imgKey, POINT startIndex, POINT endIndex, TERRAIN trIndex)
{
	int numX, numY;
	numX = (endIndex.x - startIndex.y + 1);
	numY = (endIndex.y - startIndex.y + 1);
	int k = 0;
	string a(tileKey);
	string b = to_string(k);
	a.append(b);

	int a;
	int b;
	tagTile_tr* tr = findTerrain(a);
	if (tr != NULL)
	{
		k++;
		while (tr != NULL)
		{
			a = tileKey;
			b = to_string(k);
			a.append(b);
			tr = findTerrain(a);
			if (tr != NULL) k++;
		}
	}

	int c = k;

	for (int i = 0; i < numY; ++i)
	{
		for (int j = 0; j < numX; ++j)
		{
			a = tileKey;
			b = to_string(k);
			a.append(b);
			tr = new tagTile_tr;
			tr->_image = IMAGEMANAGER->findImage(imgKey);
			tr->imageIndex = { (j + startIndex.x) * TILESIZE,(i + startIndex.y) * TILESIZE };
			tr->TR_INDEX = trIndex;
			k++;
			_mTILE_TR.insert(make_pair(a, tr));
		}
	}

	a = tileKey;
	b = to_string(c);
	return findTerrain(a.append(b));
}

tagTile_tr * tileInfoManager::addTerrain(string tileKey, string imgKey, POINT * IndexArr, int arrSize, TERRAIN trIndex)
{
	int k = 0;
	string a(tileKey);
	string b = to_string(k);
	a.append(b); //스트링 합치기

	int a;
	int b;
	tagTile_tr* tr = findTerrain(a);
	if (tr != NULL)
	{
		k++;
		while (tr != NULL)
		{
			a = tileKey;
			b = to_string(k);
			a.append(b);
			tr = findTerrain(a);
			if (tr != NULL) k++;
		}
	}

	int c = k;

	if (tr != NULL) return tr;

	for (int i = 0; i < arrSize; ++i)
	{
		a = tileKey;
		b = to_string(k);
		a.append(b);
		tr = new tagTile_tr;
		tr->_image = IMAGEMANAGER->findImage(imgKey);
		tr->imageIndex = { IndexArr[i].x * TILESIZE,IndexArr[i].y * TILESIZE };
		tr->TR_INDEX = trIndex;
		k++;
		_mTILE_TR.insert(make_pair(a, tr));
	}

	a = tileKey;
	b = to_string(c);
	return findTerrain(a.append(b));
}

tagTile_tr * tileInfoManager::addFrameTerrain(string tileKey, string imgKey, POINT index, TERRAIN trIndex)
{
	tagTile_tr* tr = findTerrain(tileKey);

	if (tr != NULL) return tr;

	int a;
	int b;
	tr = new tagTile_tr;
	tr->_image = IMAGEMANAGER->findImage(imgKey);
	tr->imageIndex = index;
	tr->TR_INDEX = trIndex;
	tr->isFrame = true;

	_mTILE_TR.insert(make_pair(tileKey, tr));

	return tr;
}

tagTile_obj * tileInfoManager::addObject(string objKey, string imgKey, POINT index, POINT volume, POINT offset, OBJECT objIndex)
{
	//int numX, numY;
	//numX = (endIndex.x - startIndex.y + 1);
	//numY = (endIndex.y - startIndex.y + 1);
	//int k = 0;
	//string a(tileKey);
	//string b = to_string(k);
	//a.append(b);
	//tagTile_tr* tr = findTerrain(a);
	//if (tr != NULL)
	//{
	//	k++;
	//	while (tr != NULL)
	//	{
	//		a = tileKey;
	//		b = to_string(k);
	//		a.append(b);
	//		tr = findTerrain(a);
	//		if (tr != NULL) k++;
	//	}
	//}
	//int c = k;
	//for (int i = 0; i < numY; ++i)
	//{
	//	for (int j = 0; j < numX; ++j)
	//	{
	//		a = tileKey;
	//		b = to_string(k);
	//		a.append(b);
	//		tr = new tagTile_tr;
	//		tr->_image = IMAGEMANAGER->findImage(imgKey);
	//		tr->imageIndex = { (j + startIndex.x) * TILESIZE,(i + startIndex.y) * TILESIZE };
	//		tr->TR_INDEX = trIndex;
	//		k++;
	//		_mTILE_TR.insert(make_pair(a, tr));
	//	}
	//}
	//a = tileKey;
	//b = to_string(c);

	int a;
	int b;
	tagTile_obj* to = findObj(objKey);

	if (to != NULL) return to;
	//값만 넣어주는 곳
	to = new tagTile_obj;
	to->_image = IMAGEMANAGER->findImage(imgKey); //이미지
	to->imageIndex = { index.x * TILESIZE, index.y * TILESIZE }; //인덱스 자리
	to->OBJ_INDEX = objIndex;
	to->VOLUME.x = volume.x; //IMAGEMANAGER->findImage(imgKey)->getFrameWidth() *;
	to->VOLUME.y = volume.y; //IMAGEMANAGER->findImage(imgKey)->getFrameHeight() *;
	to->_offSet.x = offset.x;
	to->_offSet.y = offset.y;
	to->isFrame = true;


	_mTILE_OBJ.insert(make_pair(objKey, to));

	return to;
}

tagTile_tr * tileInfoManager::findTerrain(string tileKey)
{
	auto key = _mTILE_TR.find(tileKey);

	if (key != _mTILE_TR.end())
		return key->second;

	int a;
	int b;
	return NULL;
}

tagTile_obj * tileInfoManager::findObj(string objKey)
{
	auto key = _mTILE_OBJ.find(objKey);

	if (key != _mTILE_OBJ.end())
		return key->second;

	return NULL;
}

vTrInfo* tileInfoManager::findTerrain_Index(TERRAIN trIndex)
{
	vTrInfo* vTemp = new vTrInfo;

	auto iter = _mTILE_TR.begin();

	for (; iter != _mTILE_TR.end(); iter++)
	{
		if (iter->second->TR_INDEX != trIndex) continue;

		vTemp->push_back(iter->second);
	}

	return vTemp;
}

vObjInfo * tileInfoManager::findObject_Index(OBJECT obIndex)
{
	vObjInfo* vTemp = new vObjInfo;

	auto iter = _mTILE_OBJ.begin();

	for (; iter != _mTILE_OBJ.end(); iter++)
	{
		if (iter->second->OBJ_INDEX != obIndex)continue;
		vTemp->push_back(iter->second);
	}
	return vTemp;
}
