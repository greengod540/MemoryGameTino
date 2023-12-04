#pragma once

#include "Presenter.h"
#include "InputManager.h"

class World
{
public:
	World();
	~World();

	Presenter m_presenter;
	InputManager m_inputManager;

	void init();
	void run(); //Update and Draw
	void destroy();

	bool isRunning();

private:
	bool m_running;
};