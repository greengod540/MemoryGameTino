#pragma once

#include "defines.h"

SDL_Texture* LoadTexture(string imgPath, SDL_Renderer* renderer);
bool isMouseInRect(int2 mouseCoor, SDL_Rect rect);