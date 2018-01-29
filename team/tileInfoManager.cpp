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

	//이름이 겹치면 0~찾아서 시작할 지점을 찾는다.
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
	tr->imageIndex.push_back( { index.x * TILESIZE,index.y * TILESIZE });
	tr->TR_INDEX = trIndex;
	tr->imageName = imgKey;
	tr->trKey = tileKey;

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

	//이름이 겹치면 0~찾아서 시작할 지점을 찾는다.
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
			tr->imageIndex.push_back( { (j + startIndex.x) * TILESIZE,(i + startIndex.y) * TILESIZE });
			tr->TR_INDEX = trIndex;
			tr->imageName = imgKey;
			tr->trKey = a;
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

	//이름이 겹치면 0~찾아서 시작할 지점을 찾는다.
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
		tr->imageIndex.push_back( { IndexArr[i].x * TILESIZE,IndexArr[i].y * TILESIZE });
		tr->TR_INDEX = trIndex;
		tr->imageName = imgKey;
		tr->trKey = a;
		k++;
		_mTILE_TR.insert(make_pair(a, tr));
	}

	a = tileKey;
	b = to_string(c);
	return findTerrain(a.append(b));
}

tagTile_tr * tileInfoManager::addFrameTerrain(string tileKey, string imgKey, POINT* FrameArr, int arrSize, TERRAIN trIndex)
{
	int k = 0;
	string a(tileKey);
	string b = to_string(k);
	a.append(b); //스트링 합치기

				 //이름이 겹치면 0~찾아서 시작할 지점을 찾는다.
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


	if (tr != NULL) return tr;

	tr = new tagTile_tr;
	tr->_image = IMAGEMANAGER->findImage(imgKey);
	for (int i = 0; i < arrSize; ++i)
	{
		tr->imageIndex.push_back(FrameArr[i]);
	}
	tr->TR_INDEX = trIndex;
	tr->isFrame = true;
	tr->imageName = imgKey;
	tr->trKey = tileKey;

	_mTILE_TR.insert(make_pair(tileKey, tr));

	return tr;
}

tagTile_obj * tileInfoManager::addObject(string objKey, string imgKey, POINT index, POINT volume, POINT offset, OBJECT objIndex)
{
	int k = 0;
	string a(objKey);
	string b = to_string(k);
	a.append(b); //스트링 합치기

				 //이름이 겹치면 0~찾아서 시작할 지점을 찾는다.
	tagTile_obj* to = findObj(a);
	if (to != NULL)
	{
		k++;
		while (to != NULL)
		{
			a = objKey;
			b = to_string(k);
			a.append(b);
			to = findObj(a);
			if (to != NULL) k++;
		}
	}


	if (to != NULL) return to;
	//값만 넣어주는 곳
	to = new tagTile_obj;
	to->_image = IMAGEMANAGER->findImage(imgKey); //이미지
	to->imageIndex.push_back({ index.x * TILESIZE, index.y * TILESIZE }); //인덱스 자리
	to->OBJ_INDEX = objIndex;
	to->VOLUME.x = volume.x; //IMAGEMANAGER->findImage(imgKey)->getFrameWidth() *;
	to->VOLUME.y = volume.y; //IMAGEMANAGER->findImage(imgKey)->getFrameHeight() *;
	to->_offSet.x = offset.x;
	to->_offSet.y = offset.y;
	to->isFrame = false;
	to->imageName = imgKey;
	to->objKey = objKey;


	_mTILE_OBJ.insert(make_pair(objKey, to));

	return to;
}

tagTile_obj * tileInfoManager::addObject(string objKey, string imgKey, POINT startIndex, POINT endIndex, OBJECT objIndex)
{
	int numX, numY;
	numX = (endIndex.x - startIndex.y + 1);
	numY = (endIndex.y - startIndex.y + 1);

	int k = 0;
	string a(objKey);
	string b = to_string(k);
	a.append(b);

	tagTile_obj* ob = findObj(a);
	if (ob != NULL)
	{
		k++;
		while(ob != NULL)
		{
			a = objKey;
			b = to_string(k);
			a.append(b);
			ob = findObj(a);
			if (ob != NULL) k++;
		}
	}
	int c = k;
	for (int i = 0; i < numY; ++i)
	{
		for (int j = 0; j < numX; ++j)
		{
			a = objKey;
			b = to_string(k);
			a.append(b);
			ob = new  tagTile_obj;
			ob->_image = IMAGEMANAGER->findImage(imgKey);
			ob->imageIndex.push_back({ (j + startIndex.x) * TILESIZE,(i + startIndex.y) * TILESIZE });
			ob->OBJ_INDEX = objIndex;
			ob->imageName = imgKey;
			ob->objKey = a;
			k++;
			_mTILE_OBJ.insert(make_pair(a, ob));
		}
	}
	a = objKey;
	b = to_string(c);
	return findObj(a.append(b));
}

tagTile_obj * tileInfoManager::addFrameObject(string objKey, string imgKey, POINT * FrameArr, int arrSize, POINT volume, POINT offset, OBJECT objIndex)
{
	int k = 0;
	string a(objKey);
	string b = to_string(k);
	a.append(b); //스트링 합치기

				 //이름이 겹치면 0~찾아서 시작할 지점을 찾는다.
	tagTile_obj* to = findObj(a);
	if (to != NULL)
	{
		k++;
		while (to != NULL)
		{
			a = objKey;
			b = to_string(k);
			a.append(b);
			to = findObj(a);
			if (to != NULL) k++;
		}
	}


	if (to != NULL) return to;
	//값만 넣어주는 곳
	to = new tagTile_obj;
	to->_image = IMAGEMANAGER->findImage(imgKey); //이미지
	for (int i = 0; i < arrSize; ++i)
	{
		to->imageIndex.push_back({ FrameArr[i].x * TILESIZE, FrameArr[i].y * TILESIZE }); //인덱스 자리
	}
	to->OBJ_INDEX = objIndex;
	to->VOLUME.x = volume.x; //IMAGEMANAGER->findImage(imgKey)->getFrameWidth() *;
	to->VOLUME.y = volume.y; //IMAGEMANAGER->findImage(imgKey)->getFrameHeight() *;
	to->_offSet.x = offset.x;
	to->_offSet.y = offset.y;
	to->isFrame = true;
	to->imageName = imgKey;
	to->objKey = objKey;


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

	tagTile_deco* dc = findDec(a);
	if (dc != NULL)
	{
		k++;
		while (dc != NULL)
		{
			a = decKey;
			b = to_string(k);
			a.append(b);
			dc = findDec(a);
			if (dc != NULL) k++;
		}
	}

	int c = k;

	if (dc != NULL) return dc;

	dc = new tagTile_deco;
	dc->_image = IMAGEMANAGER->findImage(imgKey);
	dc->imageIndex.push_back({ index.x * TILESIZE,index.y * TILESIZE });
	dc->DECO_INDEX = decoIndex;
	dc->imageName = imgKey;
	dc->_offset = offset;
	dc->decoKey = decKey;

	_mTILE_DEC.insert(make_pair(decKey, dc));

	return dc;
}

tagTile_deco * tileInfoManager::addDecoration(string decKey, string imagKey, DECORATION decoIndex, BOOL isFrame, POINT * indexArr, int arrSize, POINT offset, int weight , int pos)
{
	int k = 0;
	string a(decKey);
	string b = to_string(k);
	a.append(b);

	tagTile_deco* dc = findDec(a);
	if (dc != NULL)
	{
		k++;
		while (dc != NULL)
		{
			a = decKey;
			b = to_string(k);
			a.append(b);
			dc = findDec(a);
			if (dc != NULL) k++;
		}
	}

	int c = k;

	if (dc != NULL) return dc;

	dc = new tagTile_deco;

	dc->DECO_INDEX = decoIndex;
	dc->_image = IMAGEMANAGER->findImage(imagKey);
	for (int i = 0; i < arrSize; i++)
	{
		dc->imageIndex.push_back({ indexArr[i].x * TILESIZE,indexArr[i].y * TILESIZE });
	}
	dc->_offset = offset;
	dc->isFrame = isFrame;
	dc->maxFrame = arrSize;
	dc->weight = weight;
	dc->imageName = imagKey;
	dc->decoKey = a;
	dc->position = pos;
	
	a = decKey;
	b = to_string(c);
	a.append(b);
	dc->decoKey = a;

	_mTILE_DEC.insert(make_pair(a, dc));

	return dc;
}

tagTile_deco * tileInfoManager::addDecoration(string decKey, string imgKey, POINT startIndex, POINT endIndex, BOOL isFrame, DECORATION decoIndex, int weight , int pos)
{
	int numX, numY;
	numX = (endIndex.x - startIndex.y + 1);
	numY = (endIndex.y - startIndex.y + 1);

	int k = 0;
	string a(decKey);
	string b = to_string(k);
	a.append(b);

	tagTile_deco* dc = findDec(a);
	if (dc != NULL)
	{
		k++;
		while (dc != NULL)
		{
			a = decKey;
			b = to_string(k);
			a.append(b);
			dc = findDec(a);
			if (dc != NULL) k++;
		}
	}
	int c = k;
	for (int i = 0; i < numY; ++i)
	{
		for (int j = 0; j < numX; ++j)
		{
			a = decKey;
			b = to_string(k);
			a.append(b);
			dc = new  tagTile_deco;
			dc->_image = IMAGEMANAGER->findImage(imgKey);
			dc->imageIndex.push_back({ (j + startIndex.x) * TILESIZE,(i + startIndex.y) * TILESIZE });
			dc->DECO_INDEX = decoIndex;
			dc->imageName = imgKey;
			dc->decoKey = a;
			dc->weight = weight;
			dc->position = pos;
			k++;
			_mTILE_DEC.insert(make_pair(a, dc));
		}
	}
	a = decKey;
	b = to_string(c);
	a.append(b);
	return findDec(a.append(b));
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
	tc->imageName = imgKey;
	tc->charKey = cKey;

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
