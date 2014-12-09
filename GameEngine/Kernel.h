#ifndef __KERNEL_H__
#define __KERNEL_H__
#include <Windows.h>
#include "WindowController.h"
#include "SceneController.h"
#include "ResourceController.h"
#include "Logger.h"



class Kernel
{
public:
	Kernel(void);
	~Kernel(void);
	void Run(HINSTANCE, int);

private :
	WindowController* windowController;
	SceneController* sceneController;
	ResourceController* rescourceController;
	void Initialize(void);
};
#endif

