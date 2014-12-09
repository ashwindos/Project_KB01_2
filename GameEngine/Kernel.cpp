#include "Kernel.h"
#include <iostream>

Kernel::Kernel(void)
{
}


Kernel::~Kernel(void)
{
}

void Kernel::Run(HINSTANCE hInstance, int iCmdShow)
{
	
    s = new SceneController();
	w = new WindowController();
	r = new ResourceController();
	w->MakeWindow(hInstance, iCmdShow);
	s->MakeScene();

	Logger* r = new Logger();
	r->Log("Fawaka kernel");
}

