#include "stdafx.h"
#include "nameInput.h"


nameInput::nameInput()
{
}


nameInput::~nameInput()
{
}

HRESULT nameInput::init(int choice)
{
	IMAGEMANAGER->addImage("이름입력", "image/UI/nameInput.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	_P = PointMake(100, 100);
	_cursor = 0;
	_nameCount = 0;
	_count=0;
	_choice = choice;
	sprintf(checking, "%d", _choice);
	for(int i=0;i<64;i++) _write[i] = NULL;

	//대문자
	int startX=56, startY=331;
	for (int i = 0; i < 26; ++i)
	{
		if (i>=20)_locate[i] = PointMake(startX + ((i-20) * 30), startY+74);
		else if (i >= 10) _locate[i] = PointMake(startX + ((i-10) * 30), startY+37);
		else _locate[i] = PointMake(startX + (i * 30), startY);
	}

	//소문자
	startX = 367, startY = 331;
	for (int i = 26; i < 52; ++i)
	{
		if (i>45)_locate[i] = PointMake(startX + ((i - 46) * 30), startY + 74);
		else if (i > 35) _locate[i] = PointMake(startX + ((i - 36) * 30), startY + 37);
		else _locate[i] = PointMake(startX + ((i-26) * 30), startY);
	}

	//지움
	_locate[52] = PointMake(491, 283);
	//완료
	_locate[53] = PointMake(601, 283);

	for (int i = 0; i < 8; i++)
	{
		_name[i].rc = RectMakeCenter(136 + (i * 20), 221, 20, 30);
		_name[i].alphabet = (NULL);
		_name[i].locate = 0;
	}

	//SL = new saveLoad;
	//setSL(SL);

	
	return S_OK;
}

void nameInput::release()
{
	
}

void nameInput::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (_cursor >= 30 && _cursor <= 32)
		{
			_cursor = 52;
		}
		else if (_cursor >= 33 && _cursor <= 35)
		{
			_cursor = 53;
		}
		else if ((_cursor >= 0 && _cursor <= 5) || (_cursor >= 26 && _cursor <= 29))
		{
			_cursor += 20;
		}
		else if ((_cursor >= 6 && _cursor <= 9))
		{
			_cursor += 10;
		}
		else if (_cursor == 52)
		{
			_cursor = 50;
		}
		else if (_cursor == 53)
		{
			_cursor = 44;
		}
		else
		{
			_cursor -= 10;
		}

	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if ((_cursor >= 20 && _cursor <= 25) || (_cursor >= 46 && _cursor <= 51))
		{
			_cursor -= 20;
		}
		else if ((_cursor >= 16 && _cursor <= 19) || (_cursor >= 42 && _cursor <= 45))
		{
			_cursor -= 10;
		}
		else if (_cursor == 52)
		{
			_cursor = 30;
		}
		else if (_cursor == 53)
		{
			_cursor = 34;
		}
		else
		{
			_cursor += 10;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		if (_cursor == 0|| _cursor == 10|| _cursor == 20)
		{
			if (_cursor == 20) _cursor += 31;
			else _cursor += 35;
		}
		else if (_cursor == 26 || _cursor == 36 || _cursor == 46)
		{
			if (_cursor == 46) _cursor -= 21;
			else _cursor -= 17;
		}
		else if (_cursor == 52)
		{
			_cursor++;
		}
		else
		{
			_cursor--;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		if (_cursor == 9 || _cursor == 19 || _cursor == 25)
		{
			if (_cursor == 25) _cursor += 21;
			else _cursor += 17;
		}
		else if (_cursor == 35 || _cursor == 45 || _cursor == 51)
		{
			if (_cursor == 51) _cursor -= 31;
			else _cursor -= 35;
		}
		else if (_cursor == 53)
		{
			_cursor--;
		}
		else
		{
			_cursor++;
		}
	}
	_P = _locate[_cursor];
	_fairy = RectMakeCenter(_P.x, _P.y, 48, 48);

	//WF = *WFP;

	//이후 확인키 조정바람
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		if (_cursor == 53)
		{
			if (strstr(_write, ",") == false)
			{//얘는 왜 안되는 걸까
				//Link가 입력되어야 한다.
				sprintf(_write, "12,35,40,37,0,0,0,0,10");
				//그리고 세이브작동
				switch (_choice)
				{
				case 0:
					save1();
					break;
				case 1:
					save2();
					break;
				case 2:
					save3();
					break;
				}
				SCENEMANAGER->changeScene("파일");
			}
			else
			{
				//남은칸을 0으로 채우고 현재 입력된 _write가 입력되어야 한다
				for (int i = _nameCount; i < 8; i++)
				{
					sprintf(cat, "0,");
					strcat(_write, cat);
					_nameCount++;
				}
				//마지막에 체력10을 입력
				sprintf(cat, "10");
				strcat(_write, cat);
				//그리고 세이브작동
				save1();
				SCENEMANAGER->changeScene("파일");
			}
		}
		//지움
		else if(_cursor == 52)
		{
			//아무것도 없으면
			if (strstr(_write, ",") == false)
			{
				//아무것도 하지말것
			}
			else
			{
				//가장 마지막 글자를 지울 것
				erase();
			}
		}
		else if(_nameCount>=8) _cursor = 53;
		else if (_cursor >= 0 && _cursor < 52)
		{
			sprintf(cat, "%d,", _cursor+1);
			strcat(_write, cat);
			_nameCount++;
		}
	}
	//취소키로 조정바람
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_cursor=52;
	}

	
	if (strstr(_write, ","))
	{
		alphabet();
		alphabetRend();
	}
	_count++;
	if (_count % 5 == 0)
	{
		if (IMAGEMANAGER->findImage("커서요정")->getFrameX() == 1)IMAGEMANAGER->findImage("커서요정")->setFrameX(0);
		else IMAGEMANAGER->findImage("커서요정")->setFrameX(IMAGEMANAGER->findImage("커서요정")->getFrameX() + 1);
	}
}

void nameInput::render()
{
	IMAGEMANAGER->findImage("이름입력")->render(getMemDC());
	IMAGEMANAGER->findImage("커서요정")->frameRender(getMemDC(), _fairy.left, _fairy.top);
	
	Rectangle(getMemDC(), RectMakeCenter(_ptMouse.x, _ptMouse.y, 16, 30).left, RectMakeCenter(_ptMouse.x, _ptMouse.y, 16, 30).top
		,RectMakeCenter(_ptMouse.x, _ptMouse.y, 16, 30).right, RectMakeCenter(_ptMouse.x, _ptMouse.y, 16, 30).bottom);

	for (int i = 0; i < 8; i++)
	{
			//대문자
			if (_name[i].alphabet >= 0 && _name[i].alphabet <= 26)
			{
				IMAGEMANAGER->findImage("대문자")->render(getMemDC(), _name[i].rc.left, _name[i].rc.top,
					_name[i].locate, 0, 17, 30);
			}
			//소문자
			else if(_name[i].alphabet >= 27 && _name[i].alphabet <= 52)
			{
				IMAGEMANAGER->findImage("소문자")->render(getMemDC(), _name[i].rc.left, _name[i].rc.top,
					_name[i].locate, 0, 14, 30);
			}
	}
	char str[128];
	//sprintf(str, "%s", checking);
	TextOut(getMemDC(), 10, 10, checking, strlen(checking));
}

void nameInput::save1()
{
	//생각해보니 이건 네임인풋에서 돌야야겠다
	HANDLE file;
	DWORD write;

	char str[128];

	strcpy(str, _write);

	file = CreateFile("save1.txt", GENERIC_WRITE, FALSE, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, strlen(str), &write, NULL);

	CloseHandle(file);
}
void nameInput::save2()
{
	//생각해보니 이건 네임인풋에서 돌야야겠다
	HANDLE file;
	DWORD write;

	char str[128];

	strcpy(str, _write);

	file = CreateFile("save2.txt", GENERIC_WRITE, FALSE, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, strlen(str), &write, NULL);

	CloseHandle(file);
}
void nameInput::save3()
{
	//생각해보니 이건 네임인풋에서 돌야야겠다
	HANDLE file;
	DWORD write;

	char str[128];

	strcpy(str, _write);

	file = CreateFile("save3.txt", GENERIC_WRITE, FALSE, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, strlen(str), &write, NULL);

	CloseHandle(file);
}
void nameInput::erase()
{//하나씩 지우는 건 나중에
	//char copy[64];
	//char *temp;
	//_nameCount = 0;
	//for (int i = 0; i < 8; i++)
	//{
	//	_name[i].alphabet = 0;
	//	_name[i].locate = 0;
	//}
	//
	//strcpy(copy, _write);
	//temp = strtok(temp, copy);
	//strcpy(_write, copy);
	_write[0] = '\0';
	_nameCount = 0;
	for (int i = 0; i < 8; i++)
	{
		_name[i].alphabet = 0;
		_name[i].locate = 0;
	}
}

void nameInput::alphabet()
{
	char copy[64];
	char *temp;
	int i=1;

	//보여줄 칸을 임의의 char로 이동(copy에 _write를 담음)
	//토큰화시 손상됨
	strcpy(copy, _write);

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
void nameInput::alphabetRend()
{
	//자른 인트를 사용해서 알파벳 x위치 이동
	for (int i = 0; i < 8; ++i)
	{
		//대문자
		if (_name[i].alphabet >= 0 && _name[i].alphabet <= 26)
		{
			_name[i].locate = _name[i].alphabet * 17;
		}
		//소문자
		else
		{
			_name[i].locate = (_name[i].alphabet-27) * 14;
		}
	}
}