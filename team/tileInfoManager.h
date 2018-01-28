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
	//지형등록 1 : 낱개
	tagTile_tr* addTerrain(string tileKey, string imgKey, POINT index, TERRAIN trIndex);
	//지형등록 2 : 여러 개 STARTINDEX~ENDINDEX까지 영역에 있는 타일들을 등록 (ENDINDEX.X - STARTINDEX.X) * (ENDINDEX.Y - STARTINDEX.Y) 만큼 생성
	tagTile_tr* addTerrain(string tileKey, string imgKey, POINT startIndex, POINT endIndex, TERRAIN trIndex);
	//지형등록 3 : 여러 개 POINT 배열로 등록 -> 분산되어있는 것들 프레임X
	tagTile_tr* addTerrain(string tileKey, string imgKey, POINT* IndexArr, int arrSize, TERRAIN trIndex);
	//지형등록 4 : 움직이는 지형 등록 
	tagTile_tr* addFrameTerrain(string tileKey, string imgKey, POINT* FrameArr,int arrSize, TERRAIN trIndex);

	tagTile_tr* findTerrain(string tileKey);

	//오브젝트
	//오브젝트 등록 1 :단일 오브젝트 추가
	tagTile_obj* addObject(string objKey, string imgKey, POINT index, POINT volume, POINT offset, OBJECT objIndex);
	//오브젝트 등록 2 : startIndex부터 endIndex까지의 오브젝트들을 한번에 추가 단, volume이 1이어야함
	tagTile_obj* addObject(string objKey, string imgKey, POINT startIndex, POINT endIndex, OBJECT objIndex);
	//오브젝트 등록 3 : 움직이는 오브젝트 등록
	tagTile_obj* addFrameObject(string objKey, string imgKey, POINT* FrameArr, int arrSize, POINT volume, POINT offset, OBJECT objIndex);

	tagTile_obj* findObj(string objKey);

	//데코
	tagTile_deco* addDecoration(string decKey, string imgKey, DECORATION decoIndex, BOOL isFrame, POINT index, POINT offset, int weight);

	tagTile_deco* addDecoration(string decKey, string imagKey, DECORATION decoIndex, BOOL isFrame, POINT* indexArr, int arrSize, POINT offset, int weight , int pos);

	tagTile_deco* addDecoration(string decKey, string imageKey, DECORATION decoIndex, vector<POINT*> vectorFrameArr, int arrSize, POINT offset, int* weight, int weightArrSize);

	tagTile_deco* addDecoration(string decKey, string imgKey, POINT startIndex, POINT endIndex, BOOL isFrame,DECORATION decoIndex, int weight , int pos);
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