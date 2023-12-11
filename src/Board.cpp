#include "Board.h"
#include "Presenter.h"
#include "InputManager.h"

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

	string backgorundImg, player1ConfigFile, player2ConfigFile, tmp;

	stream.open(CONFIG_FOLDER + configFile);

    stream >> tmp >> backgorundImg;
	stream >> tmp >> player1ConfigFile >> player2ConfigFile;

	stream.close();

	m_background = loadTexture(backgorundImg);

	m_player1.init(player1ConfigFile);
	m_player2.init(player2ConfigFile);
}

void Board::update()
{
	m_player1.update();
	m_player2.update();
}

void Board::draw()
{
	drawObject(m_background);

	m_player1.draw();
	m_player2.draw();
}

void Board::destroy()
{
	SDL_DestroyTexture(m_background);

	m_player1.destroy();
	m_player2.destroy();
}