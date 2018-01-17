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
	bool isFrame;

	tagTile_obj()
	{
		OBJ_INDEX = I;
		_image = NULL;
		imageIndex = { 0,0 };
		VOLUME = { 1,1 };
		isFrame = false;
	}

};

typedef vector<tagTile_tr*> vTrInfo;
typedef vector<tagTile_obj> vObjInfo;
typedef map<string, tagTile_tr*> mapTRList;
typedef map<string, tagTile_obj*> mapOBJList;

class tileInfoManager : public singletonBase<tileInfoManager>
{
private:
private:

	mapTRList _mTILE_TR;
	mapTRList _mTILE_TR_SET;

	mapOBJList _mTILE_OBJ;



public:
	tileInfoManager();
	~tileInfoManager();

	HRESULT init();
	void release();

	tagTile_tr* addTerrain(string tileKey, string imgKey, POINT index, TERRAIN trIndex);

	tagTile_tr* addTerrain(string tileKey, string imgKey, POINT startIndex, POINT endIndex, TERRAIN trIndex);

	tagTile_tr* addFrameTerrain(string tileKey, string imgKey, POINT index, TERRAIN trIndex);

	tagTile_obj* addObject(string objKey, string imgKey, POINT index, POINT volume, OBJECT objIndex);

	tagTile_tr* findTerrain(string tileKey);

	tagTile_obj* findObj(string objKey);


	vTrInfo* findTerrain_Index(TERRAIN trIndex);



};

