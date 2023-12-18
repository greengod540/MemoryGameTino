#include "Board.h"
#include "Presenter.h"
#include "InputManager.h"
#include "SoundManager.h"

Board::Board()
{

}

Board::~Board()
{

}

void Board::init()
{
	string configFile = "boardInit.txt";

	fstream stream;

	string backgorundImg, player1ConfigFile, player2ConfigFile, tmp, card1Config;

	stream.open(CONFIG_FOLDER + configFile);

    stream >> tmp >> backgorundImg;
	stream >> tmp >> player1ConfigFile >> player2ConfigFile;
	stream >> tmp >> card1Config;

	stream.close();

	m_background = loadTexture(backgorundImg);

	m_player1.init(player1ConfigFile);
	m_player2.init(player2ConfigFile);

	m_card1.init(card1Config);
}

void Board::update()
{
	/*m_player1.update();
	m_player2.update();

	if (collRectRect(m_player1.m_player.rect, m_player2.m_player.rect))
	{
		SoundManager::playSound(SOUND::PLAYER_COLLISION);
	}*/

	if (isMouseInRect(InputManager::m_mouseCoor, m_card1.m_card.rect) && InputManager::isMousePressed())
	{
		m_card1.chancheTexture();
	}
}

void Board::draw()
{
	drawObject(m_background);

	m_card1.draw();

	//m_player1.draw();
	//m_player2.draw();
}

void Board::destroy()
{
	SDL_DestroyTexture(m_background);

	m_card1.destroy();

	//m_player1.destroy();
	//m_player2.destroy();
}