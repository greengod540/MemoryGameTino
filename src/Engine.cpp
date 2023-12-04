#include "Engine.h"

SDL_Texture* LoadTexture(string imgPath, SDL_Renderer* renderer)
{
	string tmpImg = IMG_FOLDER + imgPath;

	SDL_Surface* loadingSurface = SDL_LoadBMP(tmpImg.c_str());

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadingSurface);

	if (texture == nullptr)
	{
		tmpImg = "img\\Null.bmp";

		loadingSurface = SDL_LoadBMP(tmpImg.c_str());

		texture = SDL_CreateTextureFromSurface(renderer, loadingSurface);
	}

	SDL_FreeSurface(loadingSurface);

	return texture;
}

bool isMouseInRect(int2 mouseCoor, SDL_Rect rect)
{
	if (mouseCoor.x >= rect.x && mouseCoor.x <= rect.x + rect.w && 
		mouseCoor.y >= rect.y && mouseCoor.y <= rect.y + rect.h)
	{
		return true;
	}

	return false;
}