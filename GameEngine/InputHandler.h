#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <Windows.h>
#include <dinput.h>
#include "Logger.h"

class InputHandler
{
public:
	InputHandler(HWND*);
	~InputHandler(void);

	/// Detects keyboard (and mouse) input and decides how to handle it.
	int HandleInput(void);

private:
	/// The DirectInput device.
	LPDIRECTINPUT8 dinput;

	/// The one and only keyboard.
	LPDIRECTINPUTDEVICE8 dikeyboard;

	/// The one and only mouse.
	LPDIRECTINPUTDEVICE8 dimouse;

	Logger* logger;

	/// The keyboard state is saved like this, multiple keys can be pressed at the same time after all.
	char keyboardState[256];

	/// The mouse x and y deltas are saved here.
	/// This means it does not hold the actual position, but rather the difference from its last position.
	DIMOUSESTATE mouseState;

	/// Create and acquire the keyboard.
	int CreateKeyboardDevice(HWND*);

	/// Create and acquire the mouse.
	int CreateMouseDevice(HWND*);

	/// Handle any keyboard input.
	int HandleKeyboardInput(void);

	/// Handle any mouse input.
	int HandleMouseInput(void);
};

#endif