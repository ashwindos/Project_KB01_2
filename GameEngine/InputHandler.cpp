#define KEYDOWN(name, key) (name[key] & 0x80) // Use this to check the keyboard state for button presses.

#include "InputHandler.h"
#include <Windows.h>
#include <dinput.h>
#include "Logger.h"

InputHandler::InputHandler(HWND* window)
{
	logger = new Logger();

	DirectInput8Create(
		GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&dinput,
		NULL
	);

	if(dinput == NULL)
	{
		logger->Log("DirectInput: Connection failed.");
	}
	else
	{
		logger->Log("DirectInput: Connection complete.");
	}

	CreateKeyboardDevice(window);
	CreateMouseDevice(window);
}

InputHandler::~InputHandler(void)
{
	delete logger;
	delete dinput;
	delete dikeyboard;
}

int InputHandler::CreateKeyboardDevice(HWND* window)
{
	dinput->CreateDevice(GUID_SysKeyboard, &dikeyboard, NULL);

	// Acquire the keyboard.
	if(dikeyboard)
	{
		dikeyboard->SetDataFormat(&c_dfDIKeyboard);
		dikeyboard->SetCooperativeLevel(
			*window, 
			DISCL_FOREGROUND | DISCL_EXCLUSIVE // Set to foreground exclusive
		);
		dikeyboard->Acquire();
		logger->Log("DirectInput: Keyboard acquisition complete.");
		return 1;
	}
	else
	{
		logger->Log("DirectInput: Keyboard acquisition failed.");
		return 0;
	}
}

int InputHandler::CreateMouseDevice(HWND* window)
{
	dinput->CreateDevice(GUID_SysMouse, &dimouse, NULL);

	// Acquire the mouse.
	if(dimouse)
	{
		dimouse->SetDataFormat(&c_dfDIMouse);
		dimouse->SetCooperativeLevel(
			*window, 
			DISCL_FOREGROUND | DISCL_NONEXCLUSIVE // Set to foreground nonexclusive
		);
		dimouse->Acquire();
		logger->Log("DirectInput: Mouse acquisition complete.");
		return 1;
	}
	else
	{
		logger->Log("DirectInput: Mouse acquisition failed.");
		return 0;
	}
}

int InputHandler::HandleInput() 
{
	HandleKeyboardInput();
	HandleMouseInput();
	return 1;
}

int InputHandler::HandleKeyboardInput()
{
	HRESULT  hr;

    // get the keyboard state and save it to a char[]
	hr = dikeyboard->GetDeviceState(        
		sizeof(keyboardState),
		(LPVOID)&keyboardState    
	);

    if (FAILED(hr))    
	{
		// Reacquire the keyboard in case we lost it.      
		dikeyboard->Acquire();
		return 0;
	}

	// Let the input reciever take care of what happens.
	inputReciever->OnKeyboardInputRecieved(keyboardState);

	return 1;
}

int InputHandler::HandleMouseInput()
{
	HRESULT  hr;

	// get the mouse state and save it to a char[]
	hr = dimouse->GetDeviceState(        
		sizeof(mouseState),        
		(LPVOID)&mouseState    
	);

	if (FAILED(hr))    
	{
		// Reacquire the keyboard in case we lost it.      
		dimouse->Acquire();
		return 0;
	}

	// Let the input reciever take care of what happens.
	inputReciever->OnMouseInputRecieved(mouseState);

	return 1;
}

int InputHandler::SetInputReciever(InputReciever* i)
{
	inputReciever = i;
	return 1;
}