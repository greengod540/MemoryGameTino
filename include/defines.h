#pragma once

#include <iostream>
#include <SDL.h>

using namespace std;

static string IMG_FOLDER = "img\\";
static string CONFIG_FOLDER = "config\\";

struct int2
{
	int x;
	int y;

	void reset()
	{
		x = 0;
		y = 0;
	}

	void set(int2 b) 
	{
		x = b.x;
		y = b.y;
	}

	template <typename Params>
	void operator*=(Params value)
	{
		x *= value;
		y *= value;
	}

	template <typename Params>
	void operator/=(Params value)
	{
		x /= value;
		y /= value;
	}

	template <typename Params>
	int2 operator*(Params value)
	{
		x *= value;
		y *= value;

		return *this; //Returns instance of the current class (After the modifications)
	}

	template <typename Params>
	int2 operator/(Params value)
	{
		x /= value;
		y /= value;

		return *this;
	}

	template <typename Params>
	bool operator!=(Params value)
	{
		if (x == value && y == value)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

struct Drawable 
{
	SDL_Texture* texture;
	SDL_Rect rect; //srcRect;
};

struct DrawableDstRect : Drawable
{
	SDL_Rect dstRect;
};