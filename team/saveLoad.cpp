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
	for (int i = 0; i < 8; i++)
	{
		_name[i].rc = RectMakeCenter(186 + (i * 20), 195, 20, 30);
		_name[i].alphabet = 0;
		_name[i].locate = 0;
	}

	for (int i = 0; i < 8; i++)
	{
		_name2[i].rc = RectMakeCenter(186 + (i * 20), 285, 20, 30);
		_name2[i].alphabet = 0;
		_name2[i].locate = 0;
	}

	for (int i = 0; i < 8; i++)
	{
		_name3[i].rc = RectMakeCenter(186 + (i * 20), 375, 20, 30);
		_name3[i].alphabet = 0;
		_name3[i].locate = 0;
	}
	//NI = new nameInput;
	//setNI(NI);

	check();
	if (_file)alphabet1();
	if (_file2)alphabet2();
	if (_file3)alphabet3();


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
					if (!_file)
					{
						_cursor = 0;
						_source = 0;
						_mode = CURSOR;
					}
					else{
						_source = 0;
						_cursor = 0;
						_mode = PASTE;
					}
				}
				break;
			case 1:
				_P = PointMake(100, 284);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					if (!_file2)
					{
						_cursor = 0;
						_source = 0;
						_mode = CURSOR;
					}
					else{
						_source = 1;
						_cursor = 0;
						_mode = PASTE;
					}
				}
				break;
			case 2:
				_P = PointMake(100, 374);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					if (!_file3)
					{
						_cursor = 0;
						_source = 0;
						_mode = CURSOR;
					}
					else{
						_source = 2;
						_cursor = 0;
						_mode = PASTE;
					}
				}
				break;
			}
		}
			break;

		case PASTE:
		{
			switch (_cursor)
			{
			case 0:
				_P = PointMake(100, 190);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					//A를 B복사
					copy(_source,_cursor);
					_mode = PASTE;
					_cursor = 0;
					_source = 0;
					_mode = CURSOR;
					SCENEMANAGER->changeScene("입력창", 0);
					SCENEMANAGER->changeScene("파일");
				}
				break;
			case 1:
				_P = PointMake(100, 284);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					//A를 B복사
					copy(_source, _cursor);
					_cursor = 0;
					_source = 0;
					_mode = CURSOR;
					SCENEMANAGER->changeScene("입력창", 0);
					SCENEMANAGER->changeScene("파일");
				}
				break;
			case 2:
				_P = PointMake(100, 374);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					//A를 B복사
					copy(_source, _cursor);
					_cursor = 0;
					_source = 0;
					_mode = CURSOR;
					SCENEMANAGER->changeScene("입력창", 0);
					SCENEMANAGER->changeScene("파일");
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
					_file = false;
					for (int i = 0; i < 8; i++)
					{
						_name[i].rc = RectMakeCenter(186 + (i * 20), 195, 20, 30);
						_name[i].alphabet = 0;
						_name[i].locate = 0;
					}
					remove("save1.txt");
					_mode = CURSOR;
					SCENEMANAGER->changeScene("파일");
				}
				break;
			case 1:
				_P = PointMake(100, 284);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					_file2 = false;
					for (int i = 0; i < 8; i++)
					{
						_name2[i].rc = RectMakeCenter(186 + (i * 20), 285, 20, 30);
						_name2[i].alphabet = 0;
						_name2[i].locate = 0;
					}
					remove("save2.txt");
					_mode = CURSOR;
					SCENEMANAGER->changeScene("파일");
				}
				break;
			case 2:
				_P = PointMake(100, 374);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					_file3 = false;
					for (int i = 0; i < 8; i++)
					{
						_name3[i].rc = RectMakeCenter(186 + (i * 20), 375, 20, 30);
						_name3[i].alphabet = 0;
						_name3[i].locate = 0;
					}
					remove("save3.txt");
					_mode = CURSOR;
					SCENEMANAGER->changeScene("파일");
				}
				break;
			}
		}
		break;

		}
		_fairy = RectMakeCenter(_P.x, _P.y, 48, 48);
	}
	tect = RectMakeCenter(_ptMouse.x, _ptMouse.y, 20, 30);

	

	alphabetRend();

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

	for (int i = 0; i < 8; i++)
	{
		//1대문자
		if (_name[i].alphabet >= 0 && _name[i].alphabet <= 26)
		{
			IMAGEMANAGER->findImage("대문자")->render(getMemDC(), _name[i].rc.left, _name[i].rc.top,
				_name[i].locate, 0, 17, 30);
		}
		//1소문자
		else if (_name[i].alphabet >= 27 && _name[i].alphabet <= 52)
		{
			IMAGEMANAGER->findImage("소문자")->render(getMemDC(), _name[i].rc.left, _name[i].rc.top,
				_name[i].locate, 0, 14, 30);
		}
		//2대문자
		if (_name2[i].alphabet >= 0 && _name2[i].alphabet <= 26)
		{
			IMAGEMANAGER->findImage("대문자")->render(getMemDC(), _name2[i].rc.left, _name2[i].rc.top,
				_name2[i].locate, 0, 17, 30);
		}
		//2소문자
		else if (_name2[i].alphabet >= 27 && _name2[i].alphabet <= 52)
		{
			IMAGEMANAGER->findImage("소문자")->render(getMemDC(), _name2[i].rc.left, _name2[i].rc.top,
				_name2[i].locate, 0, 14, 30);
		}
		//3대문자
		if (_name3[i].alphabet >= 0 && _name3[i].alphabet <= 26)
		{
			IMAGEMANAGER->findImage("대문자")->render(getMemDC(), _name3[i].rc.left, _name3[i].rc.top,
				_name3[i].locate, 0, 17, 30);
		}
		//3소문자
		else if (_name3[i].alphabet >= 27 && _name3[i].alphabet <= 52)
		{
			IMAGEMANAGER->findImage("소문자")->render(getMemDC(), _name3[i].rc.left, _name3[i].rc.top,
				_name3[i].locate, 0, 14, 30);
		}
	}

	//Rectangle(getMemDC(), _fairy.left, _fairy.top, _fairy.right, _fairy.bottom);
	IMAGEMANAGER->findImage("커서요정")->frameRender(getMemDC(), _fairy.left, _fairy.top);
	for(int i=0;i<8;++i)
	{
		char str[128];
		sprintf(str, "%d", _name[i].alphabet);
		TextOut(getMemDC(), 10, 10+(i*20), str, strlen(str));
	}
	for (int i = 0; i<8; ++i)
	{
		char str[128];
		sprintf(str, "%d", _name2[i].alphabet);
		TextOut(getMemDC(), 30, 10 + (i * 20), str, strlen(str));
	}
	for (int i = 0; i<8; ++i)
	{
		char str[128];
		sprintf(str, "%d", _name3[i].alphabet);
		TextOut(getMemDC(), 50, 10 + (i * 20), str, strlen(str));
	}
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
		_file = false;
	}
	else
	{
		_file = true;
	}
	CloseHandle(file);

	file = CreateFile("save2.txt", GENERIC_READ, FALSE, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (ReadFile(file, str, strlen(str), &read, NULL) == false)
	{
		_file2 = false;
	}
	else
	{
		_file2 = true;
	}
	CloseHandle(file);

	file = CreateFile("save3.txt", GENERIC_READ, FALSE, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (ReadFile(file, str, strlen(str), &read, NULL) == false)
	{
		_file3 = false;
	}
	else
	{
		_file3 = true;
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

	if (ReadFile(file, str, strlen(str), &read, NULL) == false)
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
	HANDLE file;
	DWORD write;
	vector<string> VS;
	char copy[64];
	vector<string> VC;

	switch (source)
	{
	case 0:
		//if(_file) VS = TXTDATA->txtLoad("save1.txt");
		for (int i; i < 8; ++i)
		{
			VC.push_back(itoa(_name[i].alphabet, copy, 10));
		}
		VC.push_back("10");
		break;
	case 1:
		for (int i; i < 8; ++i)
		{
			VC.push_back(itoa(_name2[i].alphabet, copy, 10));
		}
		VC.push_back("10");
		break;
	case 2:
		for (int i; i < 8; ++i)
		{
			VC.push_back(itoa(_name3[i].alphabet, copy, 10));
		}
		VC.push_back("10");
		break;
	}

	
	

	switch (target)
	{
	case 0:
		TXTDATA->txtSave("save1.txt", VC);
		break;
	case 1:
		//file = CreateFile("save2.txt", GENERIC_WRITE, 0, NULL,
		//	CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		//WriteFile(file, _save1, strlen(_save1), &write, NULL);
		TXTDATA->txtSave("save2.txt",VC);
		break;
	case 2:
		TXTDATA->txtSave("save3.txt", VC);
		break;
	}

}

void saveLoad::alphabet1()
{
	char copy[64];
	const char *temp;
	
	vector<string> VS;
	VS = TXTDATA->txtLoad("save1.txt");
	for (int i = 0; i < 8; i++)
	{
		_name[i].alphabet = atoi(VS[i].c_str());
	}

	//	strcpy(_save1, str);

	//보여줄 칸을 임의의 char로 이동(copy에 _write를 담음)儆
	//토큰화시 손상됨
	//strcpy(copy, "儆");

	//처음걸 잘라서 0번 네임에 넣어줌
	//temp = strtok(copy, "儆");
	//_name[0].alphabet = atoi(temp);
	//strcat(_save1, temp);
	//남은 것들을 0다음인 1부터 넣어주고
	//while (temp = strtok(NULL, "儆"))
	//{
		//_name[i].alphabet = atoi(temp);
	//	strcat(_save1, temp);
		//넣고 나면 i수를 증가시킴
	//	i++;
	//}
	//이름칸에 어떤 알파벳일지 int형으로 옮김

}
void saveLoad::alphabet2()
{
	vector<string> VS;
	VS = TXTDATA->txtLoad("save2.txt");
	for (int i = 0; i < 8; i++)
	{
		_name2[i].alphabet = atoi(VS[i].c_str());
	}
}

void saveLoad::alphabet3()
{
	vector<string> VS;
	VS = TXTDATA->txtLoad("save3.txt");
	for (int i = 0; i < 8; i++)
	{
		_name3[i].alphabet = atoi(VS[i].c_str());
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