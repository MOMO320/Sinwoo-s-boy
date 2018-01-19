#pragma once
#include "singletonBase.h"
#include "image.h"
#include "tileNode.h"
#include <map>
#include <vector>


struct tagTile_tr
{
	TERRAIN TR_INDEX;
	image* _image;
	POINT imageIndex;
	bool isFrame;

	tagTile_tr()
	{
		TR_INDEX = TR_BASIC;
		_image = NULL;
		imageIndex = { 0,0 };
		isFrame = false;
	}


};

struct tagTile_obj
{
	OBJECT OBJ_INDEX;
	image* _image;
	POINT imageIndex;
	POINT VOLUME;
	POINT _offSet;
	bool isFrame;

	tagTile_obj()
	{
		OBJ_INDEX = OBJECT_NONE;
		_image = NULL;
		imageIndex = { 0,0 };
		VOLUME = { 1,1 };
		_offSet = { 0,0 };
		isFrame = false;
	}

};

struct tagTile_deco
{
	DECORATION DECO_INDEX;
	image* _image;
	POINT imageIndex;
	
	tagTile_deco()
	{
		DECO_INDEX = DECO_NONE;
		_image = NULL;
		imageIndex = { 0,0 };
	}
};

typedef vector<tagTile_tr*> vTrInfo;
typedef vector<tagTile_obj*> vObjInfo;
typedef vector<tagTile_deco*> vDecInfo;
typedef map<string, tagTile_tr*> mapTRList;
typedef map<string, tagTile_obj*> mapOBJList;
typedef map<string, tagTile_deco*> mapDecList;

class tileInfoManager : public singletonBase<tileInfoManager>
{
private:

private:

	mapTRList _mTILE_TR;
	mapTRList _mTILE_TR_SET;

	mapOBJList _mTILE_OBJ;

	mapDecList _mTILE_DEC;

public:
	tileInfoManager();
	~tileInfoManager();

	HRESULT init();
	void release();

	tagTile_tr* addTerrain(string tileKey, string imgKey, POINT index, TERRAIN trIndex);

	tagTile_tr* addTerrain(string tileKey, string imgKey, POINT startIndex, POINT endIndex, TERRAIN trIndex);

	tagTile_tr* addTerrain(string tileKey, string imgKey, POINT* IndexArr,int arrSize, TERRAIN trIndex);

	tagTile_tr* addFrameTerrain(string tileKey, string imgKey, POINT index, TERRAIN trIndex);

	tagTile_obj* addObject(string objKey, string imgKey, POINT index, POINT volume, POINT offset ,OBJECT objIndex);

	tagTile_tr* findTerrain(string tileKey);

	tagTile_obj* findObj(string objKey);

	tagTile_deco* addDecoration(string decKey, string imgKey, POINT index, DECORATION decoIndex);

	tagTile_deco* findDec(string decKey);


	vTrInfo* findTerrain_Index(TERRAIN trIndex);

	vObjInfo* findObject_Index(OBJECT obIndex);

	vDecInfo* findDeco_Index(DECORATION decoIndex);
};

