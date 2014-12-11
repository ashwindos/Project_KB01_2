// GameEngine.cpp : Defines the entry point for the console application.

#include "Logger.h"
#include "Kernel.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdline, int iCmdShow)    
{

	
	 Logger* r = new Logger();
	 Kernel* k = new Kernel(hInstance, iCmdShow);
	 r->Log("Hello World!");
	 k->Run();

     return 0;
}