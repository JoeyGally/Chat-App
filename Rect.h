#pragma once
#ifndef RECT_H
#define RECT_H

#include "SDL.h"
#include "Color.h"

class Rect
{
public:
	Rect();
	Rect(int x, int y);
	~Rect() {};

	//Accessor
	SDL_Rect getRect() { return mRect; };
	int* getWidth() { return &mRect.w; };
	int* getHeight() { return &mRect.h; };

	void setColor(Color color);
private:
	SDL_Rect mRect;
};

#endif