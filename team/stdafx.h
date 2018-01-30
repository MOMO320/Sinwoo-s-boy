#pragma once
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             

#include <windows.h>
#include <windowsx.h>

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include <commdlg.h>
#include <io.h>
#include <functional>


#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "utils.h"
#include "collision.h"
#include "imageManager.h"
#include "timeManager.h"
#include "soundManager.h"
#include "txtData.h"
#include "effectManager.h"
#include "iniDataManager.h"
#include "sceneManager.h"
#include "keyAniManager.h"
#include "cameraManager.h"
#include "database.h"
#include "tileInfoManager.h"
#include "InGame_map.h"
#include "aStarMapInfo.h"

using namespace std;
using namespace HEXA_UTIL;

//=====================================
// ## 디파인 ## 17.09.29 ##
//=====================================

#define WINNAME		(LPTSTR)(TEXT("Hexa API"))
#define WINSTARTX	0
#define WINSTARTY	0
#define WINSIZEX	750 
#define WINSIZEY	500
#define WINSTYLE	WS_CAPTION | WS_SYSMENU

//맵툴 사이즈
#define TOOLSTARTX 30
#define TOOLSTARTY 30
#define TOOLSIZEX 1500
#define TOOLSIZEY 900




#define RND randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()
#define EFFECTMANAGER effectManager::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define KEYANIMANAGER keyAniManager::getSingleton()
#define TXTDATA txtData::getSingleton()
#define INIDATA iniDataManager::getSingleton()
#define DATABASE database::getSingleton()
#define TILEMANAGER tileInfoManager::getSingleton()
#define CAMERAMANAGER cameraManager::getSingleton()
#define IGMAP InGame_map::getSingleton()
#define ASTARINFO aStarMapInfo::getSingleton()
//=============================================================
// ## 17.10.18 ## Macro ##
//=============================================================

#define SAFE_DELETE(p) {if(p) {delete(p); (p) = NULL;}}
#define SAFE_RELEASE(p) {if(p) {(p)->release(); (p)=NULL;}}


//=====================================
// ## extern ## 17.10.12 ##
//=====================================

enum SWITCH_MAIN
{
	PAGE_CHANGE,
	PAGE_GAME,
	PAGE_MAPTOOL,
};

enum PAGE_INDEX
{
	PAGE_MAIN,
	PAGE_ADDMAP,
	PAGE_SETATTRIBUTE,
};



enum BUTTON_NUM
{
	BTN_TERRAIN,
	BTN_OBJECT,
	BTN_EVENT,
	BTN_CHARACTER,
	BTN_DECO,
	BTN_MAINPAGE,
	BTN_COMBOBOX,
	BTN_SCROLL_VERT,
	BTN_SCROLL_HORI,
	BTN_SCROLL_X,
	BTN_SCROLL_Y,
	BTN_ADD_MAP,
	WINDOW_ADD_MAP_CHILD,
	BTN_DELETE_MAP,
	BTN_ADD_MAP_OK,
	BTN_ADD_MAP_NO,
	TEXT_ADD_MAPNAME,
	TEXT_ADD_MAPX,
	TEXT_ADD_MAPY,
	COMBOBOX_MAP_KIND,
	BTN_ERASER,
	BTN_SAVE,
	BTN_SAVE_ALL,
	BTN_LOAD,
	BTN_LOAD_ALL,
	SETATTRIBUTE_COMBOBOX_PAGE_SELECT,
	SETATTRIBUTE_BTN_OK,
	SETATTRIBUTE_BTN_NO,
	SETATTRIBUTE_BTN_PATROL,
	SETATTRIBUTE_COMBOBOX_EV_INDEX,
	SETATTRIBUTE_COMBOBOX_EV_ACTINDEX,
	SETATTRIBUTE_TEXT_CHAR_FROM,
	SETATTRIBUTE_TEXT_COLOR1,
	SETATTRIBUTE_TEXT_COLOR2,
	SETATTRIBUTE_TEXT_COLOR3,
	SETATTRIBUTE_TEXT_NEXTMAP,
	SETATTRIBUTE_EV_TEXT_PARAM,
	BTN_ADD_LEFT,
	BTN_ADD_TOP,
	BTN_ADD_RIGHT,
	BTN_ADD_BOTTOM,
};

extern HINSTANCE _hInstance;
extern HWND	_hWnd;
extern POINT _ptMouse;
extern POINT _cameraPtMouse;
extern BOOL _leftMouseButton;
extern SWITCH_MAIN page;
extern BOOL _pageChange;
extern PAGE_INDEX current_PAGE;
extern int tileSizeX, tileSizeY;
//extern int vertScrollMove;
//extern int horzScrollMove;

