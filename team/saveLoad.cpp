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

	return S_OK;
}
void saveLoad::release()
{
}
void saveLoad::update()	
{
}
void saveLoad::render()	
{
}

void saveLoad::check()
{

}
void saveLoad::load()
{
	//�ε��ߴ��� ������ ������ǲ������ �̵�
	HANDLE file;
	DWORD read;

	char str[128];

	file = CreateFile("save1.txt", GENERIC_READ, FALSE, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, strlen(str), &read, NULL);

	CloseHandle(file);
}
void saveLoad::save()
{
	//�����غ��� �̰� ������ǲ���� ���߾߰ڴ�
	HANDLE file;
	DWORD write;

	char str[128] = "";

	file = CreateFile("save1.txt", GENERIC_WRITE, FALSE, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, strlen(str), &write, NULL);

	CloseHandle(file);
}
void saveLoad::copy(int source,int target)
{

}
void saveLoad::del(int target)
{

}