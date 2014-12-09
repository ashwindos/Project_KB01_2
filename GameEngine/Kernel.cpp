#include "Kernel.h"
#include <iostream>

Kernel::Kernel(void)
{
	Initialize();
}


Kernel::~Kernel(void)
{
}

void Kernel::Run(HINSTANCE hInstance, int iCmdShow)
{
	
   
	w->MakeWindow(hInstance, iCmdShow);
	s->MakeScene();

	
	l->Log("Fawaka kernel");
}

void Kernel::Initialize()
{	
	l = new Logger();
	s = new SceneController();
	w = new WindowController();
	r = new ResourceController();
}

