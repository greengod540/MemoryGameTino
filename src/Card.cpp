#include "Card.h"
#include "Presenter.h"

Card::Card()
{

}

Card::~Card()
{

}

void Card::init(string configFile)
{
	fstream stream;

	string tmp, backImg, frontImg;

	stream.open(CONFIG_FOLDER + CARD_FOLDER + configFile);

	stream >> tmp >> backImg >> frontImg;
	stream >> tmp >> m_card.rect.x >> m_card.rect.y >> m_card.rect.w >> m_card.rect.h;

	stream.close();

	m_back = loadTexture(CARD_FOLDER + backImg);
	m_front = loadTexture(CARD_FOLDER + frontImg);

	m_card.texture = m_back; //For dev purposes texture = front
}

void Card::chancheTexture()
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
