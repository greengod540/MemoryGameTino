#include "Board.h"
#include "Presenter.h"

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

	string backgorundImg, playerConfigFile, tmp;

	stream.open(CONFIG_FOLDER + configFile);

    stream >> tmp >> backgorundImg;
	stream >> tmp >> playerConfigFile;

	stream.close();

	initPlayer(playerConfigFile);

	m_background = loadTexture(backgorundImg);
}

void Board::update()
{
	movePlayer();
}

void Board::draw()
{
	drawObject(m_background);
}

void Board::destroy()
{
	SDL_DestroyTexture(m_background);
	SDL_DestroyTexture(m_player.texture);
}

void Board::initPlayer(string configFile)
{
	//W, A, S, D - move
	//Start position (Rect)
	//Texture
}

void Board::movePlayer()
{

}
