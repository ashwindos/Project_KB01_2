#include "Kernel.h"
#include "Renderer.h"
#include "DirectX.h"
#include <iostream>
#include <Windows.h>
#include <process.h>
#include <stdio.h>
#include <map>
#include <string>

Kernel::Kernel(HINSTANCE hInstance, int iCmdShow)
{
	Initialize(hInstance, iCmdShow);
}

Kernel::~Kernel(void)
{
	delete l;
	delete s;
	delete w;
	delete r;
	delete Renderers;
}

void Kernel::Run()
{
	while(true)
	{
		Update();
		Sleep(33);
	}
}

void Kernel::Update()
{
	s->RefreshAll();
	l->Log("Running");
}

void Kernel::Initialize(HINSTANCE hInstance, int iCmdShow)
{	
	l = new Logger();
	s = new SceneController();
	w = new WindowController();
	r = new ResourceController();
	Renderers = new std::map<std::string, Renderer*>();
	Renderer* r = new DirectX();

	AddRenderer("dirx", r);

	w->MakeWindow(hInstance, iCmdShow);
	s->MakeScene();
}

void Kernel::AddRenderer(std::string key, Renderer* r)
{
	(*Renderers)[key] = r;
}

Renderer* Kernel::GetRenderer(std::string key)
{
	return (*Renderers)[key];
}