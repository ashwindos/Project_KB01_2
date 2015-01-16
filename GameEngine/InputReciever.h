#ifndef INPUTRECIEVER_H
#define INPUTRECIEVER_H

#include <dinput.h>

class InputReciever
{
public:
	InputReciever(void){}
	virtual ~InputReciever(void){}
	virtual int OnKeyboardInputRecieved(char[]) = 0;
	virtual int OnMouseInputRecieved(DIMOUSESTATE) = 0;
};

#endif