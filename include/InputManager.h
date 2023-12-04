#pragma once

#include "Engine.h"

class InputManager
{
public:
	InputManager();
	~InputManager();

	static int2 m_mouseCoor;

	static const Uint8* m_keyboardState;

	void handleInput();
	void setMouseMultiply(int2 multyplier);

	static bool isMousePressed();

private:
	SDL_Event m_event;

	int2 m_mouseMultiply;

	static bool m_mouseIsPressed;
	static bool m_mouseIsDoublePressed;
};

bool isAnyKeyPressed()
{
	int numOfKeys = 322;

	for (int i = 0; i < numOfKeys; i++)
	{
		if (InputManager::m_keyboardState[i])
		{
			return true;
		}
	}

	return false;
}

bool isKeyPressed(SDL_Scancode code)
{
	return InputManager::m_keyboardState[code];
}