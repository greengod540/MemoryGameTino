#pragma once

#include <SDL_mixer.h>

#include "Engine.h"

class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	void init();
	static void playSound(SOUND sound);
	void destroy();

	static Mix_Chunk* m_backgroundMusic;

	static Mix_Chunk* m_playerColl;
	static Mix_Chunk* cardsFlip;
	static Mix_Chunk* cardsSame;
	static Mix_Chunk* cardsNotSame;
};