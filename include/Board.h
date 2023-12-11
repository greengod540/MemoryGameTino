#pragma once

#include "Engine.h"

class Board
{
public:
	Board();
	~Board();

	void init();
	void update();
	void draw();
	void destroy();

private:
	Drawable m_player;

	void initPlayer(string configFile);
	void movePlayer();

	SDL_Texture* m_background;

	SDL_Scancode m_w, m_a, m_s, m_d;
};