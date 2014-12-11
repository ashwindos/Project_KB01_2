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
	Kernel(HINSTANCE, int);
	~Kernel(void);

	/// Call this function to start the engine.
	/// The game loop is located here.
	void Run();

private:
	void Initialize(HINSTANCE, int);

	/// This function is called every turn by the game loop.
	void Update(void);

	Logger* l;
	WindowController* w;
	SceneController* s;
	ResourceController* r;
};
#endif

