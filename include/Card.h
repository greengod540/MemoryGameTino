#pragma once

#include "Engine.h"

class Card
{
public:
	Card();
	~Card();

	void init(string configFile);
	void chancheTexture();
	void draw();
	void destroy();

	Drawable m_card;
private:

	SDL_Texture* m_back;
	SDL_Texture* m_front;
};