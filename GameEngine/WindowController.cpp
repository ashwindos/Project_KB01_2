#include "WindowController.h"
#include "Window.h"
#include "Logger.h"
#include <Windows.h>
#include <process.h>

WindowController::WindowController(HINSTANCE* hInst)
{
	logger = new Logger();
	hInstance = hInst;
}

WindowController::~WindowController(void)
{
}

int WindowController::MakeWindow(LPCWSTR windowName, int index)
{
	windows[index] = new Window(windowName, hInstance);
	return 1;
}

/// Launch the window
unsigned int __stdcall WindowThread(void* data) 
{
	Window* window = (Window*)data;
	window->Launch();
	return 0;
}

int WindowController::LaunchWindow(int index)
{
	HANDLE myhandle[1];
	myhandle[0] = (HANDLE)_beginthreadex(0, 0, &WindowThread, (void*)windows[index], 0, 0); // Call the thread that keeps the window up.
	
	return 1;
}

Window* WindowController::GetWindow(int index) 
{
	return windows[index];
}