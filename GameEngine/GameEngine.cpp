// GameEngine.cpp : Defines the entry point for the console application.
//
#include "Logger.h"
#include "Window.h"
#include <Windows.h>
#include "D3dtest.h"

int WINAPI WinMain( HINSTANCE hInstance,  
                    HINSTANCE hPrevInstance,
                    LPSTR szCmdLine,
                    int iCmdShow)    
{
	Window* w = new Window(hInstance, iCmdShow);
	return 0;
}