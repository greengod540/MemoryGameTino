#pragma once

#include "Engine.h"

class Player
{
public:
	Player();
	~Player();

	void init(string configFile);
	void update();
	void draw();
	void move();
	void destroy();

	Drawable m_player;
private:

	SDL_Scancode m_up, m_left, m_down, m_right;

	int m_speed;
};