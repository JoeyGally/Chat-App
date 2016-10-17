#pragma once
#ifndef FONT_H
#define FONT_H

#include <string.h>
#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"

using namespace std;

class Font
{
public:
	Font();
	Font(string font, int size);
	~Font();

	void cleanup();

	//Accessors
	inline TTF_Font* getFont() { return mFont; };
	string getFontName() { return mName; };
	int getFontSize() { return mSize; };

private:
	string mName;
	int mSize;
	TTF_Font* mFont;
};


#endif