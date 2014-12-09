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
	//WindowController* w = new WindowController();
	SceneController* s = new SceneController();
	w = new WindowController();
	w->MakeWindow(hInstance, iCmdShow);
	s->MakeScene();

	Logger* r = new Logger();
	r->Log("Fawaka kernel");
}

