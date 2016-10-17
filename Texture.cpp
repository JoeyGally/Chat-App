#include "Texture.h"
#include "Window.h"

Texture::Texture()
{
	mTexture = nullptr;
}

Texture::Texture(Font font, Color color, Rect rect, string text)
{
	mRect = rect;

	//Create the text (surface) to plop onto a texture i think
	SDL_Surface* textSurface = TTF_RenderText_Solid(font.getFont(), text.c_str(), color.getColor());
	mTexture = SDL_CreateTextureFromSurface(Window::getInstance()->getRenderer(), textSurface); //convert text surface to texture
}

void Texture::cleanup()
{
	SDL_DestroyTexture(mTexture);
	mTexture = nullptr;
}