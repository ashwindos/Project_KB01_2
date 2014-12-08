#include "WindowController.h"
#include "Window.h"
#include <Windows.h>

WindowController::WindowController(void)
{
}

void WindowController::MakeWindow(HINSTANCE hInstance, int iCmdShow)
{
	Window* w = new Window(hInstance, iCmdShow);
}

WindowController::~WindowController(void)
{
}
