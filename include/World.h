#pragma once

#include "Presenter.h"
#include "InputManager.h"
#include "Board.h"

class World
{
public:
	World();
	~World();

	Presenter m_presenter;
	InputManager m_inputManager;
	Board m_board;

	void init();
	void run(); //Update and Draw
	void destroy();

	bool isRunning();

private:
	bool m_running;
};