#include <Windows.h>
#include "Kernel.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdline, int iCmdShow)
{
	Kernel* k = new Kernel(&hInstance);
	k->SetLoopRate(60);
	k->Run();

	return 0;
}

