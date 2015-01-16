#ifndef Kernel_H
#define Kernel_H

#include <iostream>
#include <Windows.h>
#include <map>
#include <string>
#include "Logger.h"
#include "WindowController.h"
#include "SceneController.h"
#include "ResourceController.h"
#include "Renderer.h"
#include "InputHandler.h"

class Kernel
{
public:
	Kernel(HINSTANCE*);
	~Kernel(void);

	/// Run the engine.
	int Run(void);

	/// Set how many times a second a step will happen in the game loop.
	int SetLoopRate(int);

	/// Get a renderer in exchange for a key.
	Renderer* GetRenderer(std::string);

private:
	/// Add a new renderer with a string as the key.
	int AddRenderer(std::string, Renderer*);

	/// This function is called whenever the game updates in the game loop.
	int OnGameUpdate(void);

	/// Returns false if the window is no longer up.
	bool Running(void);

	/// Every time the engine starts it's useful to log it, so logs can be told apart.
	int LogNewSession(void);

	/// The waiting time between each step of the game loop.
	int stepDuration;

	Logger* logger;
	InputHandler* handler;

	WindowController* windowController;
	SceneController* sceneController;
	ResourceController* resourceController;

	std::map<std::string, Renderer*>* Renderers;
};
#endif

