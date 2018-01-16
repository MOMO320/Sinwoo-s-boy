#pragma once
#include "singletonBase.h"
#include "image.h"
#include "tileNode.h"
#include <map>


struct tagTILE_TR
{
	TERRAIN TR_INDEX;
	image* _image;
	bool isFrame;
};

struct tagTILE_OBJ
{
	OBJECT OBJ_INDEX;
	image* _image;
	POINT VOLUME;
	bool isFrame;

};

typedef map<string, tagTILE_TR*> mapTRList;
typedef map<string, tagTILE_OBJ*> mapOBJList;

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

	
	tagTILE_TR* addTerrain(string strKey,TERRAIN TRindex, const char* fileName, int width, int height, bool trans, COLORREF transColor);


	tagTILE_TR* addTerrain(string strKey, TERRAIN TRindex, const char* fileName, int sourX, int sourY, int width, int height, bool trans, COLORREF transColor);

	//특정 영역을 모두 등록 맵의 키는 strKey에서 strcat을 이용해 0~숫자를 붙인다.
	tagTILE_TR* addTerrain(string strKey, TERRAIN TRindex, const char* fileName, int sourX, int sourY, int width, int height, int destX, int destY, bool trans, COLORREF transColor);

	tagTILE_TR* addFrameTerrain(string strKey, TERRAIN TRindex, const char* fileName, int sourX, int sourY, int widht, int height, bool trans, COLORREF transColor);

	tagTILE_OBJ* addObject(string strKey, OBJECT OBJindex, const char* fileName, int width, int height, int volumeX, int volumeY, bool trans, COLORREF transColor);

	tagTILE_OBJ* addFrameObject(string strKey, OBJECT OBJindex, const char* fileName, int width, int height, int frameX, int frameY, int volumeX, int volumeY, bool trans, COLORREF transColor);

	tagTILE_TR* findTerrain(string strKey);

	tagTILE_OBJ* findObject(string strKey);

	BOOL deleteTerrain(string strKey);

	BOOL deleteObject(string strKey);

	BOOL deleteAll(void);





};

