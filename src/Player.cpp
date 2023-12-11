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
	stream >> tmp >> up >> left >> s >> d;
	stream >> tmp >> m_speed;

	stream.close();

	m_player.texture = loadTexture(playerImg);

	//Converts the int to SDL_Scancode
	m_w = (SDL_Scancode)w;
	m_a = (SDL_Scancode)a;
	m_s = (SDL_Scancode)s;
	m_d = (SDL_Scancode)d;
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
	if (isKeyPressed(m_w))
	{
		m_player.rect.y -= m_speed;
	}
	if (isKeyPressed(m_a))
	{
		m_player.rect.x -= m_speed;
	}
	if (isKeyPressed(m_s))
	{
		m_player.rect.y += m_speed;
	}
	if (isKeyPressed(m_d))
	{
		m_player.rect.x += m_speed;
	}
}

void Player::destroy()
{
	SDL_DestroyTexture(m_player.texture);
}
