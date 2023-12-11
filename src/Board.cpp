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

	drawObject(m_player);
}

void Board::destroy()
{
	SDL_DestroyTexture(m_background);
	SDL_DestroyTexture(m_player.texture);
}

void Board::initPlayer(string configFile)
{
	string tmp, playerImg;

	int w, s, a, d;

	fstream stream;

	stream.open(CONFIG_FOLDER + configFile);

	stream >> tmp >> playerImg;
	stream >> tmp >> m_player.rect.x >> m_player.rect.y >> m_player.rect.w >> m_player.rect.h;
	stream >> tmp >> w >> a >> s >> d;

	stream.close();

	m_player.texture = loadTexture(playerImg);

	//Converts the int to SDL_Scancode
	m_w = (SDL_Scancode)w;
	m_a = (SDL_Scancode)a;
	m_s = (SDL_Scancode)s;
	m_d = (SDL_Scancode)d;
}

void Board::movePlayer()
{
	if (isKeyPressed(m_w))
	{
		m_player.rect.y -= 5;
	}
	if (isKeyPressed(m_a))
	{
		m_player.rect.x -= 5;
	}
	if (isKeyPressed(m_s))
	{
		m_player.rect.y += 5;
	}
	if (isKeyPressed(m_d))
	{
		m_player.rect.x += 5;
	}
}
