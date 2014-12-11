#ifndef __RESOURCECONTROLLER_H_
#define __RESOURCEONTROLLER_H_
#include "Resource.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
class ResourceController
{
public:
	ResourceController(void);
	~ResourceController(void);
	void OpenFile();
	void CloseFile();
	void DeleteFile(Resource);
	void SearchFile();
	HGLOBAL WINAPI LoadResource( _In_opt_  HMODULE hModule, _In_ HRSRC hResInfo);

};
#endif

