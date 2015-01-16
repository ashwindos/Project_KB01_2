#include <dinput.h>

class InputReciever
{
public:
	InputReciever(void);
	virtual ~InputReciever(void);
	virtual int OnKeyboardInputRecieved(char[]);
	virtual int OnMouseInputRecieved(DIMOUSESTATE);
};

