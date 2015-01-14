#ifndef WINDOW_H
#define WINDOW_H

#include <Windows.h>
#include "Logger.h"

class Window
{
public:
	Window(LPCWSTR, HINSTANCE*);
	~Window(void);

	/// Launch the window, this function will stay up through the window's lifespan.
	int Launch();

	/// Returns whether or not the window is still up.
	bool IsUp(void);

	/// The actual window handle is stored.
	HWND Instance;
private:
	Logger* logger;

	/// Name that is displayed on the window chrome.
	LPCWSTR name;

	/// Whether or not the window is still up.
	bool isUp;

	HINSTANCE* hInstance;
};
#endif