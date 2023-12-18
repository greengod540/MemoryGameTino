#pragma once

#include "Engine.h"
#include "Player.h"
#include "Card.h" 

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
	SDL_Texture* m_background;
	
	Player m_player1;
	Player m_player2;

	Card m_card1;
};