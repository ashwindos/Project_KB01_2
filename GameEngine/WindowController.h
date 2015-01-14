#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include "Window.h"
#include "Logger.h"
#include <Windows.h>

class WindowController
{
public:
	WindowController(HINSTANCE*);
	~WindowController(void);

	/// Make a new window and store it.
	int MakeWindow(LPCWSTR, int);

	/// Launch a window that has been made.
	int LaunchWindow(int);

	/// Returns a pointer to a window.
	Window* GetWindow(int);

	Window* windows[8];
private:
	Logger* logger;
	HINSTANCE* hInstance;
};

#endif
