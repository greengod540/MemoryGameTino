#include "InputManager.h"

bool InputManager::m_mouseIsPressed = bool();
bool InputManager::m_mouseIsDoublePressed = bool();

int2 InputManager::m_mouseCoor = int2();

const Uint8* InputManager::m_keyboardState = nullptr;

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

void InputManager::handleInput()
{
	m_mouseIsPressed = false;
	m_mouseIsDoublePressed = false;

	//Events for the mouse
	while (SDL_PollEvent(&m_event))
	{
		switch (m_event.type)
		{
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&(m_mouseCoor.x), &(m_mouseCoor.y));

			m_mouseCoor.x *= m_mouseMultiply.x;
			m_mouseCoor.y *= m_mouseMultiply.y;

			break;
		case SDL_MOUSEBUTTONDOWN:
			if (m_event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseIsPressed = true;
			}
			break;
		}
	}

	m_keyboardState = SDL_GetKeyboardState(NULL);
}

void InputManager::setMouseMultiply(int2 multyplier)
{
	m_mouseMultiply = multyplier;
}

bool InputManager::isMousePressed()
{
	return m_mouseIsPressed;
}
