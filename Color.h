#pragma once
#ifndef COLOR_H
#define COLOR_H

#include "SDL.h"

class Color
{
public:
	Color();
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	~Color() {};

	//Accessors
	inline SDL_Color getColor() { return mColor; };
	uint8_t getR() { return mRed; };
	uint8_t getG() { return mGreen; };
	uint8_t getB() { return mBlue; };
	uint8_t getA() { return mAlpha; };

private:
	uint8_t mRed, mGreen, mBlue, mAlpha;
	SDL_Color mColor;
};

#endif