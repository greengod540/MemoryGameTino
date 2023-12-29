#include "Card.h"
#include "Presenter.h"
#include <random>

Card::Card()
{

}

Card::~Card()
{

}

void Card::init(string configFile)
{
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> posXDist(300, 800);
	std::uniform_int_distribution<int> posYDist(0, 700);

	fstream stream;

	string tmp, backImg, frontImg;

	stream.open(CONFIG_FOLDER + CARD_FOLDER + configFile);

	stream >> tmp >> backImg >> frontImg;



	stream.close();

	m_back = loadTexture(CARD_FOLDER + backImg);
	m_front = loadTexture(CARD_FOLDER + frontImg);

	m_card.texture = m_front;

	
}

void Card::changeTexture()
{
	if (m_card.texture == m_back)
	{
		m_card.texture = m_front;
	}
	else
	{
		m_card.texture = m_back;
	}
}

void Card::draw()
{
	drawObject(m_card);
}

void Card::destroy()
{
	SDL_DestroyTexture(m_back);
	SDL_DestroyTexture(m_front);
	SDL_DestroyTexture(m_card.texture);
}
