#ifndef __WINDOW_H_
#define __WINDOW_H_
#include <Windows.h>
#include "Logger.h"
#include <string>
#include "Renderer.h"

class Window
{
private:
	Logger*	r;
public:
	Window(HINSTANCE hInstance,  int iCmdShow);
	~Window();
	
	int init(HINSTANCE, int, Renderer*);
	
};
#endif