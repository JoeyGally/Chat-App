#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string.h>
#include "SDL.h"
#include "Texture.h"

using namespace std;

class Window
{
public:
	~Window();

	static Window* getInstance(); //singletooooon woooo game architecture

	void cleanup();
	void drawTexture(Texture texture, Rect rect);
	inline void present() { SDL_RenderPresent(mRenderer); };

	//Accessors
	inline SDL_Window* getGLWindow() { return mGLWindow; };
	SDL_Renderer* getRenderer() { return mRenderer; };
	int getWidth() { return mWidth; };
	int getHeight() { return mHeight; };
	string getTitle() { return mTitle; };

private:
	int mWidth, mHeight;
	string mTitle;
	SDL_Window* mGLWindow;
	SDL_Renderer* mRenderer;

	bool init();

	//for singleton
	static Window* mWindowInstance;
	static bool mFlag;
	Window();
};

#endif