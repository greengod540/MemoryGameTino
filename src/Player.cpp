#include "Player.h"
#include "Presenter.h"
#include "InputManager.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::init(string configFile)
{
	string tmp, playerImg;

	int up, left, down, right;

	fstream stream;

	stream.open(CONFIG_FOLDER + configFile);

	stream >> tmp >> playerImg;
	stream >> tmp >> m_player.rect.x >> m_player.rect.y >> m_player.rect.w >> m_player.rect.h;
	stream >> tmp >> up >> left >> down >> right;
	stream >> tmp >> m_speed;

	stream.close();

	m_player.texture = loadTexture(playerImg);

	//Converts the int to SDL_Scancode
	m_up = static_cast<SDL_Scancode>(up); //(SDL_Scancode)up
	m_left = static_cast<SDL_Scancode>(left);
	m_down = static_cast<SDL_Scancode>(down);
	m_right = static_cast<SDL_Scancode>(right);
}

void Player::update()
{
	move();
}

void Player::draw()
{
	drawObject(m_player);
}

void Player::move()
{
	if (isKeyPressed(m_up))
	{
		m_player.rect.y -= m_speed;
	}
	if (isKeyPressed(m_left))
	{
		m_player.rect.x -= m_speed;
	}
	if (isKeyPressed(m_down))
	{
		m_player.rect.y += m_speed;
	}
	if (isKeyPressed(m_right))
	{
		m_player.rect.x += m_speed;
	}
}

void Player::destroy()
{
	SDL_DestroyTexture(m_player.texture);
}
