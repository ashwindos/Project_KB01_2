#include "Kernel.h"
#include <iostream>
#include <Windows.h>
#include <process.h>
#include <stdio.h>

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
}

void Kernel::Initialize(HINSTANCE hInstance, int iCmdShow)
{	
	l = new Logger();
	s = new SceneController();
	w = new WindowController();
	r = new ResourceController();

	w->MakeWindow(hInstance, iCmdShow);
	s->MakeScene();
}

