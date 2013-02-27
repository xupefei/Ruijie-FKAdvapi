#include "stdafx.h"
#include "FKAdvapi.h"

typedef DWORD (CALLBACK *FUNC)(char*);

FKADVAPI_API DWORD SuFindProcess(char* procToFind)
{
	
	HINSTANCE hModule = LoadLibrary(L"SuAdvapi.dll");
	FUNC addr=(FUNC)GetProcAddress(hModule,"SuFindProcess");

	return (*addr)(procToFind);
}
