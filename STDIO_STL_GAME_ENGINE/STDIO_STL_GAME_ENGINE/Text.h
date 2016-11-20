#pragma once
#include<SDL.h>
#include<SDL_ttf.h>
#include<stdio.h>

class Text
{
public:
	//function
	Text();
	Text(SDL_Renderer* renderer, char* text,char* font);
	Text(SDL_Renderer* renderer, char* text, int r, int g, int b);
	~Text();
	void setTextPosition(int x, int y) { _textRect.x = x; _textRect.y = y; }
	void draw();

	//variables

private:
	//variables
	SDL_Renderer* _renderer;
	TTF_Font* _textFont;
	SDL_Texture* _textTexture;//the text on screen after convert char* to texture
	SDL_Color _textColor = { 0,0,0,255 };//Text color by default is Black and visible
	SDL_Rect _textRect;
};

