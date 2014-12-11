// GameEngine.cpp : Defines the entry point for the console application.

#include "Logger.h"
#include "Kernel.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdline, int iCmdShow)    
{
<<<<<<< HEAD
	
	 Logger* r = new Logger();
	 Kernel* k = new Kernel();
	 r->Log("Hello World!");
	 k->Run(hInstance, iCmdShow);
=======
	 Kernel* k = new Kernel(hInstance, iCmdShow);
	 k->Run();
>>>>>>> a423264690ff54d8d93ecb36690ab290a3059265
     return 0;
}