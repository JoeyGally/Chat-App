#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_ttf.h"
#include "Window.h"
#include <deque>

using namespace std;

const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 480;
const int MAX_PAST_TEXTS = 8;

int main(int argc, char* args[])
{
	Window* window;
	window = Window::getInstance();

	Font font;
	Color color;
	Rect enterText(10, SCREEN_HEIGHT - 50);
	Texture* wordsTexture;

	string name1 = "User 1: ";
	string name2 = "User 2: ";
	string text = name1;
	bool user1 = true;

	deque<string> pastTexts;

	bool exit = false;
	
	SDL_Event e; //to get what the user does

	SDL_StartTextInput();

	// "Game" Loop
	while (!exit)
	{		
		while (SDL_PollEvent(&e) != 0) //if anything has happened
		{
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) //Escape or x button to quit
			{
				exit = true;
			}
			else if (e.type == SDL_TEXTINPUT || e.type == SDL_KEYDOWN) // If you're typing
			{
				system("cls");
				if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE && text.length() >= 0) //If you type a backspace
				{
					if ( (text.length() - 1) > (name1.length() - 1) )
					{
						text = text.substr(0, text.length() - 1); //remove the last letter
					}					
				}
				else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN && text.length() >= 0) //Enter key
				{
					pastTexts.push_front(text);
					if (pastTexts.size() > MAX_PAST_TEXTS)
					{
						pastTexts.pop_back();
					}

					if (user1)
					{
						text = name1;
					}
					else
					{
						text = name2;
					}					
				}
				else if (e.type == SDL_TEXTINPUT) //If you're typing anything else
				{
					text += e.text.text; //add it to the end of the text
				}								
			}
		}

		//Clear the old screen, put the stuff on it, and then present it
		SDL_RenderClear(window->getRenderer());
		wordsTexture = new Texture(font, color, enterText, text);
		window->drawTexture(*wordsTexture, enterText);

		int offset = 50;
		int ctr = 1;
		for (int i = 0; i < pastTexts.size(); i++)
		{			
			ctr++;
			if (SCREEN_HEIGHT - (offset * ctr) >= 0)
			{
				Rect tempRect(10, SCREEN_HEIGHT - (offset * ctr));
				Texture temp(font, color, tempRect, pastTexts[i]);
				window->drawTexture(temp, tempRect);
			}
		}

		window->present();
	}
	
	return 0;
}