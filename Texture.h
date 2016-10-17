#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include "SDL.h"
#include "Font.h"
#include "Color.h"
#include "Rect.h"
#include <iostream>
#include <string.h>

using namespace std;

class Window;

class Texture
{
public:
	Texture();
	Texture(Font font, Color color, Rect rect, string text);
	~Texture() { cleanup(); };

	void cleanup();

	//Accessors
	SDL_Texture* getTexture() { return mTexture; };
	Rect getRect() { return mRect; };
private:
	SDL_Texture* mTexture;
	Rect mRect;
};

#endif