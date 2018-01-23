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

	return NULL;
}

tagTile_obj * tileInfoManager::findObj(string objKey)
{
	auto key = _mTILE_OBJ.find(objKey);

	if (key != _mTILE_OBJ.end())
		return key->second;

	return NULL;
}

tagTile_deco * tileInfoManager::addDecoration(string decKey, string imgKey, DECORATION decoIndex,BOOL isFrame, POINT index, POINT offset, int weight)
{
	int k = 0;
	string a(decKey);
	string b = to_string(k);
	a.append(b);

	tagTile_deco* tr = findDec(a);
	if (tr != NULL)
	{
		k++;
		while (tr != NULL)
		{
			a = decKey;
			b = to_string(k);
			a.append(b);
			tr = findDec(a);
			if (tr != NULL) k++;
		}
	}

	int c = k;

	if (tr != NULL) return tr;

	tr = new tagTile_deco;
	tr->_image = IMAGEMANAGER->findImage(imgKey);
	tr->imageIndex.push_back({ index.x * TILESIZE,index.y * TILESIZE });
	tr->DECO_INDEX = decoIndex;

	_mTILE_DEC.insert(make_pair(decKey, tr));

	return tr;
}

tagTile_deco * tileInfoManager::addDecoration(string decKey, string imagKey, DECORATION decoIndex, BOOL isFrame, POINT * indexArr, int arrSize, int weight)
{
	int k = 0;
	string a(decKey);
	string b = to_string(k);
	a.append(b);

	tagTile_deco* tr = findDec(a);
	if (tr != NULL)
	{
		k++;
		while (tr != NULL)
		{
			a = decKey;
			b = to_string(k);
			a.append(b);
			tr = findDec(a);
			if (tr != NULL) k++;
		}
	}

	int c = k;

	if (tr != NULL) return tr;

	tr = new tagTile_deco;
	
	for (int i = 0; i < arrSize; i++)
	{
		tr->DECO_INDEX = decoIndex;
		tr->_image = IMAGEMANAGER->findImage(imagKey);
		tr->imageIndex.push_back({ indexArr[i].x * TILESIZE,indexArr[i].y * TILESIZE });
		tr->isFrame = isFrame;
		tr->maxFrame = arrSize;
		tr->weight = weight;
	}

	a = decKey;
	b = to_string(c);
	a.append(b);

	_mTILE_DEC.insert(make_pair(a, tr));

	return tr;
}

tagTile_deco * tileInfoManager::findDec(string decKey)
{
	auto key = _mTILE_DEC.find(decKey);

	if (key != _mTILE_DEC.end())
	{
		return key->second;
	}
	return NULL;
}

vDecInfo * tileInfoManager::findAllDeco()
{
	vDecInfo* vTemp = new vDecInfo;

	auto iter = _mTILE_DEC.begin();

	for (; iter != _mTILE_DEC.end(); iter++)
	{
		vTemp->push_back(iter->second);
	}

	return vTemp;
}

tagTile_character * tileInfoManager::addCharacter(string cKey, string imgKey, CHARACTER cIndex, POINT offset)
{
	int k = 0;
	string a(cKey);
	string b = to_string(k);
	a.append(b);

	tagTile_character* tc = findChracter(a);
	if (tc != NULL)
	{
		k++;
		while (tc != NULL)
		{
			a = cKey;
			b = to_string(k);
			a.append(b);
			tc = findChracter(a);
			if (tc != NULL) k++;
		}
	}

	int c = k;

	if (tc != NULL) return tc;

	tc = new tagTile_character;
	tc->_image = IMAGEMANAGER->findImage(imgKey);
	tc->_offSet = offset;
	tc->CHARACTER_INDEX = cIndex;

	_mTILE_CHAR.insert(make_pair(cKey, tc));

	return tc;
}

tagTile_character * tileInfoManager::findChracter(string cKey)
{
	auto key = _mTILE_CHAR.find(cKey);

	if (key != _mTILE_CHAR.end())
	{
		return key->second;
	}
	return NULL;
}

vCharInfo * tileInfoManager::findAllCharacter()
{
	vCharInfo* vTemp = new vCharInfo;

	auto iter = _mTILE_CHAR.begin();

	for (; iter != _mTILE_CHAR.end(); iter++)
	{
		vTemp->push_back(iter->second);
	}

	return vTemp;
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

vDecInfo * tileInfoManager::findDeco_Index(DECORATION decoIndex)
{
	vDecInfo* vTemp = new vDecInfo;

	auto iter = _mTILE_DEC.begin();

	for (; iter != _mTILE_DEC.end(); iter++)
	{
		if (iter->second->DECO_INDEX != decoIndex)continue;

		vTemp->push_back(iter->second);
	}

	return vTemp;
}

vCharInfo * tileInfoManager::findCharacter_Index(CHARACTER charIndex)
{
	vCharInfo* vTemp = new vCharInfo;

	auto iter = _mTILE_CHAR.begin();

	for (; iter != _mTILE_CHAR.end(); iter++)
	{
		if (iter->second->CHARACTER_INDEX != charIndex)continue;

		vTemp->push_back(iter->second);
	}

	return vTemp;
}
