#include "stdafx.h"
#include "saveLoad.h"


saveLoad::saveLoad()
{
}


saveLoad::~saveLoad()
{
}

HRESULT saveLoad::init()
{
	IMAGEMANAGER->addImage("세이브파일", "image/UI/saveLoad.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	_cursor = 0;
	_mode = CURSOR;
	_alpha = 255;
	_alphaOn = false;
	_count = 0;
	//check();



	for (int i = 0; i < 8; i++)
	{
		_name[i].rc = RectMakeCenter(195 + (i * 20), 186, 20, 30);
		_name[i].alphabet = (NULL);
		_name[i].locate = 0;
	}
	for (int i = 0; i < 8; i++)
	{
		_name2[i].rc = RectMakeCenter(285 + (i * 20), 186, 20, 30);
		_name2[i].alphabet = (NULL);
		_name2[i].locate = 0;
	}
	for (int i = 0; i < 8; i++)
	{
		_name3[i].rc = RectMakeCenter(375 + (i * 20), 186, 20, 30);
		_name3[i].alphabet = (NULL);
		_name3[i].locate = 0;
	}

	//NI = new nameInput;
	//setNI(NI);

	return S_OK;
}
void saveLoad::release()
{
}
void saveLoad::update()	
{
	if (_alpha>0&&_alphaOn==false) _alpha -= 5;
	else if (_alphaOn) _alpha += 5;
	//알파작동중에는 작동하지 않도록
	if (_alpha == 0)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT) || KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			if (_mode == COPY || _mode == DEL)
			{
				if (_cursor == 0) _cursor = 2;
				else _cursor--;
			}
			else
			{
				if (_cursor == 0) _cursor = 4;
				else _cursor--;
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) || KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			if (_mode == COPY || _mode == DEL)
			{
				if (_cursor == 2) _cursor = 0;
				else _cursor++;
			}
			else
			{
				if (_cursor == 4) _cursor = 0;
				else _cursor++;
			}
		}


		switch (_mode)
		{
		case CURSOR:
		{
			switch (_cursor)
			{
			case 0:
				_P = PointMake(100, 190);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					load1();
				}
				break;
			case 1:
				_P = PointMake(100, 284);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					load2();
				}
				break;
			case 2:
				_P = PointMake(100, 374);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					load3();
				}
				break;
			case 3:
				_P = PointMake(143, 438);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					_cursor = 0;
					_mode = COPY;
				}
				break;
			case 4:
				_P = PointMake(399, 438);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					_cursor = 0;
					_mode = DEL;
				}
				break;
			}
		}
		break;

		case COPY:
		{
			switch (_cursor)
			{
			case 0:
				_P = PointMake(100, 190);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					//A를 B복사
					_cursor = 0;
					_mode = CURSOR;

				}
				break;
			case 1:
				_P = PointMake(100, 284);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					//A를 B복사
					_cursor = 0;
					_mode = CURSOR;
				}
				break;
			case 2:
				_P = PointMake(100, 374);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					//A를 B복사
					_cursor = 0;
					_mode = CURSOR;
				}
				break;
			}
		}
			break;

		case DEL:
		{
			switch (_cursor)
			{
			case 0:
				_P = PointMake(100, 190);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					remove("save1.txt");
					_cursor = 0;
					_mode = CURSOR;
				}
				break;
			case 1:
				_P = PointMake(100, 284);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					remove("save2.txt");
					_cursor = 0;
					_mode = CURSOR;
				}
				break;
			case 2:
				_P = PointMake(100, 374);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					remove("save3.txt");
					_cursor = 0;
					_mode = CURSOR;
				}
				break;
			}
		}
		break;

		}
		_fairy = RectMakeCenter(_P.x, _P.y, 48, 48);
	}
	tect = RectMakeCenter(_ptMouse.x, _ptMouse.y, 20, 30);



	if (strstr(_save1, ","))
	{
		alphabetRend();
	}
	_count++;
	if (_count % 5 == 0)
	{
		if (IMAGEMANAGER->findImage("커서요정")->getFrameX() == 1)IMAGEMANAGER->findImage("커서요정")->setFrameX(0);
		else IMAGEMANAGER->findImage("커서요정")->setFrameX(IMAGEMANAGER->findImage("커서요정")->getFrameX() + 1);
	}

}
void saveLoad::render()	
{
	IMAGEMANAGER->findImage("세이브파일")->render(getMemDC());

	//char str[128];
	//sprintf(str, "%d, %d", _P.x, _P.y);
	//TextOut(getMemDC(), 10, 10, str, strlen(str));

	//Rectangle(getMemDC(), _fairy.left, _fairy.top, _fairy.right, _fairy.bottom);
	IMAGEMANAGER->findImage("커서요정")->frameRender(getMemDC(), _fairy.left, _fairy.top);

	char str[128];
	//sprintf(str, "%s", _save1);
	//TextOut(getMemDC(), 10, 10, str, strlen(str));

	Rectangle(getMemDC(), tect.left, tect.top, tect.right, tect.bottom);

	IMAGEMANAGER->findImage("암전용")->alphaRender(getMemDC(), _alpha);
}

void saveLoad::check()
{
	HANDLE file;
	DWORD read;

	char str[128];


	file = CreateFile("save1.txt", GENERIC_READ, FALSE, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (ReadFile(file, str, strlen(str), &read, NULL) == false)
	{

	}
	else
	{
	}

	file = CreateFile("save2.txt", GENERIC_READ, FALSE, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (ReadFile(file, str, strlen(str), &read, NULL) == false)
	{

	}
	else
	{

	}

	file = CreateFile("save3.txt", GENERIC_READ, FALSE, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (ReadFile(file, str, strlen(str), &read, NULL) == false)
	{

	}
	else
	{

	}

	CloseHandle(file);
}
void saveLoad::load1()
{
	//로드했더니 없으면 네임인풋씬으로 이동
	HANDLE file;
	DWORD read;

	char str[128];

	file = CreateFile("save1.txt", GENERIC_READ, FALSE, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, strlen(str), &read, NULL);

	if (strstr(str,",")==false)
	{
		SCENEMANAGER->changeScene("입력창",0);
	}
	else
	{
		//SCENEMANAGER->changeScene("인게임");
	}

	CloseHandle(file);
}

void saveLoad::load2()
{
	//로드했더니 없으면 네임인풋씬으로 이동
	HANDLE file;
	DWORD read;

	char str[128];

	file = CreateFile("save2.txt", GENERIC_READ, FALSE, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (ReadFile(file, str, strlen(str), &read, NULL) == false)
	{
		SCENEMANAGER->changeScene("입력창",1);
	}
	else
	{
		//SCENEMANAGER->changeScene("인게임");
	}
	CloseHandle(file);
}

void saveLoad::load3()
{
	//로드했더니 없으면 네임인풋씬으로 이동
	HANDLE file;
	DWORD read;

	char str[128];

	file = CreateFile("save3.txt", GENERIC_READ, FALSE, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (ReadFile(file, str, strlen(str), &read, NULL) == false)
	{
		SCENEMANAGER->changeScene("입력창",2);
	}
	else
	{
		//SCENEMANAGER->changeScene("인게임");
	}
	CloseHandle(file);
}

void saveLoad::copy(int source,int target)
{

}

void saveLoad::alphabet1()
{
	char copy[64];
	char *temp;
	int i = 1;

	//보여줄 칸을 임의의 char로 이동(copy에 _write를 담음)
	//토큰화시 손상됨
	//strcpy(copy, SAVE);

	//처음걸 잘라서 0번 네임에 넣어줌
	temp = strtok(copy, ",");
	_name[0].alphabet = atoi(temp);

	//남은 것들을 0다음인 1부터 넣어주고
	while (temp = strtok(NULL, ","))
	{
		_name[i].alphabet = atoi(temp);
		//넣고 나면 i수를 증가시킴
		i++;
	}
	//이름칸에 어떤 알파벳일지 int형으로 옮김

	

}
void saveLoad::alphabet2()
{
	char copy[64];
	char *temp;
	int i = 1;

	strcpy(copy, _save2);
	temp = strtok(copy, ",");
	_name2[0].alphabet = atoi(temp);
	while (temp = strtok(NULL, ","))
	{
		_name2[i].alphabet = atoi(temp);
		i++;
	}
}

void saveLoad::alphabet3()
{
	char copy[64];
	char *temp;
	int i = 1;

	strcpy(copy, _save3);
	temp = strtok(copy, ",");
	_name3[0].alphabet = atoi(temp);
	while (temp = strtok(NULL, ","))
	{
		_name3[i].alphabet = atoi(temp);
		i++;
	}
}
void saveLoad::alphabetRend()
{
	//자른 인트를 사용해서 알파벳 x위치 이동
	for (int i = 0; i < 8; ++i)
	{
		//대문자1
		if (_name[i].alphabet >= 0 && _name[i].alphabet <= 26)
		{
			_name[i].locate = _name[i].alphabet * 17;
		}
		//소문자1
		else
		{
			_name[i].locate = (_name[i].alphabet - 27) * 14;
		}

		//대문자2
		if (_name2[i].alphabet >= 0 && _name2[i].alphabet <= 26)
		{
			_name2[i].locate = _name2[i].alphabet * 17;
		}
		//소문자2
		else
		{
			_name2[i].locate = (_name2[i].alphabet - 27) * 14;
		}

		//대문자3
		if (_name3[i].alphabet >= 0 && _name3[i].alphabet <= 26)
		{
			_name3[i].locate = _name3[i].alphabet * 17;
		}

		//소문자3
		else
		{
			_name3[i].locate = (_name3[i].alphabet - 27) * 14;
		}
	}
}