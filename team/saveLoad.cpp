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
	//로드했더니 없으면 네임인풋씬으로 이동
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
	//생각해보니 이건 네임인풋에서 돌야야겠다
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