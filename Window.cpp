#include "Window.h"

bool Window::mFlag = false;
Window* Window::mWindowInstance = NULL;

Window::Window()
{
	mWidth = 720;
	mHeight = 480;
	mTitle = "Chat App";

	init();
}

bool Window::init()
{
	//Init SDL
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		cout << "init error: " << SDL_GetError << endl;
		return false;
	}

	//Create the window
	mGLWindow = SDL_CreateWindow(mTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		mWidth, mHeight, SDL_WINDOW_SHOWN);

	//Make sure the window was made
	if (mGLWindow == NULL)
	{
		cout << "window error: " << SDL_GetError << endl;
		return false;
	}

	//Init the renderer
	mRenderer = SDL_CreateRenderer(mGLWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	return true;
}

Window::~Window()
{
	cleanup();
}

void Window::cleanup()
{
	SDL_DestroyWindow(mGLWindow);
	mGLWindow = nullptr;

	SDL_DestroyRenderer(mRenderer);
	mRenderer = nullptr;

	SDL_Quit();

	mFlag = false;
}

Window* Window::getInstance()
{
	if (!mFlag)
	{
		mWindowInstance = new Window();
		mFlag = true;
		return mWindowInstance;
	}
	else
	{
		return mWindowInstance;
	}
}


void Window::drawTexture(Texture texture, Rect rect)
{
	SDL_QueryTexture(texture.getTexture(), NULL, NULL, rect.getWidth(), rect.getHeight());
	SDL_RenderCopy(mRenderer, texture.getTexture(), NULL, &rect.getRect()); //lol get rekt
}