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
//=============================================================
// ## 17.10.18 ## Macro ##
//=============================================================

#define SAFE_DELETE(p) {if(p) {delete(p); (p) = NULL;}}
#define SAFE_RELEASE(p) {if(p) {(p)->release(); (p)=NULL;}}


//=====================================
// ## extern ## 17.10.12 ##
//=====================================

enum PAGE
{
	PAGE_CHANGE,
	PAGE_GAME,
	PAGE_MAPTOOL,
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
};

extern HINSTANCE _hInstance;
extern HWND	_hWnd;
extern POINT _ptMouse;
extern POINT _cameraPtMouse;
extern BOOL _leftMouseButton;
extern PAGE page;
extern BOOL _pageChange;
extern BOOL popUpPage;
