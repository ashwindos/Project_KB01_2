#include "Window.h"
#include <Windows.h>
#ifndef __WindowController_h__
#define __WindowController_h__

class WindowController
{
public:
	WindowController(void);
	~WindowController(void);
	void MakeWindow(HINSTANCE,int);
};
#endif
