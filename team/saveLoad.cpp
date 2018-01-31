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
	IMAGEMANAGER->addImage("���̺�����", "image/UI/saveLoad.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
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
	//�����۵��߿��� �۵����� �ʵ���
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
					//A�� B����
					copy(_source,_cursor);
					_mode = PASTE;
					_cursor = 0;
					_source = 0;
					_mode = CURSOR;
					SCENEMANAGER->changeScene("�Է�â", 0);
					SCENEMANAGER->changeScene("����");
				}
				break;
			case 1:
				_P = PointMake(100, 284);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					//A�� B����
					copy(_source, _cursor);
					_cursor = 0;
					_source = 0;
					_mode = CURSOR;
					SCENEMANAGER->changeScene("�Է�â", 0);
					SCENEMANAGER->changeScene("����");
				}
				break;
			case 2:
				_P = PointMake(100, 374);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					//A�� B����
					copy(_source, _cursor);
					_cursor = 0;
					_source = 0;
					_mode = CURSOR;
					SCENEMANAGER->changeScene("�Է�â", 0);
					SCENEMANAGER->changeScene("����");
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
					SCENEMANAGER->changeScene("����");
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
					SCENEMANAGER->changeScene("����");
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
					SCENEMANAGER->changeScene("����");
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
		if (IMAGEMANAGER->findImage("Ŀ������")->getFrameX() == 1)IMAGEMANAGER->findImage("Ŀ������")->setFrameX(0);
		else IMAGEMANAGER->findImage("Ŀ������")->setFrameX(IMAGEMANAGER->findImage("Ŀ������")->getFrameX() + 1);
	}

}
void saveLoad::render()	
{
	IMAGEMANAGER->findImage("���̺�����")->render(getMemDC());

	//char str[128];
	//sprintf(str, "%d, %d", _P.x, _P.y);
	//TextOut(getMemDC(), 10, 10, str, strlen(str));

	for (int i = 0; i < 8; i++)
	{
		//1�빮��
		if (_name[i].alphabet >= 0 && _name[i].alphabet <= 26)
		{
			IMAGEMANAGER->findImage("�빮��")->render(getMemDC(), _name[i].rc.left, _name[i].rc.top,
				_name[i].locate, 0, 17, 30);
		}
		//1�ҹ���
		else if (_name[i].alphabet >= 27 && _name[i].alphabet <= 52)
		{
			IMAGEMANAGER->findImage("�ҹ���")->render(getMemDC(), _name[i].rc.left, _name[i].rc.top,
				_name[i].locate, 0, 14, 30);
		}
		//2�빮��
		if (_name2[i].alphabet >= 0 && _name2[i].alphabet <= 26)
		{
			IMAGEMANAGER->findImage("�빮��")->render(getMemDC(), _name2[i].rc.left, _name2[i].rc.top,
				_name2[i].locate, 0, 17, 30);
		}
		//2�ҹ���
		else if (_name2[i].alphabet >= 27 && _name2[i].alphabet <= 52)
		{
			IMAGEMANAGER->findImage("�ҹ���")->render(getMemDC(), _name2[i].rc.left, _name2[i].rc.top,
				_name2[i].locate, 0, 14, 30);
		}
		//3�빮��
		if (_name3[i].alphabet >= 0 && _name3[i].alphabet <= 26)
		{
			IMAGEMANAGER->findImage("�빮��")->render(getMemDC(), _name3[i].rc.left, _name3[i].rc.top,
				_name3[i].locate, 0, 17, 30);
		}
		//3�ҹ���
		else if (_name3[i].alphabet >= 27 && _name3[i].alphabet <= 52)
		{
			IMAGEMANAGER->findImage("�ҹ���")->render(getMemDC(), _name3[i].rc.left, _name3[i].rc.top,
				_name3[i].locate, 0, 14, 30);
		}
	}

	//Rectangle(getMemDC(), _fairy.left, _fairy.top, _fairy.right, _fairy.bottom);
	IMAGEMANAGER->findImage("Ŀ������")->frameRender(getMemDC(), _fairy.left, _fairy.top);
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

	IMAGEMANAGER->findImage("������")->alphaRender(getMemDC(), _alpha);
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
	//�ε��ߴ��� ������ ������ǲ������ �̵�
	HANDLE file;
	DWORD read;

	char str[128];

	file = CreateFile("save1.txt", GENERIC_READ, FALSE, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (ReadFile(file, str, strlen(str), &read, NULL) == false)
	{
		SCENEMANAGER->changeScene("�Է�â",0);
	}
	else
	{
		//SCENEMANAGER->changeScene("�ΰ���");
	}

	CloseHandle(file);
}

void saveLoad::load2()
{
	//�ε��ߴ��� ������ ������ǲ������ �̵�
	HANDLE file;
	DWORD read;

	char str[128];

	file = CreateFile("save2.txt", GENERIC_READ, FALSE, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (ReadFile(file, str, strlen(str), &read, NULL) == false)
	{
		SCENEMANAGER->changeScene("�Է�â",1);
	}
	else
	{
		//SCENEMANAGER->changeScene("�ΰ���");
	}
	CloseHandle(file);
}

void saveLoad::load3()
{
	//�ε��ߴ��� ������ ������ǲ������ �̵�
	HANDLE file;
	DWORD read;

	char str[128];

	file = CreateFile("save3.txt", GENERIC_READ, FALSE, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (ReadFile(file, str, strlen(str), &read, NULL) == false)
	{
		SCENEMANAGER->changeScene("�Է�â",2);
	}
	else
	{
		//SCENEMANAGER->changeScene("�ΰ���");
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

	//������ ĭ�� ������ char�� �̵�(copy�� _write�� ����)��
	//��ūȭ�� �ջ��
	//strcpy(copy, "��");

	//ó���� �߶� 0�� ���ӿ� �־���
	//temp = strtok(copy, "��");
	//_name[0].alphabet = atoi(temp);
	//strcat(_save1, temp);
	//���� �͵��� 0������ 1���� �־��ְ�
	//while (temp = strtok(NULL, "��"))
	//{
		//_name[i].alphabet = atoi(temp);
	//	strcat(_save1, temp);
		//�ְ� ���� i���� ������Ŵ
	//	i++;
	//}
	//�̸�ĭ�� � ���ĺ����� int������ �ű�

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
	//�ڸ� ��Ʈ�� ����ؼ� ���ĺ� x��ġ �̵�
	for (int i = 0; i < 8; ++i)
	{
		//�빮��1
		if (_name[i].alphabet >= 0 && _name[i].alphabet <= 26)
		{
			_name[i].locate = _name[i].alphabet * 17;
		}
		//�ҹ���1
		else
		{
			_name[i].locate = (_name[i].alphabet - 27) * 14;
		}

		//�빮��2
		if (_name2[i].alphabet >= 0 && _name2[i].alphabet <= 26)
		{
			_name2[i].locate = _name2[i].alphabet * 17;
		}
		//�ҹ���2
		else
		{
			_name2[i].locate = (_name2[i].alphabet - 27) * 14;
		}

		//�빮��3
		if (_name3[i].alphabet >= 0 && _name3[i].alphabet <= 26)
		{
			_name3[i].locate = _name3[i].alphabet * 17;
		}

		//�ҹ���3
		else
		{
			_name3[i].locate = (_name3[i].alphabet - 27) * 14;
		}
	}
}