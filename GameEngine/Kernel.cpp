#include "Kernel.h"


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
	r->Log("goed man , goed  kernel");
}

void Kernel :: Initialize()
{
	windowController = new WindowController();
	sceneController = new SceneController();
	rescourceController = new ResourceController();
}

