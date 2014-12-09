#ifndef __Kernel_H__
#define __Kernel_H__
#include "Kernel.h"
#include "WindowController.h"
#include <Windows.h>
#include "Logger.h"
#include "SceneController.h"
#include "ResourceController.h"
#include <iostream>



class Kernel
{
public:
	Kernel(void);
	~Kernel(void);
	void Run(HINSTANCE, int);

private:
	WindowController* w;
	//SceneController* s;
	//ResourceController* r;
};
#endif

