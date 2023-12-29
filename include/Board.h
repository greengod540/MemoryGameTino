	#pragma once
#include "Engine.h"
#include<string>
#include "Player.h"
#include <Card.h>
#include <SDL.h>
#include <vector>
#include <map>


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
	Card m_card2;
	Card m_card3;
	Card m_card4;
	Card m_card5;
	Card m_card10;
	Card m_card6;
	Card m_card7;
	Card m_card8;
	Card m_card9;
	std::vector<Card> cards = { m_card1, m_card2, m_card3, m_card4, m_card5 };
	std::map<int, int> ids;
};