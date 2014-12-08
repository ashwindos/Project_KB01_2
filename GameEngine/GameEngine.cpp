// GameEngine.cpp : Defines the entry point for the console application.

#include "Logger.h"
#include "Kernel.h" 
#include <iostream>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdline, int iCmdShow)    
{
	 Logger* r = new Logger();
	 Kernel* k = new Kernel();
	 r->Log("Hello World!");
	 k->Run(hInstance, iCmdShow);
     return 0;
}