#include "Kernel.h"
#include "WindowController.h"
#include <Windows.h>
#include "Logger.h"
#include <iostream>

Kernel::Kernel(void)
{
}


Kernel::~Kernel(void)
{
}

void Kernel::Run(HINSTANCE hInstance, int iCmdShow)
{
	WindowController* w = new WindowController();
	w->MakeWindow(hInstance, iCmdShow);

	Logger* r = new Logger();
	r->Log("Fawaka kernel");
}

