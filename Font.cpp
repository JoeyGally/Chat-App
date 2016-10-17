#include "Font.h"

Font::Font()
{
	mName = "data-latin.ttf";
	mSize = 20;

	//Init text & fonts
	if (TTF_Init() < 0)
	{
		cout << "TTF Error: " << TTF_GetError << endl;
		return;
	}

	mFont = TTF_OpenFont(mName.c_str(), mSize);
}

Font::Font(string name, int size)
{
	mName = name;
	mSize = size;

	//Init text & fonts
	if (TTF_Init() < 0)
	{
		cout << "TTF Error: " << TTF_GetError << endl;
		return;
	}

	mFont = TTF_OpenFont(mName.c_str(), mSize);
}

Font::~Font()
{
	cleanup();
}

void Font::cleanup()
{
	mFont = nullptr;
}