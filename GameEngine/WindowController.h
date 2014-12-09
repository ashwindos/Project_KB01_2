#ifndef __WINDOWCONTROLLER_H_
#define __WINDOWCONTROLLER_H_
#include "Window.h"
#include <Windows.h>

class WindowController
{
public:
	WindowController(void);
	~WindowController(void);
	void MakeWindow(HINSTANCE,int);
};
#endif
