#ifndef __Kernel_H__
#define __Kernel_H__
#include "Kernel.h"
#include "WindowController.h"
#include "Logger.h"
#include "SceneController.h"
#include "ResourceController.h"
#include "Renderer.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <map>
#include <string>

class Kernel
{
public:
	Kernel(HINSTANCE, int);
	~Kernel(void);

	/// Call this function to start the engine.
	/// The game loop is located here.
	void Run();

	/// Get a renderer in exchange for a key.
	Renderer* GetRenderer(std::string);

private:
	void Initialize(HINSTANCE, int);

	/// This function is called every turn by the game loop.
	void Update(void);

	/// Add a new renderer with a string as the key.
	void AddRenderer(std::string, Renderer*);

	Logger* l;
	WindowController* w;
	SceneController* s;
	ResourceController* r;
	std::map<std::string, Renderer*>* Renderers;
};
#endif

