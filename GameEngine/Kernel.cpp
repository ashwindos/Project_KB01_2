#include "Kernel.h"
#include "Renderer.h"
#include "DirectX.h"
#include "Window.h"
#include "Logger.h"
#include <iostream>
#include <Windows.h>
#include <process.h>
#include <stdio.h>
#include <map>
#include <string>

Kernel::Kernel(HINSTANCE* hInstance)
{
	// Initialize the logger.
	logger = new Logger();
	LogNewSession();

	// Create the DirectX Renderer.
	Renderers = new std::map<std::string, Renderer*>();
	Renderer* r = new DirectX();
	AddRenderer("dirx", r);

	// Initialize the window controller and create a window
	windowController = new WindowController(hInstance);
	windowController->MakeWindow(L"3D ENGINE", 0);
	windowController->LaunchWindow(0);

	// The window we just created is needed to initialize the inputhandler...
	Window* w = windowController->GetWindow(0);
	HWND* wnd = &(w->Instance);
	handler = new InputHandler(wnd);

	// ...and also for the directX renderer.
	r->initD3D(*wnd);
	r->InitGeometry();

	sceneController = new SceneController();
	resourceController = new ResourceController();

	// default is a loop rate of 30 times a second.
	SetLoopRate(30);
}

Kernel::~Kernel(void)
{
	delete logger;
	delete sceneController;
	delete windowController;
	delete resourceController;
	delete Renderers;
}

int Kernel::Run()
{
	Renderer* r = GetRenderer("dirx");
	logger->Log("Entering the game loop.");

	// Call OnGameUpdate() and sleep for a bit.
	while(Running())
	{
		OnGameUpdate();
		r->Render();
		Sleep(stepDuration);
	}

	return 0;
}

int Kernel::SetLoopRate(int loopRate)
{
	if(loopRate < 1)
	{
		return 0; // needs to happen at least once a second
	}
	else
	{
		stepDuration = 1000 / loopRate;
		return 1;
	}
}

int Kernel::OnGameUpdate() 
{
	handler->HandleInput(); // Handle user input.
	return 0;
}

bool Kernel::Running()
{
	return true; // TODO implement
}

int Kernel::LogNewSession()
{
	logger->Log("-------------------------------");
	logger->Log("NEW ENGINE SESSION STARTED HERE");
	logger->Log("-------------------------------");

	return 1;
}

void Kernel::AddRenderer(std::string key, Renderer* r)
{
	(*Renderers)[key] = r;
}

Renderer* Kernel::GetRenderer(std::string key)
{
	return (*Renderers)[key];
}