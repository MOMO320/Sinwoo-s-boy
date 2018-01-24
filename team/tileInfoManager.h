#pragma once
#include "singletonBase.h"
#include "image.h"
#include "tileNode.h"
#include <map>
#include <vector>






typedef vector<tagTile_tr*> vTrInfo;
typedef vector<tagTile_obj*> vObjInfo;
typedef vector<tagTile_deco*> vDecInfo;
typedef vector<tagTile_character*> vCharInfo;
typedef vector<tagTile_event*> vEvInfo;

typedef map<string, tagTile_tr*> mapTRList;
typedef map<string, tagTile_obj*> mapOBJList;
typedef map<string, tagTile_deco*> mapDecList;
typedef map<string, tagTile_character*> mapCharList;
typedef map<string, tagTile_event*> mapEvList;

class tileInfoManager : public singletonBase<tileInfoManager>
{
private:

private:

	mapTRList _mTILE_TR;
	mapTRList _mTILE_TR_SET;

	mapOBJList _mTILE_OBJ;

	mapDecList _mTILE_DEC;

	mapCharList _mTILE_CHAR;

	mapEvList _mTILE_EVENT;

public:
	tileInfoManager();
	~tileInfoManager();

	HRESULT init();
	void release();

	//지형
	tagTile_tr* addTerrain(string tileKey, string imgKey, POINT index, TERRAIN trIndex);

	tagTile_tr* addTerrain(string tileKey, string imgKey, POINT startIndex, POINT endIndex, TERRAIN trIndex);

	tagTile_tr* addTerrain(string tileKey, string imgKey, POINT* IndexArr, int arrSize, TERRAIN trIndex);

	tagTile_tr* addFrameTerrain(string tileKey, string imgKey, POINT index, TERRAIN trIndex);

	tagTile_tr* findTerrain(string tileKey);

	//오브젝트
	tagTile_obj* addObject(string objKey, string imgKey, POINT index, POINT volume, POINT offset, OBJECT objIndex);
	tagTile_obj* addObject(string objKey, string imgKey, POINT startIndex, POINT endIndex, OBJECT objIndex);
	tagTile_obj* findObj(string objKey);

	//데코
	tagTile_deco* addDecoration(string decKey, string imgKey, DECORATION decoIndex, BOOL isFrame, POINT index, POINT offset, int weight);

	tagTile_deco* addDecoration(string decKey, string imagKey, DECORATION decoIndex, BOOL isFrame, POINT* indexArr, int arrSize, int weight);

	tagTile_deco* findDec(string decKey);

	vDecInfo* findAllDeco();

	//캐릭터
	tagTile_character* addCharacter(string cKey, string imgKey, CHARACTER cIndex, POINT offset);

	tagTile_character* findChracter(string cKey);

	vCharInfo* findAllCharacter();

	//enum 종류별 지형 찾기
	vTrInfo* findTerrain_Index(TERRAIN trIndex);

	vObjInfo* findObject_Index(OBJECT obIndex);

	vDecInfo* findDeco_Index(DECORATION decoIndex);

	vCharInfo* findCharacter_Index(CHARACTER charIndex);
};