#include <Windows.h>
#include <string>
#include "D3dtest.h"
#pragma once
class Window
{
public:
	Window(HINSTANCE hInstance,  int iCmdShow);
	~Window();
	
	int init(HINSTANCE, int, D3dtest*);
	
};