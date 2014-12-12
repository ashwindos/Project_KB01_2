#include "WindowController.h"
#include "Window.h"
#include <vector>
#include <Windows.h>

WindowController::WindowController(void)
{
	this->Windows = new std::vector<Window*>();
}

void WindowController::MakeWindow(HINSTANCE hInstance, int iCmdShow)
{
	Window* w = new Window(hInstance, iCmdShow);
	Windows->push_back(w);
}

WindowController::~WindowController(void)
{
}
