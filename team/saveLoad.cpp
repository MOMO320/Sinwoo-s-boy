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
					//A�� B����
					_cursor = 0;
					_mode = CURSOR;

				}
				break;
			case 1:
				_P = PointMake(100, 284);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					//A�� B����
					_cursor = 0;
					_mode = CURSOR;
				}
				break;
			case 2:
				_P = PointMake(100, 374);
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					//A�� B����
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

	//Rectangle(getMemDC(), _fairy.left, _fairy.top, _fairy.right, _fairy.bottom);
	IMAGEMANAGER->findImage("Ŀ������")->frameRender(getMemDC(), _fairy.left, _fairy.top);

	char str[128];
	//sprintf(str, "%s", _save1);
	//TextOut(getMemDC(), 10, 10, str, strlen(str));

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
	//�ε��ߴ��� ������ ������ǲ������ �̵�
	HANDLE file;
	DWORD read;

	char str[128];

	file = CreateFile("save1.txt", GENERIC_READ, FALSE, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, strlen(str), &read, NULL);

	if (strstr(str,",")==false)
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

}

void saveLoad::alphabet1()
{
	char copy[64];
	char *temp;
	int i = 1;

	//������ ĭ�� ������ char�� �̵�(copy�� _write�� ����)
	//��ūȭ�� �ջ��
	//strcpy(copy, SAVE);

	//ó���� �߶� 0�� ���ӿ� �־���
	temp = strtok(copy, ",");
	_name[0].alphabet = atoi(temp);

	//���� �͵��� 0������ 1���� �־��ְ�
	while (temp = strtok(NULL, ","))
	{
		_name[i].alphabet = atoi(temp);
		//�ְ� ���� i���� ������Ŵ
		i++;
	}
	//�̸�ĭ�� � ���ĺ����� int������ �ű�

	

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