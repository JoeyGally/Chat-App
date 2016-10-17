#include "Color.h"

Color::Color()
{
	//Make default color white because why not
	mRed = 255;
	mGreen = 255;
	mBlue = 255;
	mAlpha = 255;

	mColor = {mRed, mGreen, mBlue, mAlpha};
}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	mRed = r;
	mGreen = g;
	mBlue = b;
	mAlpha = a;

	mColor = { mRed, mGreen, mBlue, mAlpha };
}